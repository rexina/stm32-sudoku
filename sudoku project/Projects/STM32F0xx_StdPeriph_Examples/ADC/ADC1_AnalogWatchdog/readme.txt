/**
  @page ADC1_AnalogWatchdog ADC ADC1_AnalogWatchdog Description
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    ADC/ADC1_AnalogWatchdog/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Description of the ADC Analog Watchdog example.
  ******************************************************************************
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
   @endverbatim

@par Example Description 

This example describes how to use the ADC analog watchdog to guard continuously  
an ADC channel.
The ADC1 is configured to convert continuously ADC channel11 
The analog watchdog is configured and enabled to guard a single regular channel.
Each time the channel11 converted value exceeds programmed analog watchdog high 
threshold (value 3102) or goes down analog watchdog low threshold (value 1861)
an AWD interrupt is generated and the output pin connected to LED4 is toggled. The
LED will bright as long as the AWD interrupt is generated which means that the 
converted value of regular ADC channel11 is outside the range limited by high and 
low analog watchdog thresholds.

@note that ADC channel11 is connected to a potentiometer (RV3) which can deliver 
a voltage between 0V and 3.3V.


@par Directory contents 

  - ADC/ADC1_AnalogWatchdog/stm32f0xx_conf.h    Library Configuration file
  - ADC/ADC1_AnalogWatchdog/stm32f0xx_it.c      Interrupt handlers
  - ADC/ADC1_AnalogWatchdog/stm32f0xx_it.h      Interrupt handlers header file
  - ADC/ADC1_AnalogWatchdog/main.c              Main program
  - ADC/ADC1_AnalogWatchdog/main.h              Main program  header file
  - ADC/ADC1_AnalogWatchdog/system_stm32f0xx.c  STM32F0xx system source file
  
@note The "system_stm32f0xx.c" is generated by an automatic clock configuration 
      tool and can be easily customized to meet user application requirements. 
      To select different clock setup, use the "STM32F0xx_Clock_Configuration_VX.Y.Z.xls" 
      provided with the AN4055 package available on <a href="http://www.st.com/internet/mcu/class/1734.jsp">  ST Microcontrollers </a>

         
@par Hardware and Software environment

  - This example runs on STM32F0xx Devices.
  
  - This example has been tested with STMicroelectronics STM320518-EVAL (STM32F0xx)
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM320518-EVAL Set-up
     - Use potentiometer RV3

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F0xx_StdPeriph_Templates
 - Open your preferred toolchain
 - Select STM32F0XX_MD(STM32F0x1xx) workspace
 - Add the following files to the project source list
     - Utilities/STM32_EVAL/STM320518_EVAL/stm320518_eval.c
     - Utilities/STM32_EVAL/STM320518_EVAL/stm320518_eval_lcd.c  
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
