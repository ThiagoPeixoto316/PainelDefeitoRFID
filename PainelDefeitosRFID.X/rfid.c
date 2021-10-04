/*
 * File:   rfid.c
 * Author: 20185210
 *
 * Created on 4 de Outubro de 2021, 15:53
 */


#include <xc.h>

void SPI_Initialize_Master()
{
    TRISC5 = 0; //
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 0; //Set as output for slave mode 
}

void SPI_Initialize_Slave()
{
    TRISC5 = 0; // SDO pin should be declared as output 
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 1; //Set as in out for master mode
}


void SPI_Write(char incoming) 
{
    SSPBUF = incoming; //Write the user given data into buffer
}

unsigned SPI_Ready2Read()
{
    if (SSPSTAT & 0b00000001)
        return 1;
    else
        return 0;
}

char SPI_Read() //Read the received data
{
    while ( !SSPSTATbits.BF ); // Hold till BF bit is set, to make sure the complete data is read
    return(SSPBUF); // return the read data
}

