/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32L4xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx Flash Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
 *
 * @date 12 February 2016
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
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

/*
 * For details see:
 * RM0434 Reference manual: STM32L4x6 advanced ARM®-based 32-bit MCUs
 * December 2015, Doc ID 024597 Rev 4
 */

/**@{*/
#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/stm32/common/flash_common_f.h>
#include <libopencm3/stm32/common/flash_common_idcache.h>

/* --- FLASH registers ------------------------------------------------------ */

#define FLASH_ACR		MMIO32(FLASH_BASE + 0x00)
#define FLASH_KEYR		MMIO32(FLASH_BASE + 0x08)
#define FLASH_OPTKEYR		MMIO32(FLASH_BASE + 0x0C)
#define FLASH_SR		MMIO32(FLASH_BASE + 0x10)
#define FLASH_CR		MMIO32(FLASH_BASE + 0x14)
#define FLASH_ECCR		MMIO32(FLASH_BASE + 0x18)
#define FLASH_OPTR		MMIO32(FLASH_BASE + 0x20)
#define FLASH_PCROP1ASR		MMIO32(FLASH_BASE + 0x24)
#define FLASH_PCROP1AER		MMIO32(FLASH_BASE + 0x28)
#define FLASH_WRP1AR		MMIO32(FLASH_BASE + 0x2C)
#define FLASH_WRP1BR		MMIO32(FLASH_BASE + 0x30)
#define FLASH_PCROP1BSR		MMIO32(FLASH_BASE + 0x34)
#define FLASH_PCROP1BER		MMIO32(FLASH_BASE + 0x38)
#define FLASH_IPCCBR		MMIO32(FLASH_BASE + 0x3C)
#define FLASH_C2ACR		MMIO32(FLASH_BASE + 0x5C)
#define FLASH_C2SR		MMIO32(FLASH_BASE + 0x60)
#define FLASH_C2CR		MMIO32(FLASH_BASE + 0x64)
#define FLASH_SFR		MMIO32(FLASH_BASE + 0x80)
#define FLASH_SRRVR		MMIO32(FLASH_BASE + 0x84)

/* --- FLASH_ACR values ----------------------------------------------------- */

#define FLASH_ACR_EMPTY		        (1 << 16)
#define FLASH_ACR_PES		        (1 << 15)
#define FLASH_ACR_DCRST		        (1 << 12)
#define FLASH_ACR_ICRST		        (1 << 11)
#define FLASH_ACR_DCEN		        (1 << 10)
#define FLASH_ACR_ICEN	        	(1 << 9)
#define FLASH_ACR_PRFTEN		(1 << 8)

#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		0x07

#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
#define FLASH_ACR_LATENCY_2WS		0x02
#define FLASH_ACR_LATENCY_3WS		0x03

/* --- FLASH_SR values ------------------------------------------------------ */

#define FLASH_SR_PESD			(1 << 19)
#define FLASH_SR_CFGBSY			(1 << 18)
#define FLASH_SR_BSY			(1 << 16)
#define FLASH_SR_OPTVERR		(1 << 15)
#define FLASH_SR_RDERR			(1 << 14)
#define FLASH_SR_OPTNV  		(1 << 13)
#define FLASH_SR_FASTERR		(1 << 9)
#define FLASH_SR_MISERR			(1 << 8)
#define FLASH_SR_PGSERR			(1 << 7)
#define FLASH_SR_SIZERR			(1 << 6)
#define FLASH_SR_PGAERR			(1 << 5)
#define FLASH_SR_WRPERR			(1 << 4)
#define FLASH_SR_PROGERR		(1 << 3)
#define FLASH_SR_OPERR			(1 << 1)
#define FLASH_SR_EOP			(1 << 0)

/* --- FLASH_CR values ------------------------------------------------------ */

#define FLASH_CR_LOCK			(1 << 31)
#define FLASH_CR_OPTLOCK		(1 << 30)
#define FLASH_CR_OBL_LAUNCH		(1 << 27)
#define FLASH_CR_RDERRIE		(1 << 26)
#define FLASH_CR_ERRIE			(1 << 25)
#define FLASH_CR_EOPIE			(1 << 24)
#define FLASH_CR_FSTPG			(1 << 18)
#define FLASH_CR_OPTSTRT		(1 << 17)
#define FLASH_CR_STRT			(1 << 16)
#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_PER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)

#define FLASH_CR_PNB_SHIFT		3
#define FLASH_CR_PNB_MASK		0xff

/* --- FLASH_ECCR values ---------------------------------------------------- */

#define FLASH_ECCR_ECCD			(1 << 31)
#define FLASH_ECCR_ECCC			(1 << 30)
#define FLASH_ECCR_ECCIE		(1 << 24)
#define FLASH_ECCR_SYSF_ECC		(1 << 20)

#define FLASH_ECCR_CPUID_SHIFT	        26
#define FLASH_ECCR_CPUID_MASK	        0x7

#define FLASH_ECCR_ADDR_ECC_SHIFT	0
#define FLASH_ECCR_ADDR_ECC_MASK	0x1ffff

/* --- FLASH_OPTR values ---------------------------------------------------- */

#define FLASH_OPTR_nBOOT0		(1 << 27)
#define FLASH_OPTR_nSWBOOT0		(1 << 26)
#define FLASH_OPTR_SRAM2_RST		(1 << 25)
#define FLASH_OPTR_SRAM2_PE		(1 << 24)
#define FLASH_OPTR_nBOOT1		(1 << 23)
#define FLASH_OPTR_WWDG_SW		(1 << 19)
#define FLASH_OPTR_IWDG_STDBY		(1 << 18)
#define FLASH_OPTR_IWDG_STOP		(1 << 17)
#define FLASH_OPTR_IDWG_SW		(1 << 16)
#define FLASH_OPTR_nRST_SHDW		(1 << 14)
#define FLASH_OPTR_nRST_STDBY		(1 << 13)
#define FLASH_OPTR_nRST_STOP		(1 << 12)
#define FLASH_OPTR_ESE  		(1 << 8)

#define FLASH_OPTR_AGC_TRIM_SHIFT	29
#define FLASH_OPTR_AGC_TRIM_MASK	0x7

#define FLASH_OPTR_BOR_SHIFT		8
#define FLASH_OPTR_BOR_MASK		0x7
#define FLASH_OPTR_BOR_LEVEL_0		0
#define FLASH_OPTR_BOR_LEVEL_1		1
#define FLASH_OPTR_BOR_LEVEL_2		2
#define FLASH_OPTR_BOR_LEVEL_3		3
#define FLASH_OPTR_BOR_LEVEL_4		4

#define FLASH_OPTR_RDP_SHIFT		0
#define FLASH_OPTR_RDP_MASK		0xff
#define FLASH_OPTR_RDP_LEVEL_0		0xAA
#define FLASH_OPTR_RDP_LEVEL_1		0xBB
#define FLASH_OPTR_RDP_LEVEL_2		0xCC

/* --- FLASH_PCROP1ASR values ----------------------------------------------- */

#define FLASH_PCROP1ASR_PCROP1_STRT_SHIFT	0
#define FLASH_PCROP1ASR_PCROP1_STRT_MASK	0x1ff

/* --- FLASH_PCROP1AER values ----------------------------------------------- */

#define FLASH_PCROP1AER_PCROP_RDP		(1 << 31)

#define FLASH_PCROP1AER_PCROP1A_END_SHIFT	0
#define FLASH_PCROP1AER_PCROP1A_END_MASK	0x1ff

/* --- FLASH_WRP1AR values -------------------------------------------------- */

#define FLASH_WRP1AR_WRP1A_END_SHIFT		16
#define FLASH_WRP1AR_WRP1A_END_MASK		0xff

#define FLASH_WRP1AR_WRP1A_STRT_SHIFT		0
#define FLASH_WRP1AR_WRP1A_STRT_MASK		0xff

/* --- FLASH_WRP1BR values -------------------------------------------------- */

#define FLASH_WRP1BR_WRP1B_END_SHIFT		16
#define FLASH_WRP1BR_WRP1B_END_MASK		0xff

#define FLASH_WRP1BR_WRP1B_STRT_SHIFT		0
#define FLASH_WRP1BR_WRP1B_STRT_MASK		0xff

/* --- FLASH_PCROP1BSR values ----------------------------------------------- */

#define FLASH_PCROP1BSR_PCROP1B_STRT_SHIFT	0
#define FLASH_PCROP1BSR_PCROP1B_STRT_MASK	0x1ff

/* --- FLASH_PCROP1BER values ----------------------------------------------- */

#define FLASH_PCROP1BER_PCROP1B_END_SHIFT	0
#define FLASH_PCROP1BER_PCROP1B_END_MASK	0x1ff

/* --- FLASH_IPCCBR values -------------------------------------------------- */

#define FLASH_IPCCBR_IPCCDBA_SHIFT      	0
#define FLASH_IPCCBR_IPCCDBA_MASK	        0x3fff

/* --- FLASH_SFR values ----------------------------------------------------- */

#define FLASH_SFR_DDS                           (1 << 12)
#define FLASH_SFR_FSD                           (1 << 8)

#define FLASH_SFR_SFSA_SHIFT      	        0
#define FLASH_SFR_SFSA_MASK	                0xff

/* --- FLASH_SRRVR values --------------------------------------------------- */

#define FLASH_SRRVR_C2OPT                       (1 << 31)
#define FLASH_SRRVR_NBRSD                       (1 << 30)
#define FLASH_SRRVR_BRSD                        (1 << 23)

#define FLASH_SRRVR_SNBRSA_SHIFT      	        25
#define FLASH_SRRVR_SNBRSA_MASK	                0x1f

#define FLASH_SRRVR_SBRSA_SHIFT      	        18
#define FLASH_SRRVR_SBRSA_MASK	                0x1f

#define FLASH_SRRVR_SBRV_SHIFT      	        0
#define FLASH_SRRVR_SBRV_MASK	                0x3ffff

/* --- FLASH_C2ACR values --------------------------------------------------- */

#define FLASH_C2ACR_PES		                (1 << 15)
#define FLASH_C2ACR_ICRST		        (1 << 11)
#define FLASH_C2ACR_ICEN	                (1 << 9)
#define FLASH_C2ACR_PRFTEN		        (1 << 8)

/* --- FLASH_C2SR values ---------------------------------------------------- */

#define FLASH_C2SR_PESD			        (1 << 19)
#define FLASH_C2SR_CFGBSY			(1 << 18)
#define FLASH_C2SR_BSY			        (1 << 16)
#define FLASH_C2SR_RDERR			(1 << 14)
#define FLASH_C2SR_FASTERR		        (1 << 9)
#define FLASH_C2SR_MISERR			(1 << 8)
#define FLASH_C2SR_PGSERR			(1 << 7)
#define FLASH_C2SR_SIZERR			(1 << 6)
#define FLASH_C2SR_PGAERR			(1 << 5)
#define FLASH_C2SR_WRPERR			(1 << 4)
#define FLASH_C2SR_PROGERR		        (1 << 3)
#define FLASH_C2SR_OPERR			(1 << 1)
#define FLASH_C2SR_EOP			        (1 << 0)

/* --- FLASH_C2CR values ---------------------------------------------------- */

#define FLASH_C2CR_RDERRIE		        (1 << 26)
#define FLASH_C2CR_ERRIE			(1 << 25)
#define FLASH_C2CR_EOPIE			(1 << 24)
#define FLASH_C2CR_FSTPG			(1 << 18)
#define FLASH_C2CR_STRT			        (1 << 16)
#define FLASH_C2CR_MER			        (1 << 2)
#define FLASH_C2CR_PER			        (1 << 1)
#define FLASH_C2CR_PG			        (1 << 0)

#define FLASH_C2CR_PNB_SHIFT		        3
#define FLASH_C2CR_PNB_MASK		        0xff

/* --- FLASH Keys ----------------------------------------------------------- */

#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

#define FLASH_OPTKEYR_KEY1		((uint32_t)0x08192a3b)
#define FLASH_OPTKEYR_KEY2		((uint32_t)0x4c5d6e7f)

/* --- Function prototypes -------------------------------------------------- */

BEGIN_DECLS

void flash_clear_progerr_flag(void);
void flash_clear_pgserr_flag(void);
void flash_clear_size_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_clear_wrperr_flag(void);
void flash_lock_option_bytes(void);
void flash_program_double_word(uint32_t address, uint64_t data);
void flash_program(uint32_t address, uint8_t *data, uint32_t len);
void flash_erase_page(uint32_t page);
void flash_erase_all_pages(void);
void flash_program_option_bytes(uint32_t data);

END_DECLS

#endif
/**@}*/
