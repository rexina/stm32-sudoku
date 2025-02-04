/**
  ******************************************************************************
  * @file    USART/USART_AutoBaudRate/main.c 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
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
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F0xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup USART_AutoBaudRate
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void USART_Configuration(void);
static void AutoBauRate_StartBitMethod(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{ 
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
  */
  
  /* Initialize LEDs available on STM320518-EVAL board ************************/
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  
  /* Configure and enable the systick timer to generate an interrupt each 1 ms */
  SysTick_Config((SystemCoreClock / 1000));
  
  /* USART configuration */
  USART_Configuration();
  
  /* AutoBaudRate for USART by Start bit Method */
  AutoBauRate_StartBitMethod();
  
  while(1);
}

/**
  * @brief Configure the USART Device
  * @param  None
  * @retval None
  */
static void USART_Configuration(void)
{ 
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure; 
  
  /* Enable GPIOA and DMA clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA , ENABLE);
  
  /* Enable USART1 APB clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  
  /* USART1 Pins configuration **************************************************/
  GPIO_DeInit(GPIOA);
  
  /* Connect pin to Periph */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);    
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1); 
  
  /* Configure pins as AF pushpull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure); 
  
  /* USARTx configured as follow:
  - BaudRate = 115200 baud  
  - Word Length = 8 Bits
  - Stop Bit = 1 Stop Bit
  - Parity = No Parity
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled
  */
  
  USART_DeInit(USART1);
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART1, &USART_InitStructure);
}

/**
  * @brief  Start Bit Method to USART AutoBaudRate.
  * @param  None
  * @retval None
  */
static void AutoBauRate_StartBitMethod(void)
{ 
  /* USART enable */
  USART_Cmd(USART1, ENABLE);
  
  /* Configure the AutoBaudRate method */
  USART_AutoBaudRateConfig(USART1, USART_AutoBaudRate_StartBit);
  
  /* Enable AutoBaudRate feature */
  USART_AutoBaudRateCmd(USART1, ENABLE);
  
  /* Wait until Receive enable acknowledge flag is set */
  while(USART_GetFlagStatus(USART1, USART_FLAG_REACK) == RESET)
  {}  
  
  /* Wait until Transmit enable acknowledge flag is set */  
  while(USART_GetFlagStatus(USART1, USART_FLAG_TEACK) == RESET)
  {}  
  
  /* Loop until the end of Autobaudrate phase */
  while(USART_GetFlagStatus(USART1, USART_FLAG_ABRF) == RESET)
  {}  
  
  /* If AutoBaudBate error occurred */
  if (USART_GetFlagStatus(USART1, USART_FLAG_ABRE) != RESET)
  {
    /* Turn on LED3 */
    STM_EVAL_LEDOn(LED3);
  }
  else
  {
    /* Turn on LED2 */
    STM_EVAL_LEDOn(LED2);
    
    /* Wait until RXNE flag is set */
    while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
    {}
    
    /* Wait until TXE flag is set */    
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
    {}
    
    /* Send received character */
    USART_SendData(USART1, USART_ReceiveData(USART1)); 
    
    /* clear the TE bit (if a transmission is on going or a data is in the TDR, it will be sent before
    efectivelly disabling the transmission) */
    USART_DirectionModeCmd(USART1, USART_Mode_Tx, DISABLE);
    
    /* Check the Transfer Complete Flag */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
    {}
  }
  
  /* USART Disable */
  USART_Cmd(USART1, DISABLE);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
