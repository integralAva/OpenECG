#include "bsp_spi.h"

#include "spi.h"


uint32_t SPI_Transmit32bit(uint32_t Tx)
{
    uint32_t RxBuf;
    LL_SPI_Enable(SPI1);
    LL_SPI_StartMasterTransfer(SPI1);
    while(LL_SPI_IsActiveFlag_TXP(SPI1) == 0);
    LL_SPI_TransmitData32(SPI1,Tx);
    while(LL_SPI_IsActiveFlag_RXP(SPI1) == 0);
    RxBuf = LL_SPI_ReceiveData32(SPI1);
    
    LL_SPI_ClearFlag_TXTF(SPI1);
    LL_SPI_ClearFlag_EOT(SPI1);
    LL_SPI_SuspendMasterTransfer(SPI1);
    LL_SPI_Disable(SPI1);
    return RxBuf;
}

