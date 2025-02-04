/**
  @page TIM_One_Pulse TIM One Pulse example
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    TIM/One_Pulse/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Description of the TIM One Pulse example.
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

This example shows how to use the TIM peripheral to generate a One pulse Mode 
after a Rising edge of an external signal is received in Timer Input pin.

TIM2CLK = SystemCoreClock, we want to get TIM2 counter clock at 24 MHz:
  - Prescaler = (TIM2CLK / TIM2 counter clock) - 1

SystemCoreClock is set to 48 MHz.

The Autoreload value is 65535 (TIM2->ARR), so the maximum frequency value to 
trigger the TIM2 input is 24000000/65535 = 366.2 Hz.

The TIM2 is configured as follows: 
The One Pulse mode is used, the external signal is connected to TIM2 CH2 pin (PA.01), 
the rising edge is used as active edge, the One Pulse signal is output 
on TIM2_CH1 (PA.05).

The TIM_Pulse defines the delay value, the delay value is fixed to:
delay =  CCR1/TIM2 counter clock = 16383 / 24000000 = 682.6 us. 
The (TIM_Period - TIM_Pulse) defines the One Pulse value, the pulse value is fixed to:
One Pulse value = (TIM_Period - TIM_Pulse)/TIM2 counter clock 
                = (65535 - 16383) / 24000000 = 2.04 ms.
 

@par Directory contents 

  - TIM/One_Pulse/stm32f0xx_conf.h    Library Configuration file
  - TIM/One_Pulse/stm32f0xx_it.c      Interrupt handlers
  - TIM/One_Pulse/stm32f0xx_it.h      Interrupt handlers header file
  - TIM/One_Pulse/main.c              Main program
  - TIM/One_Pulse/system_stm32f0xx.c  STM32F0xx system source file
  
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
    - Connect the external signal to the TIM2_CH2 pin (PA.01)
    - Connect the TIM2_CH1 (PA.05) pin to an oscilloscope to monitor the waveform.


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
