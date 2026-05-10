#include <stdint.h>
#include "platform.h"

#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/timer.h"
#include "drivers/pwm_mapping.h"
#include "drivers/nvic.h"
#include "drivers/system.h"

// Timer Hardware Map for Motor Outputs
// Standard MICOAIR743 mapping for Motors 1-4
timerHardware_t timerHardware[] = {
    DEF_TIM(TIM8,  CH1, PC6,  TIM_USE_OUTPUT_AUTO, 0, 0), // Motor 1
    DEF_TIM(TIM8,  CH2, PC7,  TIM_USE_OUTPUT_AUTO, 0, 1), // Motor 2
    DEF_TIM(TIM8,  CH3, PC8,  TIM_USE_OUTPUT_AUTO, 0, 2), // Motor 3
    DEF_TIM(TIM8,  CH4, PC9,  TIM_USE_OUTPUT_AUTO, 0, 3), // Motor 4
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);

// Override for 48MHz Crystal for MICOAIR743
void targetSystemClockConfig(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
    while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    
    // --- MANDATORY 48MHz DIVIDER ---
    RCC_OscInitStruct.PLL.PLLM = 48; 
    // -------------------------------
    
    RCC_OscInitStruct.PLL.PLLN = 480;
    RCC_OscInitStruct.PLL.PLLP = 2;
    RCC_OscInitStruct.PLL.PLLQ = 20;
    RCC_OscInitStruct.PLL.PLLR = 2;
    RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_0;
    
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB3Divider = RCC_APB3_DIV2;
    RCC_ClkInitStruct.APB1Divider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2Divider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4Divider = RCC_APB4_DIV2;

    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
}
