/*
 * Component description for SUPC
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
#ifndef _PIC32CMJH01_SUPC_COMPONENT_H_
#define _PIC32CMJH01_SUPC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SUPC                      */
/* ************************************************************************** */

/* -------- SUPC_INTENCLR : (SUPC Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define SUPC_INTENCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (SUPC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define SUPC_INTENCLR_BODVDDRDY_Pos           _UINT32_(0)                                          /* (SUPC_INTENCLR) BODVDD Ready Position */
#define SUPC_INTENCLR_BODVDDRDY_Msk           (_UINT32_(0x1) << SUPC_INTENCLR_BODVDDRDY_Pos)       /* (SUPC_INTENCLR) BODVDD Ready Mask */
#define SUPC_INTENCLR_BODVDDRDY(value)        (SUPC_INTENCLR_BODVDDRDY_Msk & (_UINT32_(value) << SUPC_INTENCLR_BODVDDRDY_Pos)) /* Assignment of value for BODVDDRDY in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_BODVDDDET_Pos           _UINT32_(1)                                          /* (SUPC_INTENCLR) BODVDD Detection Position */
#define SUPC_INTENCLR_BODVDDDET_Msk           (_UINT32_(0x1) << SUPC_INTENCLR_BODVDDDET_Pos)       /* (SUPC_INTENCLR) BODVDD Detection Mask */
#define SUPC_INTENCLR_BODVDDDET(value)        (SUPC_INTENCLR_BODVDDDET_Msk & (_UINT32_(value) << SUPC_INTENCLR_BODVDDDET_Pos)) /* Assignment of value for BODVDDDET in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_BVDDSRDY_Pos            _UINT32_(2)                                          /* (SUPC_INTENCLR) BODVDD Synchronization Ready Position */
#define SUPC_INTENCLR_BVDDSRDY_Msk            (_UINT32_(0x1) << SUPC_INTENCLR_BVDDSRDY_Pos)        /* (SUPC_INTENCLR) BODVDD Synchronization Ready Mask */
#define SUPC_INTENCLR_BVDDSRDY(value)         (SUPC_INTENCLR_BVDDSRDY_Msk & (_UINT32_(value) << SUPC_INTENCLR_BVDDSRDY_Pos)) /* Assignment of value for BVDDSRDY in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_Msk                     _UINT32_(0x00000007)                                 /* (SUPC_INTENCLR) Register Mask  */


/* -------- SUPC_INTENSET : (SUPC Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define SUPC_INTENSET_RESETVALUE              _UINT32_(0x00)                                       /*  (SUPC_INTENSET) Interrupt Enable Set  Reset Value */

#define SUPC_INTENSET_BODVDDRDY_Pos           _UINT32_(0)                                          /* (SUPC_INTENSET) BODVDD Ready Position */
#define SUPC_INTENSET_BODVDDRDY_Msk           (_UINT32_(0x1) << SUPC_INTENSET_BODVDDRDY_Pos)       /* (SUPC_INTENSET) BODVDD Ready Mask */
#define SUPC_INTENSET_BODVDDRDY(value)        (SUPC_INTENSET_BODVDDRDY_Msk & (_UINT32_(value) << SUPC_INTENSET_BODVDDRDY_Pos)) /* Assignment of value for BODVDDRDY in the SUPC_INTENSET register */
#define SUPC_INTENSET_BODVDDDET_Pos           _UINT32_(1)                                          /* (SUPC_INTENSET) BODVDD Detection Position */
#define SUPC_INTENSET_BODVDDDET_Msk           (_UINT32_(0x1) << SUPC_INTENSET_BODVDDDET_Pos)       /* (SUPC_INTENSET) BODVDD Detection Mask */
#define SUPC_INTENSET_BODVDDDET(value)        (SUPC_INTENSET_BODVDDDET_Msk & (_UINT32_(value) << SUPC_INTENSET_BODVDDDET_Pos)) /* Assignment of value for BODVDDDET in the SUPC_INTENSET register */
#define SUPC_INTENSET_BVDDSRDY_Pos            _UINT32_(2)                                          /* (SUPC_INTENSET) BODVDD Synchronization Ready Position */
#define SUPC_INTENSET_BVDDSRDY_Msk            (_UINT32_(0x1) << SUPC_INTENSET_BVDDSRDY_Pos)        /* (SUPC_INTENSET) BODVDD Synchronization Ready Mask */
#define SUPC_INTENSET_BVDDSRDY(value)         (SUPC_INTENSET_BVDDSRDY_Msk & (_UINT32_(value) << SUPC_INTENSET_BVDDSRDY_Pos)) /* Assignment of value for BVDDSRDY in the SUPC_INTENSET register */
#define SUPC_INTENSET_Msk                     _UINT32_(0x00000007)                                 /* (SUPC_INTENSET) Register Mask  */


/* -------- SUPC_INTFLAG : (SUPC Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#define SUPC_INTFLAG_RESETVALUE               _UINT32_(0x00)                                       /*  (SUPC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define SUPC_INTFLAG_BODVDDRDY_Pos            _UINT32_(0)                                          /* (SUPC_INTFLAG) BODVDD Ready Position */
#define SUPC_INTFLAG_BODVDDRDY_Msk            (_UINT32_(0x1) << SUPC_INTFLAG_BODVDDRDY_Pos)        /* (SUPC_INTFLAG) BODVDD Ready Mask */
#define SUPC_INTFLAG_BODVDDRDY(value)         (SUPC_INTFLAG_BODVDDRDY_Msk & (_UINT32_(value) << SUPC_INTFLAG_BODVDDRDY_Pos)) /* Assignment of value for BODVDDRDY in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_BODVDDDET_Pos            _UINT32_(1)                                          /* (SUPC_INTFLAG) BODVDD Detection Position */
#define SUPC_INTFLAG_BODVDDDET_Msk            (_UINT32_(0x1) << SUPC_INTFLAG_BODVDDDET_Pos)        /* (SUPC_INTFLAG) BODVDD Detection Mask */
#define SUPC_INTFLAG_BODVDDDET(value)         (SUPC_INTFLAG_BODVDDDET_Msk & (_UINT32_(value) << SUPC_INTFLAG_BODVDDDET_Pos)) /* Assignment of value for BODVDDDET in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_BVDDSRDY_Pos             _UINT32_(2)                                          /* (SUPC_INTFLAG) BODVDD Synchronization Ready Position */
#define SUPC_INTFLAG_BVDDSRDY_Msk             (_UINT32_(0x1) << SUPC_INTFLAG_BVDDSRDY_Pos)         /* (SUPC_INTFLAG) BODVDD Synchronization Ready Mask */
#define SUPC_INTFLAG_BVDDSRDY(value)          (SUPC_INTFLAG_BVDDSRDY_Msk & (_UINT32_(value) << SUPC_INTFLAG_BVDDSRDY_Pos)) /* Assignment of value for BVDDSRDY in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_Msk                      _UINT32_(0x00000007)                                 /* (SUPC_INTFLAG) Register Mask  */


/* -------- SUPC_STATUS : (SUPC Offset: 0x0C) ( R/ 32) Power and Clocks Status -------- */
#define SUPC_STATUS_RESETVALUE                _UINT32_(0x00)                                       /*  (SUPC_STATUS) Power and Clocks Status  Reset Value */

#define SUPC_STATUS_BODVDDRDY_Pos             _UINT32_(0)                                          /* (SUPC_STATUS) BODVDD Ready Position */
#define SUPC_STATUS_BODVDDRDY_Msk             (_UINT32_(0x1) << SUPC_STATUS_BODVDDRDY_Pos)         /* (SUPC_STATUS) BODVDD Ready Mask */
#define SUPC_STATUS_BODVDDRDY(value)          (SUPC_STATUS_BODVDDRDY_Msk & (_UINT32_(value) << SUPC_STATUS_BODVDDRDY_Pos)) /* Assignment of value for BODVDDRDY in the SUPC_STATUS register */
#define SUPC_STATUS_BODVDDDET_Pos             _UINT32_(1)                                          /* (SUPC_STATUS) BODVDD Detection Position */
#define SUPC_STATUS_BODVDDDET_Msk             (_UINT32_(0x1) << SUPC_STATUS_BODVDDDET_Pos)         /* (SUPC_STATUS) BODVDD Detection Mask */
#define SUPC_STATUS_BODVDDDET(value)          (SUPC_STATUS_BODVDDDET_Msk & (_UINT32_(value) << SUPC_STATUS_BODVDDDET_Pos)) /* Assignment of value for BODVDDDET in the SUPC_STATUS register */
#define SUPC_STATUS_BVDDSRDY_Pos              _UINT32_(2)                                          /* (SUPC_STATUS) BODVDD Synchronization Ready Position */
#define SUPC_STATUS_BVDDSRDY_Msk              (_UINT32_(0x1) << SUPC_STATUS_BVDDSRDY_Pos)          /* (SUPC_STATUS) BODVDD Synchronization Ready Mask */
#define SUPC_STATUS_BVDDSRDY(value)           (SUPC_STATUS_BVDDSRDY_Msk & (_UINT32_(value) << SUPC_STATUS_BVDDSRDY_Pos)) /* Assignment of value for BVDDSRDY in the SUPC_STATUS register */
#define SUPC_STATUS_Msk                       _UINT32_(0x00000007)                                 /* (SUPC_STATUS) Register Mask  */


/* -------- SUPC_BODVDD : (SUPC Offset: 0x10) (R/W 32) BODVDD Control -------- */
#define SUPC_BODVDD_RESETVALUE                _UINT32_(0x00)                                       /*  (SUPC_BODVDD) BODVDD Control  Reset Value */

#define SUPC_BODVDD_ENABLE_Pos                _UINT32_(1)                                          /* (SUPC_BODVDD) Enable Position */
#define SUPC_BODVDD_ENABLE_Msk                (_UINT32_(0x1) << SUPC_BODVDD_ENABLE_Pos)            /* (SUPC_BODVDD) Enable Mask */
#define SUPC_BODVDD_ENABLE(value)             (SUPC_BODVDD_ENABLE_Msk & (_UINT32_(value) << SUPC_BODVDD_ENABLE_Pos)) /* Assignment of value for ENABLE in the SUPC_BODVDD register */
#define SUPC_BODVDD_HYST_Pos                  _UINT32_(2)                                          /* (SUPC_BODVDD) Hysteresis Enable Position */
#define SUPC_BODVDD_HYST_Msk                  (_UINT32_(0x1) << SUPC_BODVDD_HYST_Pos)              /* (SUPC_BODVDD) Hysteresis Enable Mask */
#define SUPC_BODVDD_HYST(value)               (SUPC_BODVDD_HYST_Msk & (_UINT32_(value) << SUPC_BODVDD_HYST_Pos)) /* Assignment of value for HYST in the SUPC_BODVDD register */
#define SUPC_BODVDD_ACTION_Pos                _UINT32_(3)                                          /* (SUPC_BODVDD) Action when Threshold Crossed Position */
#define SUPC_BODVDD_ACTION_Msk                (_UINT32_(0x3) << SUPC_BODVDD_ACTION_Pos)            /* (SUPC_BODVDD) Action when Threshold Crossed Mask */
#define SUPC_BODVDD_ACTION(value)             (SUPC_BODVDD_ACTION_Msk & (_UINT32_(value) << SUPC_BODVDD_ACTION_Pos)) /* Assignment of value for ACTION in the SUPC_BODVDD register */
#define   SUPC_BODVDD_ACTION_NONE_Val         _UINT32_(0x0)                                        /* (SUPC_BODVDD) No action  */
#define   SUPC_BODVDD_ACTION_RESET_Val        _UINT32_(0x1)                                        /* (SUPC_BODVDD) The BODVDD generates a reset  */
#define   SUPC_BODVDD_ACTION_INT_Val          _UINT32_(0x2)                                        /* (SUPC_BODVDD) The BODVDD generates an interrupt  */
#define SUPC_BODVDD_ACTION_NONE               (SUPC_BODVDD_ACTION_NONE_Val << SUPC_BODVDD_ACTION_Pos) /* (SUPC_BODVDD) No action Position */
#define SUPC_BODVDD_ACTION_RESET              (SUPC_BODVDD_ACTION_RESET_Val << SUPC_BODVDD_ACTION_Pos) /* (SUPC_BODVDD) The BODVDD generates a reset Position */
#define SUPC_BODVDD_ACTION_INT                (SUPC_BODVDD_ACTION_INT_Val << SUPC_BODVDD_ACTION_Pos) /* (SUPC_BODVDD) The BODVDD generates an interrupt Position */
#define SUPC_BODVDD_STDBYCFG_Pos              _UINT32_(5)                                          /* (SUPC_BODVDD) Configuration in Standby mode Position */
#define SUPC_BODVDD_STDBYCFG_Msk              (_UINT32_(0x1) << SUPC_BODVDD_STDBYCFG_Pos)          /* (SUPC_BODVDD) Configuration in Standby mode Mask */
#define SUPC_BODVDD_STDBYCFG(value)           (SUPC_BODVDD_STDBYCFG_Msk & (_UINT32_(value) << SUPC_BODVDD_STDBYCFG_Pos)) /* Assignment of value for STDBYCFG in the SUPC_BODVDD register */
#define SUPC_BODVDD_RUNSTDBY_Pos              _UINT32_(6)                                          /* (SUPC_BODVDD) Run during Standby Position */
#define SUPC_BODVDD_RUNSTDBY_Msk              (_UINT32_(0x1) << SUPC_BODVDD_RUNSTDBY_Pos)          /* (SUPC_BODVDD) Run during Standby Mask */
#define SUPC_BODVDD_RUNSTDBY(value)           (SUPC_BODVDD_RUNSTDBY_Msk & (_UINT32_(value) << SUPC_BODVDD_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the SUPC_BODVDD register */
#define SUPC_BODVDD_ACTCFG_Pos                _UINT32_(8)                                          /* (SUPC_BODVDD) Configuration in Active mode Position */
#define SUPC_BODVDD_ACTCFG_Msk                (_UINT32_(0x1) << SUPC_BODVDD_ACTCFG_Pos)            /* (SUPC_BODVDD) Configuration in Active mode Mask */
#define SUPC_BODVDD_ACTCFG(value)             (SUPC_BODVDD_ACTCFG_Msk & (_UINT32_(value) << SUPC_BODVDD_ACTCFG_Pos)) /* Assignment of value for ACTCFG in the SUPC_BODVDD register */
#define SUPC_BODVDD_PSEL_Pos                  _UINT32_(12)                                         /* (SUPC_BODVDD) Prescaler Select Position */
#define SUPC_BODVDD_PSEL_Msk                  (_UINT32_(0xF) << SUPC_BODVDD_PSEL_Pos)              /* (SUPC_BODVDD) Prescaler Select Mask */
#define SUPC_BODVDD_PSEL(value)               (SUPC_BODVDD_PSEL_Msk & (_UINT32_(value) << SUPC_BODVDD_PSEL_Pos)) /* Assignment of value for PSEL in the SUPC_BODVDD register */
#define   SUPC_BODVDD_PSEL_DIV2_Val           _UINT32_(0x0)                                        /* (SUPC_BODVDD) Divide clock by 2  */
#define   SUPC_BODVDD_PSEL_DIV4_Val           _UINT32_(0x1)                                        /* (SUPC_BODVDD) Divide clock by 4  */
#define   SUPC_BODVDD_PSEL_DIV8_Val           _UINT32_(0x2)                                        /* (SUPC_BODVDD) Divide clock by 8  */
#define   SUPC_BODVDD_PSEL_DIV16_Val          _UINT32_(0x3)                                        /* (SUPC_BODVDD) Divide clock by 16  */
#define   SUPC_BODVDD_PSEL_DIV32_Val          _UINT32_(0x4)                                        /* (SUPC_BODVDD) Divide clock by 32  */
#define   SUPC_BODVDD_PSEL_DIV64_Val          _UINT32_(0x5)                                        /* (SUPC_BODVDD) Divide clock by 64  */
#define   SUPC_BODVDD_PSEL_DIV128_Val         _UINT32_(0x6)                                        /* (SUPC_BODVDD) Divide clock by 128  */
#define   SUPC_BODVDD_PSEL_DIV256_Val         _UINT32_(0x7)                                        /* (SUPC_BODVDD) Divide clock by 256  */
#define   SUPC_BODVDD_PSEL_DIV512_Val         _UINT32_(0x8)                                        /* (SUPC_BODVDD) Divide clock by 512  */
#define   SUPC_BODVDD_PSEL_DIV1024_Val        _UINT32_(0x9)                                        /* (SUPC_BODVDD) Divide clock by 1024  */
#define   SUPC_BODVDD_PSEL_DIV2048_Val        _UINT32_(0xA)                                        /* (SUPC_BODVDD) Divide clock by 2048  */
#define   SUPC_BODVDD_PSEL_DIV4096_Val        _UINT32_(0xB)                                        /* (SUPC_BODVDD) Divide clock by 4096  */
#define   SUPC_BODVDD_PSEL_DIV8192_Val        _UINT32_(0xC)                                        /* (SUPC_BODVDD) Divide clock by 8192  */
#define   SUPC_BODVDD_PSEL_DIV16384_Val       _UINT32_(0xD)                                        /* (SUPC_BODVDD) Divide clock by 16384  */
#define   SUPC_BODVDD_PSEL_DIV32768_Val       _UINT32_(0xE)                                        /* (SUPC_BODVDD) Divide clock by 32768  */
#define   SUPC_BODVDD_PSEL_DIV65536_Val       _UINT32_(0xF)                                        /* (SUPC_BODVDD) Divide clock by 65536  */
#define SUPC_BODVDD_PSEL_DIV2                 (SUPC_BODVDD_PSEL_DIV2_Val << SUPC_BODVDD_PSEL_Pos)  /* (SUPC_BODVDD) Divide clock by 2 Position */
#define SUPC_BODVDD_PSEL_DIV4                 (SUPC_BODVDD_PSEL_DIV4_Val << SUPC_BODVDD_PSEL_Pos)  /* (SUPC_BODVDD) Divide clock by 4 Position */
#define SUPC_BODVDD_PSEL_DIV8                 (SUPC_BODVDD_PSEL_DIV8_Val << SUPC_BODVDD_PSEL_Pos)  /* (SUPC_BODVDD) Divide clock by 8 Position */
#define SUPC_BODVDD_PSEL_DIV16                (SUPC_BODVDD_PSEL_DIV16_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 16 Position */
#define SUPC_BODVDD_PSEL_DIV32                (SUPC_BODVDD_PSEL_DIV32_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 32 Position */
#define SUPC_BODVDD_PSEL_DIV64                (SUPC_BODVDD_PSEL_DIV64_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 64 Position */
#define SUPC_BODVDD_PSEL_DIV128               (SUPC_BODVDD_PSEL_DIV128_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 128 Position */
#define SUPC_BODVDD_PSEL_DIV256               (SUPC_BODVDD_PSEL_DIV256_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 256 Position */
#define SUPC_BODVDD_PSEL_DIV512               (SUPC_BODVDD_PSEL_DIV512_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 512 Position */
#define SUPC_BODVDD_PSEL_DIV1024              (SUPC_BODVDD_PSEL_DIV1024_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 1024 Position */
#define SUPC_BODVDD_PSEL_DIV2048              (SUPC_BODVDD_PSEL_DIV2048_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 2048 Position */
#define SUPC_BODVDD_PSEL_DIV4096              (SUPC_BODVDD_PSEL_DIV4096_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 4096 Position */
#define SUPC_BODVDD_PSEL_DIV8192              (SUPC_BODVDD_PSEL_DIV8192_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 8192 Position */
#define SUPC_BODVDD_PSEL_DIV16384             (SUPC_BODVDD_PSEL_DIV16384_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 16384 Position */
#define SUPC_BODVDD_PSEL_DIV32768             (SUPC_BODVDD_PSEL_DIV32768_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 32768 Position */
#define SUPC_BODVDD_PSEL_DIV65536             (SUPC_BODVDD_PSEL_DIV65536_Val << SUPC_BODVDD_PSEL_Pos) /* (SUPC_BODVDD) Divide clock by 65536 Position */
#define SUPC_BODVDD_LEVEL_Pos                 _UINT32_(16)                                         /* (SUPC_BODVDD) Threshold Level for VDD Position */
#define SUPC_BODVDD_LEVEL_Msk                 (_UINT32_(0x3F) << SUPC_BODVDD_LEVEL_Pos)            /* (SUPC_BODVDD) Threshold Level for VDD Mask */
#define SUPC_BODVDD_LEVEL(value)              (SUPC_BODVDD_LEVEL_Msk & (_UINT32_(value) << SUPC_BODVDD_LEVEL_Pos)) /* Assignment of value for LEVEL in the SUPC_BODVDD register */
#define SUPC_BODVDD_Msk                       _UINT32_(0x003FF17E)                                 /* (SUPC_BODVDD) Register Mask  */


/* -------- SUPC_VREG : (SUPC Offset: 0x18) (R/W 32) VREG Control -------- */
#define SUPC_VREG_RESETVALUE                  _UINT32_(0x02)                                       /*  (SUPC_VREG) VREG Control  Reset Value */

#define SUPC_VREG_ENABLE_Pos                  _UINT32_(1)                                          /* (SUPC_VREG) Enable Position */
#define SUPC_VREG_ENABLE_Msk                  (_UINT32_(0x1) << SUPC_VREG_ENABLE_Pos)              /* (SUPC_VREG) Enable Mask */
#define SUPC_VREG_ENABLE(value)               (SUPC_VREG_ENABLE_Msk & (_UINT32_(value) << SUPC_VREG_ENABLE_Pos)) /* Assignment of value for ENABLE in the SUPC_VREG register */
#define SUPC_VREG_RUNSTDBY_Pos                _UINT32_(6)                                          /* (SUPC_VREG) Run during Standby Position */
#define SUPC_VREG_RUNSTDBY_Msk                (_UINT32_(0x1) << SUPC_VREG_RUNSTDBY_Pos)            /* (SUPC_VREG) Run during Standby Mask */
#define SUPC_VREG_RUNSTDBY(value)             (SUPC_VREG_RUNSTDBY_Msk & (_UINT32_(value) << SUPC_VREG_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the SUPC_VREG register */
#define SUPC_VREG_Msk                         _UINT32_(0x00000042)                                 /* (SUPC_VREG) Register Mask  */


/* -------- SUPC_VREF : (SUPC Offset: 0x1C) (R/W 32) VREF Control -------- */
#define SUPC_VREF_RESETVALUE                  _UINT32_(0x00)                                       /*  (SUPC_VREF) VREF Control  Reset Value */

#define SUPC_VREF_VREFOE_Pos                  _UINT32_(2)                                          /* (SUPC_VREF) Voltage Reference Output Enable Position */
#define SUPC_VREF_VREFOE_Msk                  (_UINT32_(0x1) << SUPC_VREF_VREFOE_Pos)              /* (SUPC_VREF) Voltage Reference Output Enable Mask */
#define SUPC_VREF_VREFOE(value)               (SUPC_VREF_VREFOE_Msk & (_UINT32_(value) << SUPC_VREF_VREFOE_Pos)) /* Assignment of value for VREFOE in the SUPC_VREF register */
#define SUPC_VREF_RUNSTDBY_Pos                _UINT32_(6)                                          /* (SUPC_VREF) Run during Standby Position */
#define SUPC_VREF_RUNSTDBY_Msk                (_UINT32_(0x1) << SUPC_VREF_RUNSTDBY_Pos)            /* (SUPC_VREF) Run during Standby Mask */
#define SUPC_VREF_RUNSTDBY(value)             (SUPC_VREF_RUNSTDBY_Msk & (_UINT32_(value) << SUPC_VREF_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the SUPC_VREF register */
#define SUPC_VREF_ONDEMAND_Pos                _UINT32_(7)                                          /* (SUPC_VREF) On Demand Control Position */
#define SUPC_VREF_ONDEMAND_Msk                (_UINT32_(0x1) << SUPC_VREF_ONDEMAND_Pos)            /* (SUPC_VREF) On Demand Control Mask */
#define SUPC_VREF_ONDEMAND(value)             (SUPC_VREF_ONDEMAND_Msk & (_UINT32_(value) << SUPC_VREF_ONDEMAND_Pos)) /* Assignment of value for ONDEMAND in the SUPC_VREF register */
#define SUPC_VREF_SEL_Pos                     _UINT32_(16)                                         /* (SUPC_VREF) Voltage Reference Selection Position */
#define SUPC_VREF_SEL_Msk                     (_UINT32_(0xF) << SUPC_VREF_SEL_Pos)                 /* (SUPC_VREF) Voltage Reference Selection Mask */
#define SUPC_VREF_SEL(value)                  (SUPC_VREF_SEL_Msk & (_UINT32_(value) << SUPC_VREF_SEL_Pos)) /* Assignment of value for SEL in the SUPC_VREF register */
#define   SUPC_VREF_SEL_1V024_Val             _UINT32_(0x0)                                        /* (SUPC_VREF) 1.024V voltage reference typical value  */
#define   SUPC_VREF_SEL_2V048_Val             _UINT32_(0x2)                                        /* (SUPC_VREF) 2.048V voltage reference typical value  */
#define   SUPC_VREF_SEL_4V096_Val             _UINT32_(0x3)                                        /* (SUPC_VREF) 4.096V voltage reference typical value  */
#define SUPC_VREF_SEL_1V024                   (SUPC_VREF_SEL_1V024_Val << SUPC_VREF_SEL_Pos)       /* (SUPC_VREF) 1.024V voltage reference typical value Position */
#define SUPC_VREF_SEL_2V048                   (SUPC_VREF_SEL_2V048_Val << SUPC_VREF_SEL_Pos)       /* (SUPC_VREF) 2.048V voltage reference typical value Position */
#define SUPC_VREF_SEL_4V096                   (SUPC_VREF_SEL_4V096_Val << SUPC_VREF_SEL_Pos)       /* (SUPC_VREF) 4.096V voltage reference typical value Position */
#define SUPC_VREF_Msk                         _UINT32_(0x000F00C4)                                 /* (SUPC_VREF) Register Mask  */


/* SUPC register offsets definitions */
#define SUPC_INTENCLR_REG_OFST         _UINT32_(0x00)      /* (SUPC_INTENCLR) Interrupt Enable Clear Offset */
#define SUPC_INTENSET_REG_OFST         _UINT32_(0x04)      /* (SUPC_INTENSET) Interrupt Enable Set Offset */
#define SUPC_INTFLAG_REG_OFST          _UINT32_(0x08)      /* (SUPC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define SUPC_STATUS_REG_OFST           _UINT32_(0x0C)      /* (SUPC_STATUS) Power and Clocks Status Offset */
#define SUPC_BODVDD_REG_OFST           _UINT32_(0x10)      /* (SUPC_BODVDD) BODVDD Control Offset */
#define SUPC_VREG_REG_OFST             _UINT32_(0x18)      /* (SUPC_VREG) VREG Control Offset */
#define SUPC_VREF_REG_OFST             _UINT32_(0x1C)      /* (SUPC_VREF) VREF Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SUPC register API structure */
typedef struct
{  /* Supply Controller */
  __IO  uint32_t                       SUPC_INTENCLR;      /* Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       SUPC_INTENSET;      /* Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       SUPC_INTFLAG;       /* Offset: 0x08 (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       SUPC_STATUS;        /* Offset: 0x0C (R/   32) Power and Clocks Status */
  __IO  uint32_t                       SUPC_BODVDD;        /* Offset: 0x10 (R/W  32) BODVDD Control */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       SUPC_VREG;          /* Offset: 0x18 (R/W  32) VREG Control */
  __IO  uint32_t                       SUPC_VREF;          /* Offset: 0x1C (R/W  32) VREF Control */
} supc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_SUPC_COMPONENT_H_ */
