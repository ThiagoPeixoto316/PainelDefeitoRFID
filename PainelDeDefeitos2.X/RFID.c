/*
 * File:   RFID.c
 * Author: 20185210
 *
 * Created on 13 de Outubro de 2021, 15:38
 */


#include <xc.h>
#include "RFID.h"

void MFRC522_Init()
{
     MFRC522_CS_Direction = 0;
     MFRC522_Rst_Direction = 0;
     MFRC522_CS = 1;
     MFRC522_Rst = 1;
        
     MFRC522_Reset();
        
     MFRC522_Wr( TMODEREG, 0x8D );      //Tauto=1; f(Timer) = 6.78MHz/TPreScaler
     MFRC522_Wr( TPRESCALERREG, 0x3E ); //TModeReg[3..0] + TPrescalerReg
     MFRC522_Wr( TRELOADREGL, 30 );           
     MFRC522_Wr( TRELOADREGH, 0 );
        
     MFRC522_Wr( TXAUTOREG, 0x40 );    //100%ASK
     MFRC522_Wr( MODEREG, 0x3D );      // CRC valor inicial de 0x6363
        
     //MFRC522_Clear_Bit( STATUS2REG, 0x08 );//MFCrypto1On=0
     //MFRC522_Wr( RXSELREG, 0x86 );      //RxWait = RxSelReg[5..0]
     //MFRC522_Wr( RFCFGREG, 0x7F );     //RxGain = 48dB

     MFRC522_AntennaOn();
}

void MFRC522_Reset()
{
        MFRC522_Wr( COMMANDREG, PCD_RESETPHASE );
}
static void MFRC522_Wr( char addr, char value )
{
        MFRC522_CS = 0;
        SPI_Write( ( addr << 1 ) & 0x7E );
        SPI_Write( value );
        MFRC522_CS = 1;
}

void MFRC522_AntennaOn()
{
 MFRC522_Set_Bit( TXCONTROLREG, 0x03 );
}
static void MFRC522_Set_Bit( char addr, char mask )
{
     MFRC522_Wr( addr, MFRC522_Rd( addr ) | mask );
}
static char MFRC522_Rd( char addr )
{
char value;
        MFRC522_CS = 0;
        SPI_Write( (( addr << 1 ) & 0x7E) | 0x80 );
        value = SPI_Read( 0x00 );
        MFRC522_CS = 1;
        return (value);
}