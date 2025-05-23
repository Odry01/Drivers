/*
 * Component description for MTB
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
#ifndef _PIC32CMJH01_MTB_COMPONENT_H_
#define _PIC32CMJH01_MTB_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR MTB                       */
/* ************************************************************************** */

/* -------- MTB_POSITION : (MTB Offset: 0x00) (R/W 32) MTB Position -------- */
#define MTB_POSITION_WRAP_Pos                 _UINT32_(2)                                          /* (MTB_POSITION) Pointer Value Wraps Position */
#define MTB_POSITION_WRAP_Msk                 (_UINT32_(0x1) << MTB_POSITION_WRAP_Pos)             /* (MTB_POSITION) Pointer Value Wraps Mask */
#define MTB_POSITION_WRAP(value)              (MTB_POSITION_WRAP_Msk & (_UINT32_(value) << MTB_POSITION_WRAP_Pos)) /* Assignment of value for WRAP in the MTB_POSITION register */
#define MTB_POSITION_POINTER_Pos              _UINT32_(3)                                          /* (MTB_POSITION) Trace Packet Location Pointer Position */
#define MTB_POSITION_POINTER_Msk              (_UINT32_(0x1FFFFFFF) << MTB_POSITION_POINTER_Pos)   /* (MTB_POSITION) Trace Packet Location Pointer Mask */
#define MTB_POSITION_POINTER(value)           (MTB_POSITION_POINTER_Msk & (_UINT32_(value) << MTB_POSITION_POINTER_Pos)) /* Assignment of value for POINTER in the MTB_POSITION register */
#define MTB_POSITION_Msk                      _UINT32_(0xFFFFFFFC)                                 /* (MTB_POSITION) Register Mask  */


/* -------- MTB_MASTER : (MTB Offset: 0x04) (R/W 32) MTB Master -------- */
#define MTB_MASTER_RESETVALUE                 _UINT32_(0x00)                                       /*  (MTB_MASTER) MTB Master  Reset Value */

#define MTB_MASTER_MASK_Pos                   _UINT32_(0)                                          /* (MTB_MASTER) Maximum Value of the Trace Buffer in SRAM Position */
#define MTB_MASTER_MASK_Msk                   (_UINT32_(0x1F) << MTB_MASTER_MASK_Pos)              /* (MTB_MASTER) Maximum Value of the Trace Buffer in SRAM Mask */
#define MTB_MASTER_MASK(value)                (MTB_MASTER_MASK_Msk & (_UINT32_(value) << MTB_MASTER_MASK_Pos)) /* Assignment of value for MASK in the MTB_MASTER register */
#define MTB_MASTER_TSTARTEN_Pos               _UINT32_(5)                                          /* (MTB_MASTER) Trace Start Input Enable Position */
#define MTB_MASTER_TSTARTEN_Msk               (_UINT32_(0x1) << MTB_MASTER_TSTARTEN_Pos)           /* (MTB_MASTER) Trace Start Input Enable Mask */
#define MTB_MASTER_TSTARTEN(value)            (MTB_MASTER_TSTARTEN_Msk & (_UINT32_(value) << MTB_MASTER_TSTARTEN_Pos)) /* Assignment of value for TSTARTEN in the MTB_MASTER register */
#define MTB_MASTER_TSTOPEN_Pos                _UINT32_(6)                                          /* (MTB_MASTER) Trace Stop Input Enable Position */
#define MTB_MASTER_TSTOPEN_Msk                (_UINT32_(0x1) << MTB_MASTER_TSTOPEN_Pos)            /* (MTB_MASTER) Trace Stop Input Enable Mask */
#define MTB_MASTER_TSTOPEN(value)             (MTB_MASTER_TSTOPEN_Msk & (_UINT32_(value) << MTB_MASTER_TSTOPEN_Pos)) /* Assignment of value for TSTOPEN in the MTB_MASTER register */
#define MTB_MASTER_SFRWPRIV_Pos               _UINT32_(7)                                          /* (MTB_MASTER) Special Function Register Write Privilege Position */
#define MTB_MASTER_SFRWPRIV_Msk               (_UINT32_(0x1) << MTB_MASTER_SFRWPRIV_Pos)           /* (MTB_MASTER) Special Function Register Write Privilege Mask */
#define MTB_MASTER_SFRWPRIV(value)            (MTB_MASTER_SFRWPRIV_Msk & (_UINT32_(value) << MTB_MASTER_SFRWPRIV_Pos)) /* Assignment of value for SFRWPRIV in the MTB_MASTER register */
#define MTB_MASTER_RAMPRIV_Pos                _UINT32_(8)                                          /* (MTB_MASTER) SRAM Privilege Position */
#define MTB_MASTER_RAMPRIV_Msk                (_UINT32_(0x1) << MTB_MASTER_RAMPRIV_Pos)            /* (MTB_MASTER) SRAM Privilege Mask */
#define MTB_MASTER_RAMPRIV(value)             (MTB_MASTER_RAMPRIV_Msk & (_UINT32_(value) << MTB_MASTER_RAMPRIV_Pos)) /* Assignment of value for RAMPRIV in the MTB_MASTER register */
#define MTB_MASTER_HALTREQ_Pos                _UINT32_(9)                                          /* (MTB_MASTER) Halt Request Position */
#define MTB_MASTER_HALTREQ_Msk                (_UINT32_(0x1) << MTB_MASTER_HALTREQ_Pos)            /* (MTB_MASTER) Halt Request Mask */
#define MTB_MASTER_HALTREQ(value)             (MTB_MASTER_HALTREQ_Msk & (_UINT32_(value) << MTB_MASTER_HALTREQ_Pos)) /* Assignment of value for HALTREQ in the MTB_MASTER register */
#define MTB_MASTER_EN_Pos                     _UINT32_(31)                                         /* (MTB_MASTER) Main Trace Enable Position */
#define MTB_MASTER_EN_Msk                     (_UINT32_(0x1) << MTB_MASTER_EN_Pos)                 /* (MTB_MASTER) Main Trace Enable Mask */
#define MTB_MASTER_EN(value)                  (MTB_MASTER_EN_Msk & (_UINT32_(value) << MTB_MASTER_EN_Pos)) /* Assignment of value for EN in the MTB_MASTER register */
#define MTB_MASTER_Msk                        _UINT32_(0x800003FF)                                 /* (MTB_MASTER) Register Mask  */


/* -------- MTB_FLOW : (MTB Offset: 0x08) (R/W 32) MTB Flow -------- */
#define MTB_FLOW_RESETVALUE                   _UINT32_(0x00)                                       /*  (MTB_FLOW) MTB Flow  Reset Value */

#define MTB_FLOW_AUTOSTOP_Pos                 _UINT32_(0)                                          /* (MTB_FLOW) Auto Stop Tracing Position */
#define MTB_FLOW_AUTOSTOP_Msk                 (_UINT32_(0x1) << MTB_FLOW_AUTOSTOP_Pos)             /* (MTB_FLOW) Auto Stop Tracing Mask */
#define MTB_FLOW_AUTOSTOP(value)              (MTB_FLOW_AUTOSTOP_Msk & (_UINT32_(value) << MTB_FLOW_AUTOSTOP_Pos)) /* Assignment of value for AUTOSTOP in the MTB_FLOW register */
#define MTB_FLOW_AUTOHALT_Pos                 _UINT32_(1)                                          /* (MTB_FLOW) Auto Halt Request Position */
#define MTB_FLOW_AUTOHALT_Msk                 (_UINT32_(0x1) << MTB_FLOW_AUTOHALT_Pos)             /* (MTB_FLOW) Auto Halt Request Mask */
#define MTB_FLOW_AUTOHALT(value)              (MTB_FLOW_AUTOHALT_Msk & (_UINT32_(value) << MTB_FLOW_AUTOHALT_Pos)) /* Assignment of value for AUTOHALT in the MTB_FLOW register */
#define MTB_FLOW_WATERMARK_Pos                _UINT32_(3)                                          /* (MTB_FLOW) Watermark value Position */
#define MTB_FLOW_WATERMARK_Msk                (_UINT32_(0x1FFFFFFF) << MTB_FLOW_WATERMARK_Pos)     /* (MTB_FLOW) Watermark value Mask */
#define MTB_FLOW_WATERMARK(value)             (MTB_FLOW_WATERMARK_Msk & (_UINT32_(value) << MTB_FLOW_WATERMARK_Pos)) /* Assignment of value for WATERMARK in the MTB_FLOW register */
#define MTB_FLOW_Msk                          _UINT32_(0xFFFFFFFB)                                 /* (MTB_FLOW) Register Mask  */


/* -------- MTB_BASE : (MTB Offset: 0x0C) ( R/ 32) MTB Base -------- */
#define MTB_BASE_Msk                          _UINT32_(0x00000000)                                 /* (MTB_BASE) Register Mask  */


/* -------- MTB_ITCTRL : (MTB Offset: 0xF00) (R/W 32) MTB Integration Mode Control -------- */
#define MTB_ITCTRL_Msk                        _UINT32_(0x00000000)                                 /* (MTB_ITCTRL) Register Mask  */


/* -------- MTB_CLAIMSET : (MTB Offset: 0xFA0) (R/W 32) MTB Claim Set -------- */
#define MTB_CLAIMSET_Msk                      _UINT32_(0x00000000)                                 /* (MTB_CLAIMSET) Register Mask  */


/* -------- MTB_CLAIMCLR : (MTB Offset: 0xFA4) (R/W 32) MTB Claim Clear -------- */
#define MTB_CLAIMCLR_Msk                      _UINT32_(0x00000000)                                 /* (MTB_CLAIMCLR) Register Mask  */


/* -------- MTB_LOCKACCESS : (MTB Offset: 0xFB0) (R/W 32) MTB Lock Access -------- */
#define MTB_LOCKACCESS_Msk                    _UINT32_(0x00000000)                                 /* (MTB_LOCKACCESS) Register Mask  */


/* -------- MTB_LOCKSTATUS : (MTB Offset: 0xFB4) ( R/ 32) MTB Lock Status -------- */
#define MTB_LOCKSTATUS_Msk                    _UINT32_(0x00000000)                                 /* (MTB_LOCKSTATUS) Register Mask  */


/* -------- MTB_AUTHSTATUS : (MTB Offset: 0xFB8) ( R/ 32) MTB Authentication Status -------- */
#define MTB_AUTHSTATUS_Msk                    _UINT32_(0x00000000)                                 /* (MTB_AUTHSTATUS) Register Mask  */


/* -------- MTB_DEVARCH : (MTB Offset: 0xFBC) ( R/ 32) MTB Device Architecture -------- */
#define MTB_DEVARCH_Msk                       _UINT32_(0x00000000)                                 /* (MTB_DEVARCH) Register Mask  */


/* -------- MTB_DEVID : (MTB Offset: 0xFC8) ( R/ 32) MTB Device Configuration -------- */
#define MTB_DEVID_Msk                         _UINT32_(0x00000000)                                 /* (MTB_DEVID) Register Mask  */


/* -------- MTB_DEVTYPE : (MTB Offset: 0xFCC) ( R/ 32) MTB Device Type -------- */
#define MTB_DEVTYPE_Msk                       _UINT32_(0x00000000)                                 /* (MTB_DEVTYPE) Register Mask  */


/* -------- MTB_PID4 : (MTB Offset: 0xFD0) ( R/ 32) Peripheral Identification 4 -------- */
#define MTB_PID4_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID4) Register Mask  */


/* -------- MTB_PID5 : (MTB Offset: 0xFD4) ( R/ 32) Peripheral Identification 5 -------- */
#define MTB_PID5_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID5) Register Mask  */


/* -------- MTB_PID6 : (MTB Offset: 0xFD8) ( R/ 32) Peripheral Identification 6 -------- */
#define MTB_PID6_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID6) Register Mask  */


/* -------- MTB_PID7 : (MTB Offset: 0xFDC) ( R/ 32) Peripheral Identification 7 -------- */
#define MTB_PID7_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID7) Register Mask  */


/* -------- MTB_PID0 : (MTB Offset: 0xFE0) ( R/ 32) Peripheral Identification 0 -------- */
#define MTB_PID0_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID0) Register Mask  */


/* -------- MTB_PID1 : (MTB Offset: 0xFE4) ( R/ 32) Peripheral Identification 1 -------- */
#define MTB_PID1_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID1) Register Mask  */


/* -------- MTB_PID2 : (MTB Offset: 0xFE8) ( R/ 32) Peripheral Identification 2 -------- */
#define MTB_PID2_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID2) Register Mask  */


/* -------- MTB_PID3 : (MTB Offset: 0xFEC) ( R/ 32) Peripheral Identification 3 -------- */
#define MTB_PID3_Msk                          _UINT32_(0x00000000)                                 /* (MTB_PID3) Register Mask  */


/* -------- MTB_CID0 : (MTB Offset: 0xFF0) ( R/ 32) Component Identification 0 -------- */
#define MTB_CID0_Msk                          _UINT32_(0x00000000)                                 /* (MTB_CID0) Register Mask  */


/* -------- MTB_CID1 : (MTB Offset: 0xFF4) ( R/ 32) Component Identification 1 -------- */
#define MTB_CID1_Msk                          _UINT32_(0x00000000)                                 /* (MTB_CID1) Register Mask  */


/* -------- MTB_CID2 : (MTB Offset: 0xFF8) ( R/ 32) Component Identification 2 -------- */
#define MTB_CID2_Msk                          _UINT32_(0x00000000)                                 /* (MTB_CID2) Register Mask  */


/* -------- MTB_CID3 : (MTB Offset: 0xFFC) ( R/ 32) Component Identification 3 -------- */
#define MTB_CID3_Msk                          _UINT32_(0x00000000)                                 /* (MTB_CID3) Register Mask  */


/* MTB register offsets definitions */
#define MTB_POSITION_REG_OFST          _UINT32_(0x00)      /* (MTB_POSITION) MTB Position Offset */
#define MTB_MASTER_REG_OFST            _UINT32_(0x04)      /* (MTB_MASTER) MTB Master Offset */
#define MTB_FLOW_REG_OFST              _UINT32_(0x08)      /* (MTB_FLOW) MTB Flow Offset */
#define MTB_BASE_REG_OFST              _UINT32_(0x0C)      /* (MTB_BASE) MTB Base Offset */
#define MTB_ITCTRL_REG_OFST            _UINT32_(0xF00)     /* (MTB_ITCTRL) MTB Integration Mode Control Offset */
#define MTB_CLAIMSET_REG_OFST          _UINT32_(0xFA0)     /* (MTB_CLAIMSET) MTB Claim Set Offset */
#define MTB_CLAIMCLR_REG_OFST          _UINT32_(0xFA4)     /* (MTB_CLAIMCLR) MTB Claim Clear Offset */
#define MTB_LOCKACCESS_REG_OFST        _UINT32_(0xFB0)     /* (MTB_LOCKACCESS) MTB Lock Access Offset */
#define MTB_LOCKSTATUS_REG_OFST        _UINT32_(0xFB4)     /* (MTB_LOCKSTATUS) MTB Lock Status Offset */
#define MTB_AUTHSTATUS_REG_OFST        _UINT32_(0xFB8)     /* (MTB_AUTHSTATUS) MTB Authentication Status Offset */
#define MTB_DEVARCH_REG_OFST           _UINT32_(0xFBC)     /* (MTB_DEVARCH) MTB Device Architecture Offset */
#define MTB_DEVID_REG_OFST             _UINT32_(0xFC8)     /* (MTB_DEVID) MTB Device Configuration Offset */
#define MTB_DEVTYPE_REG_OFST           _UINT32_(0xFCC)     /* (MTB_DEVTYPE) MTB Device Type Offset */
#define MTB_PID4_REG_OFST              _UINT32_(0xFD0)     /* (MTB_PID4) Peripheral Identification 4 Offset */
#define MTB_PID5_REG_OFST              _UINT32_(0xFD4)     /* (MTB_PID5) Peripheral Identification 5 Offset */
#define MTB_PID6_REG_OFST              _UINT32_(0xFD8)     /* (MTB_PID6) Peripheral Identification 6 Offset */
#define MTB_PID7_REG_OFST              _UINT32_(0xFDC)     /* (MTB_PID7) Peripheral Identification 7 Offset */
#define MTB_PID0_REG_OFST              _UINT32_(0xFE0)     /* (MTB_PID0) Peripheral Identification 0 Offset */
#define MTB_PID1_REG_OFST              _UINT32_(0xFE4)     /* (MTB_PID1) Peripheral Identification 1 Offset */
#define MTB_PID2_REG_OFST              _UINT32_(0xFE8)     /* (MTB_PID2) Peripheral Identification 2 Offset */
#define MTB_PID3_REG_OFST              _UINT32_(0xFEC)     /* (MTB_PID3) Peripheral Identification 3 Offset */
#define MTB_CID0_REG_OFST              _UINT32_(0xFF0)     /* (MTB_CID0) Component Identification 0 Offset */
#define MTB_CID1_REG_OFST              _UINT32_(0xFF4)     /* (MTB_CID1) Component Identification 1 Offset */
#define MTB_CID2_REG_OFST              _UINT32_(0xFF8)     /* (MTB_CID2) Component Identification 2 Offset */
#define MTB_CID3_REG_OFST              _UINT32_(0xFFC)     /* (MTB_CID3) Component Identification 3 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* MTB register API structure */
typedef struct
{  /* Cortex-M0+ Micro-Trace Buffer */
  __IO  uint32_t                       MTB_POSITION;       /* Offset: 0x00 (R/W  32) MTB Position */
  __IO  uint32_t                       MTB_MASTER;         /* Offset: 0x04 (R/W  32) MTB Master */
  __IO  uint32_t                       MTB_FLOW;           /* Offset: 0x08 (R/W  32) MTB Flow */
  __I   uint32_t                       MTB_BASE;           /* Offset: 0x0C (R/   32) MTB Base */
  __I   uint8_t                        Reserved1[0xEF0];
  __IO  uint32_t                       MTB_ITCTRL;         /* Offset: 0xF00 (R/W  32) MTB Integration Mode Control */
  __I   uint8_t                        Reserved2[0x9C];
  __IO  uint32_t                       MTB_CLAIMSET;       /* Offset: 0xFA0 (R/W  32) MTB Claim Set */
  __IO  uint32_t                       MTB_CLAIMCLR;       /* Offset: 0xFA4 (R/W  32) MTB Claim Clear */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       MTB_LOCKACCESS;     /* Offset: 0xFB0 (R/W  32) MTB Lock Access */
  __I   uint32_t                       MTB_LOCKSTATUS;     /* Offset: 0xFB4 (R/   32) MTB Lock Status */
  __I   uint32_t                       MTB_AUTHSTATUS;     /* Offset: 0xFB8 (R/   32) MTB Authentication Status */
  __I   uint32_t                       MTB_DEVARCH;        /* Offset: 0xFBC (R/   32) MTB Device Architecture */
  __I   uint8_t                        Reserved4[0x08];
  __I   uint32_t                       MTB_DEVID;          /* Offset: 0xFC8 (R/   32) MTB Device Configuration */
  __I   uint32_t                       MTB_DEVTYPE;        /* Offset: 0xFCC (R/   32) MTB Device Type */
  __I   uint32_t                       MTB_PID4;           /* Offset: 0xFD0 (R/   32) Peripheral Identification 4 */
  __I   uint32_t                       MTB_PID5;           /* Offset: 0xFD4 (R/   32) Peripheral Identification 5 */
  __I   uint32_t                       MTB_PID6;           /* Offset: 0xFD8 (R/   32) Peripheral Identification 6 */
  __I   uint32_t                       MTB_PID7;           /* Offset: 0xFDC (R/   32) Peripheral Identification 7 */
  __I   uint32_t                       MTB_PID0;           /* Offset: 0xFE0 (R/   32) Peripheral Identification 0 */
  __I   uint32_t                       MTB_PID1;           /* Offset: 0xFE4 (R/   32) Peripheral Identification 1 */
  __I   uint32_t                       MTB_PID2;           /* Offset: 0xFE8 (R/   32) Peripheral Identification 2 */
  __I   uint32_t                       MTB_PID3;           /* Offset: 0xFEC (R/   32) Peripheral Identification 3 */
  __I   uint32_t                       MTB_CID0;           /* Offset: 0xFF0 (R/   32) Component Identification 0 */
  __I   uint32_t                       MTB_CID1;           /* Offset: 0xFF4 (R/   32) Component Identification 1 */
  __I   uint32_t                       MTB_CID2;           /* Offset: 0xFF8 (R/   32) Component Identification 2 */
  __I   uint32_t                       MTB_CID3;           /* Offset: 0xFFC (R/   32) Component Identification 3 */
} mtb_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_MTB_COMPONENT_H_ */
