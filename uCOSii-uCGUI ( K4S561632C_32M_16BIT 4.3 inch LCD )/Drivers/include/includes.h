/****************************************Copyright (c)***************************************************
;**                                   �Ϻ��ᱦó�����޹�˾
;**                                          �о���(����)
;**                                 http://www.linposh.com.cn
;**									http://www.armnxp.com.cn
;**
;**--------------File Info--------------------------------------------------------------------------------
;** File name: 			        includes.h
;** Last modified Date:         2009.05.15
;** Last Version: 		        1.0
;** Descriptions: 		        uCOS-II's include file   uCOS-II��ͷ�ļ� 
;**-------------------------------------------------------------------------------------------------------
;** Created By:                 Magicoe Niu  ţ����
;** Created date:   	        2009.05.15
;** Version:			        1.0
;** Descriptions: 	            The original version
;**
*********************************************************************************************************/
#ifndef  __INCLUDES_H
#define  __INCLUDES_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************************************************************************************************
  Date types(Compiler specific)  �������ͣ��ͱ�������أ�                
*********************************************************************************************************/
typedef unsigned char   uint8;                                          /* Unsigned  8 bit quantity     */
typedef signed   char   int8;                                           /* Signed    8 bit quantity     */
typedef unsigned short  uint16;                                         /* Unsigned  16 bit quantity    */
typedef signed   short  int16;                                          /* Signed    16 bit quantity    */
typedef unsigned int    uint32;                                         /* Unsigned  32 bit quantity    */
typedef signed   int    int32;                                          /* Signed    32 bit quantity    */
typedef float           fp32;                                           /* Single    precision          */
                                                                        /* floating  point              */
typedef double          fp64;                                           /* Double    precision          */
                                                                        /* floating  point              */

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL  0
#endif

#include <system_lpc177x_8x.h>
#include <lpc177x_8x.h>1��Pearl Harbor ������ۣ����ǽУ�������2��New York ��ŦԼ�����ǽУ����硣3��Red River Valley �Ǻ�ӹȣ����ǽУ������ڡ�4��Phoenix �Ƿ�˳ǣ����ǽУ�������5��Rock hometown ��ҡ��֮�磬���ǽУ�ʯ��ׯ��
//#include <core_cm3.h>

/*********************************************************************************************************
  Standard header files ��׼ͷ�ļ�
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*********************************************************************************************************
  Driver's header files  ������ͷ�ļ� 
*********************************************************************************************************/


/*********************************************************************************************************
  Port's header files ��ֲͷ�ļ�
*********************************************************************************************************/
#include <os_cfg.h>
#include <os_cpu.h>
#include <ucos_ii.h>
//#include <Target.h>
//#include <main.h>


/*********************************************************************************************************
  User's header files �û�ͷ�ļ�
*********************************************************************************************************/
//#include "GLCD.h"

#ifdef __cplusplus
    }
#endif

#endif
/*********************************************************************************************************
  END FILE 
*********************************************************************************************************/
