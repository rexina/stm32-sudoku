/**
  @page PWMSignalControl COMP2 PWM signal control example
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    COMP/PWMSignalControl/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Description of the COMP2 PWM signal control example.
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

This example shows how to configure COMP2 peripheral to hold on safe state
(low level) TIM1 channels as soon as COMP2 output is set at high level.

  - COMP2 is configured as following:
     - Inverting input is internally connected to VREFINT = 1.22V
     - Non Inverting input is connected to PA3
     - Output is internally connected to TIM2 BKIN (Break Input)

  - TIM1CLK is set to 48 MHz, the TIM1 Prescaler is equal to 0 so the TIM1 counter
    clock used is 48 MHz.
    TIM1 frequency is defined as follow:
    TIM1 channels frequency = TIM1 counter clock / (Period + 1) 
                            = 48000000 /(100 + 1) 
                            = 475 KHz.

  - External voltage should be connected to PA3 (RV3 potentiometer can be used).

  - Connect an oscilloscope to TIM1 channel PA8 to display waveform. 

  - While PA3 is lower than VREFINT (1.22V), PWM signal is displayed on PA8.
    While PA3 is higher than VREFINT, PA8 is in low level.
 

@par Directory contents 

  - COMP/PWMSignalControl/stm32f0xx_conf.h    Library Configuration file
  - COMP/PWMSignalControl/stm32f0xx_it.c      Interrupt handlers
  - COMP/PWMSignalControl/stm32f0xx_it.h      Interrupt handlers header file
  - COMP/PWMSignalControl/main.c              Main program
  - COMP/PWMSignalControl/system_stm32f0xx.c  STM32F0xx system source file
  
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
    - RV3 Potentiometer connected to PC.01 pin.
    - Connect PA.03 to PC.01 pin using a wire.
    - Connect an oscilloscope to PA.08 pin to display waveform.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F0xx_StdPeriph_Templates
 - Open your preferred toolchain
 - Select STM32F0XX_MD(STM32F0x1xx) workspace  
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
