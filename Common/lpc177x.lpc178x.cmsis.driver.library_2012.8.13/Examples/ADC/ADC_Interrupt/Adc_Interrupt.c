/**********************************************************************
* $Id$		Adc_Interrupt.c		2011-06-02
*//**
* @file		Adc_Interrupt.c
* @brief	This example describes how to use ADC conversion in
* 			interrupt mode
* @version	1.0
* @date		02. June. 2011
* @author	NXP MCU SW Application Team
*
* Copyright(C) 2011, NXP Semiconductor
* All rights reserved.
*
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors'
* relevant copyright in the software, without fee, provided that it
* is used in conjunction with NXP Semiconductors microcontrollers.  This
* copyright, permission, and disclaimer notice must appear in all copies of
* this code.
**********************************************************************/
#include "lpc177x_8x_adc.h"
#include "lpc177x_8x_pinsel.h"
#include "debug_frmwrk.h"
#include "bsp.h"

/* Example group ----------------------------------------------------------- */
/** @defgroup ADC_Interrupt		ADC Interrupt
 * @ingroup ADC_Examples
 * @{
 */

/************************** PRIVATE DEFINITIONS ***********************/


/************************** PRIVATE VARIABLES *************************/
uint8_t menu1[] =
"********************************************************************************\n\r"
" Hello NXP Semiconductors \n\r"
" ADC INTERRUPT example: \n\r"
"\t - MCU: LPC177x_8x \n\r"
"\t - Core: ARM CORTEX-M3 \n\r"
"\t - Communicate via: UART0\1\2 - 115200 bps \n\r"
" Use ADC with 12-bit resolution rate of 400KHz, read in INTERRUPT mode\n\r"
" To get ADC channel value and display via UART interface\n\r"
" Turn the potentiometer to see how ADC value changes\n\r"
" Press q to stop the demo\n\r"
"********************************************************************************\n\r";
__IO uint32_t adc_value;

/************************** PRIVATE FUNCTION *************************/
void ADC_IRQHandler(void);

void print_menu(void);

/*----------------- INTERRUPT SERVICE ROUTINES --------------------------*/
/*********************************************************************//**
 * @brief		ADC interrupt handler sub-routine
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void ADC_IRQHandler(void)
{
	adc_value = 0;

	if (ADC_ChannelGetStatus(LPC_ADC, BRD_ADC_PREPARED_CHANNEL, ADC_DATA_DONE))
	{
		adc_value =  ADC_ChannelGetData(LPC_ADC, BRD_ADC_PREPARED_CHANNEL);

		NVIC_DisableIRQ(ADC_IRQn);
	}
}

/*-------------------------PRIVATE FUNCTIONS------------------------------*/
/*********************************************************************//**
 * @brief		Print menu
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void print_menu(void)
{
	_DBG(menu1);
}

/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief		c_entry: Main ADC program body
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void c_entry(void)
{
	uint32_t tmp;
    uint8_t  quit;

	/* Initialize debug via UART0
	 * � 115200bps
	 * � 8 data bit
	 * � No parity
	 * � 1 stop bit
	 * � No flow control
	 */
	debug_frmwrk_init();

	// print welcome screen
	print_menu();

	/*
	 * Init ADC pin that currently is being used on the board
	 */
	PINSEL_ConfigPin (BRD_ADC_PREPARED_CH_PORT, BRD_ADC_PREPARED_CH_PIN, BRD_ADC_PREPARED_CH_FUNC_NO);
	PINSEL_SetAnalogPinMode(BRD_ADC_PREPARED_CH_PORT,BRD_ADC_PREPARED_CH_PIN,ENABLE);

	/* Configuration for ADC:
	 *  ADC conversion rate = 400KHz
	 */
	ADC_Init(LPC_ADC, 500000);

	ADC_IntConfig(LPC_ADC, BRD_ADC_PREPARED_INTR, ENABLE);
	ADC_ChannelCmd(LPC_ADC, BRD_ADC_PREPARED_CHANNEL, ENABLE);

	/* preemption = 1, sub-priority = 1 */
	NVIC_SetPriority(ADC_IRQn, ((0x01<<3)|0x01));

	while(1)
	{
		// Start conversion
		ADC_StartCmd(LPC_ADC, ADC_START_NOW);

		/* Enable ADC in NVIC */
		NVIC_EnableIRQ(ADC_IRQn);

		//Display the result of conversion on the UART0
		_DBG("ADC value on channel "); _DBD(BRD_ADC_PREPARED_CHANNEL);
		_DBG(" is: "); _DBD32(adc_value); _DBG_("");

		for(tmp = 0; tmp < 1000000; tmp++);
	    if(_DG_NONBLOCK(&quit) &&
			(quit == 'Q' || quit == 'q'))
			break;
	}
    _DBG_("Demo termination!!!");

	ADC_DeInit(LPC_ADC);
}

/* Support required entry point for other toolchain */
int main (void)
{
	c_entry();
	return 0;
}

/**
 * @}
 */
