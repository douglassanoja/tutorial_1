/*
 i2c_detect
 
  @Company:
    Paolo Carlo Bernardi

  @File Name:
    i2c_detect.h

  @Summary:
  i2c slave address detect function (header file)

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

#include "../mcc_generated_files/mcc.h"

#ifndef _I2CDETECT_H
#define _I2CDETECT_H

void i2c_detect(void);


#endif