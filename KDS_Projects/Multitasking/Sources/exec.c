#include "exec.h"

/**
 * Lista de tarefas.
 */
volatile task_t *_tasks = NULL;

/**
 * Contador de tempo do sistema, incrementado a cada 10ms.
 */
volatile uint32_t ticks;


void SysTick_Handler (void) {
	systimer_tick();
}

/**
 * Inicializa��o da biblioteca.
 * Deve ser chamado antes de qualquer rotina da biblioteca.
 */
void task_init(void)
{
   /*
    * Limpa a lista de tarefas.
    */
   _tasks = NULL;
   ticks = 0;

   SysTick_Config(SystemCoreClock/1000);      /* Generate interrupt each 1 ms  */

}


/**
 * Atende � interrup��o do Timer 2.
 * Atualiza a base de tempo do sistema.
 */
 void systimer_tick(void)
 {
   register task_t *task;

   /*
    * Incrementa base de tempo principal.
    */
   ticks++;

   /*
    * Verifica temporiza��o das tarefas.
    */
   list_for_each(_tasks, task) {
      if(task->tempo) task->tempo--;
   }

   /*
    * Limpa interrup��o.
    */
   //IFS0bits.T2IF = 0;
}


/**
 * Ponto de entrada do despachador de tarefas.
 * Deve ser chamado continuamente, dentro do loop principal do programa.
 */
void task_run (void)
{
   register task_t *task;
   static void (*fn)(uint16_t);

   disable();

   /*
    * Varre a lista de tarefas.
    */
tenta:
   list_for_each(_tasks, task) {
      if(task->tempo == 0) {
         /*
          * Tarefa pronta.
          * Chama rotina definida.
          */
         fn = task->func;
         enable();
         fn(task->par);
         disable();

         /*
          * Remove a tarefa da fila.
          */
         free((void*)task);
         list_remove(&_tasks, task);
         goto tenta;
      }
   }

   enable();
}


/**
 * Insere uma tarefa / callback para execu��o no sistema.
 * @param f Endere�o da tarefa.
 * @param p Valor do par�metro a ser passado para a tarefa.
 * @param t Tempo para executar a tarefa (zero = imediato).
 * @return TRUE se bem sucedido.
 */
bool_t add_task  (uint32_t f,  uint16_t p,  uint16_t t)
{
   task_t *novo;

   if(f == 0) return FALSE;

   /*
    * Aloca espa�o para uma nova tarefa.
    */
   novo = malloc(sizeof(task_t));
   if(novo == NULL) return FALSE;

   /*
    * Informa��es iniciais da tarefa.
    */
   novo->func = f;
   novo->par = p;
   novo->tempo = t;

   /*
    * Adiciona � lista de tarefas para execu��o.
    */
   disable();
   list_add(&_tasks, novo);
   enable();

   return TRUE;
}


/**
 * Cancela a execu��o de uma tarefa / callback se ainda n�o executada.
 * @param f Endere�o da tarefa.
 * @return TRUE se a tarefa foi removida.
 */
bool_t cancel_task (uint32_t f)
{
   register task_t *p;
   bool_t ok;

   if(f == 0) return FALSE;

   ok = FALSE;
   disable();

   /*
    * Procura na lista de tarefas.
    */
tenta:
   list_for_each(_tasks, p) {
      if(p->func == f) {
         /*
          * Tarefa encontrada: remove.
          */
         list_remove(&_tasks, p);
         free((void*)p);
         ok = TRUE;
         goto tenta;
      }
   }

   enable();
   return ok;
}
