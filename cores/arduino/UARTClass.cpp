/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//smm <GPS03> START: UARTClass constructor - no portname input parameter
//smm <GPS03> Copy/paste all code from Arduino-IDE UARTClass.h & UARTClass.cpp files over code in respective PlatformIO-IDE files

//smm: Copying all code from Arduino-IDE/MXChip to PlatformIO/MXChip - UARTClass.h, UARTClass.cpp files.

//smm: Differences between PlatformIO vs. Arduino:

//smm: .h file:      ........... Platformio-IDE          ........... Arduino-IDE
//smm: (1)           #define UART_RCV_SIZE 128           #define UART_RCV_SIZE 256
//smm: (2)           UARTClass();                        UARTClass(UARTName p);  
//smm: (3)           ---                                 protected type,'UARTName port' declared in UARTClass

//smm: .cpp file:   .... Additions shown in Arduino-IDE code to implement UARTClass class with a port name input argument
//smm: (1) Arduino-IDE:  UARTClass class - port name input-parameter '(UARTName p)' added in implementation of UARTClass  
//smm: (2) Arduino-IDE:  UARTClass class - UARTClass::init member function implementation, added conditional code: 'if(port == UART_1)'

//smm <GPS03> END: UARTClass constructor - no portname input parameter


#include "mbed.h"
#include "UARTClass.h"
#include "BufferedSerial.h"

UARTClass::UARTClass()
{
  serial = NULL;
}

UARTClass::UARTClass(UARTName p)
{
  serial = NULL;
  port = p;
}

UARTClass::~UARTClass()
{
  //delete serial;
}

void UARTClass::begin(const uint32_t dwBaudRate)
{
  init();
  serial->baud(dwBaudRate);
}

void UARTClass::end(void)
{
  // TODO
}

size_t UARTClass::write(const uint8_t c)
{
  init();
  serial->putc(c);
  return 1;
}

size_t UARTClass::write(const uint8_t *buffer, size_t size)
{
  init();
  return serial->write(buffer, size);
}

int UARTClass::available( void )
{
  init();
  //return the amount of data available
  return serial->readable();
}

int UARTClass::availableForWrite(void)
{
  init();
  return serial->writable();
}

int  UARTClass::read(void)
{
  init();
  return serial->getc();
}

int UARTClass::peek( void )
{
  init();
  return serial->peek();
}

void UARTClass::flush( void )
{
  init();
  return serial->flush();
}

void UARTClass::init(void)
{
  if(serial == NULL)
  {
    if(port == UART_1) 
    {
      serial = new BufferedSerial(STDIO_UART1_TX, STDIO_UART1_RX, UART_RCV_SIZE);
    }
    else
    {
      serial = new BufferedSerial(STDIO_UART_TX, STDIO_UART_RX, UART_RCV_SIZE);
    }
  }
}
