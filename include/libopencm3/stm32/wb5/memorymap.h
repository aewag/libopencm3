/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- STM32 specific peripheral definitions ------------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE			(0x40000000U)
#define QUADSPI_BANK_BASE		(0x90000000U)
#define INFO_BASE			(0x1fff0000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x00010000)
#define PERIPH_BASE_APB3		(PERIPH_BASE + 0x20000000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x00020000)
#define PERIPH_BASE_AHB2		(PERIPH_BASE + 0x08000000)
#define PERIPH_BASE_AHB4		(PERIPH_BASE + 0x18000000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define LCD_BASE			(PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x5c00)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB1 + 0x6800)
#define USB_SRAM_BASE			(PERIPH_BASE_APB1 + 0x6c00)
#define LPTIM1_BASE			(PERIPH_BASE_APB1 + 0x7c00)
#define LPUART1_BASE			(PERIPH_BASE_APB1 + 0x8000)
#define LPTIM2_BASE			(PERIPH_BASE_APB1 + 0x9400)

/* APB2 */
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define VREFBUF_BASE			(PERIPH_BASE_APB2 + 0x0030)
#define COMP_BASE			(PERIPH_BASE_APB2 + 0x0200)
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x2C00)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define TIM16_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM17_BASE			(PERIPH_BASE_APB2 + 0x4800)

/* APB3 */
#define BLE_CTRL_BASE			(PERIPH_BASE_APB3 + 0x0000)
#define RADIO_CTRL_BASE			(PERIPH_BASE_APB3 + 0x0400)
#define I802154_CTRL_BASE               (PERIPH_BASE_APB3 + 0x1000)

/* AHB1 */
#define DMA1_BASE			(PERIPH_BASE_AHB1 + 0x0000)
#define DMA2_BASE			(PERIPH_BASE_AHB1 + 0x0400)
#define DMAMUX_BASE			(PERIPH_BASE_AHB1 + 0x0800)
#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)
#define TSC_BASE			(PERIPH_BASE_AHB1 + 0x4000)

/* AHB2 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB2 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB2 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB2 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB2 + 0x0c00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB2 + 0x1000)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB2 + 0x1c00)
/* Still AHB2, good job ST */
#define ADC_BASE			(0x50040000U + 0x0000)
#define AES1_BASE			(0x50060000U + 0x0000)

/* AHB4 */
#define RCC_BASE		        (PERIPH_BASE_AHB4 + 0x0000)
#define PWR_BASE		        (PERIPH_BASE_AHB4 + 0x0400)
#define EXTI_BASE		        (PERIPH_BASE_AHB4 + 0x0800)
#define IPCC_BASE		        (PERIPH_BASE_AHB4 + 0x0c00)
#define True_RNG_BASE		        (PERIPH_BASE_AHB4 + 0x1000)
#define HESM_BASE		        (PERIPH_BASE_AHB4 + 0x1400)
#define AES2_BASE		        (PERIPH_BASE_AHB4 + 0x1800)
#define PKA_BASE		        (PERIPH_BASE_AHB4 + 0x2000)
#define PKA_RAM_BASE		        (PERIPH_BASE_AHB4 + 0x2400)
#define FLASH_BASE		        (PERIPH_BASE_AHB4 + 0x4000)

/* Private peripherals */
#define DBGMCU_BASE			(PPBI_BASE + 0x00042000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x75e0)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x7590)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 0x14)
#define DESIG_PACKAGE			MMIO16((INFO_BASE + 0x7500))

#endif
