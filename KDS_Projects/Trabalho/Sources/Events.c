/* ###################################################################
**     Filename    : Events.c
**     Project     : Trabalho
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-01-19, 18:35, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "App.h"

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LED_Blue_OnEnd (module Events)
**
**     Component   :  LED_Blue [PWM]
**     Description :
**         This event is called when the specified number of cycles has
**         been generated. (Only when the component is enabled -
**         <Enable> and the events are enabled - <EnableEvent>). The
**         event is available only when the <Interrupt service/event>
**         property is enabled and selected peripheral supports
**         appropriate interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED_Blue_OnEnd(void)
{
	/* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Clock_10_ms_OnInterrupt (module Events)
**
**     Component   :  Clock_10_ms [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Clock_10_ms_OnInterrupt(void)
{
	/* Write your code here ... */

	if(Aut_Light.states == State_IDLE)
	{
		// Há presença?
		if(Infrared_sensor_GetVal())
		{
			if(Aut_Light.debounce++ > 15)
			{
				// Debounce de 150ms OK!
				Aut_Light.debounce = 0;

				// A presença persiste?
				if(Infrared_sensor_GetVal())
				{
					// Light ON!
					Aut_Light.states = State_ON;
				}
			}
		}
		else
		{
			if(Aut_Light.pwm >= 30000)
			{
				if(Aut_Light.time_off-- <= 0)
				{
					// Light OFF!
					Aut_Light.states 	= State_OFF;
					Aut_Light.time_off 	= 0;
				}
			}
		}
	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
