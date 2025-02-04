/**
  @page SPI_MSD SPI Mirco SD Card example
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    SPI/SPI_MSD/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Description of the SPI Mirco SD Card example.
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

This example provides a basic example of how to use the SPI firmware library and
an associate SPI SDcard driver to communicate with an SDcard available on The eval board.

The first step consist in filling the SPI Tx buffer. Then this last one is written 
on the micro sd cards. A comparison between the Buffer transmitted (Buffer_Block_Tx)
and the received one (Buffer_Block_Rx) is done and LED1 is turned on in case of 
success otherwise LED2 is turned on.


@par Directory contents 

  - SPI/SPI_MSD/stm32f0xx_conf.h    Library Configuration file
  - SPI/SPI_MSD/stm32f0xx_it.c      Interrupt handlers
  - SPI/SPI_MSD/stm32f0xx_it.h      Interrupt handlers header file
  - SPI/SPI_MSD/main.c              Main program
  - SPI/SPI_MSD/main.h              Main program header file
  - SPI/SPI_MSD/system_stm32f0xx.c  STM32F0xx system source file
  
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
    - MicroSD card is already available on this board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F0xx_StdPeriph_Templates
 - Open your preferred toolchain 
 - Select STM32F0XX_MD(STM32F0x1xx) workspace 
 - Add the following files to the project source list
      - Utilities/STM32_EVAL/STM320518_EVAL/stm320518_eval.c
      - Utilities/STM32_EVAL/STM320518_EVAL/stm320518_eval_spi_sd.c 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
