/**
  @page Battery_Charge_Monitoring ADC Basic Example Description
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    ADC/Battery_Charge_Monitoring/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   ADC Battery charge monitoring Description.
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

This example describes how to measure VBAT voltage using ADC1 regular channel 18.
In fact, the measured value correspond to VBAT/2; as the VBAT voltage could be higher
than VDDA, to ensure the correct operation of the ADC, the VBAT pin is internally
connected to a bridge divider by 2.

User can display the VBAT voltage on the EVAL Board LCD 


@par Directory contents 

  - ADC/Battery_Charge_Monitoring/stm32f0xx_conf.h    Library Configuration file
  - ADC/Battery_Charge_Monitoring/stm32f0xx_it.c      Interrupt handlers
  - ADC/Battery_Charge_Monitoring/stm32f0xx_it.h      Interrupt handlers header file
  - ADC/Battery_Charge_Monitoring/main.c              Main program
  - ADC/Battery_Charge_Monitoring/main.h              Main program header file
  - ADC/Battery_Charge_Monitoring/system_stm32f0xx.c  STM32F0xx system source file
  
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
    - Make sure that jumper JP12 is in position 2-3 to connect the 3V battery to VBAT pin

     
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
