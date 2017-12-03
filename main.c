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

void main(void)
{
    uint8_t blinkCount = 0;
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    SYSTEM_Initialize();
    
    printf("\n\rMicrochip PIC18 IOT from Scratch\n\r");
    
    while (1)
    {
        if (TMR0_HasOverflowOccured()) {
            if (blinkCount < 4) {
                LED_Toggle();
            }
            TMR0_Initialize();
            blinkCount += 1;
            if (blinkCount == 9) {
                blinkCount = 0;
            }
        }
    }
}

/* Microchip original notes: */

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
