/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
#ifndef PIN_DEF_H_
#define PIN_DEF_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "LAUNCHPAD.1.0.1.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
/* Keypad */
#define KP_PORT         GPIO_PORT_K
#define KP_PIN_IN_3     GPIO_PIN_7
#define KP_PIN_IN_2     GPIO_PIN_6
#define KP_PIN_IN_1     GPIO_PIN_5
#define KP_PIN_IN_0     GPIO_PIN_4
#define KP_PIN_OUT_3    GPIO_PIN_3
#define KP_PIN_OUT_2    GPIO_PIN_2
#define KP_PIN_OUT_1    GPIO_PIN_1
#define KP_PIN_OUT_0    GPIO_PIN_0

#define KP_PIN_IN       (KP_PIN_IN_3 |  \
                         KP_PIN_IN_2 |  \
                         KP_PIN_IN_1 |  \
                         KP_PIN_IN_0)

#define KP_PIN_OUT      (KP_PIN_OUT_3 | \
                         KP_PIN_OUT_2 | \
                         KP_PIN_OUT_1 | \
                         KP_PIN_OUT_0)

#define KP_PIN          (KP_PIN_IN |    \
                         KP_PIN_OUT)
//-----------------------------------------------------------------------------
/* LCD */

//-----------------------------------------------------------------------------
/* WiFi */
#define	WIFI_MODULE		UART3
#define	WIFI_INT		INT_UART3

#define	WIFI_PORT_DATA	GPIO_PORT_A
#define	WIFI_PIN_TX		GPIO_PIN_5
#define	WIFI_PIN_RX		GPIO_PIN_4

#define	WIFI_PORT_CTL	GPIO_PORT_A
#define	WIFI_PIN_RST	GPIO_PIN_3
#define	WIFI_PIN_EN		GPIO_PIN_2

#define WIFI_TIMER      TIMER0
#define WIFI_TIMER_SUB  TIMER_A
//-----------------------------------------------------------------------------
/* Actuator */
#define ACT_MODULE      GPIO_PORT_LED_12
#define ACT_PORT        GPIO_PORT_LED_12
#define ACT_PIN_1       GPIO_PIN_LED_1
#define ACT_PIN_2       GPIO_PIN_LED_2
//-----------------------------------------------------------------------------
/* ICDI */
#define ICDI_MODULE     UART_ICDI
#define ICDI_INT        INT_UART3
#define ICDI_PORT       GPIO_PORT_A
#define ICDI_PIN_TX     GPIO_PIN_1
#define ICDI_PIN_RX     GPIO_PIN_0


/******************************************************************************
 *	Function
 *****************************************************************************/


#endif /* PIN_DEF_H_ */

