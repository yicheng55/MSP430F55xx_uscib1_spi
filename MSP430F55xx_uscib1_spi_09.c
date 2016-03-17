/*
 * MSP430F5529_SST25VF.c
 *
 *  Created on: 2016/3/15
 *      Author: User1
 */
#include    <stdio.h>
#include    <string.h>
#include 	<msp430.h>
#include    "SST25VF.h"
#include    "spi.h"
#include    "FlashSPAN.h"


unsigned char upper_128[128];

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	int	i, ret ,ret1;
	unsigned long temp;
	uint32_t address;


	for(i=0; i< 128 ; i++)
	{
		upper_128[i] = 0x20+i;
	}


	address = 0x0;
	//sst25vf_Init();
	ret = flashSPAN_Init();
	//printf("\nret = %d \n",ret);
	ret1 = flashSPAN_EraseAll();
	//printf("ret = %d \n",ret);

	for(i=0; i< 50 ; i++);
	flashSPAN_Write(address, upper_128 , sizeof(upper_128));

	memset(upper_128,0x00,sizeof(upper_128));
	flashSPAN_Read(address, upper_128 , sizeof(upper_128));

	for(i=0; i< 128 ; i++)
	{
		printf("%x ", upper_128[i]);
	}


	temp = sst25vf_RDSR();
	//printf("\nRead_Status_Register= %lx ,size=%x\n", temp, sizeof(temp));
	return  0;
}
