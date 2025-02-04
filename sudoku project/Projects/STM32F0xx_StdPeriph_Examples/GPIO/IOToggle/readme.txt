/**
  @page GPIO_IOToggle GPIO IO Toggle example
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    GPIO/IOToggle/readme.txt  
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   GPIO IO Toggle example Description.
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

GPIO ports are connected on AHB bus, using BSRR and BRR registers two cycles are
required to set a pin and another two cycles to reset it. So GPIO pins can toggle
at AHB clock divided by 4.

This example describes how to use BSRR and BRR (Port Bit Set/Reset Register High 
and Low) for maximum IO toggling.

PC10 and PC11 when using the STM320518-EVAL (configured in output pushpull mode)
toggles in a forever loop:
 - Set PC10 and PC11 by setting corresponding bits in BSRR register
 - Reset PC10 and PC11 by setting corresponding bits in BRR register

In this example, HCLK is configured at 48 MHz so PC10 and PC11 toggles at 12MHz.
To achieve the maximum IO toggling frequency, you have to configure your compiler
options for high speed optimization.


@par Directory contents 

  - GPIO/IOToggle/stm32f0xx_conf.h    Library Configuration file
  - GPIO/IOToggle/stm32f0xx_it.c      Interrupt handlers
  - GPIO/IOToggle/stm32f0xx_it.h      Interrupt handlers header file
  - GPIO/IOToggle/main.c              Main program
  - GPIO/IOToggle/system_stm32f0xx.c  STM32F0xx system source file
  
@note The "system_stm32f0xx.c" is generated by an automatic clock configuration 
      tool and can be easily customized to meet user application requirements. 
      To select different clock setup, use the "STM32F0xx_Clock_Configuration_VX.Y.Z.xls" 
      provided with the AN4055 package available on <a href="http://www.st.com/internet/mcu/class/1734.jsp">  ST Microcontrollers </a>

         
@par Hardware and Software environment

  - This example runs on STM32F0xx Devices.
  
  - This example has been tested with STMicroelectronics STM320518-EVAL (STM32F0xx)
    evaluation board and can be easily tailored to any other supported device 
    and development board.


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
