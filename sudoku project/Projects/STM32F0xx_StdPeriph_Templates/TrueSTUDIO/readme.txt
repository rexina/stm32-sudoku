/**
  @page truestudio TrueSTUDIO Project Template for STM32F0xx devices
 
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   This sub-directory contains all the user-modifiable files needed to
  *          create a new project linked with the STM32F0xx Standard Peripherals
  *          Library and working with TrueSTUDIO software toolchain.
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
 
 @par Directory contents
 
 - .cproject/.project: A pre-configured project file with the provided library
                       structure that produces an executable image with TrueSTUDIO.

 - stm32_flash.ld:     This file is the TrueSTUDIO linker script used to 
                       place program code (readonly) in internal FLASH and
                       data (readwrite, Stack and Heap)in internal SRAM. 
                       You can customize this file to your need.
                                                          
 @par How to use it ?

 - Open the TrueSTUDIO toolchain.
 - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace 
   directory.
 - Click on File->Import, select General->'Existing Projects into Workspace' 
   and then click "Next". 
 - Browse to the TrueSTUDIO workspace directory and select the project: 
   - STM32F0XX_MD(STM32F0x1xx): to configure the project for STM32F0x1xx devices.
   - STM32F0XX_LD(STM32F0x0xx): to configure the project for STM32F0x0xx devices.
   - STM32F030: to configure the project for STM32F030 devices.
 - Rebuild all project files: Select the project in the "Project explorer" 
   window then click on Project->build project menu.
 - Run program: Select the project in the "Project explorer" window then click 
   Run->Debug (F11)

 @note The needed define symbols for this config are already declared in the
       preprocessor section: USE_STM320518_EVAL, STM32F0XX, USE_STDPERIPH_DRIVER 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

