/*
 * Component description for OSC32KCTRL
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
#ifndef _PIC32CMJH01_OSC32KCTRL_COMPONENT_H_
#define _PIC32CMJH01_OSC32KCTRL_COMPONENT_H_

/* ************************************************************************** */
/*                   SOFTWARE API DEFINITION FOR OSC32KCTRL                   */
/* ************************************************************************** */

/* -------- OSC32KCTRL_INTENCLR : (OSC32KCTRL Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define OSC32KCTRL_INTENCLR_RESETVALUE        _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTENCLR) Interrupt Enable Clear  Reset Value */

#define OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos    _UINT32_(0)                                          /* (OSC32KCTRL_INTENCLR) XOSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENCLR_XOSC32KRDY_Msk    (_UINT32_(0x1) << OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTENCLR) XOSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENCLR_XOSC32KRDY(value) (OSC32KCTRL_INTENCLR_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos)) /* Assignment of value for XOSC32KRDY in the OSC32KCTRL_INTENCLR register */
#define OSC32KCTRL_INTENCLR_OSC32KRDY_Pos     _UINT32_(1)                                          /* (OSC32KCTRL_INTENCLR) OSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENCLR_OSC32KRDY_Msk     (_UINT32_(0x1) << OSC32KCTRL_INTENCLR_OSC32KRDY_Pos) /* (OSC32KCTRL_INTENCLR) OSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENCLR_OSC32KRDY(value)  (OSC32KCTRL_INTENCLR_OSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENCLR_OSC32KRDY_Pos)) /* Assignment of value for OSC32KRDY in the OSC32KCTRL_INTENCLR register */
#define OSC32KCTRL_INTENCLR_CLKFAIL_Pos       _UINT32_(2)                                          /* (OSC32KCTRL_INTENCLR) XOSC32K Clock Failure Detector Interrupt Enable Position */
#define OSC32KCTRL_INTENCLR_CLKFAIL_Msk       (_UINT32_(0x1) << OSC32KCTRL_INTENCLR_CLKFAIL_Pos)   /* (OSC32KCTRL_INTENCLR) XOSC32K Clock Failure Detector Interrupt Enable Mask */
#define OSC32KCTRL_INTENCLR_CLKFAIL(value)    (OSC32KCTRL_INTENCLR_CLKFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTENCLR_CLKFAIL_Pos)) /* Assignment of value for CLKFAIL in the OSC32KCTRL_INTENCLR register */
#define OSC32KCTRL_INTENCLR_Msk               _UINT32_(0x00000007)                                 /* (OSC32KCTRL_INTENCLR) Register Mask  */


/* -------- OSC32KCTRL_INTENSET : (OSC32KCTRL Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define OSC32KCTRL_INTENSET_RESETVALUE        _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTENSET) Interrupt Enable Set  Reset Value */

#define OSC32KCTRL_INTENSET_XOSC32KRDY_Pos    _UINT32_(0)                                          /* (OSC32KCTRL_INTENSET) XOSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENSET_XOSC32KRDY_Msk    (_UINT32_(0x1) << OSC32KCTRL_INTENSET_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTENSET) XOSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENSET_XOSC32KRDY(value) (OSC32KCTRL_INTENSET_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENSET_XOSC32KRDY_Pos)) /* Assignment of value for XOSC32KRDY in the OSC32KCTRL_INTENSET register */
#define OSC32KCTRL_INTENSET_OSC32KRDY_Pos     _UINT32_(1)                                          /* (OSC32KCTRL_INTENSET) OSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENSET_OSC32KRDY_Msk     (_UINT32_(0x1) << OSC32KCTRL_INTENSET_OSC32KRDY_Pos) /* (OSC32KCTRL_INTENSET) OSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENSET_OSC32KRDY(value)  (OSC32KCTRL_INTENSET_OSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENSET_OSC32KRDY_Pos)) /* Assignment of value for OSC32KRDY in the OSC32KCTRL_INTENSET register */
#define OSC32KCTRL_INTENSET_CLKFAIL_Pos       _UINT32_(2)                                          /* (OSC32KCTRL_INTENSET) XOSC32K Clock Failure Detector Interrupt Enable Position */
#define OSC32KCTRL_INTENSET_CLKFAIL_Msk       (_UINT32_(0x1) << OSC32KCTRL_INTENSET_CLKFAIL_Pos)   /* (OSC32KCTRL_INTENSET) XOSC32K Clock Failure Detector Interrupt Enable Mask */
#define OSC32KCTRL_INTENSET_CLKFAIL(value)    (OSC32KCTRL_INTENSET_CLKFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTENSET_CLKFAIL_Pos)) /* Assignment of value for CLKFAIL in the OSC32KCTRL_INTENSET register */
#define OSC32KCTRL_INTENSET_Msk               _UINT32_(0x00000007)                                 /* (OSC32KCTRL_INTENSET) Register Mask  */


/* -------- OSC32KCTRL_INTFLAG : (OSC32KCTRL Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#define OSC32KCTRL_INTFLAG_RESETVALUE         _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos     _UINT32_(0)                                          /* (OSC32KCTRL_INTFLAG) XOSC32K Ready Position */
#define OSC32KCTRL_INTFLAG_XOSC32KRDY_Msk     (_UINT32_(0x1) << OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTFLAG) XOSC32K Ready Mask */
#define OSC32KCTRL_INTFLAG_XOSC32KRDY(value)  (OSC32KCTRL_INTFLAG_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos)) /* Assignment of value for XOSC32KRDY in the OSC32KCTRL_INTFLAG register */
#define OSC32KCTRL_INTFLAG_OSC32KRDY_Pos      _UINT32_(1)                                          /* (OSC32KCTRL_INTFLAG) OSC32K Ready Position */
#define OSC32KCTRL_INTFLAG_OSC32KRDY_Msk      (_UINT32_(0x1) << OSC32KCTRL_INTFLAG_OSC32KRDY_Pos)  /* (OSC32KCTRL_INTFLAG) OSC32K Ready Mask */
#define OSC32KCTRL_INTFLAG_OSC32KRDY(value)   (OSC32KCTRL_INTFLAG_OSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTFLAG_OSC32KRDY_Pos)) /* Assignment of value for OSC32KRDY in the OSC32KCTRL_INTFLAG register */
#define OSC32KCTRL_INTFLAG_CLKFAIL_Pos        _UINT32_(2)                                          /* (OSC32KCTRL_INTFLAG) XOSC32K Clock Failure Detector Position */
#define OSC32KCTRL_INTFLAG_CLKFAIL_Msk        (_UINT32_(0x1) << OSC32KCTRL_INTFLAG_CLKFAIL_Pos)    /* (OSC32KCTRL_INTFLAG) XOSC32K Clock Failure Detector Mask */
#define OSC32KCTRL_INTFLAG_CLKFAIL(value)     (OSC32KCTRL_INTFLAG_CLKFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTFLAG_CLKFAIL_Pos)) /* Assignment of value for CLKFAIL in the OSC32KCTRL_INTFLAG register */
#define OSC32KCTRL_INTFLAG_Msk                _UINT32_(0x00000007)                                 /* (OSC32KCTRL_INTFLAG) Register Mask  */


/* -------- OSC32KCTRL_STATUS : (OSC32KCTRL Offset: 0x0C) ( R/ 32) Power and Clocks Status -------- */
#define OSC32KCTRL_STATUS_RESETVALUE          _UINT32_(0x00)                                       /*  (OSC32KCTRL_STATUS) Power and Clocks Status  Reset Value */

#define OSC32KCTRL_STATUS_XOSC32KRDY_Pos      _UINT32_(0)                                          /* (OSC32KCTRL_STATUS) XOSC32K Ready Position */
#define OSC32KCTRL_STATUS_XOSC32KRDY_Msk      (_UINT32_(0x1) << OSC32KCTRL_STATUS_XOSC32KRDY_Pos)  /* (OSC32KCTRL_STATUS) XOSC32K Ready Mask */
#define OSC32KCTRL_STATUS_XOSC32KRDY(value)   (OSC32KCTRL_STATUS_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_XOSC32KRDY_Pos)) /* Assignment of value for XOSC32KRDY in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_OSC32KRDY_Pos       _UINT32_(1)                                          /* (OSC32KCTRL_STATUS) OSC32K Ready Position */
#define OSC32KCTRL_STATUS_OSC32KRDY_Msk       (_UINT32_(0x1) << OSC32KCTRL_STATUS_OSC32KRDY_Pos)   /* (OSC32KCTRL_STATUS) OSC32K Ready Mask */
#define OSC32KCTRL_STATUS_OSC32KRDY(value)    (OSC32KCTRL_STATUS_OSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_OSC32KRDY_Pos)) /* Assignment of value for OSC32KRDY in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_CLKFAIL_Pos         _UINT32_(2)                                          /* (OSC32KCTRL_STATUS) XOSC32K Clock Failure Detector Position */
#define OSC32KCTRL_STATUS_CLKFAIL_Msk         (_UINT32_(0x1) << OSC32KCTRL_STATUS_CLKFAIL_Pos)     /* (OSC32KCTRL_STATUS) XOSC32K Clock Failure Detector Mask */
#define OSC32KCTRL_STATUS_CLKFAIL(value)      (OSC32KCTRL_STATUS_CLKFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_CLKFAIL_Pos)) /* Assignment of value for CLKFAIL in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_CLKSW_Pos           _UINT32_(3)                                          /* (OSC32KCTRL_STATUS) XOSC32K Clock switch Position */
#define OSC32KCTRL_STATUS_CLKSW_Msk           (_UINT32_(0x1) << OSC32KCTRL_STATUS_CLKSW_Pos)       /* (OSC32KCTRL_STATUS) XOSC32K Clock switch Mask */
#define OSC32KCTRL_STATUS_CLKSW(value)        (OSC32KCTRL_STATUS_CLKSW_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_CLKSW_Pos)) /* Assignment of value for CLKSW in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_Msk                 _UINT32_(0x0000000F)                                 /* (OSC32KCTRL_STATUS) Register Mask  */


/* -------- OSC32KCTRL_RTCCTRL : (OSC32KCTRL Offset: 0x10) (R/W 32) RTC Clock Selection -------- */
#define OSC32KCTRL_RTCCTRL_RESETVALUE         _UINT32_(0x00)                                       /*  (OSC32KCTRL_RTCCTRL) RTC Clock Selection  Reset Value */

#define OSC32KCTRL_RTCCTRL_RTCSEL_Pos         _UINT32_(0)                                          /* (OSC32KCTRL_RTCCTRL) RTC Clock Selection Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_Msk         (_UINT32_(0x7) << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)     /* (OSC32KCTRL_RTCCTRL) RTC Clock Selection Mask */
#define OSC32KCTRL_RTCCTRL_RTCSEL(value)      (OSC32KCTRL_RTCCTRL_RTCSEL_Msk & (_UINT32_(value) << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)) /* Assignment of value for RTCSEL in the OSC32KCTRL_RTCCTRL register */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K_Val _UINT32_(0x0)                                        /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32kHz internal ULP oscillator  */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K_Val _UINT32_(0x1)                                        /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32kHz internal ULP oscillator  */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K_Val _UINT32_(0x2)                                        /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz internal oscillator  */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K_Val _UINT32_(0x3)                                        /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz internal oscillator  */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K_Val _UINT32_(0x4)                                        /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz external crystal oscillator  */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K_Val _UINT32_(0x5)                                        /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz external crystal oscillator  */
#define OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K       (OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32kHz internal ULP oscillator Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K      (OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32kHz internal ULP oscillator Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K       (OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz internal oscillator Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K      (OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz internal oscillator Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K      (OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz external crystal oscillator Position */
#define OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K     (OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos) /* (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz external crystal oscillator Position */
#define OSC32KCTRL_RTCCTRL_Msk                _UINT32_(0x00000007)                                 /* (OSC32KCTRL_RTCCTRL) Register Mask  */


/* -------- OSC32KCTRL_XOSC32K : (OSC32KCTRL Offset: 0x14) (R/W 16) 32kHz External Crystal Oscillator (XOSC32K) Control -------- */
#define OSC32KCTRL_XOSC32K_RESETVALUE         _UINT16_(0x80)                                       /*  (OSC32KCTRL_XOSC32K) 32kHz External Crystal Oscillator (XOSC32K) Control  Reset Value */

#define OSC32KCTRL_XOSC32K_ENABLE_Pos         _UINT16_(1)                                          /* (OSC32KCTRL_XOSC32K) Oscillator Enable Position */
#define OSC32KCTRL_XOSC32K_ENABLE_Msk         (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_ENABLE_Pos)     /* (OSC32KCTRL_XOSC32K) Oscillator Enable Mask */
#define OSC32KCTRL_XOSC32K_ENABLE(value)      (OSC32KCTRL_XOSC32K_ENABLE_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_ENABLE_Pos)) /* Assignment of value for ENABLE in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_XTALEN_Pos         _UINT16_(2)                                          /* (OSC32KCTRL_XOSC32K) Crystal Oscillator Enable Position */
#define OSC32KCTRL_XOSC32K_XTALEN_Msk         (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_XTALEN_Pos)     /* (OSC32KCTRL_XOSC32K) Crystal Oscillator Enable Mask */
#define OSC32KCTRL_XOSC32K_XTALEN(value)      (OSC32KCTRL_XOSC32K_XTALEN_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_XTALEN_Pos)) /* Assignment of value for XTALEN in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_EN32K_Pos          _UINT16_(3)                                          /* (OSC32KCTRL_XOSC32K) 32kHz Output Enable Position */
#define OSC32KCTRL_XOSC32K_EN32K_Msk          (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_EN32K_Pos)      /* (OSC32KCTRL_XOSC32K) 32kHz Output Enable Mask */
#define OSC32KCTRL_XOSC32K_EN32K(value)       (OSC32KCTRL_XOSC32K_EN32K_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_EN32K_Pos)) /* Assignment of value for EN32K in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_EN1K_Pos           _UINT16_(4)                                          /* (OSC32KCTRL_XOSC32K) 1kHz Output Enable Position */
#define OSC32KCTRL_XOSC32K_EN1K_Msk           (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_EN1K_Pos)       /* (OSC32KCTRL_XOSC32K) 1kHz Output Enable Mask */
#define OSC32KCTRL_XOSC32K_EN1K(value)        (OSC32KCTRL_XOSC32K_EN1K_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_EN1K_Pos)) /* Assignment of value for EN1K in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_RUNSTDBY_Pos       _UINT16_(6)                                          /* (OSC32KCTRL_XOSC32K) Run in Standby Position */
#define OSC32KCTRL_XOSC32K_RUNSTDBY_Msk       (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_RUNSTDBY_Pos)   /* (OSC32KCTRL_XOSC32K) Run in Standby Mask */
#define OSC32KCTRL_XOSC32K_RUNSTDBY(value)    (OSC32KCTRL_XOSC32K_RUNSTDBY_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_ONDEMAND_Pos       _UINT16_(7)                                          /* (OSC32KCTRL_XOSC32K) On Demand Control Position */
#define OSC32KCTRL_XOSC32K_ONDEMAND_Msk       (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_ONDEMAND_Pos)   /* (OSC32KCTRL_XOSC32K) On Demand Control Mask */
#define OSC32KCTRL_XOSC32K_ONDEMAND(value)    (OSC32KCTRL_XOSC32K_ONDEMAND_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_ONDEMAND_Pos)) /* Assignment of value for ONDEMAND in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_STARTUP_Pos        _UINT16_(8)                                          /* (OSC32KCTRL_XOSC32K) Oscillator Start-Up Time Position */
#define OSC32KCTRL_XOSC32K_STARTUP_Msk        (_UINT16_(0x7) << OSC32KCTRL_XOSC32K_STARTUP_Pos)    /* (OSC32KCTRL_XOSC32K) Oscillator Start-Up Time Mask */
#define OSC32KCTRL_XOSC32K_STARTUP(value)     (OSC32KCTRL_XOSC32K_STARTUP_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_STARTUP_Pos)) /* Assignment of value for STARTUP in the OSC32KCTRL_XOSC32K register */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE1_Val _UINT16_(0x0)                                        /* (OSC32KCTRL_XOSC32K) 122 us  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE32_Val _UINT16_(0x1)                                        /* (OSC32KCTRL_XOSC32K) 1.06 ms  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE2048_Val _UINT16_(0x2)                                        /* (OSC32KCTRL_XOSC32K) 62.6 ms  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE4096_Val _UINT16_(0x3)                                        /* (OSC32KCTRL_XOSC32K) 125 ms  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE16384_Val _UINT16_(0x4)                                        /* (OSC32KCTRL_XOSC32K) 500 ms  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE32768_Val _UINT16_(0x5)                                        /* (OSC32KCTRL_XOSC32K) 1 s  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE65536_Val _UINT16_(0x6)                                        /* (OSC32KCTRL_XOSC32K) 2 s  */
#define   OSC32KCTRL_XOSC32K_STARTUP_CYCLE131072_Val _UINT16_(0x7)                                        /* (OSC32KCTRL_XOSC32K) 4 s  */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE1     (OSC32KCTRL_XOSC32K_STARTUP_CYCLE1_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 122 us Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE32    (OSC32KCTRL_XOSC32K_STARTUP_CYCLE32_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 1.06 ms Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE2048  (OSC32KCTRL_XOSC32K_STARTUP_CYCLE2048_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 62.6 ms Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE4096  (OSC32KCTRL_XOSC32K_STARTUP_CYCLE4096_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 125 ms Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE16384 (OSC32KCTRL_XOSC32K_STARTUP_CYCLE16384_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 500 ms Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE32768 (OSC32KCTRL_XOSC32K_STARTUP_CYCLE32768_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 1 s Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE65536 (OSC32KCTRL_XOSC32K_STARTUP_CYCLE65536_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 2 s Position */
#define OSC32KCTRL_XOSC32K_STARTUP_CYCLE131072 (OSC32KCTRL_XOSC32K_STARTUP_CYCLE131072_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 4 s Position */
#define OSC32KCTRL_XOSC32K_WRTLOCK_Pos        _UINT16_(12)                                         /* (OSC32KCTRL_XOSC32K) Write Lock Position */
#define OSC32KCTRL_XOSC32K_WRTLOCK_Msk        (_UINT16_(0x1) << OSC32KCTRL_XOSC32K_WRTLOCK_Pos)    /* (OSC32KCTRL_XOSC32K) Write Lock Mask */
#define OSC32KCTRL_XOSC32K_WRTLOCK(value)     (OSC32KCTRL_XOSC32K_WRTLOCK_Msk & (_UINT16_(value) << OSC32KCTRL_XOSC32K_WRTLOCK_Pos)) /* Assignment of value for WRTLOCK in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_Msk                _UINT16_(0x17DE)                                     /* (OSC32KCTRL_XOSC32K) Register Mask  */


/* -------- OSC32KCTRL_CFDCTRL : (OSC32KCTRL Offset: 0x16) (R/W 8) Clock Failure Detector Control -------- */
#define OSC32KCTRL_CFDCTRL_RESETVALUE         _UINT8_(0x00)                                        /*  (OSC32KCTRL_CFDCTRL) Clock Failure Detector Control  Reset Value */

#define OSC32KCTRL_CFDCTRL_CFDEN_Pos          _UINT8_(0)                                           /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Enable Position */
#define OSC32KCTRL_CFDCTRL_CFDEN_Msk          (_UINT8_(0x1) << OSC32KCTRL_CFDCTRL_CFDEN_Pos)       /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Enable Mask */
#define OSC32KCTRL_CFDCTRL_CFDEN(value)       (OSC32KCTRL_CFDCTRL_CFDEN_Msk & (_UINT8_(value) << OSC32KCTRL_CFDCTRL_CFDEN_Pos)) /* Assignment of value for CFDEN in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_SWBACK_Pos         _UINT8_(1)                                           /* (OSC32KCTRL_CFDCTRL) Clock Switch Back Enable Position */
#define OSC32KCTRL_CFDCTRL_SWBACK_Msk         (_UINT8_(0x1) << OSC32KCTRL_CFDCTRL_SWBACK_Pos)      /* (OSC32KCTRL_CFDCTRL) Clock Switch Back Enable Mask */
#define OSC32KCTRL_CFDCTRL_SWBACK(value)      (OSC32KCTRL_CFDCTRL_SWBACK_Msk & (_UINT8_(value) << OSC32KCTRL_CFDCTRL_SWBACK_Pos)) /* Assignment of value for SWBACK in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_CFDPRESC_Pos       _UINT8_(2)                                           /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Prescaler Position */
#define OSC32KCTRL_CFDCTRL_CFDPRESC_Msk       (_UINT8_(0x1) << OSC32KCTRL_CFDCTRL_CFDPRESC_Pos)    /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Prescaler Mask */
#define OSC32KCTRL_CFDCTRL_CFDPRESC(value)    (OSC32KCTRL_CFDCTRL_CFDPRESC_Msk & (_UINT8_(value) << OSC32KCTRL_CFDCTRL_CFDPRESC_Pos)) /* Assignment of value for CFDPRESC in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_Msk                _UINT8_(0x07)                                        /* (OSC32KCTRL_CFDCTRL) Register Mask  */


/* -------- OSC32KCTRL_EVCTRL : (OSC32KCTRL Offset: 0x17) (R/W 8) Event Control -------- */
#define OSC32KCTRL_EVCTRL_RESETVALUE          _UINT8_(0x00)                                        /*  (OSC32KCTRL_EVCTRL) Event Control  Reset Value */

#define OSC32KCTRL_EVCTRL_CFDEO_Pos           _UINT8_(0)                                           /* (OSC32KCTRL_EVCTRL) Clock Failure Detector Event Output Enable Position */
#define OSC32KCTRL_EVCTRL_CFDEO_Msk           (_UINT8_(0x1) << OSC32KCTRL_EVCTRL_CFDEO_Pos)        /* (OSC32KCTRL_EVCTRL) Clock Failure Detector Event Output Enable Mask */
#define OSC32KCTRL_EVCTRL_CFDEO(value)        (OSC32KCTRL_EVCTRL_CFDEO_Msk & (_UINT8_(value) << OSC32KCTRL_EVCTRL_CFDEO_Pos)) /* Assignment of value for CFDEO in the OSC32KCTRL_EVCTRL register */
#define OSC32KCTRL_EVCTRL_Msk                 _UINT8_(0x01)                                        /* (OSC32KCTRL_EVCTRL) Register Mask  */


/* -------- OSC32KCTRL_OSC32K : (OSC32KCTRL Offset: 0x18) (R/W 32) 32kHz Internal Oscillator (OSC32K) Control -------- */
#define OSC32KCTRL_OSC32K_RESETVALUE          _UINT32_(0x3F0080)                                   /*  (OSC32KCTRL_OSC32K) 32kHz Internal Oscillator (OSC32K) Control  Reset Value */

#define OSC32KCTRL_OSC32K_ENABLE_Pos          _UINT32_(1)                                          /* (OSC32KCTRL_OSC32K) Oscillator Enable Position */
#define OSC32KCTRL_OSC32K_ENABLE_Msk          (_UINT32_(0x1) << OSC32KCTRL_OSC32K_ENABLE_Pos)      /* (OSC32KCTRL_OSC32K) Oscillator Enable Mask */
#define OSC32KCTRL_OSC32K_ENABLE(value)       (OSC32KCTRL_OSC32K_ENABLE_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_ENABLE_Pos)) /* Assignment of value for ENABLE in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_EN32K_Pos           _UINT32_(2)                                          /* (OSC32KCTRL_OSC32K) 32kHz Output Enable Position */
#define OSC32KCTRL_OSC32K_EN32K_Msk           (_UINT32_(0x1) << OSC32KCTRL_OSC32K_EN32K_Pos)       /* (OSC32KCTRL_OSC32K) 32kHz Output Enable Mask */
#define OSC32KCTRL_OSC32K_EN32K(value)        (OSC32KCTRL_OSC32K_EN32K_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_EN32K_Pos)) /* Assignment of value for EN32K in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_EN1K_Pos            _UINT32_(3)                                          /* (OSC32KCTRL_OSC32K) 1kHz Output Enable Position */
#define OSC32KCTRL_OSC32K_EN1K_Msk            (_UINT32_(0x1) << OSC32KCTRL_OSC32K_EN1K_Pos)        /* (OSC32KCTRL_OSC32K) 1kHz Output Enable Mask */
#define OSC32KCTRL_OSC32K_EN1K(value)         (OSC32KCTRL_OSC32K_EN1K_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_EN1K_Pos)) /* Assignment of value for EN1K in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_RUNSTDBY_Pos        _UINT32_(6)                                          /* (OSC32KCTRL_OSC32K) Run in Standby Position */
#define OSC32KCTRL_OSC32K_RUNSTDBY_Msk        (_UINT32_(0x1) << OSC32KCTRL_OSC32K_RUNSTDBY_Pos)    /* (OSC32KCTRL_OSC32K) Run in Standby Mask */
#define OSC32KCTRL_OSC32K_RUNSTDBY(value)     (OSC32KCTRL_OSC32K_RUNSTDBY_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_ONDEMAND_Pos        _UINT32_(7)                                          /* (OSC32KCTRL_OSC32K) On Demand Control Position */
#define OSC32KCTRL_OSC32K_ONDEMAND_Msk        (_UINT32_(0x1) << OSC32KCTRL_OSC32K_ONDEMAND_Pos)    /* (OSC32KCTRL_OSC32K) On Demand Control Mask */
#define OSC32KCTRL_OSC32K_ONDEMAND(value)     (OSC32KCTRL_OSC32K_ONDEMAND_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_ONDEMAND_Pos)) /* Assignment of value for ONDEMAND in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_STARTUP_Pos         _UINT32_(8)                                          /* (OSC32KCTRL_OSC32K) Oscillator Start-Up Time Position */
#define OSC32KCTRL_OSC32K_STARTUP_Msk         (_UINT32_(0x7) << OSC32KCTRL_OSC32K_STARTUP_Pos)     /* (OSC32KCTRL_OSC32K) Oscillator Start-Up Time Mask */
#define OSC32KCTRL_OSC32K_STARTUP(value)      (OSC32KCTRL_OSC32K_STARTUP_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_STARTUP_Pos)) /* Assignment of value for STARTUP in the OSC32KCTRL_OSC32K register */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE3_Val _UINT32_(0x0)                                        /* (OSC32KCTRL_OSC32K) 0.183 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE4_Val _UINT32_(0x1)                                        /* (OSC32KCTRL_OSC32K) 0.214 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE6_Val _UINT32_(0x2)                                        /* (OSC32KCTRL_OSC32K) 0.275 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE10_Val _UINT32_(0x3)                                        /* (OSC32KCTRL_OSC32K) 0.397 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE18_Val _UINT32_(0x4)                                        /* (OSC32KCTRL_OSC32K) 0.641 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE34_Val _UINT32_(0x5)                                        /* (OSC32KCTRL_OSC32K) 1.129 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE66_Val _UINT32_(0x6)                                        /* (OSC32KCTRL_OSC32K) 2.106 ms  */
#define   OSC32KCTRL_OSC32K_STARTUP_CYCLE130_Val _UINT32_(0x7)                                        /* (OSC32KCTRL_OSC32K) 4.059 ms  */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE3      (OSC32KCTRL_OSC32K_STARTUP_CYCLE3_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 0.183 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE4      (OSC32KCTRL_OSC32K_STARTUP_CYCLE4_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 0.214 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE6      (OSC32KCTRL_OSC32K_STARTUP_CYCLE6_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 0.275 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE10     (OSC32KCTRL_OSC32K_STARTUP_CYCLE10_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 0.397 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE18     (OSC32KCTRL_OSC32K_STARTUP_CYCLE18_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 0.641 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE34     (OSC32KCTRL_OSC32K_STARTUP_CYCLE34_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 1.129 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE66     (OSC32KCTRL_OSC32K_STARTUP_CYCLE66_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 2.106 ms Position */
#define OSC32KCTRL_OSC32K_STARTUP_CYCLE130    (OSC32KCTRL_OSC32K_STARTUP_CYCLE130_Val << OSC32KCTRL_OSC32K_STARTUP_Pos) /* (OSC32KCTRL_OSC32K) 4.059 ms Position */
#define OSC32KCTRL_OSC32K_WRTLOCK_Pos         _UINT32_(12)                                         /* (OSC32KCTRL_OSC32K) Write Lock Position */
#define OSC32KCTRL_OSC32K_WRTLOCK_Msk         (_UINT32_(0x1) << OSC32KCTRL_OSC32K_WRTLOCK_Pos)     /* (OSC32KCTRL_OSC32K) Write Lock Mask */
#define OSC32KCTRL_OSC32K_WRTLOCK(value)      (OSC32KCTRL_OSC32K_WRTLOCK_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_WRTLOCK_Pos)) /* Assignment of value for WRTLOCK in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_CALIB_Pos           _UINT32_(16)                                         /* (OSC32KCTRL_OSC32K) Oscillator Calibration Position */
#define OSC32KCTRL_OSC32K_CALIB_Msk           (_UINT32_(0x7F) << OSC32KCTRL_OSC32K_CALIB_Pos)      /* (OSC32KCTRL_OSC32K) Oscillator Calibration Mask */
#define OSC32KCTRL_OSC32K_CALIB(value)        (OSC32KCTRL_OSC32K_CALIB_Msk & (_UINT32_(value) << OSC32KCTRL_OSC32K_CALIB_Pos)) /* Assignment of value for CALIB in the OSC32KCTRL_OSC32K register */
#define OSC32KCTRL_OSC32K_Msk                 _UINT32_(0x007F17CE)                                 /* (OSC32KCTRL_OSC32K) Register Mask  */


/* -------- OSC32KCTRL_OSCULP32K : (OSC32KCTRL Offset: 0x1C) (R/W 32) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control -------- */
#define OSC32KCTRL_OSCULP32K_WRTLOCK_Pos      _UINT32_(15)                                         /* (OSC32KCTRL_OSCULP32K) Write Lock Position */
#define OSC32KCTRL_OSCULP32K_WRTLOCK_Msk      (_UINT32_(0x1) << OSC32KCTRL_OSCULP32K_WRTLOCK_Pos)  /* (OSC32KCTRL_OSCULP32K) Write Lock Mask */
#define OSC32KCTRL_OSCULP32K_WRTLOCK(value)   (OSC32KCTRL_OSCULP32K_WRTLOCK_Msk & (_UINT32_(value) << OSC32KCTRL_OSCULP32K_WRTLOCK_Pos)) /* Assignment of value for WRTLOCK in the OSC32KCTRL_OSCULP32K register */
#define OSC32KCTRL_OSCULP32K_Msk              _UINT32_(0x00008000)                                 /* (OSC32KCTRL_OSCULP32K) Register Mask  */


/* OSC32KCTRL register offsets definitions */
#define OSC32KCTRL_INTENCLR_REG_OFST   _UINT32_(0x00)      /* (OSC32KCTRL_INTENCLR) Interrupt Enable Clear Offset */
#define OSC32KCTRL_INTENSET_REG_OFST   _UINT32_(0x04)      /* (OSC32KCTRL_INTENSET) Interrupt Enable Set Offset */
#define OSC32KCTRL_INTFLAG_REG_OFST    _UINT32_(0x08)      /* (OSC32KCTRL_INTFLAG) Interrupt Flag Status and Clear Offset */
#define OSC32KCTRL_STATUS_REG_OFST     _UINT32_(0x0C)      /* (OSC32KCTRL_STATUS) Power and Clocks Status Offset */
#define OSC32KCTRL_RTCCTRL_REG_OFST    _UINT32_(0x10)      /* (OSC32KCTRL_RTCCTRL) RTC Clock Selection Offset */
#define OSC32KCTRL_XOSC32K_REG_OFST    _UINT32_(0x14)      /* (OSC32KCTRL_XOSC32K) 32kHz External Crystal Oscillator (XOSC32K) Control Offset */
#define OSC32KCTRL_CFDCTRL_REG_OFST    _UINT32_(0x16)      /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Control Offset */
#define OSC32KCTRL_EVCTRL_REG_OFST     _UINT32_(0x17)      /* (OSC32KCTRL_EVCTRL) Event Control Offset */
#define OSC32KCTRL_OSC32K_REG_OFST     _UINT32_(0x18)      /* (OSC32KCTRL_OSC32K) 32kHz Internal Oscillator (OSC32K) Control Offset */
#define OSC32KCTRL_OSCULP32K_REG_OFST  _UINT32_(0x1C)      /* (OSC32KCTRL_OSCULP32K) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* OSC32KCTRL register API structure */
typedef struct
{  /* 32k Oscillators Control */
  __IO  uint32_t                       OSC32KCTRL_INTENCLR; /* Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       OSC32KCTRL_INTENSET; /* Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       OSC32KCTRL_INTFLAG; /* Offset: 0x08 (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       OSC32KCTRL_STATUS;  /* Offset: 0x0C (R/   32) Power and Clocks Status */
  __IO  uint32_t                       OSC32KCTRL_RTCCTRL; /* Offset: 0x10 (R/W  32) RTC Clock Selection */
  __IO  uint16_t                       OSC32KCTRL_XOSC32K; /* Offset: 0x14 (R/W  16) 32kHz External Crystal Oscillator (XOSC32K) Control */
  __IO  uint8_t                        OSC32KCTRL_CFDCTRL; /* Offset: 0x16 (R/W  8) Clock Failure Detector Control */
  __IO  uint8_t                        OSC32KCTRL_EVCTRL;  /* Offset: 0x17 (R/W  8) Event Control */
  __IO  uint32_t                       OSC32KCTRL_OSC32K;  /* Offset: 0x18 (R/W  32) 32kHz Internal Oscillator (OSC32K) Control */
  __IO  uint32_t                       OSC32KCTRL_OSCULP32K; /* Offset: 0x1C (R/W  32) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control */
} osc32kctrl_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_OSC32KCTRL_COMPONENT_H_ */
