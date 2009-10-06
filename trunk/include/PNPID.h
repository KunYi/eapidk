/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL$
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for PNPID.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : PNPID.h
 *I  File Location        : include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

typedef struct VendorLookupTable_s{
        uint16_t PNPID;
        TCHAR   *pVName;
}VendorLookupTable_t;

#define PNPID_END_OF_LIST_MARKER 0xFFFF
VendorLookupTable_t VendorLookupTable[]={
	{0x2504, TEXT("Anatek Electronics Inc."                                                                 )},  /* AAE */
	{0x3404, TEXT("Ann Arbor Technologies"                                                                  )},  /* AAT */
	{0x4104, TEXT("ABBAHOME   INC."                                                                         )},  /* ABA */
	{0x4304, TEXT("AboCom System Inc"                                                                       )},  /* ABC */
	{0x4404, TEXT("Allen Bradley Company"                                                                   )},  /* ABD */
	{0x4504, TEXT("Alcatel Bell"                                                                            )},  /* ABE */
	{0x4F04, TEXT("D-Link Systems Inc"                                                                      )},  /* ABO */
	{0x5404, TEXT("Anchor Bay Technologies, Inc."                                                           )},  /* ABT */
	{0x5604, TEXT("Advanced Research Technology"                                                            )},  /* ABV */
	{0x6104, TEXT("Ariel Corporation"                                                                       )},  /* ACA */
	{0x6204, TEXT("Aculab Ltd"                                                                              )},  /* ACB */
	{0x6304, TEXT("Accton Technology Corporation"                                                           )},  /* ACC */
	{0x6404, TEXT("AWETA BV"                                                                                )},  /* ACD */
	{0x6504, TEXT("Actek Engineering Pty Ltd"                                                               )},  /* ACE */
	{0x6704, TEXT("A&R Cambridge Ltd"                                                                       )},  /* ACG */
	{0x6804, TEXT("Archtek Telecom Corporation"                                                             )},  /* ACH */
	{0x6904, TEXT("Ancor Communications Inc"                                                                )},  /* ACI */
	{0x6B04, TEXT("Acksys"                                                                                  )},  /* ACK */
	{0x6C04, TEXT("Apricot Computers"                                                                       )},  /* ACL */
	{0x6D04, TEXT("Acroloop Motion Control Systems Inc"                                                     )},  /* ACM */
	{0x6F04, TEXT("Allion Computer Inc."                                                                    )},  /* ACO */
	{0x7004, TEXT("Aspen Tech Inc"                                                                          )},  /* ACP */
	{0x7204, TEXT("Acer Technologies"                                                                       )},  /* ACR */
	{0x7304, TEXT("Altos Computer Systems"                                                                  )},  /* ACS */
	{0x7404, TEXT("Applied Creative Technology"                                                             )},  /* ACT */
	{0x7504, TEXT("Acculogic"                                                                               )},  /* ACU */
	{0x7604, TEXT("ActivCard S.A"                                                                           )},  /* ACV */
	{0x8104, TEXT("Addi-Data GmbH"                                                                          )},  /* ADA */
	{0x8204, TEXT("Aldebbaron"                                                                              )},  /* ADB */
	{0x8304, TEXT("Acnhor Datacomm"                                                                         )},  /* ADC */
	{0x8404, TEXT("Advanced Peripheral Devices Inc"                                                         )},  /* ADD */
	{0x8504, TEXT("Arithmos, Inc."                                                                          )},  /* ADE */
	{0x8804, TEXT("Aerodata Holdings Ltd"                                                                   )},  /* ADH */
	{0x8904, TEXT("ADI Systems Inc"                                                                         )},  /* ADI */
	{0x8B04, TEXT("Adtek System Science Company Ltd"                                                        )},  /* ADK */
	{0x8C04, TEXT("ASTRA Security Products Ltd"                                                             )},  /* ADL */
	{0x8D04, TEXT("Ad Lib MultiMedia Inc"                                                                   )},  /* ADM */
	{0x8E04, TEXT("Analog & Digital Devices Tel. Inc"                                                       )},  /* ADN */
	{0x9004, TEXT("Adaptec Inc"                                                                             )},  /* ADP */
	{0x9204, TEXT("Nasa Ames Research Center"                                                               )},  /* ADR */
	{0x9304, TEXT("Analog Devices Inc"                                                                      )},  /* ADS */
	{0x9404, TEXT("Adtek"                                                                                   )},  /* ADT */
	{0x9404, TEXT("Adtek"                                                                                   )},  /* ADT */
	{0x9604, TEXT("Advanced Micro Devices Inc"                                                              )},  /* ADV */
	{0x9804, TEXT("Adax Inc"                                                                                )},  /* ADX */
	{0xA304, TEXT("Antex Electronics Corporation"                                                           )},  /* AEC */
	{0xA404, TEXT("Advanced Electronic Designs, Inc."                                                       )},  /* AED */
	{0xA904, TEXT("Actiontec Electric Inc"                                                                  )},  /* AEI */
	{0xAA04, TEXT("Alpha Electronics Company"                                                               )},  /* AEJ */
	{0xAD04, TEXT("ASEM S.p.A."                                                                             )},  /* AEM */
	{0xB004, TEXT("Aetas Peripheral International"                                                          )},  /* AEP */
	{0xB404, TEXT("Aethra Telecomunicazioni S.r.l."                                                         )},  /* AET */
	{0xC104, TEXT("Alfa Inc"                                                                                )},  /* AFA */
	{0xE304, TEXT("Beijing Aerospace Golden Card Electronic Engineering Co.,Ltd."                           )},  /* AGC */
	{0xE904, TEXT("Artish Graphics Inc"                                                                     )},  /* AGI */
	{0xEC04, TEXT("Argolis"                                                                                 )},  /* AGL */
	{0xED04, TEXT("Advan Int'l Corporation"                                                                 )},  /* AGM */
	{0xF404, TEXT("Agilent Technologies"                                                                    )},  /* AGT */
	{0x0305, TEXT("Advantech Co., Ltd."                                                                     )},  /* AHC */
	{0x2305, TEXT("Arnos Insturments & Computer Systems"                                                    )},  /* AIC */
	{0x2505, TEXT("Altmann Industrieelektronik"                                                             )},  /* AIE */
	{0x2905, TEXT("Amptron International Inc."                                                              )},  /* AII */
	{0x2C05, TEXT("Altos India Ltd"                                                                         )},  /* AIL */
	{0x2D05, TEXT("AIMS Lab Inc"                                                                            )},  /* AIM */
	{0x3205, TEXT("Advanced Integ. Research Inc"                                                            )},  /* AIR */
	{0x3305, TEXT("Alien Internet Services"                                                                 )},  /* AIS */
	{0x3705, TEXT("Aiwa Company Ltd"                                                                        )},  /* AIW */
	{0x3805, TEXT("ALTINEX, INC."                                                                           )},  /* AIX */
	{0x4105, TEXT("AJA Video Systems, Inc."                                                                 )},  /* AJA */
	{0x6205, TEXT("Akebia Ltd"                                                                              )},  /* AKB */
	{0x6905, TEXT("AKIA Corporation"                                                                        )},  /* AKI */
	{0x6C05, TEXT("AMiT Ltd"                                                                                )},  /* AKL */
	{0x6D05, TEXT("Asahi Kasei Microsystems Company Ltd"                                                    )},  /* AKM */
	{0x7005, TEXT("Atom Komplex Prylad"                                                                     )},  /* AKP */
	{0x7905, TEXT("Askey Computer Corporation"                                                              )},  /* AKY */
	{0x8105, TEXT("Alacron Inc"                                                                             )},  /* ALA */
	{0x8305, TEXT("Altec Corporation"                                                                       )},  /* ALC */
	{0x8405, TEXT("In4S Inc"                                                                                )},  /* ALD */
	{0x8705, TEXT("Realtek Semiconductor Corp."                                                             )},  /* ALG */
	{0x8805, TEXT("AL Systems"                                                                              )},  /* ALH */
	{0x8905, TEXT("Acer Labs"                                                                               )},  /* ALI */
	{0x8A05, TEXT("Altec Lansing"                                                                           )},  /* ALJ */
	{0x8B05, TEXT("Acrolink Inc"                                                                            )},  /* ALK */
	{0x8C05, TEXT("Alliance Semiconductor Corporation"                                                      )},  /* ALL */
	{0x8D05, TEXT("Acutec Ltd."                                                                             )},  /* ALM */
	{0x8E05, TEXT("Alana Technologies"                                                                      )},  /* ALN */
	{0x8F05, TEXT("Algolith Inc."                                                                           )},  /* ALO */
	{0x9005, TEXT("Alps Electric Company Ltd"                                                               )},  /* ALP */
	{0x9205, TEXT("Advanced Logic"                                                                          )},  /* ALR */
	{0x9305, TEXT("Avance Logic Inc"                                                                        )},  /* ALS */
	{0x9405, TEXT("Altra"                                                                                   )},  /* ALT */
	{0x9605, TEXT("AlphaView LCD"                                                                           )},  /* ALV */
	{0x9805, TEXT("ALEXON Co.,Ltd."                                                                         )},  /* ALX */
	{0xA105, TEXT("Asia Microelectronic Development Inc"                                                    )},  /* AMA */
	{0xA205, TEXT("Ambient Technologies, Inc."                                                              )},  /* AMB */
	{0xA305, TEXT("Attachmate Corporation"                                                                  )},  /* AMC */
	{0xA405, TEXT("Amdek Corporation"                                                                       )},  /* AMD */
	{0xA905, TEXT("American Megatrends Inc"                                                                 )},  /* AMI */
	{0xAC05, TEXT("Anderson Multimedia Communications (HK) Limited"                                         )},  /* AML */
	{0xAE05, TEXT("Amimon LTD."                                                                             )},  /* AMN */
	{0xB005, TEXT("AMP Inc"                                                                                 )},  /* AMP */
	{0xB405, TEXT("AMT International Industry"                                                              )},  /* AMT */
	{0xB805, TEXT("AMX LLC"                                                                                 )},  /* AMX */
	{0xC105, TEXT("Anakron"                                                                                 )},  /* ANA */
	{0xC305, TEXT("Ancot"                                                                                   )},  /* ANC */
	{0xC405, TEXT("Adtran Inc"                                                                              )},  /* AND */
	{0xC905, TEXT("Anigma Inc"                                                                              )},  /* ANI */
	{0xCB05, TEXT("Anko Electronic Company Ltd"                                                             )},  /* ANK */
	{0xCC05, TEXT("Analogix Semiconductor, Inc"                                                             )},  /* ANL */
	{0xCF05, TEXT("Anorad Corporation"                                                                      )},  /* ANO */
	{0xD005, TEXT("Andrew Network Production"                                                               )},  /* ANP */
	{0xD205, TEXT("ANR Ltd"                                                                                 )},  /* ANR */
	{0xD305, TEXT("Ansel Communication Company"                                                             )},  /* ANS */
	{0xD405, TEXT("Ace CAD Enterprise Company Ltd"                                                          )},  /* ANT */
	{0xD805, TEXT("Acer Netxus Inc"                                                                         )},  /* ANX */
	{0xE105, TEXT("AOpen Inc."                                                                              )},  /* AOA */
	{0xE505, TEXT("Advanced Optics Electronics, Inc."                                                       )},  /* AOE */
	{0xEC05, TEXT("America OnLine"                                                                          )},  /* AOL */
	{0xF405, TEXT("Alcatel"                                                                                 )},  /* AOT */
	{0x0306, TEXT("American Power Conversion"                                                               )},  /* APC */
	{0x0406, TEXT("AppliAdata"                                                                              )},  /* APD */
	{0x0706, TEXT("Horner Electric Inc"                                                                     )},  /* APG */
	{0x0906, TEXT("A Plus Info Corporation"                                                                 )},  /* API */
	{0x0C06, TEXT("Aplicom Oy"                                                                              )},  /* APL */
	{0x0D06, TEXT("Applied Memory Tech"                                                                     )},  /* APM */
	{0x0E06, TEXT("Appian Tech Inc"                                                                         )},  /* APN */
	{0x1006, TEXT("Apple Computer Inc"                                                                      )},  /* APP */
	{0x1206, TEXT("Aprilia s.p.a."                                                                          )},  /* APR */
	{0x1306, TEXT("Autologic Inc"                                                                           )},  /* APS */
	{0x1406, TEXT("Audio Processing Technology  Ltd"                                                        )},  /* APT */
	{0x1806, TEXT("AP Designs Ltd"                                                                          )},  /* APX */
	{0x4306, TEXT("Alta Research Corporation"                                                               )},  /* ARC */
	{0x4506, TEXT("ICET S.p.A."                                                                             )},  /* ARE */
	{0x4706, TEXT("Argus Electronics Co., LTD"                                                              )},  /* ARG */
	{0x4906, TEXT("Argosy Research Inc"                                                                     )},  /* ARI */
	{0x4B06, TEXT("Ark Logic Inc"                                                                           )},  /* ARK */
	{0x4C06, TEXT("Arlotto Comnet Inc"                                                                      )},  /* ARL */
	{0x4D06, TEXT("Arima"                                                                                   )},  /* ARM */
	{0x4F06, TEXT("Poso International B.V."                                                                 )},  /* ARO */
	{0x5306, TEXT("Arescom Inc"                                                                             )},  /* ARS */
	{0x5406, TEXT("Corion Industrial Corporation"                                                           )},  /* ART */
	{0x6306, TEXT("Ascom Strategic Technology Unit"                                                         )},  /* ASC */
	{0x6406, TEXT("USC Information Sciences Institute"                                                      )},  /* ASD */
	{0x6506, TEXT("AseV Display Labs"                                                                       )},  /* ASE */
	{0x6906, TEXT("Ahead Systems"                                                                           )},  /* ASI */
	{0x6B06, TEXT("Ask A/S"                                                                                 )},  /* ASK */
	{0x6C06, TEXT("AccuScene Corporation Ltd"                                                               )},  /* ASL */
	{0x6D06, TEXT("ASEM S.p.A."                                                                             )},  /* ASM */
	{0x6E06, TEXT("Asante Tech Inc"                                                                         )},  /* ASN */
	{0x7006, TEXT("ASP Microelectronics Ltd"                                                                )},  /* ASP */
	{0x7406, TEXT("AST Research Inc"                                                                        )},  /* AST */
	{0x7506, TEXT("Asuscom Network Inc"                                                                     )},  /* ASU */
	{0x7806, TEXT("AudioScience"                                                                            )},  /* ASX */
	{0x7906, TEXT("Rockwell Collins / Airshow Systems"                                                      )},  /* ASY */
	{0x8106, TEXT("Allied Telesyn International (Asia) Pte Ltd"                                             )},  /* ATA */
	{0x8306, TEXT("Ably-Tech Corporation"                                                                   )},  /* ATC */
	{0x8406, TEXT("Alpha Telecom Inc"                                                                       )},  /* ATD */
	{0x8506, TEXT("Innovate Ltd"                                                                            )},  /* ATE */
	{0x8806, TEXT("Athena Informatica S.R.L."                                                               )},  /* ATH */
	{0x8906, TEXT("Allied Telesis KK"                                                                       )},  /* ATI */
	{0x8B06, TEXT("Allied Telesyn Int'l"                                                                    )},  /* ATK */
	{0x8C06, TEXT("Arcus Technology Ltd"                                                                    )},  /* ATL */
	{0x8D06, TEXT("ATM Ltd"                                                                                 )},  /* ATM */
	{0x8E06, TEXT("Athena Smartcard Solutions Ltd."                                                         )},  /* ATN */
	{0x8F06, TEXT("ASTRO DESIGN, INC."                                                                      )},  /* ATO */
	{0x9006, TEXT("Alpha-Top Corporation"                                                                   )},  /* ATP */
	{0x9406, TEXT("AT&T"                                                                                    )},  /* ATT */
	{0x9606, TEXT("Office Depot, Inc."                                                                      )},  /* ATV */
	{0x9806, TEXT("Athenix Corporation"                                                                     )},  /* ATX */
	{0xA906, TEXT("Alps Electric Inc"                                                                       )},  /* AUI */
	{0xAF06, TEXT("DO NOT USE - AUO"                                                                        )},  /* AUO */
	{0xB206, TEXT("Aureal Semiconductor"                                                                    )},  /* AUR */
	{0xB406, TEXT("Autotime Corporation"                                                                    )},  /* AUT */
	{0xC106, TEXT("Avaya Communication"                                                                     )},  /* AVA */
	{0xC306, TEXT("Auravision Corporation"                                                                  )},  /* AVC */
	{0xC406, TEXT("Avid Electronics Corporation"                                                            )},  /* AVD */
	{0xC506, TEXT("Add Value Enterpises (Asia) Pte Ltd"                                                     )},  /* AVE */
	{0xC906, TEXT("Nippon Avionics Co.,Ltd"                                                                 )},  /* AVI */
	{0xCD06, TEXT("AVM GmbH"                                                                                )},  /* AVM */
	{0xCF06, TEXT("Avocent Corporation"                                                                     )},  /* AVO */
	{0xD406, TEXT("Avtek (Electronics) Pty Ltd"                                                             )},  /* AVT */
	{0xD606, TEXT("SBS Technologies (Canada), Inc. (was Avvida Systems, Inc.)"                              )},  /* AVV */
	{0xE306, TEXT("Access Works Comm Inc"                                                                   )},  /* AWC */
	{0xEC06, TEXT("Aironet Wireless Communications, Inc"                                                    )},  /* AWL */
	{0xF306, TEXT("Wave Systems"                                                                            )},  /* AWS */
	{0x0207, TEXT("Adrienne Electronics Corporation"                                                        )},  /* AXB */
	{0x0307, TEXT("AXIOMTEK CO., LTD."                                                                      )},  /* AXC */
	{0x0507, TEXT("D-Link Systems Inc (used as 2nd pnpid)"                                                  )},  /* AXE */
	{0x0907, TEXT("American Magnetics"                                                                      )},  /* AXI */
	{0x0C07, TEXT("Axel"                                                                                    )},  /* AXL */
	{0x1007, TEXT("American Express"                                                                        )},  /* AXP */
	{0x1407, TEXT("Axtend Technologies Inc"                                                                 )},  /* AXT */
	{0x1807, TEXT("Axxon Computer Corporation"                                                              )},  /* AXX */
	{0x1907, TEXT("AXYZ Automation Services, Inc"                                                           )},  /* AXY */
	{0x2407, TEXT("Aydin Displays"                                                                          )},  /* AYD */
	{0x3207, TEXT("Airlib, Inc"                                                                             )},  /* AYR */
	{0x4D07, TEXT("AZ Middelheim - Radiotherapy"                                                            )},  /* AZM */
	{0x5407, TEXT("Aztech Systems Ltd"                                                                      )},  /* AZT */
	{0x2308, TEXT("Biometric Access Corporation"                                                            )},  /* BAC */
	{0x2E08, TEXT("Banyan"                                                                                  )},  /* BAN */
	{0x4208, TEXT("an-najah university"                                                                     )},  /* BBB */
	{0x4808, TEXT("B&Bh"                                                                                    )},  /* BBH */
	{0x4C08, TEXT("Brain Boxes Limited"                                                                     )},  /* BBL */
	{0x6308, TEXT("Beaver Computer Corporaton"                                                              )},  /* BCC */
	{0x6408, TEXT("Dr. Seufert GmbH"                                                                        )},  /* BCD */
	{0x6D08, TEXT("Broadcom"                                                                                )},  /* BCM */
	{0x7108, TEXT("Deutsche Telekom Berkom GmbH"                                                            )},  /* BCQ */
	{0x7308, TEXT("Booria CAD/CAM systems"                                                                  )},  /* BCS */
	{0x8F08, TEXT("Brahler ICS"                                                                             )},  /* BDO */
	{0x9208, TEXT("Blonder Tongue Labs, Inc."                                                               )},  /* BDR */
	{0x9308, TEXT("Barco Display Systems"                                                                   )},  /* BDS */
	{0xA308, TEXT("Elektro Beckhoff GmbH"                                                                   )},  /* BEC */
	{0xA908, TEXT("Beckworth Enterprises Inc"                                                               )},  /* BEI */
	{0xAB08, TEXT("Beko Elektronik A.S."                                                                    )},  /* BEK */
	{0xAC08, TEXT("Beltronic Industrieelektronik GmbH"                                                      )},  /* BEL */
	{0xAF08, TEXT("Baug & Olufsen"                                                                          )},  /* BEO */
	{0xC508, TEXT("B.F. Engineering Corporation"                                                            )},  /* BFE */
	{0xE208, TEXT("Barco Graphics N.V"                                                                      )},  /* BGB */
	{0xF408, TEXT("Budzetron Inc"                                                                           )},  /* BGT */
	{0x1A09, TEXT("BitHeadz, Inc."                                                                          )},  /* BHZ */
	{0x2309, TEXT("Big Island Communications"                                                               )},  /* BIC */
	{0x2909, TEXT("Boeckeler Instruments Inc"                                                               )},  /* BII */
	{0x2C09, TEXT("Billion Electric Company Ltd"                                                            )},  /* BIL */
	{0x2F09, TEXT("BioLink Technologies International, Inc."                                                )},  /* BIO */
	{0x3409, TEXT("Bit 3 Computer"                                                                          )},  /* BIT */
	{0x8909, TEXT("Busicom"                                                                                 )},  /* BLI */
	{0x8E09, TEXT("BioLink Technologies"                                                                    )},  /* BLN */
	{0x9009, TEXT("Bloomberg L.P."                                                                          )},  /* BLP */
	{0xA909, TEXT("Benson Medical Instruments Company"                                                      )},  /* BMI */
	{0xAC09, TEXT("BIOMED Lab"                                                                              )},  /* BML */
	{0xB309, TEXT("BIOMEDISYS"                                                                              )},  /* BMS */
	{0xC509, TEXT("Bull AB"                                                                                 )},  /* BNE */
	{0xCB09, TEXT("Banksia Tech Pty Ltd"                                                                    )},  /* BNK */
	{0xCF09, TEXT("Bang & Olufsen"                                                                          )},  /* BNO */
	{0xD309, TEXT("Boulder Nonlinear Systems"                                                               )},  /* BNS */
	{0xE209, TEXT("Rainy Orchard"                                                                           )},  /* BOB */
	{0xE509, TEXT("BOE"                                                                                     )},  /* BOE */
	{0xF309, TEXT("BOS"                                                                                     )},  /* BOS */
	{0x040A, TEXT("Micro Solutions, Inc."                                                                   )},  /* BPD */
	{0x150A, TEXT("Best Power"                                                                              )},  /* BPU */
	{0x430A, TEXT("BARC"                                                                                    )},  /* BRC */
	{0x470A, TEXT("Bridge Information Co., Ltd"                                                             )},  /* BRG */
	{0x490A, TEXT("Boca Research Inc"                                                                       )},  /* BRI */
	{0x4D0A, TEXT("Braemar Inc"                                                                             )},  /* BRM */
	{0x4F0A, TEXT("BROTHER INDUSTRIES,LTD."                                                                 )},  /* BRO */
	{0x650A, TEXT("Bose Corporation"                                                                        )},  /* BSE */
	{0x6C0A, TEXT("Biomedical Systems Laboratory"                                                           )},  /* BSL */
	{0x740A, TEXT("BodySound Technologies, Inc."                                                            )},  /* BST */
	{0x830A, TEXT("Bit 3 Computer"                                                                          )},  /* BTC */
	{0x850A, TEXT("Brilliant Technology"                                                                    )},  /* BTE */
	{0x860A, TEXT("Bitfield Oy"                                                                             )},  /* BTF */
	{0x890A, TEXT("BusTech Inc"                                                                             )},  /* BTI */
	{0xA60A, TEXT("Yasuhiko Shirai Melco Inc"                                                               )},  /* BUF */
	{0xAA0A, TEXT("ATI Tech Inc"                                                                            )},  /* BUJ */
	{0xAC0A, TEXT("Bull"                                                                                    )},  /* BUL */
	{0xB20A, TEXT("Bernecker & Rainer Ind-Eletronik GmbH"                                                   )},  /* BUR */
	{0xB30A, TEXT("BusTek"                                                                                  )},  /* BUS */
	{0xB40A, TEXT("21ST CENTURY ENTERTAINMENT"                                                              )},  /* BUT */
	{0xEB0A, TEXT("Bitworks Inc."                                                                           )},  /* BWK */
	{0x050B, TEXT("Buxco Electronics"                                                                       )},  /* BXE */
	{0x240B, TEXT("byd:sign corporation"                                                                    )},  /* BYD */
	{0x210C, TEXT("Castles Automation Co., Ltd"                                                             )},  /* CAA */
	{0x230C, TEXT("CA & F Elettronica"                                                                      )},  /* CAC */
	{0x270C, TEXT("CalComp"                                                                                 )},  /* CAG */
	{0x290C, TEXT("Canon Inc."                                                                              )},  /* CAI */
	{0x2C0C, TEXT("Acon"                                                                                    )},  /* CAL */
	{0x2D0C, TEXT("Cambridge Audio"                                                                         )},  /* CAM */
	{0x2E0C, TEXT("Canopus Company Ltd"                                                                     )},  /* CAN */
	{0x2E0C, TEXT("Canopus Company Ltd"                                                                     )},  /* CAN */
	{0x2E0C, TEXT("Canopus Company Ltd"                                                                     )},  /* CAN */
	{0x320C, TEXT("Cardinal Company Ltd"                                                                    )},  /* CAR */
	{0x330C, TEXT("CASIO COMPUTER CO.,LTD"                                                                  )},  /* CAS */
	{0x340C, TEXT("Consultancy in Advanced Technology"                                                      )},  /* CAT */
	{0x490C, TEXT("ComputerBoards Inc"                                                                      )},  /* CBI */
	{0x520C, TEXT("Cebra Tech A/S"                                                                          )},  /* CBR */
	{0x580C, TEXT("Cybex Computer Products Corporation"                                                     )},  /* CBX */
	{0x630C, TEXT("C-Cube Microsystems"                                                                     )},  /* CCC */
	{0x690C, TEXT("Cache"                                                                                   )},  /* CCI */
	{0x6A0C, TEXT("CONTEC CO.,LTD."                                                                         )},  /* CCJ */
	{0x6C0C, TEXT("CCL/ITRI"                                                                                )},  /* CCL */
	{0x700C, TEXT("Capetronic USA Inc"                                                                      )},  /* CCP */
	{0x830C, TEXT("Core Dynamics Corporation"                                                               )},  /* CDC */
	{0x840C, TEXT("Convergent Data Devices"                                                                 )},  /* CDD */
	{0x850C, TEXT("Colin.de"                                                                                )},  /* CDE */
	{0x870C, TEXT("Christie Digital Systems Inc"                                                            )},  /* CDG */
	{0x890C, TEXT("Concept Development Inc"                                                                 )},  /* CDI */
	{0x8B0C, TEXT("Cray Communications"                                                                     )},  /* CDK */
	{0x8E0C, TEXT("Codenoll Technical Corporation"                                                          )},  /* CDN */
	{0x900C, TEXT("CalComp"                                                                                 )},  /* CDP */
	{0x930C, TEXT("Computer Diagnostic Systems"                                                             )},  /* CDS */
	{0x940C, TEXT("IBM Corporation"                                                                         )},  /* CDT */
	{0x960C, TEXT("Convergent Design Inc."                                                                  )},  /* CDV */
	{0xA10C, TEXT("Consumer Electronics Association"                                                        )},  /* CEA */
	{0xA30C, TEXT("Chicony Electronics Company Ltd"                                                         )},  /* CEC */
	{0xA40C, TEXT("Cambridge Electronic Design Ltd"                                                         )},  /* CED */
	{0xA60C, TEXT("Cefar Digital Vision"                                                                    )},  /* CEF */
	{0xA90C, TEXT("Crestron Electronics, Inc."                                                              )},  /* CEI */
	{0xAD0C, TEXT("MEC Electronics GmbH"                                                                    )},  /* CEM */
	{0xAE0C, TEXT("Centurion Technologies P/L"                                                              )},  /* CEN */
	{0xB00C, TEXT("C-DAC"                                                                                   )},  /* CEP */
	{0xB20C, TEXT("Ceronix"                                                                                 )},  /* CER */
	{0xB40C, TEXT("TEC CORPORATION"                                                                         )},  /* CET */
	{0xC70C, TEXT("Atlantis"                                                                                )},  /* CFG */
	{0xE10C, TEXT("Chunghwa Picture Tubes, LTD"                                                             )},  /* CGA */
	{0xF30C, TEXT("Chyron Corp"                                                                             )},  /* CGS */
	{0x010D, TEXT("Chase Research PLC"                                                                      )},  /* CHA */
	{0x030D, TEXT("Chic Technology Corp."                                                                   )},  /* CHC */
	{0x040D, TEXT("ChangHong Electric Co.,Ltd"                                                              )},  /* CHD */
	{0x050D, TEXT("Acer Inc"                                                                                )},  /* CHE */
	{0x070D, TEXT("Sichuan Changhong Electric CO, LTD."                                                     )},  /* CHG */
	{0x090D, TEXT("Chrontel Inc"                                                                            )},  /* CHI */
	{0x0C0D, TEXT("Chloride-R&D"                                                                            )},  /* CHL */
	{0x0D0D, TEXT("CHIC TECHNOLOGY CORP."                                                                   )},  /* CHM */
	{0x0F0D, TEXT("Sichuang Changhong Corporation"                                                          )},  /* CHO */
	{0x100D, TEXT("CH Products"                                                                             )},  /* CHP */
	{0x130D, TEXT("Agentur Chairos"                                                                         )},  /* CHS */
	{0x140D, TEXT("Chunghwa Picture Tubes,LTD."                                                             )},  /* CHT */
	{0x190D, TEXT("Cherry GmbH"                                                                             )},  /* CHY */
	{0x230D, TEXT("Comm. Intelligence Corporation"                                                          )},  /* CIC */
	{0x290D, TEXT("Cromack Industries Inc"                                                                  )},  /* CII */
	{0x2C0D, TEXT("Citicom Infotech Private Limited"                                                        )},  /* CIL */
	{0x2E0D, TEXT("Citron GmbH"                                                                             )},  /* CIN */
	{0x300D, TEXT("Ciprico Inc"                                                                             )},  /* CIP */
	{0x320D, TEXT("Cirrus Logic Inc"                                                                        )},  /* CIR */
	{0x330D, TEXT("Cisco Systems Inc"                                                                       )},  /* CIS */
	{0x340D, TEXT("Citifax Limited"                                                                         )},  /* CIT */
	{0x630D, TEXT("The Concept Keyboard Company Ltd"                                                        )},  /* CKC */
	{0x810D, TEXT("Clarion Company Ltd"                                                                     )},  /* CLA */
	{0x840D, TEXT("COMMAT L.t.d."                                                                           )},  /* CLD */
	{0x850D, TEXT("Classe Audio"                                                                            )},  /* CLE */
	{0x870D, TEXT("CoreLogic"                                                                               )},  /* CLG */
	{0x890D, TEXT("Cirrus Logic Inc"                                                                        )},  /* CLI */
	{0x8D0D, TEXT("CrystaLake Multimedia"                                                                   )},  /* CLM */
	{0x8F0D, TEXT("Clone Computers"                                                                         )},  /* CLO */
	{0x940D, TEXT("automated computer control systems"                                                      )},  /* CLT */
	{0x960D, TEXT("Clevo Company"                                                                           )},  /* CLV */
	{0x980D, TEXT("CardLogix"                                                                               )},  /* CLX */
	{0xA30D, TEXT("CMC Ltd"                                                                                 )},  /* CMC */
	{0xA40D, TEXT("Colorado MicroDisplay, Inc."                                                             )},  /* CMD */
	{0xA70D, TEXT("Chenming Mold Ind. Corp."                                                                )},  /* CMG */
	{0xA90D, TEXT("C-Media Electronics"                                                                     )},  /* CMI */
	{0xAD0D, TEXT("Comtime GmbH"                                                                            )},  /* CMM */
	{0xAF0D, TEXT("Chi Mei Optoelectronics corp."                                                           )},  /* CMO */
	{0xB20D, TEXT("Cambridge Research Systems Ltd"                                                          )},  /* CMR */
	{0xB30D, TEXT("CompuMaster Srl"                                                                         )},  /* CMS */
	{0xB80D, TEXT("Comex Electronics AB"                                                                    )},  /* CMX */
	{0xC20D, TEXT("American Power Conversion"                                                               )},  /* CNB */
	{0xC30D, TEXT("Alvedon Computers Ltd"                                                                   )},  /* CNC */
	{0xC50D, TEXT("Cine-tal"                                                                                )},  /* CNE */
	{0xC90D, TEXT("Connect Int'l A/S"                                                                       )},  /* CNI */
	{0xCE0D, TEXT("Canon Inc"                                                                               )},  /* CNN */
	{0xD40D, TEXT("COINT Multimedia Systems"                                                                )},  /* CNT */
	{0xE20D, TEXT("COBY Electronics Co., Ltd"                                                               )},  /* COB */
	{0xE40D, TEXT("CODAN Pty. Ltd."                                                                         )},  /* COD */
	{0xE90D, TEXT("Codec Inc."                                                                              )},  /* COI */
	{0xEC0D, TEXT("Rockwell Collins, Inc."                                                                  )},  /* COL */
	{0xED0D, TEXT("Comtrol Corporation"                                                                     )},  /* COM */
	{0xEE0D, TEXT("Contec Company Ltd"                                                                      )},  /* CON */
	{0xF20D, TEXT("Corollary Inc"                                                                           )},  /* COR */
	{0xF30D, TEXT("CoStar Corporation"                                                                      )},  /* COS */
	{0xF40D, TEXT("Core Technology Inc"                                                                     )},  /* COT */
	{0xF70D, TEXT("Polycow Productions"                                                                     )},  /* COW */
	{0x030E, TEXT("Ciprico Inc"                                                                             )},  /* CPC */
	{0x040E, TEXT("CompuAdd"                                                                                )},  /* CPD */
	{0x090E, TEXT("Computer Peripherals Inc"                                                                )},  /* CPI */
	{0x0C0E, TEXT("Compal Electronics Inc"                                                                  )},  /* CPL */
	{0x110E, TEXT("Compaq Computer Company"                                                                 )},  /* CPQ */
	{0x140E, TEXT("cPATH"                                                                                   )},  /* CPT */
	{0x180E, TEXT("Powermatic Data Systems"                                                                 )},  /* CPX */
	{0x430E, TEXT("CONRAC GmbH"                                                                             )},  /* CRC */
	{0x440E, TEXT("Cardinal Technical Inc"                                                                  )},  /* CRD */
	{0x450E, TEXT("Creative Labs Inc"                                                                       )},  /* CRE */
	{0x490E, TEXT("Crio Inc."                                                                               )},  /* CRI */
	{0x4C0E, TEXT("Creative Logic  "                                                                        )},  /* CRL */
	{0x4E0E, TEXT("Cornerstone Imaging"                                                                     )},  /* CRN */
	{0x4F0E, TEXT("Extraordinary Technologies PTY Limited"                                                  )},  /* CRO */
	{0x510E, TEXT("Cirque Corporation"                                                                      )},  /* CRQ */
	{0x530E, TEXT("Crescendo Communication Inc"                                                             )},  /* CRS */
	{0x580E, TEXT("Cyrix Corporation"                                                                       )},  /* CRX */
	{0x620E, TEXT("Transtex SA"                                                                             )},  /* CSB */
	{0x630E, TEXT("Crystal Semiconductor"                                                                   )},  /* CSC */
	{0x640E, TEXT("Cresta Systems Inc"                                                                      )},  /* CSD */
	{0x650E, TEXT("Concept Solutions & Engineering"                                                         )},  /* CSE */
	{0x690E, TEXT("Cabletron System Inc"                                                                    )},  /* CSI */
	{0x6F0E, TEXT("California Institute of Technology"                                                      )},  /* CSO */
	{0x730E, TEXT("CSS Laboratories"                                                                        )},  /* CSS */
	{0x740E, TEXT("CSTI Inc"                                                                                )},  /* CST */
	{0x810E, TEXT("CoSystems Inc"                                                                           )},  /* CTA */
	{0x830E, TEXT("CTC Communication Development Company Ltd"                                               )},  /* CTC */
	{0x850E, TEXT("Chunghwa Telecom Co., Ltd."                                                              )},  /* CTE */
	{0x8C0E, TEXT("Creative Technology Ltd"                                                                 )},  /* CTL */
	{0x8D0E, TEXT("Computerm Corporation"                                                                   )},  /* CTM */
	{0x8E0E, TEXT("Computone Products"                                                                      )},  /* CTN */
	{0x900E, TEXT("Computer Technology Corporation"                                                         )},  /* CTP */
	{0x930E, TEXT("Comtec Systems Co., Ltd."                                                                )},  /* CTS */
	{0x980E, TEXT("Creatix Polymedia GmbH"                                                                  )},  /* CTX */
	{0xA20E, TEXT("Cubix Corporation"                                                                       )},  /* CUB */
	{0xAB0E, TEXT("Calibre UK Ltd"                                                                          )},  /* CUK */
	{0xD30E, TEXT("Clarity Visual Systems"                                                                  )},  /* CVS */
	{0xF20E, TEXT("Connectware Inc"                                                                         )},  /* CWR */
	{0x140F, TEXT("Conexant Systems"                                                                        )},  /* CXT */
	{0x220F, TEXT("CyberVision"                                                                             )},  /* CYB */
	{0x230F, TEXT("Cylink Corporation"                                                                      )},  /* CYC */
	{0x240F, TEXT("Cyclades Corporation"                                                                    )},  /* CYD */
	{0x2C0F, TEXT("Cyberlabs"                                                                               )},  /* CYL */
	{0x340F, TEXT("Cytechinfo Inc"                                                                          )},  /* CYT */
	{0x360F, TEXT("Cyviz AS"                                                                                )},  /* CYV */
	{0x370F, TEXT("Cyberware"                                                                               )},  /* CYW */
	{0x380F, TEXT("Cyrix Corporation"                                                                       )},  /* CYX */
	{0x2310, TEXT("Digital Acoustics Corporation"                                                           )},  /* DAC */
	{0x2510, TEXT("Digatron Industrie Elektronik GmbH"                                                      )},  /* DAE */
	{0x2910, TEXT("DAIS SET Ltd."                                                                           )},  /* DAI */
	{0x2B10, TEXT("Daktronics"                                                                              )},  /* DAK */
	{0x2C10, TEXT("Digital Audio Labs Inc"                                                                  )},  /* DAL */
	{0x3310, TEXT("DAVIS AS"                                                                                )},  /* DAS */
	{0x3410, TEXT("Datel Inc"                                                                               )},  /* DAT */
	{0x3510, TEXT("Daou Tech Inc"                                                                           )},  /* DAU */
	{0x3610, TEXT("Davicom Semiconductor Inc"                                                               )},  /* DAV */
	{0x3710, TEXT("DA2 Technologies Inc"                                                                    )},  /* DAW */
	{0x3810, TEXT("Data Apex Ltd"                                                                           )},  /* DAX */
	{0x4410, TEXT("Diebold Inc."                                                                            )},  /* DBD */
	{0x4910, TEXT("DigiBoard Inc"                                                                           )},  /* DBI */
	{0x4B10, TEXT("Databook Inc"                                                                            )},  /* DBK */
	{0x4C10, TEXT("Doble Engineering Company"                                                               )},  /* DBL */
	{0x4E10, TEXT("DB Networks Inc"                                                                         )},  /* DBN */
	{0x6110, TEXT("Digital Communications Association"                                                      )},  /* DCA */
	{0x6310, TEXT("Dale Computer Corporation"                                                               )},  /* DCC */
	{0x6410, TEXT("Datacast LLC"                                                                            )},  /* DCD */
	{0x6510, TEXT("dSPACE GmbH"                                                                             )},  /* DCE */
	{0x6910, TEXT("Concepts Inc"                                                                            )},  /* DCI */
	{0x6C10, TEXT("Dynamic Controls Ltd"                                                                    )},  /* DCL */
	{0x6D10, TEXT("DCM Data Products"                                                                       )},  /* DCM */
	{0x6F10, TEXT("Dialogue Technology Corporation"                                                         )},  /* DCO */
	{0x7210, TEXT("Decros Ltd"                                                                              )},  /* DCR */
	{0x7310, TEXT("Diamond Computer Systems Inc"                                                            )},  /* DCS */
	{0x7410, TEXT("Dancall Telecom A/S"                                                                     )},  /* DCT */
	{0x7610, TEXT("Datatronics Technology Inc"                                                              )},  /* DCV */
	{0x8110, TEXT("DA2 Technologies Corporation"                                                            )},  /* DDA */
	{0x8410, TEXT("Danka Data Devices"                                                                      )},  /* DDD */
	{0x8910, TEXT("Data Display AG"                                                                         )},  /* DDI */
	{0x9310, TEXT("Barco, n.v."                                                                             )},  /* DDS */
	{0x9410, TEXT("Datadesk Technologies Inc"                                                               )},  /* DDT */
	{0xA310, TEXT("Digital Equipment Corporation"                                                           )},  /* DEC */
	{0xA910, TEXT("Deico Electronics"                                                                       )},  /* DEI */
	{0xAC10, TEXT("Deltec Corporation"                                                                      )},  /* DEL */
	{0xAE10, TEXT("Densitron Computers Ltd"                                                                 )},  /* DEN */
	{0xB810, TEXT("idex displays"                                                                           )},  /* DEX */
	{0xC910, TEXT("DFI"                                                                                     )},  /* DFI */
	{0xCB10, TEXT("SharkTec A/S"                                                                            )},  /* DFK */
	{0xE110, TEXT("Digiital Arts Inc"                                                                       )},  /* DGA */
	{0xE310, TEXT("Data General Corporation"                                                                )},  /* DGC */
	{0xE910, TEXT("DIGI International"                                                                      )},  /* DGI */
	{0xEB10, TEXT("DugoTech Co., LTD"                                                                       )},  /* DGK */
	{0xF010, TEXT("Digicorp European sales S.A."                                                            )},  /* DGP */
	{0xF310, TEXT("Diagsoft Inc"                                                                            )},  /* DGS */
	{0xF410, TEXT("The Dearborn Group"                                                                      )},  /* DGT */
	{0xF410, TEXT("The Dearborn Group"                                                                      )},  /* DGT */
	{0x1011, TEXT("DH Print"                                                                                )},  /* DHP */
	{0x1111, TEXT("Quadram"                                                                                 )},  /* DHQ */
	{0x1411, TEXT("Projectavision Inc"                                                                      )},  /* DHT */
	{0x2111, TEXT("Diadem"                                                                                  )},  /* DIA */
	{0x2711, TEXT("Digicom S.p.A."                                                                          )},  /* DIG */
	{0x2911, TEXT("Dataq Instruments Inc"                                                                   )},  /* DII */
	{0x2D11, TEXT("dPict Imaging, Inc."                                                                     )},  /* DIM */
	{0x2E11, TEXT("Daintelecom Co., Ltd"                                                                    )},  /* DIN */
	{0x3311, TEXT("Diseda S.A."                                                                             )},  /* DIS */
	{0x3411, TEXT("Dragon Information Technology"                                                           )},  /* DIT */
	{0x4511, TEXT("Capstone Visua lProduct Development "                                                    )},  /* DJE */
	{0x5011, TEXT("Maygay Machines, Ltd"                                                                    )},  /* DJP */
	{0x7911, TEXT("Datakey Inc"                                                                             )},  /* DKY */
	{0x8311, TEXT("Diamond Lane Comm. Corporation"                                                          )},  /* DLC */
	{0x8711, TEXT("Digital-Logic GmbH"                                                                      )},  /* DLG */
	{0x8B11, TEXT("D-Link Systems Inc"                                                                      )},  /* DLK */
	{0x9411, TEXT("Digitelec Informatique Park Cadera"                                                      )},  /* DLT */
	{0xA211, TEXT("Digicom Systems Inc"                                                                     )},  /* DMB */
	{0xA311, TEXT("Dune Microsystems Corporation"                                                           )},  /* DMC */
	{0xAD11, TEXT("Dimond Multimedia Systems Inc"                                                           )},  /* DMM */
	{0xB011, TEXT("D&M Holdings Inc, Professional Business Company"                                         )},  /* DMP */
	{0xB311, TEXT("DOME imaging systems"                                                                    )},  /* DMS */
	{0xB611, TEXT("NDS Ltd"                                                                                 )},  /* DMV */
	{0xC111, TEXT("DNA Enterprises, Inc."                                                                   )},  /* DNA */
	{0xC711, TEXT("Apache Micro Peripherals Inc"                                                            )},  /* DNG */
	{0xC911, TEXT("Deterministic Networks Inc."                                                             )},  /* DNI */
	{0xD411, TEXT("Dr. Neuhous Telekommunikation GmbH"                                                      )},  /* DNT */
	{0xD611, TEXT("DiCon"                                                                                   )},  /* DNV */
	{0xEC11, TEXT("Dolman Technologies Group Inc"                                                           )},  /* DOL */
	{0xED11, TEXT("Dome Imaging Systems"                                                                    )},  /* DOM */
	{0xEE11, TEXT("DENON, Ltd."                                                                             )},  /* DON */
	{0xF411, TEXT("Dotronic Mikroelektronik GmbH"                                                           )},  /* DOT */
	{0x0112, TEXT("DigiTalk Pro AV"                                                                         )},  /* DPA */
	{0x0312, TEXT("Delta Electronics Inc"                                                                   )},  /* DPC */
	{0x0912, TEXT("DocuPoint"                                                                               )},  /* DPI */
	{0x0C12, TEXT("Digital Projection Limited"                                                              )},  /* DPL */
	{0x0D12, TEXT("ADPM Synthesis sas"                                                                      )},  /* DPM */
	{0x1312, TEXT("Digital Processing Systems"                                                              )},  /* DPS */
	{0x1412, TEXT("DPT"                                                                                     )},  /* DPT */
	{0x1812, TEXT("DpiX, Inc."                                                                              )},  /* DPX */
	{0x2212, TEXT("Datacube Inc"                                                                            )},  /* DQB */
	{0x4212, TEXT("Dr. Bott KG"                                                                             )},  /* DRB */
	{0x4312, TEXT("Data Ray Corp."                                                                          )},  /* DRC */
	{0x4412, TEXT("DIGITAL REFLECTION INC."                                                                 )},  /* DRD */
	{0x4912, TEXT("Data Race Inc"                                                                           )},  /* DRI */
	{0x6412, TEXT("DS Multimedia Pte Ltd"                                                                   )},  /* DSD */
	{0x6912, TEXT("Digitan Systems Inc"                                                                     )},  /* DSI */
	{0x6D12, TEXT("DSM Digital Services GmbH"                                                               )},  /* DSM */
	{0x7012, TEXT("Domain Technology Inc"                                                                   )},  /* DSP */
	{0x8112, TEXT("DELTATEC "                                                                               )},  /* DTA */
	{0x8312, TEXT("DTC Tech Corporation"                                                                    )},  /* DTC */
	{0x8912, TEXT("Diversified Technology, Inc."                                                            )},  /* DTI */
	{0x8B12, TEXT("Dynax Electronics (HK) Ltd"                                                              )},  /* DTK */
	{0x8C12, TEXT("e-Net Inc"                                                                               )},  /* DTL */
	{0x8E12, TEXT("Datang  Telephone Co"                                                                    )},  /* DTN */
	{0x8F12, TEXT("Deutsche Thomson OHG"                                                                    )},  /* DTO */
	{0x9812, TEXT("Data Translation"                                                                        )},  /* DTX */
	{0xA112, TEXT("Dosch & Amand GmbH & Company KG"                                                         )},  /* DUA */
	{0xAE12, TEXT("NCR Corporation"                                                                         )},  /* DUN */
	{0xC412, TEXT("Dictaphone Corporation"                                                                  )},  /* DVD */
	{0xCC12, TEXT("Devolo AG"                                                                               )},  /* DVL */
	{0xD312, TEXT("Digital Video System"                                                                    )},  /* DVS */
	{0xD412, TEXT("Data Video"                                                                              )},  /* DVT */
	{0xE512, TEXT("Daewoo Electronics Company Ltd"                                                          )},  /* DWE */
	{0x0313, TEXT("Digipronix Control Systems"                                                              )},  /* DXC */
	{0x1013, TEXT("Data Expert Corporation"                                                                 )},  /* DXP */
	{0x1313, TEXT("Signet"                                                                                  )},  /* DXS */
	{0x2313, TEXT("Dycam Inc"                                                                               )},  /* DYC */
	{0x2D13, TEXT("Dymo-CoStar Corporation"                                                                 )},  /* DYM */
	{0x2E13, TEXT("Askey Computer Corporation"                                                              )},  /* DYN */
	{0x3813, TEXT("Dynax Electronics (HK) Ltd"                                                              )},  /* DYX */
	{0x3314, TEXT("Evans and Sutherland Computer"                                                           )},  /* EAS */
	{0x4814, TEXT("Data Price Informatica"                                                                  )},  /* EBH */
	{0x5414, TEXT("HUALONG TECHNOLOGY CO., LTD"                                                             )},  /* EBT */
	{0x6114, TEXT("Electro Cam Corp."                                                                       )},  /* ECA */
	{0x6314, TEXT("ESSential Comm. Corporation"                                                             )},  /* ECC */
	{0x6914, TEXT("Enciris Technologies"                                                                    )},  /* ECI */
	{0x6B14, TEXT("Eugene Chukhlomin Sole Proprietorship, d.b.a. "                                          )},  /* ECK */
	{0x6C14, TEXT("Excel Company Ltd"                                                                       )},  /* ECL */
	{0x6D14, TEXT("E-Cmos Tech Corporation"                                                                 )},  /* ECM */
	{0x6F14, TEXT("Echo Speech Corporation"                                                                 )},  /* ECO */
	{0x7014, TEXT("Elecom Company Ltd"                                                                      )},  /* ECP */
	{0x7314, TEXT("Elitegroup Computer Systems Company Ltd"                                                 )},  /* ECS */
	{0x7414, TEXT("Enciris Technologies "                                                                   )},  /* ECT */
	{0x8314, TEXT("e.Digital Corporation"                                                                   )},  /* EDC */
	{0x8714, TEXT("Electronic-Design GmbH"                                                                  )},  /* EDG */
	{0x8914, TEXT("Edimax Tech. Company Ltd"                                                                )},  /* EDI */
	{0x8D14, TEXT("EDMI"                                                                                    )},  /* EDM */
	{0xA514, TEXT("ET&T Technology Company Ltd"                                                             )},  /* EEE */
	{0xA814, TEXT("EEH Datalink GmbH"                                                                       )},  /* EEH */
	{0xB014, TEXT("E.E.P.D. GmbH"                                                                           )},  /* EEP */
	{0xB314, TEXT("EE Solutions, Inc."                                                                      )},  /* EES */
	{0xE414, TEXT("EIZO GmbH Display Technologies "                                                         )},  /* EGD */
	{0xEC14, TEXT("Eagle Technology"                                                                        )},  /* EGL */
	{0xEE14, TEXT("Egenera, Inc."                                                                           )},  /* EGN */
	{0xEF14, TEXT("Ergo Electronics"                                                                        )},  /* EGO */
	{0x0A15, TEXT("Epson Research"                                                                          )},  /* EHJ */
	{0x2315, TEXT("Eicon Technology Corporation"                                                            )},  /* EIC */
	{0x6115, TEXT("MagTek Inc."                                                                             )},  /* EKA */
	{0x6315, TEXT("Eastman Kodak Company"                                                                   )},  /* EKC */
	{0x7315, TEXT("EKSEN YAZILIM"                                                                           )},  /* EKS */
	{0x8115, TEXT("ELAD srl"                                                                                )},  /* ELA */
	{0x8315, TEXT("Electro Scientific Ind"                                                                  )},  /* ELC */
	{0x8515, TEXT("Elecom Company Ltd"                                                                      )},  /* ELE */
	{0x8715, TEXT("Elmeg GmbH Kommunikationstechnik"                                                        )},  /* ELG */
	{0x8915, TEXT("Edsun Laboratories"                                                                      )},  /* ELI */
	{0x8C15, TEXT("Electrosonic Ltd"                                                                        )},  /* ELL */
	{0x8D15, TEXT("Elmic Systems Inc"                                                                       )},  /* ELM */
	{0x8F15, TEXT("Elo TouchSystems Inc"                                                                    )},  /* ELO */
	{0x8F15, TEXT("Elo TouchSystems Inc"                                                                    )},  /* ELO */
	{0x9315, TEXT("ELSA GmbH"                                                                               )},  /* ELS */
	{0x9415, TEXT("Element Labs, Inc."                                                                      )},  /* ELT */
	{0x9815, TEXT("Elonex PLC"                                                                              )},  /* ELX */
	{0xA215, TEXT("Embedded computing inc ltd"                                                              )},  /* EMB */
	{0xA315, TEXT("eMicro Corporation"                                                                      )},  /* EMC */
	{0xA515, TEXT("EMiNE TECHNOLOGY COMPANY, LTD."                                                          )},  /* EME */
	{0xA715, TEXT("EMG Consultants Inc"                                                                     )},  /* EMG */
	{0xA915, TEXT("Ex Machina Inc"                                                                          )},  /* EMI */
	{0xB515, TEXT("Emulex Corporation"                                                                      )},  /* EMU */
	{0xC315, TEXT("Eizo Nanao Corporation"                                                                  )},  /* ENC */
	{0xC415, TEXT("ENIDAN Technologies Ltd"                                                                 )},  /* END */
	{0xC515, TEXT("ENE Technology Inc."                                                                     )},  /* ENE */
	{0xC915, TEXT("Efficient Networks"                                                                      )},  /* ENI */
	{0xD315, TEXT("Ensoniq Corporation"                                                                     )},  /* ENS */
	{0xD415, TEXT("Enterprise Comm. & Computing Inc"                                                        )},  /* ENT */
	{0x0316, TEXT("Empac"                                                                                   )},  /* EPC */
	{0x0916, TEXT("Envision Peripherals, Inc"                                                               )},  /* EPI */
	{0x0E16, TEXT("EPiCON Inc."                                                                             )},  /* EPN */
	{0x1316, TEXT("KEPS"                                                                                    )},  /* EPS */
	{0x3016, TEXT("Equipe Electronics Ltd."                                                                 )},  /* EQP */
	{0x3816, TEXT("Equinox Systems Inc"                                                                     )},  /* EQX */
	{0x4716, TEXT("Ergo System"                                                                             )},  /* ERG */
	{0x4916, TEXT("Ericsson Mobile Communications AB"                                                       )},  /* ERI */
	{0x4E16, TEXT("Ericsson, Inc."                                                                          )},  /* ERN */
	{0x5016, TEXT("Euraplan GmbH"                                                                           )},  /* ERP */
	{0x5416, TEXT("Escort Insturments Corporation"                                                          )},  /* ERT */
	{0x6316, TEXT("Eden Sistemas de Computacao S/A"                                                         )},  /* ESC */
	{0x6716, TEXT("ELCON Systemtechnik GmbH"                                                                )},  /* ESG */
	{0x6916, TEXT("Extended Systems, Inc."                                                                  )},  /* ESI */
	{0x6B16, TEXT("ES&S"                                                                                    )},  /* ESK */
	{0x7316, TEXT("ESS Technology Inc"                                                                      )},  /* ESS */
	{0x7416, TEXT("Embedded Solution Technology"                                                            )},  /* EST */
	{0x7916, TEXT("E-Systems Inc"                                                                           )},  /* ESY */
	{0x8316, TEXT("Everton Technology Company Ltd"                                                          )},  /* ETC */
	{0x8916, TEXT("Eclipse Tech Inc"                                                                        )},  /* ETI */
	{0x8B16, TEXT("eTEK Labs Inc."                                                                          )},  /* ETK */
	{0x8C16, TEXT("Evertz Microsystems Ltd."                                                                )},  /* ETL */
	{0x9316, TEXT("Electronic Trade Solutions Ltd"                                                          )},  /* ETS */
	{0x9416, TEXT("E-Tech Inc"                                                                              )},  /* ETT */
	{0xB416, TEXT("Ericsson Mobile Networks B.V."                                                           )},  /* EUT */
	{0xC916, TEXT("eviateg GmbH"                                                                            )},  /* EVI */
	{0xD816, TEXT("Everex"                                                                                  )},  /* EVX */
	{0x0117, TEXT("Exabyte"                                                                                 )},  /* EXA */
	{0x0317, TEXT("Excession Audio"                                                                         )},  /* EXC */
	{0x0917, TEXT("Exide Electronics"                                                                       )},  /* EXI */
	{0x0E17, TEXT("RGB Systems, Inc. dba Extron Electronics"                                                )},  /* EXN */
	{0x1017, TEXT("Data Export Corporation"                                                                 )},  /* EXP */
	{0x1417, TEXT("Exatech Computadores & Servicos Ltda"                                                    )},  /* EXT */
	{0x1817, TEXT("Exxact GmbH"                                                                             )},  /* EXX */
	{0x1917, TEXT("Exterity Ltd"                                                                            )},  /* EXY */
	{0x4517, TEXT("EzE Technologies"                                                                        )},  /* EZE */
	{0x5017, TEXT("Storm Technology"                                                                        )},  /* EZP */
	{0x3218, TEXT("Farallon Computing"                                                                      )},  /* FAR */
	{0x4918, TEXT("Interface Corporation"                                                                   )},  /* FBI */
	{0x6218, TEXT("Furukawa Electric Company Ltd"                                                           )},  /* FCB */
	{0x6718, TEXT("First International Computer Ltd"                                                        )},  /* FCG */
	{0x7318, TEXT("Focus Enhancements, Inc."                                                                )},  /* FCS */
	{0x8318, TEXT("Future Domain"                                                                           )},  /* FDC */
	{0x9418, TEXT("Fujitsu Display Technologies Corp."                                                      )},  /* FDT */
	{0xA318, TEXT("FURUNO ELECTRIC CO., LTD."                                                               )},  /* FEC */
	{0xAC18, TEXT("Fellowes & Questec"                                                                      )},  /* FEL */
	{0xB218, TEXT("Ferranti Int'L"                                                                          )},  /* FER */
	{0xC918, TEXT("Fairfield Industries"                                                                    )},  /* FFI */
	{0xE418, TEXT("Lisa Draexlmaier GmbH"                                                                   )},  /* FGD */
	{0xEC18, TEXT("Fujitsu General Limited."                                                                )},  /* FGL */
	{0x0C19, TEXT("FHLP"                                                                                    )},  /* FHL */
	{0x2319, TEXT("Formosa Industrial Computing Inc"                                                        )},  /* FIC */
	{0x2C19, TEXT("Forefront Int'l Ltd"                                                                     )},  /* FIL */
	{0x2E19, TEXT("Finecom Co., Ltd."                                                                       )},  /* FIN */
	{0x3219, TEXT("Chaplet Systems Inc"                                                                     )},  /* FIR */
	{0x3319, TEXT("FLY-IT Simulators"                                                                       )},  /* FIS */
	{0x4319, TEXT("Fujitsu Takamisawa Component Limited"                                                    )},  /* FJC */
	{0x5319, TEXT("Fujitsu Spain"                                                                           )},  /* FJS */
	{0x5419, TEXT("F.J. Tieman BV"                                                                          )},  /* FJT */
	{0x8919, TEXT("Faroudja Laboratories"                                                                   )},  /* FLI */
	{0x9919, TEXT("Butterfly Communications"                                                                )},  /* FLY */
	{0xA119, TEXT("Fast Multimedia AG"                                                                      )},  /* FMA */
	{0xA319, TEXT("Ford Microelectronics Inc"                                                               )},  /* FMC */
	{0xA919, TEXT("Fujitsu Microelect Inc"                                                                  )},  /* FMI */
	{0xA919, TEXT("Fujitsu Microelect Inc"                                                                  )},  /* FMI */
	{0xAC19, TEXT("Fujitsu Microelect Ltd"                                                                  )},  /* FML */
	{0xBA19, TEXT("Formoza-Altair"                                                                          )},  /* FMZ */
	{0xC319, TEXT("Fanuc LTD"                                                                               )},  /* FNC */
	{0xC919, TEXT("Funai Electric Co., Ltd."                                                                )},  /* FNI */
	{0xE119, TEXT("FOR-A Company Limited"                                                                   )},  /* FOA */
	{0xF319, TEXT("Foss Tecator"                                                                            )},  /* FOS */
	{0x051A, TEXT("Fujitsu Peripherals Ltd"                                                                 )},  /* FPE */
	{0x131A, TEXT("Deltec Corporation"                                                                      )},  /* FPS */
	{0x181A, TEXT("Cirel Systemes"                                                                          )},  /* FPX */
	{0x431A, TEXT("Force Computers"                                                                         )},  /* FRC */
	{0x441A, TEXT("Freedom Scientific BLV"                                                                  )},  /* FRD */
	{0x451A, TEXT("Forvus Research Inc"                                                                     )},  /* FRE */
	{0x491A, TEXT("Fibernet Research Inc"                                                                   )},  /* FRI */
	{0x531A, TEXT("South Mountain Technologies, LTD"                                                        )},  /* FRS */
	{0x631A, TEXT("Future Systems Consulting KK"                                                            )},  /* FSC */
	{0x691A, TEXT("Fore Systems Inc"                                                                        )},  /* FSI */
	{0x741A, TEXT("Modesto PC Inc"                                                                          )},  /* FST */
	{0x831A, TEXT("Futuretouch Corporation"                                                                 )},  /* FTC */
	{0x851A, TEXT("Frontline Test Equipment Inc."                                                           )},  /* FTE */
	{0x871A, TEXT("FTG Data Systems"                                                                        )},  /* FTG */
	{0x891A, TEXT("FastPoint Technologies, Inc."                                                            )},  /* FTI */
	{0x8E1A, TEXT("Fountain Technologies Inc"                                                               )},  /* FTN */
	{0x921A, TEXT("Mediasonic"                                                                              )},  /* FTR */
	{0xAA1A, TEXT("Fujitsu Ltd"                                                                             )},  /* FUJ */
	{0xAE1A, TEXT("sisel muhendislik"                                                                       )},  /* FUN */
	{0xB31A, TEXT("Fujitsu Siemens Computers GmbH"                                                          )},  /* FUS */
	{0xC31A, TEXT("First Virtual Corporation"                                                               )},  /* FVC */
	{0xD81A, TEXT("C-C-C Group Plc"                                                                         )},  /* FVX */
	{0xF21A, TEXT("Flat Connections Inc"                                                                    )},  /* FWR */
	{0x181B, TEXT("Fuji Xerox"                                                                              )},  /* FXX */
	{0x431B, TEXT("Founder Group Shenzhen Co."                                                              )},  /* FZC */
	{0x491B, TEXT("FZI Forschungszentrum Informatik"                                                        )},  /* FZI */
	{0x271C, TEXT("Gage Applied Sciences Inc"                                                               )},  /* GAG */
	{0x2C1C, TEXT("Galil Motion Control"                                                                    )},  /* GAL */
	{0x351C, TEXT("Gaudi Co., Ltd."                                                                         )},  /* GAU */
	{0x631C, TEXT("GCC Technologies Inc"                                                                    )},  /* GCC */
	{0x691C, TEXT("Gateway Comm. Inc"                                                                       )},  /* GCI */
	{0x731C, TEXT("Grey Cell Systems Ltd"                                                                   )},  /* GCS */
	{0x831C, TEXT("General Datacom"                                                                         )},  /* GDC */
	{0x891C, TEXT("G. Diehl ISDN GmbH"                                                                      )},  /* GDI */
	{0x931C, TEXT("GDS"                                                                                     )},  /* GDS */
	{0x941C, TEXT("Vortex Computersysteme GmbH"                                                             )},  /* GDT */
	{0xA61C, TEXT("GE Fanuc Embedded Systems"                                                               )},  /* GEF */
	{0xAD1C, TEXT("Gem Plus"                                                                                )},  /* GEM */
	{0xAE1C, TEXT("Genesys ATE Inc"                                                                         )},  /* GEN */
	{0xAF1C, TEXT("GEO Sense"                                                                               )},  /* GEO */
	{0xB31C, TEXT("GES Singapore Pte Ltd"                                                                   )},  /* GES */
	{0xCD1C, TEXT("GFMesstechnik GmbH"                                                                      )},  /* GFM */
	{0xCE1C, TEXT("Gefen Inc."                                                                              )},  /* GFN */
	{0x231D, TEXT("General Inst. Corporation"                                                               )},  /* GIC */
	{0x2D1D, TEXT("Guillemont International"                                                                )},  /* GIM */
	{0x331D, TEXT("AT&T Global Info Solutions"                                                              )},  /* GIS */
	{0x4E1D, TEXT("Grand Junction Networks"                                                                 )},  /* GJN */
	{0x851D, TEXT("AD electronics"                                                                          )},  /* GLE */
	{0x8D1D, TEXT("Genesys Logic"                                                                           )},  /* GLM */
	{0x931D, TEXT("Gadget Labs LLC"                                                                         )},  /* GLS */
	{0xAB1D, TEXT("GMK Electronic Design GmbH"                                                              )},  /* GMK */
	{0xAC1D, TEXT("General Information Systems"                                                             )},  /* GML */
	{0xAD1D, TEXT("GMM Research Inc"                                                                        )},  /* GMM */
	{0xAE1D, TEXT("GEMINI 2000 Ltd"                                                                         )},  /* GMN */
	{0xB81D, TEXT("GMX Inc"                                                                                 )},  /* GMX */
	{0xC41D, TEXT("Gennum Corporation"                                                                      )},  /* GND */
	{0xCE1D, TEXT("GN Nettest Inc"                                                                          )},  /* GNN */
	{0xDA1D, TEXT("Gunze Ltd"                                                                               )},  /* GNZ */
	{0x411E, TEXT("Graphica Computer"                                                                       )},  /* GRA */
	{0x451E, TEXT("GOLD RAIN ENTERPRISES CORP."                                                             )},  /* GRE */
	{0x481E, TEXT("Granch Ltd"                                                                              )},  /* GRH */
	{0x561E, TEXT("Advanced Gravis"                                                                         )},  /* GRV */
	{0x591E, TEXT("Robert Gray Company"                                                                     )},  /* GRY */
	{0x621E, TEXT("NIPPONDENCHI CO,.LTD"                                                                    )},  /* GSB */
	{0x631E, TEXT("General Standards Corporation"                                                           )},  /* GSC */
	{0x6D1E, TEXT("Goldstar Company Ltd"                                                                    )},  /* GSM */
	{0x741E, TEXT("Graphic SystemTechnology"                                                                )},  /* GST */
	{0x791E, TEXT("Grossenbacher Systeme AG"                                                                )},  /* GSY */
	{0x831E, TEXT("Graphtec Corporation"                                                                    )},  /* GTC */
	{0x891E, TEXT("Goldtouch"                                                                               )},  /* GTI */
	{0x8B1E, TEXT("G-Tech Corporation"                                                                      )},  /* GTK */
	{0x8D1E, TEXT("Garnet System Company Ltd"                                                               )},  /* GTM */
	{0x931E, TEXT("Geotest Marvin Test Systems Inc"                                                         )},  /* GTS */
	{0x941E, TEXT("General Touch Technology Co., Ltd."                                                      )},  /* GTT */
	{0xA41E, TEXT("Guntermann & Drunck GmbH"                                                                )},  /* GUD */
	{0xBA1E, TEXT("Guzik Technical Enterprises"                                                             )},  /* GUZ */
	{0xC31E, TEXT("GVC Corporation"                                                                         )},  /* GVC */
	{0xCC1E, TEXT("Global Village Communication"                                                            )},  /* GVL */
	{0xE91E, TEXT("GW Instruments"                                                                          )},  /* GWI */
	{0xF91E, TEXT("Gateway 2000"                                                                            )},  /* GWY */
	{0x451F, TEXT("GUNZE Limited"                                                                           )},  /* GZE */
	{0x2520, TEXT("Haider electronics"                                                                      )},  /* HAE */
	{0x2920, TEXT("Haivision Systems Inc."                                                                  )},  /* HAI */
	{0x2C20, TEXT("Halberthal"                                                                              )},  /* HAL */
	{0x2E20, TEXT("Hanchang System Corporation"                                                             )},  /* HAN */
	{0x3920, TEXT("Hayes Microcomputer Products Inc"                                                        )},  /* HAY */
	{0x6120, TEXT("DAT"                                                                                     )},  /* HCA */
	{0x6C20, TEXT("HCL America Inc"                                                                         )},  /* HCL */
	{0x6D20, TEXT("HCL Peripherals"                                                                         )},  /* HCM */
	{0x7020, TEXT("Hitachi Computer Products Inc"                                                           )},  /* HCP */
	{0x7720, TEXT("Hauppauge Computer Works Inc"                                                            )},  /* HCW */
	{0x8320, TEXT("HardCom Elektronik & Datateknik"                                                         )},  /* HDC */
	{0x8920, TEXT("HD-INFO d.o.o."                                                                          )},  /* HDI */
	{0x9620, TEXT("Holografika kft."                                                                        )},  /* HDV */
	{0xA320, TEXT("Hitachi Engineering Company Ltd"                                                         )},  /* HEC */
	{0xA320, TEXT("Hitachi Engineering Company Ltd"                                                         )},  /* HEC */
	{0xAC20, TEXT("Hitachi Micro Systems Europe Ltd"                                                        )},  /* HEL */
	{0xB220, TEXT("Ascom Business Systems"                                                                  )},  /* HER */
	{0xB420, TEXT("HETEC Datensysteme GmbH"                                                                 )},  /* HET */
	{0x0321, TEXT("HIRAKAWA HEWTECH CORP. "                                                                 )},  /* HHC */
	{0x2221, TEXT("Hibino Corporation"                                                                      )},  /* HIB */
	{0x2321, TEXT("Hitachi Information Technology Co., Ltd."                                                )},  /* HIC */
	{0x2B21, TEXT("Hikom Co., Ltd."                                                                         )},  /* HIK */
	{0x2C21, TEXT("Hilevel Technology"                                                                      )},  /* HIL */
	{0x3421, TEXT("Hitachi America Ltd"                                                                     )},  /* HIT */
	{0x4921, TEXT("Harris & Jeffries Inc"                                                                   )},  /* HJI */
	{0x6121, TEXT("HONKO MFG. CO., LTD."                                                                    )},  /* HKA */
	{0x6721, TEXT("Josef Heim KG"                                                                           )},  /* HKG */
	{0xA321, TEXT("Hualon Microelectric Corporation"                                                        )},  /* HMC */
	{0xAB21, TEXT("hmk Daten-System-Technik BmbH"                                                           )},  /* HMK */
	{0xB821, TEXT("HUMAX Co., Ltd."                                                                         )},  /* HMX */
	{0xD321, TEXT("Hughes Network Systems"                                                                  )},  /* HNS */
	{0xE221, TEXT("HOB Electronic GmbH"                                                                     )},  /* HOB */
	{0xE521, TEXT("Hosiden Corporation"                                                                     )},  /* HOE */
	{0xEC21, TEXT("Holoeye Photonics AG"                                                                    )},  /* HOL */
	{0x0322, TEXT("Hewlett Packard Co."                                                                     )},  /* HPC */
	{0x0422, TEXT("Hewlett Packard"                                                                         )},  /* HPD */
	{0x0922, TEXT("Headplay, Inc."                                                                          )},  /* HPI */
	{0x0B22, TEXT("HAMAMATSU PHOTONICS K.K."                                                                )},  /* HPK */
	{0x1122, TEXT("HP"                                                                                      )},  /* HPQ */
	{0x1222, TEXT("H.P.R. Electronics GmbH"                                                                 )},  /* HPR */
	{0x4322, TEXT("Hercules"                                                                                )},  /* HRC */
	{0x4522, TEXT("Qingdao Haier Electronics Co., Ltd."                                                     )},  /* HRE */
	{0x4C22, TEXT("Herolab GmbH"                                                                            )},  /* HRL */
	{0x5322, TEXT("Harris Semiconductor"                                                                    )},  /* HRS */
	{0x5422, TEXT("HERCULES"                                                                                )},  /* HRT */
	{0x6322, TEXT("Hagiwara Sys-Com Company Ltd"                                                            )},  /* HSC */
	{0x6D22, TEXT("AT&T Microelectronics"                                                                   )},  /* HSM */
	{0x8322, TEXT("Hitachi Ltd"                                                                             )},  /* HTC */
	{0x8922, TEXT("Hampshire Company, Inc."                                                                 )},  /* HTI */
	{0x8B22, TEXT("Holtek Microelectronics Inc"                                                             )},  /* HTK */
	{0x9822, TEXT("Hitex Systementwicklung GmbH"                                                            )},  /* HTX */
	{0xA222, TEXT("GAI-Tronics, A Hubbell Company"                                                          )},  /* HUB */
	{0xAD22, TEXT("IMP Electronics Ltd."                                                                    )},  /* HUM */
	{0xE122, TEXT("Harris Canada Inc"                                                                       )},  /* HWA */
	{0xE322, TEXT("DBA Hans Wedemeyer"                                                                      )},  /* HWC */
	{0xE422, TEXT("Highwater Designs Ltd"                                                                   )},  /* HWD */
	{0xF022, TEXT("Hewlett Packard"                                                                         )},  /* HWP */
	{0x0D23, TEXT("Hexium Ltd."                                                                             )},  /* HXM */
	{0x2323, TEXT("Hypercope Gmbh Aachen"                                                                   )},  /* HYC */
	{0x2F23, TEXT("HYC CO., LTD."                                                                           )},  /* HYO */
	{0x3023, TEXT("Hyphen Ltd"                                                                              )},  /* HYP */
	{0x3223, TEXT("Hypertec Pty Ltd"                                                                        )},  /* HYR */
	{0x3423, TEXT("Heng Yu Technology (HK) Limited"                                                         )},  /* HYT */
	{0x3623, TEXT("Hynix Semiconductor"                                                                     )},  /* HYV */
	{0x2624, TEXT("Institut f r angewandte Funksystemtechnik GmbH"                                          )},  /* IAF */
	{0x2924, TEXT("Integration Associates, Inc."                                                            )},  /* IAI */
	{0x3424, TEXT("IAT Germany GmbH"                                                                        )},  /* IAT */
	{0x4324, TEXT("Integrated Business Systems"                                                             )},  /* IBC */
	{0x4924, TEXT("INBINE.CO.LTD"                                                                           )},  /* IBI */
	{0x4D24, TEXT("IBM Brasil"                                                                              )},  /* IBM */
	{0x4D24, TEXT("IBM Brasil"                                                                              )},  /* IBM */
	{0x5024, TEXT("IBP Instruments GmbH"                                                                    )},  /* IBP */
	{0x5224, TEXT("IBR GmbH"                                                                                )},  /* IBR */
	{0x6124, TEXT("ICA Inc"                                                                                 )},  /* ICA */
	{0x6324, TEXT("BICC Data Networks Ltd"                                                                  )},  /* ICC */
	{0x6424, TEXT("ICD Inc"                                                                                 )},  /* ICD */
	{0x6524, TEXT("IC Ensemble"                                                                             )},  /* ICE */
	{0x6924, TEXT("Infotek Communication Inc"                                                               )},  /* ICI */
	{0x6D24, TEXT("Intracom SA"                                                                             )},  /* ICM */
	{0x6E24, TEXT("Sanyo Icon"                                                                              )},  /* ICN */
	{0x6F24, TEXT("Intel Corp"                                                                              )},  /* ICO */
	{0x7324, TEXT("Integrated Circuit Systems"                                                              )},  /* ICS */
	{0x7824, TEXT("ICCC A/S"                                                                                )},  /* ICX */
	{0x8324, TEXT("International Datacasting Corporation"                                                   )},  /* IDC */
	{0x8524, TEXT("IDE Associates"                                                                          )},  /* IDE */
	{0x8B24, TEXT("IDK Corporation"                                                                         )},  /* IDK */
	{0x8F24, TEXT("IDEO Product Development"                                                                )},  /* IDO */
	{0x9324, TEXT("Interdigital Sistemas de Informacao"                                                     )},  /* IDS */
	{0x9424, TEXT("International Display Technology"                                                        )},  /* IDT */
	{0x9824, TEXT("IDEXX Labs"                                                                              )},  /* IDX */
	{0xA324, TEXT("Interlace Engineering Corporation"                                                       )},  /* IEC */
	{0xA524, TEXT("IEE"                                                                                     )},  /* IEE */
	{0xA924, TEXT("Interlink Electronics"                                                                   )},  /* IEI */
	{0xD324, TEXT("In Focus Systems Inc"                                                                    )},  /* IFS */
	{0xD424, TEXT("Informtech"                                                                              )},  /* IFT */
	{0xD824, TEXT("Infineon Technologies AG"                                                                )},  /* IFX */
	{0xE324, TEXT("Intergate Pty Ltd"                                                                       )},  /* IGC */
	{0xED24, TEXT("IGM Communi"                                                                             )},  /* IGM */
	{0x2325, TEXT("ISIC Innoscan Industrial Computers A/S"                                                  )},  /* IIC */
	{0x2925, TEXT("Intelligent Instrumentation"                                                             )},  /* III */
	{0x2E25, TEXT("IINFRA Co., Ltd"                                                                         )},  /* IIN */
	{0x7325, TEXT("Ikos Systems Inc"                                                                        )},  /* IKS */
	{0x8325, TEXT("Image Logic Corporation"                                                                 )},  /* ILC */
	{0x9325, TEXT("Innotech Corporation"                                                                    )},  /* ILS */
	{0xA125, TEXT("Imagraph"                                                                                )},  /* IMA */
	{0xA325, TEXT("IMC Networks"                                                                            )},  /* IMC */
	{0xA425, TEXT("ImasDe Canarias S.A."                                                                    )},  /* IMD */
	{0xA525, TEXT("Imagraph"                                                                                )},  /* IME */
	{0xA725, TEXT("IMAGENICS Co., Ltd."                                                                     )},  /* IMG */
	{0xA925, TEXT("International Microsystems Inc"                                                          )},  /* IMI */
	{0xAD25, TEXT("Immersion Corporation"                                                                   )},  /* IMM */
	{0xAE25, TEXT("Impossible Production"                                                                   )},  /* IMN */
	{0xB025, TEXT("Impression Products Incorporated"                                                        )},  /* IMP */
	{0xB425, TEXT("Inmax Technology Corporation"                                                            )},  /* IMT */
	{0xC325, TEXT("Home Row Inc"                                                                            )},  /* INC */
	{0xC425, TEXT("ILC"                                                                                     )},  /* IND */
	{0xC525, TEXT("Inventec Electronics (M) Sdn. Bhd."                                                      )},  /* INE */
	{0xC625, TEXT("Inframetrics Inc"                                                                        )},  /* INF */
	{0xC725, TEXT("Integraph Corporation"                                                                   )},  /* ING */
	{0xC925, TEXT("Initio Corporation"                                                                      )},  /* INI */
	{0xCB25, TEXT("Indtek Co., Ltd."                                                                        )},  /* INK */
	{0xCC25, TEXT("InnoLux Display Corporation"                                                             )},  /* INL */
	{0xCD25, TEXT("InnoMedia Inc"                                                                           )},  /* INM */
	{0xCE25, TEXT("Innovent Systems, Inc."                                                                  )},  /* INN */
	{0xCF25, TEXT("Innolab Pte Ltd"                                                                         )},  /* INO */
	{0xD025, TEXT("Interphase Corporation"                                                                  )},  /* INP */
	{0xD325, TEXT("Ines GmbH"                                                                               )},  /* INS */
	{0xD425, TEXT("Interphase Corporation"                                                                  )},  /* INT */
	{0xD525, TEXT("Inovatec S.p.A."                                                                         )},  /* INU */
	{0xD625, TEXT("Inviso, Inc."                                                                            )},  /* INV */
	{0xDA25, TEXT("Best Buy"                                                                                )},  /* INZ */
	{0xE125, TEXT("CRE Technology Corporation"                                                              )},  /* IOA */
	{0xE425, TEXT("I-O Data Device Inc"                                                                     )},  /* IOD */
	{0xED25, TEXT("Iomega"                                                                                  )},  /* IOM */
	{0xEE25, TEXT("Inside Out Networks"                                                                     )},  /* ION */
	{0xF325, TEXT("i-O Display System"                                                                      )},  /* IOS */
	{0xF425, TEXT("I/OTech Inc"                                                                             )},  /* IOT */
	{0x0326, TEXT("IPC Corporation"                                                                         )},  /* IPC */
	{0x0426, TEXT("Industrial Products Design, Inc."                                                        )},  /* IPD */
	{0x0926, TEXT("Intelligent Platform Management Interface (IPMI) forum (Intel, HP, NEC, Dell)"           )},  /* IPI */
	{0x0D26, TEXT("IPM Industria Politecnica Meridionale SpA"                                               )},  /* IPM */
	{0x0E26, TEXT("Performance Technologies"                                                                )},  /* IPN */
	{0x1226, TEXT("Ithaca Peripherals"                                                                      )},  /* IPR */
	{0x1326, TEXT("IPS, Inc. (Intellectual Property Solutions, Inc.)"                                       )},  /* IPS */
	{0x1426, TEXT("International Power Technologies"                                                        )},  /* IPT */
	{0x1726, TEXT("IPWireless, Inc"                                                                         )},  /* IPW */
	{0x3426, TEXT("IMAGEQUEST Co., Ltd"                                                                     )},  /* IQT */
	{0x4426, TEXT("IRdata"                                                                                  )},  /* IRD */
	{0x6126, TEXT("Symbol Technologies"                                                                     )},  /* ISA */
	{0x6326, TEXT("Id3 Semiconductors"                                                                      )},  /* ISC */
	{0x6726, TEXT("Insignia Solutions Inc"                                                                  )},  /* ISG */
	{0x6926, TEXT("Interface Solutions"                                                                     )},  /* ISI */
	{0x6C26, TEXT("Isolation Systems"                                                                       )},  /* ISL */
	{0x7026, TEXT("IntreSource Systems Pte Ltd"                                                             )},  /* ISP */
	{0x7226, TEXT("INSIS Co., LTD."                                                                         )},  /* ISR */
	{0x7326, TEXT("ISS Inc"                                                                                 )},  /* ISS */
	{0x7426, TEXT("Intersolve Technologies"                                                                 )},  /* IST */
	{0x7926, TEXT("International Integrated Systems,Inc.(IISI)"                                             )},  /* ISY */
	{0x8126, TEXT("Itausa Export North America"                                                             )},  /* ITA */
	{0x8326, TEXT("Intercom Inc"                                                                            )},  /* ITC */
	{0x8426, TEXT("Internet Technology Corporation"                                                         )},  /* ITD */
	{0x8526, TEXT("Integrated Tech Express Inc"                                                             )},  /* ITE */
	{0x8B26, TEXT("ITK Telekommunikation AG"                                                                )},  /* ITK */
	{0x8C26, TEXT("Inter-Tel"                                                                               )},  /* ITL */
	{0x8D26, TEXT("ITM inc."                                                                                )},  /* ITM */
	{0x8E26, TEXT("The NTI Group"                                                                           )},  /* ITN */
	{0x9026, TEXT("IT-PRO Consulting und Systemhaus GmbH"                                                   )},  /* ITP */
	{0x9226, TEXT("Infotronic America, Inc."                                                                )},  /* ITR */
	{0x9326, TEXT("IDTECH"                                                                                  )},  /* ITS */
	{0x9426, TEXT("I&T Telecom."                                                                            )},  /* ITT */
	{0x9826, TEXT("integrated Technology Express Inc"                                                       )},  /* ITX */
	{0xA326, TEXT("ICSL"                                                                                    )},  /* IUC */
	{0xC926, TEXT("Intervoice Inc"                                                                          )},  /* IVI */
	{0xCD26, TEXT("Liyama North America"                                                                    )},  /* IVM */
	{0xF226, TEXT("Icuiti Corporation"                                                                      )},  /* IWR */
	{0xF826, TEXT("Intelliworxx, Inc."                                                                      )},  /* IWX */
	{0x0427, TEXT("Intertex Data AB"                                                                        )},  /* IXD */
	{0x2328, TEXT("Astec Inc"                                                                               )},  /* JAC */
	{0x2528, TEXT("Japan Aviation Electronics Industry, Limited"                                            )},  /* JAE */
	{0x3428, TEXT("Jaton Corporation"                                                                       )},  /* JAT */
	{0x3A28, TEXT("Carrera Computer Inc (used as second pnpid)"                                             )},  /* JAZ */
	{0x6528, TEXT("Jace Tech Inc"                                                                           )},  /* JCE */
	{0x8C28, TEXT("Japan Digital Laboratory Co.,Ltd."                                                       )},  /* JDL */
	{0xAE28, TEXT("N-Vision"                                                                                )},  /* JEN */
	{0xB428, TEXT("JET POWER TECHNOLOGY CO., LTD."                                                          )},  /* JET */
	{0xD828, TEXT("Jones Futurex Inc"                                                                       )},  /* JFX */
	{0xE428, TEXT("University College"                                                                      )},  /* JGD */
	{0x2329, TEXT("Jaeik Information & Communication Co., Ltd."                                             )},  /* JIC */
	{0xB429, TEXT("Micro Technical Company Ltd"                                                             )},  /* JMT */
	{0x032A, TEXT("JPC Technology Limited"                                                                  )},  /* JPC */
	{0x172A, TEXT("Wallis Hamilton Industries"                                                              )},  /* JPW */
	{0x252A, TEXT("CNet Technical Inc"                                                                      )},  /* JQE */
	{0x642A, TEXT("JS DigiTech, Inc"                                                                        )},  /* JSD */
	{0x692A, TEXT("Jupiter Systems, Inc."                                                                   )},  /* JSI */
	{0x6B2A, TEXT("SANKEN ELECTRIC CO., LTD"                                                                )},  /* JSK */
	{0x932A, TEXT("JS Motorsports"                                                                          )},  /* JTS */
	{0xAB2A, TEXT("Janich & Klass Computertechnik GmbH"                                                     )},  /* JUK */
	{0xB02A, TEXT("Jupiter Systems"                                                                         )},  /* JUP */
	{0xC32A, TEXT("JVC"                                                                                     )},  /* JVC */
	{0xE42A, TEXT("Video International Inc."                                                                )},  /* JWD */
	{0xEC2A, TEXT("Jewell Instruments, LLC"                                                                 )},  /* JWL */
	{0xF32A, TEXT("JWSpencer & Co."                                                                         )},  /* JWS */
	{0xF92A, TEXT("Jetway Information Co., Ltd"                                                             )},  /* JWY */
	{0x322C, TEXT("Karna"                                                                                   )},  /* KAR */
	{0x492C, TEXT("Kidboard Inc"                                                                            )},  /* KBI */
	{0x4C2C, TEXT("Kobil Systems GmbH"                                                                      )},  /* KBL */
	{0x6C2C, TEXT("Keycorp Ltd"                                                                             )},  /* KCL */
	{0x852C, TEXT("KDE"                                                                                     )},  /* KDE */
	{0x8B2C, TEXT("Kodiak Tech"                                                                             )},  /* KDK */
	{0x8D2C, TEXT("Korea Data Systems Co., Ltd."                                                            )},  /* KDM */
	{0x932C, TEXT("KDS USA"                                                                                 )},  /* KDS */
	{0xA32C, TEXT("Kyushu Electronics Systems Inc"                                                          )},  /* KEC */
	{0xAD2C, TEXT("Kontron Embedded Modules GmbH"                                                           )},  /* KEM */
	{0xB32C, TEXT("Kesa Corporation"                                                                        )},  /* KES */
	{0xB92C, TEXT("Key Tech Inc"                                                                            )},  /* KEY */
	{0xC32C, TEXT("SCD Tech"                                                                                )},  /* KFC */
	{0xD82C, TEXT("Kofax Image Products"                                                                    )},  /* KFX */
	{0x332D, TEXT("KiSS Technology A/S"                                                                     )},  /* KIS */
	{0xA32D, TEXT("Mitsumi Company Ltd"                                                                     )},  /* KMC */
	{0xAC2D, TEXT("Kensington Microware Ltd"                                                                )},  /* KML */
	{0xC32D, TEXT("Konica corporation"                                                                      )},  /* KNC */
	{0xD82D, TEXT("Nutech Marketing PTL"                                                                    )},  /* KNX */
	{0xE22D, TEXT("Kobil Systems GmbH"                                                                      )},  /* KOB */
	{0xE42D, TEXT("Eastman Kodak Company"                                                                   )},  /* KOD */
	{0xE52D, TEXT("KOLTER ELECTRONIC"                                                                       )},  /* KOE */
	{0xEC2D, TEXT("Kollmorgen Motion Technologies Group"                                                    )},  /* KOL */
	{0xF72D, TEXT("KOWA Company,LTD. "                                                                      )},  /* KOW */
	{0x032E, TEXT("King Phoenix Company"                                                                    )},  /* KPC */
	{0x4C2E, TEXT("Krell Industries Inc."                                                                   )},  /* KRL */
	{0x592E, TEXT("Kroy LLC"                                                                                )},  /* KRY */
	{0x632E, TEXT("Kinetic Systems Corporation"                                                             )},  /* KSC */
	{0x6C2E, TEXT("Karn Solutions Ltd."                                                                     )},  /* KSL */
	{0x782E, TEXT("King Tester Corporation"                                                                 )},  /* KSX */
	{0x832E, TEXT("Kingston Tech Corporation"                                                               )},  /* KTC */
	{0x852E, TEXT("K-Tech"                                                                                  )},  /* KTE */
	{0x872E, TEXT("Kayser-Threde GmbH"                                                                      )},  /* KTG */
	{0x892E, TEXT("Konica Technical Inc"                                                                    )},  /* KTI */
	{0x8B2E, TEXT("Key Tronic Corporation"                                                                  )},  /* KTK */
	{0x8E2E, TEXT("Katron Tech Inc"                                                                         )},  /* KTN */
	{0xB22E, TEXT("Kurta Corporation"                                                                       )},  /* KUR */
	{0xC12E, TEXT("Kvaser AB"                                                                               )},  /* KVA */
	{0xE42E, TEXT("Kenwood Corporation"                                                                     )},  /* KWD */
	{0x232F, TEXT("Kyocera Corporation"                                                                     )},  /* KYC */
	{0x252F, TEXT("KYE Syst Corporation"                                                                    )},  /* KYE */
	{0x2B2F, TEXT("Samsung Electronics America Inc"                                                         )},  /* KYK */
	{0x492F, TEXT("K-Zone International co. Ltd."                                                           )},  /* KZI */
	{0x4E2F, TEXT("K-Zone International"                                                                    )},  /* KZN */
	{0x2230, TEXT("ACT Labs Ltd"                                                                            )},  /* LAB */
	{0x2330, TEXT("LaCie"                                                                                   )},  /* LAC */
	{0x2630, TEXT("Microline"                                                                               )},  /* LAF */
	{0x2730, TEXT("Laguna Systems"                                                                          )},  /* LAG */
	{0x2E30, TEXT("Sodeman Lancom Inc"                                                                      )},  /* LAN */
	{0x3330, TEXT("LASAT Comm. A/S"                                                                         )},  /* LAS */
	{0x3630, TEXT("Lava Computer MFG Inc"                                                                   )},  /* LAV */
	{0x4F30, TEXT("Lubosoft"                                                                                )},  /* LBO */
	{0x6330, TEXT("LCI"                                                                                     )},  /* LCC */
	{0x6430, TEXT("Toshiba Matsushita Display Technology Co., Ltd"                                          )},  /* LCD */
	{0x6530, TEXT("La Commande Electronique"                                                                )},  /* LCE */
	{0x6930, TEXT("Lite-On Communication Inc"                                                               )},  /* LCI */
	{0x6D30, TEXT("Latitude Comm."                                                                          )},  /* LCM */
	{0x6E30, TEXT("LEXICON"                                                                                 )},  /* LCN */
	{0x7330, TEXT("Longshine Electronics Company"                                                           )},  /* LCS */
	{0x7430, TEXT("Labcal Technologies"                                                                     )},  /* LCT */
	{0x9430, TEXT("LogiDataTech Electronic GmbH"                                                            )},  /* LDT */
	{0xA330, TEXT("Lectron Company Ltd"                                                                     )},  /* LEC */
	{0xA430, TEXT("Long Engineering Design Inc"                                                             )},  /* LED */
	{0xA730, TEXT("Legerity, Inc"                                                                           )},  /* LEG */
	{0xAE30, TEXT("Lenovo Group Limited"                                                                    )},  /* LEN */
	{0xAF30, TEXT("First International Computer Inc"                                                        )},  /* LEO */
	{0xB830, TEXT("Lexical Ltd"                                                                             )},  /* LEX */
	{0xE330, TEXT("Logic Ltd"                                                                               )},  /* LGC */
	{0xE930, TEXT("Logitech Inc"                                                                            )},  /* LGI */
	{0xF330, TEXT("LG Semicom Company Ltd"                                                                  )},  /* LGS */
	{0xF830, TEXT("Lasergraphics, Inc."                                                                     )},  /* LGX */
	{0x0131, TEXT("Lars Haagh ApS"                                                                          )},  /* LHA */
	{0x0531, TEXT("Lung Hwa Electronics Company Ltd"                                                        )},  /* LHE */
	{0x3431, TEXT("Lithics Silicon Technology"                                                              )},  /* LIT */
	{0x5831, TEXT("Datalogic Corporation"                                                                   )},  /* LJX */
	{0x6D31, TEXT("Likom Technology Sdn. Bhd."                                                              )},  /* LKM */
	{0xA731, TEXT("Lucent Technologies"                                                                     )},  /* LMG */
	{0xA931, TEXT("Lexmark Int'l Inc"                                                                       )},  /* LMI */
	{0xB031, TEXT("Leda Media Products"                                                                     )},  /* LMP */
	{0xB431, TEXT("Laser Master"                                                                            )},  /* LMT */
	{0xC431, TEXT("Land Computer Company Ltd"                                                               )},  /* LND */
	{0xCB31, TEXT("Link Tech Inc"                                                                           )},  /* LNK */
	{0xD231, TEXT("Linear Systems Ltd."                                                                     )},  /* LNR */
	{0xD431, TEXT("LANETCO International"                                                                   )},  /* LNT */
	{0xD631, TEXT("Lenovo"                                                                                  )},  /* LNV */
	{0xE331, TEXT("Locamation B.V."                                                                         )},  /* LOC */
	{0xE531, TEXT("Loewe Opta GmbH"                                                                         )},  /* LOE */
	{0xE731, TEXT("Logicode Technology Inc"                                                                 )},  /* LOG */
	{0x0532, TEXT("El-PUSK Co., Ltd."                                                                       )},  /* LPE */
	{0x0932, TEXT("Design Technology"                                                                       )},  /* LPI */
	{0x0C32, TEXT("DO NOT USE - LPL"                                                                        )},  /* LPL */
	{0x6332, TEXT("LifeSize Communications"                                                                 )},  /* LSC */
	{0x6932, TEXT("Loughborough Sound Images"                                                               )},  /* LSI */
	{0x6A32, TEXT("LSI Japan Company Ltd"                                                                   )},  /* LSJ */
	{0x6C32, TEXT("Logical Solutions"                                                                       )},  /* LSL */
	{0x7932, TEXT("LSI Systems Inc"                                                                         )},  /* LSY */
	{0x8332, TEXT("Labtec Inc"                                                                              )},  /* LTC */
	{0x8932, TEXT("Jongshine Tech Inc"                                                                      )},  /* LTI */
	{0x8B32, TEXT("Lucidity Technology Company Ltd"                                                         )},  /* LTK */
	{0x8E32, TEXT("Litronic Inc"                                                                            )},  /* LTN */
	{0x9332, TEXT("LTS Scale LLC"                                                                           )},  /* LTS */
	{0x9632, TEXT("Leitch Technology International Inc."                                                    )},  /* LTV */
	{0x9732, TEXT("Lightware, Inc"                                                                          )},  /* LTW */
	{0xA332, TEXT("Lucent Technologies"                                                                     )},  /* LUC */
	{0xAD32, TEXT("Lumagen, Inc."                                                                           )},  /* LUM */
	{0xB832, TEXT("Luxxell Research Inc"                                                                    )},  /* LUX */
	{0xE332, TEXT("Labway Corporation"                                                                      )},  /* LWC */
	{0xF232, TEXT("Lightware Visual Engineering"                                                            )},  /* LWR */
	{0xF732, TEXT("Lanier Worldwide"                                                                        )},  /* LWW */
	{0x0E33, TEXT("Luxeon"                                                                                  )},  /* LXN */
	{0x1333, TEXT("ELEA CardWare"                                                                           )},  /* LXS */
	{0x5833, TEXT("Lightwell Company Ltd"                                                                   )},  /* LZX */
	{0x2334, TEXT("MAC System Company Ltd"                                                                  )},  /* MAC */
	{0x2434, TEXT("Xedia Corporation"                                                                       )},  /* MAD */
	{0x2534, TEXT("Maestro Pty Ltd"                                                                         )},  /* MAE */
	{0x2734, TEXT("MAG InnoVision"                                                                          )},  /* MAG */
	{0x2934, TEXT("Mutoh America Inc"                                                                       )},  /* MAI */
	{0x2C34, TEXT("Meridian Audio Ltd"                                                                      )},  /* MAL */
	{0x2E34, TEXT("LGIC"                                                                                    )},  /* MAN */
	{0x3334, TEXT("Mass Inc."                                                                               )},  /* MAS */
	{0x3434, TEXT("Matsushita Electric Ind. Company Ltd"                                                    )},  /* MAT */
	{0x3834, TEXT("Rogen Tech Distribution Inc"                                                             )},  /* MAX */
	{0x3934, TEXT("Maynard Electronics"                                                                     )},  /* MAY */
	{0x3A34, TEXT("MAZeT GmbH"                                                                              )},  /* MAZ */
	{0x4334, TEXT("MBC"                                                                                     )},  /* MBC */
	{0x4434, TEXT("Microbus PLC"                                                                            )},  /* MBD */
	{0x4D34, TEXT("Marshall Electronics"                                                                    )},  /* MBM */
	{0x5634, TEXT("Moreton Bay"                                                                             )},  /* MBV */
	{0x6134, TEXT("American Nuclear Systems Inc"                                                            )},  /* MCA */
	{0x6334, TEXT("Micro Industries"                                                                        )},  /* MCC */
	{0x6434, TEXT("McDATA Corporation"                                                                      )},  /* MCD */
	{0x6534, TEXT("Metz-Werke GmbH & Co KG"                                                                 )},  /* MCE */
	{0x6734, TEXT("Motorola Computer Group"                                                                 )},  /* MCG */
	{0x6934, TEXT("Micronics Computers"                                                                     )},  /* MCI */
	{0x6C34, TEXT("Motorola Communications Israel"                                                          )},  /* MCL */
	{0x6D34, TEXT("Metricom Inc"                                                                            )},  /* MCM */
	{0x6E34, TEXT("Micron Electronics Inc"                                                                  )},  /* MCN */
	{0x6F34, TEXT("Motion Computing Inc."                                                                   )},  /* MCO */
	{0x7034, TEXT("Magni Systems Inc"                                                                       )},  /* MCP */
	{0x7134, TEXT("Mat's Computers"                                                                         )},  /* MCQ */
	{0x7234, TEXT("Marina Communicaitons"                                                                   )},  /* MCR */
	{0x7334, TEXT("Micro Computer Systems"                                                                  )},  /* MCS */
	{0x7434, TEXT("Microtec"                                                                                )},  /* MCT */
	{0x8134, TEXT("Media4 Inc"                                                                              )},  /* MDA */
	{0x8334, TEXT("Midori Electronics"                                                                      )},  /* MDC */
	{0x8434, TEXT("MODIS"                                                                                   )},  /* MDD */
	{0x8734, TEXT("Madge Networks"                                                                          )},  /* MDG */
	{0x8934, TEXT("Micro Design Inc"                                                                        )},  /* MDI */
	{0x8B34, TEXT("Mediatek Corporation"                                                                    )},  /* MDK */
	{0x8F34, TEXT("Panasonic"                                                                               )},  /* MDO */
	{0x9234, TEXT("Medar Inc"                                                                               )},  /* MDR */
	{0x9334, TEXT("Micro Display Systems Inc"                                                               )},  /* MDS */
	{0x9434, TEXT("Magus Data Tech"                                                                         )},  /* MDT */
	{0x9634, TEXT("MET Development Inc"                                                                     )},  /* MDV */
	{0x9834, TEXT("MicroDatec GmbH"                                                                         )},  /* MDX */
	{0x9934, TEXT("Microdyne Inc"                                                                           )},  /* MDY */
	{0xA334, TEXT("Mega System Technologies Inc"                                                            )},  /* MEC */
	{0xA434, TEXT("Messeltronik Dresden GmbH"                                                               )},  /* MED */
	{0xA534, TEXT("Mitsubishi Electric Engineering Co., Ltd."                                               )},  /* MEE */
	{0xA734, TEXT("Abeam Tech Ltd"                                                                          )},  /* MEG */
	{0xA934, TEXT("Panasonic Industry Company"                                                              )},  /* MEI */
	{0xAC34, TEXT("Mitsubishi Electric Corporation"                                                         )},  /* MEL */
	{0xAE34, TEXT("MEN Mikroelectronik Nueruberg GmbH"                                                      )},  /* MEN */
	{0xB134, TEXT("Matelect Ltd."                                                                           )},  /* MEQ */
	{0xB434, TEXT("Metheus Corporation"                                                                     )},  /* MET */
	{0xC734, TEXT("MicroField Graphics Inc"                                                                 )},  /* MFG */
	{0xC934, TEXT("Micro Firmware"                                                                          )},  /* MFI */
	{0xD234, TEXT("MediaFire Corp."                                                                         )},  /* MFR */
	{0xE134, TEXT("Mega System Technologies, Inc."                                                          )},  /* MGA */
	{0xE534, TEXT("Schneider Electric S.A."                                                                 )},  /* MGE */
	{0xEC34, TEXT("M-G Technology Ltd"                                                                      )},  /* MGL */
	{0xF434, TEXT("Megatech R & D Company"                                                                  )},  /* MGT */
	{0x2335, TEXT("Micom Communications Inc"                                                                )},  /* MIC */
	{0x2435, TEXT("miro Displays"                                                                           )},  /* MID */
	{0x2935, TEXT("Mitec Inc"                                                                               )},  /* MII */
	{0x2C35, TEXT("Marconi Instruments Ltd"                                                                 )},  /* MIL */
	{0x3035, TEXT("micronpc.com"                                                                            )},  /* MIP */
	{0x3235, TEXT("Miro Computer Prod."                                                                     )},  /* MIR */
	{0x3335, TEXT("Modular Industrial Solutions Inc"                                                        )},  /* MIS */
	{0x3435, TEXT("MCM Industrial Technology GmbH"                                                          )},  /* MIT */
	{0x4935, TEXT("MARANTZ JAPAN, INC."                                                                     )},  /* MJI */
	{0x5335, TEXT("MJS Designs"                                                                             )},  /* MJS */
	{0x6335, TEXT("Media Tek Inc."                                                                          )},  /* MKC */
	{0x7435, TEXT("MICROTEK Inc."                                                                           )},  /* MKT */
	{0x7635, TEXT("Trtheim Technology"                                                                      )},  /* MKV */
	{0x8435, TEXT("Deep Video Imaging Ltd"                                                                  )},  /* MLD */
	{0x8735, TEXT("Micrologica AG"                                                                          )},  /* MLG */
	{0x8935, TEXT("McIntosh Laboratory Inc."                                                                )},  /* MLI */
	{0x8D35, TEXT("Millennium Engineering Inc"                                                              )},  /* MLM */
	{0x8E35, TEXT("Mark Levinson"                                                                           )},  /* MLN */
	{0x9335, TEXT("Milestone EPE"                                                                           )},  /* MLS */
	{0x9835, TEXT("Mylex Corporation"                                                                       )},  /* MLX */
	{0xA135, TEXT("Micromedia AG"                                                                           )},  /* MMA */
	{0xA435, TEXT("Micromed Biotecnologia Ltd"                                                              )},  /* MMD */
	{0xA635, TEXT("Minnesota Mining and Manufacturing"                                                      )},  /* MMF */
	{0xA935, TEXT("Multimax"                                                                                )},  /* MMI */
	{0xAD35, TEXT("Electronic Measurements"                                                                 )},  /* MMM */
	{0xAE35, TEXT("MiniMan Inc"                                                                             )},  /* MMN */
	{0xB335, TEXT("MMS Electronics"                                                                         )},  /* MMS */
	{0xC335, TEXT("Mini Micro Methods Ltd"                                                                  )},  /* MNC */
	{0xCC35, TEXT("Monorail Inc"                                                                            )},  /* MNL */
	{0xD035, TEXT("Microcom"                                                                                )},  /* MNP */
	{0xE435, TEXT("Modular Technology"                                                                      )},  /* MOD */
	{0xED35, TEXT("Momentum Data Systems"                                                                   )},  /* MOM */
	{0xF335, TEXT("Moses Corporation"                                                                       )},  /* MOS */
	{0xF435, TEXT("Motorola UDS"                                                                            )},  /* MOT */
	{0x0336, TEXT("M-Pact Inc"                                                                              )},  /* MPC */
	{0x0936, TEXT("Mediatrix Peripherals Inc"                                                               )},  /* MPI */
	{0x0A36, TEXT("Microlab"                                                                                )},  /* MPJ */
	{0x0C36, TEXT("Maple Research Inst. Company Ltd"                                                        )},  /* MPL */
	{0x0E36, TEXT("Mainpine Limited"                                                                        )},  /* MPN */
	{0x1336, TEXT("mps Software GmbH"                                                                       )},  /* MPS */
	{0x1836, TEXT("Micropix Technologies, Ltd."                                                             )},  /* MPX */
	{0x3036, TEXT("MultiQ Products AB"                                                                      )},  /* MQP */
	{0x4136, TEXT("Miranda Technologies Inc"                                                                )},  /* MRA */
	{0x4336, TEXT("Marconi Simulation & Ty-Coch Way Training"                                               )},  /* MRC */
	{0x4436, TEXT("MicroDisplay Corporation"                                                                )},  /* MRD */
	{0x4B36, TEXT("Maruko & Company Ltd"                                                                    )},  /* MRK */
	{0x4C36, TEXT("Miratel"                                                                                 )},  /* MRL */
	{0x4F36, TEXT("Medikro Oy"                                                                              )},  /* MRO */
	{0x5436, TEXT("Merging Technologies"                                                                    )},  /* MRT */
	{0x6136, TEXT("Micro Systemation AB"                                                                    )},  /* MSA */
	{0x6336, TEXT("Mouse Systems Corporation"                                                               )},  /* MSC */
	{0x6436, TEXT("Datenerfassungs- und Informationssysteme"                                                )},  /* MSD */
	{0x6636, TEXT("M-Systems Flash Disk Pioneers"                                                           )},  /* MSF */
	{0x6736, TEXT("MSI GmbH"                                                                                )},  /* MSG */
	{0x6836, TEXT("Microsoft"                                                                               )},  /* MSH */
	{0x6936, TEXT("Microstep"                                                                               )},  /* MSI */
	{0x6B36, TEXT("Megasoft Inc"                                                                            )},  /* MSK */
	{0x6C36, TEXT("MicroSlate Inc."                                                                         )},  /* MSL */
	{0x6D36, TEXT("Advanced Digital Systems"                                                                )},  /* MSM */
	{0x7036, TEXT("Mistral Solutions [P] Ltd."                                                              )},  /* MSP */
	{0x7436, TEXT("MS Telematica"                                                                           )},  /* MST */
	{0x7536, TEXT("motorola"                                                                                )},  /* MSU */
	{0x7636, TEXT("Mosgi Corporation"                                                                       )},  /* MSV */
	{0x7836, TEXT("Micomsoft Co., Ltd."                                                                     )},  /* MSX */
	{0x7936, TEXT("MicroTouch Systems Inc"                                                                  )},  /* MSY */
	{0x8236, TEXT("Media Technologies Ltd."                                                                 )},  /* MTB */
	{0x8336, TEXT("Mars-Tech Corporation"                                                                   )},  /* MTC */
	{0x8436, TEXT("MindTech Display Co. Ltd"                                                                )},  /* MTD */
	{0x8536, TEXT("MediaTec GmbH"                                                                           )},  /* MTE */
	{0x8836, TEXT("Micro-Tech Hearing Instruments"                                                          )},  /* MTH */
	{0x8936, TEXT("MaxCom Technical Inc"                                                                    )},  /* MTI */
	{0x8936, TEXT("MaxCom Technical Inc"                                                                    )},  /* MTI */
	{0x8B36, TEXT("Microtek International Inc."                                                             )},  /* MTK */
	{0x8C36, TEXT("Mitel Corporation"                                                                       )},  /* MTL */
	{0x8E36, TEXT("Mtron Storage Technology Co., Ltd."                                                      )},  /* MTN */
	{0x9236, TEXT("Mitron computer Inc"                                                                     )},  /* MTR */
	{0x9336, TEXT("Multi-Tech Systems"                                                                      )},  /* MTS */
	{0x9536, TEXT("Mark of the Unicorn Inc"                                                                 )},  /* MTU */
	{0x9836, TEXT("Matrox"                                                                                  )},  /* MTX */
	{0xA436, TEXT("Multi-Dimension Institute"                                                               )},  /* MUD */
	{0xAB36, TEXT("mainpine limited"                                                                        )},  /* MUK */
	{0xC436, TEXT("Microvitec PLC"                                                                          )},  /* MVD */
	{0xC936, TEXT("Media Vision Inc"                                                                        )},  /* MVI */
	{0xCD36, TEXT("SOBO VISION"                                                                             )},  /* MVM */
	{0xD336, TEXT("Microvision"                                                                             )},  /* MVS */
	{0xD836, TEXT("COM 1"                                                                                   )},  /* MVX */
	{0xE936, TEXT("Multiwave Innovation Pte Ltd"                                                            )},  /* MWI */
	{0xF236, TEXT("mware"                                                                                   )},  /* MWR */
	{0xF936, TEXT("Microway Inc"                                                                            )},  /* MWY */
	{0x0437, TEXT("MaxData Computer GmbH & Co.KG"                                                           )},  /* MXD */
	{0x0937, TEXT("Macronix Inc"                                                                            )},  /* MXI */
	{0x0C37, TEXT("Hitachi Maxell, Ltd."                                                                    )},  /* MXL */
	{0x1037, TEXT("Maxpeed Corporation"                                                                     )},  /* MXP */
	{0x1437, TEXT("Maxtech Corporation"                                                                     )},  /* MXT */
	{0x1637, TEXT("MaxVision Corporation"                                                                   )},  /* MXV */
	{0x2137, TEXT("Monydata"                                                                                )},  /* MYA */
	{0x3237, TEXT("Myriad Solutions Ltd"                                                                    )},  /* MYR */
	{0x3837, TEXT("Micronyx Inc"                                                                            )},  /* MYX */
	{0x2338, TEXT("Ncast Corporation"                                                                       )},  /* NAC */
	{0x2438, TEXT("NAD Electronics"                                                                         )},  /* NAD */
	{0x2C38, TEXT("Network Alchemy"                                                                         )},  /* NAL */
	{0x3638, TEXT("Navigation Corporation"                                                                  )},  /* NAV */
	{0x3838, TEXT("Naxos Tecnologia"                                                                        )},  /* NAX */
	{0x4C38, TEXT("N*Able Technologies Inc"                                                                 )},  /* NBL */
	{0x5338, TEXT("National Key Lab. on ISN"                                                                )},  /* NBS */
	{0x5438, TEXT("NingBo Bestwinning Technology CO., Ltd"                                                  )},  /* NBT */
	{0x6138, TEXT("Nixdorf Company"                                                                         )},  /* NCA */
	{0x6338, TEXT("NCR Corporation"                                                                         )},  /* NCC */
	{0x6538, TEXT("Norcent Technology, Inc."                                                                )},  /* NCE */
	{0x6938, TEXT("NewCom Inc"                                                                              )},  /* NCI */
	{0x6C38, TEXT("NetComm Ltd"                                                                             )},  /* NCL */
	{0x7238, TEXT("NCR Electronics"                                                                         )},  /* NCR */
	{0x7338, TEXT("Northgate Computer Systems"                                                              )},  /* NCS */
	{0x7438, TEXT("NEC CustomTechnica, Ltd."                                                                )},  /* NCT */
	{0x8338, TEXT("National DataComm Corporaiton"                                                           )},  /* NDC */
	{0x8938, TEXT("National Display Systems"                                                                )},  /* NDI */
	{0x8B38, TEXT("Naitoh Densei CO., LTD."                                                                 )},  /* NDK */
	{0x8C38, TEXT("Network Designers"                                                                       )},  /* NDL */
	{0x9338, TEXT("Nokia Data"                                                                              )},  /* NDS */
	{0xA338, TEXT("NEC Corporation"                                                                         )},  /* NEC */
	{0xAF38, TEXT("NEO TELECOM CO.,LTD."                                                                    )},  /* NEO */
	{0xB438, TEXT("Mettler Toledo"                                                                          )},  /* NET */
	{0xB538, TEXT("NEUROTEC - EMPRESA DE PESQUISA E DESENVOLVIMENTO EM BIOMEDICINA"                         )},  /* NEU */
	{0xB838, TEXT("Nexgen Mediatech Inc.,"                                                                  )},  /* NEX */
	{0xC338, TEXT("BTC Korea Co., Ltd"                                                                      )},  /* NFC */
	{0xD338, TEXT("Number Five Software"                                                                    )},  /* NFS */
	{0xE338, TEXT("Network General"                                                                         )},  /* NGC */
	{0xF338, TEXT("A D S Exports"                                                                           )},  /* NGS */
	{0x1439, TEXT("Vinci Labs"                                                                              )},  /* NHT */
	{0x2339, TEXT("National Instruments Corporation"                                                        )},  /* NIC */
	{0x3339, TEXT("Nissei Electric Company"                                                                 )},  /* NIS */
	{0x3439, TEXT("Network Info Technology"                                                                 )},  /* NIT */
	{0x3839, TEXT("Seanix Technology Inc"                                                                   )},  /* NIX */
	{0x8339, TEXT("Next Level Communications"                                                               )},  /* NLC */
	{0xB039, TEXT("Nokia Mobile Phones"                                                                     )},  /* NMP */
	{0xB339, TEXT("Natural Micro System"                                                                    )},  /* NMS */
	{0xB639, TEXT("NEC-Mitsubishi Electric Visual Systems Corporation"                                      )},  /* NMV */
	{0xB839, TEXT("Neomagic"                                                                                )},  /* NMX */
	{0xC339, TEXT("NNC"                                                                                     )},  /* NNC */
	{0xEB39, TEXT("Nokia Display Products"                                                                  )},  /* NOK */
	{0xF239, TEXT("Norand Corporation"                                                                      )},  /* NOR */
	{0xF439, TEXT("Not Limited Inc"                                                                         )},  /* NOT */
	{0x093A, TEXT("Network Peripherals Inc"                                                                 )},  /* NPI */
	{0x4C3A, TEXT("U.S. Naval Research Lab"                                                                 )},  /* NRL */
	{0x543A, TEXT("Beijing Northern Radiantelecom Co."                                                      )},  /* NRT */
	{0x563A, TEXT("Taugagreining hf"                                                                        )},  /* NRV */
	{0x633A, TEXT("National Semiconductor Corporation"                                                      )},  /* NSC */
	{0x693A, TEXT("NISSEI ELECTRIC CO.,LTD"                                                                 )},  /* NSI */
	{0x703A, TEXT("Nspire System Inc."                                                                      )},  /* NSP */
	{0x733A, TEXT("Newport Systems Solutions"                                                               )},  /* NSS */
	{0x743A, TEXT("Network Security Technology Co"                                                          )},  /* NST */
	{0x833A, TEXT("NeoTech S.R.L"                                                                           )},  /* NTC */
	{0x893A, TEXT("New Tech Int'l Company"                                                                  )},  /* NTI */
	{0x8C3A, TEXT("National Transcomm. Ltd"                                                                 )},  /* NTL */
	{0x8E3A, TEXT("Nuvoton Technology Corporation "                                                         )},  /* NTN */
	{0x923A, TEXT("N-trig Innovative Technologies, Inc."                                                    )},  /* NTR */
	{0x933A, TEXT("Nits Technology Inc."                                                                    )},  /* NTS */
	{0x943A, TEXT("NTT Advanced Technology Corporation"                                                     )},  /* NTT */
	{0x973A, TEXT("Networth Inc"                                                                            )},  /* NTW */
	{0x983A, TEXT("Netaccess Inc"                                                                           )},  /* NTX */
	{0xA73A, TEXT("NU Technology, Inc."                                                                     )},  /* NUG */
	{0xA93A, TEXT("NU Inc."                                                                                 )},  /* NUI */
	{0xC33A, TEXT("NetVision Corporation"                                                                   )},  /* NVC */
	{0xC43A, TEXT("Nvidia"                                                                                  )},  /* NVD */
	{0xC93A, TEXT("NuVision US, Inc."                                                                       )},  /* NVI */
	{0xCC3A, TEXT("Novell Inc"                                                                              )},  /* NVL */
	{0xD43A, TEXT("Navatek Engineering Corporation"                                                         )},  /* NVT */
	{0xE33A, TEXT("NW Computer Engineering"                                                                 )},  /* NWC */
	{0xF03A, TEXT("NovaWeb Technologies Inc"                                                                )},  /* NWP */
	{0xF33A, TEXT("Newisys, Inc."                                                                           )},  /* NWS */
	{0x033B, TEXT("NextCom K.K."                                                                            )},  /* NXC */
	{0x073B, TEXT("Nexgen"                                                                                  )},  /* NXG */
	{0x103B, TEXT("NXP Semiconductors bv."                                                                  )},  /* NXP */
	{0x113B, TEXT("Nexiq Technologies, Inc."                                                                )},  /* NXQ */
	{0x133B, TEXT("Technology Nexus Secure Open Systems AB"                                                 )},  /* NXS */
	{0x233B, TEXT("nakayo telecommunications,inc."                                                          )},  /* NYC */
	{0x2B3C, TEXT("Oak Tech Inc"                                                                            )},  /* OAK */
	{0x333C, TEXT("Oasys Technology Company"                                                                )},  /* OAS */
	{0x643C, TEXT("Macraigor Systems Inc"                                                                   )},  /* OCD */
	{0x6E3C, TEXT("Olfan"                                                                                   )},  /* OCN */
	{0x733C, TEXT("Open Connect Solutions"                                                                  )},  /* OCS */
	{0x8D3C, TEXT("ODME Inc."                                                                               )},  /* ODM */
	{0x923C, TEXT("Odrac"                                                                                   )},  /* ODR */
	{0xA33C, TEXT("ORION ELECTRIC CO.,LTD"                                                                  )},  /* OEC */
	{0x233D, TEXT("Option Industrial Computers"                                                             )},  /* OIC */
	{0x2D3D, TEXT("Option International"                                                                    )},  /* OIM */
	{0x2E3D, TEXT("Option International"                                                                    )},  /* OIN */
	{0x693D, TEXT("OKI Electric Industrial Company Ltd"                                                     )},  /* OKI */
	{0x833D, TEXT("Olicom A/S"                                                                              )},  /* OLC */
	{0x843D, TEXT("Olidata S.p.A."                                                                          )},  /* OLD */
	{0x893D, TEXT("Olivetti"                                                                                )},  /* OLI */
	{0x943D, TEXT("Olitec S.A."                                                                             )},  /* OLT */
	{0x963D, TEXT("Olitec S.A."                                                                             )},  /* OLV */
	{0x993D, TEXT("OLYMPUS CORPORATION"                                                                     )},  /* OLY */
	{0xA33D, TEXT("OBJIX Multimedia Corporation"                                                            )},  /* OMC */
	{0xAE3D, TEXT("Omnitel"                                                                                 )},  /* OMN */
	{0xB23D, TEXT("Omron Corporation"                                                                       )},  /* OMR */
	{0xC53D, TEXT("Oneac Corporation"                                                                       )},  /* ONE */
	{0xCB3D, TEXT("ONKYO Corporation"                                                                       )},  /* ONK */
	{0xD33D, TEXT("On Systems Inc"                                                                          )},  /* ONS */
	{0xD73D, TEXT("OPEN Networks Ltd"                                                                       )},  /* ONW */
	{0xD83D, TEXT("SOMELEC Z.I. Du Vert Galanta"                                                            )},  /* ONX */
	{0xF33D, TEXT("OSRAM"                                                                                   )},  /* OOS */
	{0x033E, TEXT("Opcode Inc"                                                                              )},  /* OPC */
	{0x093E, TEXT("D.N.S. Corporation"                                                                      )},  /* OPI */
	{0x143E, TEXT("OPTi Inc"                                                                                )},  /* OPT */
	{0x163E, TEXT("Optivision Inc"                                                                          )},  /* OPV */
	{0x293E, TEXT("Oksori Company Ltd"                                                                      )},  /* OQI */
	{0x473E, TEXT("ORGA Kartensysteme GmbH"                                                                 )},  /* ORG */
	{0x493E, TEXT("OSR Open Systems Resources, Inc."                                                        )},  /* ORI */
	{0x4E3E, TEXT("ORION ELECTRIC CO., LTD."                                                                )},  /* ORN */
	{0x613E, TEXT("OSAKA Micro Computer, Inc."                                                              )},  /* OSA */
	{0x703E, TEXT("OPTI-UPS Corporation"                                                                    )},  /* OSP */
	{0x723E, TEXT("Oksori Company Ltd"                                                                      )},  /* OSR */
	{0x893E, TEXT("Orchid Technology"                                                                       )},  /* OTI */
	{0x943E, TEXT("OPTO22, Inc."                                                                            )},  /* OTT */
	{0xAB3E, TEXT("OUK Company Ltd"                                                                         )},  /* OUK */
	{0xEC3E, TEXT("Mediacom Technologies Pte Ltd"                                                           )},  /* OWL */
	{0x153F, TEXT("Oxus Research S.A."                                                                      )},  /* OXU */
	{0x2F3F, TEXT("Shadow Systems"                                                                          )},  /* OYO */
	{0x4F3F, TEXT("Tribe Computer Works Inc"                                                                )},  /* OZO */
	{0x2340, TEXT("Pacific Avionics Corporation"                                                            )},  /* PAC */
	{0x2440, TEXT("Promotion and Display Technology Ltd."                                                   )},  /* PAD */
	{0x2B40, TEXT("Many CNC System Co., Ltd."                                                               )},  /* PAK */
	{0x2D40, TEXT("Peter Antesberger Messtechnik"                                                           )},  /* PAM */
	{0x2E40, TEXT("The Panda Project"                                                                       )},  /* PAN */
	{0x3240, TEXT("Parallan Comp Inc"                                                                       )},  /* PAR */
	{0x4940, TEXT("Pitney Bowes"                                                                            )},  /* PBI */
	{0x4C40, TEXT("Packard Bell Electronics"                                                                )},  /* PBL */
	{0x4E40, TEXT("Packard Bell NEC"                                                                        )},  /* PBN */
	{0x5640, TEXT("Pitney Bowes"                                                                            )},  /* PBV */
	{0x6140, TEXT("Philips BU Add On Card"                                                                  )},  /* PCA */
	{0x6240, TEXT("OCTAL S.A."                                                                              )},  /* PCB */
	{0x6340, TEXT("PowerCom Technology Company Ltd"                                                         )},  /* PCC */
	{0x6740, TEXT("First Industrial Computer Inc"                                                           )},  /* PCG */
	{0x6940, TEXT("Pioneer Computer Inc"                                                                    )},  /* PCI */
	{0x6B40, TEXT("PCBANK21"                                                                                )},  /* PCK */
	{0x6C40, TEXT("pentel.co.,ltd"                                                                          )},  /* PCL */
	{0x6D40, TEXT("PCM Systems Corporation"                                                                 )},  /* PCM */
	{0x6F40, TEXT("Performance Concepts Inc.,"                                                              )},  /* PCO */
	{0x7040, TEXT("Procomp USA Inc"                                                                         )},  /* PCP */
	{0x7440, TEXT("PC-Tel Inc"                                                                              )},  /* PCT */
	{0x7740, TEXT("Pacific CommWare Inc"                                                                    )},  /* PCW */
	{0x7840, TEXT("PC Xperten"                                                                              )},  /* PCX */
	{0x8D40, TEXT("Psion Dacom Plc."                                                                        )},  /* PDM */
	{0x8E40, TEXT("AT&T Paradyne"                                                                           )},  /* PDN */
	{0x9240, TEXT("Pure Data Inc"                                                                           )},  /* PDR */
	{0x9340, TEXT("PD Systems International Ltd"                                                            )},  /* PDS */
	{0x9440, TEXT("PDTS - Prozessdatentechnik und Systeme"                                                  )},  /* PDT */
	{0x9640, TEXT("Prodrive B.V."                                                                           )},  /* PDV */
	{0xA340, TEXT("POTRANS Electrical Corp."                                                                )},  /* PEC */
	{0xA940, TEXT("PEI Electronics Inc"                                                                     )},  /* PEI */
	{0xAC40, TEXT("Primax Electric Ltd"                                                                     )},  /* PEL */
	{0xAE40, TEXT("Interactive Computer Products Inc"                                                       )},  /* PEN */
	{0xB040, TEXT("Peppercon AG"                                                                            )},  /* PEP */
	{0xB240, TEXT("Perceptive Signal Technologies"                                                          )},  /* PER */
	{0xB440, TEXT("Practical Electronic Tools"                                                              )},  /* PET */
	{0xD440, TEXT("Telia ProSoft AB"                                                                        )},  /* PFT */
	{0xED40, TEXT("Paradigm Advanced Research Centre"                                                       )},  /* PGM */
	{0xF040, TEXT("propagamma kommunikation"                                                                )},  /* PGP */
	{0xF340, TEXT("Princeton Graphic Systems"                                                               )},  /* PGS */
	{0x0341, TEXT("Pijnenburg Beheer N.V."                                                                  )},  /* PHC */
	{0x0941, TEXT("DO NOT USE - PHI"                                                                        )},  /* PHI */
	{0x0C41, TEXT("Philips Consumer Electronics Company"                                                    )},  /* PHL */
	{0x0F41, TEXT("Photonics Systems Inc."                                                                  )},  /* PHO */
	{0x1341, TEXT("Philips Communication Systems"                                                           )},  /* PHS */
	{0x1941, TEXT("Phylon Communications"                                                                   )},  /* PHY */
	{0x2541, TEXT("Pacific Image Electronics Company Ltd"                                                   )},  /* PIE */
	{0x2D41, TEXT("Prism, LLC"                                                                              )},  /* PIM */
	{0x2F41, TEXT("Pioneer Electronic Corporation"                                                          )},  /* PIO */
	{0x3841, TEXT("Pixie Tech Inc"                                                                          )},  /* PIX */
	{0x4141, TEXT("Projecta"                                                                                )},  /* PJA */
	{0x4441, TEXT("Projectiondesign AS"                                                                     )},  /* PJD */
	{0x5441, TEXT("Pan Jit International Inc."                                                              )},  /* PJT */
	{0x6141, TEXT("Acco UK ltd. "                                                                           )},  /* PKA */
	{0x8341, TEXT("Pro-Log Corporation"                                                                     )},  /* PLC */
	{0x8D41, TEXT("PROLINK Microsystems Corp."                                                              )},  /* PLM */
	{0x9641, TEXT("PLUS Vision Corp."                                                                       )},  /* PLV */
	{0x9841, TEXT("Parallax Graphics"                                                                       )},  /* PLX */
	{0x9941, TEXT("Polycom Inc."                                                                            )},  /* PLY */
	{0xA341, TEXT("PMC Consumer Electronics Ltd"                                                            )},  /* PMC */
	{0xA441, TEXT("TDK USA Corporation"                                                                     )},  /* PMD */
	{0xAD41, TEXT("Point Multimedia System"                                                                 )},  /* PMM */
	{0xB441, TEXT("Promate Electronic Co., Ltd."                                                            )},  /* PMT */
	{0xB841, TEXT("Photomatrix"                                                                             )},  /* PMX */
	{0xC741, TEXT("Microsoft"                                                                               )},  /* PNG */
	{0xC741, TEXT("Microsoft"                                                                               )},  /* PNG */
	{0xCC41, TEXT("Panelview, Inc."                                                                         )},  /* PNL */
	{0xD041, TEXT("Microsoft"                                                                               )},  /* PNP */
	{0xD241, TEXT("Planar Systems, Inc."                                                                    )},  /* PNR */
	{0xD341, TEXT("PanaScope"                                                                               )},  /* PNS */
	{0xD841, TEXT("Phoenix Technologies, Ltd."                                                              )},  /* PNX */
	{0xEC41, TEXT("PolyComp (PTY) Ltd."                                                                     )},  /* POL */
	{0xEE41, TEXT("Perpetual Technologies, LLC"                                                             )},  /* PON */
	{0xF241, TEXT("Portalis LC"                                                                             )},  /* POR */
	{0x0342, TEXT("Phoenixtec Power Company Ltd"                                                            )},  /* PPC */
	{0x0442, TEXT("MEPhI"                                                                                   )},  /* PPD */
	{0x0942, TEXT("Practical Peripherals"                                                                   )},  /* PPI */
	{0x0D42, TEXT("Clinton Electronics Corp."                                                               )},  /* PPM */
	{0x1042, TEXT("Purup Prepress AS"                                                                       )},  /* PPP */
	{0x1242, TEXT("PicPro"                                                                                  )},  /* PPR */
	{0x4142, TEXT("PRO/AUTOMATION"                                                                          )},  /* PRA */
	{0x4342, TEXT("PerComm"                                                                                 )},  /* PRC */
	{0x4442, TEXT("Praim S.R.L."                                                                            )},  /* PRD */
	{0x4642, TEXT("Digital Electronics Corporation"                                                         )},  /* PRF */
	{0x4742, TEXT("The Phoenix Research Group Inc"                                                          )},  /* PRG */
	{0x4942, TEXT("Priva Hortimation BV"                                                                    )},  /* PRI */
	{0x4D42, TEXT("Prometheus"                                                                              )},  /* PRM */
	{0x4F42, TEXT("Proteon"                                                                                 )},  /* PRO */
	{0x5342, TEXT("Leutron Vision"                                                                          )},  /* PRS */
	{0x5842, TEXT("Proxima Corporation"                                                                     )},  /* PRX */
	{0x6142, TEXT("Advanced Signal Processing Technologies"                                                 )},  /* PSA */
	{0x6342, TEXT("Philips Semiconductors"                                                                  )},  /* PSC */
	{0x6442, TEXT("Peus-Systems GmbH"                                                                       )},  /* PSD */
	{0x6542, TEXT("Practical Solutions Pte., Ltd."                                                          )},  /* PSE */
	{0x6942, TEXT("PSI-Perceptive Solutions Inc"                                                            )},  /* PSI */
	{0x6C42, TEXT("Perle Systems Limited"                                                                   )},  /* PSL */
	{0x6D42, TEXT("Prosum"                                                                                  )},  /* PSM */
	{0x7442, TEXT("Global Data SA"                                                                          )},  /* PST */
	{0x8342, TEXT("PS Technology Corporation"                                                               )},  /* PTC */
	{0x8742, TEXT("Cipher Systems Inc"                                                                      )},  /* PTG */
	{0x8842, TEXT("Pathlight Technology Inc"                                                                )},  /* PTH */
	{0x8942, TEXT("Promise Technology Inc"                                                                  )},  /* PTI */
	{0x8C42, TEXT("Pantel Inc"                                                                              )},  /* PTL */
	{0x9342, TEXT("Plain Tree Systems Inc"                                                                  )},  /* PTS */
	{0xC742, TEXT("Proview Global Co., Ltd"                                                                 )},  /* PVG */
	{0xCE42, TEXT("Pixel Vision"                                                                            )},  /* PVN */
	{0xD042, TEXT("Klos Technologies, Inc."                                                                 )},  /* PVP */
	{0x0343, TEXT("Phoenix Contact"                                                                         )},  /* PXC */
	{0x0543, TEXT("PIXELA CORPORATION"                                                                      )},  /* PXE */
	{0x0C43, TEXT("The Moving Pixel Company"                                                                )},  /* PXL */
	{0x0D43, TEXT("Proxim Inc"                                                                              )},  /* PXM */
	{0x6344, TEXT("QuakeCom Company Ltd"                                                                    )},  /* QCC */
	{0x6844, TEXT("Metronics Inc"                                                                           )},  /* QCH */
	{0x6944, TEXT("Quanta Computer Inc"                                                                     )},  /* QCI */
	{0x6B44, TEXT("Quick Corporation"                                                                       )},  /* QCK */
	{0x6C44, TEXT("Quadrant Components Inc"                                                                 )},  /* QCL */
	{0x7044, TEXT("Qualcomm Inc"                                                                            )},  /* QCP */
	{0x8944, TEXT("Quantum Data Incorporated"                                                               )},  /* QDI */
	{0x8D44, TEXT("Quadram"                                                                                 )},  /* QDM */
	{0x9344, TEXT("Quanta Display Inc."                                                                     )},  /* QDS */
	{0xC644, TEXT("Padix Co., Inc."                                                                         )},  /* QFF */
	{0xC944, TEXT("Quickflex, Inc"                                                                          )},  /* QFI */
	{0x8345, TEXT("Q-Logic"                                                                                 )},  /* QLC */
	{0x3146, TEXT("Chuomusen Co., Ltd. "                                                                    )},  /* QQQ */
	{0x6946, TEXT("Quantum Solutions, Inc."                                                                 )},  /* QSI */
	{0x8446, TEXT("Quantum 3D Inc"                                                                          )},  /* QTD */
	{0x8846, TEXT("Questech Ltd"                                                                            )},  /* QTH */
	{0x8946, TEXT("Quicknet Technologies Inc"                                                               )},  /* QTI */
	{0x8D46, TEXT("Quantum"                                                                                 )},  /* QTM */
	{0x9246, TEXT("Qtronix Corporation"                                                                     )},  /* QTR */
	{0xA146, TEXT("Quatographic AG"                                                                         )},  /* QUA */
	{0xA546, TEXT("Questra Consulting"                                                                      )},  /* QUE */
	{0x2348, TEXT("Racore Computer Products Inc"                                                            )},  /* RAC */
	{0x2448, TEXT("Radisys Corporation"                                                                     )},  /* RAD */
	{0x2948, TEXT("Rockwell Automation/Intecolor"                                                           )},  /* RAI */
	{0x2E48, TEXT("Rancho Tech Inc"                                                                         )},  /* RAN */
	{0x3248, TEXT("Raritan, Inc."                                                                           )},  /* RAR */
	{0x3348, TEXT("RAScom Inc"                                                                              )},  /* RAS */
	{0x3448, TEXT("Rent-A-Tech"                                                                             )},  /* RAT */
	{0x3948, TEXT("Raylar Design, Inc."                                                                     )},  /* RAY */
	{0x6548, TEXT("Parc d'Activite des Bellevues"                                                           )},  /* RCE */
	{0x6848, TEXT("Reach Technology Inc"                                                                    )},  /* RCH */
	{0x6948, TEXT("RC International"                                                                        )},  /* RCI */
	{0x6E48, TEXT("Radio Consult SRL"                                                                       )},  /* RCN */
	{0x8948, TEXT("Rainbow Displays, Inc."                                                                  )},  /* RDI */
	{0x8D48, TEXT("Tremon Enterprises Company Ltd"                                                          )},  /* RDM */
	{0x9348, TEXT("Radius Inc"                                                                              )},  /* RDS */
	{0xA148, TEXT("Real D"                                                                                  )},  /* REA */
	{0xA348, TEXT("ReCom"                                                                                   )},  /* REC */
	{0xA448, TEXT("Research Electronics Development Inc"                                                    )},  /* RED */
	{0xA648, TEXT("Reflectivity, Inc."                                                                      )},  /* REF */
	{0xAC48, TEXT("Reliance Electric Ind Corporation"                                                       )},  /* REL */
	{0xAD48, TEXT("SCI Systems Inc."                                                                        )},  /* REM */
	{0xAE48, TEXT("Renesas Technology Corp."                                                                )},  /* REN */
	{0xB348, TEXT("ResMed Pty Ltd"                                                                          )},  /* RES */
	{0xEC48, TEXT("Robertson Geologging Ltd"                                                                )},  /* RGL */
	{0x0D49, TEXT("Rohm Company Ltd"                                                                        )},  /* RHM */
	{0x2949, TEXT("Racal Interlan Inc"                                                                      )},  /* RII */
	{0x2F49, TEXT("Rios Systems Company Ltd"                                                                )},  /* RIO */
	{0x3449, TEXT("Ritech Inc"                                                                              )},  /* RIT */
	{0x3649, TEXT("Rivulet Communications"                                                                  )},  /* RIV */
	{0x4149, TEXT("Roland Corporation"                                                                      )},  /* RJA */
	{0x5349, TEXT("Advanced Engineering"                                                                    )},  /* RJS */
	{0x6349, TEXT("Reakin Technolohy Corporation"                                                           )},  /* RKC */
	{0x8449, TEXT("MEPCO"                                                                                   )},  /* RLD */
	{0x8E49, TEXT("RadioLAN Inc"                                                                            )},  /* RLN */
	{0xA349, TEXT("Raritan Computer, Inc"                                                                   )},  /* RMC */
	{0xB049, TEXT("Research Machines"                                                                       )},  /* RMP */
	{0xC249, TEXT("Rainbow Technologies"                                                                    )},  /* RNB */
	{0xE249, TEXT("Robust Electronics GmbH "                                                                )},  /* ROB */
	{0xE849, TEXT("Rohm Co., Ltd."                                                                          )},  /* ROH */
	{0xEB49, TEXT("Rockwell International"                                                                  )},  /* ROK */
	{0xF049, TEXT("Roper International Ltd"                                                                 )},  /* ROP */
	{0x144A, TEXT("R.P.T.Intergroups"                                                                       )},  /* RPT */
	{0x494A, TEXT("Radicom Research Inc"                                                                    )},  /* RRI */
	{0x634A, TEXT("PhotoTelesis"                                                                            )},  /* RSC */
	{0x684A, TEXT("ADC-Centre"                                                                              )},  /* RSH */
	{0x694A, TEXT("Rampage Systems Inc"                                                                     )},  /* RSI */
	{0x6E4A, TEXT("Radiospire Networks, Inc."                                                               )},  /* RSN */
	{0x714A, TEXT("R Squared"                                                                               )},  /* RSQ */
	{0x734A, TEXT("Rockwell Semiconductor Systems"                                                          )},  /* RSS */
	{0x784A, TEXT("Rapid Tech Corporation"                                                                  )},  /* RSX */
	{0x834A, TEXT("Relia Technologies"                                                                      )},  /* RTC */
	{0x894A, TEXT("Rancho Tech Inc"                                                                         )},  /* RTI */
	{0x8C4A, TEXT("Realtek Semiconductor Company Ltd"                                                       )},  /* RTL */
	{0x934A, TEXT("Raintree Systems"                                                                        )},  /* RTS */
	{0xAE4A, TEXT("RUNCO International"                                                                     )},  /* RUN */
	{0xB04A, TEXT("Ups Manufactoring s.r.l."                                                                )},  /* RUP */
	{0xC34A, TEXT("RSI Systems Inc"                                                                         )},  /* RVC */
	{0xC94A, TEXT("Realvision Inc"                                                                          )},  /* RVI */
	{0xCC4A, TEXT("Reveal Computer Prod"                                                                    )},  /* RVL */
	{0xE34A, TEXT("Red Wing Corporation"                                                                    )},  /* RWC */
	{0x144B, TEXT("Tectona SoftSolutions (P) Ltd.,"                                                         )},  /* RXT */
	{0x214C, TEXT("Sanritz Automation Co.,Ltd."                                                             )},  /* SAA */
	{0x254C, TEXT("Saab Aerotech"                                                                           )},  /* SAE */
	{0x274C, TEXT("Sedlbauer"                                                                               )},  /* SAG */
	{0x294C, TEXT("Sage Inc"                                                                                )},  /* SAI */
	{0x2B4C, TEXT("Saitek Ltd"                                                                              )},  /* SAK */
	{0x2D4C, TEXT("Samsung Electric Company"                                                                )},  /* SAM */
	{0x2E4C, TEXT("Sanyo Electric Co.,Ltd."                                                                 )},  /* SAN */
	{0x334C, TEXT("Stores Automated Systems Inc"                                                            )},  /* SAS */
	{0x344C, TEXT("Shuttle Tech"                                                                            )},  /* SAT */
	{0x434C, TEXT("Shanghai Bell Telephone Equip Mfg Co"                                                    )},  /* SBC */
	{0x444C, TEXT("Softbed - Consulting & Development Ltd"                                                  )},  /* SBD */
	{0x494C, TEXT("SMART Technologies Inc."                                                                 )},  /* SBI */
	{0x534C, TEXT("SBS-or Industrial Computers GmbH"                                                        )},  /* SBS */
	{0x544C, TEXT("Senseboard Technologies AB"                                                              )},  /* SBT */
	{0x634C, TEXT("SORD Computer Corporation"                                                               )},  /* SCC */
	{0x644C, TEXT("Sanyo Electric Company Ltd"                                                              )},  /* SCD */
	{0x654C, TEXT("Sun Corporation"                                                                         )},  /* SCE */
	{0x684C, TEXT("Schlumberger Cards"                                                                      )},  /* SCH */
	{0x694C, TEXT("System Craft"                                                                            )},  /* SCI */
	{0x6C4C, TEXT("Sigmacom Co., Ltd."                                                                      )},  /* SCL */
	{0x6D4C, TEXT("SCM Microsystems Inc"                                                                    )},  /* SCM */
	{0x6E4C, TEXT("Scanport, Inc."                                                                          )},  /* SCN */
	{0x6F4C, TEXT("SORCUS Computer GmbH"                                                                    )},  /* SCO */
	{0x704C, TEXT("Scriptel Corporation"                                                                    )},  /* SCP */
	{0x724C, TEXT("Systran Corporation"                                                                     )},  /* SCR */
	{0x734C, TEXT("Nanomach Anstalt"                                                                        )},  /* SCS */
	{0x744C, TEXT("Smart Card Technology"                                                                   )},  /* SCT */
	{0x814C, TEXT("SAT (Societe Anonyme)"                                                                   )},  /* SDA */
	{0x844C, TEXT("Intrada-SDD Ltd"                                                                         )},  /* SDD */
	{0x854C, TEXT("Sherwood Digital Electronics Corporation"                                                )},  /* SDE */
	{0x864C, TEXT("SODIFF E&T CO., Ltd."                                                                    )},  /* SDF */
	{0x884C, TEXT("Communications Specialies, Inc."                                                         )},  /* SDH */
	{0x894C, TEXT("Samtron Displays Inc"                                                                    )},  /* SDI */
	{0x8B4C, TEXT("SAIT-Devlonics"                                                                          )},  /* SDK */
	{0x924C, TEXT("SDR Systems"                                                                             )},  /* SDR */
	{0x934C, TEXT("SunRiver Data System"                                                                    )},  /* SDS */
	{0x944C, TEXT("Siemens AG"                                                                              )},  /* SDT */
	{0x984C, TEXT("SDX Business Systems Ltd"                                                                )},  /* SDX */
	{0xA14C, TEXT("Seanix Technology Inc."                                                                  )},  /* SEA */
	{0xA24C, TEXT("system elektronik GmbH"                                                                  )},  /* SEB */
	{0xA34C, TEXT("Seiko Epson Corporation"                                                                 )},  /* SEC */
	{0xA54C, TEXT("SeeColor Corporation"                                                                    )},  /* SEE */
	{0xA94C, TEXT("Seitz & Associates Inc"                                                                  )},  /* SEI */
	{0xAC4C, TEXT("Way2Call Communications"                                                                 )},  /* SEL */
	{0xAD4C, TEXT("Samsung Electronics Company Ltd"                                                         )},  /* SEM */
	{0xAE4C, TEXT("Sencore"                                                                                 )},  /* SEN */
	{0xAF4C, TEXT("SEOS Ltd"                                                                                )},  /* SEO */
	{0xB04C, TEXT("SEP Eletronica Ltda."                                                                    )},  /* SEP */
	{0xB24C, TEXT("Sony Ericsson Mobile Communications Inc."                                                )},  /* SER */
	{0xB44C, TEXT("SendTek Corporation"                                                                     )},  /* SET */
	{0xCD4C, TEXT("TORNADO Company"                                                                         )},  /* SFM */
	{0xD44C, TEXT("Mikroforum Ring 3"                                                                       )},  /* SFT */
	{0xE34C, TEXT("Spectragraphics Corporation"                                                             )},  /* SGC */
	{0xE44C, TEXT("Sigma Designs, Inc."                                                                     )},  /* SGD */
	{0xE54C, TEXT("Kansai Electric Company Ltd"                                                             )},  /* SGE */
	{0xE94C, TEXT("Scan Group Ltd"                                                                          )},  /* SGI */
	{0xEC4C, TEXT("Super Gate Technology Company Ltd"                                                       )},  /* SGL */
	{0xED4C, TEXT("SAGEM"                                                                                   )},  /* SGM */
	{0xEF4C, TEXT("Logos Design A/S"                                                                        )},  /* SGO */
	{0xF44C, TEXT("Stargate Technology"                                                                     )},  /* SGT */
	{0xF84C, TEXT("Silicon Graphics Inc"                                                                    )},  /* SGX */
	{0xFA4C, TEXT("Systec Computer GmbH"                                                                    )},  /* SGZ */
	{0x034D, TEXT("ShibaSoku Co., Ltd."                                                                     )},  /* SHC */
	{0x074D, TEXT("Soft & Hardware development Goldammer GmbH"                                              )},  /* SHG */
	{0x094D, TEXT("Jiangsu Shinco Electronic Group Co., Ltd"                                                )},  /* SHI */
	{0x104D, TEXT("Sharp Corporation"                                                                       )},  /* SHP */
	{0x124D, TEXT("Digital Discovery"                                                                       )},  /* SHR */
	{0x144D, TEXT("Shin Ho Tech"                                                                            )},  /* SHT */
	{0x214D, TEXT("SIEMENS AG"                                                                              )},  /* SIA */
	{0x224D, TEXT("Sanyo Electric Company Ltd"                                                              )},  /* SIB */
	{0x234D, TEXT("Sysmate Corporation"                                                                     )},  /* SIC */
	{0x244D, TEXT("Seiko Instruments Information Devices Inc"                                               )},  /* SID */
	{0x254D, TEXT("Siemens"                                                                                 )},  /* SIE */
	{0x274D, TEXT("Sigma Designs Inc"                                                                       )},  /* SIG */
	{0x294D, TEXT("Silicon Image, Inc."                                                                     )},  /* SII */
	{0x2C4D, TEXT("Silicon Laboratories, Inc"                                                               )},  /* SIL */
	{0x2D4D, TEXT("S3 Inc"                                                                                  )},  /* SIM */
	{0x2E4D, TEXT("Singular Technology Co., Ltd."                                                           )},  /* SIN */
	{0x324D, TEXT("Sirius Technologies Pty Ltd"                                                             )},  /* SIR */
	{0x334D, TEXT("Silicon Integrated Systems Corporation"                                                  )},  /* SIS */
	{0x344D, TEXT("Sitintel"                                                                                )},  /* SIT */
	{0x354D, TEXT("Seiko Instruments USA Inc"                                                               )},  /* SIU */
	{0x384D, TEXT("Zuniq Data Corporation"                                                                  )},  /* SIX */
	{0x454D, TEXT("Sejin Electron Inc"                                                                      )},  /* SJE */
	{0x644D, TEXT("Schneider & Koch"                                                                        )},  /* SKD */
	{0x744D, TEXT("Samsung Electro-Mechanics Company Ltd"                                                   )},  /* SKT */
	{0x794D, TEXT("SKYDATA S.P.A."                                                                          )},  /* SKY */
	{0x814D, TEXT("Systeme Lauer GmbH&Co KG"                                                                )},  /* SLA */
	{0x824D, TEXT("Shlumberger Ltd"                                                                         )},  /* SLB */
	{0x834D, TEXT("Syslogic Datentechnik AG"                                                                )},  /* SLC */
	{0x884D, TEXT("Silicon Library Inc."                                                                    )},  /* SLH */
	{0x894D, TEXT("Symbios Logic Inc"                                                                       )},  /* SLI */
	{0x8B4D, TEXT("Silitek Corporation"                                                                     )},  /* SLK */
	{0x8D4D, TEXT("Solomon Technology Corporation"                                                          )},  /* SLM */
	{0x924D, TEXT("Schlumberger Technology Corporate"                                                       )},  /* SLR */
	{0x944D, TEXT("Salt Internatioinal Corp."                                                               )},  /* SLT */
	{0x984D, TEXT("Specialix"                                                                               )},  /* SLX */
	{0xA14D, TEXT("SMART Modular Technologies"                                                              )},  /* SMA */
	{0xA24D, TEXT("Schlumberger"                                                                            )},  /* SMB */
	{0xA34D, TEXT("Standard Microsystems Corporation"                                                       )},  /* SMC */
	{0xA54D, TEXT("Sysmate Company"                                                                         )},  /* SME */
	{0xA94D, TEXT("SpaceLabs Medical Inc"                                                                   )},  /* SMI */
	{0xAB4D, TEXT("SMK CORPORATION"                                                                         )},  /* SMK */
	{0xAC4D, TEXT("Sumitomo Metal Industries, Ltd."                                                         )},  /* SML */
	{0xAD4D, TEXT("Shark Multimedia Inc"                                                                    )},  /* SMM */
	{0xAF4D, TEXT("STMicroelectronics"                                                                      )},  /* SMO */
	{0xB04D, TEXT("Simple Computing"                                                                        )},  /* SMP */
	{0xB24D, TEXT("B.& V. s.r.l."                                                                           )},  /* SMR */
	{0xB34D, TEXT("Silicom Multimedia Systems Inc"                                                          )},  /* SMS */
	{0xB44D, TEXT("Silcom Manufacturing Tech Inc"                                                           )},  /* SMT */
	{0xC34D, TEXT("Sentronic International Corp."                                                           )},  /* SNC */
	{0xC94D, TEXT("Siemens Microdesign GmbH"                                                                )},  /* SNI */
	{0xCB4D, TEXT("S&K Electronics"                                                                         )},  /* SNK */
	{0xCF4D, TEXT("SINOSUN TECHNOLOGY CO., LTD"                                                             )},  /* SNO */
	{0xD04D, TEXT("Siemens Nixdorf Info Systems"                                                            )},  /* SNP */
	{0xD34D, TEXT("Cirtech (UK) Ltd"                                                                        )},  /* SNS */
	{0xD44D, TEXT("SuperNet Inc"                                                                            )},  /* SNT */
	{0xD74D, TEXT("Snell & Wilcox"                                                                          )},  /* SNW */
	{0xD84D, TEXT("Sonix Comm. Ltd"                                                                         )},  /* SNX */
	{0xD94D, TEXT("Sony"                                                                                    )},  /* SNY */
	{0xE94D, TEXT("Silicon Optix Corporation"                                                               )},  /* SOI */
	{0xEC4D, TEXT("Solitron Technologies Inc"                                                               )},  /* SOL */
	{0xEE4D, TEXT("Sony"                                                                                    )},  /* SON */
	{0xF24D, TEXT("Sorcus Computer GmbH"                                                                    )},  /* SOR */
	{0xF44D, TEXT("Sotec Company Ltd"                                                                       )},  /* SOT */
	{0xF94D, TEXT("SOYO Group, Inc"                                                                         )},  /* SOY */
	{0x034E, TEXT("SpinCore Technologies, Inc"                                                              )},  /* SPC */
	{0x054E, TEXT("SPEA Software AG"                                                                        )},  /* SPE */
	{0x084E, TEXT("G&W Instruments GmbH"                                                                    )},  /* SPH */
	{0x094E, TEXT("SPACE-I Co., Ltd."                                                                       )},  /* SPI */
	{0x0C4E, TEXT("Smart Silicon Systems Pty Ltd"                                                           )},  /* SPL */
	{0x0E4E, TEXT("Sapience Corporation"                                                                    )},  /* SPN */
	{0x124E, TEXT("pmns GmbH"                                                                               )},  /* SPR */
	{0x134E, TEXT("Synopsys Inc"                                                                            )},  /* SPS */
	{0x144E, TEXT("Sceptre Tech Inc"                                                                        )},  /* SPT */
	{0x154E, TEXT("SIM2 Multimedia S.P.A."                                                                  )},  /* SPU */
	{0x184E, TEXT("Simplex Time Recorder Co."                                                               )},  /* SPX */
	{0x344E, TEXT("Sequent Computer Systems Inc"                                                            )},  /* SQT */
	{0x434E, TEXT("Integrated Tech Express Inc"                                                             )},  /* SRC */
	{0x444E, TEXT("Setred"                                                                                  )},  /* SRD */
	{0x464E, TEXT("Surf Communication Solutions Ltd"                                                        )},  /* SRF */
	{0x474E, TEXT("Intuitive Surgical, Inc."                                                                )},  /* SRG */
	{0x544E, TEXT("SeeReal Technologies GmbH"                                                               )},  /* SRT */
	{0x634E, TEXT("Sierra Semiconductor Inc"                                                                )},  /* SSC */
	{0x644E, TEXT("FlightSafety International"                                                              )},  /* SSD */
	{0x654E, TEXT("Samsung Electronic Co."                                                                  )},  /* SSE */
	{0x694E, TEXT("S-S Technology Inc"                                                                      )},  /* SSI */
	{0x6A4E, TEXT("Sankyo Seiki Mfg.co., Ltd"                                                               )},  /* SSJ */
	{0x704E, TEXT("Spectrum Signal Proecessing Inc"                                                         )},  /* SSP */
	{0x734E, TEXT("S3 Inc"                                                                                  )},  /* SSS */
	{0x744E, TEXT("SystemSoft Corporation"                                                                  )},  /* SST */
	{0x814E, TEXT("ST Electronics Systems Assembly Pte Ltd"                                                 )},  /* STA */
	{0x824E, TEXT("STB Systems Inc"                                                                         )},  /* STB */
	{0x834E, TEXT("STAC Electronics"                                                                        )},  /* STC */
	{0x844E, TEXT("STD Computer Inc"                                                                        )},  /* STD */
	{0x854E, TEXT("SII Ido-Tsushin Inc"                                                                     )},  /* STE */
	{0x864E, TEXT("Starflight Electronics"                                                                  )},  /* STF */
	{0x874E, TEXT("StereoGraphics Corp."                                                                    )},  /* STG */
	{0x884E, TEXT("Semtech Corporation"                                                                     )},  /* STH */
	{0x894E, TEXT("Smart Tech Inc"                                                                          )},  /* STI */
	{0x8B4E, TEXT("SANTAK CORP."                                                                            )},  /* STK */
	{0x8C4E, TEXT("SigmaTel Inc"                                                                            )},  /* STL */
	{0x8D4E, TEXT("SGS Thomson Microelectronics"                                                            )},  /* STM */
	{0x8E4E, TEXT("Samsung Electronics America"                                                             )},  /* STN */
	{0x8F4E, TEXT("Stollmann E+V GmbH"                                                                      )},  /* STO */
	{0x904E, TEXT("StreamPlay Ltd"                                                                          )},  /* STP */
	{0x924E, TEXT("Starlight Networks Inc"                                                                  )},  /* STR */
	{0x934E, TEXT("SITECSYSTEM CO., LTD."                                                                   )},  /* STS */
	{0x944E, TEXT("Star Paging Telecom Tech (Shenzhen) Co. Ltd."                                            )},  /* STT */
	{0x974E, TEXT("Starwin Inc."                                                                            )},  /* STW */
	{0x994E, TEXT("SDS Technologies"                                                                        )},  /* STY */
	{0xA24E, TEXT("Subspace Comm. Inc"                                                                      )},  /* SUB */
	{0xAD4E, TEXT("Summagraphics Corporation"                                                               )},  /* SUM */
	{0xAE4E, TEXT("Sun Electronics Corporation"                                                             )},  /* SUN */
	{0xB04E, TEXT("Supra Corporation"                                                                       )},  /* SUP */
	{0xB24E, TEXT("Surenam Computer Corporation"                                                            )},  /* SUR */
	{0xC14E, TEXT("SGEG"                                                                                    )},  /* SVA */
	{0xC34E, TEXT("Intellix Corp."                                                                          )},  /* SVC */
	{0xC44E, TEXT("SVD Computer"                                                                            )},  /* SVD */
	{0xC94E, TEXT("Sun Microsystems"                                                                        )},  /* SVI */
	{0xD34E, TEXT("SVSI"                                                                                    )},  /* SVS */
	{0xD44E, TEXT("SEVIT Co., Ltd."                                                                         )},  /* SVT */
	{0xE34E, TEXT("Software Café"                                                                           )},  /* SWC */
	{0xE94E, TEXT("Sierra Wireless Inc."                                                                    )},  /* SWI */
	{0xEC4E, TEXT("Sharedware Ltd"                                                                          )},  /* SWL */
	{0xF34E, TEXT("Static"                                                                                  )},  /* SWS */
	{0xF44E, TEXT("Software Technologies Group,Inc."                                                        )},  /* SWT */
	{0x024F, TEXT("Syntax-Brillian"                                                                         )},  /* SXB */
	{0x044F, TEXT("Silex technology, Inc."                                                                  )},  /* SXD */
	{0x0C4F, TEXT("SolutionInside"                                                                          )},  /* SXL */
	{0x234F, TEXT("Sysmic"                                                                                  )},  /* SYC */
	{0x2B4F, TEXT("Stryker Communications"                                                                  )},  /* SYK */
	{0x2C4F, TEXT("Sylvania Computer Products"                                                              )},  /* SYL */
	{0x2D4F, TEXT("Symicron Computer Communications Ltd."                                                   )},  /* SYM */
	{0x2E4F, TEXT("Synaptics Inc"                                                                           )},  /* SYN */
	{0x304F, TEXT("SYPRO Co Ltd"                                                                            )},  /* SYP */
	{0x334F, TEXT("Sysgration Ltd"                                                                          )},  /* SYS */
	{0x344F, TEXT("Seyeon Tech Company Ltd"                                                                 )},  /* SYT */
	{0x364F, TEXT("SYVAX Inc"                                                                               )},  /* SYV */
	{0x384F, TEXT("Prime Systems, Inc."                                                                     )},  /* SYX */
	{0x2150, TEXT("Tandberg"                                                                                )},  /* TAA */
	{0x2250, TEXT("Todos Data System AB"                                                                    )},  /* TAB */
	{0x2750, TEXT("Teles AG"                                                                                )},  /* TAG */
	{0x2950, TEXT("Toshiba America Info Systems Inc"                                                        )},  /* TAI */
	{0x2D50, TEXT("Tamura Seisakusyo Ltd"                                                                   )},  /* TAM */
	{0x3350, TEXT("Taskit Rechnertechnik GmbH"                                                              )},  /* TAS */
	{0x3450, TEXT("Teleliaison Inc"                                                                         )},  /* TAT */
	{0x3850, TEXT("Taxan (Europe) Ltd"                                                                      )},  /* TAX */
	{0x4250, TEXT("Triple S Engineering Inc"                                                                )},  /* TBB */
	{0x4350, TEXT("Turbo Communication, Inc"                                                                )},  /* TBC */
	{0x5350, TEXT("Turtle Beach System"                                                                     )},  /* TBS */
	{0x6350, TEXT("Tandon Corporation"                                                                      )},  /* TCC */
	{0x6450, TEXT("Taicom Data Systems Co., Ltd."                                                           )},  /* TCD */
	{0x6550, TEXT("Century Corporation"                                                                     )},  /* TCE */
	{0x6850, TEXT("Interaction Systems, Inc"                                                                )},  /* TCH */
	{0x6950, TEXT("Tulip Computers Int'l B.V."                                                              )},  /* TCI */
	{0x6A50, TEXT("TEAC America Inc"                                                                        )},  /* TCJ */
	{0x6C50, TEXT("Technical Concepts Ltd"                                                                  )},  /* TCL */
	{0x6D50, TEXT("3Com Corporation"                                                                        )},  /* TCM */
	{0x6E50, TEXT("Tecnetics (PTY) Ltd"                                                                     )},  /* TCN */
	{0x6F50, TEXT("Thomas-Conrad Corporation"                                                               )},  /* TCO */
	{0x7250, TEXT("Thomson Consumer Electronics"                                                            )},  /* TCR */
	{0x7350, TEXT("Tatung Company of America Inc"                                                           )},  /* TCS */
	{0x7450, TEXT("Telecom Technology Centre Co. Ltd."                                                      )},  /* TCT */
	{0x7850, TEXT("FREEMARS Heavy Industries"                                                               )},  /* TCX */
	{0x8350, TEXT("Teradici"                                                                                )},  /* TDC */
	{0x8450, TEXT("Tandberg Data Display AS"                                                                )},  /* TDD */
	{0x8B50, TEXT("TDK USA Corporation"                                                                     )},  /* TDK */
	{0x8D50, TEXT("Tandem Computer Europe Inc"                                                              )},  /* TDM */
	{0x9050, TEXT("3D Perception"                                                                           )},  /* TDP */
	{0x9350, TEXT("Tri-Data Systems Inc"                                                                    )},  /* TDS */
	{0x9450, TEXT("TDT"                                                                                     )},  /* TDT */
	{0x9650, TEXT("TDVision Systems, Inc."                                                                  )},  /* TDV */
	{0x9950, TEXT("Tandy Electronics"                                                                       )},  /* TDY */
	{0xA150, TEXT("TEAC System Corporation"                                                                 )},  /* TEA */
	{0xA350, TEXT("Tecmar Inc"                                                                              )},  /* TEC */
	{0xAB50, TEXT("Tektronix Inc"                                                                           )},  /* TEK */
	{0xAC50, TEXT("Promotion and Display Technology Ltd."                                                   )},  /* TEL */
	{0xB250, TEXT("TerraTec Electronic GmbH"                                                                )},  /* TER */
	{0xE950, TEXT("TriGem Computer Inc"                                                                     )},  /* TGI */
	{0xED50, TEXT("TriGem Computer,Inc."                                                                    )},  /* TGM */
	{0xF350, TEXT("Torus Systems Ltd"                                                                       )},  /* TGS */
	{0xF650, TEXT("Grass Valley Germany GmbH"                                                               )},  /* TGV */
	{0x0E51, TEXT("Thundercom Holdings Sdn. Bhd."                                                           )},  /* THN */
	{0x2351, TEXT("Trigem KinfoComm"                                                                        )},  /* TIC */
	{0x3051, TEXT("TIPTEL AG"                                                                               )},  /* TIP */
	{0x3651, TEXT("OOO Technoinvest"                                                                        )},  /* TIV */
	{0x3851, TEXT("Tixi.Com GmbH"                                                                           )},  /* TIX */
	{0x6351, TEXT("Taiko Electric Works.LTD"                                                                )},  /* TKC */
	{0x6E51, TEXT("Teknor Microsystem Inc"                                                                  )},  /* TKN */
	{0x6F51, TEXT("TouchKo, Inc."                                                                           )},  /* TKO */
	{0x7351, TEXT("TimeKeeping Systems, Inc."                                                               )},  /* TKS */
	{0x8151, TEXT("Ferrari Electronic GmbH"                                                                 )},  /* TLA */
	{0x8451, TEXT("Telindus"                                                                                )},  /* TLD */
	{0x8951, TEXT("TOSHIBA TELI CORPORATION"                                                                )},  /* TLI */
	{0x8B51, TEXT("Telelink AG"                                                                             )},  /* TLK */
	{0x9351, TEXT("Teleste Educational OY"                                                                  )},  /* TLS */
	{0x9451, TEXT("Dai Telecom S.p.A."                                                                      )},  /* TLT */
	{0x9651, TEXT("S3 Inc"                                                                                  )},  /* TLV */
	{0x9851, TEXT("Telxon Corporation"                                                                      )},  /* TLX */
	{0xA351, TEXT("Techmedia Computer Systems Corporation"                                                  )},  /* TMC */
	{0xA551, TEXT("AT&T Microelectronics"                                                                   )},  /* TME */
	{0xA951, TEXT("Texas Microsystem"                                                                       )},  /* TMI */
	{0xAD51, TEXT("Time Management, Inc."                                                                   )},  /* TMM */
	{0xB251, TEXT("Taicom International Inc"                                                                )},  /* TMR */
	{0xB351, TEXT("Trident Microsystems Ltd"                                                                )},  /* TMS */
	{0xB451, TEXT("T-Metrics Inc."                                                                          )},  /* TMT */
	{0xB851, TEXT("Thermotrex Corporation"                                                                  )},  /* TMX */
	{0xC351, TEXT("TNC Industrial Company Ltd"                                                              )},  /* TNC */
	{0xCD51, TEXT("TECNIMAGEN SA"                                                                           )},  /* TNM */
	{0xD951, TEXT("Tennyson Tech Pty Ltd"                                                                   )},  /* TNY */
	{0xE551, TEXT("TOEI Electronics Co., Ltd."                                                              )},  /* TOE */
	{0xE751, TEXT("The OPEN Group"                                                                          )},  /* TOG */
	{0xF051, TEXT("Orion Communications Co., Ltd."                                                          )},  /* TOP */
	{0xF351, TEXT("Toshiba Corporation"                                                                     )},  /* TOS */
	{0xF551, TEXT("Touchstone Technology"                                                                   )},  /* TOU */
	{0x0352, TEXT("Touch Panel Systems Corporation"                                                         )},  /* TPC */
	{0x0552, TEXT("Technology Power Enterprises Inc"                                                        )},  /* TPE */
	{0x0A52, TEXT("(none)"                                                                                  )},  /* TPJ */
	{0x0B52, TEXT("TOPRE CORPORATION"                                                                       )},  /* TPK */
	{0x1252, TEXT("Topro Technology Inc"                                                                    )},  /* TPR */
	{0x1352, TEXT("Teleprocessing Systeme GmbH"                                                             )},  /* TPS */
	{0x1652, TEXT("Top Victory Electronics ( Fujian ) Company Ltd"                                          )},  /* TPV */
	{0x1A52, TEXT("Ypoaz Systems Inc"                                                                       )},  /* TPZ */
	{0x4152, TEXT("TriTech Microelectronics International"                                                  )},  /* TRA */
	{0x4352, TEXT("Trioc AB"                                                                                )},  /* TRC */
	{0x4452, TEXT("Trident Microsystem Inc"                                                                 )},  /* TRD */
	{0x4552, TEXT("Tremetrics"                                                                              )},  /* TRE */
	{0x4952, TEXT("Tricord Systems"                                                                         )},  /* TRI */
	{0x4C52, TEXT("Royal Information"                                                                       )},  /* TRL */
	{0x4D52, TEXT("Tekram Technology Company Ltd"                                                           )},  /* TRM */
	{0x4E52, TEXT("Datacommunicatie Tron B.V."                                                              )},  /* TRN */
	{0x5352, TEXT("Torus Systems Ltd"                                                                       )},  /* TRS */
	{0x5552, TEXT("Aashima Technology B.V."                                                                 )},  /* TRU */
	{0x5852, TEXT("Trex Enterprises"                                                                        )},  /* TRX */
	{0x6252, TEXT("Toshiba America Info Systems Inc"                                                        )},  /* TSB */
	{0x6352, TEXT("Sanyo Electric Company Ltd"                                                              )},  /* TSC */
	{0x6452, TEXT("TechniSat Digital GmbH"                                                                  )},  /* TSD */
	{0x6552, TEXT("Tottori Sanyo Electric"                                                                  )},  /* TSE */
	{0x6652, TEXT("Racal-Airtech Software Forge Ltd"                                                        )},  /* TSF */
	{0x6752, TEXT("The Software Group Ltd"                                                                  )},  /* TSG */
	{0x6952, TEXT("TeleVideo Systems"                                                                       )},  /* TSI */
	{0x6C52, TEXT("Tottori SANYO Electric Co., Ltd."                                                        )},  /* TSL */
	{0x7052, TEXT("U.S. Navy"                                                                               )},  /* TSP */
	{0x7452, TEXT("Transtream Inc"                                                                          )},  /* TST */
	{0x7952, TEXT("TouchSystems"                                                                            )},  /* TSY */
	{0x8152, TEXT("Topson Technology Co., Ltd."                                                             )},  /* TTA */
	{0x8252, TEXT("National Semiconductor Japan Ltd"                                                        )},  /* TTB */
	{0x8352, TEXT("Telecommunications Techniques Corporation"                                               )},  /* TTC */
	{0x8552, TEXT("TTE, Inc."                                                                               )},  /* TTE */
	{0x8952, TEXT("Trenton Terminals Inc"                                                                   )},  /* TTI */
	{0x8B52, TEXT("Totoku Electric Company Ltd"                                                             )},  /* TTK */
	{0x8C52, TEXT("2-Tel B.V."                                                                              )},  /* TTL */
	{0x9352, TEXT("TechnoTrend Systemtechnik GmbH"                                                          )},  /* TTS */
	{0xB452, TEXT("Tut Systems"                                                                             )},  /* TUT */
	{0xC452, TEXT("Tecnovision"                                                                             )},  /* TVD */
	{0xC952, TEXT("Truevision"                                                                              )},  /* TVI */
	{0xCD52, TEXT("Taiwan Video & Monitor Corporation"                                                      )},  /* TVM */
	{0xCF52, TEXT("TV One Ltd"                                                                              )},  /* TVO */
	{0xD252, TEXT("TV Interactive Corporation"                                                              )},  /* TVR */
	{0xD352, TEXT("TVS Electronics Limited"                                                                 )},  /* TVS */
	{0xE152, TEXT("Tidewater Association"                                                                   )},  /* TWA */
	{0xE552, TEXT("Kontron Electronik"                                                                      )},  /* TWE */
	{0xE852, TEXT("Twinhead International Corporation"                                                      )},  /* TWH */
	{0xE952, TEXT("Easytel oy"                                                                              )},  /* TWI */
	{0xEB52, TEXT("TOWITOKO electronics GmbH"                                                               )},  /* TWK */
	{0x0C53, TEXT("Trixel Ltd"                                                                              )},  /* TXL */
	{0x0E53, TEXT("Texas Insturments"                                                                       )},  /* TXN */
	{0x1453, TEXT("Textron Defense System"                                                                  )},  /* TXT */
	{0x2E53, TEXT("Tyan Computer Corporation"                                                               )},  /* TYN */
	{0x3354, TEXT("Ultima Associates Pte Ltd"                                                               )},  /* UAS */
	{0x4954, TEXT("Ungermann-Bass Inc"                                                                      )},  /* UBI */
	{0x4C54, TEXT("Ubinetics Ltd."                                                                          )},  /* UBL */
	{0x8E54, TEXT("Uniden Corporation"                                                                      )},  /* UDN */
	{0xA354, TEXT("Ultima Electronics Corporation"                                                          )},  /* UEC */
	{0xA754, TEXT("Elitegroup Computer Systems Company Ltd"                                                 )},  /* UEG */
	{0xA954, TEXT("Universal Electronics Inc"                                                               )},  /* UEI */
	{0xB454, TEXT("Universal Empowering Technologies"                                                       )},  /* UET */
	{0xC754, TEXT("UNIGRAF-USA"                                                                             )},  /* UFG */
	{0xCF54, TEXT("UFO Systems Inc"                                                                         )},  /* UFO */
	{0x0255, TEXT("XOCECO"                                                                                  )},  /* UHB */
	{0x2355, TEXT("Uniform Industrial Corporation"                                                          )},  /* UIC */
	{0x5255, TEXT("Ueda Japan Radio Co., Ltd."                                                              )},  /* UJR */
	{0x9455, TEXT("Ultra Network Tech"                                                                      )},  /* ULT */
	{0xA355, TEXT("United Microelectr Corporation"                                                          )},  /* UMC */
	{0xA755, TEXT("Umezawa Giken Co.,Ltd"                                                                   )},  /* UMG */
	{0xAD55, TEXT("Universal Multimedia"                                                                    )},  /* UMM */
	{0xC155, TEXT("Unisys DSD"                                                                              )},  /* UNA */
	{0xC255, TEXT("Unisys Corporation"                                                                      )},  /* UNB */
	{0xC355, TEXT("Unisys Corporation"                                                                      )},  /* UNC */
	{0xC455, TEXT("DO NOT USE - UND"                                                                        )},  /* UND */
	{0xC555, TEXT("DO NOT USE - UNE"                                                                        )},  /* UNE */
	{0xC655, TEXT("DO NOT USE - UNF"                                                                        )},  /* UNF */
	{0xC955, TEXT("Unisys Corporation"                                                                      )},  /* UNI */
	{0xC955, TEXT("Unisys Corporation"                                                                      )},  /* UNI */
	{0xCD55, TEXT("Unisys Corporation"                                                                      )},  /* UNM */
	{0xCF55, TEXT("Unisys Corporation"                                                                      )},  /* UNO */
	{0xD055, TEXT("Unitop"                                                                                  )},  /* UNP */
	{0xD355, TEXT("Unisys Corporation"                                                                      )},  /* UNS */
	{0xD455, TEXT("Unisys Corporation"                                                                      )},  /* UNT */
	{0xD955, TEXT("Unicate"                                                                                 )},  /* UNY */
	{0x1056, TEXT("UPPI"                                                                                    )},  /* UPP */
	{0x1356, TEXT("Systems Enhancement"                                                                     )},  /* UPS */
	{0x4456, TEXT("Video Computer S.p.A."                                                                   )},  /* URD */
	{0x6156, TEXT("Utimaco Safeware AG"                                                                     )},  /* USA */
	{0x6456, TEXT("U.S. Digital Corporation"                                                                )},  /* USD */
	{0x6956, TEXT("Universal Scientific Industrial Co., Ltd."                                               )},  /* USI */
	{0x7256, TEXT("U.S. Robotics Inc"                                                                       )},  /* USR */
	{0x8456, TEXT("Up to Date Tech"                                                                         )},  /* UTD */
	{0xE356, TEXT("Uniwill Computer Corp."                                                                  )},  /* UWC */
	{0x2C58, TEXT("Valence Computing Corporation"                                                           )},  /* VAL */
	{0x3258, TEXT("Varian Australia Pty Ltd"                                                                )},  /* VAR */
	{0x5458, TEXT("Valley Board Ltda"                                                                       )},  /* VBT */
	{0x6358, TEXT("Virtual Computer Corporation"                                                            )},  /* VCC */
	{0x6958, TEXT("VistaCom Inc"                                                                            )},  /* VCI */
	{0x6A58, TEXT("Victor Company of Japan, Limited"                                                        )},  /* VCJ */
	{0x6D58, TEXT("Vector Magnetics, LLC"                                                                   )},  /* VCM */
	{0x7858, TEXT("VCONEX"                                                                                  )},  /* VCX */
	{0x8158, TEXT("Victor Data Systems"                                                                     )},  /* VDA */
	{0x8D58, TEXT("Vadem"                                                                                   )},  /* VDM */
	{0x8F58, TEXT("Video & Display Oriented Corporation"                                                    )},  /* VDO */
	{0x9358, TEXT("Vidisys GmbH & Company"                                                                  )},  /* VDS */
	{0x9458, TEXT("Viditec, Inc."                                                                           )},  /* VDT */
	{0xA358, TEXT("Vector Informatik GmbH"                                                                  )},  /* VEC */
	{0xAB58, TEXT("Vektrex"                                                                                 )},  /* VEK */
	{0xB358, TEXT("Vestel Elektronik Sanayi ve Ticaret A. S."                                               )},  /* VES */
	{0xC958, TEXT("VeriFone Inc"                                                                            )},  /* VFI */
	{0x0959, TEXT("Macrocad Development Inc."                                                               )},  /* VHI */
	{0x2159, TEXT("VIA Tech Inc"                                                                            )},  /* VIA */
	{0x2259, TEXT("Tatung UK Ltd"                                                                           )},  /* VIB */
	{0x2359, TEXT("Victron B.V."                                                                            )},  /* VIC */
	{0x2459, TEXT("Ingram Macrotron Germany"                                                                )},  /* VID */
	{0x2B59, TEXT("Viking Connectors"                                                                       )},  /* VIK */
	{0x2E59, TEXT("Vine Micros Ltd"                                                                         )},  /* VIN */
	{0x3259, TEXT("Visual Interface, Inc"                                                                   )},  /* VIR */
	{0x3359, TEXT("Visioneer"                                                                               )},  /* VIS */
	{0x3459, TEXT("Visitech AS"                                                                             )},  /* VIT */
	{0x8259, TEXT("ValleyBoard Ltda."                                                                       )},  /* VLB */
	{0x9459, TEXT("VideoLan Technologies"                                                                   )},  /* VLT */
	{0xA959, TEXT("Vermont Microsystems"                                                                    )},  /* VMI */
	{0xAC59, TEXT("Vine Micros Limited"                                                                     )},  /* VML */
	{0xC359, TEXT("Vinca Corporation"                                                                       )},  /* VNC */
	{0xE259, TEXT("MaxData Computer AG"                                                                     )},  /* VOB */
	{0x125A, TEXT("Best Buy"                                                                                )},  /* VPR */
	{0x435A, TEXT("Virtual Resources Corporation"                                                           )},  /* VRC */
	{0x635A, TEXT("ViewSonic Corporation"                                                                   )},  /* VSC */
	{0x645A, TEXT("3M"                                                                                      )},  /* VSD */
	{0x695A, TEXT("VideoServer"                                                                             )},  /* VSI */
	{0x6E5A, TEXT("Ingram Macrotron"                                                                        )},  /* VSN */
	{0x705A, TEXT("Vision Systems GmbH"                                                                     )},  /* VSP */
	{0x725A, TEXT("V-Star Electronics Inc."                                                                 )},  /* VSR */
	{0x835A, TEXT("VTel Corporation"                                                                        )},  /* VTC */
	{0x875A, TEXT("Voice Technologies Group Inc"                                                            )},  /* VTG */
	{0x895A, TEXT("VLSI Tech Inc"                                                                           )},  /* VTI */
	{0x8B5A, TEXT("Viewteck Co., Ltd."                                                                      )},  /* VTK */
	{0x8C5A, TEXT("Vivid Technology Pte Ltd"                                                                )},  /* VTL */
	{0x935A, TEXT("VTech Computers Ltd"                                                                     )},  /* VTS */
	{0x965A, TEXT("VATIV Technologies"                                                                      )},  /* VTV */
	{0xB45A, TEXT("Vutrix (UK) Ltd"                                                                         )},  /* VUT */
	{0xE25A, TEXT("Vweb Corp."                                                                              )},  /* VWB */
	{0x235C, TEXT("Wacom Tech"                                                                              )},  /* WAC */
	{0x2C5C, TEXT("Wave Access"                                                                             )},  /* WAL */
	{0x365C, TEXT("Wavephore"                                                                               )},  /* WAV */
	{0x4E5C, TEXT("MicroSoftWare"                                                                           )},  /* WBN */
	{0x535C, TEXT("WB Systemtechnik GmbH"                                                                   )},  /* WBS */
	{0x695C, TEXT("Wisecom Inc"                                                                             )},  /* WCI */
	{0x735C, TEXT("Woodwind Communications Systems Inc"                                                     )},  /* WCS */
	{0x835C, TEXT("Western Digital"                                                                         )},  /* WDC */
	{0x855C, TEXT("Westinghouse Digital Electronics"                                                        )},  /* WDE */
	{0xA25C, TEXT("WebGear Inc"                                                                             )},  /* WEB */
	{0xA35C, TEXT("Winbond Electronics Corporation"                                                         )},  /* WEC */
	{0xB95C, TEXT("WEY Design AG"                                                                           )},  /* WEY */
	{0x095D, TEXT("Whistle Communications"                                                                  )},  /* WHI */
	{0x295D, TEXT("Innoware Inc"                                                                            )},  /* WII */
	{0x2C5D, TEXT("WIPRO Information Technology Ltd"                                                        )},  /* WIL */
	{0x2E5D, TEXT("Wintop Technology Inc"                                                                   )},  /* WIN */
	{0x305D, TEXT("Wipro Infotech"                                                                          )},  /* WIP */
	{0x685D, TEXT("Uni-Take Int'l Inc."                                                                     )},  /* WKH */
	{0x845D, TEXT("Wildfire Communications Inc"                                                             )},  /* WLD */
	{0xAC5D, TEXT("Wolfson Microelectronics Ltd"                                                            )},  /* WML */
	{0xAF5D, TEXT("Westermo Teleindustri AB"                                                                )},  /* WMO */
	{0xB45D, TEXT("Winmate Communication Inc"                                                               )},  /* WMT */
	{0xC95D, TEXT("WillNet Inc."                                                                            )},  /* WNI */
	{0xD65D, TEXT("Winnov L.P."                                                                             )},  /* WNV */
	{0xD85D, TEXT("Wincor Nixdorf International GmbH"                                                       )},  /* WNX */
	{0x015E, TEXT("Matsushita Communication Industrial Co., Ltd."                                           )},  /* WPA */
	{0x095E, TEXT("Wearnes Peripherals International (Pte) Ltd"                                             )},  /* WPI */
	{0x435E, TEXT("WiNRADiO Communications"                                                                 )},  /* WRC */
	{0x635E, TEXT("CIS Technology Inc"                                                                      )},  /* WSC */
	{0x705E, TEXT("Wireless And Smart Products Inc."                                                        )},  /* WSP */
	{0x835E, TEXT("ACC Microelectronics"                                                                    )},  /* WTC */
	{0x895E, TEXT("WorkStation Tech"                                                                        )},  /* WTI */
	{0x8B5E, TEXT("Wearnes Thakral Pte"                                                                     )},  /* WTK */
	{0x935E, TEXT("Restek Electric Company Ltd"                                                             )},  /* WTS */
	{0xCD5E, TEXT("Wave Systems Corporation"                                                                )},  /* WVM */
	{0xF65E, TEXT("World Wide Video, Inc."                                                                  )},  /* WWV */
	{0x335F, TEXT("Myse Technology"                                                                         )},  /* WYS */
	{0x345F, TEXT("Wooyoung Image & Information Co.,Ltd."                                                   )},  /* WYT */
	{0x2360, TEXT("XAC Automation Corp"                                                                     )},  /* XAC */
	{0xC760, TEXT("Jan Strapko - FOTO"                                                                      )},  /* XFG */
	{0xCF60, TEXT("EXFO Electro Optical Engineering"                                                        )},  /* XFO */
	{0x2E61, TEXT("Xinex Networks Inc"                                                                      )},  /* XIN */
	{0x2F61, TEXT("Xiotech Corporation"                                                                     )},  /* XIO */
	{0x3261, TEXT("Xirocm Inc"                                                                              )},  /* XIR */
	{0x3461, TEXT("Xitel Pty ltd"                                                                           )},  /* XIT */
	{0x9861, TEXT("Xilinx, Inc."                                                                            )},  /* XLX */
	{0xAD61, TEXT("C3PO S.L."                                                                               )},  /* XMM */
	{0xD461, TEXT("XN Technologies, Inc."                                                                   )},  /* XNT */
	{0x3562, TEXT("SHANGHAI SVA-DAV ELECTRONICS CO., LTD"                                                   )},  /* XQU */
	{0x4362, TEXT("Xircom Inc"                                                                              )},  /* XRC */
	{0x4F62, TEXT("XORO ELECTRONICS (CHENGDU) LIMITED"                                                      )},  /* XRO */
	{0x6E62, TEXT("Xscreen AS"                                                                              )},  /* XSN */
	{0x7462, TEXT("XS Technologies Inc"                                                                     )},  /* XST */
	{0x7962, TEXT("XSYS"                                                                                    )},  /* XSY */
	{0x8462, TEXT("Icuiti Corporation"                                                                      )},  /* XTD */
	{0x8C62, TEXT("Crystal Computer"                                                                        )},  /* XTL */
	{0x8E62, TEXT("X-10 (USA) Inc"                                                                          )},  /* XTN */
	{0x2363, TEXT("Xycotec Computer GmbH"                                                                   )},  /* XYC */
	{0xA464, TEXT("Y-E Data Inc"                                                                            )},  /* YED */
	{0x1165, TEXT("Yokogawa Electric Corporation"                                                           )},  /* YHQ */
	{0x1765, TEXT("Exacom SA"                                                                               )},  /* YHW */
	{0xA865, TEXT("Yamaha Corporation"                                                                      )},  /* YMH */
	{0xF765, TEXT("American Biometric Company"                                                              )},  /* YOW */
	{0x2E68, TEXT("Zandar Technologies plc"                                                                 )},  /* ZAN */
	{0x3868, TEXT("Zefiro Acoustics"                                                                        )},  /* ZAX */
	{0x3A68, TEXT("Zazzle Technologies"                                                                     )},  /* ZAZ */
	{0x5268, TEXT("Zebra Technologies International, LLC"                                                   )},  /* ZBR */
	{0x7468, TEXT("ZeitControl cardsystems GmbH"                                                            )},  /* ZCT */
	{0x9368, TEXT("Zenith Data Systems"                                                                     )},  /* ZDS */
	{0xF468, TEXT("Zenith Data Systems"                                                                     )},  /* ZGT */
	{0x2369, TEXT("ZTEIC DESIGN CO., LTD. "                                                                 )},  /* ZIC */
	{0xB469, TEXT("Zalman Tech Co., Ltd."                                                                   )},  /* ZMT */
	{0xBA69, TEXT("Z Microsystems"                                                                          )},  /* ZMZ */
	{0xC969, TEXT("Zetinet Inc"                                                                             )},  /* ZNI */
	{0xD869, TEXT("Znyx Adv. Systems"                                                                       )},  /* ZNX */
	{0xF769, TEXT("Zowie Intertainment, Inc"                                                                )},  /* ZOW */
	{0x4E6A, TEXT("Zoran Corporation"                                                                       )},  /* ZRN */
	{0x656A, TEXT("Zenith Data Systems"                                                                     )},  /* ZSE */
	{0x836A, TEXT("ZyDAS Technology Corporation"                                                            )},  /* ZTC */
	{0x896A, TEXT("Zoom Telephonics Inc"                                                                    )},  /* ZTI */
	{0x8D6A, TEXT("ZT Group Int'l Inc."                                                                     )},  /* ZTM */
	{0x246B, TEXT("Zydacron Inc"                                                                            )},  /* ZYD */
	{0x306B, TEXT("Zypcom Inc"                                                                              )},  /* ZYP */
	{0x346B, TEXT("Zytex Computers"                                                                         )},  /* ZYT */
	{0x386B, TEXT("Zyxel"                                                                                   )},  /* ZYX */
	{0x5A6B, TEXT("Boca Research Inc"                                                                       )},  /* ZZZ */
	{0x8358, TEXT("VDC Display Systems"                                                                     )},  /* VDC */
	{0x934D, TEXT("Schnick-Schnack-Systems GmbH"                                                            )},  /* SLS */
	{0x6520, TEXT("Hitachi Consumer Electronics Co., Ltd"                                                   )},  /* HCE */
	{0x450F, TEXT("Carl Zeiss AG"                                                                           )},  /* CZE */
	{0x6116, TEXT("Elbit Systems of America"                                                                )},  /* ESA */
	{0x2942, TEXT("Pixel Qi"                                                                                )},  /* PQI */
	{0xC942, TEXT("Prime view international Co., Ltd"                                                       )},  /* PVI */
	{0x842E, TEXT("Takahata Electronics Co.,Ltd."                                                           )},  /* KTD */
	{0x2B38, TEXT("Nakano Engineering Co.,Ltd."                                                             )},  /* NAK */
	{0xE334, TEXT("Mentor Graphics Corporation"                                                             )},  /* MGC */
	{0x3419, TEXT("Feature Integration Technology Inc."                                                     )},  /* FIT */
	{0x6422, TEXT("HannStar Display Corp"                                                                   )},  /* HSD */
	{0x7022, TEXT("HannStar Display Corp"                                                                   )},  /* HSP */
	{0x9414, TEXT("Emerging Display Technologies Corp"                                                      )},  /* EDT */
	{0x8C11, TEXT("Dell Inc"                                                                                )},  /* DLL */
	{0xB411, TEXT("Distributed Management Task Force, Inc. (DMTF) "                                         )},  /* DMT */
	{0x9742, TEXT("DO NOT USE"                                                                              )},  /* PTW */
	{0xC342, TEXT("DO NOT USE"                                                                              )},  /* PVC */
	{0x8B4A, TEXT("DO NOT USE"                                                                              )},  /* RTK */
	{0xA74C, TEXT("DO NOT USE"                                                                              )},  /* SEG */
	{0xCA51, TEXT("DO NOT USE"                                                                              )},  /* TNJ */
	{0x2E5C, TEXT("DO NOT USE"                                                                              )},  /* WAN */
	{0xB260, TEXT("DO NOT USE"                                                                              )},  /* XER */
	{0xE361, TEXT("DO NOT USE"                                                                              )},  /* XOC */
	{0x8519, TEXT("ADTI Media, Inc"                                                                         )},  /* FLE */
	{0xFFFF, NULL},  /* End of list marker */
};
