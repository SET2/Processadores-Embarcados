/*
 * App.h
 *
 *  Created on: 20/01/2018
 *      Author: Eder Andrade
 */

#ifndef APP_H_
#define APP_H_

#include "PE_Types.h"

/* defines ***********************/
#define NUM_STATES	(byte)3

/* Function pointers *************/
typedef void (*pfunc)(void);

/* enums *************************/
typedef enum
{
	State_ON = 0,
	State_OFF	,
	State_IDLE	,

}en_States;

/* structs ***********************/
typedef struct
{
	// Variável para indicar os estados da máquina
	en_States states		;

	// Debounce para leitura do nível do sensor de infrared
	int16 	debounce		;

	// Valor do PWM
	int16	pwm				;

	// Tempo para desligamento quando não há presença
	int16 	time_off		;

	// Ponteiro de função que funcionará como a "máquina de estados"
	pfunc 	func_pointer[NUM_STATES];

}st_App;

/* externs ***********************/
extern st_App Aut_Light;

/* Prototypes ********************/
void Aut_ligh_Init	(void);
void Aut_light_ON	(void);
void Aut_light_OFF	(void);
void Aut_light_Idle	(void);


#endif /* APP_H_ */
