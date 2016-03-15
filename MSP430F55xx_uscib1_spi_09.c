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
	int	i;
	unsigned long temp;
	uint32_t address;

	address = 0x0;
	//sst25vf_Init();
	flashSPAN_Init();
	flashSPAN_Read(address, upper_128 , sizeof(upper_128));

	for(i=0; i< 128 ; i++)
	{
		printf("%x ", upper_128[i]);
	}


	temp = sst25vf_RDSR();
	printf("\nRead_Status_Register= %lx ,size=%x\n", temp, sizeof(temp));
	return  0;
}
