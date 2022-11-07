// License       : License.txt
// Specifications: Spec-LM45B_LM45C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM45B.h
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM45B_H__
#define __LM45B_H__

#include "user_define.h"

// Components number
#define iLM45B                  129U                    // Texas Instruments LM45B, LM45C

// LM45B, LM45C System Parts definitions
#define iLM45B_xoff             0.0F                    // X offset [V]
#define iLM45B_yoff             0.0F                    // Y offset [degree celsius]
#define iLM45B_gain             0.01F                   // Gain [V/degree celsius]
#define iLM45B_max              100.0F                  // Temperature Max [degree celsius]
#define iLM45B_min              2.5F                    // Temperature Min [degree celsius]     CAUTION:-20[°C],the circuit needs a voltage Offset

extern const tbl_adc_t tbl_LM45B;

#endif /*__LM45B_H__*/
