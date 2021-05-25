#ifndef __GPIO_H__
#define __GPIO_H__
#define GPIO_BASE      0xbfd00000
#define CR0_ADDR       GPIO_BASE | 0x8000   //32'hbfd0_8000
#define CR1_ADDR       GPIO_BASE | 0x8004   //32'hbfd0_8004 
#define CR2_ADDR       GPIO_BASE | 0x8008   //32'hbfd0_8008 
#define CR3_ADDR       GPIO_BASE | 0x800c   //32'hbfd0_800c 
#define CR4_ADDR       GPIO_BASE | 0x8010   //32'hbfd0_8010 
#define CR5_ADDR       GPIO_BASE | 0x8014   //32'hbfd0_8014 
#define CR6_ADDR       GPIO_BASE | 0x8018   //32'hbfd0_8018 
#define CR7_ADDR       GPIO_BASE | 0x801c   //32'hbfd0_801c 

#define LED_ADDR       GPIO_BASE | 0xf000   //32'hbfd0_f000 
#define LED_RG0_ADDR   GPIO_BASE | 0xf004   //32'hbfd0_f004 
#define LED_RG1_ADDR   GPIO_BASE | 0xf008   //32'hbfd0_f008 
#define NUM_ADDR       GPIO_BASE | 0xf010   //32'hbfd0_f010
#define SWITCH_ADDR    GPIO_BASE | 0xf020   //32'hbfd0_f020 
#define TIMER_ADDR     GPIO_BASE | 0xe000   //32'hbfd0_e000 

#endif