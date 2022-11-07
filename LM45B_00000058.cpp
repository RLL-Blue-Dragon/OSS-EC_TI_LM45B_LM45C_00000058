// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM45B_00000058.cpp
// BSL              : 00000058
// Model number     : Texas Instruments LM45B, LM45C
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "LM45B.h"

AnalogIn LM45B_adc( iLM45B_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t LM45B_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( LM45B_adc , tbl_LM45B );
        return( res );
}
