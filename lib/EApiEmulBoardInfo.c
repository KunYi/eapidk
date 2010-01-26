/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
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
 *I Description: Auto Created for EApiEmulBoardInfo.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiEmulBoardInfo.c
 *I  File Location        : lib
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EApiLib.h>


/*
 *
 *  
 *
 *  Get String
 *
 *
 *
 */
typedef struct StringLookupTbl_s{
  uint32_t Id          ; /* EAPI String Id */
  char    *StringPtr   ; /* Pointer to Return String */
}StringLookupTbl_t;
const StringLookupTbl_t StringLookup[]={
  {EAPI_ID_BOARD_MANUFACTURER_STR  , "PICMG"                  },
  {EAPI_ID_BOARD_NAME_STR          , "SAMPLE API"             },
  {EAPI_ID_BOARD_SERIAL_STR        , "Sample Serial Number"   },
  {EAPI_ID_BOARD_BIOS_REVISION_STR , "PICMGR2.0"              },
#if (EAPI_PLATFORM==EAPI_PLATFORM_COM0)
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , EAPI_COM0_PLATFORM_STR    },
#elif (EAPI_PLATFORM==EAPI_PLATFORM_ETX)
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , EAPI_ETX_PLATFORM_STR    },
#elif (EAPI_PLATFORM==EAPI_PLATFORM_Q7) 
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , EAPI_Q7_PLATFORM_STR     },
#elif (EAPI_PLATFORM==EAPI_PLATFORM_TCA)
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , EAPI_TCA_PLATFORM_STR     },
#else
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , "Unknown Platform Type"  },
#endif
};

uint32_t 
EApiBoardGetStringAEmul( 
    __IN    uint32_t  Id      , 
    __OUT       char *pBuffer , 
    __INOUT uint32_t *pBufLen
    )
{
  uint32_t i;
  uint32_t ErrorCode=EAPI_STATUS_SUCCESS;
  uint32_t BufLenSav;

  BufLenSav=*pBufLen;

  for(i=0;i<ARRAY_SIZE(StringLookup);i++)
  {
      if(StringLookup[i].Id==Id)
      {
        /* 
         * Basically equivilant to
         * strncpy(pBuffer, StringLookup[i].StringPtr, *pBufLen);
         * StringLookup[i].StringPtr[*pBufLen-1]='\0';
         * *pBufLen=strlen(StringLookup[i].StringPtr);
         *
         */
        *pBufLen=(uint32_t)strlen(StringLookup[i].StringPtr)+1;
        if(BufLenSav<*pBufLen)
        {
          ErrorCode=EAPI_STATUS_MORE_DATA;
        }
        else
        {
          BufLenSav=*pBufLen;
        }
        if(BufLenSav && (pBuffer!=NULL))
	{
          memcpy(pBuffer, StringLookup[i].StringPtr, BufLenSav);
          pBuffer[BufLenSav-1]='\0';
        }
        EAPI_LIB_RETURN_ERROR_IF(
		EApiBoardGetStringAEmul, 
		(ErrorCode==EAPI_STATUS_MORE_DATA), 
		EAPI_STATUS_MORE_DATA  , 
		"pBuffer Overrun Prevented"
		);
        EAPI_LIB_RETURN_SUCCESS(
		EApiBoardGetStringAEmul, 
		""
		);
      }
  }
  EAPI_LIB_RETURN_ERROR(
	EApiBoardGetStringAEmul, 
	EAPI_STATUS_UNSUPPORTED  , 
	"Unrecognised String ID"
	);
}

/*
 *
 *  
 *
 *  Get Value
 *
 *
 *
 */
typedef struct ValueLookupTbl_s{
  uint32_t Id          ; /* EAPI Value Id */
  uint32_t Value       ; /* Return Value for ID */
}ValueLookupTbl_t;
const ValueLookupTbl_t ValueLookup[]={
  {EAPI_ID_BOARD_BOOT_COUNTER_VAL       , 0x00000010              },
  {EAPI_ID_BOARD_RUNNING_TIME_METER_VAL , 0x00010000              },
  {EAPI_ID_BOARD_PNPID_VAL              , EAPI_PNPID_PICMG        },
#if (EAPI_PLATFORM==EAPI_PLATFORM_COM0)
  {EAPI_ID_BOARD_PLATFORM_REV_VAL       , EAPI_COM0_REV_2_0       },
#elif (EAPI_PLATFORM==EAPI_PLATFORM_ETX)
  {EAPI_ID_BOARD_PLATFORM_REV_VAL       , EAPI_ETX_REV_3_0        },
#elif (EAPI_PLATFORM==EAPI_PLATFORM_Q7) 
  {EAPI_ID_BOARD_PLATFORM_REV_VAL       , EAPI_Q7_REV_1_0         },
#else
/*   {EAPI_ID_BOARD_PLATFORM_REV_VAL       , EAPI_VER_CREATE(0,0,0)  }, */
#endif

  {EAPI_ID_BOARD_DRIVER_VERSION_VAL     , EAPI_VER_CREATE(0,0,0)  },
  {EAPI_ID_BOARD_LIB_VERSION_VAL        , EAPI_VER_CREATE(LIB_VERSION, LIB_REVISION, LIB_BUILD)},
  /* HWMON */
  /* Temperature */
  {EAPI_ID_HWMON_CPU_TEMP               , EAPI_ENCODE_CELCIUS(100.1)  },
  {EAPI_ID_HWMON_CHIPSET_TEMP           , EAPI_ENCODE_CELCIUS(46.2)  },
  {EAPI_ID_HWMON_SYSTEM_TEMP            , EAPI_ENCODE_CELCIUS(-45.3)  },
  /* Voltage */
  {EAPI_ID_HWMON_VOLTAGE_VCORE          ,  1300  },
  {EAPI_ID_HWMON_VOLTAGE_2V5            ,  2500  },
  {EAPI_ID_HWMON_VOLTAGE_3V3            ,  3300  },
  {EAPI_ID_HWMON_VOLTAGE_VBAT           ,  3000  },
  {EAPI_ID_HWMON_VOLTAGE_5V             ,  5000  },
  {EAPI_ID_HWMON_VOLTAGE_5VSB           ,  5000  },
  {EAPI_ID_HWMON_VOLTAGE_12V            , 12000  },
  /* Voltage */
  {EAPI_ID_HWMON_FAN_CPU                ,  5000  },
  {EAPI_ID_HWMON_FAN_SYSTEM             ,  2500  },
};

uint32_t 
EApiBoardGetValueEmul( 
    __IN  uint32_t Id     , 
    __OUT uint32_t *pValue
    )
{
  uint32_t i;

  for(i=0;i<ARRAY_SIZE(ValueLookup);i++)
  {
      if(ValueLookup[i].Id==Id)
      {
        *pValue=ValueLookup[i].Value;
        EAPI_LIB_RETURN_SUCCESS(EApiBoardGetValueEmul, "");
      }
  }
  EAPI_LIB_RETURN_ERROR(
			EApiBoardGetValueEmul, 
			EAPI_STATUS_UNSUPPORTED  , 
			"Unrecognised Value ID"
		);
}

