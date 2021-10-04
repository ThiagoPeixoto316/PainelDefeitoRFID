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

void main(void) 
{
    IHM.init();
    IHM.print("Iniciando");
    while(1)
        ;
    
}
