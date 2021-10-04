/* 
 * File:   rfid.h
 * Author: 20185210
 *
 * Created on 4 de Outubro de 2021, 15:53
 */

#ifndef RFID_H
#define	RFID_H

void SPI_Initialize_Master();
void SPI_Initialize_Slave();
void SPI_Write(char incoming);
unsigned SPI_Ready2Read();
char SPI_Read(); //Read the received data

#endif	/* RFID_H */

