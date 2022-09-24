/******************************************************************************/
/* ADAS1000 SPI 寄存器地址映射 					        					  */
/******************************************************************************/
#define	ADAS1000_NOP			0x00	/* 空数据 */
#define	ADAS1000_ECGCTL			0x01	/* ECG 设置寄存器 */
#define	ADAS1000_LOFFCTL		0x02	/* 导联脱落控制寄存器  */
#define	ADAS1000_RESPCTL		0x03	/* 呼吸控制寄存器 */
#define	ADAS1000_PACECTL		0x04	/* 起搏控制寄存器 */
#define	ADAS1000_CMREFCTL		0x05	/* 共模，参考，屏蔽控制寄存器 */
#define	ADAS1000_GPIOCTL		0x06	/* GPIO 控制寄存器 */
#define	ADAS1000_PACEAMPTH		0x07	/* 起搏幅度阈值控制寄存器 */
#define	ADAS1000_TESTTONE		0x08	/* 测试音设置 */
#define	ADAS1000_CALDAC			0x09	/* DAC校准 */
#define	ADAS1000_FRMCTL			0x0A	/* 帧控制寄存器 */
#define	ADAS1000_FILTCTL		0x0B	/* 滤波器控制寄存器 */
#define	ADAS1000_LOFFUTH		0x0C	/* 交流导联脱落阈值上限 */
#define	ADAS1000_LOFFLTH		0x0D	/* 交流导联脱落阈值下限 */
#define	ADAS1000_PACEEDGETH		0x0E	/* 起搏边沿阈值 */
#define	ADAS1000_PACELVLTH		0x0F	/* 起搏电平阈值 */
#define	ADAS1000_LADATA			0x11	/* LA或导联I数据 */
#define	ADAS1000_LLDATA			0x12	/* LL或导联II数据 */
#define	ADAS1000_RADATA			0x13	/* RA或导联III数据 */
#define	ADAS1000_V1DATA			0x14	/* V1或V1'数据 */
#define	ADAS1000_V2DATA			0x15	/* V2或V2'数据 */
#define	ADAS1000_PACEDATA		0x1A	/* 起搏数据或状态寄存器 */
#define	ADAS1000_RESPMAG		0x1B	/* 呼吸幅度数据 */
#define	ADAS1000_RESPPH			0x1C	/* 呼吸相位数据 */
#define	ADAS1000_LOFF			0x1D	/* 导联脱落状态 */
#define	ADAS1000_DCLEADSOFF		0x1E	/* 直流导联脱落寄存器 */
#define ADAS1000_OPSTAT         0x1F    /* 工作状态寄存器 */
#define	ADAS1000_EXTENDSW		0x20	/* 呼吸输入拓展开关 */
#define	ADAS1000_CALLA			0x21	/* 用户增益校准LA */
#define	ADAS1000_CALLL			0x22	/* 用户增益校准LL */
#define	ADAS1000_CALRA			0x23	/* 用户增益校准RA */
#define	ADAS1000_CALV1			0x24	/* 用户增益校准V1 */
#define	ADAS1000_CALV2			0x25	/* 用户增益校准V2 */
#define	ADAS1000_LOAMLA			0x31	/* LA导联脱落幅度 */
#define	ADAS1000_LOAMLL			0x32	/* LL导联脱落幅度 */
#define	ADAS1000_LOAMRA			0x33	/* RA导联脱落幅度 */
#define	ADAS1000_LOAMV1			0x34	/* V1导联脱落幅度 */
#define	ADAS1000_LOAMV2			0x35	/* V2导联脱落幅度 */
#define	ADAS1000_PACE1_DATA		0x3A	/* 起搏1宽度和幅度 */
#define	ADAS1000_PACE2_DATA		0x3B	/* 起搏2宽度和幅度 */
#define	ADAS1000_PACE3_DATA		0x3C	/* 起搏3宽度和幅度 */
#define	ADAS1000_FRAMES			0x40	/* 帧表头 */
#define	ADAS1000_CRC			0x41	/* CRC寄存器 */

/******************************************************************************/
/* ECG 设置寄存器 				        									  */
/******************************************************************************/
#define ADAS1000_ECGCTL_LAEN		(1ul << 23)	/* 	ECG 通道LA使能, 关断通道电源, 输入变为 
													高阻态 : 1 = 使能, 0 = 关断 */
                                                    
#define ADAS1000_ECGCTL_LLEN		(1ul << 22)	/* 	ECG 通道LL使能, 关断通道电源, 输入变为 
													高阻态 : 1 = 使能, 0 = 关断 */
                                                    
#define ADAS1000_ECGCTL_RAEN		(1ul << 21)	/* 	ECG 通道RA使能, 关断通道电源, 输入变为 
													高阻态 : 1 = 使能, 0 = 关断 */
                                                    
#define ADAS1000_ECGCTL_V1EN		(1ul << 20)	/* 	ECG 通道V1使能, 关断通道电源, 输入变为 
													高阻态 : 1 = 使能, 0 = 关断 */
                                                    
#define ADAS1000_ECGCTL_V2EN		(1ul << 19)	/* 	ECG 通道V2使能, 关断通道电源, 输入变为 
													高阻态 : 1 = 使能, 0 = 关断 */
                                                    
#define ADAS1000_ECGCTL_CHCONFIG	(1ul << 10)	/* 	此位置1，选择差分模拟前端输入: 
														0 = 单端输入，用于数字导联模式或电极模式, 
														1 = 差分输入，用于模拟导联模式 */
                                                        
#define ADAS1000_ECGCTL_GAIN 		(1ul << 8)	/* 	前置放大器和抗混叠滤波器的总增益: 
														00 = GAIN 0 = x1.4, 01 = GAIN 1 = x2.1, 
														10 = GAIN 2 = x2.8, 11 = GAIN 3 = x4.2 */
                                                        
#define ADAS1000_ECGCTL_VREFBUF 	(1ul << 7)	/* 	VREF 缓冲区使能:   0 = 关断, 1 = 使能 (使用内部VREF时 
													此位必须使能) */
                                                    
#define ADAS1000_ECGCTL_CLKEXT		(1ul << 6)	/* 	使能外部时钟输入，而不使用晶振。在组合模式下，
													若设置为从机，晶振自动禁用，从机接收
													主机的时钟:  
														0 = 使用晶振, 1 = 使用外部时钟源. */
                                                        
#define ADAS1000_ECGCTL_MASTER		(1ul << 5)	/* 	在组合模式下。此位用于设置主器件 (SYNC_GANG引脚配置 
													为输出). 单通道模式下 (GANG = 0), 忽略此位:  
														0 = 从机, 1 = 主机  */
                                                        
#define ADAS1000_ECGCTL_GANG		(1ul << 4)	/* 	使能组合模式. 此位置1会激活CLK_IO和SYNC_GANG: 
														0 = 单通道模式,  1 = 组合模式 */
                                                        
#define ADAS1000_ECGCTL_HP			(1ul << 3)	/* 	选择噪声和功耗性能。此位控制ADC采样频率，也会影响呼吸 
													载波频率.详见数据手册: 
														0 = 1MSPS - 低功耗,  1 = 2 MSPS 高性能，低噪声 */
                                                        
#define ADAS1000_ECGCTL_CNVEN		(1ul << 2)	/* 	转换使能，此位置1来使能ADC转换和滤波器: 
														0 = 关断, 1 = 使能 */
                                                        
#define ADAS1000_ECGCTL_PWREN		(1ul << 1)	/* 	电源使能，通过将该位清0来关断器件. 所有模拟时钟都关断， 
													外部时钟禁用。关断器件，只要未切断DVDD，寄存器就不会丢失:  
														0 = 关断,  1 = 电源使能 */
                                                        
#define ADAS1000_ECGCTL_SWRST		(1ul << 0)	/* 	软件复位，此位置1，所有寄存器回复默认值. 
													此位自动归0.软件复位要求发生一个NOP命令来完成复位： 
													0 = 无,  1 = 重置 */

/******************************************************************************/
/* 导联脱落控制寄存器 		        										  */
/******************************************************************************/
#define ADAS1000_LOFFCTL_LAPH 		(1ul << 23)	/* 	交流导联LA脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_LLPH 		(1ul << 22)	/* 	交流导联LL脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_RAPH		(1ul << 21)	/* 	交流导联RA脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_V1PH		(1ul << 20)	/* 	交流导联V1脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_V2PH		(1ul << 19)	/* 	交流导联V2脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_CEPH		(1ul << 18)	/* 	交流导联脱落相位: 0 = 同相, 1 = 180°错相 */

#define ADAS1000_LOFFCTL_LAACLOEN	(1ul << 17)	/* 	LA电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_LLACLOEN	(1ul << 16)	/*	LL电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_RAACLOEN	(1ul << 15)	/* 	RA电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_V1ACLOEN	(1ul << 14)	/* 	V1电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_V2ACLOEN	(1ul << 13)	/* 	V2电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_CEACLOEN	(1ul << 12)	/* 	CE电极交流导联脱落检测使能： 
													0 = 禁用交流导联脱落检测, 1 = 使能交流导联脱落检测 */
                                                        
#define ADAS1000_LOFFCTL_ACCURREN	(1ul << 7)	/* 交流导联脱落电流阈值 (仅ACSEL = 1). 
														00 = 12.5nA rms, 01  =  25nA rms, 
														10  =  50nA rms, 11  =  100nA rms */
                                                        
#define ADAS1000_LOFFCTL_DCCURRENT	(1ul << 2)	/* 	直流导联脱落电流阈值 (仅ACSEL = 0) 
														000 = 0nA, 001  =  10nA, 010  =  20nA, 011  =  30nA, 
														100  =  40nA, 101  =  50nA, 110  =  60nA, 111  =  70nA */
                                                        
#define ADAS1000_LOFFCTL_ACSEL 		(1ul << 1)	/* 	选择直流或交流导联脱落检测. 如果 LOFFEN = 0, 此位为无关位. 
                                                    如果 LOFFEN = 1：
                                                    此位 0 = 使能直流导联脱落检测. 
													(交流导联脱落检测通过位17-12使能), 
													1  = 禁用直流导联脱落检测. 交流导联脱落检测使能 
													(除CE外的所有电极). */
                                                    
#define ADAS1000_LOFFCTL_LOFFEN		(1ul << 0)	/* 	使能导联脱落检测功能: 
														0 = 禁用导联脱落检测, 1 = 使能导联脱落检测 */

/******************************************************************************/
/* 呼吸控制寄存器 							                				  */
/******************************************************************************/
#define ADAS1000_RESPCTL_RESPEXTSYNC	(1ul << 15)	/* 	此位置1，呼吸DAC的MSB输出到GPIO3
														0 = GPIO3正常工作, 1 = MSB输出到GPIO3 */
                                                        
#define ADAS1000_RESPCTL_RESPEXTAMP		(1ul << 14)	/* 	使用外部呼吸仪表放大器
                                                        0 = 禁用， 1 = 使能*/
                                                        
#define ADAS1000_RESPCTL_RESPOUT		(1ul << 13)	/* 	外部呼吸驱动输出,当RESPCAP=1时，自动选择RESP_RA
                                                        0 = RESPDAC _LL, 1 = RESPDAC_LA */
                                                        
#define ADAS1000_RESPCTL_RESPCAP		(1ul << 12)	/* 	选择呼吸电容来源. 
															0 = 使用内部电容, 1 = 使用外部电容 */
                                                            
#define ADAS1000_RESPCTL_RESPGAIN		(1ul << 8)	/* 	呼吸仪表放大器增益 (10倍时饱和): 
															0000 = x1 倍增益, 0001 = x2 倍增益, 0010 = x3 倍增益, 
															... 
															1000 = x9 倍增益, 1001 = x10 倍增益, 11xx = x10 倍增益 */
                                                            
#define ADAS1000_RESPCTL_RESPEXTSEL 	(1ul << 7)	/* 	选择外部呼吸路径。仅RESPSEL选择外部路径时适用
                                                        EXT_RESP_RA自动使能
                                                     0 = EXT_RESP_LL, 1 = EXT_RESP _LA */
                                                     
#define ADAS1000_RESPCTL_RESPSEL		(1ul << 5)	/* 	设置呼吸测量导联: 
														00 = I导联, 01 = II导联, 
														10 = III导联, 11 = 外部呼吸路径 */
                                                        
#define ADAS1000_RESPCTL_RESPAMP 		(1ul << 3)	/* 	设置呼吸测试音幅度:  
															00 = /8, 01  = /4, 
															10  = /2, 11  = /1 */
                                                            
#define ADAS1000_RESPCTL_RESPFREQ		(1ul << 1)	/* 	设置呼吸阻抗测量频率: 
															00 = 56kHz, 01 = 54kHz, 10 = 52kHz, 11 = 50kHz */
                                                            
#define ADAS1000_RESPCTL_RESPEN			(1ul << 0)	/* 	呼吸使能: 
															0 = 关断, 1  = 使能 */

#define ADAS1000_RESPCTL_RESPGAIN_MASK	(0x0000000Ful << 8)														
#define ADAS1000_RESPCTL_RESPSEL_MASK	(0x00000003ul << 5)														
															
/******************************************************************************/
/* 起搏检测控制寄存器             											  */
/******************************************************************************/
#define ADAS1000_PACECTL_PACEFILTW		(1ul << 11)	/* 	起搏宽度滤波器: 
															0 = 滤波器禁用, 1 = 滤波器使能 */
                                                            
#define ADAS1000_PACECTL_PACETFILT2		(1ul << 10)	/* 	起搏验证滤波器 2: 
															0 = 禁用, 1 = 使能 */
                                                            
#define ADAS1000_PACECTL_PACETFILT1		(1ul << 9)	/* 	起搏验证滤波器 1 : 
															0 = 禁用, 1 = 使能 */
                                                            
#define ADAS1000_PACECTL_PACE3SEL 		(1ul << 7)	/* 	设置起搏检测器3检测的导联: 
															00 = 导联I, 01 = 导联II, 10 = 导联III, 11 = 导联aVF */
                                                            
#define ADAS1000_PACECTL_PACE2SEL 		(1ul << 5)	/* 	设置起搏检测器2检测的导联: 
															00 = 导联I, 01 = 导联II, 10 = 导联III, 11 = 导联aVF */
                                                            
#define ADAS1000_PACECTL_PACE1SEL 		(1ul << 3)	/* 	设置起搏检测器1检测的导联: 
															00 = 导联I, 01 = 导联II, 10 = 导联III, 11 = 导联aVF */
                                                            
#define ADAS1000_PACECTL_PACE3EN		(1ul << 2)	/* 	使能起搏检测器3: 
															0 = 禁用, 1  = 使能 */
                                                            
#define ADAS1000_PACECTL_PACE2EN		(1ul << 1)	/* 	使能起搏检测器2: 
															0 = 禁用, 1  = 使能 */
                                                            
#define ADAS1000_PACECTL_PACE1EN		(1ul << 0)	/* 	使能起搏检测器1: 
															0 = 禁用, 1  = 使能 */

#define ADAS1000_PACECTL_PACE3SEL_MASK	(0x00000003ul << 7)
#define ADAS1000_PACECTL_PACE2SEL_MASK	(0x00000003ul << 5)
#define ADAS1000_PACECTL_PACE1SEL_MASK	(0x00000003ul << 3)
															
/******************************************************************************/
/* 共模，参考，屏蔽驱动控制寄存器 	                        				  */
/******************************************************************************/
#define ADAS1000_CMREFCTL_LACM		(1ul << 23)	/*	共模电极选择*/
#define ADAS1000_CMREFCTL_LLCM		(1ul << 22)	/*	5个电极的任意组合来产生共模信号VCM */
#define ADAS1000_CMREFCTL_RACM		(1ul << 21)	/*	在EXTCM = 1的情况下，忽略此5位 */
#define ADAS1000_CMREFCTL_V1CM		(1ul << 20)	/*	共模信号是所选电极的平均值，选择单个电极时，共模信号是该电极的电平*/
#define ADAS1000_CMREFCTL_V2CM		(1ul << 19)	/*	当5位全部为0（禁用）时，共模信号由内部REF驱动*/
												/*		0 = 不参与共模信号 */
												/*		1 = 参与共模信号 */
                                                
                                                
#define ADAS1000_CMREFCTL_LARLD		(1ul << 14)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_LLRLD		(1ul << 13)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_RARLD		(1ul << 12)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_V1RLD		(1ul << 11)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_V2RLD		(1ul << 10)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_CERLD		(1ul << 9)	/*	RLD 求和结输入
														0 = 不参入求和结输入
														1 = 参与求和结输入 */
                                                        
#define ADAS1000_CMREFCTL_CEREFEN	(1ul << 8)	/*	公共电极（CE）参考
                                                    0 = 禁用公共电极
                                                    1 = 使能公共电极*/
                                                        
#define ADAS1000_CMREFCTL_RLDSEL	(1ul << 4)	/*	选择参考驱动的电极
														0000 = RLD_OUT, 0001 = LA, 0010 = LL,
														0011 = RA, 0100 = V1, 0101 = V2,
														0110 to 1111 = 保留 */
                                                        
#define ADAS1000_CMREFCTL_DRVCM		(1ul << 3)	/*	共模输出。置1时，共模信号通过共模引脚输出
													如果使用外部共模，此位不起作用  
														0 = 不输出共模
														1   = 输出共模 */
                                                        
#define ADAS1000_CMREFCTL_EXTCM		(1ul << 2)	/*	选择共模来源 
													(组合模式下使用)
														0 = 内部共模
														1 = 外部共模 */
                                                        
#define ADAS1000_CMREFCTL_RLD_EN	(1ul << 1)	/*	使能RLD参考电极
														0 = 禁用
														1  = 使能 */
                                                        
#define ADAS1000_CMREFCTL_SHLDEN	(1ul << 0)	/*	使能屏蔽驱动
														0 = 禁用
														1  = 使能 */

#define ADAS1000_CMREFCTL_RLDSEL_MASK (0x0000000Ful << 4)
														
/******************************************************************************/
/* GPIO控制寄存器         													  */
/******************************************************************************/
#define ADAS1000_GPIOCTL_SPIFW		(1ul << 18)	/*	片选控制
														0 = 片选在帧期间置位
														1 = 片选在字期间置位 */
                                                        
#define ADAS1000_GPIOCTL_SPIEN		(1ul << 16)	/*	第二SPI使能 (仅1000和1000-2)
													第二SPI接口以128khz速率提供ECG数据 
													占用GPIO0,1,2引脚
														0 = 禁用
														1 = 使能.*/
                                                        
#define ADAS1000_GPIOCTL_G3CTL		(1ul << 14)	/*	GPIO3模式
														00 = 高阻态, 01 = 输入,
														10 = 输出, 11 = 开漏输出 */
                                                        
#define ADAS1000_GPIOCTL_G3OUT		(1ul << 13)	/*	输出模式下的GPIO状态
														0  = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G3IN		(1ul << 12)	/*	(只读) 输入模式下GPIO3的电平 
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G2CTL 		(1ul << 10)	/*	GPIO2模式
														00 = 高阻态, 01 = 输入,
														10 = 输出, 11 = 开漏输出 */
                                                        
#define ADAS1000_GPIOCTL_G2OUT		(1ul << 9)	/*	输出模式下GPIO2的电平
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G2IN		(1ul << 8)	/*	(只读) 输入模式下GPIO2的电平
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G1CTL		(1ul << 6)	/*	GPIO1模式
														00 = 高阻态, 01 = 输入,
														10 = 输出, 11 = 开漏输出 */
                                                        
#define ADAS1000_GPIOCTL_G1OUT		(1ul << 5)	/*	输出模式下GPIO1的电平
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G1IN		(1ul << 4)	/*	(只读) 输入模式下GPIO1的电平
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G0CTL		(1ul << 2)	/*	GPIO0的模式
														00 = 高阻态, 01 = 输入,
														10 = 输出, 11 = 开漏输出 */
                                                        
#define ADAS1000_GPIOCTL_G0OUT		(1ul << 1)	/*	输出模式下GPIO0的电平.
														0 = 低电平
														1 = 高电平 */
                                                        
#define ADAS1000_GPIOCTL_G0IN		(1ul << 0)	/*	(只读) 输入模式下GPIO0的电平
														0 = 低电平
														1 = 高电平 */

#define ADAS1000_GPIOCTL_G3CTL_MASK	(0x00000003ul << 14)
#define ADAS1000_GPIOCTL_G2CTL_MASK	(0x00000003ul << 10)
#define ADAS1000_GPIOCTL_G1CTL_MASK	(0x00000003ul << 6)
#define ADAS1000_GPIOCTL_G0CTL_MASK	(0x00000003ul << 2)
														
/******************************************************************************/
/* 起搏幅度阈值寄存器                										  */
/******************************************************************************/
#define ADAS1000_PACEAMPTH_PACE3AMPTH	(1ul << 16)	/*	起搏幅度阈值			*/
#define ADAS1000_PACEAMPTH_PACE2AMPTH	(1ul << 8)	/*	阈值 = N * VREF/GAIN/2^16 	*/
#define ADAS1000_PACEAMPTH_PACE1AMPTH	(1ul << 0)	

#define ADAS1000_PACEAMPTH_PACE3AMPTH_MASK		(0x000000FFul << 16)
#define ADAS1000_PACEAMPTH_PACE2AMPTH_MASK		(0x000000FFul << 8)
#define ADAS1000_PACEAMPTH_PACE1AMPTH_MASK		(0x000000FFul << 0)

/******************************************************************************/
/* 测试音寄存器       														  */
/******************************************************************************/
#define ADAS1000_TESTTONE_TONLA		(1ul << 23)	/*	测试音选择 */
#define ADAS1000_TESTTONE_TONLL		(1ul << 22)	/* 	0 = 1.3V 基准电压 */
#define ADAS1000_TESTTONE_TONRA		(1ul << 21)	/*	1 = 1mV 正弦波或方波 */
#define ADAS1000_TESTTONE_TONV1		(1ul << 20)
#define ADAS1000_TESTTONE_TONV2		(1ul << 19)

#define ADAS1000_TESTTONE_TONTYPE	(1ul << 3)	/*	测试音类型
                                                    00 = 10Hz 正弦波
													01 = 150Hz 正弦波
													1x = 1Hz 1mV 正弦波 */
                                                    
#define ADAS1000_TESTTONE_TONINT	(1ul << 2)	/*	测试音来源
													0 = 外部输入
													1  = 内部测试音 */
                                                    
#define ADAS1000_TESTTONE_TONOUT	(1ul << 1)	/*	测试音输出使能
													0 = 内部测试音模式下，禁用测试音输出
													1 = 内部测试音模式下，CAL_DAC_IO输出测试音. */
                                                    
#define ADAS1000_TESTTONE_TONEN		(1ul << 0)	/*	测试音使能
													0 = 禁用测试音
													1 = 使能测试音 */

#define ADAS1000_TESTTONE_TONTYPE_MASK (0x00000003ul << 3)
													
/******************************************************************************/
/* 校准DAC寄存器         													  */
/******************************************************************************/
#define ADAS1000_CALDAC_CALCHPEN	(1ul << 13)	/*	校准斩波时钟使能. 
														0 = 关断
														1  = 使能. */
                                                        
#define ADAS1000_CALDAC_CALMODEEN	(1ul << 12)	/*	校准模式使能
														0 = 禁用校准模式
														1 = 使能校准模式. */
                                                        
#define ADAS1000_CALDAC_CALINT		(1ul << 11)	/*	校准来源
														0 = 外部CAL_DAC_IO校准. 
														1 = 内部校准. */
                                                        
#define ADAS1000_CALDAC_CALDACEN	(1ul << 10)	/*	校准DAC使能. 
														0 = 禁用校准DAC
														1 = 使能校准DAC. */
                                                        
#define ADAS1000_CALDAC_CALDATA		(1ul << 0)	/*	校准DAC值 	*/

#define ADAS1000_CALDAC_CALDATA_MASK (0x000003FFul << 0)

/******************************************************************************/
/* 帧控制寄存器            													  */
/******************************************************************************/
#define ADAS1000_FRMCTL_LEAD_I_LADIS	(1ul << 23)	/*	将字包括或排除于数据帧中 */
#define ADAS1000_FRMCTL_LEAD_II_LLDIS	(1ul << 22)	/*	如果导联脱落，则数据字 */
#define ADAS1000_FRMCTL_LEAD_III_RADIS	(1ul << 21)	/*	为未定义.*/
#define ADAS1000_FRMCTL_V1DIS			(1ul << 20)	/*		0 = 包含在帧中 */
#define ADAS1000_FRMCTL_V2DIS			(1ul << 19)	/*		1 = 排除于帧 */

#define ADAS1000_FRMCTL_PACEDIS			(1ul << 14)	/*	起搏检测
															0 = 包含在帧中
															1 = 排除于帧	*/
                                                            
#define ADAS1000_FRMCTL_RESPMDIS		(1ul << 13)	/*	呼吸幅度
															0 = 包含在帧中
															1 = 排除于帧 */
                                                            
#define ADAS1000_FRMCTL_RESPPHDIS		(1ul << 12)	/*	呼吸相位
															0 = 包含在帧中
															1 = 排除于帧 */
                                                            
#define ADAS1000_FRMCTL_LOFFDIS			(1ul << 11)	/*	导联脱落信息
															0 = 包含在帧中
															1 = 排除于帧 */
                                                            
#define ADAS1000_FRMCTL_GPIODIS			(1ul << 10)	/*	GPIO字禁用
															0 = 包含在帧中
															1 = 排除于帧	*/
                                                            
#define ADAS1000_FRMCTL_CRCDIS			(1ul << 9)	/*	CRC字禁用
															0 = 包含在帧中
															1 = 排除于帧 */
                                                            
                                                            
#define ADAS1000_FRMCTL_ADIS			(1ul << 7)	/*	如果表头中未设置其标志，则自动排除该字.
															0 = 固定格式
															1 = 自动排除 */
                                                            
#define ADAS1000_FRMCTL_RDYRPT			(1ul << 6)	/*	重复就绪，如果帧表头显示数据未就绪，
														则持续发送帧表头
                                                        直到数据就绪. 
															0 = 总是发生整帧
															1 = 重复发生表头直到就绪 */
                                                            
#define ADAS1000_FRMCTL_DATAFMT			(1ul << 4)	/*	输出数据格式
															0 = 数字导联或矢量格式 
																(仅2khz-16khz)
															1  = 电极格式 */
                                                            
#define ADAS1000_FRMCTL_SKIP			(1ul << 2)	/*	跳过模式
															00 = 输出每一帧
															01 = 每隔一帧输出
															1x = 每隔三帧输出 */
                                                            
#define ADAS1000_FRMCTL_FRMRATE                 (1ul << 0) /*  设置输出速率
                                                            00 = 2khz
                                                            01 = 16khz
                                                            10 = 128khz（DATAFMT = 1）
                                                            11 = 31.25HZ*/
                                                            
#define ADAS1000_FRMCTL_FRMRATE_2KHZ	0x00		/*	2 kHz */
#define ADAS1000_FRMCTL_FRMRATE_16KHZ	0x01		/*	16 kHz */
#define ADAS1000_FRMCTL_FRMRATE_128KHZ	0x10		/*	128 kHz */
#define ADAS1000_FRMCTL_FRMRATE_31_25HZ	0x11		/*	31.25 Hz */

#define ADAS1000_FRMCTL_WORD_MASK	(ADAS1000_FRMCTL_LEAD_I_LADIS 	| \
									 ADAS1000_FRMCTL_LEAD_II_LLDIS 	| \
									 ADAS1000_FRMCTL_LEAD_III_RADIS | \
									 ADAS1000_FRMCTL_V1DIS 			| \
									 ADAS1000_FRMCTL_V2DIS 			| \
									 ADAS1000_FRMCTL_PACEDIS 		| \
									 ADAS1000_FRMCTL_RESPMDIS 		| \
									 ADAS1000_FRMCTL_RESPPHDIS		| \
									 ADAS1000_FRMCTL_LOFFDIS 		| \
									 ADAS1000_FRMCTL_GPIODIS 		| \
									 ADAS1000_FRMCTL_CRCDIS)
#define ADAS1000_FRMCTL_SKIP_MASK		(0x00000003ul << 2)
#define ADAS1000_FRMCTL_FRMRATE_MASK	(0x00000003ul << 0)

/******************************************************************************/
/* 滤波器控制寄存器      													  */
/******************************************************************************/
#define ADAS1000_FILTCTL_MN2K	(1ul << 5)	/*	SPI主器件的2khz陷波旁路
													0 = 旁路陷波
													1 = 滤波存在 */
                                                    
#define ADAS1000_FILTCTL_N2KBP	(1ul << 4)	/*	2khz陷波旁路
													0 = 陷波存在
													1 = 陷波旁路 */
                                                    
#define ADAS1000_FILTCTL_LPF	(1ul << 2)	/*	低通滤波器设置
                                                00 = 40Hz
												01 = 150Hz
												10 = 250 Hz
												11 = 450Hz */

#define ADAS1000_FILTCTL_LPF_MASK	(0x00000003ul << 2)

/******************************************************************************/
/* 交流导联脱落阈值上限寄存器        										  */
/******************************************************************************/
#define ADAS1000_LOFFUTH_ADCOVER	(1ul << 16)	/*	ADC超量程阈值. 
                                                        阈值 = 最大值 - ADCOVER * 2^6
														0000 = max value (禁用)
														0001 = max_value - 64
														0010 = max_value - 128
														...
														1111: max_value - 960 */
                                                        
#define ADAS1000_LOFFUTH_LOFFUTH	(1ul << 0)	/*	AC Leads off upper Threshold. Leads off will be detected if the DC
													or AC output is = N * 2 * VREF/GAIN/2^16. 0 = 0V */

#define ADAS1000_LOFFUTH_ADCOVER_MASK	(0x0000000Ful << 16)
#define ADAS1000_LOFFUTH_LOFFUTH_MASK	(0x0000FFFFul << 0)

/******************************************************************************/
/* 交流导联脱落阈值下限寄存器        										  */
/******************************************************************************/
#define ADAS1000_LOFFLTH_ADCUNDR	(1ul << 16)	/*	ADC欠量程阈值. 
													阈值 = 最小值 + ADCUNDR * 2^6
														0000 = 最小值 (禁用)
														0001 = 最小值 + 64
														0010 = 最小值 + 128
														...
														1111: 最小值 + 960 */
                                                        
#define ADAS1000_LOFFLTH_LOFFLTH	(1ul << 0)	/*	AC Leads off lower Threshold. Leads off will be detected if the DC 
													or AC output is = N * 2 * VREF/GAIN/2^16. 0 = 0V */

#define ADAS1000_LOFFLTH_ADCUNDR_MASK	(0x0000000Ful << 16)
#define ADAS1000_LOFFLTH_LOFFLTH_MASK	(0x0000FFFFul << 0)

/******************************************************************************/
/* 起搏边沿阈值寄存器            											  */
/******************************************************************************/
#define ADAS1000_PACEEDGETH_PACE3EDGTH	(1ul << 16)	/*	起搏边沿触发阈值	*/
#define ADAS1000_PACEEDGETH_PACE2EDGTH	(1ul << 8)	/*		0 = PACEAMPTH/2			*/
#define ADAS1000_PACEEDGETH_PACE1EDGTH	(1ul << 0)	/*		1 = VREF/GAIN/2^16		*/
													/*		N = N * VREF/GAIN/2^16	*/

#define ADAS1000_PACEEDGETH_PACE3EDGTH_MASK	(0x000000FFul << 16)
#define ADAS1000_PACEEDGETH_PACE2EDGTH_MASK	(0x000000FFul << 8)
#define ADAS1000_PACEEDGETH_PACE1EDGTH_MASK	(0x000000FFul << 0)													
													
/******************************************************************************/
/* 起搏电平阈值寄存器            											  */
/******************************************************************************/
#define ADAS1000_PACELVLTH_PACE3LVLTH	(1ul << 16)	/*	起搏电平阈值，这是一个有符值.	*/
#define ADAS1000_PACELVLTH_PACE2LVLTH	(1ul << 8)	/*		-1 = 0xFFF = -VREF/GAIN/2^16				*/
#define ADAS1000_PACELVLTH_PACE1LVLTH	(1ul << 0)	/*		 0 = 0x0000 = 0V							*/
													/*		+1 = 0x001 = +VREF/GAIN/2^16				*/
													/*		 N = N * VREF/GAIN/2^16						*/

#define ADAS1000_PACELVLTH_PACE3LVLTH_MASK	(0x000000FFul << 16)
#define ADAS1000_PACELVLTH_PACE2LVLTH_MASK	(0x000000FFul << 8)
#define ADAS1000_PACELVLTH_PACE1LVLTH_MASK	(0x000000FFul << 0)													

/***********************************************************************************/
/* 导联数据寄存器                                                                  */
/***********************************************************************************/
 #define ADAS1000_LADATA_ADDRESS		(1ul << 24)	/* 	0x11 : LA或导联I
													0x12 : LL或导联II
													0x13 : RA或导联III
													0x14 : V1
													0x15 : V2*/
                                                    
#define ADAS1000_LADATA_ECG_DATA	(1ul << 0)	/*	通道数据值。数据左对齐（MSB），无论数据速率为何值
                                                    在电极模式和模拟导联模式下。数据结果为无符号整数
                                                    在数字导联或矢量模式下，值为有符二进制补码整数格式，范围是
                                                    电极格式的2倍，因为它能从+VREF摆动到-VREF；因此LSB大小加倍
                                                    
                                                    电极模式和模拟导联模式：
                                                      最小值（000....） = 0v
                                                      最大值（111....） = VREF/GAIN
                                                        LSB = (2*VREF/GAIN) / (2N-1)
                                                        ECG(电压) = ECG数据 * LSB
                                                    数字导联模式：
                                                      最小值（100....） = -（VREF/GAIN）
                                                      最大值（011....） = VREF/GAIN
                                                        LSB = (4 * VREF/GAIN) / (2N - 1)
                                                        ECG(电压) = ECG数据 * LSB
													
														其中，N是数据位数：128khz为16位，2/16khz为24位 */

#define ADAS1000_LADATA_ADDRESS_MASK	(0x000000FFul << 24)
#define ADAS1000_LADATA_ECG_DATA_MASK	(0x00FFFFFFul << 0)

/******************************************************************************/
/* 起搏检测数据、状态寄存器	            									  */
/******************************************************************************/
#define ADAS1000_PACEDATA_ADDRESS			(1ul << 24)	/*	0001 1010 = Pace Detection 	*/

#define ADAS1000_PACEDATA_PACE3_DETECTED	(1ul << 23)	/*	检测到起搏3. 
																0 = 未检测到起搏
																1 = 检测到起搏 */
                                                                
#define ADAS1000_PACEDATA_PACE_CH3_WIDTH	(1ul << 20)	/*	此位是起搏脉冲的log2(宽度)-1. 
															N: 宽度 = 2^(N+1) / 128kHz */
                                                            
#define ADAS1000_PACEDATA_PACE_CH3_HEIGHT	(1ul << 16)	/*	此位是起搏脉冲的log2(高度)
															N: 高度 = 2^N * VREF / GAIN / 2^16 */
                                                            
#define ADAS1000_PACEDATA_PACE2_DETECTED	(1ul << 15)	/*	检测的起搏2 
															   0 = 未检测到起搏
															   1 = 检测到起搏*/
                                                               
#define ADAS1000_PACEDATA_PACE_CH2_WIDTH	(1ul << 12)	/*	此位是起搏脉冲的log2(宽度)-1. 
															N: 宽度 = 2^(N+1) / 128kHz */
                                                            
#define ADAS1000_PACEDATA_PACE_CH2_HEIGHT	(1ul << 8)	/*	此位是起搏脉冲的log2(高度)
															N: 高度 = 2^N * VREF / GAIN / 2^16 */
                                                            
#define ADAS1000_PACEDATA_PACE1_DETECTED	(1ul << 7)	/*	检测到起搏1. 
															   0 = 未检测到起搏
															   1 = 检测到起搏 */
#define ADAS1000_PACEDATA_PACE_CH1_WIDTH	(1ul << 4)	/*	此位是起搏脉冲的log2(宽度)-1. 
															N: 宽度 = 2^(N+1) / 128kHz */
                                                            
#define ADAS1000_PACEDATA_CH1_HEIGHT		(1ul << 0)	/*	此位是起搏脉冲的log2(高度)
															N: 高度 = 2^N * VREF / GAIN / 2^16 */

#define ADAS1000_PACEDATA_ADDRESS_MASK			(0x000000FFul << 24)
#define ADAS1000_PACEDATA_PACE_CH3_WIDTH_MASK	(0x00000007ul << 20)
#define ADAS1000_PACEDATA_PACE_CH3_HEIGHT_MASK	(0x0000000Ful << 16)
#define ADAS1000_PACEDATA_PACE_CH2_WIDTH_MASK	(0x00000007ul << 12)
#define ADAS1000_PACEDATA_PACE_CH2_HEIGHT_MASK	(0x0000000Ful << 8)
#define ADAS1000_PACEDATA_PACE_CH1_WIDTH_MASK	(0x00000007ul << 4)
#define ADAS1000_PACEDATA_PACE_CH1_HEIGHT_MASK	(0x0000000Ful << 0)

/******************************************************************************/
/* 呼吸幅度数据寄存器                    									  */
/******************************************************************************/
#define ADAS1000_RESPMAG_ADDRESS	(1ul << 24)	/*	0001 1011 = Respiration Magnitude */

#define ADAS1000_RESPMAG_MAGNITUDE	(1ul << 0)	/*	呼吸信号的幅度。这是一个带符号的值. 
                                                    4 * （VREF / (1.6468 * 呼吸增益)） / （2^24 - 1）*/

#define ADAS1000_RESPMAG_ADDRESS_MASK	(0x000000FFul << 24)
#define ADAS1000_RESPMAG_MAGNITUDE_MASK	(0x00FFFFFFul << 0)

/******************************************************************************/
/* 呼吸相位数据寄存器                										  */
/******************************************************************************/
#define ADAS1000_RESPPH_ADDRESS	(1ul << 24)	/*	0001 1100 = Respiration Phase */

#define ADAS1000_RESPPH_PHASE	(1ul << 0)	/*	呼吸信号的相位.可以解读为带符号或无符号值。
                                                如果为无符号，则范围是0到2pai
                                                如果为有符号，则范围是-pai到pai
													0x000000 = 0
													0x000001 = 2pi / 2^24
													0x400000 = pi/2
													0x800000 = +pi = -pi 
													0xC00000 = +3pi/2 = -pi/2
													0xFFFFFF = +2pi(1 - 2^(-24)) = -2p / 2^24 */

#define ADAS1000_RESPPH_ADDRESS_MASK	(0x000000FFul << 24)
#define ADAS1000_RESPPH_PHASE_MASK		(0x00FFFFFFul << 0)

/******************************************************************************/
/* 导联脱落状态寄存器        												  */
/******************************************************************************/
#define ADAS1000_LOFF_ADDRESS				(1ul << 24)	/*	Address bits define the word data 0001 1101 = Leads Off	*/

#define ADAS1000_LOFF_RL_LEADS_OFF_STATUS	(1ul << 23)	/*	电极连接状态	*/
#define ADAS1000_LOFF_LA_LEADS_OFF_STATUS	(1ul << 22)	/*	如果直流或交流导联检测使能，这些位反映对应的导联脱落状态*/
#define ADAS1000_LOFF_LL_LEADS_OFF_STATUS	(1ul << 21)	/*	如果AC和DC均使能，则仅反映交流导联脱落状态 */
#define ADAS1000_LOFF_RA_LEADS_OFF_STATUS	(1ul << 20)	/*	直流状态通过DCLEAD-OFF寄存器提供 */
#define ADAS1000_LOFF_V1_LEADS_OFF_STATUS	(1ul << 19)	/*	CE电极只有DC脱落检测 */
#define ADAS1000_LOFF_V2_LEADS_OFF_STATUS	(1ul << 18)	
#define ADAS1000_LOFF_CELO					(1ul << 13) /*	   0 = 电极连接 */
														/*	   1 = 电极脱落 */
                                                        
#define ADAS1000_LOFF_LAADCOR				(1ul << 12)	/*	ADC溢出错误.*/
#define ADAS1000_LOFF_LLADCOR				(1ul << 11)	/*	这些位指示ADC超出范围*/
#define ADAS1000_LOFF_RAADCOR				(1ul << 10)
#define ADAS1000_LOFF_V1ADCOR				(1ul << 9)
#define ADAS1000_LOFF_V2ADCOR				(1ul << 8)

#define ADAS1000_LOFF_ADDRESS_MASK			(0x000000FFul << 24)

/******************************************************************************/
/* 直流导联脱落寄存器     													  */
/******************************************************************************/
#define ADAS1000_DCLEADSOFF_ADDRESS				(1ul << 24)	/*	Address bits define the word data 0001 1110 = DC Leads Off	  */

#define ADAS1000_DCLEADSOFF_RL_INPUT_OVERRANGE	(1ul << 23)	/*	直流导联脱落检测基于比较器 */
#define ADAS1000_DCLEADSOFF_LA_INPUT_OVERRANGE	(1ul << 22)	/*	与一个固定的电平进行比较 */
#define ADAS1000_DCLEADSOFF_LL_INPUT_OVERRANGE	(1ul << 21)	/*	各位指示是否超过直流比较阈值电平 */
#define ADAS1000_DCLEADSOFF_RA_INPUT_OVERRANGE	(1ul << 20)	/*	   0 = 电极 < 超范围阈值, 2.4 V	 */
#define ADAS1000_DCLEADSOFF_CE_INPUT_OVERRANGE	(1ul << 13)	/*	   1 = 电极 > 超范围阈值, 2.4 V	 */

#define ADAS1000_DCLEADSOFF_RL_INPUT_UNDERRANGE	(1ul << 12)	/*	直流导联脱落检测基于比较器 */
#define ADAS1000_DCLEADSOFF_LA_INPUT_UNDERRANGE	(1ul << 11)	/*	与一个固定的电平进行比较 */
#define ADAS1000_DCLEADSOFF_LL_INPUT_UNDERRANGE	(1ul << 10)	/*	各位指示是否超过直流比较阈值电平 */
#define ADAS1000_DCLEADSOFF_RA_INPUT_UNDERRANGE	(1ul << 9)	/*		0 = 电极 > 欠范围阈值, 0.2 V */
#define ADAS1000_DCLEADSOFF_CE_INPUT_UNDERRANGE	(1ul << 2)	/*	   	1 = 电极 < 欠范围阈值, 0.2 V */

#define ADAS1000_DCLEADSOFF_ADDRESS_MASK		(0x000000FFul << 24)

/******************************************************************************/
/* 呼吸输入拓展开关寄存器                              						  */
/******************************************************************************/
#define ADAS1000_EXTENDSW_EXTRESP_RA_LA		(1ul << 23)	/* 电极输入的外部呼吸电极输入开关	*/
#define ADAS1000_EXTENDSW_EXTRESP_RA_LL		(1ul << 22)
#define ADAS1000_EXTENDSW_EXTRESP_RA_RA		(1ul << 21)	/*		0 = 断开	*/
#define ADAS1000_EXTENDSW_EXTRESP_RA_V1		(1ul << 20)	/*		1 = 闭合	*/
#define ADAS1000_EXTENDSW_EXTRESP_RA_V2		(1ul << 19)
#define ADAS1000_EXTENDSW_EXTRESP_LL_LA		(1ul << 18)
#define ADAS1000_EXTENDSW_EXTRESP_LL_LL		(1ul << 17)
#define ADAS1000_EXTENDSW_EXTRESP_LL_RA		(1ul << 16)
#define ADAS1000_EXTENDSW_EXTRESP_LL_V1		(1ul << 15)
#define ADAS1000_EXTENDSW_EXTRESP_LL_V2		(1ul << 14)
#define ADAS1000_EXTENDSW_EXTRESP_LA_LA		(1ul << 13)
#define ADAS1000_EXTENDSW_EXTRESP_LA_LL		(1ul << 12)
#define ADAS1000_EXTENDSW_EXTRESP_LA_RA		(1ul << 11)
#define ADAS1000_EXTENDSW_EXTRESP_LA_V1		(1ul << 10)
#define ADAS1000_EXTENDSW_EXTRESP_LA_V2		(1ul << 9)

#define ADAS1000_EXTENDSW_FREE_V1			(1ul << 8)
#define ADAS1000_EXTENDSW_FREE_V2			(1ul << 7)

/******************************************************************************/
/* 用户增益校准寄存器                                						  */
/******************************************************************************/
#define	ADAS1000_CAL_ADDRESS	(1ul << 24)	/*	0x21 : CAL LA
												0x22 : CAL LL
												0x23 : CAL RA
												0x24 : CAL V1
												0x25 : CAL V2 */
                                                
#define	ADAS1000_CAL_USRCAL		(1ul << 23)	/*	校准值选择:
													0 = 工程校准
													1 = 用户校准 */
                                                    
#define	ADAS1000_CAL_CALVALUE	(1ul << 0)	/*	增益校准值. 
												结果 = 数据 * (1 + GAIN * 2^(-17))
													0x7FF (+2047) = *1.00000011111111111b
													0x001 (+1) 	  = *1.00000000000000001b
													0x000 (0)     = *1.00000000000000000b
													0xFFF (-1)    = *0.11111111111111111b
													0x800 (-2048) = *0.11111100000000000b */

#define	ADAS1000_CAL_ADDRESS_MASK	(0x000000FFul << 24)
#define	ADAS1000_CAL_CALVALUE_MASK	(0x00000FFFul << 0)

/******************************************************************************/
/* 交流导联脱落幅度寄存器                              						  */
/******************************************************************************/
#define	ADAS1000_LOAM_ADDRESS	(1ul << 24)	/*	0x31 : LA AC Leads off Magnitude
												0x32 : LL AC Leads off Magnitude
												0x33 : RA AC Leads off Magnitude
												0x34 : V1 AC Leads off Magnitude
												0x35 : V2 AC Leads off Magnitude */
                                                
#define	ADAS1000_LOAM_LOFFAM	(1ul << 0)	/*	幅度.
													最小值 0x0000 = 0V
													LSB 0x0001= VREF / GAIN / 2^16
													最大值 0xFFFF = VREF / GAIN */

#define	ADAS1000_LOAM_ADDRESS_MASK	(0x000000FFul << 24)
#define	ADAS1000_LOAM_LOFFAM_MASK	(0x0000FFFFul << 0)


/******************************************************************************/
/* 起搏宽度和幅度寄存器                           							  */
/******************************************************************************/
#define	ADAS1000_PACE_DATA_ADDRESS	(1ul << 24)	/*	0x3A : PACE1DATA
													0x3B : PACE2DATA
													0x3C : PACE3DATA */
                                                    
#define	ADAS1000_PACE_DATA_HEIGHT	(1ul << 8)	/*	起搏高度，有符二进制补码
														0 = 0 
														1 = VREF / GAIN / 2^16
														N = N * VREF / GAIN / 2^16 */
                                                        
#define	ADAS1000_PACE_DATA_WIDTH	(1ul << 0)	/*	起搏宽度，128khz采样；
														N:   N / 128kHz   = 宽度
														12:  12+1 / 128kHz  = 101.56us
														255: 255 / 128kHz = 2.0ms */

#define	ADAS1000_PACE_DATA_ADDRESS_MASK	(0x000000FFul << 24)
#define	ADAS1000_PACE_DATA_HEIGHT_MASK	(0x0000FFFFul << 8)
#define	ADAS1000_PACE_DATA_WIDTH_MASK	(0x000000FFul << 0)

/******************************************************************************/
/* 帧表头寄存器                           									  */
/******************************************************************************/
#define ADAS1000_FRAMES_MARKER					(1ul << 31)	/*	表头标志，设1表示表头 */

#define ADAS1000_FRAMES_READY_BIT				(1ul << 30)	/*	就绪位，指示ECG数据是否计算完成且可读取 
																   0 = 就绪
																   1 = 忙	*/
                                                                   
#define ADAS1000_FRAMES_OVERFLOW				(1ul << 28)	/*	溢出位 指示自上次以来，遗失的帧数 
																计数到达最大值时，此域饱和
																如果此位大于0 
																则帧中的数据有效但非最新
																使用跳过模式时(FLMCTL 3:2)
																溢出位用作标志
																非零表示溢出
																	00 = 0 遗失
																	01 = 1 遗失
																	10 = 2 遗失
																	11 = 3 个遗失或以上	*/
                                                                    
#define ADAS1000_FRAMES_FAULT					(1ul << 27)	/*	器件内部错误.
																	0 = 正常工作
																	1 = 错误	*/
                                                                    
#define ADAS1000_FRAMES_PACE3_DETECTED			(1ul << 26)	/*	起搏3
																	0 = 无起搏脉冲
																	1 = 起搏脉冲存在	*/
                                                                    
#define ADAS1000_FRAMES_PACE2_DETECTED			(1ul << 25)	/*	起搏2
																	0 = 无起搏脉冲
																	1 = 起搏脉冲存在	*/
                                                                    
#define ADAS1000_FRAMES_PACE1_DETECTED			(1ul << 24)	/*	起搏1
																	0 = 无起搏脉冲
																	1 = 起搏脉冲存在	*/
                                                                    
#define ADAS1000_FRAMES_RESPIRATION				(1ul << 23)	/*	0 = 无新的呼吸数据
																1 = 呼吸数据更新 */
                                                                
#define ADAS1000_FRAMES_LEADS_OFF_DETECTED		(1ul << 22)	/*	如果DC和AC检测都使能，则此位表示所有交流导联脱落和
                                                                直流导联脱落的“或”结果
                                                                如果只使能AC或者DC，那么此位表示AC或DC导联脱落的
                                                                “或”结果
                                                                即，任意一个导联出现脱落现象，该位置1
																	0 = 所有导联正常
																	1 = 一个或更多导联脱落	*/
                                                                    
#define ADAS1000_FRAMES_DC_LEADS_OFF_DETECTED	(1ul << 21)	/*	0 = 所有导联连接
																1 = 一个或更多导联脱落	*/
                                                                
#define ADAS1000_FRAMES_ADC_OUT_OF_RANGE		(1ul << 20)	/*	0 = ADC在范围内
																1 = ADC 溢出 */

