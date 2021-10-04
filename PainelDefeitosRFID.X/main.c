/*
 * File:   main.c
 * Author: 20185210
 *
 * Created on 4 de Outubro de 2021, 15:28
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "ihm.h"
#include "lcd.h"
#include "rfid.h"

void main(void) 
{
    IHM.init();
    IHM.print("Iniciando");
    
    SPI_Initialize_Master();
   
    while(1)
    {   
        SPI_Write(0X0A);
        delay(100);
        SPI_Write(0X0F);
        delay(100);
        SPI_Write(0X15);
        delay(100);
    }
}
