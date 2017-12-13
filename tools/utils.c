/*
 utils
 
  @Company:
    Paolo Carlo Bernardi

  @File Name:
    utils.c

  @Summary:
    Various utility functions

  @Description:
    
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

#include "utils.h"

void printWelcome(void) {
    printf("\n\r+---------------------------------------------+");
    printf("\n\r| Welcome to Microchip PIC18 IOT from Scratch |");
    printf("\n\r+---------------------------------------------+\n\r");    
}

void positionLed(void) {
    
    static uint8_t blinkCount = 0;

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