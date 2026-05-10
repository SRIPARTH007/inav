#pragma once

// 1. UNLOCK ALL GPIO PORTS
#define TARGET_IO_PORTA 0xFFFF
#define TARGET_IO_PORTB 0xFFFF
#define TARGET_IO_PORTC 0xFFFF
#define TARGET_IO_PORTD 0xFFFF
#define TARGET_IO_PORTE 0xFFFF
#define TARGET_IO_PORTH 0xFFFF

#define TARGET_BOARD_IDENTIFIER "M743"
#define USBD_PRODUCT_STRING     "KSPR_H743_V4"

// 2. CLOCK CONFIG (48MHz Crystal)
#ifdef HSE_VALUE
#undef HSE_VALUE
#endif
#define HSE_VALUE       48000000

// 3. LEDS (Direct Pin Names to avoid macro loops)
#define LED0                    PB11
#define LED1                    PE10
#define LED2                    PE15

// 4. SPI CONFIG
#define USE_SPI
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_6

#define SPI6_SCK_PIN            PA5
#define SPI6_MISO_PIN           PA6
#define SPI6_MOSI_PIN           PA7
#define USE_IMU_ICM42688
#define ICM42688_SPI_BUS        BUS_SPI6
#define ICM42688_CS_PIN         PA15

#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15
#define USE_IMU_BMI088
#define BMI088_SPI_BUS          BUS_SPI2
#define BMI088_GYRO_CS_PIN      PB12
#define BMI088_ACC_CS_PIN       PB0

// 5. I2C CONFIG (The Fix: Using Raw Pins + Clearer Bus Definitions)
#define USE_I2C
#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_4

// Force I2C1 (Mag)
#define I2C1_SCL                PB8
#define I2C1_SDA                PB9

// Force I2C4 (Baro)
#define I2C4_SCL                PB6
#define I2C4_SDA                PB7

#define USE_BARO
#define USE_BARO_BMP388
#define BARO_I2C_BUS            BUS_I2C4

#define USE_MAG
#define USE_MAG_BMM350
#define MAG_I2C_BUS             BUS_I2C1

// 6. ADC
#define USE_ADC
#define VBAT_ADC_PIN            PC0 
#define CURRENT_METER_ADC_PIN   PC1

// Force build start 6 - Clean Macro State
