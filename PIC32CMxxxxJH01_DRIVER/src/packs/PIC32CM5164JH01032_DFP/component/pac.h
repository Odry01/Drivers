/*
 * Component description for PAC
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
#ifndef _PIC32CMJH01_PAC_COMPONENT_H_
#define _PIC32CMJH01_PAC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR PAC                       */
/* ************************************************************************** */

/* -------- PAC_WRCTRL : (PAC Offset: 0x00) (R/W 32) Write control -------- */
#define PAC_WRCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (PAC_WRCTRL) Write control  Reset Value */

#define PAC_WRCTRL_PERID_Pos                  _UINT32_(0)                                          /* (PAC_WRCTRL) Peripheral identifier Position */
#define PAC_WRCTRL_PERID_Msk                  (_UINT32_(0xFFFF) << PAC_WRCTRL_PERID_Pos)           /* (PAC_WRCTRL) Peripheral identifier Mask */
#define PAC_WRCTRL_PERID(value)               (PAC_WRCTRL_PERID_Msk & (_UINT32_(value) << PAC_WRCTRL_PERID_Pos)) /* Assignment of value for PERID in the PAC_WRCTRL register */
#define PAC_WRCTRL_KEY_Pos                    _UINT32_(16)                                         /* (PAC_WRCTRL) Peripheral access control key Position */
#define PAC_WRCTRL_KEY_Msk                    (_UINT32_(0xFF) << PAC_WRCTRL_KEY_Pos)               /* (PAC_WRCTRL) Peripheral access control key Mask */
#define PAC_WRCTRL_KEY(value)                 (PAC_WRCTRL_KEY_Msk & (_UINT32_(value) << PAC_WRCTRL_KEY_Pos)) /* Assignment of value for KEY in the PAC_WRCTRL register */
#define   PAC_WRCTRL_KEY_OFF_Val              _UINT32_(0x0)                                        /* (PAC_WRCTRL) No action  */
#define   PAC_WRCTRL_KEY_CLR_Val              _UINT32_(0x1)                                        /* (PAC_WRCTRL) Clear protection  */
#define   PAC_WRCTRL_KEY_SET_Val              _UINT32_(0x2)                                        /* (PAC_WRCTRL) Set protection  */
#define   PAC_WRCTRL_KEY_SETLCK_Val           _UINT32_(0x3)                                        /* (PAC_WRCTRL) Set and lock protection  */
#define PAC_WRCTRL_KEY_OFF                    (PAC_WRCTRL_KEY_OFF_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) No action Position */
#define PAC_WRCTRL_KEY_CLR                    (PAC_WRCTRL_KEY_CLR_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Clear protection Position */
#define PAC_WRCTRL_KEY_SET                    (PAC_WRCTRL_KEY_SET_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Set protection Position */
#define PAC_WRCTRL_KEY_SETLCK                 (PAC_WRCTRL_KEY_SETLCK_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set and lock protection Position */
#define PAC_WRCTRL_Msk                        _UINT32_(0x00FFFFFF)                                 /* (PAC_WRCTRL) Register Mask  */


/* -------- PAC_EVCTRL : (PAC Offset: 0x04) (R/W 8) Event control -------- */
#define PAC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (PAC_EVCTRL) Event control  Reset Value */

#define PAC_EVCTRL_ERREO_Pos                  _UINT8_(0)                                           /* (PAC_EVCTRL) Peripheral acess error event output Position */
#define PAC_EVCTRL_ERREO_Msk                  (_UINT8_(0x1) << PAC_EVCTRL_ERREO_Pos)               /* (PAC_EVCTRL) Peripheral acess error event output Mask */
#define PAC_EVCTRL_ERREO(value)               (PAC_EVCTRL_ERREO_Msk & (_UINT8_(value) << PAC_EVCTRL_ERREO_Pos)) /* Assignment of value for ERREO in the PAC_EVCTRL register */
#define PAC_EVCTRL_Msk                        _UINT8_(0x01)                                        /* (PAC_EVCTRL) Register Mask  */


/* -------- PAC_INTENCLR : (PAC Offset: 0x08) (R/W 8) Interrupt enable clear -------- */
#define PAC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENCLR) Interrupt enable clear  Reset Value */

#define PAC_INTENCLR_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENCLR) Peripheral access error interrupt disable Position */
#define PAC_INTENCLR_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENCLR_ERR_Pos)               /* (PAC_INTENCLR) Peripheral access error interrupt disable Mask */
#define PAC_INTENCLR_ERR(value)               (PAC_INTENCLR_ERR_Msk & (_UINT8_(value) << PAC_INTENCLR_ERR_Pos)) /* Assignment of value for ERR in the PAC_INTENCLR register */
#define PAC_INTENCLR_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENCLR) Register Mask  */


/* -------- PAC_INTENSET : (PAC Offset: 0x09) (R/W 8) Interrupt enable set -------- */
#define PAC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENSET) Interrupt enable set  Reset Value */

#define PAC_INTENSET_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENSET) Peripheral access error interrupt enable Position */
#define PAC_INTENSET_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENSET_ERR_Pos)               /* (PAC_INTENSET) Peripheral access error interrupt enable Mask */
#define PAC_INTENSET_ERR(value)               (PAC_INTENSET_ERR_Msk & (_UINT8_(value) << PAC_INTENSET_ERR_Pos)) /* Assignment of value for ERR in the PAC_INTENSET register */
#define PAC_INTENSET_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENSET) Register Mask  */


/* -------- PAC_INTFLAGAHB : (PAC Offset: 0x10) (R/W 32) Bridge interrupt flag status -------- */
#define PAC_INTFLAGAHB_RESETVALUE             _UINT32_(0x00)                                       /*  (PAC_INTFLAGAHB) Bridge interrupt flag status  Reset Value */

#define PAC_INTFLAGAHB_FLASH_Pos              _UINT32_(0)                                          /* (PAC_INTFLAGAHB) FLASH Position */
#define PAC_INTFLAGAHB_FLASH_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_FLASH_Pos)          /* (PAC_INTFLAGAHB) FLASH Mask */
#define PAC_INTFLAGAHB_FLASH(value)           (PAC_INTFLAGAHB_FLASH_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_FLASH_Pos)) /* Assignment of value for FLASH in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HSRAMCM0P_Pos          _UINT32_(1)                                          /* (PAC_INTFLAGAHB) SRAM CPU Position */
#define PAC_INTFLAGAHB_HSRAMCM0P_Msk          (_UINT32_(0x1) << PAC_INTFLAGAHB_HSRAMCM0P_Pos)      /* (PAC_INTFLAGAHB) SRAM CPU Mask */
#define PAC_INTFLAGAHB_HSRAMCM0P(value)       (PAC_INTFLAGAHB_HSRAMCM0P_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HSRAMCM0P_Pos)) /* Assignment of value for HSRAMCM0P in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HSRAMDSU_Pos           _UINT32_(2)                                          /* (PAC_INTFLAGAHB) SRAM DSU Position */
#define PAC_INTFLAGAHB_HSRAMDSU_Msk           (_UINT32_(0x1) << PAC_INTFLAGAHB_HSRAMDSU_Pos)       /* (PAC_INTFLAGAHB) SRAM DSU Mask */
#define PAC_INTFLAGAHB_HSRAMDSU(value)        (PAC_INTFLAGAHB_HSRAMDSU_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HSRAMDSU_Pos)) /* Assignment of value for HSRAMDSU in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBB_Pos               _UINT32_(3)                                          /* (PAC_INTFLAGAHB) HPB1 Position */
#define PAC_INTFLAGAHB_APBB_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBB_Pos)           /* (PAC_INTFLAGAHB) HPB1 Mask */
#define PAC_INTFLAGAHB_APBB(value)            (PAC_INTFLAGAHB_APBB_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBB_Pos)) /* Assignment of value for APBB in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBA_Pos               _UINT32_(4)                                          /* (PAC_INTFLAGAHB) HPB0 Position */
#define PAC_INTFLAGAHB_APBA_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBA_Pos)           /* (PAC_INTFLAGAHB) HPB0 Mask */
#define PAC_INTFLAGAHB_APBA(value)            (PAC_INTFLAGAHB_APBA_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBA_Pos)) /* Assignment of value for APBA in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBC_Pos               _UINT32_(5)                                          /* (PAC_INTFLAGAHB) HPB2 Position */
#define PAC_INTFLAGAHB_APBC_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBC_Pos)           /* (PAC_INTFLAGAHB) HPB2 Mask */
#define PAC_INTFLAGAHB_APBC(value)            (PAC_INTFLAGAHB_APBC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBC_Pos)) /* Assignment of value for APBC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_LPRAMDMAC_Pos          _UINT32_(6)                                          /* (PAC_INTFLAGAHB) SRAM DMAC Position */
#define PAC_INTFLAGAHB_LPRAMDMAC_Msk          (_UINT32_(0x1) << PAC_INTFLAGAHB_LPRAMDMAC_Pos)      /* (PAC_INTFLAGAHB) SRAM DMAC Mask */
#define PAC_INTFLAGAHB_LPRAMDMAC(value)       (PAC_INTFLAGAHB_LPRAMDMAC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_LPRAMDMAC_Pos)) /* Assignment of value for LPRAMDMAC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_DIVAS_Pos              _UINT32_(7)                                          /* (PAC_INTFLAGAHB) DIVAS Position */
#define PAC_INTFLAGAHB_DIVAS_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_DIVAS_Pos)          /* (PAC_INTFLAGAHB) DIVAS Mask */
#define PAC_INTFLAGAHB_DIVAS(value)           (PAC_INTFLAGAHB_DIVAS_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_DIVAS_Pos)) /* Assignment of value for DIVAS in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBD_Pos               _UINT32_(8)                                          /* (PAC_INTFLAGAHB) HPB3 Position */
#define PAC_INTFLAGAHB_APBD_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBD_Pos)           /* (PAC_INTFLAGAHB) HPB3 Mask */
#define PAC_INTFLAGAHB_APBD(value)            (PAC_INTFLAGAHB_APBD_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBD_Pos)) /* Assignment of value for APBD in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HMCRAMCHS_ICM_Pos      _UINT32_(9)                                          /* (PAC_INTFLAGAHB) SRAM ICM Position */
#define PAC_INTFLAGAHB_HMCRAMCHS_ICM_Msk      (_UINT32_(0x1) << PAC_INTFLAGAHB_HMCRAMCHS_ICM_Pos)  /* (PAC_INTFLAGAHB) SRAM ICM Mask */
#define PAC_INTFLAGAHB_HMCRAMCHS_ICM(value)   (PAC_INTFLAGAHB_HMCRAMCHS_ICM_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HMCRAMCHS_ICM_Pos)) /* Assignment of value for HMCRAMCHS_ICM in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_Msk                    _UINT32_(0x000003FF)                                 /* (PAC_INTFLAGAHB) Register Mask  */


/* -------- PAC_INTFLAGA : (PAC Offset: 0x14) (R/W 32) Peripheral interrupt flag status - Bridge A -------- */
#define PAC_INTFLAGA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A  Reset Value */

#define PAC_INTFLAGA_PAC_Pos                  _UINT32_(0)                                          /* (PAC_INTFLAGA) PAC Position */
#define PAC_INTFLAGA_PAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_PAC_Pos)              /* (PAC_INTFLAGA) PAC Mask */
#define PAC_INTFLAGA_PAC(value)               (PAC_INTFLAGA_PAC_Msk & (_UINT32_(value) << PAC_INTFLAGA_PAC_Pos)) /* Assignment of value for PAC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PM_Pos                   _UINT32_(1)                                          /* (PAC_INTFLAGA) PM Position */
#define PAC_INTFLAGA_PM_Msk                   (_UINT32_(0x1) << PAC_INTFLAGA_PM_Pos)               /* (PAC_INTFLAGA) PM Mask */
#define PAC_INTFLAGA_PM(value)                (PAC_INTFLAGA_PM_Msk & (_UINT32_(value) << PAC_INTFLAGA_PM_Pos)) /* Assignment of value for PM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_MCLK_Pos                 _UINT32_(2)                                          /* (PAC_INTFLAGA) MCLK Position */
#define PAC_INTFLAGA_MCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_MCLK_Pos)             /* (PAC_INTFLAGA) MCLK Mask */
#define PAC_INTFLAGA_MCLK(value)              (PAC_INTFLAGA_MCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_MCLK_Pos)) /* Assignment of value for MCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RSTC_Pos                 _UINT32_(3)                                          /* (PAC_INTFLAGA) RSTC Position */
#define PAC_INTFLAGA_RSTC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_RSTC_Pos)             /* (PAC_INTFLAGA) RSTC Mask */
#define PAC_INTFLAGA_RSTC(value)              (PAC_INTFLAGA_RSTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RSTC_Pos)) /* Assignment of value for RSTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSCCTRL_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGA) OSCCTRL Position */
#define PAC_INTFLAGA_OSCCTRL_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_OSCCTRL_Pos)          /* (PAC_INTFLAGA) OSCCTRL Mask */
#define PAC_INTFLAGA_OSCCTRL(value)           (PAC_INTFLAGA_OSCCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSCCTRL_Pos)) /* Assignment of value for OSCCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSC32KCTRL_Pos           _UINT32_(5)                                          /* (PAC_INTFLAGA) OSC32KCTRL Position */
#define PAC_INTFLAGA_OSC32KCTRL_Msk           (_UINT32_(0x1) << PAC_INTFLAGA_OSC32KCTRL_Pos)       /* (PAC_INTFLAGA) OSC32KCTRL Mask */
#define PAC_INTFLAGA_OSC32KCTRL(value)        (PAC_INTFLAGA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSC32KCTRL_Pos)) /* Assignment of value for OSC32KCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SUPC_Pos                 _UINT32_(6)                                          /* (PAC_INTFLAGA) SUPC Position */
#define PAC_INTFLAGA_SUPC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_SUPC_Pos)             /* (PAC_INTFLAGA) SUPC Mask */
#define PAC_INTFLAGA_SUPC(value)              (PAC_INTFLAGA_SUPC_Msk & (_UINT32_(value) << PAC_INTFLAGA_SUPC_Pos)) /* Assignment of value for SUPC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_GCLK_Pos                 _UINT32_(7)                                          /* (PAC_INTFLAGA) GCLK Position */
#define PAC_INTFLAGA_GCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_GCLK_Pos)             /* (PAC_INTFLAGA) GCLK Mask */
#define PAC_INTFLAGA_GCLK(value)              (PAC_INTFLAGA_GCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_GCLK_Pos)) /* Assignment of value for GCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_WDT_Pos                  _UINT32_(8)                                          /* (PAC_INTFLAGA) WDT Position */
#define PAC_INTFLAGA_WDT_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_WDT_Pos)              /* (PAC_INTFLAGA) WDT Mask */
#define PAC_INTFLAGA_WDT(value)               (PAC_INTFLAGA_WDT_Msk & (_UINT32_(value) << PAC_INTFLAGA_WDT_Pos)) /* Assignment of value for WDT in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RTC_Pos                  _UINT32_(9)                                          /* (PAC_INTFLAGA) RTC Position */
#define PAC_INTFLAGA_RTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_RTC_Pos)              /* (PAC_INTFLAGA) RTC Mask */
#define PAC_INTFLAGA_RTC(value)               (PAC_INTFLAGA_RTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RTC_Pos)) /* Assignment of value for RTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_EIC_Pos                  _UINT32_(10)                                         /* (PAC_INTFLAGA) EIC Position */
#define PAC_INTFLAGA_EIC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_EIC_Pos)              /* (PAC_INTFLAGA) EIC Mask */
#define PAC_INTFLAGA_EIC(value)               (PAC_INTFLAGA_EIC_Msk & (_UINT32_(value) << PAC_INTFLAGA_EIC_Pos)) /* Assignment of value for EIC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FREQM_Pos                _UINT32_(11)                                         /* (PAC_INTFLAGA) FREQM Position */
#define PAC_INTFLAGA_FREQM_Msk                (_UINT32_(0x1) << PAC_INTFLAGA_FREQM_Pos)            /* (PAC_INTFLAGA) FREQM Mask */
#define PAC_INTFLAGA_FREQM(value)             (PAC_INTFLAGA_FREQM_Msk & (_UINT32_(value) << PAC_INTFLAGA_FREQM_Pos)) /* Assignment of value for FREQM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_MCRAMC_Pos               _UINT32_(12)                                         /* (PAC_INTFLAGA) MCRAMC Position */
#define PAC_INTFLAGA_MCRAMC_Msk               (_UINT32_(0x1) << PAC_INTFLAGA_MCRAMC_Pos)           /* (PAC_INTFLAGA) MCRAMC Mask */
#define PAC_INTFLAGA_MCRAMC(value)            (PAC_INTFLAGA_MCRAMC_Msk & (_UINT32_(value) << PAC_INTFLAGA_MCRAMC_Pos)) /* Assignment of value for MCRAMC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_Msk                      _UINT32_(0x00001FFF)                                 /* (PAC_INTFLAGA) Register Mask  */


/* -------- PAC_INTFLAGB : (PAC Offset: 0x18) (R/W 32) Peripheral interrupt flag status - Bridge B -------- */
#define PAC_INTFLAGB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B  Reset Value */

#define PAC_INTFLAGB_PORT_Pos                 _UINT32_(0)                                          /* (PAC_INTFLAGB) PORT Position */
#define PAC_INTFLAGB_PORT_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_PORT_Pos)             /* (PAC_INTFLAGB) PORT Mask */
#define PAC_INTFLAGB_PORT(value)              (PAC_INTFLAGB_PORT_Msk & (_UINT32_(value) << PAC_INTFLAGB_PORT_Pos)) /* Assignment of value for PORT in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_DSU_Pos                  _UINT32_(1)                                          /* (PAC_INTFLAGB) DSU Position */
#define PAC_INTFLAGB_DSU_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_DSU_Pos)              /* (PAC_INTFLAGB) DSU Mask */
#define PAC_INTFLAGB_DSU(value)               (PAC_INTFLAGB_DSU_Msk & (_UINT32_(value) << PAC_INTFLAGB_DSU_Pos)) /* Assignment of value for DSU in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_NVMCTRL_Pos              _UINT32_(2)                                          /* (PAC_INTFLAGB) NVMCTRL Position */
#define PAC_INTFLAGB_NVMCTRL_Msk              (_UINT32_(0x1) << PAC_INTFLAGB_NVMCTRL_Pos)          /* (PAC_INTFLAGB) NVMCTRL Mask */
#define PAC_INTFLAGB_NVMCTRL(value)           (PAC_INTFLAGB_NVMCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGB_NVMCTRL_Pos)) /* Assignment of value for NVMCTRL in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_DMAC_Pos                 _UINT32_(3)                                          /* (PAC_INTFLAGB) DMAC Position */
#define PAC_INTFLAGB_DMAC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_DMAC_Pos)             /* (PAC_INTFLAGB) DMAC Mask */
#define PAC_INTFLAGB_DMAC(value)              (PAC_INTFLAGB_DMAC_Msk & (_UINT32_(value) << PAC_INTFLAGB_DMAC_Pos)) /* Assignment of value for DMAC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_MTB_Pos                  _UINT32_(4)                                          /* (PAC_INTFLAGB) MTB Position */
#define PAC_INTFLAGB_MTB_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_MTB_Pos)              /* (PAC_INTFLAGB) MTB Mask */
#define PAC_INTFLAGB_MTB(value)               (PAC_INTFLAGB_MTB_Msk & (_UINT32_(value) << PAC_INTFLAGB_MTB_Pos)) /* Assignment of value for MTB in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_HMATRIXHS_Pos            _UINT32_(5)                                          /* (PAC_INTFLAGB) HMATRIXHS Position */
#define PAC_INTFLAGB_HMATRIXHS_Msk            (_UINT32_(0x1) << PAC_INTFLAGB_HMATRIXHS_Pos)        /* (PAC_INTFLAGB) HMATRIXHS Mask */
#define PAC_INTFLAGB_HMATRIXHS(value)         (PAC_INTFLAGB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_INTFLAGB_HMATRIXHS_Pos)) /* Assignment of value for HMATRIXHS in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_Msk                      _UINT32_(0x0000003F)                                 /* (PAC_INTFLAGB) Register Mask  */


/* -------- PAC_INTFLAGC : (PAC Offset: 0x1C) (R/W 32) Peripheral interrupt flag status - Bridge C -------- */
#define PAC_INTFLAGC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C  Reset Value */

#define PAC_INTFLAGC_EVSYS_Pos                _UINT32_(0)                                          /* (PAC_INTFLAGC) EVSYS Position */
#define PAC_INTFLAGC_EVSYS_Msk                (_UINT32_(0x1) << PAC_INTFLAGC_EVSYS_Pos)            /* (PAC_INTFLAGC) EVSYS Mask */
#define PAC_INTFLAGC_EVSYS(value)             (PAC_INTFLAGC_EVSYS_Msk & (_UINT32_(value) << PAC_INTFLAGC_EVSYS_Pos)) /* Assignment of value for EVSYS in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM0_Pos              _UINT32_(1)                                          /* (PAC_INTFLAGC) SERCOM0 Position */
#define PAC_INTFLAGC_SERCOM0_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM0_Pos)          /* (PAC_INTFLAGC) SERCOM0 Mask */
#define PAC_INTFLAGC_SERCOM0(value)           (PAC_INTFLAGC_SERCOM0_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM0_Pos)) /* Assignment of value for SERCOM0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM1_Pos              _UINT32_(2)                                          /* (PAC_INTFLAGC) SERCOM1 Position */
#define PAC_INTFLAGC_SERCOM1_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM1_Pos)          /* (PAC_INTFLAGC) SERCOM1 Mask */
#define PAC_INTFLAGC_SERCOM1(value)           (PAC_INTFLAGC_SERCOM1_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM1_Pos)) /* Assignment of value for SERCOM1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM2_Pos              _UINT32_(3)                                          /* (PAC_INTFLAGC) SERCOM2 Position */
#define PAC_INTFLAGC_SERCOM2_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM2_Pos)          /* (PAC_INTFLAGC) SERCOM2 Mask */
#define PAC_INTFLAGC_SERCOM2(value)           (PAC_INTFLAGC_SERCOM2_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM2_Pos)) /* Assignment of value for SERCOM2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM3_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGC) SERCOM3 Position */
#define PAC_INTFLAGC_SERCOM3_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM3_Pos)          /* (PAC_INTFLAGC) SERCOM3 Mask */
#define PAC_INTFLAGC_SERCOM3(value)           (PAC_INTFLAGC_SERCOM3_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM3_Pos)) /* Assignment of value for SERCOM3 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM4_Pos              _UINT32_(5)                                          /* (PAC_INTFLAGC) SERCOM4 Position */
#define PAC_INTFLAGC_SERCOM4_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM4_Pos)          /* (PAC_INTFLAGC) SERCOM4 Mask */
#define PAC_INTFLAGC_SERCOM4(value)           (PAC_INTFLAGC_SERCOM4_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM4_Pos)) /* Assignment of value for SERCOM4 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM5_Pos              _UINT32_(6)                                          /* (PAC_INTFLAGC) SERCOM5 Position */
#define PAC_INTFLAGC_SERCOM5_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM5_Pos)          /* (PAC_INTFLAGC) SERCOM5 Mask */
#define PAC_INTFLAGC_SERCOM5(value)           (PAC_INTFLAGC_SERCOM5_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM5_Pos)) /* Assignment of value for SERCOM5 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_CAN0_Pos                 _UINT32_(7)                                          /* (PAC_INTFLAGC) CAN0 Position */
#define PAC_INTFLAGC_CAN0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_CAN0_Pos)             /* (PAC_INTFLAGC) CAN0 Mask */
#define PAC_INTFLAGC_CAN0(value)              (PAC_INTFLAGC_CAN0_Msk & (_UINT32_(value) << PAC_INTFLAGC_CAN0_Pos)) /* Assignment of value for CAN0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_CAN1_Pos                 _UINT32_(8)                                          /* (PAC_INTFLAGC) CAN1 Position */
#define PAC_INTFLAGC_CAN1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_CAN1_Pos)             /* (PAC_INTFLAGC) CAN1 Mask */
#define PAC_INTFLAGC_CAN1(value)              (PAC_INTFLAGC_CAN1_Msk & (_UINT32_(value) << PAC_INTFLAGC_CAN1_Pos)) /* Assignment of value for CAN1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC0_Pos                 _UINT32_(9)                                          /* (PAC_INTFLAGC) TCC0 Position */
#define PAC_INTFLAGC_TCC0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC0_Pos)             /* (PAC_INTFLAGC) TCC0 Mask */
#define PAC_INTFLAGC_TCC0(value)              (PAC_INTFLAGC_TCC0_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC0_Pos)) /* Assignment of value for TCC0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC1_Pos                 _UINT32_(10)                                         /* (PAC_INTFLAGC) TCC1 Position */
#define PAC_INTFLAGC_TCC1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC1_Pos)             /* (PAC_INTFLAGC) TCC1 Mask */
#define PAC_INTFLAGC_TCC1(value)              (PAC_INTFLAGC_TCC1_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC1_Pos)) /* Assignment of value for TCC1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC2_Pos                 _UINT32_(11)                                         /* (PAC_INTFLAGC) TCC2 Position */
#define PAC_INTFLAGC_TCC2_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC2_Pos)             /* (PAC_INTFLAGC) TCC2 Mask */
#define PAC_INTFLAGC_TCC2(value)              (PAC_INTFLAGC_TCC2_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC2_Pos)) /* Assignment of value for TCC2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC0_Pos                  _UINT32_(12)                                         /* (PAC_INTFLAGC) TC0 Position */
#define PAC_INTFLAGC_TC0_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC0_Pos)              /* (PAC_INTFLAGC) TC0 Mask */
#define PAC_INTFLAGC_TC0(value)               (PAC_INTFLAGC_TC0_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC0_Pos)) /* Assignment of value for TC0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC1_Pos                  _UINT32_(13)                                         /* (PAC_INTFLAGC) TC1 Position */
#define PAC_INTFLAGC_TC1_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC1_Pos)              /* (PAC_INTFLAGC) TC1 Mask */
#define PAC_INTFLAGC_TC1(value)               (PAC_INTFLAGC_TC1_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC1_Pos)) /* Assignment of value for TC1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC2_Pos                  _UINT32_(14)                                         /* (PAC_INTFLAGC) TC2 Position */
#define PAC_INTFLAGC_TC2_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC2_Pos)              /* (PAC_INTFLAGC) TC2 Mask */
#define PAC_INTFLAGC_TC2(value)               (PAC_INTFLAGC_TC2_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC2_Pos)) /* Assignment of value for TC2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC3_Pos                  _UINT32_(15)                                         /* (PAC_INTFLAGC) TC3 Position */
#define PAC_INTFLAGC_TC3_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC3_Pos)              /* (PAC_INTFLAGC) TC3 Mask */
#define PAC_INTFLAGC_TC3(value)               (PAC_INTFLAGC_TC3_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC3_Pos)) /* Assignment of value for TC3 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC4_Pos                  _UINT32_(16)                                         /* (PAC_INTFLAGC) TC4 Position */
#define PAC_INTFLAGC_TC4_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC4_Pos)              /* (PAC_INTFLAGC) TC4 Mask */
#define PAC_INTFLAGC_TC4(value)               (PAC_INTFLAGC_TC4_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC4_Pos)) /* Assignment of value for TC4 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_ADC0_Pos                 _UINT32_(17)                                         /* (PAC_INTFLAGC) ADC0 Position */
#define PAC_INTFLAGC_ADC0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_ADC0_Pos)             /* (PAC_INTFLAGC) ADC0 Mask */
#define PAC_INTFLAGC_ADC0(value)              (PAC_INTFLAGC_ADC0_Msk & (_UINT32_(value) << PAC_INTFLAGC_ADC0_Pos)) /* Assignment of value for ADC0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_ADC1_Pos                 _UINT32_(18)                                         /* (PAC_INTFLAGC) ADC1 Position */
#define PAC_INTFLAGC_ADC1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_ADC1_Pos)             /* (PAC_INTFLAGC) ADC1 Mask */
#define PAC_INTFLAGC_ADC1(value)              (PAC_INTFLAGC_ADC1_Msk & (_UINT32_(value) << PAC_INTFLAGC_ADC1_Pos)) /* Assignment of value for ADC1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_AC_Pos                   _UINT32_(19)                                         /* (PAC_INTFLAGC) AC Position */
#define PAC_INTFLAGC_AC_Msk                   (_UINT32_(0x1) << PAC_INTFLAGC_AC_Pos)               /* (PAC_INTFLAGC) AC Mask */
#define PAC_INTFLAGC_AC(value)                (PAC_INTFLAGC_AC_Msk & (_UINT32_(value) << PAC_INTFLAGC_AC_Pos)) /* Assignment of value for AC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_DAC_Pos                  _UINT32_(20)                                         /* (PAC_INTFLAGC) DAC Position */
#define PAC_INTFLAGC_DAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_DAC_Pos)              /* (PAC_INTFLAGC) DAC Mask */
#define PAC_INTFLAGC_DAC(value)               (PAC_INTFLAGC_DAC_Msk & (_UINT32_(value) << PAC_INTFLAGC_DAC_Pos)) /* Assignment of value for DAC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_PTC_Pos                  _UINT32_(21)                                         /* (PAC_INTFLAGC) PTC Position */
#define PAC_INTFLAGC_PTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_PTC_Pos)              /* (PAC_INTFLAGC) PTC Mask */
#define PAC_INTFLAGC_PTC(value)               (PAC_INTFLAGC_PTC_Msk & (_UINT32_(value) << PAC_INTFLAGC_PTC_Pos)) /* Assignment of value for PTC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_CCL_Pos                  _UINT32_(22)                                         /* (PAC_INTFLAGC) CCL Position */
#define PAC_INTFLAGC_CCL_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_CCL_Pos)              /* (PAC_INTFLAGC) CCL Mask */
#define PAC_INTFLAGC_CCL(value)               (PAC_INTFLAGC_CCL_Msk & (_UINT32_(value) << PAC_INTFLAGC_CCL_Pos)) /* Assignment of value for CCL in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_ICM_Pos                  _UINT32_(25)                                         /* (PAC_INTFLAGC) ICM Position */
#define PAC_INTFLAGC_ICM_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_ICM_Pos)              /* (PAC_INTFLAGC) ICM Mask */
#define PAC_INTFLAGC_ICM(value)               (PAC_INTFLAGC_ICM_Msk & (_UINT32_(value) << PAC_INTFLAGC_ICM_Pos)) /* Assignment of value for ICM in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_PDEC_Pos                 _UINT32_(26)                                         /* (PAC_INTFLAGC) PDEC Position */
#define PAC_INTFLAGC_PDEC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_PDEC_Pos)             /* (PAC_INTFLAGC) PDEC Mask */
#define PAC_INTFLAGC_PDEC(value)              (PAC_INTFLAGC_PDEC_Msk & (_UINT32_(value) << PAC_INTFLAGC_PDEC_Pos)) /* Assignment of value for PDEC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SMBIST_Pos               _UINT32_(27)                                         /* (PAC_INTFLAGC) SMBIST Position */
#define PAC_INTFLAGC_SMBIST_Msk               (_UINT32_(0x1) << PAC_INTFLAGC_SMBIST_Pos)           /* (PAC_INTFLAGC) SMBIST Mask */
#define PAC_INTFLAGC_SMBIST(value)            (PAC_INTFLAGC_SMBIST_Msk & (_UINT32_(value) << PAC_INTFLAGC_SMBIST_Pos)) /* Assignment of value for SMBIST in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_Msk                      _UINT32_(0x0E7FFFFF)                                 /* (PAC_INTFLAGC) Register Mask  */

#define PAC_INTFLAGC_SERCOM_Pos               _UINT32_(1)                                          /* (PAC_INTFLAGC Position) SERCOMx */
#define PAC_INTFLAGC_SERCOM_Msk               (_UINT32_(0x3F) << PAC_INTFLAGC_SERCOM_Pos)          /* (PAC_INTFLAGC Mask) SERCOM */
#define PAC_INTFLAGC_SERCOM(value)            (PAC_INTFLAGC_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM_Pos)) 
#define PAC_INTFLAGC_CAN_Pos                  _UINT32_(7)                                          /* (PAC_INTFLAGC Position) CANx */
#define PAC_INTFLAGC_CAN_Msk                  (_UINT32_(0x3) << PAC_INTFLAGC_CAN_Pos)              /* (PAC_INTFLAGC Mask) CAN */
#define PAC_INTFLAGC_CAN(value)               (PAC_INTFLAGC_CAN_Msk & (_UINT32_(value) << PAC_INTFLAGC_CAN_Pos)) 
#define PAC_INTFLAGC_TCC_Pos                  _UINT32_(9)                                          /* (PAC_INTFLAGC Position) TCCx */
#define PAC_INTFLAGC_TCC_Msk                  (_UINT32_(0x7) << PAC_INTFLAGC_TCC_Pos)              /* (PAC_INTFLAGC Mask) TCC */
#define PAC_INTFLAGC_TCC(value)               (PAC_INTFLAGC_TCC_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC_Pos)) 
#define PAC_INTFLAGC_TC_Pos                   _UINT32_(12)                                         /* (PAC_INTFLAGC Position) TCx */
#define PAC_INTFLAGC_TC_Msk                   (_UINT32_(0x1F) << PAC_INTFLAGC_TC_Pos)              /* (PAC_INTFLAGC Mask) TC */
#define PAC_INTFLAGC_TC(value)                (PAC_INTFLAGC_TC_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC_Pos)) 
#define PAC_INTFLAGC_ADC_Pos                  _UINT32_(17)                                         /* (PAC_INTFLAGC Position) ADCx */
#define PAC_INTFLAGC_ADC_Msk                  (_UINT32_(0x3) << PAC_INTFLAGC_ADC_Pos)              /* (PAC_INTFLAGC Mask) ADC */
#define PAC_INTFLAGC_ADC(value)               (PAC_INTFLAGC_ADC_Msk & (_UINT32_(value) << PAC_INTFLAGC_ADC_Pos)) 

/* -------- PAC_INTFLAGD : (PAC Offset: 0x20) (R/W 32) Peripheral interrupt flag status - Bridge D -------- */
#define PAC_INTFLAGD_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGD) Peripheral interrupt flag status - Bridge D  Reset Value */

#define PAC_INTFLAGD_SERCOM6_Pos              _UINT32_(0)                                          /* (PAC_INTFLAGD) SERCOM6 Position */
#define PAC_INTFLAGD_SERCOM6_Msk              (_UINT32_(0x1) << PAC_INTFLAGD_SERCOM6_Pos)          /* (PAC_INTFLAGD) SERCOM6 Mask */
#define PAC_INTFLAGD_SERCOM6(value)           (PAC_INTFLAGD_SERCOM6_Msk & (_UINT32_(value) << PAC_INTFLAGD_SERCOM6_Pos)) /* Assignment of value for SERCOM6 in the PAC_INTFLAGD register */
#define PAC_INTFLAGD_SERCOM7_Pos              _UINT32_(1)                                          /* (PAC_INTFLAGD) SERCOM7 Position */
#define PAC_INTFLAGD_SERCOM7_Msk              (_UINT32_(0x1) << PAC_INTFLAGD_SERCOM7_Pos)          /* (PAC_INTFLAGD) SERCOM7 Mask */
#define PAC_INTFLAGD_SERCOM7(value)           (PAC_INTFLAGD_SERCOM7_Msk & (_UINT32_(value) << PAC_INTFLAGD_SERCOM7_Pos)) /* Assignment of value for SERCOM7 in the PAC_INTFLAGD register */
#define PAC_INTFLAGD_TC5_Pos                  _UINT32_(2)                                          /* (PAC_INTFLAGD) TC5 Position */
#define PAC_INTFLAGD_TC5_Msk                  (_UINT32_(0x1) << PAC_INTFLAGD_TC5_Pos)              /* (PAC_INTFLAGD) TC5 Mask */
#define PAC_INTFLAGD_TC5(value)               (PAC_INTFLAGD_TC5_Msk & (_UINT32_(value) << PAC_INTFLAGD_TC5_Pos)) /* Assignment of value for TC5 in the PAC_INTFLAGD register */
#define PAC_INTFLAGD_TC6_Pos                  _UINT32_(3)                                          /* (PAC_INTFLAGD) TC6 Position */
#define PAC_INTFLAGD_TC6_Msk                  (_UINT32_(0x1) << PAC_INTFLAGD_TC6_Pos)              /* (PAC_INTFLAGD) TC6 Mask */
#define PAC_INTFLAGD_TC6(value)               (PAC_INTFLAGD_TC6_Msk & (_UINT32_(value) << PAC_INTFLAGD_TC6_Pos)) /* Assignment of value for TC6 in the PAC_INTFLAGD register */
#define PAC_INTFLAGD_TC7_Pos                  _UINT32_(4)                                          /* (PAC_INTFLAGD) TC7 Position */
#define PAC_INTFLAGD_TC7_Msk                  (_UINT32_(0x1) << PAC_INTFLAGD_TC7_Pos)              /* (PAC_INTFLAGD) TC7 Mask */
#define PAC_INTFLAGD_TC7(value)               (PAC_INTFLAGD_TC7_Msk & (_UINT32_(value) << PAC_INTFLAGD_TC7_Pos)) /* Assignment of value for TC7 in the PAC_INTFLAGD register */
#define PAC_INTFLAGD_Msk                      _UINT32_(0x0000001F)                                 /* (PAC_INTFLAGD) Register Mask  */

#define PAC_INTFLAGD_SERCOM_Pos               _UINT32_(0)                                          /* (PAC_INTFLAGD Position) SERCOM6 */
#define PAC_INTFLAGD_SERCOM_Msk               (_UINT32_(0x3) << PAC_INTFLAGD_SERCOM_Pos)           /* (PAC_INTFLAGD Mask) SERCOM */
#define PAC_INTFLAGD_SERCOM(value)            (PAC_INTFLAGD_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGD_SERCOM_Pos)) 
#define PAC_INTFLAGD_TC_Pos                   _UINT32_(2)                                          /* (PAC_INTFLAGD Position) TC7 */
#define PAC_INTFLAGD_TC_Msk                   (_UINT32_(0x7) << PAC_INTFLAGD_TC_Pos)               /* (PAC_INTFLAGD Mask) TC */
#define PAC_INTFLAGD_TC(value)                (PAC_INTFLAGD_TC_Msk & (_UINT32_(value) << PAC_INTFLAGD_TC_Pos)) 

/* -------- PAC_STATUSA : (PAC Offset: 0x34) ( R/ 32) Peripheral write protection status - Bridge A -------- */
#define PAC_STATUSA_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSA) Peripheral write protection status - Bridge A  Reset Value */

#define PAC_STATUSA_PAC_Pos                   _UINT32_(0)                                          /* (PAC_STATUSA) PAC APB Protect Enable Position */
#define PAC_STATUSA_PAC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_PAC_Pos)               /* (PAC_STATUSA) PAC APB Protect Enable Mask */
#define PAC_STATUSA_PAC(value)                (PAC_STATUSA_PAC_Msk & (_UINT32_(value) << PAC_STATUSA_PAC_Pos)) /* Assignment of value for PAC in the PAC_STATUSA register */
#define PAC_STATUSA_PM_Pos                    _UINT32_(1)                                          /* (PAC_STATUSA) PM APB Protect Enable Position */
#define PAC_STATUSA_PM_Msk                    (_UINT32_(0x1) << PAC_STATUSA_PM_Pos)                /* (PAC_STATUSA) PM APB Protect Enable Mask */
#define PAC_STATUSA_PM(value)                 (PAC_STATUSA_PM_Msk & (_UINT32_(value) << PAC_STATUSA_PM_Pos)) /* Assignment of value for PM in the PAC_STATUSA register */
#define PAC_STATUSA_MCLK_Pos                  _UINT32_(2)                                          /* (PAC_STATUSA) MCLK APB Protect Enable Position */
#define PAC_STATUSA_MCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_MCLK_Pos)              /* (PAC_STATUSA) MCLK APB Protect Enable Mask */
#define PAC_STATUSA_MCLK(value)               (PAC_STATUSA_MCLK_Msk & (_UINT32_(value) << PAC_STATUSA_MCLK_Pos)) /* Assignment of value for MCLK in the PAC_STATUSA register */
#define PAC_STATUSA_RSTC_Pos                  _UINT32_(3)                                          /* (PAC_STATUSA) RSTC APB Protect Enable Position */
#define PAC_STATUSA_RSTC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_RSTC_Pos)              /* (PAC_STATUSA) RSTC APB Protect Enable Mask */
#define PAC_STATUSA_RSTC(value)               (PAC_STATUSA_RSTC_Msk & (_UINT32_(value) << PAC_STATUSA_RSTC_Pos)) /* Assignment of value for RSTC in the PAC_STATUSA register */
#define PAC_STATUSA_OSCCTRL_Pos               _UINT32_(4)                                          /* (PAC_STATUSA) OSCCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSCCTRL_Msk               (_UINT32_(0x1) << PAC_STATUSA_OSCCTRL_Pos)           /* (PAC_STATUSA) OSCCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSCCTRL(value)            (PAC_STATUSA_OSCCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSCCTRL_Pos)) /* Assignment of value for OSCCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_OSC32KCTRL_Pos            _UINT32_(5)                                          /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSC32KCTRL_Msk            (_UINT32_(0x1) << PAC_STATUSA_OSC32KCTRL_Pos)        /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSC32KCTRL(value)         (PAC_STATUSA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSC32KCTRL_Pos)) /* Assignment of value for OSC32KCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_SUPC_Pos                  _UINT32_(6)                                          /* (PAC_STATUSA) SUPC APB Protect Enable Position */
#define PAC_STATUSA_SUPC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_SUPC_Pos)              /* (PAC_STATUSA) SUPC APB Protect Enable Mask */
#define PAC_STATUSA_SUPC(value)               (PAC_STATUSA_SUPC_Msk & (_UINT32_(value) << PAC_STATUSA_SUPC_Pos)) /* Assignment of value for SUPC in the PAC_STATUSA register */
#define PAC_STATUSA_GCLK_Pos                  _UINT32_(7)                                          /* (PAC_STATUSA) GCLK APB Protect Enable Position */
#define PAC_STATUSA_GCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_GCLK_Pos)              /* (PAC_STATUSA) GCLK APB Protect Enable Mask */
#define PAC_STATUSA_GCLK(value)               (PAC_STATUSA_GCLK_Msk & (_UINT32_(value) << PAC_STATUSA_GCLK_Pos)) /* Assignment of value for GCLK in the PAC_STATUSA register */
#define PAC_STATUSA_WDT_Pos                   _UINT32_(8)                                          /* (PAC_STATUSA) WDT APB Protect Enable Position */
#define PAC_STATUSA_WDT_Msk                   (_UINT32_(0x1) << PAC_STATUSA_WDT_Pos)               /* (PAC_STATUSA) WDT APB Protect Enable Mask */
#define PAC_STATUSA_WDT(value)                (PAC_STATUSA_WDT_Msk & (_UINT32_(value) << PAC_STATUSA_WDT_Pos)) /* Assignment of value for WDT in the PAC_STATUSA register */
#define PAC_STATUSA_RTC_Pos                   _UINT32_(9)                                          /* (PAC_STATUSA) RTC APB Protect Enable Position */
#define PAC_STATUSA_RTC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_RTC_Pos)               /* (PAC_STATUSA) RTC APB Protect Enable Mask */
#define PAC_STATUSA_RTC(value)                (PAC_STATUSA_RTC_Msk & (_UINT32_(value) << PAC_STATUSA_RTC_Pos)) /* Assignment of value for RTC in the PAC_STATUSA register */
#define PAC_STATUSA_EIC_Pos                   _UINT32_(10)                                         /* (PAC_STATUSA) EIC APB Protect Enable Position */
#define PAC_STATUSA_EIC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_EIC_Pos)               /* (PAC_STATUSA) EIC APB Protect Enable Mask */
#define PAC_STATUSA_EIC(value)                (PAC_STATUSA_EIC_Msk & (_UINT32_(value) << PAC_STATUSA_EIC_Pos)) /* Assignment of value for EIC in the PAC_STATUSA register */
#define PAC_STATUSA_FREQM_Pos                 _UINT32_(11)                                         /* (PAC_STATUSA) FREQM APB Protect Enable Position */
#define PAC_STATUSA_FREQM_Msk                 (_UINT32_(0x1) << PAC_STATUSA_FREQM_Pos)             /* (PAC_STATUSA) FREQM APB Protect Enable Mask */
#define PAC_STATUSA_FREQM(value)              (PAC_STATUSA_FREQM_Msk & (_UINT32_(value) << PAC_STATUSA_FREQM_Pos)) /* Assignment of value for FREQM in the PAC_STATUSA register */
#define PAC_STATUSA_MCRAMC_Pos                _UINT32_(12)                                         /* (PAC_STATUSA) MCRAMC APB Protect Enable Position */
#define PAC_STATUSA_MCRAMC_Msk                (_UINT32_(0x1) << PAC_STATUSA_MCRAMC_Pos)            /* (PAC_STATUSA) MCRAMC APB Protect Enable Mask */
#define PAC_STATUSA_MCRAMC(value)             (PAC_STATUSA_MCRAMC_Msk & (_UINT32_(value) << PAC_STATUSA_MCRAMC_Pos)) /* Assignment of value for MCRAMC in the PAC_STATUSA register */
#define PAC_STATUSA_Msk                       _UINT32_(0x00001FFF)                                 /* (PAC_STATUSA) Register Mask  */


/* -------- PAC_STATUSB : (PAC Offset: 0x38) ( R/ 32) Peripheral write protection status - Bridge B -------- */
#define PAC_STATUSB_RESETVALUE                _UINT32_(0x02)                                       /*  (PAC_STATUSB) Peripheral write protection status - Bridge B  Reset Value */

#define PAC_STATUSB_PORT_Pos                  _UINT32_(0)                                          /* (PAC_STATUSB) PORT APB Protect Enable Position */
#define PAC_STATUSB_PORT_Msk                  (_UINT32_(0x1) << PAC_STATUSB_PORT_Pos)              /* (PAC_STATUSB) PORT APB Protect Enable Mask */
#define PAC_STATUSB_PORT(value)               (PAC_STATUSB_PORT_Msk & (_UINT32_(value) << PAC_STATUSB_PORT_Pos)) /* Assignment of value for PORT in the PAC_STATUSB register */
#define PAC_STATUSB_DSU_Pos                   _UINT32_(1)                                          /* (PAC_STATUSB) DSU APB Protect Enable Position */
#define PAC_STATUSB_DSU_Msk                   (_UINT32_(0x1) << PAC_STATUSB_DSU_Pos)               /* (PAC_STATUSB) DSU APB Protect Enable Mask */
#define PAC_STATUSB_DSU(value)                (PAC_STATUSB_DSU_Msk & (_UINT32_(value) << PAC_STATUSB_DSU_Pos)) /* Assignment of value for DSU in the PAC_STATUSB register */
#define PAC_STATUSB_NVMCTRL_Pos               _UINT32_(2)                                          /* (PAC_STATUSB) NVMCTRL APB Protect Enable Position */
#define PAC_STATUSB_NVMCTRL_Msk               (_UINT32_(0x1) << PAC_STATUSB_NVMCTRL_Pos)           /* (PAC_STATUSB) NVMCTRL APB Protect Enable Mask */
#define PAC_STATUSB_NVMCTRL(value)            (PAC_STATUSB_NVMCTRL_Msk & (_UINT32_(value) << PAC_STATUSB_NVMCTRL_Pos)) /* Assignment of value for NVMCTRL in the PAC_STATUSB register */
#define PAC_STATUSB_DMAC_Pos                  _UINT32_(3)                                          /* (PAC_STATUSB) DMAC APB Protect Enable Position */
#define PAC_STATUSB_DMAC_Msk                  (_UINT32_(0x1) << PAC_STATUSB_DMAC_Pos)              /* (PAC_STATUSB) DMAC APB Protect Enable Mask */
#define PAC_STATUSB_DMAC(value)               (PAC_STATUSB_DMAC_Msk & (_UINT32_(value) << PAC_STATUSB_DMAC_Pos)) /* Assignment of value for DMAC in the PAC_STATUSB register */
#define PAC_STATUSB_MTB_Pos                   _UINT32_(4)                                          /* (PAC_STATUSB) MTB APB Protect Enable Position */
#define PAC_STATUSB_MTB_Msk                   (_UINT32_(0x1) << PAC_STATUSB_MTB_Pos)               /* (PAC_STATUSB) MTB APB Protect Enable Mask */
#define PAC_STATUSB_MTB(value)                (PAC_STATUSB_MTB_Msk & (_UINT32_(value) << PAC_STATUSB_MTB_Pos)) /* Assignment of value for MTB in the PAC_STATUSB register */
#define PAC_STATUSB_HMATRIXHS_Pos             _UINT32_(5)                                          /* (PAC_STATUSB) HMATRIXHS APB Protect Enable Position */
#define PAC_STATUSB_HMATRIXHS_Msk             (_UINT32_(0x1) << PAC_STATUSB_HMATRIXHS_Pos)         /* (PAC_STATUSB) HMATRIXHS APB Protect Enable Mask */
#define PAC_STATUSB_HMATRIXHS(value)          (PAC_STATUSB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_STATUSB_HMATRIXHS_Pos)) /* Assignment of value for HMATRIXHS in the PAC_STATUSB register */
#define PAC_STATUSB_Msk                       _UINT32_(0x0000003F)                                 /* (PAC_STATUSB) Register Mask  */


/* -------- PAC_STATUSC : (PAC Offset: 0x3C) ( R/ 32) Peripheral write protection status - Bridge C -------- */
#define PAC_STATUSC_RESETVALUE                _UINT32_(0x9000000)                                  /*  (PAC_STATUSC) Peripheral write protection status - Bridge C  Reset Value */

#define PAC_STATUSC_EVSYS_Pos                 _UINT32_(0)                                          /* (PAC_STATUSC) EVSYS APB Protect Enable Position */
#define PAC_STATUSC_EVSYS_Msk                 (_UINT32_(0x1) << PAC_STATUSC_EVSYS_Pos)             /* (PAC_STATUSC) EVSYS APB Protect Enable Mask */
#define PAC_STATUSC_EVSYS(value)              (PAC_STATUSC_EVSYS_Msk & (_UINT32_(value) << PAC_STATUSC_EVSYS_Pos)) /* Assignment of value for EVSYS in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM0_Pos               _UINT32_(1)                                          /* (PAC_STATUSC) SERCOM0 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM0_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM0_Pos)           /* (PAC_STATUSC) SERCOM0 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM0(value)            (PAC_STATUSC_SERCOM0_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM0_Pos)) /* Assignment of value for SERCOM0 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM1_Pos               _UINT32_(2)                                          /* (PAC_STATUSC) SERCOM1 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM1_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM1_Pos)           /* (PAC_STATUSC) SERCOM1 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM1(value)            (PAC_STATUSC_SERCOM1_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM1_Pos)) /* Assignment of value for SERCOM1 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM2_Pos               _UINT32_(3)                                          /* (PAC_STATUSC) SERCOM2 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM2_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM2_Pos)           /* (PAC_STATUSC) SERCOM2 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM2(value)            (PAC_STATUSC_SERCOM2_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM2_Pos)) /* Assignment of value for SERCOM2 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM3_Pos               _UINT32_(4)                                          /* (PAC_STATUSC) SERCOM3 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM3_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM3_Pos)           /* (PAC_STATUSC) SERCOM3 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM3(value)            (PAC_STATUSC_SERCOM3_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM3_Pos)) /* Assignment of value for SERCOM3 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM4_Pos               _UINT32_(5)                                          /* (PAC_STATUSC) SERCOM4 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM4_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM4_Pos)           /* (PAC_STATUSC) SERCOM4 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM4(value)            (PAC_STATUSC_SERCOM4_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM4_Pos)) /* Assignment of value for SERCOM4 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM5_Pos               _UINT32_(6)                                          /* (PAC_STATUSC) SERCOM5 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM5_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM5_Pos)           /* (PAC_STATUSC) SERCOM5 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM5(value)            (PAC_STATUSC_SERCOM5_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM5_Pos)) /* Assignment of value for SERCOM5 in the PAC_STATUSC register */
#define PAC_STATUSC_CAN0_Pos                  _UINT32_(7)                                          /* (PAC_STATUSC) CAN0 APB Protect Enable Position */
#define PAC_STATUSC_CAN0_Msk                  (_UINT32_(0x1) << PAC_STATUSC_CAN0_Pos)              /* (PAC_STATUSC) CAN0 APB Protect Enable Mask */
#define PAC_STATUSC_CAN0(value)               (PAC_STATUSC_CAN0_Msk & (_UINT32_(value) << PAC_STATUSC_CAN0_Pos)) /* Assignment of value for CAN0 in the PAC_STATUSC register */
#define PAC_STATUSC_CAN1_Pos                  _UINT32_(8)                                          /* (PAC_STATUSC) CAN1 APB Protect Enable Position */
#define PAC_STATUSC_CAN1_Msk                  (_UINT32_(0x1) << PAC_STATUSC_CAN1_Pos)              /* (PAC_STATUSC) CAN1 APB Protect Enable Mask */
#define PAC_STATUSC_CAN1(value)               (PAC_STATUSC_CAN1_Msk & (_UINT32_(value) << PAC_STATUSC_CAN1_Pos)) /* Assignment of value for CAN1 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC0_Pos                  _UINT32_(9)                                          /* (PAC_STATUSC) TCC0 APB Protect Enable Position */
#define PAC_STATUSC_TCC0_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC0_Pos)              /* (PAC_STATUSC) TCC0 APB Protect Enable Mask */
#define PAC_STATUSC_TCC0(value)               (PAC_STATUSC_TCC0_Msk & (_UINT32_(value) << PAC_STATUSC_TCC0_Pos)) /* Assignment of value for TCC0 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC1_Pos                  _UINT32_(10)                                         /* (PAC_STATUSC) TCC1 APB Protect Enable Position */
#define PAC_STATUSC_TCC1_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC1_Pos)              /* (PAC_STATUSC) TCC1 APB Protect Enable Mask */
#define PAC_STATUSC_TCC1(value)               (PAC_STATUSC_TCC1_Msk & (_UINT32_(value) << PAC_STATUSC_TCC1_Pos)) /* Assignment of value for TCC1 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC2_Pos                  _UINT32_(11)                                         /* (PAC_STATUSC) TCC2 APB Protect Enable Position */
#define PAC_STATUSC_TCC2_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC2_Pos)              /* (PAC_STATUSC) TCC2 APB Protect Enable Mask */
#define PAC_STATUSC_TCC2(value)               (PAC_STATUSC_TCC2_Msk & (_UINT32_(value) << PAC_STATUSC_TCC2_Pos)) /* Assignment of value for TCC2 in the PAC_STATUSC register */
#define PAC_STATUSC_TC0_Pos                   _UINT32_(12)                                         /* (PAC_STATUSC) TC0 APB Protect Enable Position */
#define PAC_STATUSC_TC0_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC0_Pos)               /* (PAC_STATUSC) TC0 APB Protect Enable Mask */
#define PAC_STATUSC_TC0(value)                (PAC_STATUSC_TC0_Msk & (_UINT32_(value) << PAC_STATUSC_TC0_Pos)) /* Assignment of value for TC0 in the PAC_STATUSC register */
#define PAC_STATUSC_TC1_Pos                   _UINT32_(13)                                         /* (PAC_STATUSC) TC1 APB Protect Enable Position */
#define PAC_STATUSC_TC1_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC1_Pos)               /* (PAC_STATUSC) TC1 APB Protect Enable Mask */
#define PAC_STATUSC_TC1(value)                (PAC_STATUSC_TC1_Msk & (_UINT32_(value) << PAC_STATUSC_TC1_Pos)) /* Assignment of value for TC1 in the PAC_STATUSC register */
#define PAC_STATUSC_TC2_Pos                   _UINT32_(14)                                         /* (PAC_STATUSC) TC2 APB Protect Enable Position */
#define PAC_STATUSC_TC2_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC2_Pos)               /* (PAC_STATUSC) TC2 APB Protect Enable Mask */
#define PAC_STATUSC_TC2(value)                (PAC_STATUSC_TC2_Msk & (_UINT32_(value) << PAC_STATUSC_TC2_Pos)) /* Assignment of value for TC2 in the PAC_STATUSC register */
#define PAC_STATUSC_TC3_Pos                   _UINT32_(15)                                         /* (PAC_STATUSC) TC3 APB Protect Enable Position */
#define PAC_STATUSC_TC3_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC3_Pos)               /* (PAC_STATUSC) TC3 APB Protect Enable Mask */
#define PAC_STATUSC_TC3(value)                (PAC_STATUSC_TC3_Msk & (_UINT32_(value) << PAC_STATUSC_TC3_Pos)) /* Assignment of value for TC3 in the PAC_STATUSC register */
#define PAC_STATUSC_TC4_Pos                   _UINT32_(16)                                         /* (PAC_STATUSC) TC4 APB Protect Enable Position */
#define PAC_STATUSC_TC4_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC4_Pos)               /* (PAC_STATUSC) TC4 APB Protect Enable Mask */
#define PAC_STATUSC_TC4(value)                (PAC_STATUSC_TC4_Msk & (_UINT32_(value) << PAC_STATUSC_TC4_Pos)) /* Assignment of value for TC4 in the PAC_STATUSC register */
#define PAC_STATUSC_ADC0_Pos                  _UINT32_(17)                                         /* (PAC_STATUSC) ADC0 APB Protect Enable Position */
#define PAC_STATUSC_ADC0_Msk                  (_UINT32_(0x1) << PAC_STATUSC_ADC0_Pos)              /* (PAC_STATUSC) ADC0 APB Protect Enable Mask */
#define PAC_STATUSC_ADC0(value)               (PAC_STATUSC_ADC0_Msk & (_UINT32_(value) << PAC_STATUSC_ADC0_Pos)) /* Assignment of value for ADC0 in the PAC_STATUSC register */
#define PAC_STATUSC_ADC1_Pos                  _UINT32_(18)                                         /* (PAC_STATUSC) ADC1 APB Protect Enable Position */
#define PAC_STATUSC_ADC1_Msk                  (_UINT32_(0x1) << PAC_STATUSC_ADC1_Pos)              /* (PAC_STATUSC) ADC1 APB Protect Enable Mask */
#define PAC_STATUSC_ADC1(value)               (PAC_STATUSC_ADC1_Msk & (_UINT32_(value) << PAC_STATUSC_ADC1_Pos)) /* Assignment of value for ADC1 in the PAC_STATUSC register */
#define PAC_STATUSC_AC_Pos                    _UINT32_(19)                                         /* (PAC_STATUSC) AC APB Protect Enable Position */
#define PAC_STATUSC_AC_Msk                    (_UINT32_(0x1) << PAC_STATUSC_AC_Pos)                /* (PAC_STATUSC) AC APB Protect Enable Mask */
#define PAC_STATUSC_AC(value)                 (PAC_STATUSC_AC_Msk & (_UINT32_(value) << PAC_STATUSC_AC_Pos)) /* Assignment of value for AC in the PAC_STATUSC register */
#define PAC_STATUSC_DAC_Pos                   _UINT32_(20)                                         /* (PAC_STATUSC) DAC APB Protect Enable Position */
#define PAC_STATUSC_DAC_Msk                   (_UINT32_(0x1) << PAC_STATUSC_DAC_Pos)               /* (PAC_STATUSC) DAC APB Protect Enable Mask */
#define PAC_STATUSC_DAC(value)                (PAC_STATUSC_DAC_Msk & (_UINT32_(value) << PAC_STATUSC_DAC_Pos)) /* Assignment of value for DAC in the PAC_STATUSC register */
#define PAC_STATUSC_PTC_Pos                   _UINT32_(21)                                         /* (PAC_STATUSC) PTC APB Protect Enable Position */
#define PAC_STATUSC_PTC_Msk                   (_UINT32_(0x1) << PAC_STATUSC_PTC_Pos)               /* (PAC_STATUSC) PTC APB Protect Enable Mask */
#define PAC_STATUSC_PTC(value)                (PAC_STATUSC_PTC_Msk & (_UINT32_(value) << PAC_STATUSC_PTC_Pos)) /* Assignment of value for PTC in the PAC_STATUSC register */
#define PAC_STATUSC_CCL_Pos                   _UINT32_(22)                                         /* (PAC_STATUSC) CCL APB Protect Enable Position */
#define PAC_STATUSC_CCL_Msk                   (_UINT32_(0x1) << PAC_STATUSC_CCL_Pos)               /* (PAC_STATUSC) CCL APB Protect Enable Mask */
#define PAC_STATUSC_CCL(value)                (PAC_STATUSC_CCL_Msk & (_UINT32_(value) << PAC_STATUSC_CCL_Pos)) /* Assignment of value for CCL in the PAC_STATUSC register */
#define PAC_STATUSC_ICM_Pos                   _UINT32_(25)                                         /* (PAC_STATUSC) ICM APB Protect Enable Position */
#define PAC_STATUSC_ICM_Msk                   (_UINT32_(0x1) << PAC_STATUSC_ICM_Pos)               /* (PAC_STATUSC) ICM APB Protect Enable Mask */
#define PAC_STATUSC_ICM(value)                (PAC_STATUSC_ICM_Msk & (_UINT32_(value) << PAC_STATUSC_ICM_Pos)) /* Assignment of value for ICM in the PAC_STATUSC register */
#define PAC_STATUSC_PDEC_Pos                  _UINT32_(26)                                         /* (PAC_STATUSC) PDEC APB Protect Enable Position */
#define PAC_STATUSC_PDEC_Msk                  (_UINT32_(0x1) << PAC_STATUSC_PDEC_Pos)              /* (PAC_STATUSC) PDEC APB Protect Enable Mask */
#define PAC_STATUSC_PDEC(value)               (PAC_STATUSC_PDEC_Msk & (_UINT32_(value) << PAC_STATUSC_PDEC_Pos)) /* Assignment of value for PDEC in the PAC_STATUSC register */
#define PAC_STATUSC_SMBIST_Pos                _UINT32_(27)                                         /* (PAC_STATUSC) SMBIST APB Protect Enable Position */
#define PAC_STATUSC_SMBIST_Msk                (_UINT32_(0x1) << PAC_STATUSC_SMBIST_Pos)            /* (PAC_STATUSC) SMBIST APB Protect Enable Mask */
#define PAC_STATUSC_SMBIST(value)             (PAC_STATUSC_SMBIST_Msk & (_UINT32_(value) << PAC_STATUSC_SMBIST_Pos)) /* Assignment of value for SMBIST in the PAC_STATUSC register */
#define PAC_STATUSC_Msk                       _UINT32_(0x0E7FFFFF)                                 /* (PAC_STATUSC) Register Mask  */

#define PAC_STATUSC_SERCOM_Pos                _UINT32_(1)                                          /* (PAC_STATUSC Position) SERCOMx APB Protect Enable */
#define PAC_STATUSC_SERCOM_Msk                (_UINT32_(0x3F) << PAC_STATUSC_SERCOM_Pos)           /* (PAC_STATUSC Mask) SERCOM */
#define PAC_STATUSC_SERCOM(value)             (PAC_STATUSC_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM_Pos)) 
#define PAC_STATUSC_CAN_Pos                   _UINT32_(7)                                          /* (PAC_STATUSC Position) CANx APB Protect Enable */
#define PAC_STATUSC_CAN_Msk                   (_UINT32_(0x3) << PAC_STATUSC_CAN_Pos)               /* (PAC_STATUSC Mask) CAN */
#define PAC_STATUSC_CAN(value)                (PAC_STATUSC_CAN_Msk & (_UINT32_(value) << PAC_STATUSC_CAN_Pos)) 
#define PAC_STATUSC_TCC_Pos                   _UINT32_(9)                                          /* (PAC_STATUSC Position) TCCx APB Protect Enable */
#define PAC_STATUSC_TCC_Msk                   (_UINT32_(0x7) << PAC_STATUSC_TCC_Pos)               /* (PAC_STATUSC Mask) TCC */
#define PAC_STATUSC_TCC(value)                (PAC_STATUSC_TCC_Msk & (_UINT32_(value) << PAC_STATUSC_TCC_Pos)) 
#define PAC_STATUSC_TC_Pos                    _UINT32_(12)                                         /* (PAC_STATUSC Position) TCx APB Protect Enable */
#define PAC_STATUSC_TC_Msk                    (_UINT32_(0x1F) << PAC_STATUSC_TC_Pos)               /* (PAC_STATUSC Mask) TC */
#define PAC_STATUSC_TC(value)                 (PAC_STATUSC_TC_Msk & (_UINT32_(value) << PAC_STATUSC_TC_Pos)) 
#define PAC_STATUSC_ADC_Pos                   _UINT32_(17)                                         /* (PAC_STATUSC Position) ADCx APB Protect Enable */
#define PAC_STATUSC_ADC_Msk                   (_UINT32_(0x3) << PAC_STATUSC_ADC_Pos)               /* (PAC_STATUSC Mask) ADC */
#define PAC_STATUSC_ADC(value)                (PAC_STATUSC_ADC_Msk & (_UINT32_(value) << PAC_STATUSC_ADC_Pos)) 

/* -------- PAC_STATUSD : (PAC Offset: 0x40) ( R/ 32) Peripheral write protection status - Bridge D -------- */
#define PAC_STATUSD_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSD) Peripheral write protection status - Bridge D  Reset Value */

#define PAC_STATUSD_SERCOM6_Pos               _UINT32_(0)                                          /* (PAC_STATUSD) SERCOM6 APB Protect Enable Position */
#define PAC_STATUSD_SERCOM6_Msk               (_UINT32_(0x1) << PAC_STATUSD_SERCOM6_Pos)           /* (PAC_STATUSD) SERCOM6 APB Protect Enable Mask */
#define PAC_STATUSD_SERCOM6(value)            (PAC_STATUSD_SERCOM6_Msk & (_UINT32_(value) << PAC_STATUSD_SERCOM6_Pos)) /* Assignment of value for SERCOM6 in the PAC_STATUSD register */
#define PAC_STATUSD_SERCOM7_Pos               _UINT32_(1)                                          /* (PAC_STATUSD) SERCOM7 APB Protect Enable Position */
#define PAC_STATUSD_SERCOM7_Msk               (_UINT32_(0x1) << PAC_STATUSD_SERCOM7_Pos)           /* (PAC_STATUSD) SERCOM7 APB Protect Enable Mask */
#define PAC_STATUSD_SERCOM7(value)            (PAC_STATUSD_SERCOM7_Msk & (_UINT32_(value) << PAC_STATUSD_SERCOM7_Pos)) /* Assignment of value for SERCOM7 in the PAC_STATUSD register */
#define PAC_STATUSD_TC5_Pos                   _UINT32_(2)                                          /* (PAC_STATUSD) TC5 APB Protect Enable Position */
#define PAC_STATUSD_TC5_Msk                   (_UINT32_(0x1) << PAC_STATUSD_TC5_Pos)               /* (PAC_STATUSD) TC5 APB Protect Enable Mask */
#define PAC_STATUSD_TC5(value)                (PAC_STATUSD_TC5_Msk & (_UINT32_(value) << PAC_STATUSD_TC5_Pos)) /* Assignment of value for TC5 in the PAC_STATUSD register */
#define PAC_STATUSD_TC6_Pos                   _UINT32_(3)                                          /* (PAC_STATUSD) TC6 APB Protect Enable Position */
#define PAC_STATUSD_TC6_Msk                   (_UINT32_(0x1) << PAC_STATUSD_TC6_Pos)               /* (PAC_STATUSD) TC6 APB Protect Enable Mask */
#define PAC_STATUSD_TC6(value)                (PAC_STATUSD_TC6_Msk & (_UINT32_(value) << PAC_STATUSD_TC6_Pos)) /* Assignment of value for TC6 in the PAC_STATUSD register */
#define PAC_STATUSD_TC7_Pos                   _UINT32_(4)                                          /* (PAC_STATUSD) TC7 APB Protect Enable Position */
#define PAC_STATUSD_TC7_Msk                   (_UINT32_(0x1) << PAC_STATUSD_TC7_Pos)               /* (PAC_STATUSD) TC7 APB Protect Enable Mask */
#define PAC_STATUSD_TC7(value)                (PAC_STATUSD_TC7_Msk & (_UINT32_(value) << PAC_STATUSD_TC7_Pos)) /* Assignment of value for TC7 in the PAC_STATUSD register */
#define PAC_STATUSD_Msk                       _UINT32_(0x0000001F)                                 /* (PAC_STATUSD) Register Mask  */

#define PAC_STATUSD_SERCOM_Pos                _UINT32_(0)                                          /* (PAC_STATUSD Position) SERCOM6 APB Protect Enable */
#define PAC_STATUSD_SERCOM_Msk                (_UINT32_(0x3) << PAC_STATUSD_SERCOM_Pos)            /* (PAC_STATUSD Mask) SERCOM */
#define PAC_STATUSD_SERCOM(value)             (PAC_STATUSD_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSD_SERCOM_Pos)) 
#define PAC_STATUSD_TC_Pos                    _UINT32_(2)                                          /* (PAC_STATUSD Position) TC7 APB Protect Enable */
#define PAC_STATUSD_TC_Msk                    (_UINT32_(0x7) << PAC_STATUSD_TC_Pos)                /* (PAC_STATUSD Mask) TC */
#define PAC_STATUSD_TC(value)                 (PAC_STATUSD_TC_Msk & (_UINT32_(value) << PAC_STATUSD_TC_Pos)) 

/* PAC register offsets definitions */
#define PAC_WRCTRL_REG_OFST            _UINT32_(0x00)      /* (PAC_WRCTRL) Write control Offset */
#define PAC_EVCTRL_REG_OFST            _UINT32_(0x04)      /* (PAC_EVCTRL) Event control Offset */
#define PAC_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (PAC_INTENCLR) Interrupt enable clear Offset */
#define PAC_INTENSET_REG_OFST          _UINT32_(0x09)      /* (PAC_INTENSET) Interrupt enable set Offset */
#define PAC_INTFLAGAHB_REG_OFST        _UINT32_(0x10)      /* (PAC_INTFLAGAHB) Bridge interrupt flag status Offset */
#define PAC_INTFLAGA_REG_OFST          _UINT32_(0x14)      /* (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A Offset */
#define PAC_INTFLAGB_REG_OFST          _UINT32_(0x18)      /* (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B Offset */
#define PAC_INTFLAGC_REG_OFST          _UINT32_(0x1C)      /* (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C Offset */
#define PAC_INTFLAGD_REG_OFST          _UINT32_(0x20)      /* (PAC_INTFLAGD) Peripheral interrupt flag status - Bridge D Offset */
#define PAC_STATUSA_REG_OFST           _UINT32_(0x34)      /* (PAC_STATUSA) Peripheral write protection status - Bridge A Offset */
#define PAC_STATUSB_REG_OFST           _UINT32_(0x38)      /* (PAC_STATUSB) Peripheral write protection status - Bridge B Offset */
#define PAC_STATUSC_REG_OFST           _UINT32_(0x3C)      /* (PAC_STATUSC) Peripheral write protection status - Bridge C Offset */
#define PAC_STATUSD_REG_OFST           _UINT32_(0x40)      /* (PAC_STATUSD) Peripheral write protection status - Bridge D Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* PAC register API structure */
typedef struct
{  /* Peripheral Access Controller */
  __IO  uint32_t                       PAC_WRCTRL;         /* Offset: 0x00 (R/W  32) Write control */
  __IO  uint8_t                        PAC_EVCTRL;         /* Offset: 0x04 (R/W  8) Event control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        PAC_INTENCLR;       /* Offset: 0x08 (R/W  8) Interrupt enable clear */
  __IO  uint8_t                        PAC_INTENSET;       /* Offset: 0x09 (R/W  8) Interrupt enable set */
  __I   uint8_t                        Reserved2[0x06];
  __IO  uint32_t                       PAC_INTFLAGAHB;     /* Offset: 0x10 (R/W  32) Bridge interrupt flag status */
  __IO  uint32_t                       PAC_INTFLAGA;       /* Offset: 0x14 (R/W  32) Peripheral interrupt flag status - Bridge A */
  __IO  uint32_t                       PAC_INTFLAGB;       /* Offset: 0x18 (R/W  32) Peripheral interrupt flag status - Bridge B */
  __IO  uint32_t                       PAC_INTFLAGC;       /* Offset: 0x1C (R/W  32) Peripheral interrupt flag status - Bridge C */
  __IO  uint32_t                       PAC_INTFLAGD;       /* Offset: 0x20 (R/W  32) Peripheral interrupt flag status - Bridge D */
  __I   uint8_t                        Reserved3[0x10];
  __I   uint32_t                       PAC_STATUSA;        /* Offset: 0x34 (R/   32) Peripheral write protection status - Bridge A */
  __I   uint32_t                       PAC_STATUSB;        /* Offset: 0x38 (R/   32) Peripheral write protection status - Bridge B */
  __I   uint32_t                       PAC_STATUSC;        /* Offset: 0x3C (R/   32) Peripheral write protection status - Bridge C */
  __I   uint32_t                       PAC_STATUSD;        /* Offset: 0x40 (R/   32) Peripheral write protection status - Bridge D */
} pac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_PAC_COMPONENT_H_ */
