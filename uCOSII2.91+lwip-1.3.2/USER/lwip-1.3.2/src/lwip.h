/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               LWIP.h
** Descriptions:            The LWIP application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2011-3-9
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef __LWIP_H
#define __LWIP_H

/* Private define ------------------------------------------------------------*/
#define  EMAC_MAX_PACKET_SIZE  1536  /* 1536 bytes */

/* Private function prototypes -----------------------------------------------*/
void Init_lwIP(void);
void Display_IPAddress(void);
void Ethernet_Initialize(void);
int ethernet_send(void *pPacket, int size);

#endif 

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/