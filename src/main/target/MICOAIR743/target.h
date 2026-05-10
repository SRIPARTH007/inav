#pragma once

// *************** GPIO PORT UNLOCKS **********************
// Necessary to prevent "No pins are defined" error
#define TARGET_IO_PORTA 0xFFFF
#define TARGET_IO_PORTB 0xFFFF
#define TARGET_IO_PORTC 0xFFFF
#define TARGET_IO_PORTD 0xFFFF
#define TARGET_IO_PORTE 0xFFFF
#define TARGET_IO_PORTH 0xFFFF

#define TARGET_BOARD_IDENTIFIER "M743"
#define USBD_PRODUCT_STRING     "KSPR_H743_V4"

// *************** 48MHz CLOCK CONFIGURATION **********************
#ifdef HSE_VALUE
#undef HSE_VALUE
#endif
#define HSE_VALUE       48000000

// *************** LED **********************
#define LED0                    IO_TAG(PB11)
#define LED1                    IO_TAG(PE10)
#define LED2                    IO_TAG(PE15)

// *************** SPI DEVICES **********************
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

// *************** I2C DEVICES **********************
#define USE_I2C
#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_4

#define I2C4_SCL                IO_TAG(PB6)
#define I2C4_SDA                IO_TAG(PB7)

#define I2C1_SCL                IO_TAG(PB8)
#define I2C1_SDA                IO_TAG(PB9)

#define USE_BARO
#define USE_BARO_BMP388
#define BARO_I2C_BUS            BUS_I2C4

#define USE_MAG
#define USE_MAG_BMM350
#define MAG_I2C_BUS             BUS_I2C1

// *************** ADC *****************************
#define USE_ADC
#define VBAT_ADC_PIN            PC0 
#define CURRENT_METER_ADC_PIN   PC1

// Force build start 5
