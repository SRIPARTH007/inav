#pragma once

#define TARGET_BOARD_IDENTIFIER "M743"
#define USBD_PRODUCT_STRING     "KSPR_H743_V4"

// *************** 48MHz CLOCK CONFIGURATION **********************
// Fixed: Using undef/def to prevent "redefined" error
#ifdef HSE_VALUE
#undef HSE_VALUE
#endif
#define HSE_VALUE       48000000

// *************** LED **********************
#define LED0                    PB11  
#define LED1                    PE10  
#define LED2                    PE15  

// *************** SPI DEVICES **********************
#define USE_SPI
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_6

// Primary IMU: ICM42688 on SPI6
#define SPI6_SCK_PIN            PA5
#define SPI6_MISO_PIN           PA6
#define SPI6_MOSI_PIN           PA7
#define USE_IMU_ICM42688
#define ICM42688_SPI_BUS        BUS_SPI6
#define ICM42688_CS_PIN         PA15

// Secondary IMU: BMI088 on SPI2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15
#define USE_IMU_BMI088
#define BMI088_SPI_BUS          BUS_SPI2
#define BMI088_GYRO_CS_PIN      PB12
#define BMI088_ACC_CS_PIN       PB0

// *************** I2C DEVICES **********************
// Fixed: Wrapped pins in IO_TAG to prevent macro expansion errors
#define USE_I2C
#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_4

// Baros on I2C4 (PB6, PB7)
#define I2C4_SCL                IO_TAG(PB6)
#define I2C4_SDA                IO_TAG(PB7)

// Magnetometer on I2C1 (PB8, PB9)
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
// Force build start
