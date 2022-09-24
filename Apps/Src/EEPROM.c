#include "EEPROM.h"
#include "SysConfig.h"
#include "i2c.h"

#define AT24_W 0xA0
#define AT24_R 0xA1

/* AT24C128 256(page)*64(point)byte*/

static uint16_t Calc_Addr(unsigned char page,unsigned char bit)
{
    uint16_t addr = bit;
    addr |= (page<<6);
    return addr;
}

static void WriteData(uint8_t * data,uint8_t len,uint8_t page,uint8_t point)
{
    uint16_t addr = Calc_Addr(page,point);
    HAL_I2C_Mem_Write(&hi2c4,AT24_W,addr,I2C_MEMADD_SIZE_16BIT,data,len,0xFF);
}

static void ReadData(uint8_t * data,uint8_t len,uint8_t page,uint8_t point)
{
    uint16_t addr = Calc_Addr(page,point);
    HAL_I2C_Mem_Read(&hi2c4,AT24_R,addr,I2C_MEMADD_SIZE_16BIT,data,len,0xFF);
}

void EEPROM_RestartRecord(void)
{
    /* Clear All Bits */
    WriteData(0,64,ECG_Cache_Data,0);
}

void EEPROM_ECG_Record(uint8_t data)
{
    uint8_t temp[2];
    ReadData(temp,2,ECG_Cache_Data,ECG_Cache_Page);
    temp[0] += 2;
    WriteData(&data,1,temp[0],temp[1]);
    if(temp[1] >= 63)
    {
        temp[1] = 0;
        temp[0]++;
    }else
    {
        temp[1]++;
    }
    temp[0] -= 2;
    WriteData(temp,2,ECG_Cache_Data,ECG_Cache_Page);
}
