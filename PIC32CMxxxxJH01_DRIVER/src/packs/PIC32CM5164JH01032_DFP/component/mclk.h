/*
 * Component description for MCLK
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
#ifndef _PIC32CMJH01_MCLK_COMPONENT_H_
#define _PIC32CMJH01_MCLK_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR MCLK                      */
/* ************************************************************************** */

/* -------- MCLK_INTENCLR : (MCLK Offset: 0x01) (R/W 8) Interrupt Enable Clear -------- */
#define MCLK_INTENCLR_RESETVALUE              _UINT8_(0x00)                                        /*  (MCLK_INTENCLR) Interrupt Enable Clear  Reset Value */

#define MCLK_INTENCLR_CKRDY_Pos               _UINT8_(0)                                           /* (MCLK_INTENCLR) Clock Ready Interrupt Enable Position */
#define MCLK_INTENCLR_CKRDY_Msk               (_UINT8_(0x1) << MCLK_INTENCLR_CKRDY_Pos)            /* (MCLK_INTENCLR) Clock Ready Interrupt Enable Mask */
#define MCLK_INTENCLR_CKRDY(value)            (MCLK_INTENCLR_CKRDY_Msk & (_UINT8_(value) << MCLK_INTENCLR_CKRDY_Pos)) /* Assignment of value for CKRDY in the MCLK_INTENCLR register */
#define MCLK_INTENCLR_Msk                     _UINT8_(0x01)                                        /* (MCLK_INTENCLR) Register Mask  */


/* -------- MCLK_INTENSET : (MCLK Offset: 0x02) (R/W 8) Interrupt Enable Set -------- */
#define MCLK_INTENSET_RESETVALUE              _UINT8_(0x00)                                        /*  (MCLK_INTENSET) Interrupt Enable Set  Reset Value */

#define MCLK_INTENSET_CKRDY_Pos               _UINT8_(0)                                           /* (MCLK_INTENSET) Clock Ready Interrupt Enable Position */
#define MCLK_INTENSET_CKRDY_Msk               (_UINT8_(0x1) << MCLK_INTENSET_CKRDY_Pos)            /* (MCLK_INTENSET) Clock Ready Interrupt Enable Mask */
#define MCLK_INTENSET_CKRDY(value)            (MCLK_INTENSET_CKRDY_Msk & (_UINT8_(value) << MCLK_INTENSET_CKRDY_Pos)) /* Assignment of value for CKRDY in the MCLK_INTENSET register */
#define MCLK_INTENSET_Msk                     _UINT8_(0x01)                                        /* (MCLK_INTENSET) Register Mask  */


/* -------- MCLK_INTFLAG : (MCLK Offset: 0x03) (R/W 8) Interrupt Flag Status and Clear -------- */
#define MCLK_INTFLAG_RESETVALUE               _UINT8_(0x01)                                        /*  (MCLK_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define MCLK_INTFLAG_CKRDY_Pos                _UINT8_(0)                                           /* (MCLK_INTFLAG) Clock Ready Position */
#define MCLK_INTFLAG_CKRDY_Msk                (_UINT8_(0x1) << MCLK_INTFLAG_CKRDY_Pos)             /* (MCLK_INTFLAG) Clock Ready Mask */
#define MCLK_INTFLAG_CKRDY(value)             (MCLK_INTFLAG_CKRDY_Msk & (_UINT8_(value) << MCLK_INTFLAG_CKRDY_Pos)) /* Assignment of value for CKRDY in the MCLK_INTFLAG register */
#define MCLK_INTFLAG_Msk                      _UINT8_(0x01)                                        /* (MCLK_INTFLAG) Register Mask  */


/* -------- MCLK_CPUDIV : (MCLK Offset: 0x04) (R/W 8) CPU Clock Division -------- */
#define MCLK_CPUDIV_RESETVALUE                _UINT8_(0x01)                                        /*  (MCLK_CPUDIV) CPU Clock Division  Reset Value */

#define MCLK_CPUDIV_CPUDIV_Pos                _UINT8_(0)                                           /* (MCLK_CPUDIV) CPU Clock Division Factor Position */
#define MCLK_CPUDIV_CPUDIV_Msk                (_UINT8_(0xFF) << MCLK_CPUDIV_CPUDIV_Pos)            /* (MCLK_CPUDIV) CPU Clock Division Factor Mask */
#define MCLK_CPUDIV_CPUDIV(value)             (MCLK_CPUDIV_CPUDIV_Msk & (_UINT8_(value) << MCLK_CPUDIV_CPUDIV_Pos)) /* Assignment of value for CPUDIV in the MCLK_CPUDIV register */
#define   MCLK_CPUDIV_CPUDIV_DIV1_Val         _UINT8_(0x1)                                         /* (MCLK_CPUDIV) Divide by 1  */
#define   MCLK_CPUDIV_CPUDIV_DIV2_Val         _UINT8_(0x2)                                         /* (MCLK_CPUDIV) Divide by 2  */
#define   MCLK_CPUDIV_CPUDIV_DIV4_Val         _UINT8_(0x4)                                         /* (MCLK_CPUDIV) Divide by 4  */
#define   MCLK_CPUDIV_CPUDIV_DIV8_Val         _UINT8_(0x8)                                         /* (MCLK_CPUDIV) Divide by 8  */
#define   MCLK_CPUDIV_CPUDIV_DIV16_Val        _UINT8_(0x10)                                        /* (MCLK_CPUDIV) Divide by 16  */
#define   MCLK_CPUDIV_CPUDIV_DIV32_Val        _UINT8_(0x20)                                        /* (MCLK_CPUDIV) Divide by 32  */
#define   MCLK_CPUDIV_CPUDIV_DIV64_Val        _UINT8_(0x40)                                        /* (MCLK_CPUDIV) Divide by 64  */
#define   MCLK_CPUDIV_CPUDIV_DIV128_Val       _UINT8_(0x80)                                        /* (MCLK_CPUDIV) Divide by 128  */
#define MCLK_CPUDIV_CPUDIV_DIV1               (MCLK_CPUDIV_CPUDIV_DIV1_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 1 Position */
#define MCLK_CPUDIV_CPUDIV_DIV2               (MCLK_CPUDIV_CPUDIV_DIV2_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 2 Position */
#define MCLK_CPUDIV_CPUDIV_DIV4               (MCLK_CPUDIV_CPUDIV_DIV4_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 4 Position */
#define MCLK_CPUDIV_CPUDIV_DIV8               (MCLK_CPUDIV_CPUDIV_DIV8_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 8 Position */
#define MCLK_CPUDIV_CPUDIV_DIV16              (MCLK_CPUDIV_CPUDIV_DIV16_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 16 Position */
#define MCLK_CPUDIV_CPUDIV_DIV32              (MCLK_CPUDIV_CPUDIV_DIV32_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 32 Position */
#define MCLK_CPUDIV_CPUDIV_DIV64              (MCLK_CPUDIV_CPUDIV_DIV64_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 64 Position */
#define MCLK_CPUDIV_CPUDIV_DIV128             (MCLK_CPUDIV_CPUDIV_DIV128_Val << MCLK_CPUDIV_CPUDIV_Pos) /* (MCLK_CPUDIV) Divide by 128 Position */
#define MCLK_CPUDIV_Msk                       _UINT8_(0xFF)                                        /* (MCLK_CPUDIV) Register Mask  */


/* -------- MCLK_AHBMASK : (MCLK Offset: 0x10) (R/W 32) AHB Mask -------- */
#define MCLK_AHBMASK_RESETVALUE               _UINT32_(0x7FFF)                                     /*  (MCLK_AHBMASK) AHB Mask  Reset Value */

#define MCLK_AHBMASK_APBA_Pos                 _UINT32_(0)                                          /* (MCLK_AHBMASK) APBA AHB Clock Mask Position */
#define MCLK_AHBMASK_APBA_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_APBA_Pos)             /* (MCLK_AHBMASK) APBA AHB Clock Mask Mask */
#define MCLK_AHBMASK_APBA(value)              (MCLK_AHBMASK_APBA_Msk & (_UINT32_(value) << MCLK_AHBMASK_APBA_Pos)) /* Assignment of value for APBA in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_APBB_Pos                 _UINT32_(1)                                          /* (MCLK_AHBMASK) APBB AHB Clock Mask Position */
#define MCLK_AHBMASK_APBB_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_APBB_Pos)             /* (MCLK_AHBMASK) APBB AHB Clock Mask Mask */
#define MCLK_AHBMASK_APBB(value)              (MCLK_AHBMASK_APBB_Msk & (_UINT32_(value) << MCLK_AHBMASK_APBB_Pos)) /* Assignment of value for APBB in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_APBC_Pos                 _UINT32_(2)                                          /* (MCLK_AHBMASK) APBC AHB Clock Mask Position */
#define MCLK_AHBMASK_APBC_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_APBC_Pos)             /* (MCLK_AHBMASK) APBC AHB Clock Mask Mask */
#define MCLK_AHBMASK_APBC(value)              (MCLK_AHBMASK_APBC_Msk & (_UINT32_(value) << MCLK_AHBMASK_APBC_Pos)) /* Assignment of value for APBC in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_DSU_Pos                  _UINT32_(3)                                          /* (MCLK_AHBMASK) DSU AHB Clock Mask Position */
#define MCLK_AHBMASK_DSU_Msk                  (_UINT32_(0x1) << MCLK_AHBMASK_DSU_Pos)              /* (MCLK_AHBMASK) DSU AHB Clock Mask Mask */
#define MCLK_AHBMASK_DSU(value)               (MCLK_AHBMASK_DSU_Msk & (_UINT32_(value) << MCLK_AHBMASK_DSU_Pos)) /* Assignment of value for DSU in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_HMATRIXHS_Pos            _UINT32_(4)                                          /* (MCLK_AHBMASK) HMATRIXHS AHB Clock Mask Position */
#define MCLK_AHBMASK_HMATRIXHS_Msk            (_UINT32_(0x1) << MCLK_AHBMASK_HMATRIXHS_Pos)        /* (MCLK_AHBMASK) HMATRIXHS AHB Clock Mask Mask */
#define MCLK_AHBMASK_HMATRIXHS(value)         (MCLK_AHBMASK_HMATRIXHS_Msk & (_UINT32_(value) << MCLK_AHBMASK_HMATRIXHS_Pos)) /* Assignment of value for HMATRIXHS in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_NVMCTRL_Pos              _UINT32_(5)                                          /* (MCLK_AHBMASK) NVMCTRL AHB Clock Mask Position */
#define MCLK_AHBMASK_NVMCTRL_Msk              (_UINT32_(0x1) << MCLK_AHBMASK_NVMCTRL_Pos)          /* (MCLK_AHBMASK) NVMCTRL AHB Clock Mask Mask */
#define MCLK_AHBMASK_NVMCTRL(value)           (MCLK_AHBMASK_NVMCTRL_Msk & (_UINT32_(value) << MCLK_AHBMASK_NVMCTRL_Pos)) /* Assignment of value for NVMCTRL in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_MCRAMC_Pos               _UINT32_(6)                                          /* (MCLK_AHBMASK) MCRAMC AHB Clock Mask Position */
#define MCLK_AHBMASK_MCRAMC_Msk               (_UINT32_(0x1) << MCLK_AHBMASK_MCRAMC_Pos)           /* (MCLK_AHBMASK) MCRAMC AHB Clock Mask Mask */
#define MCLK_AHBMASK_MCRAMC(value)            (MCLK_AHBMASK_MCRAMC_Msk & (_UINT32_(value) << MCLK_AHBMASK_MCRAMC_Pos)) /* Assignment of value for MCRAMC in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_DMAC_Pos                 _UINT32_(7)                                          /* (MCLK_AHBMASK) DMAC AHB Clock Mask Position */
#define MCLK_AHBMASK_DMAC_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_DMAC_Pos)             /* (MCLK_AHBMASK) DMAC AHB Clock Mask Mask */
#define MCLK_AHBMASK_DMAC(value)              (MCLK_AHBMASK_DMAC_Msk & (_UINT32_(value) << MCLK_AHBMASK_DMAC_Pos)) /* Assignment of value for DMAC in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_CAN0_Pos                 _UINT32_(8)                                          /* (MCLK_AHBMASK) CAN0 AHB Clock Mask Position */
#define MCLK_AHBMASK_CAN0_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_CAN0_Pos)             /* (MCLK_AHBMASK) CAN0 AHB Clock Mask Mask */
#define MCLK_AHBMASK_CAN0(value)              (MCLK_AHBMASK_CAN0_Msk & (_UINT32_(value) << MCLK_AHBMASK_CAN0_Pos)) /* Assignment of value for CAN0 in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_CAN1_Pos                 _UINT32_(9)                                          /* (MCLK_AHBMASK) CAN1 AHB Clock Mask Position */
#define MCLK_AHBMASK_CAN1_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_CAN1_Pos)             /* (MCLK_AHBMASK) CAN1 AHB Clock Mask Mask */
#define MCLK_AHBMASK_CAN1(value)              (MCLK_AHBMASK_CAN1_Msk & (_UINT32_(value) << MCLK_AHBMASK_CAN1_Pos)) /* Assignment of value for CAN1 in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_PAC_Pos                  _UINT32_(10)                                         /* (MCLK_AHBMASK) PAC AHB Clock Mask Position */
#define MCLK_AHBMASK_PAC_Msk                  (_UINT32_(0x1) << MCLK_AHBMASK_PAC_Pos)              /* (MCLK_AHBMASK) PAC AHB Clock Mask Mask */
#define MCLK_AHBMASK_PAC(value)               (MCLK_AHBMASK_PAC_Msk & (_UINT32_(value) << MCLK_AHBMASK_PAC_Pos)) /* Assignment of value for PAC in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_DIVAS_Pos                _UINT32_(12)                                         /* (MCLK_AHBMASK) DIVAS AHB Clock Mask Position */
#define MCLK_AHBMASK_DIVAS_Msk                (_UINT32_(0x1) << MCLK_AHBMASK_DIVAS_Pos)            /* (MCLK_AHBMASK) DIVAS AHB Clock Mask Mask */
#define MCLK_AHBMASK_DIVAS(value)             (MCLK_AHBMASK_DIVAS_Msk & (_UINT32_(value) << MCLK_AHBMASK_DIVAS_Pos)) /* Assignment of value for DIVAS in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_APBD_Pos                 _UINT32_(13)                                         /* (MCLK_AHBMASK) APBD AHB Clock Mask Position */
#define MCLK_AHBMASK_APBD_Msk                 (_UINT32_(0x1) << MCLK_AHBMASK_APBD_Pos)             /* (MCLK_AHBMASK) APBD AHB Clock Mask Mask */
#define MCLK_AHBMASK_APBD(value)              (MCLK_AHBMASK_APBD_Msk & (_UINT32_(value) << MCLK_AHBMASK_APBD_Pos)) /* Assignment of value for APBD in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_ICM_Pos                  _UINT32_(14)                                         /* (MCLK_AHBMASK) ICM AHB Clock Mask Position */
#define MCLK_AHBMASK_ICM_Msk                  (_UINT32_(0x1) << MCLK_AHBMASK_ICM_Pos)              /* (MCLK_AHBMASK) ICM AHB Clock Mask Mask */
#define MCLK_AHBMASK_ICM(value)               (MCLK_AHBMASK_ICM_Msk & (_UINT32_(value) << MCLK_AHBMASK_ICM_Pos)) /* Assignment of value for ICM in the MCLK_AHBMASK register */
#define MCLK_AHBMASK_Msk                      _UINT32_(0x000077FF)                                 /* (MCLK_AHBMASK) Register Mask  */

#define MCLK_AHBMASK_CAN_Pos                  _UINT32_(8)                                          /* (MCLK_AHBMASK Position) CANx AHB Clock Mask */
#define MCLK_AHBMASK_CAN_Msk                  (_UINT32_(0x3) << MCLK_AHBMASK_CAN_Pos)              /* (MCLK_AHBMASK Mask) CAN */
#define MCLK_AHBMASK_CAN(value)               (MCLK_AHBMASK_CAN_Msk & (_UINT32_(value) << MCLK_AHBMASK_CAN_Pos)) 

/* -------- MCLK_APBAMASK : (MCLK Offset: 0x14) (R/W 32) APBA Mask -------- */
#define MCLK_APBAMASK_RESETVALUE              _UINT32_(0x1FFF)                                     /*  (MCLK_APBAMASK) APBA Mask  Reset Value */

#define MCLK_APBAMASK_PAC_Pos                 _UINT32_(0)                                          /* (MCLK_APBAMASK) PAC APB Clock Enable Position */
#define MCLK_APBAMASK_PAC_Msk                 (_UINT32_(0x1) << MCLK_APBAMASK_PAC_Pos)             /* (MCLK_APBAMASK) PAC APB Clock Enable Mask */
#define MCLK_APBAMASK_PAC(value)              (MCLK_APBAMASK_PAC_Msk & (_UINT32_(value) << MCLK_APBAMASK_PAC_Pos)) /* Assignment of value for PAC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_PM_Pos                  _UINT32_(1)                                          /* (MCLK_APBAMASK) PM APB Clock Enable Position */
#define MCLK_APBAMASK_PM_Msk                  (_UINT32_(0x1) << MCLK_APBAMASK_PM_Pos)              /* (MCLK_APBAMASK) PM APB Clock Enable Mask */
#define MCLK_APBAMASK_PM(value)               (MCLK_APBAMASK_PM_Msk & (_UINT32_(value) << MCLK_APBAMASK_PM_Pos)) /* Assignment of value for PM in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_MCLK_Pos                _UINT32_(2)                                          /* (MCLK_APBAMASK) MCLK APB Clock Enable Position */
#define MCLK_APBAMASK_MCLK_Msk                (_UINT32_(0x1) << MCLK_APBAMASK_MCLK_Pos)            /* (MCLK_APBAMASK) MCLK APB Clock Enable Mask */
#define MCLK_APBAMASK_MCLK(value)             (MCLK_APBAMASK_MCLK_Msk & (_UINT32_(value) << MCLK_APBAMASK_MCLK_Pos)) /* Assignment of value for MCLK in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_RSTC_Pos                _UINT32_(3)                                          /* (MCLK_APBAMASK) RSTC APB Clock Enable Position */
#define MCLK_APBAMASK_RSTC_Msk                (_UINT32_(0x1) << MCLK_APBAMASK_RSTC_Pos)            /* (MCLK_APBAMASK) RSTC APB Clock Enable Mask */
#define MCLK_APBAMASK_RSTC(value)             (MCLK_APBAMASK_RSTC_Msk & (_UINT32_(value) << MCLK_APBAMASK_RSTC_Pos)) /* Assignment of value for RSTC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_OSCCTRL_Pos             _UINT32_(4)                                          /* (MCLK_APBAMASK) OSCCTRL APB Clock Enable Position */
#define MCLK_APBAMASK_OSCCTRL_Msk             (_UINT32_(0x1) << MCLK_APBAMASK_OSCCTRL_Pos)         /* (MCLK_APBAMASK) OSCCTRL APB Clock Enable Mask */
#define MCLK_APBAMASK_OSCCTRL(value)          (MCLK_APBAMASK_OSCCTRL_Msk & (_UINT32_(value) << MCLK_APBAMASK_OSCCTRL_Pos)) /* Assignment of value for OSCCTRL in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_OSC32KCTRL_Pos          _UINT32_(5)                                          /* (MCLK_APBAMASK) OSC32KCTRL APB Clock Enable Position */
#define MCLK_APBAMASK_OSC32KCTRL_Msk          (_UINT32_(0x1) << MCLK_APBAMASK_OSC32KCTRL_Pos)      /* (MCLK_APBAMASK) OSC32KCTRL APB Clock Enable Mask */
#define MCLK_APBAMASK_OSC32KCTRL(value)       (MCLK_APBAMASK_OSC32KCTRL_Msk & (_UINT32_(value) << MCLK_APBAMASK_OSC32KCTRL_Pos)) /* Assignment of value for OSC32KCTRL in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_SUPC_Pos                _UINT32_(6)                                          /* (MCLK_APBAMASK) SUPC APB Clock Enable Position */
#define MCLK_APBAMASK_SUPC_Msk                (_UINT32_(0x1) << MCLK_APBAMASK_SUPC_Pos)            /* (MCLK_APBAMASK) SUPC APB Clock Enable Mask */
#define MCLK_APBAMASK_SUPC(value)             (MCLK_APBAMASK_SUPC_Msk & (_UINT32_(value) << MCLK_APBAMASK_SUPC_Pos)) /* Assignment of value for SUPC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_GCLK_Pos                _UINT32_(7)                                          /* (MCLK_APBAMASK) GCLK APB Clock Enable Position */
#define MCLK_APBAMASK_GCLK_Msk                (_UINT32_(0x1) << MCLK_APBAMASK_GCLK_Pos)            /* (MCLK_APBAMASK) GCLK APB Clock Enable Mask */
#define MCLK_APBAMASK_GCLK(value)             (MCLK_APBAMASK_GCLK_Msk & (_UINT32_(value) << MCLK_APBAMASK_GCLK_Pos)) /* Assignment of value for GCLK in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_WDT_Pos                 _UINT32_(8)                                          /* (MCLK_APBAMASK) WDT APB Clock Enable Position */
#define MCLK_APBAMASK_WDT_Msk                 (_UINT32_(0x1) << MCLK_APBAMASK_WDT_Pos)             /* (MCLK_APBAMASK) WDT APB Clock Enable Mask */
#define MCLK_APBAMASK_WDT(value)              (MCLK_APBAMASK_WDT_Msk & (_UINT32_(value) << MCLK_APBAMASK_WDT_Pos)) /* Assignment of value for WDT in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_RTC_Pos                 _UINT32_(9)                                          /* (MCLK_APBAMASK) RTC APB Clock Enable Position */
#define MCLK_APBAMASK_RTC_Msk                 (_UINT32_(0x1) << MCLK_APBAMASK_RTC_Pos)             /* (MCLK_APBAMASK) RTC APB Clock Enable Mask */
#define MCLK_APBAMASK_RTC(value)              (MCLK_APBAMASK_RTC_Msk & (_UINT32_(value) << MCLK_APBAMASK_RTC_Pos)) /* Assignment of value for RTC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_EIC_Pos                 _UINT32_(10)                                         /* (MCLK_APBAMASK) EIC APB Clock Enable Position */
#define MCLK_APBAMASK_EIC_Msk                 (_UINT32_(0x1) << MCLK_APBAMASK_EIC_Pos)             /* (MCLK_APBAMASK) EIC APB Clock Enable Mask */
#define MCLK_APBAMASK_EIC(value)              (MCLK_APBAMASK_EIC_Msk & (_UINT32_(value) << MCLK_APBAMASK_EIC_Pos)) /* Assignment of value for EIC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_FREQM_Pos               _UINT32_(11)                                         /* (MCLK_APBAMASK) FREQM APB Clock Enable Position */
#define MCLK_APBAMASK_FREQM_Msk               (_UINT32_(0x1) << MCLK_APBAMASK_FREQM_Pos)           /* (MCLK_APBAMASK) FREQM APB Clock Enable Mask */
#define MCLK_APBAMASK_FREQM(value)            (MCLK_APBAMASK_FREQM_Msk & (_UINT32_(value) << MCLK_APBAMASK_FREQM_Pos)) /* Assignment of value for FREQM in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_MCRAMC_Pos              _UINT32_(12)                                         /* (MCLK_APBAMASK) MCRAMC APB Clock Enable Position */
#define MCLK_APBAMASK_MCRAMC_Msk              (_UINT32_(0x1) << MCLK_APBAMASK_MCRAMC_Pos)          /* (MCLK_APBAMASK) MCRAMC APB Clock Enable Mask */
#define MCLK_APBAMASK_MCRAMC(value)           (MCLK_APBAMASK_MCRAMC_Msk & (_UINT32_(value) << MCLK_APBAMASK_MCRAMC_Pos)) /* Assignment of value for MCRAMC in the MCLK_APBAMASK register */
#define MCLK_APBAMASK_Msk                     _UINT32_(0x00001FFF)                                 /* (MCLK_APBAMASK) Register Mask  */


/* -------- MCLK_APBBMASK : (MCLK Offset: 0x18) (R/W 32) APBB Mask -------- */
#define MCLK_APBBMASK_RESETVALUE              _UINT32_(0x07)                                       /*  (MCLK_APBBMASK) APBB Mask  Reset Value */

#define MCLK_APBBMASK_PORT_Pos                _UINT32_(0)                                          /* (MCLK_APBBMASK) PORT APB Clock Enable Position */
#define MCLK_APBBMASK_PORT_Msk                (_UINT32_(0x1) << MCLK_APBBMASK_PORT_Pos)            /* (MCLK_APBBMASK) PORT APB Clock Enable Mask */
#define MCLK_APBBMASK_PORT(value)             (MCLK_APBBMASK_PORT_Msk & (_UINT32_(value) << MCLK_APBBMASK_PORT_Pos)) /* Assignment of value for PORT in the MCLK_APBBMASK register */
#define MCLK_APBBMASK_DSU_Pos                 _UINT32_(1)                                          /* (MCLK_APBBMASK) DSU APB Clock Enable Position */
#define MCLK_APBBMASK_DSU_Msk                 (_UINT32_(0x1) << MCLK_APBBMASK_DSU_Pos)             /* (MCLK_APBBMASK) DSU APB Clock Enable Mask */
#define MCLK_APBBMASK_DSU(value)              (MCLK_APBBMASK_DSU_Msk & (_UINT32_(value) << MCLK_APBBMASK_DSU_Pos)) /* Assignment of value for DSU in the MCLK_APBBMASK register */
#define MCLK_APBBMASK_NVMCTRL_Pos             _UINT32_(2)                                          /* (MCLK_APBBMASK) NVMCTRL APB Clock Enable Position */
#define MCLK_APBBMASK_NVMCTRL_Msk             (_UINT32_(0x1) << MCLK_APBBMASK_NVMCTRL_Pos)         /* (MCLK_APBBMASK) NVMCTRL APB Clock Enable Mask */
#define MCLK_APBBMASK_NVMCTRL(value)          (MCLK_APBBMASK_NVMCTRL_Msk & (_UINT32_(value) << MCLK_APBBMASK_NVMCTRL_Pos)) /* Assignment of value for NVMCTRL in the MCLK_APBBMASK register */
#define MCLK_APBBMASK_HMATRIXHS_Pos           _UINT32_(5)                                          /* (MCLK_APBBMASK) HMATRIXHS APB Clock Enable Position */
#define MCLK_APBBMASK_HMATRIXHS_Msk           (_UINT32_(0x1) << MCLK_APBBMASK_HMATRIXHS_Pos)       /* (MCLK_APBBMASK) HMATRIXHS APB Clock Enable Mask */
#define MCLK_APBBMASK_HMATRIXHS(value)        (MCLK_APBBMASK_HMATRIXHS_Msk & (_UINT32_(value) << MCLK_APBBMASK_HMATRIXHS_Pos)) /* Assignment of value for HMATRIXHS in the MCLK_APBBMASK register */
#define MCLK_APBBMASK_Msk                     _UINT32_(0x00000027)                                 /* (MCLK_APBBMASK) Register Mask  */


/* -------- MCLK_APBCMASK : (MCLK Offset: 0x1C) (R/W 32) APBC Mask -------- */
#define MCLK_APBCMASK_RESETVALUE              _UINT32_(0x8000000)                                  /*  (MCLK_APBCMASK) APBC Mask  Reset Value */

#define MCLK_APBCMASK_EVSYS_Pos               _UINT32_(0)                                          /* (MCLK_APBCMASK) EVSYS APB Clock Enable Position */
#define MCLK_APBCMASK_EVSYS_Msk               (_UINT32_(0x1) << MCLK_APBCMASK_EVSYS_Pos)           /* (MCLK_APBCMASK) EVSYS APB Clock Enable Mask */
#define MCLK_APBCMASK_EVSYS(value)            (MCLK_APBCMASK_EVSYS_Msk & (_UINT32_(value) << MCLK_APBCMASK_EVSYS_Pos)) /* Assignment of value for EVSYS in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM0_Pos             _UINT32_(1)                                          /* (MCLK_APBCMASK) SERCOM0 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM0_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM0_Pos)         /* (MCLK_APBCMASK) SERCOM0 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM0(value)          (MCLK_APBCMASK_SERCOM0_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM0_Pos)) /* Assignment of value for SERCOM0 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM1_Pos             _UINT32_(2)                                          /* (MCLK_APBCMASK) SERCOM1 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM1_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM1_Pos)         /* (MCLK_APBCMASK) SERCOM1 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM1(value)          (MCLK_APBCMASK_SERCOM1_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM1_Pos)) /* Assignment of value for SERCOM1 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM2_Pos             _UINT32_(3)                                          /* (MCLK_APBCMASK) SERCOM2 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM2_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM2_Pos)         /* (MCLK_APBCMASK) SERCOM2 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM2(value)          (MCLK_APBCMASK_SERCOM2_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM2_Pos)) /* Assignment of value for SERCOM2 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM3_Pos             _UINT32_(4)                                          /* (MCLK_APBCMASK) SERCOM3 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM3_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM3_Pos)         /* (MCLK_APBCMASK) SERCOM3 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM3(value)          (MCLK_APBCMASK_SERCOM3_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM3_Pos)) /* Assignment of value for SERCOM3 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM4_Pos             _UINT32_(5)                                          /* (MCLK_APBCMASK) SERCOM4 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM4_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM4_Pos)         /* (MCLK_APBCMASK) SERCOM4 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM4(value)          (MCLK_APBCMASK_SERCOM4_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM4_Pos)) /* Assignment of value for SERCOM4 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SERCOM5_Pos             _UINT32_(6)                                          /* (MCLK_APBCMASK) SERCOM5 APB Clock Enable Position */
#define MCLK_APBCMASK_SERCOM5_Msk             (_UINT32_(0x1) << MCLK_APBCMASK_SERCOM5_Pos)         /* (MCLK_APBCMASK) SERCOM5 APB Clock Enable Mask */
#define MCLK_APBCMASK_SERCOM5(value)          (MCLK_APBCMASK_SERCOM5_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM5_Pos)) /* Assignment of value for SERCOM5 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TCC0_Pos                _UINT32_(9)                                          /* (MCLK_APBCMASK) TCC0 APB Clock Enable Position */
#define MCLK_APBCMASK_TCC0_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_TCC0_Pos)            /* (MCLK_APBCMASK) TCC0 APB Clock Enable Mask */
#define MCLK_APBCMASK_TCC0(value)             (MCLK_APBCMASK_TCC0_Msk & (_UINT32_(value) << MCLK_APBCMASK_TCC0_Pos)) /* Assignment of value for TCC0 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TCC1_Pos                _UINT32_(10)                                         /* (MCLK_APBCMASK) TCC1 APB Clock Enable Position */
#define MCLK_APBCMASK_TCC1_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_TCC1_Pos)            /* (MCLK_APBCMASK) TCC1 APB Clock Enable Mask */
#define MCLK_APBCMASK_TCC1(value)             (MCLK_APBCMASK_TCC1_Msk & (_UINT32_(value) << MCLK_APBCMASK_TCC1_Pos)) /* Assignment of value for TCC1 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TCC2_Pos                _UINT32_(11)                                         /* (MCLK_APBCMASK) TCC2 APB Clock Enable Position */
#define MCLK_APBCMASK_TCC2_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_TCC2_Pos)            /* (MCLK_APBCMASK) TCC2 APB Clock Enable Mask */
#define MCLK_APBCMASK_TCC2(value)             (MCLK_APBCMASK_TCC2_Msk & (_UINT32_(value) << MCLK_APBCMASK_TCC2_Pos)) /* Assignment of value for TCC2 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TC0_Pos                 _UINT32_(12)                                         /* (MCLK_APBCMASK) TC0 APB Clock Enable Position */
#define MCLK_APBCMASK_TC0_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_TC0_Pos)             /* (MCLK_APBCMASK) TC0 APB Clock Enable Mask */
#define MCLK_APBCMASK_TC0(value)              (MCLK_APBCMASK_TC0_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC0_Pos)) /* Assignment of value for TC0 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TC1_Pos                 _UINT32_(13)                                         /* (MCLK_APBCMASK) TC1 APB Clock Enable Position */
#define MCLK_APBCMASK_TC1_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_TC1_Pos)             /* (MCLK_APBCMASK) TC1 APB Clock Enable Mask */
#define MCLK_APBCMASK_TC1(value)              (MCLK_APBCMASK_TC1_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC1_Pos)) /* Assignment of value for TC1 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TC2_Pos                 _UINT32_(14)                                         /* (MCLK_APBCMASK) TC2 APB Clock Enable Position */
#define MCLK_APBCMASK_TC2_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_TC2_Pos)             /* (MCLK_APBCMASK) TC2 APB Clock Enable Mask */
#define MCLK_APBCMASK_TC2(value)              (MCLK_APBCMASK_TC2_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC2_Pos)) /* Assignment of value for TC2 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TC3_Pos                 _UINT32_(15)                                         /* (MCLK_APBCMASK) TC3 APB Clock Enable Position */
#define MCLK_APBCMASK_TC3_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_TC3_Pos)             /* (MCLK_APBCMASK) TC3 APB Clock Enable Mask */
#define MCLK_APBCMASK_TC3(value)              (MCLK_APBCMASK_TC3_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC3_Pos)) /* Assignment of value for TC3 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_TC4_Pos                 _UINT32_(16)                                         /* (MCLK_APBCMASK) TC4 APB Clock Enable Position */
#define MCLK_APBCMASK_TC4_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_TC4_Pos)             /* (MCLK_APBCMASK) TC4 APB Clock Enable Mask */
#define MCLK_APBCMASK_TC4(value)              (MCLK_APBCMASK_TC4_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC4_Pos)) /* Assignment of value for TC4 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_ADC0_Pos                _UINT32_(17)                                         /* (MCLK_APBCMASK) ADC0 APB Clock Enable Position */
#define MCLK_APBCMASK_ADC0_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_ADC0_Pos)            /* (MCLK_APBCMASK) ADC0 APB Clock Enable Mask */
#define MCLK_APBCMASK_ADC0(value)             (MCLK_APBCMASK_ADC0_Msk & (_UINT32_(value) << MCLK_APBCMASK_ADC0_Pos)) /* Assignment of value for ADC0 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_ADC1_Pos                _UINT32_(18)                                         /* (MCLK_APBCMASK) ADC1 APB Clock Enable Position */
#define MCLK_APBCMASK_ADC1_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_ADC1_Pos)            /* (MCLK_APBCMASK) ADC1 APB Clock Enable Mask */
#define MCLK_APBCMASK_ADC1(value)             (MCLK_APBCMASK_ADC1_Msk & (_UINT32_(value) << MCLK_APBCMASK_ADC1_Pos)) /* Assignment of value for ADC1 in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_AC_Pos                  _UINT32_(19)                                         /* (MCLK_APBCMASK) AC APB Clock Enable Position */
#define MCLK_APBCMASK_AC_Msk                  (_UINT32_(0x1) << MCLK_APBCMASK_AC_Pos)              /* (MCLK_APBCMASK) AC APB Clock Enable Mask */
#define MCLK_APBCMASK_AC(value)               (MCLK_APBCMASK_AC_Msk & (_UINT32_(value) << MCLK_APBCMASK_AC_Pos)) /* Assignment of value for AC in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_DAC_Pos                 _UINT32_(20)                                         /* (MCLK_APBCMASK) DAC APB Clock Enable Position */
#define MCLK_APBCMASK_DAC_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_DAC_Pos)             /* (MCLK_APBCMASK) DAC APB Clock Enable Mask */
#define MCLK_APBCMASK_DAC(value)              (MCLK_APBCMASK_DAC_Msk & (_UINT32_(value) << MCLK_APBCMASK_DAC_Pos)) /* Assignment of value for DAC in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_PTC_Pos                 _UINT32_(21)                                         /* (MCLK_APBCMASK) PTC APB Clock Enable Position */
#define MCLK_APBCMASK_PTC_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_PTC_Pos)             /* (MCLK_APBCMASK) PTC APB Clock Enable Mask */
#define MCLK_APBCMASK_PTC(value)              (MCLK_APBCMASK_PTC_Msk & (_UINT32_(value) << MCLK_APBCMASK_PTC_Pos)) /* Assignment of value for PTC in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_CCL_Pos                 _UINT32_(22)                                         /* (MCLK_APBCMASK) CCL APB Clock Enable Position */
#define MCLK_APBCMASK_CCL_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_CCL_Pos)             /* (MCLK_APBCMASK) CCL APB Clock Enable Mask */
#define MCLK_APBCMASK_CCL(value)              (MCLK_APBCMASK_CCL_Msk & (_UINT32_(value) << MCLK_APBCMASK_CCL_Pos)) /* Assignment of value for CCL in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_ICM_Pos                 _UINT32_(25)                                         /* (MCLK_APBCMASK) ICM APB Clock Enable Position */
#define MCLK_APBCMASK_ICM_Msk                 (_UINT32_(0x1) << MCLK_APBCMASK_ICM_Pos)             /* (MCLK_APBCMASK) ICM APB Clock Enable Mask */
#define MCLK_APBCMASK_ICM(value)              (MCLK_APBCMASK_ICM_Msk & (_UINT32_(value) << MCLK_APBCMASK_ICM_Pos)) /* Assignment of value for ICM in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_PDEC_Pos                _UINT32_(26)                                         /* (MCLK_APBCMASK) PDEC APB Clock Enable Position */
#define MCLK_APBCMASK_PDEC_Msk                (_UINT32_(0x1) << MCLK_APBCMASK_PDEC_Pos)            /* (MCLK_APBCMASK) PDEC APB Clock Enable Mask */
#define MCLK_APBCMASK_PDEC(value)             (MCLK_APBCMASK_PDEC_Msk & (_UINT32_(value) << MCLK_APBCMASK_PDEC_Pos)) /* Assignment of value for PDEC in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_SMBIST_Pos              _UINT32_(27)                                         /* (MCLK_APBCMASK) SMBIST APB Clock Enable Position */
#define MCLK_APBCMASK_SMBIST_Msk              (_UINT32_(0x1) << MCLK_APBCMASK_SMBIST_Pos)          /* (MCLK_APBCMASK) SMBIST APB Clock Enable Mask */
#define MCLK_APBCMASK_SMBIST(value)           (MCLK_APBCMASK_SMBIST_Msk & (_UINT32_(value) << MCLK_APBCMASK_SMBIST_Pos)) /* Assignment of value for SMBIST in the MCLK_APBCMASK register */
#define MCLK_APBCMASK_Msk                     _UINT32_(0x0E7FFE7F)                                 /* (MCLK_APBCMASK) Register Mask  */

#define MCLK_APBCMASK_SERCOM_Pos              _UINT32_(1)                                          /* (MCLK_APBCMASK Position) SERCOMx APB Clock Enable */
#define MCLK_APBCMASK_SERCOM_Msk              (_UINT32_(0x3F) << MCLK_APBCMASK_SERCOM_Pos)         /* (MCLK_APBCMASK Mask) SERCOM */
#define MCLK_APBCMASK_SERCOM(value)           (MCLK_APBCMASK_SERCOM_Msk & (_UINT32_(value) << MCLK_APBCMASK_SERCOM_Pos)) 
#define MCLK_APBCMASK_TCC_Pos                 _UINT32_(9)                                          /* (MCLK_APBCMASK Position) TCCx APB Clock Enable */
#define MCLK_APBCMASK_TCC_Msk                 (_UINT32_(0x7) << MCLK_APBCMASK_TCC_Pos)             /* (MCLK_APBCMASK Mask) TCC */
#define MCLK_APBCMASK_TCC(value)              (MCLK_APBCMASK_TCC_Msk & (_UINT32_(value) << MCLK_APBCMASK_TCC_Pos)) 
#define MCLK_APBCMASK_TC_Pos                  _UINT32_(12)                                         /* (MCLK_APBCMASK Position) TCx APB Clock Enable */
#define MCLK_APBCMASK_TC_Msk                  (_UINT32_(0x1F) << MCLK_APBCMASK_TC_Pos)             /* (MCLK_APBCMASK Mask) TC */
#define MCLK_APBCMASK_TC(value)               (MCLK_APBCMASK_TC_Msk & (_UINT32_(value) << MCLK_APBCMASK_TC_Pos)) 
#define MCLK_APBCMASK_ADC_Pos                 _UINT32_(17)                                         /* (MCLK_APBCMASK Position) ADCx APB Clock Enable */
#define MCLK_APBCMASK_ADC_Msk                 (_UINT32_(0x3) << MCLK_APBCMASK_ADC_Pos)             /* (MCLK_APBCMASK Mask) ADC */
#define MCLK_APBCMASK_ADC(value)              (MCLK_APBCMASK_ADC_Msk & (_UINT32_(value) << MCLK_APBCMASK_ADC_Pos)) 

/* -------- MCLK_APBDMASK : (MCLK Offset: 0x20) (R/W 32) APBD Mask -------- */
#define MCLK_APBDMASK_RESETVALUE              _UINT32_(0x00)                                       /*  (MCLK_APBDMASK) APBD Mask  Reset Value */

#define MCLK_APBDMASK_SERCOM6_Pos             _UINT32_(0)                                          /* (MCLK_APBDMASK) SERCOM6 APB Clock Enable Position */
#define MCLK_APBDMASK_SERCOM6_Msk             (_UINT32_(0x1) << MCLK_APBDMASK_SERCOM6_Pos)         /* (MCLK_APBDMASK) SERCOM6 APB Clock Enable Mask */
#define MCLK_APBDMASK_SERCOM6(value)          (MCLK_APBDMASK_SERCOM6_Msk & (_UINT32_(value) << MCLK_APBDMASK_SERCOM6_Pos)) /* Assignment of value for SERCOM6 in the MCLK_APBDMASK register */
#define MCLK_APBDMASK_SERCOM7_Pos             _UINT32_(1)                                          /* (MCLK_APBDMASK) SERCOM7 APB Clock Enable Position */
#define MCLK_APBDMASK_SERCOM7_Msk             (_UINT32_(0x1) << MCLK_APBDMASK_SERCOM7_Pos)         /* (MCLK_APBDMASK) SERCOM7 APB Clock Enable Mask */
#define MCLK_APBDMASK_SERCOM7(value)          (MCLK_APBDMASK_SERCOM7_Msk & (_UINT32_(value) << MCLK_APBDMASK_SERCOM7_Pos)) /* Assignment of value for SERCOM7 in the MCLK_APBDMASK register */
#define MCLK_APBDMASK_TC5_Pos                 _UINT32_(2)                                          /* (MCLK_APBDMASK) TC5 APB Clock Enable Position */
#define MCLK_APBDMASK_TC5_Msk                 (_UINT32_(0x1) << MCLK_APBDMASK_TC5_Pos)             /* (MCLK_APBDMASK) TC5 APB Clock Enable Mask */
#define MCLK_APBDMASK_TC5(value)              (MCLK_APBDMASK_TC5_Msk & (_UINT32_(value) << MCLK_APBDMASK_TC5_Pos)) /* Assignment of value for TC5 in the MCLK_APBDMASK register */
#define MCLK_APBDMASK_TC6_Pos                 _UINT32_(3)                                          /* (MCLK_APBDMASK) TC6 APB Clock Enable Position */
#define MCLK_APBDMASK_TC6_Msk                 (_UINT32_(0x1) << MCLK_APBDMASK_TC6_Pos)             /* (MCLK_APBDMASK) TC6 APB Clock Enable Mask */
#define MCLK_APBDMASK_TC6(value)              (MCLK_APBDMASK_TC6_Msk & (_UINT32_(value) << MCLK_APBDMASK_TC6_Pos)) /* Assignment of value for TC6 in the MCLK_APBDMASK register */
#define MCLK_APBDMASK_TC7_Pos                 _UINT32_(4)                                          /* (MCLK_APBDMASK) TC7 APB Clock Enable Position */
#define MCLK_APBDMASK_TC7_Msk                 (_UINT32_(0x1) << MCLK_APBDMASK_TC7_Pos)             /* (MCLK_APBDMASK) TC7 APB Clock Enable Mask */
#define MCLK_APBDMASK_TC7(value)              (MCLK_APBDMASK_TC7_Msk & (_UINT32_(value) << MCLK_APBDMASK_TC7_Pos)) /* Assignment of value for TC7 in the MCLK_APBDMASK register */
#define MCLK_APBDMASK_Msk                     _UINT32_(0x0000001F)                                 /* (MCLK_APBDMASK) Register Mask  */

#define MCLK_APBDMASK_SERCOM_Pos              _UINT32_(0)                                          /* (MCLK_APBDMASK Position) SERCOM6 APB Clock Enable */
#define MCLK_APBDMASK_SERCOM_Msk              (_UINT32_(0x3) << MCLK_APBDMASK_SERCOM_Pos)          /* (MCLK_APBDMASK Mask) SERCOM */
#define MCLK_APBDMASK_SERCOM(value)           (MCLK_APBDMASK_SERCOM_Msk & (_UINT32_(value) << MCLK_APBDMASK_SERCOM_Pos)) 
#define MCLK_APBDMASK_TC_Pos                  _UINT32_(2)                                          /* (MCLK_APBDMASK Position) TC7 APB Clock Enable */
#define MCLK_APBDMASK_TC_Msk                  (_UINT32_(0x7) << MCLK_APBDMASK_TC_Pos)              /* (MCLK_APBDMASK Mask) TC */
#define MCLK_APBDMASK_TC(value)               (MCLK_APBDMASK_TC_Msk & (_UINT32_(value) << MCLK_APBDMASK_TC_Pos)) 

/* MCLK register offsets definitions */
#define MCLK_INTENCLR_REG_OFST         _UINT32_(0x01)      /* (MCLK_INTENCLR) Interrupt Enable Clear Offset */
#define MCLK_INTENSET_REG_OFST         _UINT32_(0x02)      /* (MCLK_INTENSET) Interrupt Enable Set Offset */
#define MCLK_INTFLAG_REG_OFST          _UINT32_(0x03)      /* (MCLK_INTFLAG) Interrupt Flag Status and Clear Offset */
#define MCLK_CPUDIV_REG_OFST           _UINT32_(0x04)      /* (MCLK_CPUDIV) CPU Clock Division Offset */
#define MCLK_AHBMASK_REG_OFST          _UINT32_(0x10)      /* (MCLK_AHBMASK) AHB Mask Offset */
#define MCLK_APBAMASK_REG_OFST         _UINT32_(0x14)      /* (MCLK_APBAMASK) APBA Mask Offset */
#define MCLK_APBBMASK_REG_OFST         _UINT32_(0x18)      /* (MCLK_APBBMASK) APBB Mask Offset */
#define MCLK_APBCMASK_REG_OFST         _UINT32_(0x1C)      /* (MCLK_APBCMASK) APBC Mask Offset */
#define MCLK_APBDMASK_REG_OFST         _UINT32_(0x20)      /* (MCLK_APBDMASK) APBD Mask Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* MCLK register API structure */
typedef struct
{  /* Main Clock */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint8_t                        MCLK_INTENCLR;      /* Offset: 0x01 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        MCLK_INTENSET;      /* Offset: 0x02 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        MCLK_INTFLAG;       /* Offset: 0x03 (R/W  8) Interrupt Flag Status and Clear */
  __IO  uint8_t                        MCLK_CPUDIV;        /* Offset: 0x04 (R/W  8) CPU Clock Division */
  __I   uint8_t                        Reserved2[0x0B];
  __IO  uint32_t                       MCLK_AHBMASK;       /* Offset: 0x10 (R/W  32) AHB Mask */
  __IO  uint32_t                       MCLK_APBAMASK;      /* Offset: 0x14 (R/W  32) APBA Mask */
  __IO  uint32_t                       MCLK_APBBMASK;      /* Offset: 0x18 (R/W  32) APBB Mask */
  __IO  uint32_t                       MCLK_APBCMASK;      /* Offset: 0x1C (R/W  32) APBC Mask */
  __IO  uint32_t                       MCLK_APBDMASK;      /* Offset: 0x20 (R/W  32) APBD Mask */
} mclk_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_MCLK_COMPONENT_H_ */
