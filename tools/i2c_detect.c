/*
 i2c_detect
 
  @Company:
    Paolo Carlo Bernardi

  @File Name:
    i2c_detect.c

  @Summary:
  i2c slave address detect function 

  @Description:
  Function to find the I2C 7 bit address of a slave connected to the bus.
  It loops on querying the bus for address between 0x03 and 0x77. The detected
  device answers with an ACK char.  
*/

/*   Copyright 2017 Paolo Carlo Bernardi

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "i2c_detect.h"

void i2c_detect(void) {
    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;
    uint16_t slaveDeviceAddress;    // 16 bits because of 10 bit address devices
    uint8_t timeOut;                // to exit loop if device doesn't answer
    uint16_t toPending;             // timeOut pending msg: to exit loop if bus is hold
    uint8_t  writeBuffer[2];        // the data to be sent to slave
    bool found = false;

    writeBuffer[0] = (uint8_t)(slaveDeviceAddress);// low address
    writeBuffer[1] = 0x00;                         // sample data to be written
    
    printf("\n\ri2c_detect (scan from 0x03 to 0x77)");

    for (slaveDeviceAddress = 0x03; slaveDeviceAddress < 0x77; slaveDeviceAddress++) {
        
        timeOut = 0;
        
        while(status != I2C1_MESSAGE_FAIL)
        {
            // write one byte to device (2 is the length of writeBuffer)
            I2C1_MasterWrite(writeBuffer, 2, slaveDeviceAddress, &status);
            
            // wait for the message to be sent or status has changed.
            toPending = 0;
            while(status == I2C1_MESSAGE_PENDING) {
                if(toPending == 1000) {
                    printf("\n\r----> I2C bus hold by device");
                    break;
                }
                else
                    toPending++;
            }

            if (status == I2C1_MESSAGE_COMPLETE) {
                printf("\n\r----> Found device at address: 0x%02x ", slaveDeviceAddress);
                found = true;
                break;
            }

            if (timeOut == 100)
                break;
            else
                timeOut++;
        }
    }
        
    if (!found) {
        printf("\n\r----> No I2C slave found");
    }
    
}