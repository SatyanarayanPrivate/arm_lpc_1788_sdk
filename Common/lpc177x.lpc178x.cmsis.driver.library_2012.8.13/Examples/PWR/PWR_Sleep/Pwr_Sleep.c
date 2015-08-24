/**********************************************************************
* $Id$		Pwr_Sleep.c		2011-06-02
*//**
* @file		Pwr_Sleep.c
* @brief	This example describes how to enter the system in deep
* 			sleep mode and wake-up by using Windowed Watchdog timer
* 			interrupt
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
#include "LPC177x_8x.h"
#include "lpc177x_8x_clkpwr.h"
#include "debug_frmwrk.h"
#include "lpc177x_8x_wwdt.h"


/** @defgroup PWR_Sleep	Pwr Mgr Sleep
 * @ingroup PWR_Examples
 * @{
 */


/************************** PRIVATE VARIABLES *************************/
uint8_t menu[]=
"********************************************************************************\n\r"
" Hello NXP Semiconductors \n\r"
" Power Sleep example: \n\r"
"\t - MCU: LPC177x_8x \n\r"
"\t - Core: ARM CORTEX-M3 \n\r"
"\t - UART Communication115200 bps \n\r"
" This example used to enter system in sleep mode and wake up it by using \n\r"
" Watchdog timer interrupt \n\r"
"********************************************************************************\n\r";
//Watchodog time out in 2 seconds
#define WWDT_TIMEOUT 	2000000

/************************** PRIVATE FUNCTIONS *************************/
void print_menu(void);
void WDT_IRQHandler(void);

/*----------------- INTERRUPT SERVICE ROUTINES --------------------------*/
void WDT_IRQHandler(void)
{
	// Disable WDT interrupt
	NVIC_DisableIRQ(WDT_IRQn);
	WWDT_ClrTimeOutFlag();
}

/*-------------------------PRIVATE FUNCTIONS------------------------------*/
/*********************************************************************//**
 * @brief		Print Welcome menu
 * @param[in]	none
 * @return 		None
 **********************************************************************/
void print_menu(void)
{
	_DBG(menu);
}

/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief		c_entry: Main program body
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void c_entry (void)
{
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

	// Init WDT, IRC OSC, interrupt mode, timeout = 2000000 us = 2s
	WWDT_Init(WWDT_TIMEOUT);

	_DBG_("Press '1' to enter system in Sleep mode");
	while(_DG !='1');

	NVIC_EnableIRQ(WDT_IRQn);
	WWDT_Cmd(ENABLE);
	WWDT_Start(WWDT_TIMEOUT);

	_DBG_("Enter Sleep mode!");
	_DBG_("Wait 2s for WDT wake-up system...");

	// Enter target into sleep mode
	CLKPWR_Sleep();
	_DBG_("\n\rSystem wake-up!\n\r");
	while(1);
}


/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */
int main(void)
{
	c_entry();
	return 0;
}



/**
 * @}
 */
