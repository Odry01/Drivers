/*
 * Component description for RTC
 *
 * Copyright (c) 2025 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*  file generated from device description file (ATDF) version 2025-02-18T10:55:45Z  */
#ifndef _PIC32CMJH01_RTC_COMPONENT_H_
#define _PIC32CMJH01_RTC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR RTC                       */
/* ************************************************************************** */

/* -------- RTC_MODE0_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE0 Control A -------- */
#define RTC_MODE0_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE0_CTRLA) MODE0 Control A  Reset Value */

#define RTC_MODE0_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE0_CTRLA) Software Reset Position */
#define RTC_MODE0_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLA_SWRST_Pos)         /* (RTC_MODE0_CTRLA) Software Reset Mask */
#define RTC_MODE0_CTRLA_SWRST(value)          (RTC_MODE0_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE0_CTRLA) Enable Position */
#define RTC_MODE0_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE0_CTRLA_ENABLE_Pos)        /* (RTC_MODE0_CTRLA) Enable Mask */
#define RTC_MODE0_CTRLA_ENABLE(value)         (RTC_MODE0_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE0_CTRLA) Operating Mode Position */
#define RTC_MODE0_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE0_CTRLA_MODE_Pos)          /* (RTC_MODE0_CTRLA) Operating Mode Mask */
#define RTC_MODE0_CTRLA_MODE(value)           (RTC_MODE0_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_MODE_Pos)) /* Assignment of value for MODE in the RTC_MODE0_CTRLA register */
#define   RTC_MODE0_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE0_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE0_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE0_CTRLA_MODE_COUNT32          (RTC_MODE0_CTRLA_MODE_COUNT32_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 0: 32-bit Counter Position */
#define RTC_MODE0_CTRLA_MODE_COUNT16          (RTC_MODE0_CTRLA_MODE_COUNT16_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 1: 16-bit Counter Position */
#define RTC_MODE0_CTRLA_MODE_CLOCK            (RTC_MODE0_CTRLA_MODE_CLOCK_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 2: Clock/Calendar Position */
#define RTC_MODE0_CTRLA_MATCHCLR_Pos          _UINT16_(7)                                          /* (RTC_MODE0_CTRLA) Clear on Match Position */
#define RTC_MODE0_CTRLA_MATCHCLR_Msk          (_UINT16_(0x1) << RTC_MODE0_CTRLA_MATCHCLR_Pos)      /* (RTC_MODE0_CTRLA) Clear on Match Mask */
#define RTC_MODE0_CTRLA_MATCHCLR(value)       (RTC_MODE0_CTRLA_MATCHCLR_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_MATCHCLR_Pos)) /* Assignment of value for MATCHCLR in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE0_CTRLA) Prescaler Position */
#define RTC_MODE0_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE0_CTRLA_PRESCALER_Pos)     /* (RTC_MODE0_CTRLA) Prescaler Mask */
#define RTC_MODE0_CTRLA_PRESCALER(value)      (RTC_MODE0_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_PRESCALER_Pos)) /* Assignment of value for PRESCALER in the RTC_MODE0_CTRLA register */
#define   RTC_MODE0_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE0_CTRLA_PRESCALER_OFF         (RTC_MODE0_CTRLA_PRESCALER_OFF_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV1        (RTC_MODE0_CTRLA_PRESCALER_DIV1_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV2        (RTC_MODE0_CTRLA_PRESCALER_DIV2_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV4        (RTC_MODE0_CTRLA_PRESCALER_DIV4_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV8        (RTC_MODE0_CTRLA_PRESCALER_DIV8_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV16       (RTC_MODE0_CTRLA_PRESCALER_DIV16_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV32       (RTC_MODE0_CTRLA_PRESCALER_DIV32_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV64       (RTC_MODE0_CTRLA_PRESCALER_DIV64_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV128      (RTC_MODE0_CTRLA_PRESCALER_DIV128_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV256      (RTC_MODE0_CTRLA_PRESCALER_DIV256_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV512      (RTC_MODE0_CTRLA_PRESCALER_DIV512_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position */
#define RTC_MODE0_CTRLA_PRESCALER_DIV1024     (RTC_MODE0_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position */
#define RTC_MODE0_CTRLA_COUNTSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE0_CTRLA) Count Read Synchronization Enable Position */
#define RTC_MODE0_CTRLA_COUNTSYNC_Msk         (_UINT16_(0x1) << RTC_MODE0_CTRLA_COUNTSYNC_Pos)     /* (RTC_MODE0_CTRLA) Count Read Synchronization Enable Mask */
#define RTC_MODE0_CTRLA_COUNTSYNC(value)      (RTC_MODE0_CTRLA_COUNTSYNC_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_COUNTSYNC_Pos)) /* Assignment of value for COUNTSYNC in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_Msk                   _UINT16_(0x8F8F)                                     /* (RTC_MODE0_CTRLA) Register Mask  */


/* -------- RTC_MODE1_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE1 Control A -------- */
#define RTC_MODE1_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_CTRLA) MODE1 Control A  Reset Value */

#define RTC_MODE1_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE1_CTRLA) Software Reset Position */
#define RTC_MODE1_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLA_SWRST_Pos)         /* (RTC_MODE1_CTRLA) Software Reset Mask */
#define RTC_MODE1_CTRLA_SWRST(value)          (RTC_MODE1_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE1_CTRLA) Enable Position */
#define RTC_MODE1_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE1_CTRLA_ENABLE_Pos)        /* (RTC_MODE1_CTRLA) Enable Mask */
#define RTC_MODE1_CTRLA_ENABLE(value)         (RTC_MODE1_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE1_CTRLA) Operating Mode Position */
#define RTC_MODE1_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE1_CTRLA_MODE_Pos)          /* (RTC_MODE1_CTRLA) Operating Mode Mask */
#define RTC_MODE1_CTRLA_MODE(value)           (RTC_MODE1_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_MODE_Pos)) /* Assignment of value for MODE in the RTC_MODE1_CTRLA register */
#define   RTC_MODE1_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE1_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE1_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE1_CTRLA_MODE_COUNT32          (RTC_MODE1_CTRLA_MODE_COUNT32_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 0: 32-bit Counter Position */
#define RTC_MODE1_CTRLA_MODE_COUNT16          (RTC_MODE1_CTRLA_MODE_COUNT16_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 1: 16-bit Counter Position */
#define RTC_MODE1_CTRLA_MODE_CLOCK            (RTC_MODE1_CTRLA_MODE_CLOCK_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 2: Clock/Calendar Position */
#define RTC_MODE1_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE1_CTRLA) Prescaler Position */
#define RTC_MODE1_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE1_CTRLA_PRESCALER_Pos)     /* (RTC_MODE1_CTRLA) Prescaler Mask */
#define RTC_MODE1_CTRLA_PRESCALER(value)      (RTC_MODE1_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_PRESCALER_Pos)) /* Assignment of value for PRESCALER in the RTC_MODE1_CTRLA register */
#define   RTC_MODE1_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE1_CTRLA_PRESCALER_OFF         (RTC_MODE1_CTRLA_PRESCALER_OFF_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV1        (RTC_MODE1_CTRLA_PRESCALER_DIV1_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV2        (RTC_MODE1_CTRLA_PRESCALER_DIV2_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV4        (RTC_MODE1_CTRLA_PRESCALER_DIV4_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV8        (RTC_MODE1_CTRLA_PRESCALER_DIV8_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV16       (RTC_MODE1_CTRLA_PRESCALER_DIV16_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV32       (RTC_MODE1_CTRLA_PRESCALER_DIV32_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV64       (RTC_MODE1_CTRLA_PRESCALER_DIV64_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV128      (RTC_MODE1_CTRLA_PRESCALER_DIV128_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV256      (RTC_MODE1_CTRLA_PRESCALER_DIV256_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV512      (RTC_MODE1_CTRLA_PRESCALER_DIV512_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position */
#define RTC_MODE1_CTRLA_PRESCALER_DIV1024     (RTC_MODE1_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position */
#define RTC_MODE1_CTRLA_COUNTSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE1_CTRLA) Count Read Synchronization Enable Position */
#define RTC_MODE1_CTRLA_COUNTSYNC_Msk         (_UINT16_(0x1) << RTC_MODE1_CTRLA_COUNTSYNC_Pos)     /* (RTC_MODE1_CTRLA) Count Read Synchronization Enable Mask */
#define RTC_MODE1_CTRLA_COUNTSYNC(value)      (RTC_MODE1_CTRLA_COUNTSYNC_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_COUNTSYNC_Pos)) /* Assignment of value for COUNTSYNC in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_Msk                   _UINT16_(0x8F0F)                                     /* (RTC_MODE1_CTRLA) Register Mask  */


/* -------- RTC_MODE2_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE2 Control A -------- */
#define RTC_MODE2_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE2_CTRLA) MODE2 Control A  Reset Value */

#define RTC_MODE2_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE2_CTRLA) Software Reset Position */
#define RTC_MODE2_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLA_SWRST_Pos)         /* (RTC_MODE2_CTRLA) Software Reset Mask */
#define RTC_MODE2_CTRLA_SWRST(value)          (RTC_MODE2_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE2_CTRLA) Enable Position */
#define RTC_MODE2_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLA_ENABLE_Pos)        /* (RTC_MODE2_CTRLA) Enable Mask */
#define RTC_MODE2_CTRLA_ENABLE(value)         (RTC_MODE2_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE2_CTRLA) Operating Mode Position */
#define RTC_MODE2_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE2_CTRLA_MODE_Pos)          /* (RTC_MODE2_CTRLA) Operating Mode Mask */
#define RTC_MODE2_CTRLA_MODE(value)           (RTC_MODE2_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_MODE_Pos)) /* Assignment of value for MODE in the RTC_MODE2_CTRLA register */
#define   RTC_MODE2_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE2_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE2_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE2_CTRLA_MODE_COUNT32          (RTC_MODE2_CTRLA_MODE_COUNT32_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 0: 32-bit Counter Position */
#define RTC_MODE2_CTRLA_MODE_COUNT16          (RTC_MODE2_CTRLA_MODE_COUNT16_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 1: 16-bit Counter Position */
#define RTC_MODE2_CTRLA_MODE_CLOCK            (RTC_MODE2_CTRLA_MODE_CLOCK_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 2: Clock/Calendar Position */
#define RTC_MODE2_CTRLA_CLKREP_Pos            _UINT16_(6)                                          /* (RTC_MODE2_CTRLA) Clock Representation Position */
#define RTC_MODE2_CTRLA_CLKREP_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLA_CLKREP_Pos)        /* (RTC_MODE2_CTRLA) Clock Representation Mask */
#define RTC_MODE2_CTRLA_CLKREP(value)         (RTC_MODE2_CTRLA_CLKREP_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_CLKREP_Pos)) /* Assignment of value for CLKREP in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_MATCHCLR_Pos          _UINT16_(7)                                          /* (RTC_MODE2_CTRLA) Clear on Match Position */
#define RTC_MODE2_CTRLA_MATCHCLR_Msk          (_UINT16_(0x1) << RTC_MODE2_CTRLA_MATCHCLR_Pos)      /* (RTC_MODE2_CTRLA) Clear on Match Mask */
#define RTC_MODE2_CTRLA_MATCHCLR(value)       (RTC_MODE2_CTRLA_MATCHCLR_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_MATCHCLR_Pos)) /* Assignment of value for MATCHCLR in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE2_CTRLA) Prescaler Position */
#define RTC_MODE2_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE2_CTRLA_PRESCALER_Pos)     /* (RTC_MODE2_CTRLA) Prescaler Mask */
#define RTC_MODE2_CTRLA_PRESCALER(value)      (RTC_MODE2_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_PRESCALER_Pos)) /* Assignment of value for PRESCALER in the RTC_MODE2_CTRLA register */
#define   RTC_MODE2_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE2_CTRLA_PRESCALER_OFF         (RTC_MODE2_CTRLA_PRESCALER_OFF_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV1        (RTC_MODE2_CTRLA_PRESCALER_DIV1_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV2        (RTC_MODE2_CTRLA_PRESCALER_DIV2_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV4        (RTC_MODE2_CTRLA_PRESCALER_DIV4_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV8        (RTC_MODE2_CTRLA_PRESCALER_DIV8_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV16       (RTC_MODE2_CTRLA_PRESCALER_DIV16_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV32       (RTC_MODE2_CTRLA_PRESCALER_DIV32_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV64       (RTC_MODE2_CTRLA_PRESCALER_DIV64_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV128      (RTC_MODE2_CTRLA_PRESCALER_DIV128_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV256      (RTC_MODE2_CTRLA_PRESCALER_DIV256_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV512      (RTC_MODE2_CTRLA_PRESCALER_DIV512_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position */
#define RTC_MODE2_CTRLA_PRESCALER_DIV1024     (RTC_MODE2_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position */
#define RTC_MODE2_CTRLA_CLOCKSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE2_CTRLA) Clock Read Synchronization Enable Position */
#define RTC_MODE2_CTRLA_CLOCKSYNC_Msk         (_UINT16_(0x1) << RTC_MODE2_CTRLA_CLOCKSYNC_Pos)     /* (RTC_MODE2_CTRLA) Clock Read Synchronization Enable Mask */
#define RTC_MODE2_CTRLA_CLOCKSYNC(value)      (RTC_MODE2_CTRLA_CLOCKSYNC_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_CLOCKSYNC_Pos)) /* Assignment of value for CLOCKSYNC in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_Msk                   _UINT16_(0x8FCF)                                     /* (RTC_MODE2_CTRLA) Register Mask  */


/* -------- RTC_MODE0_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE0 Control B -------- */
#define RTC_MODE0_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE0_CTRLB) MODE0 Control B  Reset Value */

#define RTC_MODE0_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE0_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE0_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLB_GP0EN_Pos)         /* (RTC_MODE0_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE0_CTRLB_GP0EN(value)          (RTC_MODE0_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_GP0EN_Pos)) /* Assignment of value for GP0EN in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_Msk                   _UINT16_(0x0001)                                     /* (RTC_MODE0_CTRLB) Register Mask  */


/* -------- RTC_MODE1_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE1 Control B -------- */
#define RTC_MODE1_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_CTRLB) MODE1 Control B  Reset Value */

#define RTC_MODE1_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE1_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE1_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLB_GP0EN_Pos)         /* (RTC_MODE1_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE1_CTRLB_GP0EN(value)          (RTC_MODE1_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_GP0EN_Pos)) /* Assignment of value for GP0EN in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_Msk                   _UINT16_(0x0001)                                     /* (RTC_MODE1_CTRLB) Register Mask  */


/* -------- RTC_MODE2_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE2 Control B -------- */
#define RTC_MODE2_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE2_CTRLB) MODE2 Control B  Reset Value */

#define RTC_MODE2_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE2_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE2_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLB_GP0EN_Pos)         /* (RTC_MODE2_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE2_CTRLB_GP0EN(value)          (RTC_MODE2_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_GP0EN_Pos)) /* Assignment of value for GP0EN in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_Msk                   _UINT16_(0x0001)                                     /* (RTC_MODE2_CTRLB) Register Mask  */


/* -------- RTC_MODE0_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE0 Event Control -------- */
#define RTC_MODE0_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE0_EVCTRL) MODE0 Event Control  Reset Value */

#define RTC_MODE0_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO0_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO0(value)        (RTC_MODE0_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO0_Pos)) /* Assignment of value for PEREO0 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO1_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO1(value)        (RTC_MODE0_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO1_Pos)) /* Assignment of value for PEREO1 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO2_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO2(value)        (RTC_MODE0_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO2_Pos)) /* Assignment of value for PEREO2 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO3_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO3(value)        (RTC_MODE0_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO3_Pos)) /* Assignment of value for PEREO3 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO4_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO4(value)        (RTC_MODE0_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO4_Pos)) /* Assignment of value for PEREO4 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO5_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO5(value)        (RTC_MODE0_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO5_Pos)) /* Assignment of value for PEREO5 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO6_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO6(value)        (RTC_MODE0_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO6_Pos)) /* Assignment of value for PEREO6 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO7_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO7(value)        (RTC_MODE0_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO7_Pos)) /* Assignment of value for PEREO7 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_CMPEO0_Pos           _UINT32_(8)                                          /* (RTC_MODE0_EVCTRL) Compare 0 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_CMPEO0_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_CMPEO0_Pos)       /* (RTC_MODE0_EVCTRL) Compare 0 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_CMPEO0(value)        (RTC_MODE0_EVCTRL_CMPEO0_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_CMPEO0_Pos)) /* Assignment of value for CMPEO0 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE0_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE0_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE0_EVCTRL_OVFEO_Pos)        /* (RTC_MODE0_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_OVFEO(value)         (RTC_MODE0_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_OVFEO_Pos)) /* Assignment of value for OVFEO in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE0_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PERDEO_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PERDEO(value)        (RTC_MODE0_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PERDEO_Pos)) /* Assignment of value for PERDEO in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_Msk                  _UINT32_(0x010081FF)                                 /* (RTC_MODE0_EVCTRL) Register Mask  */

#define RTC_MODE0_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE0_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE0_EVCTRL_PEREO_Pos)       /* (RTC_MODE0_EVCTRL Mask) PEREO */
#define RTC_MODE0_EVCTRL_PEREO(value)         (RTC_MODE0_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO_Pos)) 
#define RTC_MODE0_EVCTRL_CMPEO_Pos            _UINT32_(8)                                          /* (RTC_MODE0_EVCTRL Position) Compare x Event Output Enable */
#define RTC_MODE0_EVCTRL_CMPEO_Msk            (_UINT32_(0x1) << RTC_MODE0_EVCTRL_CMPEO_Pos)        /* (RTC_MODE0_EVCTRL Mask) CMPEO */
#define RTC_MODE0_EVCTRL_CMPEO(value)         (RTC_MODE0_EVCTRL_CMPEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_CMPEO_Pos)) 

/* -------- RTC_MODE1_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE1 Event Control -------- */
#define RTC_MODE1_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE1_EVCTRL) MODE1 Event Control  Reset Value */

#define RTC_MODE1_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO0_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO0(value)        (RTC_MODE1_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO0_Pos)) /* Assignment of value for PEREO0 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO1_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO1(value)        (RTC_MODE1_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO1_Pos)) /* Assignment of value for PEREO1 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO2_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO2(value)        (RTC_MODE1_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO2_Pos)) /* Assignment of value for PEREO2 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO3_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO3(value)        (RTC_MODE1_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO3_Pos)) /* Assignment of value for PEREO3 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO4_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO4(value)        (RTC_MODE1_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO4_Pos)) /* Assignment of value for PEREO4 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO5_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO5(value)        (RTC_MODE1_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO5_Pos)) /* Assignment of value for PEREO5 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO6_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO6(value)        (RTC_MODE1_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO6_Pos)) /* Assignment of value for PEREO6 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO7_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO7(value)        (RTC_MODE1_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO7_Pos)) /* Assignment of value for PEREO7 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_CMPEO0_Pos           _UINT32_(8)                                          /* (RTC_MODE1_EVCTRL) Compare 0 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_CMPEO0_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_CMPEO0_Pos)       /* (RTC_MODE1_EVCTRL) Compare 0 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_CMPEO0(value)        (RTC_MODE1_EVCTRL_CMPEO0_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO0_Pos)) /* Assignment of value for CMPEO0 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_CMPEO1_Pos           _UINT32_(9)                                          /* (RTC_MODE1_EVCTRL) Compare 1 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_CMPEO1_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_CMPEO1_Pos)       /* (RTC_MODE1_EVCTRL) Compare 1 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_CMPEO1(value)        (RTC_MODE1_EVCTRL_CMPEO1_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO1_Pos)) /* Assignment of value for CMPEO1 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE1_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE1_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE1_EVCTRL_OVFEO_Pos)        /* (RTC_MODE1_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_OVFEO(value)         (RTC_MODE1_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_OVFEO_Pos)) /* Assignment of value for OVFEO in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE1_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PERDEO_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PERDEO(value)        (RTC_MODE1_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PERDEO_Pos)) /* Assignment of value for PERDEO in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_Msk                  _UINT32_(0x010083FF)                                 /* (RTC_MODE1_EVCTRL) Register Mask  */

#define RTC_MODE1_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE1_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE1_EVCTRL_PEREO_Pos)       /* (RTC_MODE1_EVCTRL Mask) PEREO */
#define RTC_MODE1_EVCTRL_PEREO(value)         (RTC_MODE1_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO_Pos)) 
#define RTC_MODE1_EVCTRL_CMPEO_Pos            _UINT32_(8)                                          /* (RTC_MODE1_EVCTRL Position) Compare x Event Output Enable */
#define RTC_MODE1_EVCTRL_CMPEO_Msk            (_UINT32_(0x3) << RTC_MODE1_EVCTRL_CMPEO_Pos)        /* (RTC_MODE1_EVCTRL Mask) CMPEO */
#define RTC_MODE1_EVCTRL_CMPEO(value)         (RTC_MODE1_EVCTRL_CMPEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO_Pos)) 

/* -------- RTC_MODE2_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE2 Event Control -------- */
#define RTC_MODE2_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE2_EVCTRL) MODE2 Event Control  Reset Value */

#define RTC_MODE2_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO0_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO0(value)        (RTC_MODE2_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO0_Pos)) /* Assignment of value for PEREO0 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO1_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO1(value)        (RTC_MODE2_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO1_Pos)) /* Assignment of value for PEREO1 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO2_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO2(value)        (RTC_MODE2_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO2_Pos)) /* Assignment of value for PEREO2 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO3_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO3(value)        (RTC_MODE2_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO3_Pos)) /* Assignment of value for PEREO3 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO4_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO4(value)        (RTC_MODE2_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO4_Pos)) /* Assignment of value for PEREO4 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO5_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO5(value)        (RTC_MODE2_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO5_Pos)) /* Assignment of value for PEREO5 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO6_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO6(value)        (RTC_MODE2_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO6_Pos)) /* Assignment of value for PEREO6 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO7_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO7(value)        (RTC_MODE2_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO7_Pos)) /* Assignment of value for PEREO7 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_ALARMEO0_Pos         _UINT32_(8)                                          /* (RTC_MODE2_EVCTRL) Alarm 0 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_ALARMEO0_Msk         (_UINT32_(0x1) << RTC_MODE2_EVCTRL_ALARMEO0_Pos)     /* (RTC_MODE2_EVCTRL) Alarm 0 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_ALARMEO0(value)      (RTC_MODE2_EVCTRL_ALARMEO0_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_ALARMEO0_Pos)) /* Assignment of value for ALARMEO0 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE2_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE2_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE2_EVCTRL_OVFEO_Pos)        /* (RTC_MODE2_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_OVFEO(value)         (RTC_MODE2_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_OVFEO_Pos)) /* Assignment of value for OVFEO in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE2_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PERDEO_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PERDEO(value)        (RTC_MODE2_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PERDEO_Pos)) /* Assignment of value for PERDEO in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_Msk                  _UINT32_(0x010081FF)                                 /* (RTC_MODE2_EVCTRL) Register Mask  */

#define RTC_MODE2_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE2_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE2_EVCTRL_PEREO_Pos)       /* (RTC_MODE2_EVCTRL Mask) PEREO */
#define RTC_MODE2_EVCTRL_PEREO(value)         (RTC_MODE2_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO_Pos)) 
#define RTC_MODE2_EVCTRL_ALARMEO_Pos          _UINT32_(8)                                          /* (RTC_MODE2_EVCTRL Position) Alarm x Event Output Enable */
#define RTC_MODE2_EVCTRL_ALARMEO_Msk          (_UINT32_(0x1) << RTC_MODE2_EVCTRL_ALARMEO_Pos)      /* (RTC_MODE2_EVCTRL Mask) ALARMEO */
#define RTC_MODE2_EVCTRL_ALARMEO(value)       (RTC_MODE2_EVCTRL_ALARMEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_ALARMEO_Pos)) 

/* -------- RTC_MODE0_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE0 Interrupt Enable Clear -------- */
#define RTC_MODE0_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE0_INTENCLR) MODE0 Interrupt Enable Clear  Reset Value */

#define RTC_MODE0_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER0_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER0(value)        (RTC_MODE0_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER1_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER1(value)        (RTC_MODE0_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER2_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER2(value)        (RTC_MODE0_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER3_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER3(value)        (RTC_MODE0_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER4_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER4(value)        (RTC_MODE0_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER5_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER5(value)        (RTC_MODE0_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER6_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER6(value)        (RTC_MODE0_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER7_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER7(value)        (RTC_MODE0_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE0_INTENCLR) Compare 0 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_CMP0_Pos)       /* (RTC_MODE0_INTENCLR) Compare 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_CMP0(value)        (RTC_MODE0_INTENCLR_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE0_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENCLR_OVF_Pos)        /* (RTC_MODE0_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_OVF(value)         (RTC_MODE0_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_Msk                _UINT16_(0x81FF)                                     /* (RTC_MODE0_INTENCLR) Register Mask  */

#define RTC_MODE0_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE0_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE0_INTENCLR_PER_Pos)       /* (RTC_MODE0_INTENCLR Mask) PER */
#define RTC_MODE0_INTENCLR_PER(value)         (RTC_MODE0_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER_Pos)) 
#define RTC_MODE0_INTENCLR_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTENCLR Position) Compare x Interrupt Enable */
#define RTC_MODE0_INTENCLR_CMP_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENCLR_CMP_Pos)        /* (RTC_MODE0_INTENCLR Mask) CMP */
#define RTC_MODE0_INTENCLR_CMP(value)         (RTC_MODE0_INTENCLR_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_CMP_Pos)) 

/* -------- RTC_MODE1_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE1 Interrupt Enable Clear -------- */
#define RTC_MODE1_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE1_INTENCLR) MODE1 Interrupt Enable Clear  Reset Value */

#define RTC_MODE1_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER0_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER0(value)        (RTC_MODE1_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER1_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER1(value)        (RTC_MODE1_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER2_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER2(value)        (RTC_MODE1_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER3_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER3(value)        (RTC_MODE1_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER4_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER4(value)        (RTC_MODE1_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER5_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER5(value)        (RTC_MODE1_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER6_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER6(value)        (RTC_MODE1_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER7_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER7(value)        (RTC_MODE1_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE1_INTENCLR) Compare 0 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_CMP0_Pos)       /* (RTC_MODE1_INTENCLR) Compare 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_CMP0(value)        (RTC_MODE1_INTENCLR_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_CMP1_Pos           _UINT16_(9)                                          /* (RTC_MODE1_INTENCLR) Compare 1 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_CMP1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_CMP1_Pos)       /* (RTC_MODE1_INTENCLR) Compare 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_CMP1(value)        (RTC_MODE1_INTENCLR_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP1_Pos)) /* Assignment of value for CMP1 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE1_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE1_INTENCLR_OVF_Pos)        /* (RTC_MODE1_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_OVF(value)         (RTC_MODE1_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_Msk                _UINT16_(0x83FF)                                     /* (RTC_MODE1_INTENCLR) Register Mask  */

#define RTC_MODE1_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE1_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE1_INTENCLR_PER_Pos)       /* (RTC_MODE1_INTENCLR Mask) PER */
#define RTC_MODE1_INTENCLR_PER(value)         (RTC_MODE1_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER_Pos)) 
#define RTC_MODE1_INTENCLR_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTENCLR Position) Compare x Interrupt Enable */
#define RTC_MODE1_INTENCLR_CMP_Msk            (_UINT16_(0x3) << RTC_MODE1_INTENCLR_CMP_Pos)        /* (RTC_MODE1_INTENCLR Mask) CMP */
#define RTC_MODE1_INTENCLR_CMP(value)         (RTC_MODE1_INTENCLR_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP_Pos)) 

/* -------- RTC_MODE2_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE2 Interrupt Enable Clear -------- */
#define RTC_MODE2_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE2_INTENCLR) MODE2 Interrupt Enable Clear  Reset Value */

#define RTC_MODE2_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER0_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER0(value)        (RTC_MODE2_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER1_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER1(value)        (RTC_MODE2_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER2_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER2(value)        (RTC_MODE2_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER3_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER3(value)        (RTC_MODE2_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER4_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER4(value)        (RTC_MODE2_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER5_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER5(value)        (RTC_MODE2_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER6_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER6(value)        (RTC_MODE2_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER7_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER7(value)        (RTC_MODE2_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_ALARM0_Pos         _UINT16_(8)                                          /* (RTC_MODE2_INTENCLR) Alarm 0 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_ALARM0_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENCLR_ALARM0_Pos)     /* (RTC_MODE2_INTENCLR) Alarm 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_ALARM0(value)      (RTC_MODE2_INTENCLR_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_ALARM0_Pos)) /* Assignment of value for ALARM0 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE2_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE2_INTENCLR_OVF_Pos)        /* (RTC_MODE2_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_OVF(value)         (RTC_MODE2_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_Msk                _UINT16_(0x81FF)                                     /* (RTC_MODE2_INTENCLR) Register Mask  */

#define RTC_MODE2_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE2_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE2_INTENCLR_PER_Pos)       /* (RTC_MODE2_INTENCLR Mask) PER */
#define RTC_MODE2_INTENCLR_PER(value)         (RTC_MODE2_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER_Pos)) 
#define RTC_MODE2_INTENCLR_ALARM_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTENCLR Position) Alarm x Interrupt Enable */
#define RTC_MODE2_INTENCLR_ALARM_Msk          (_UINT16_(0x1) << RTC_MODE2_INTENCLR_ALARM_Pos)      /* (RTC_MODE2_INTENCLR Mask) ALARM */
#define RTC_MODE2_INTENCLR_ALARM(value)       (RTC_MODE2_INTENCLR_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_ALARM_Pos)) 

/* -------- RTC_MODE0_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE0 Interrupt Enable Set -------- */
#define RTC_MODE0_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE0_INTENSET) MODE0 Interrupt Enable Set  Reset Value */

#define RTC_MODE0_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER0_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER0(value)        (RTC_MODE0_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER1_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER1(value)        (RTC_MODE0_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER2_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER2(value)        (RTC_MODE0_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER3_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER3(value)        (RTC_MODE0_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER4_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER4(value)        (RTC_MODE0_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER5_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER5(value)        (RTC_MODE0_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER6_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER6(value)        (RTC_MODE0_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER7_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER7(value)        (RTC_MODE0_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE0_INTENSET) Compare 0 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_CMP0_Pos)       /* (RTC_MODE0_INTENSET) Compare 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_CMP0(value)        (RTC_MODE0_INTENSET_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE0_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE0_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENSET_OVF_Pos)        /* (RTC_MODE0_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_OVF(value)         (RTC_MODE0_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_Msk                _UINT16_(0x81FF)                                     /* (RTC_MODE0_INTENSET) Register Mask  */

#define RTC_MODE0_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTENSET Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE0_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE0_INTENSET_PER_Pos)       /* (RTC_MODE0_INTENSET Mask) PER */
#define RTC_MODE0_INTENSET_PER(value)         (RTC_MODE0_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER_Pos)) 
#define RTC_MODE0_INTENSET_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTENSET Position) Compare x Interrupt Enable */
#define RTC_MODE0_INTENSET_CMP_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENSET_CMP_Pos)        /* (RTC_MODE0_INTENSET Mask) CMP */
#define RTC_MODE0_INTENSET_CMP(value)         (RTC_MODE0_INTENSET_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_CMP_Pos)) 

/* -------- RTC_MODE1_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE1 Interrupt Enable Set -------- */
#define RTC_MODE1_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE1_INTENSET) MODE1 Interrupt Enable Set  Reset Value */

#define RTC_MODE1_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER0_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER0(value)        (RTC_MODE1_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER1_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER1(value)        (RTC_MODE1_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER2_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER2(value)        (RTC_MODE1_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER3_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER3(value)        (RTC_MODE1_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER4_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER4(value)        (RTC_MODE1_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER5_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER5(value)        (RTC_MODE1_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER6_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER6(value)        (RTC_MODE1_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER7_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER7(value)        (RTC_MODE1_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE1_INTENSET) Compare 0 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_CMP0_Pos)       /* (RTC_MODE1_INTENSET) Compare 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_CMP0(value)        (RTC_MODE1_INTENSET_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_CMP1_Pos           _UINT16_(9)                                          /* (RTC_MODE1_INTENSET) Compare 1 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_CMP1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_CMP1_Pos)       /* (RTC_MODE1_INTENSET) Compare 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_CMP1(value)        (RTC_MODE1_INTENSET_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP1_Pos)) /* Assignment of value for CMP1 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE1_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE1_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE1_INTENSET_OVF_Pos)        /* (RTC_MODE1_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_OVF(value)         (RTC_MODE1_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_Msk                _UINT16_(0x83FF)                                     /* (RTC_MODE1_INTENSET) Register Mask  */

#define RTC_MODE1_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTENSET Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE1_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE1_INTENSET_PER_Pos)       /* (RTC_MODE1_INTENSET Mask) PER */
#define RTC_MODE1_INTENSET_PER(value)         (RTC_MODE1_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER_Pos)) 
#define RTC_MODE1_INTENSET_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTENSET Position) Compare x Interrupt Enable */
#define RTC_MODE1_INTENSET_CMP_Msk            (_UINT16_(0x3) << RTC_MODE1_INTENSET_CMP_Pos)        /* (RTC_MODE1_INTENSET Mask) CMP */
#define RTC_MODE1_INTENSET_CMP(value)         (RTC_MODE1_INTENSET_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP_Pos)) 

/* -------- RTC_MODE2_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE2 Interrupt Enable Set -------- */
#define RTC_MODE2_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE2_INTENSET) MODE2 Interrupt Enable Set  Reset Value */

#define RTC_MODE2_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 0 Enable Position */
#define RTC_MODE2_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER0_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 0 Enable Mask */
#define RTC_MODE2_INTENSET_PER0(value)        (RTC_MODE2_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 1 Enable Position */
#define RTC_MODE2_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER1_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 1 Enable Mask */
#define RTC_MODE2_INTENSET_PER1(value)        (RTC_MODE2_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 2 Enable Position */
#define RTC_MODE2_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER2_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 2 Enable Mask */
#define RTC_MODE2_INTENSET_PER2(value)        (RTC_MODE2_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 3 Enable Position */
#define RTC_MODE2_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER3_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 3 Enable Mask */
#define RTC_MODE2_INTENSET_PER3(value)        (RTC_MODE2_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 4 Enable Position */
#define RTC_MODE2_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER4_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 4 Enable Mask */
#define RTC_MODE2_INTENSET_PER4(value)        (RTC_MODE2_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 5 Enable Position */
#define RTC_MODE2_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER5_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 5 Enable Mask */
#define RTC_MODE2_INTENSET_PER5(value)        (RTC_MODE2_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 6 Enable Position */
#define RTC_MODE2_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER6_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 6 Enable Mask */
#define RTC_MODE2_INTENSET_PER6(value)        (RTC_MODE2_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 7 Enable Position */
#define RTC_MODE2_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER7_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 7 Enable Mask */
#define RTC_MODE2_INTENSET_PER7(value)        (RTC_MODE2_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_ALARM0_Pos         _UINT16_(8)                                          /* (RTC_MODE2_INTENSET) Alarm 0 Interrupt Enable Position */
#define RTC_MODE2_INTENSET_ALARM0_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENSET_ALARM0_Pos)     /* (RTC_MODE2_INTENSET) Alarm 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENSET_ALARM0(value)      (RTC_MODE2_INTENSET_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_ALARM0_Pos)) /* Assignment of value for ALARM0 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE2_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE2_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE2_INTENSET_OVF_Pos)        /* (RTC_MODE2_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE2_INTENSET_OVF(value)         (RTC_MODE2_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_Msk                _UINT16_(0x81FF)                                     /* (RTC_MODE2_INTENSET) Register Mask  */

#define RTC_MODE2_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTENSET Position) Periodic Interval x Enable */
#define RTC_MODE2_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE2_INTENSET_PER_Pos)       /* (RTC_MODE2_INTENSET Mask) PER */
#define RTC_MODE2_INTENSET_PER(value)         (RTC_MODE2_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER_Pos)) 
#define RTC_MODE2_INTENSET_ALARM_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTENSET Position) Alarm x Interrupt Enable */
#define RTC_MODE2_INTENSET_ALARM_Msk          (_UINT16_(0x1) << RTC_MODE2_INTENSET_ALARM_Pos)      /* (RTC_MODE2_INTENSET Mask) ALARM */
#define RTC_MODE2_INTENSET_ALARM(value)       (RTC_MODE2_INTENSET_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_ALARM_Pos)) 

/* -------- RTC_MODE0_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE0 Interrupt Flag Status and Clear -------- */
#define RTC_MODE0_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE0_INTFLAG) MODE0 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE0_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE0_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER0_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE0_INTFLAG_PER0(value)         (RTC_MODE0_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE0_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER1_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE0_INTFLAG_PER1(value)         (RTC_MODE0_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE0_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER2_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE0_INTFLAG_PER2(value)         (RTC_MODE0_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE0_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER3_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE0_INTFLAG_PER3(value)         (RTC_MODE0_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE0_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER4_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE0_INTFLAG_PER4(value)         (RTC_MODE0_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE0_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER5_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE0_INTFLAG_PER5(value)         (RTC_MODE0_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE0_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER6_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE0_INTFLAG_PER6(value)         (RTC_MODE0_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE0_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER7_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE0_INTFLAG_PER7(value)         (RTC_MODE0_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_CMP0_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTFLAG) Compare 0 Position */
#define RTC_MODE0_INTFLAG_CMP0_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_CMP0_Pos)        /* (RTC_MODE0_INTFLAG) Compare 0 Mask */
#define RTC_MODE0_INTFLAG_CMP0(value)         (RTC_MODE0_INTFLAG_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE0_INTFLAG) Overflow Position */
#define RTC_MODE0_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE0_INTFLAG_OVF_Pos)         /* (RTC_MODE0_INTFLAG) Overflow Mask */
#define RTC_MODE0_INTFLAG_OVF(value)          (RTC_MODE0_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_Msk                 _UINT16_(0x81FF)                                     /* (RTC_MODE0_INTFLAG) Register Mask  */

#define RTC_MODE0_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE0_INTFLAG Position) Periodic Interval x */
#define RTC_MODE0_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE0_INTFLAG_PER_Pos)        /* (RTC_MODE0_INTFLAG Mask) PER */
#define RTC_MODE0_INTFLAG_PER(value)          (RTC_MODE0_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER_Pos)) 
#define RTC_MODE0_INTFLAG_CMP_Pos             _UINT16_(8)                                          /* (RTC_MODE0_INTFLAG Position) Compare x */
#define RTC_MODE0_INTFLAG_CMP_Msk             (_UINT16_(0x1) << RTC_MODE0_INTFLAG_CMP_Pos)         /* (RTC_MODE0_INTFLAG Mask) CMP */
#define RTC_MODE0_INTFLAG_CMP(value)          (RTC_MODE0_INTFLAG_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_CMP_Pos)) 

/* -------- RTC_MODE1_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE1 Interrupt Flag Status and Clear -------- */
#define RTC_MODE1_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE1_INTFLAG) MODE1 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE1_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE1_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER0_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE1_INTFLAG_PER0(value)         (RTC_MODE1_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE1_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER1_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE1_INTFLAG_PER1(value)         (RTC_MODE1_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE1_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER2_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE1_INTFLAG_PER2(value)         (RTC_MODE1_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE1_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER3_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE1_INTFLAG_PER3(value)         (RTC_MODE1_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE1_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER4_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE1_INTFLAG_PER4(value)         (RTC_MODE1_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE1_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER5_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE1_INTFLAG_PER5(value)         (RTC_MODE1_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE1_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER6_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE1_INTFLAG_PER6(value)         (RTC_MODE1_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE1_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER7_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE1_INTFLAG_PER7(value)         (RTC_MODE1_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_CMP0_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTFLAG) Compare 0 Position */
#define RTC_MODE1_INTFLAG_CMP0_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_CMP0_Pos)        /* (RTC_MODE1_INTFLAG) Compare 0 Mask */
#define RTC_MODE1_INTFLAG_CMP0(value)         (RTC_MODE1_INTFLAG_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP0_Pos)) /* Assignment of value for CMP0 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_CMP1_Pos            _UINT16_(9)                                          /* (RTC_MODE1_INTFLAG) Compare 1 Position */
#define RTC_MODE1_INTFLAG_CMP1_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_CMP1_Pos)        /* (RTC_MODE1_INTFLAG) Compare 1 Mask */
#define RTC_MODE1_INTFLAG_CMP1(value)         (RTC_MODE1_INTFLAG_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP1_Pos)) /* Assignment of value for CMP1 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE1_INTFLAG) Overflow Position */
#define RTC_MODE1_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE1_INTFLAG_OVF_Pos)         /* (RTC_MODE1_INTFLAG) Overflow Mask */
#define RTC_MODE1_INTFLAG_OVF(value)          (RTC_MODE1_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_Msk                 _UINT16_(0x83FF)                                     /* (RTC_MODE1_INTFLAG) Register Mask  */

#define RTC_MODE1_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE1_INTFLAG Position) Periodic Interval x */
#define RTC_MODE1_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE1_INTFLAG_PER_Pos)        /* (RTC_MODE1_INTFLAG Mask) PER */
#define RTC_MODE1_INTFLAG_PER(value)          (RTC_MODE1_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER_Pos)) 
#define RTC_MODE1_INTFLAG_CMP_Pos             _UINT16_(8)                                          /* (RTC_MODE1_INTFLAG Position) Compare x */
#define RTC_MODE1_INTFLAG_CMP_Msk             (_UINT16_(0x3) << RTC_MODE1_INTFLAG_CMP_Pos)         /* (RTC_MODE1_INTFLAG Mask) CMP */
#define RTC_MODE1_INTFLAG_CMP(value)          (RTC_MODE1_INTFLAG_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP_Pos)) 

/* -------- RTC_MODE2_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE2 Interrupt Flag Status and Clear -------- */
#define RTC_MODE2_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE2_INTFLAG) MODE2 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE2_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE2_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER0_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE2_INTFLAG_PER0(value)         (RTC_MODE2_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER0_Pos)) /* Assignment of value for PER0 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE2_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER1_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE2_INTFLAG_PER1(value)         (RTC_MODE2_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER1_Pos)) /* Assignment of value for PER1 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE2_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER2_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE2_INTFLAG_PER2(value)         (RTC_MODE2_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER2_Pos)) /* Assignment of value for PER2 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE2_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER3_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE2_INTFLAG_PER3(value)         (RTC_MODE2_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER3_Pos)) /* Assignment of value for PER3 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE2_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER4_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE2_INTFLAG_PER4(value)         (RTC_MODE2_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER4_Pos)) /* Assignment of value for PER4 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE2_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER5_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE2_INTFLAG_PER5(value)         (RTC_MODE2_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER5_Pos)) /* Assignment of value for PER5 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE2_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER6_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE2_INTFLAG_PER6(value)         (RTC_MODE2_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER6_Pos)) /* Assignment of value for PER6 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE2_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER7_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE2_INTFLAG_PER7(value)         (RTC_MODE2_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER7_Pos)) /* Assignment of value for PER7 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_ALARM0_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTFLAG) Alarm 0 Position */
#define RTC_MODE2_INTFLAG_ALARM0_Msk          (_UINT16_(0x1) << RTC_MODE2_INTFLAG_ALARM0_Pos)      /* (RTC_MODE2_INTFLAG) Alarm 0 Mask */
#define RTC_MODE2_INTFLAG_ALARM0(value)       (RTC_MODE2_INTFLAG_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_ALARM0_Pos)) /* Assignment of value for ALARM0 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE2_INTFLAG) Overflow Position */
#define RTC_MODE2_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE2_INTFLAG_OVF_Pos)         /* (RTC_MODE2_INTFLAG) Overflow Mask */
#define RTC_MODE2_INTFLAG_OVF(value)          (RTC_MODE2_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_OVF_Pos)) /* Assignment of value for OVF in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_Msk                 _UINT16_(0x81FF)                                     /* (RTC_MODE2_INTFLAG) Register Mask  */

#define RTC_MODE2_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE2_INTFLAG Position) Periodic Interval x */
#define RTC_MODE2_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE2_INTFLAG_PER_Pos)        /* (RTC_MODE2_INTFLAG Mask) PER */
#define RTC_MODE2_INTFLAG_PER(value)          (RTC_MODE2_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER_Pos)) 
#define RTC_MODE2_INTFLAG_ALARM_Pos           _UINT16_(8)                                          /* (RTC_MODE2_INTFLAG Position) Alarm x */
#define RTC_MODE2_INTFLAG_ALARM_Msk           (_UINT16_(0x1) << RTC_MODE2_INTFLAG_ALARM_Pos)       /* (RTC_MODE2_INTFLAG Mask) ALARM */
#define RTC_MODE2_INTFLAG_ALARM(value)        (RTC_MODE2_INTFLAG_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_ALARM_Pos)) 

/* -------- RTC_DBGCTRL : (RTC Offset: 0x0E) (R/W 8) Debug Control -------- */
#define RTC_DBGCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (RTC_DBGCTRL) Debug Control  Reset Value */

#define RTC_DBGCTRL_DBGRUN_Pos                _UINT8_(0)                                           /* (RTC_DBGCTRL) Run During Debug Position */
#define RTC_DBGCTRL_DBGRUN_Msk                (_UINT8_(0x1) << RTC_DBGCTRL_DBGRUN_Pos)             /* (RTC_DBGCTRL) Run During Debug Mask */
#define RTC_DBGCTRL_DBGRUN(value)             (RTC_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << RTC_DBGCTRL_DBGRUN_Pos)) /* Assignment of value for DBGRUN in the RTC_DBGCTRL register */
#define RTC_DBGCTRL_Msk                       _UINT8_(0x01)                                        /* (RTC_DBGCTRL) Register Mask  */


/* -------- RTC_MODE0_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE0 Synchronization Busy Status -------- */
#define RTC_MODE0_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE0_SYNCBUSY) MODE0 Synchronization Busy Status  Reset Value */

#define RTC_MODE0_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE0_SYNCBUSY) Software Reset Busy Position */
#define RTC_MODE0_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE0_SYNCBUSY) Software Reset Busy Mask */
#define RTC_MODE0_SYNCBUSY_SWRST(value)       (RTC_MODE0_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE0_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE0_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE0_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE0_SYNCBUSY_ENABLE(value)      (RTC_MODE0_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE0_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE0_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE0_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_FREQCORR(value)    (RTC_MODE0_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_FREQCORR_Pos)) /* Assignment of value for FREQCORR in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COUNT_Pos          _UINT32_(3)                                          /* (RTC_MODE0_SYNCBUSY) COUNT Register Busy Position */
#define RTC_MODE0_SYNCBUSY_COUNT_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COUNT_Pos)      /* (RTC_MODE0_SYNCBUSY) COUNT Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_COUNT(value)       (RTC_MODE0_SYNCBUSY_COUNT_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COUNT_Pos)) /* Assignment of value for COUNT in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COMP0_Pos          _UINT32_(5)                                          /* (RTC_MODE0_SYNCBUSY) COMP 0 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_COMP0_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COMP0_Pos)      /* (RTC_MODE0_SYNCBUSY) COMP 0 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_COMP0(value)       (RTC_MODE0_SYNCBUSY_COMP0_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COMP0_Pos)) /* Assignment of value for COMP0 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE0_SYNCBUSY) Count Synchronization Enable Bit Busy Position */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk      (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos)  /* (RTC_MODE0_SYNCBUSY) Count Synchronization Enable Bit Busy Mask */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC(value)   (RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos)) /* Assignment of value for COUNTSYNC in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE0_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_GP0_Pos)        /* (RTC_MODE0_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_GP0(value)         (RTC_MODE0_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP0_Pos)) /* Assignment of value for GP0 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE0_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_GP1_Pos)        /* (RTC_MODE0_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_GP1(value)         (RTC_MODE0_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP1_Pos)) /* Assignment of value for GP1 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_Msk                _UINT32_(0x0003802F)                                 /* (RTC_MODE0_SYNCBUSY) Register Mask  */

#define RTC_MODE0_SYNCBUSY_COMP_Pos           _UINT32_(5)                                          /* (RTC_MODE0_SYNCBUSY Position) COMP x Register Busy */
#define RTC_MODE0_SYNCBUSY_COMP_Msk           (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COMP_Pos)       /* (RTC_MODE0_SYNCBUSY Mask) COMP */
#define RTC_MODE0_SYNCBUSY_COMP(value)        (RTC_MODE0_SYNCBUSY_COMP_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COMP_Pos)) 
#define RTC_MODE0_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE0_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE0_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE0_SYNCBUSY_GP_Pos)         /* (RTC_MODE0_SYNCBUSY Mask) GP */
#define RTC_MODE0_SYNCBUSY_GP(value)          (RTC_MODE0_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP_Pos)) 

/* -------- RTC_MODE1_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE1 Synchronization Busy Status -------- */
#define RTC_MODE1_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE1_SYNCBUSY) MODE1 Synchronization Busy Status  Reset Value */

#define RTC_MODE1_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE1_SYNCBUSY) Software Reset Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE1_SYNCBUSY) Software Reset Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_SWRST(value)       (RTC_MODE1_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE1_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE1_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_ENABLE(value)      (RTC_MODE1_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE1_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE1_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE1_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_FREQCORR(value)    (RTC_MODE1_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_FREQCORR_Pos)) /* Assignment of value for FREQCORR in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COUNT_Pos          _UINT32_(3)                                          /* (RTC_MODE1_SYNCBUSY) COUNT Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COUNT_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COUNT_Pos)      /* (RTC_MODE1_SYNCBUSY) COUNT Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COUNT(value)       (RTC_MODE1_SYNCBUSY_COUNT_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COUNT_Pos)) /* Assignment of value for COUNT in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_PER_Pos            _UINT32_(4)                                          /* (RTC_MODE1_SYNCBUSY) PER Register Busy Position */
#define RTC_MODE1_SYNCBUSY_PER_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_PER_Pos)        /* (RTC_MODE1_SYNCBUSY) PER Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_PER(value)         (RTC_MODE1_SYNCBUSY_PER_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_PER_Pos)) /* Assignment of value for PER in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COMP0_Pos          _UINT32_(5)                                          /* (RTC_MODE1_SYNCBUSY) COMP 0 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COMP0_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COMP0_Pos)      /* (RTC_MODE1_SYNCBUSY) COMP 0 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COMP0(value)       (RTC_MODE1_SYNCBUSY_COMP0_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP0_Pos)) /* Assignment of value for COMP0 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COMP1_Pos          _UINT32_(6)                                          /* (RTC_MODE1_SYNCBUSY) COMP 1 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COMP1_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COMP1_Pos)      /* (RTC_MODE1_SYNCBUSY) COMP 1 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COMP1(value)       (RTC_MODE1_SYNCBUSY_COMP1_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP1_Pos)) /* Assignment of value for COMP1 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE1_SYNCBUSY) Count Synchronization Enable Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC_Msk      (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos)  /* (RTC_MODE1_SYNCBUSY) Count Synchronization Enable Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC(value)   (RTC_MODE1_SYNCBUSY_COUNTSYNC_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos)) /* Assignment of value for COUNTSYNC in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE1_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_GP0_Pos)        /* (RTC_MODE1_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_GP0(value)         (RTC_MODE1_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP0_Pos)) /* Assignment of value for GP0 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE1_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_GP1_Pos)        /* (RTC_MODE1_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_GP1(value)         (RTC_MODE1_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP1_Pos)) /* Assignment of value for GP1 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_Msk                _UINT32_(0x0003807F)                                 /* (RTC_MODE1_SYNCBUSY) Register Mask  */

#define RTC_MODE1_SYNCBUSY_COMP_Pos           _UINT32_(5)                                          /* (RTC_MODE1_SYNCBUSY Position) COMP x Register Busy */
#define RTC_MODE1_SYNCBUSY_COMP_Msk           (_UINT32_(0x3) << RTC_MODE1_SYNCBUSY_COMP_Pos)       /* (RTC_MODE1_SYNCBUSY Mask) COMP */
#define RTC_MODE1_SYNCBUSY_COMP(value)        (RTC_MODE1_SYNCBUSY_COMP_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP_Pos)) 
#define RTC_MODE1_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE1_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE1_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE1_SYNCBUSY_GP_Pos)         /* (RTC_MODE1_SYNCBUSY Mask) GP */
#define RTC_MODE1_SYNCBUSY_GP(value)          (RTC_MODE1_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP_Pos)) 

/* -------- RTC_MODE2_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE2 Synchronization Busy Status -------- */
#define RTC_MODE2_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE2_SYNCBUSY) MODE2 Synchronization Busy Status  Reset Value */

#define RTC_MODE2_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE2_SYNCBUSY) Software Reset Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE2_SYNCBUSY) Software Reset Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_SWRST(value)       (RTC_MODE2_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_SWRST_Pos)) /* Assignment of value for SWRST in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE2_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE2_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_ENABLE(value)      (RTC_MODE2_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ENABLE_Pos)) /* Assignment of value for ENABLE in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE2_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE2_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE2_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_FREQCORR(value)    (RTC_MODE2_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_FREQCORR_Pos)) /* Assignment of value for FREQCORR in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_CLOCK_Pos          _UINT32_(3)                                          /* (RTC_MODE2_SYNCBUSY) CLOCK Register Busy Position */
#define RTC_MODE2_SYNCBUSY_CLOCK_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_CLOCK_Pos)      /* (RTC_MODE2_SYNCBUSY) CLOCK Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_CLOCK(value)       (RTC_MODE2_SYNCBUSY_CLOCK_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_CLOCK_Pos)) /* Assignment of value for CLOCK in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_ALARM0_Pos         _UINT32_(5)                                          /* (RTC_MODE2_SYNCBUSY) ALARM Register Busy Position */
#define RTC_MODE2_SYNCBUSY_ALARM0_Msk         (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ALARM0_Pos)     /* (RTC_MODE2_SYNCBUSY) ALARM Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_ALARM0(value)      (RTC_MODE2_SYNCBUSY_ALARM0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ALARM0_Pos)) /* Assignment of value for ALARM0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_MASK0_Pos          _UINT32_(11)                                         /* (RTC_MODE2_SYNCBUSY) MASK Register Busy Position */
#define RTC_MODE2_SYNCBUSY_MASK0_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_MASK0_Pos)      /* (RTC_MODE2_SYNCBUSY) MASK Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_MASK0(value)       (RTC_MODE2_SYNCBUSY_MASK0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_MASK0_Pos)) /* Assignment of value for MASK0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE2_SYNCBUSY) Clock Synchronization Enable Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC_Msk      (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos)  /* (RTC_MODE2_SYNCBUSY) Clock Synchronization Enable Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC(value)   (RTC_MODE2_SYNCBUSY_CLOCKSYNC_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos)) /* Assignment of value for CLOCKSYNC in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE2_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE2_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_GP0_Pos)        /* (RTC_MODE2_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_GP0(value)         (RTC_MODE2_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP0_Pos)) /* Assignment of value for GP0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE2_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE2_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_GP1_Pos)        /* (RTC_MODE2_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_GP1(value)         (RTC_MODE2_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP1_Pos)) /* Assignment of value for GP1 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_Msk                _UINT32_(0x0003882F)                                 /* (RTC_MODE2_SYNCBUSY) Register Mask  */

#define RTC_MODE2_SYNCBUSY_ALARM_Pos          _UINT32_(5)                                          /* (RTC_MODE2_SYNCBUSY Position) ALARM Register Busy */
#define RTC_MODE2_SYNCBUSY_ALARM_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ALARM_Pos)      /* (RTC_MODE2_SYNCBUSY Mask) ALARM */
#define RTC_MODE2_SYNCBUSY_ALARM(value)       (RTC_MODE2_SYNCBUSY_ALARM_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ALARM_Pos)) 
#define RTC_MODE2_SYNCBUSY_MASK_Pos           _UINT32_(11)                                         /* (RTC_MODE2_SYNCBUSY Position) MASK Register Busy */
#define RTC_MODE2_SYNCBUSY_MASK_Msk           (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_MASK_Pos)       /* (RTC_MODE2_SYNCBUSY Mask) MASK */
#define RTC_MODE2_SYNCBUSY_MASK(value)        (RTC_MODE2_SYNCBUSY_MASK_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_MASK_Pos)) 
#define RTC_MODE2_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE2_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE2_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE2_SYNCBUSY_GP_Pos)         /* (RTC_MODE2_SYNCBUSY Mask) GP */
#define RTC_MODE2_SYNCBUSY_GP(value)          (RTC_MODE2_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP_Pos)) 

/* -------- RTC_FREQCORR : (RTC Offset: 0x14) (R/W 8) Frequency Correction -------- */
#define RTC_FREQCORR_RESETVALUE               _UINT8_(0x00)                                        /*  (RTC_FREQCORR) Frequency Correction  Reset Value */

#define RTC_FREQCORR_VALUE_Pos                _UINT8_(0)                                           /* (RTC_FREQCORR) Correction Value Position */
#define RTC_FREQCORR_VALUE_Msk                (_UINT8_(0x7F) << RTC_FREQCORR_VALUE_Pos)            /* (RTC_FREQCORR) Correction Value Mask */
#define RTC_FREQCORR_VALUE(value)             (RTC_FREQCORR_VALUE_Msk & (_UINT8_(value) << RTC_FREQCORR_VALUE_Pos)) /* Assignment of value for VALUE in the RTC_FREQCORR register */
#define RTC_FREQCORR_SIGN_Pos                 _UINT8_(7)                                           /* (RTC_FREQCORR) Correction Sign Position */
#define RTC_FREQCORR_SIGN_Msk                 (_UINT8_(0x1) << RTC_FREQCORR_SIGN_Pos)              /* (RTC_FREQCORR) Correction Sign Mask */
#define RTC_FREQCORR_SIGN(value)              (RTC_FREQCORR_SIGN_Msk & (_UINT8_(value) << RTC_FREQCORR_SIGN_Pos)) /* Assignment of value for SIGN in the RTC_FREQCORR register */
#define RTC_FREQCORR_Msk                      _UINT8_(0xFF)                                        /* (RTC_FREQCORR) Register Mask  */


/* -------- RTC_MODE0_COUNT : (RTC Offset: 0x18) (R/W 32) MODE0 Counter Value -------- */
#define RTC_MODE0_COUNT_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE0_COUNT) MODE0 Counter Value  Reset Value */

#define RTC_MODE0_COUNT_COUNT_Pos             _UINT32_(0)                                          /* (RTC_MODE0_COUNT) Counter Value Position */
#define RTC_MODE0_COUNT_COUNT_Msk             (_UINT32_(0xFFFFFFFF) << RTC_MODE0_COUNT_COUNT_Pos)  /* (RTC_MODE0_COUNT) Counter Value Mask */
#define RTC_MODE0_COUNT_COUNT(value)          (RTC_MODE0_COUNT_COUNT_Msk & (_UINT32_(value) << RTC_MODE0_COUNT_COUNT_Pos)) /* Assignment of value for COUNT in the RTC_MODE0_COUNT register */
#define RTC_MODE0_COUNT_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE0_COUNT) Register Mask  */


/* -------- RTC_MODE1_COUNT : (RTC Offset: 0x18) (R/W 16) MODE1 Counter Value -------- */
#define RTC_MODE1_COUNT_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_COUNT) MODE1 Counter Value  Reset Value */

#define RTC_MODE1_COUNT_COUNT_Pos             _UINT16_(0)                                          /* (RTC_MODE1_COUNT) Counter Value Position */
#define RTC_MODE1_COUNT_COUNT_Msk             (_UINT16_(0xFFFF) << RTC_MODE1_COUNT_COUNT_Pos)      /* (RTC_MODE1_COUNT) Counter Value Mask */
#define RTC_MODE1_COUNT_COUNT(value)          (RTC_MODE1_COUNT_COUNT_Msk & (_UINT16_(value) << RTC_MODE1_COUNT_COUNT_Pos)) /* Assignment of value for COUNT in the RTC_MODE1_COUNT register */
#define RTC_MODE1_COUNT_Msk                   _UINT16_(0xFFFF)                                     /* (RTC_MODE1_COUNT) Register Mask  */


/* -------- RTC_MODE2_CLOCK : (RTC Offset: 0x18) (R/W 32) MODE2 Clock Value -------- */
#define RTC_MODE2_CLOCK_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE2_CLOCK) MODE2 Clock Value  Reset Value */

#define RTC_MODE2_CLOCK_SECOND_Pos            _UINT32_(0)                                          /* (RTC_MODE2_CLOCK) Second Position */
#define RTC_MODE2_CLOCK_SECOND_Msk            (_UINT32_(0x3F) << RTC_MODE2_CLOCK_SECOND_Pos)       /* (RTC_MODE2_CLOCK) Second Mask */
#define RTC_MODE2_CLOCK_SECOND(value)         (RTC_MODE2_CLOCK_SECOND_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_SECOND_Pos)) /* Assignment of value for SECOND in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_MINUTE_Pos            _UINT32_(6)                                          /* (RTC_MODE2_CLOCK) Minute Position */
#define RTC_MODE2_CLOCK_MINUTE_Msk            (_UINT32_(0x3F) << RTC_MODE2_CLOCK_MINUTE_Pos)       /* (RTC_MODE2_CLOCK) Minute Mask */
#define RTC_MODE2_CLOCK_MINUTE(value)         (RTC_MODE2_CLOCK_MINUTE_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_MINUTE_Pos)) /* Assignment of value for MINUTE in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_HOUR_Pos              _UINT32_(12)                                         /* (RTC_MODE2_CLOCK) Hour Position */
#define RTC_MODE2_CLOCK_HOUR_Msk              (_UINT32_(0x1F) << RTC_MODE2_CLOCK_HOUR_Pos)         /* (RTC_MODE2_CLOCK) Hour Mask */
#define RTC_MODE2_CLOCK_HOUR(value)           (RTC_MODE2_CLOCK_HOUR_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_HOUR_Pos)) /* Assignment of value for HOUR in the RTC_MODE2_CLOCK register */
#define   RTC_MODE2_CLOCK_HOUR_AM_Val         _UINT32_(0x0)                                        /* (RTC_MODE2_CLOCK) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define   RTC_MODE2_CLOCK_HOUR_PM_Val         _UINT32_(0x10)                                       /* (RTC_MODE2_CLOCK) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define RTC_MODE2_CLOCK_HOUR_AM               (RTC_MODE2_CLOCK_HOUR_AM_Val << RTC_MODE2_CLOCK_HOUR_Pos) /* (RTC_MODE2_CLOCK) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position */
#define RTC_MODE2_CLOCK_HOUR_PM               (RTC_MODE2_CLOCK_HOUR_PM_Val << RTC_MODE2_CLOCK_HOUR_Pos) /* (RTC_MODE2_CLOCK) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position */
#define RTC_MODE2_CLOCK_DAY_Pos               _UINT32_(17)                                         /* (RTC_MODE2_CLOCK) Day Position */
#define RTC_MODE2_CLOCK_DAY_Msk               (_UINT32_(0x1F) << RTC_MODE2_CLOCK_DAY_Pos)          /* (RTC_MODE2_CLOCK) Day Mask */
#define RTC_MODE2_CLOCK_DAY(value)            (RTC_MODE2_CLOCK_DAY_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_DAY_Pos)) /* Assignment of value for DAY in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_MONTH_Pos             _UINT32_(22)                                         /* (RTC_MODE2_CLOCK) Month Position */
#define RTC_MODE2_CLOCK_MONTH_Msk             (_UINT32_(0xF) << RTC_MODE2_CLOCK_MONTH_Pos)         /* (RTC_MODE2_CLOCK) Month Mask */
#define RTC_MODE2_CLOCK_MONTH(value)          (RTC_MODE2_CLOCK_MONTH_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_MONTH_Pos)) /* Assignment of value for MONTH in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_YEAR_Pos              _UINT32_(26)                                         /* (RTC_MODE2_CLOCK) Year Position */
#define RTC_MODE2_CLOCK_YEAR_Msk              (_UINT32_(0x3F) << RTC_MODE2_CLOCK_YEAR_Pos)         /* (RTC_MODE2_CLOCK) Year Mask */
#define RTC_MODE2_CLOCK_YEAR(value)           (RTC_MODE2_CLOCK_YEAR_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_YEAR_Pos)) /* Assignment of value for YEAR in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE2_CLOCK) Register Mask  */


/* -------- RTC_MODE1_PER : (RTC Offset: 0x1C) (R/W 16) MODE1 Counter Period -------- */
#define RTC_MODE1_PER_RESETVALUE              _UINT16_(0x00)                                       /*  (RTC_MODE1_PER) MODE1 Counter Period  Reset Value */

#define RTC_MODE1_PER_PER_Pos                 _UINT16_(0)                                          /* (RTC_MODE1_PER) Counter Period Position */
#define RTC_MODE1_PER_PER_Msk                 (_UINT16_(0xFFFF) << RTC_MODE1_PER_PER_Pos)          /* (RTC_MODE1_PER) Counter Period Mask */
#define RTC_MODE1_PER_PER(value)              (RTC_MODE1_PER_PER_Msk & (_UINT16_(value) << RTC_MODE1_PER_PER_Pos)) /* Assignment of value for PER in the RTC_MODE1_PER register */
#define RTC_MODE1_PER_Msk                     _UINT16_(0xFFFF)                                     /* (RTC_MODE1_PER) Register Mask  */


/* -------- RTC_MODE0_COMP0 : (RTC Offset: 0x20) (R/W 32) MODE0 Compare Value -------- */
#define RTC_MODE0_COMP0_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE0_COMP0) MODE0 Compare Value  Reset Value */

#define RTC_MODE0_COMP0_COMP_Pos              _UINT32_(0)                                          /* (RTC_MODE0_COMP0) Compare Value Position */
#define RTC_MODE0_COMP0_COMP_Msk              (_UINT32_(0xFFFFFFFF) << RTC_MODE0_COMP0_COMP_Pos)   /* (RTC_MODE0_COMP0) Compare Value Mask */
#define RTC_MODE0_COMP0_COMP(value)           (RTC_MODE0_COMP0_COMP_Msk & (_UINT32_(value) << RTC_MODE0_COMP0_COMP_Pos)) /* Assignment of value for COMP in the RTC_MODE0_COMP0 register */
#define RTC_MODE0_COMP0_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE0_COMP0) Register Mask  */


/* -------- RTC_MODE1_COMP : (RTC Offset: 0x20) (R/W 16) MODE1 Compare n Value -------- */
#define RTC_MODE1_COMP_RESETVALUE             _UINT16_(0x00)                                       /*  (RTC_MODE1_COMP) MODE1 Compare n Value  Reset Value */

#define RTC_MODE1_COMP_COMP_Pos               _UINT16_(0)                                          /* (RTC_MODE1_COMP) Compare Value Position */
#define RTC_MODE1_COMP_COMP_Msk               (_UINT16_(0xFFFF) << RTC_MODE1_COMP_COMP_Pos)        /* (RTC_MODE1_COMP) Compare Value Mask */
#define RTC_MODE1_COMP_COMP(value)            (RTC_MODE1_COMP_COMP_Msk & (_UINT16_(value) << RTC_MODE1_COMP_COMP_Pos)) /* Assignment of value for COMP in the RTC_MODE1_COMP register */
#define RTC_MODE1_COMP_Msk                    _UINT16_(0xFFFF)                                     /* (RTC_MODE1_COMP) Register Mask  */


/* -------- RTC_MODE2_ALARM0 : (RTC Offset: 0x20) (R/W 32) MODE2 Alarm Value -------- */
#define RTC_MODE2_ALARM0_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE2_ALARM0) MODE2 Alarm Value  Reset Value */

#define RTC_MODE2_ALARM0_SECOND_Pos           _UINT32_(0)                                          /* (RTC_MODE2_ALARM0) Second Position */
#define RTC_MODE2_ALARM0_SECOND_Msk           (_UINT32_(0x3F) << RTC_MODE2_ALARM0_SECOND_Pos)      /* (RTC_MODE2_ALARM0) Second Mask */
#define RTC_MODE2_ALARM0_SECOND(value)        (RTC_MODE2_ALARM0_SECOND_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_SECOND_Pos)) /* Assignment of value for SECOND in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_MINUTE_Pos           _UINT32_(6)                                          /* (RTC_MODE2_ALARM0) Minute Position */
#define RTC_MODE2_ALARM0_MINUTE_Msk           (_UINT32_(0x3F) << RTC_MODE2_ALARM0_MINUTE_Pos)      /* (RTC_MODE2_ALARM0) Minute Mask */
#define RTC_MODE2_ALARM0_MINUTE(value)        (RTC_MODE2_ALARM0_MINUTE_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_MINUTE_Pos)) /* Assignment of value for MINUTE in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_HOUR_Pos             _UINT32_(12)                                         /* (RTC_MODE2_ALARM0) Hour Position */
#define RTC_MODE2_ALARM0_HOUR_Msk             (_UINT32_(0x1F) << RTC_MODE2_ALARM0_HOUR_Pos)        /* (RTC_MODE2_ALARM0) Hour Mask */
#define RTC_MODE2_ALARM0_HOUR(value)          (RTC_MODE2_ALARM0_HOUR_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_HOUR_Pos)) /* Assignment of value for HOUR in the RTC_MODE2_ALARM0 register */
#define   RTC_MODE2_ALARM0_HOUR_AM_Val        _UINT32_(0x0)                                        /* (RTC_MODE2_ALARM0) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define   RTC_MODE2_ALARM0_HOUR_PM_Val        _UINT32_(0x10)                                       /* (RTC_MODE2_ALARM0) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define RTC_MODE2_ALARM0_HOUR_AM              (RTC_MODE2_ALARM0_HOUR_AM_Val << RTC_MODE2_ALARM0_HOUR_Pos) /* (RTC_MODE2_ALARM0) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position */
#define RTC_MODE2_ALARM0_HOUR_PM              (RTC_MODE2_ALARM0_HOUR_PM_Val << RTC_MODE2_ALARM0_HOUR_Pos) /* (RTC_MODE2_ALARM0) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position */
#define RTC_MODE2_ALARM0_DAY_Pos              _UINT32_(17)                                         /* (RTC_MODE2_ALARM0) Day Position */
#define RTC_MODE2_ALARM0_DAY_Msk              (_UINT32_(0x1F) << RTC_MODE2_ALARM0_DAY_Pos)         /* (RTC_MODE2_ALARM0) Day Mask */
#define RTC_MODE2_ALARM0_DAY(value)           (RTC_MODE2_ALARM0_DAY_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_DAY_Pos)) /* Assignment of value for DAY in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_MONTH_Pos            _UINT32_(22)                                         /* (RTC_MODE2_ALARM0) Month Position */
#define RTC_MODE2_ALARM0_MONTH_Msk            (_UINT32_(0xF) << RTC_MODE2_ALARM0_MONTH_Pos)        /* (RTC_MODE2_ALARM0) Month Mask */
#define RTC_MODE2_ALARM0_MONTH(value)         (RTC_MODE2_ALARM0_MONTH_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_MONTH_Pos)) /* Assignment of value for MONTH in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_YEAR_Pos             _UINT32_(26)                                         /* (RTC_MODE2_ALARM0) Year Position */
#define RTC_MODE2_ALARM0_YEAR_Msk             (_UINT32_(0x3F) << RTC_MODE2_ALARM0_YEAR_Pos)        /* (RTC_MODE2_ALARM0) Year Mask */
#define RTC_MODE2_ALARM0_YEAR(value)          (RTC_MODE2_ALARM0_YEAR_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_YEAR_Pos)) /* Assignment of value for YEAR in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE2_ALARM0) Register Mask  */


/* -------- RTC_MODE2_MASK0 : (RTC Offset: 0x24) (R/W 8) MODE2 Alarm Mask -------- */
#define RTC_MODE2_MASK0_RESETVALUE            _UINT8_(0x00)                                        /*  (RTC_MODE2_MASK0) MODE2 Alarm Mask  Reset Value */

#define RTC_MODE2_MASK0_SEL_Pos               _UINT8_(0)                                           /* (RTC_MODE2_MASK0) Alarm Mask Selection Position */
#define RTC_MODE2_MASK0_SEL_Msk               (_UINT8_(0x7) << RTC_MODE2_MASK0_SEL_Pos)            /* (RTC_MODE2_MASK0) Alarm Mask Selection Mask */
#define RTC_MODE2_MASK0_SEL(value)            (RTC_MODE2_MASK0_SEL_Msk & (_UINT8_(value) << RTC_MODE2_MASK0_SEL_Pos)) /* Assignment of value for SEL in the RTC_MODE2_MASK0 register */
#define   RTC_MODE2_MASK0_SEL_OFF_Val         _UINT8_(0x0)                                         /* (RTC_MODE2_MASK0) Alarm Disabled  */
#define   RTC_MODE2_MASK0_SEL_SS_Val          _UINT8_(0x1)                                         /* (RTC_MODE2_MASK0) Match seconds only  */
#define   RTC_MODE2_MASK0_SEL_MMSS_Val        _UINT8_(0x2)                                         /* (RTC_MODE2_MASK0) Match seconds and minutes only  */
#define   RTC_MODE2_MASK0_SEL_HHMMSS_Val      _UINT8_(0x3)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, and hours only  */
#define   RTC_MODE2_MASK0_SEL_DDHHMMSS_Val    _UINT8_(0x4)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, and days only  */
#define   RTC_MODE2_MASK0_SEL_MMDDHHMMSS_Val  _UINT8_(0x5)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, and months only  */
#define   RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS_Val _UINT8_(0x6)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, months, and years  */
#define RTC_MODE2_MASK0_SEL_OFF               (RTC_MODE2_MASK0_SEL_OFF_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Alarm Disabled Position */
#define RTC_MODE2_MASK0_SEL_SS                (RTC_MODE2_MASK0_SEL_SS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds only Position */
#define RTC_MODE2_MASK0_SEL_MMSS              (RTC_MODE2_MASK0_SEL_MMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds and minutes only Position */
#define RTC_MODE2_MASK0_SEL_HHMMSS            (RTC_MODE2_MASK0_SEL_HHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, and hours only Position */
#define RTC_MODE2_MASK0_SEL_DDHHMMSS          (RTC_MODE2_MASK0_SEL_DDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, and days only Position */
#define RTC_MODE2_MASK0_SEL_MMDDHHMMSS        (RTC_MODE2_MASK0_SEL_MMDDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, and months only Position */
#define RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS      (RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, months, and years Position */
#define RTC_MODE2_MASK0_Msk                   _UINT8_(0x07)                                        /* (RTC_MODE2_MASK0) Register Mask  */


/* -------- RTC_GP : (RTC Offset: 0x40) (R/W 32) General Purpose -------- */
#define RTC_GP_RESETVALUE                     _UINT32_(0x00)                                       /*  (RTC_GP) General Purpose  Reset Value */

#define RTC_GP_GP_Pos                         _UINT32_(0)                                          /* (RTC_GP) General Purpose Position */
#define RTC_GP_GP_Msk                         (_UINT32_(0xFFFFFFFF) << RTC_GP_GP_Pos)              /* (RTC_GP) General Purpose Mask */
#define RTC_GP_GP(value)                      (RTC_GP_GP_Msk & (_UINT32_(value) << RTC_GP_GP_Pos)) /* Assignment of value for GP in the RTC_GP register */
#define RTC_GP_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (RTC_GP) Register Mask  */


/* RTC register offsets definitions */
#define RTC_MODE0_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE0_CTRLA) MODE0 Control A Offset */
#define RTC_MODE1_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE1_CTRLA) MODE1 Control A Offset */
#define RTC_MODE2_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE2_CTRLA) MODE2 Control A Offset */
#define RTC_MODE0_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE0_CTRLB) MODE0 Control B Offset */
#define RTC_MODE1_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE1_CTRLB) MODE1 Control B Offset */
#define RTC_MODE2_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE2_CTRLB) MODE2 Control B Offset */
#define RTC_MODE0_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE0_EVCTRL) MODE0 Event Control Offset */
#define RTC_MODE1_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE1_EVCTRL) MODE1 Event Control Offset */
#define RTC_MODE2_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE2_EVCTRL) MODE2 Event Control Offset */
#define RTC_MODE0_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE0_INTENCLR) MODE0 Interrupt Enable Clear Offset */
#define RTC_MODE1_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE1_INTENCLR) MODE1 Interrupt Enable Clear Offset */
#define RTC_MODE2_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE2_INTENCLR) MODE2 Interrupt Enable Clear Offset */
#define RTC_MODE0_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE0_INTENSET) MODE0 Interrupt Enable Set Offset */
#define RTC_MODE1_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE1_INTENSET) MODE1 Interrupt Enable Set Offset */
#define RTC_MODE2_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE2_INTENSET) MODE2 Interrupt Enable Set Offset */
#define RTC_MODE0_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE0_INTFLAG) MODE0 Interrupt Flag Status and Clear Offset */
#define RTC_MODE1_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE1_INTFLAG) MODE1 Interrupt Flag Status and Clear Offset */
#define RTC_MODE2_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE2_INTFLAG) MODE2 Interrupt Flag Status and Clear Offset */
#define RTC_DBGCTRL_REG_OFST           _UINT32_(0x0E)      /* (RTC_DBGCTRL) Debug Control Offset */
#define RTC_MODE0_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE0_SYNCBUSY) MODE0 Synchronization Busy Status Offset */
#define RTC_MODE1_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE1_SYNCBUSY) MODE1 Synchronization Busy Status Offset */
#define RTC_MODE2_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE2_SYNCBUSY) MODE2 Synchronization Busy Status Offset */
#define RTC_FREQCORR_REG_OFST          _UINT32_(0x14)      /* (RTC_FREQCORR) Frequency Correction Offset */
#define RTC_MODE0_COUNT_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE0_COUNT) MODE0 Counter Value Offset */
#define RTC_MODE1_COUNT_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE1_COUNT) MODE1 Counter Value Offset */
#define RTC_MODE2_CLOCK_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE2_CLOCK) MODE2 Clock Value Offset */
#define RTC_MODE1_PER_REG_OFST         _UINT32_(0x1C)      /* (RTC_MODE1_PER) MODE1 Counter Period Offset */
#define RTC_MODE0_COMP0_REG_OFST       _UINT32_(0x20)      /* (RTC_MODE0_COMP0) MODE0 Compare Value Offset */
#define RTC_MODE1_COMP_REG_OFST        _UINT32_(0x20)      /* (RTC_MODE1_COMP) MODE1 Compare n Value Offset */
#define RTC_MODE1_COMP0_REG_OFST       _UINT32_(0x20)      /* (RTC_MODE1_COMP0) MODE1 Compare n Value Offset */
#define RTC_MODE1_COMP1_REG_OFST       _UINT32_(0x22)      /* (RTC_MODE1_COMP1) MODE1 Compare n Value Offset */
#define RTC_MODE2_ALARM0_REG_OFST      _UINT32_(0x20)      /* (RTC_MODE2_ALARM0) MODE2 Alarm Value Offset */
#define RTC_MODE2_MASK0_REG_OFST       _UINT32_(0x24)      /* (RTC_MODE2_MASK0) MODE2 Alarm Mask Offset */
#define RTC_GP_REG_OFST                _UINT32_(0x40)      /* (RTC_GP) General Purpose Offset */
#define RTC_GP0_REG_OFST               _UINT32_(0x40)      /* (RTC_GP0) General Purpose Offset */
#define RTC_GP1_REG_OFST               _UINT32_(0x44)      /* (RTC_GP1) General Purpose Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /* Offset: 0x00 (R/W  16) MODE0 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /* Offset: 0x02 (R/W  16) MODE0 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /* Offset: 0x04 (R/W  32) MODE0 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /* Offset: 0x08 (R/W  16) MODE0 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /* Offset: 0x0A (R/W  16) MODE0 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /* Offset: 0x0C (R/W  16) MODE0 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /* Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /* Offset: 0x10 (R/   32) MODE0 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /* Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint32_t                       RTC_COUNT;          /* Offset: 0x18 (R/W  32) MODE0 Counter Value */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       RTC_COMP0;          /* Offset: 0x20 (R/W  32) MODE0 Compare Value */
  __I   uint8_t                        Reserved4[0x1C];
  __IO  uint32_t                       RTC_GP[2];          /* Offset: 0x40 (R/W  32) General Purpose */
} rtc_mode0_registers_t;

/* RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /* Offset: 0x00 (R/W  16) MODE1 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /* Offset: 0x02 (R/W  16) MODE1 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /* Offset: 0x04 (R/W  32) MODE1 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /* Offset: 0x08 (R/W  16) MODE1 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /* Offset: 0x0A (R/W  16) MODE1 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /* Offset: 0x0C (R/W  16) MODE1 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /* Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /* Offset: 0x10 (R/   32) MODE1 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /* Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint16_t                       RTC_COUNT;          /* Offset: 0x18 (R/W  16) MODE1 Counter Value */
  __I   uint8_t                        Reserved3[0x02];
  __IO  uint16_t                       RTC_PER;            /* Offset: 0x1C (R/W  16) MODE1 Counter Period */
  __I   uint8_t                        Reserved4[0x02];
  __IO  uint16_t                       RTC_COMP[2];        /* Offset: 0x20 (R/W  16) MODE1 Compare n Value */
  __I   uint8_t                        Reserved5[0x1C];
  __IO  uint32_t                       RTC_GP[2];          /* Offset: 0x40 (R/W  32) General Purpose */
} rtc_mode1_registers_t;

/* RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /* Offset: 0x00 (R/W  16) MODE2 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /* Offset: 0x02 (R/W  16) MODE2 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /* Offset: 0x04 (R/W  32) MODE2 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /* Offset: 0x08 (R/W  16) MODE2 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /* Offset: 0x0A (R/W  16) MODE2 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /* Offset: 0x0C (R/W  16) MODE2 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /* Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /* Offset: 0x10 (R/   32) MODE2 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /* Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint32_t                       RTC_CLOCK;          /* Offset: 0x18 (R/W  32) MODE2 Clock Value */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       RTC_ALARM0;         /* Offset: 0x20 (R/W  32) MODE2 Alarm Value */
  __IO  uint8_t                        RTC_MASK0;          /* Offset: 0x24 (R/W  8) MODE2 Alarm Mask */
  __I   uint8_t                        Reserved4[0x1B];
  __IO  uint32_t                       RTC_GP[2];          /* Offset: 0x40 (R/W  32) General Purpose */
} rtc_mode2_registers_t;

/* RTC hardware registers */
typedef union
{  /* Real-Time Counter */
       rtc_mode0_registers_t          MODE0;          /* 32-bit Counter with Single 32-bit Compare */
       rtc_mode1_registers_t          MODE1;          /* 16-bit Counter with Two 16-bit Compares */
       rtc_mode2_registers_t          MODE2;          /* Clock/Calendar with Alarm */
} rtc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_RTC_COMPONENT_H_ */
