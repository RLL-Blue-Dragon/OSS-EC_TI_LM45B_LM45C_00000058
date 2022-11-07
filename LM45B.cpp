// License       : License.txt
// Specifications: Spec-LM45B_LM45C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM45B.cpp
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM45B.h"

#if     iLM45B_ma == iSMA                               // Simple moving average filter
static float32 LM45B_sma_buf[iLM45B_SMA_num];
static sma_f32_t LM45B_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM45B_SMA_num ,                                // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM45B_sma_buf[0]                               // buffer
};

#elif   iLM45B_ma == iEMA                               // Exponential moving average filter
static ema_f32_t LM45B_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM45B_EMA_K                                    // Exponential smoothing factor
};

#elif   iLM45B_ma == iWMA                               // Weighted moving average filter
static float32 LM45B_wma_buf[iLM45B_WMA_num];
static wma_f32_t LM45B_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM45B_WMA_num ,                                // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM45B_WMA_num * (iLM45B_WMA_num + 1)/2 ,       // kn sum
        &LM45B_wma_buf[0]                               // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM45B =
{
        iLM45B                  ,
        iLM45B_pin              ,
        iLM45B_xoff             ,
        iLM45B_yoff             ,
        iLM45B_gain             ,
        iLM45B_max              ,
        iLM45B_min              ,
        iLM45B_ma               ,
        
#if     iLM45B_ma == iSMA                               // Simple moving average filter
        &LM45B_Phy_SMA          ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM45B_ma == iEMA                               // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM45B_Phy_EMA          ,
        (wma_f32_t*)iDummy_adr
#elif   iLM45B_ma == iWMA                               // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM45B_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
