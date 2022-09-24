/* Page 0 */
#define SysBaseConfig 0x00
    #define SysOK 0x00
    #define SysVersion 0x01
    #define SysBuildDate_Day 0x02
    #define SysBuildDate_Month 0x03
    #define SysBuildDate_Year 0x04
    #define SysIsUSB_debug 0x05
    #define SysErrorCode 0x06
    
/* Page 1 */
#define ECG_Cache_Data 0x01
    #define ECG_STime_min 0x00
    #define ECG_STime_hour 0x01
    #define ECG_ETime_min 0x02
    #define ECG_ETime_hour 0x03
    #define ECG_Cache_LenA 0x04
    #define ECG_Cache_LenB 0x05
    #define ECG_Cache_LenC 0x06
    #define ECG_Cache_LenD 0x07
    #define ECG_Cache_IsActive 0x08
    #define ECG_Cache_Page 0x09
    #define ECG_Cache_Bit 0x0A
    
    
/* Page 2 */
#define ECG_CacheA 0x02

/* Page 3 */
#define ECG_CacheB 0x03


