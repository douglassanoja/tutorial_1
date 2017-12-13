/*
 tutorial_1
 
  @Company:
    Paolo Carlo Bernardi

  @File Name:
    main.c

  @Summary:
    Main section of the program tutorial_1
    http://www.paolocarlobernardi.it/index.php/en/embedded-en

  @Description:
    Tutorial's step 1,2,3:
       - Send a string via EUSART
       - Blink a LED
    Tutorial's step 4:
       - Added i2c_detect function
       - Cleaned main procedure adding utils file
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

#include "mcc_generated_files/mcc.h"
#include "tools/i2c_detect.h"
#include "tools/utils.h"

void main(void)
{    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    printWelcome();
    __delay_ms(2);  // wait a couple of msec to allow wake up of all devices
    i2c_detect();
    
    while (1)
    {
        positionLed();
    }
}
