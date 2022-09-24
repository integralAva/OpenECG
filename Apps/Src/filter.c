#include "filter.h"
#include "ADAS1000.h"
#include "DataCenter.h"
#include "filter_const.h"

#include "bsp_uart.h"

struct
{
    int32_t Lead_I;
    int32_t Lead_II;
    int32_t Lead_III;
    int32_t Lead_V;
    int32_t Resp;
}F_Basicline;

struct
{
    int32_t Lead_I;
    int32_t Lead_II;
    int32_t Lead_III;
    int32_t Lead_V;
    int32_t Resp;
}F_Processed;


/////////////////////////////////////// Low pass filter by FIR
//LFIR-I
float32_t LPF_FI_Cache[49];
arm_fir_instance_f32 FIR_LPF_FI;
//LFIR-II
float32_t LPF_FII_Cache[49];
arm_fir_instance_f32 FIR_LPF_FII;
//LFIR-III
float32_t LPF_FIII_Cache[49];
arm_fir_instance_f32 FIR_LPF_FIII;
//LFIR-V
float32_t LPF_FV_Cache[49];
arm_fir_instance_f32 FIR_LPF_FV;
//LFIR-RESP
float32_t LPF_FRESP_Cache[49];
arm_fir_instance_f32 FIR_LPF_FRESP;


///////////////////////////////////// Low pass filter for Basicline calculating by FIR
//FIR-BI
float32_t LPF_FBI_Cache[49];
arm_fir_instance_f32 FIR_LPF_FBI;
//FIR-BII
float32_t LPF_FBII_Cache[49];
arm_fir_instance_f32 FIR_LPF_FBII;
//FIR-BIII
float32_t LPF_FBIII_Cache[49];
arm_fir_instance_f32 FIR_LPF_FBIII;
//FIR-BV
float32_t LPF_FBV_Cache[49];
arm_fir_instance_f32 FIR_LPF_FBV;
//FIR-BRESP
float32_t LPF_FBR_Cache[49];
arm_fir_instance_f32 FIR_LPF_FBR;

//Cache(Basicline)
static float32_t FBcache_in,FBcache_out;
//Cache(Normal)
static float32_t Fcache_in,Fcache_out;



void Filter_Init(void)
{
    //FIR LPF ECG-I(Fs=1000Hz,Fc=30Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FI,48,FIR_LPF_const,LPF_FI_Cache,1);
    //FIR LPF ECG-II(Fs=1000Hz,Fc=30Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FII,48,FIR_LPF_const,LPF_FII_Cache,1);
    //FIR LPF ECG-III(Fs=1000Hz,Fc=30Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FIII,48,FIR_LPF_const,LPF_FIII_Cache,1);
    //FIR LPF ECG-V(Fs=1000Hz,Fc=30Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FV,48,FIR_LPF_const,LPF_FV_Cache,1);
    //FIR LPF ECG-RESP(Fs=1000Hz,Fc=30Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FRESP,48,FIR_LPF_const,LPF_FRESP_Cache,1);
    
    
    //FIR LPF ECG-B-I(Fs=20Hz,Fc=0.1Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FBI,48,Basicline_const,LPF_FBI_Cache,1);
    //FIR LPF ECG-B-II(Fs=20Hz,Fc=0.1Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FBII,48,Basicline_const,LPF_FBII_Cache,1);
    //FIR LPF ECG-B-III(Fs=20Hz,Fc=0.1Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FBIII,48,Basicline_const,LPF_FBIII_Cache,1);
    //FIR LPF ECG-B-V(Fs=20Hz,Fc=0.1Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FBV,48,Basicline_const,LPF_FBV_Cache,1);
    //FIR LPF ECG-B-V(Fs=20Hz,Fc=0.1Hz,Tap=48)
    arm_fir_init_f32(&FIR_LPF_FBR,48,Basicline_const,LPF_FBR_Cache,1);
    
}

void Filter_Run(void)
{
    //FIR_I
    Fcache_in = (float32_t)ADAS1000_Data.Lead_I;
    arm_fir_f32(&FIR_LPF_FI,&Fcache_in,&Fcache_out,1);
    F_Processed.Lead_I = (int32_t)Fcache_out;
    ECG_Data.Lead_I = F_Processed.Lead_I - F_Basicline.Lead_I;
    
    //FIR_II
    Fcache_in = (float32_t)ADAS1000_Data.Lead_II;
    arm_fir_f32(&FIR_LPF_FII,&Fcache_in,&Fcache_out,1);
    F_Processed.Lead_II = (int32_t)Fcache_out;
    ECG_Data.Lead_II = F_Processed.Lead_II - F_Basicline.Lead_II;
    
    //FIR_III
    Fcache_in = (float32_t)ADAS1000_Data.Lead_III;
    arm_fir_f32(&FIR_LPF_FIII,&Fcache_in,&Fcache_out,1);
    F_Processed.Lead_III = (int32_t)Fcache_out;
    ECG_Data.Lead_III = F_Processed.Lead_III - F_Basicline.Lead_III;
    
    //FIR_V
    Fcache_in = (float32_t)ADAS1000_Data.Lead_V;
    arm_fir_f32(&FIR_LPF_FV,&Fcache_in,&Fcache_out,1);
    F_Processed.Lead_V = (int32_t)Fcache_out;
    ECG_Data.Lead_V = F_Processed.Lead_V - F_Basicline.Lead_V;
    
    //FIR_resp
    Fcache_in = (float32_t)ADAS1000_Data.Resp;
    arm_fir_f32(&FIR_LPF_FRESP,&Fcache_in,&Fcache_out,1);
    F_Processed.Resp = (int32_t)Fcache_out;
    ECG_Data.Resp = F_Processed.Resp - F_Basicline.Resp;
    
    
    
}

//call this function at 20HZ
void Filter_Basicline(void)
{
    FBcache_in = (float32_t)F_Processed.Lead_I;
    arm_fir_f32(&FIR_LPF_FBI,&FBcache_in,&FBcache_out,1);
    F_Basicline.Lead_I = (int32_t)FBcache_out;
    
    FBcache_in = (float32_t)F_Processed.Lead_II;
    arm_fir_f32(&FIR_LPF_FBII,&FBcache_in,&FBcache_out,1);
    F_Basicline.Lead_II = (int32_t)FBcache_out;
    
    FBcache_in = (float32_t)F_Processed.Lead_III;
    arm_fir_f32(&FIR_LPF_FBIII,&FBcache_in,&FBcache_out,1);
    F_Basicline.Lead_III = (int32_t)FBcache_out;
    
    FBcache_in = (float32_t)F_Processed.Lead_V;
    arm_fir_f32(&FIR_LPF_FBV,&FBcache_in,&FBcache_out,1);
    F_Basicline.Lead_V = (int32_t)FBcache_out;
    
    FBcache_in = (float32_t)F_Processed.Resp;
    arm_fir_f32(&FIR_LPF_FBR,&FBcache_in,&FBcache_out,1);
    F_Basicline.Resp = (int32_t)FBcache_out;
}

