/*
 * App.c
 *
 *  Created on: 20/01/2018
 *      Author: Eder Andrade
 */

/* User includes */
#include "App.h"

/* Processor Expert includes */
#include "Infrared_sensor.h"
#include "LED_Red.h"
#include "LED_Green.h"
#include "LED_Blue.h"
#include "WAIT1.h"



// Variável de estrutura da aplicação
st_App Aut_Light;


void Aut_ligh_Init(void)
{
	// Inicialização da estrutura da APLICAÇÂO!
	Aut_Light.states		= State_IDLE;
	Aut_Light.debounce 		= 0;
	Aut_Light.pwm			= 0;
	Aut_Light.time_off		= 0;
	Aut_Light.func_pointer[State_ON] 	= &Aut_light_ON;
	Aut_Light.func_pointer[State_OFF] 	= &Aut_light_OFF;
	Aut_Light.func_pointer[State_IDLE] 	= &Aut_light_Idle;

	// LEDs desligados!
	LED_Blue_SetRatio16(Aut_Light.pwm);
	LED_Red_SetVal	();
	LED_Green_SetVal();
}


void Aut_light_ON(void)
{
	// Acende os LEDs "vermelho" e "verde" para formar a luz branca com o LED "azul"
	LED_Red_ClrVal	();
	LED_Green_ClrVal();

	// Soft start
	while(Aut_Light.pwm++ < 30000)
	{
		LED_Blue_SetRatio16(Aut_Light.pwm);
		WAIT1_Waitus(100);
	}

	// Tempo para desligamento carregado = 10s
	Aut_Light.time_off 	= 1000;

	// Altera o estado da máquinas
	Aut_Light.states 	= State_IDLE;
}


void Aut_light_OFF(void)
{
	static word debounce = 0;

	// Soft "END"
	if(Aut_Light.time_off == 0)
	{
		while(Aut_Light.pwm-- > 0)
		{
			LED_Blue_SetRatio16(Aut_Light.pwm);
			WAIT1_Waitus(100);
		}

		// Apaga os LEDs
		LED_Red_SetVal	();
		LED_Green_SetVal();

		Aut_Light.pwm	 = 0;
		Aut_Light.states = State_IDLE;
	}
}



void Aut_light_Idle(void)
{
	WAIT1_Waitus(10);
}


