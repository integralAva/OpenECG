#include "bsp_lcd.h"

#include "tim.h"

#define Set_SDA TSDI_GPIO_Port->BSRR = TSDI_Pin;
#define Clr_SDA TSDI_GPIO_Port->BSRR = TSDI_Pin << 16;

#define Set_RS TRS_GPIO_Port->BSRR = TRS_Pin;
#define Clr_RS TRS_GPIO_Port->BSRR = TRS_Pin << 16;

#define Set_WR TWR_GPIO_Port->BSRR = TWR_Pin;
#define Clr_WR TWR_GPIO_Port->BSRR = TWR_Pin << 16;

static void LCD_Reset(void)
{
    TRST_GPIO_Port->BSRR = TRST_Pin << 16;
    osDelay(500);
    TRST_GPIO_Port->BSRR = TRST_Pin;
    osDelay(500);
}

static void WriteComm(uint16_t CMD)
{
    Clr_RS;
    GPIOE->ODR = CMD;
    Clr_WR;
    Set_WR;
}

static void WriteData(uint16_t data)
{
    Set_RS;
    GPIOE->ODR = data;
    Clr_WR;
    Set_WR;
}


/*0-499*/
void BSP_LCD_SetLight(uint16_t light)
{
    __HAL_TIM_SetCompare(&htim12,TIM_CHANNEL_1,light);
}



void BSP_LCD_Init(void)
{
    TRS_GPIO_Port->BSRR = TRS_Pin;
    TWR_GPIO_Port->BSRR = TWR_Pin;
    TRD_GPIO_Port->BSRR = TRD_Pin;
    
    LCD_Reset();
    
    TCS_GPIO_Port->BSRR = TCS_Pin << 16;
    
        //ENABLE PAGE 1
    WriteComm(0xF000);WriteData(0x55);
    WriteComm(0xF001);WriteData(0xAA);
    WriteComm(0xF002);WriteData(0x52);
    WriteComm(0xF003);WriteData(0x08);
    WriteComm(0xF004);WriteData(0x01);

    //GAMMA SETING  RED
    WriteComm(0xD100);WriteData(0x00);
    WriteComm(0xD101);WriteData(0x00);
    WriteComm(0xD102);WriteData(0x1b);
    WriteComm(0xD103);WriteData(0x44);
    WriteComm(0xD104);WriteData(0x62);
    WriteComm(0xD105);WriteData(0x00);
    WriteComm(0xD106);WriteData(0x7b);
    WriteComm(0xD107);WriteData(0xa1);
    WriteComm(0xD108);WriteData(0xc0);
    WriteComm(0xD109);WriteData(0xee);
    WriteComm(0xD10A);WriteData(0x55);
    WriteComm(0xD10B);WriteData(0x10);
    WriteComm(0xD10C);WriteData(0x2c);
    WriteComm(0xD10D);WriteData(0x43);
    WriteComm(0xD10E);WriteData(0x57);
    WriteComm(0xD10F);WriteData(0x55);
    WriteComm(0xD110);WriteData(0x68);
    WriteComm(0xD111);WriteData(0x78);
    WriteComm(0xD112);WriteData(0x87);
    WriteComm(0xD113);WriteData(0x94);
    WriteComm(0xD114);WriteData(0x55);
    WriteComm(0xD115);WriteData(0xa0);
    WriteComm(0xD116);WriteData(0xac);
    WriteComm(0xD117);WriteData(0xb6);
    WriteComm(0xD118);WriteData(0xc1);
    WriteComm(0xD119);WriteData(0x55);
    WriteComm(0xD11A);WriteData(0xcb);
    WriteComm(0xD11B);WriteData(0xcd);
    WriteComm(0xD11C);WriteData(0xd6);
    WriteComm(0xD11D);WriteData(0xdf);
    WriteComm(0xD11E);WriteData(0x95);
    WriteComm(0xD11F);WriteData(0xe8);
    WriteComm(0xD120);WriteData(0xf1);
    WriteComm(0xD121);WriteData(0xfa);
    WriteComm(0xD122);WriteData(0x02);
    WriteComm(0xD123);WriteData(0xaa);
    WriteComm(0xD124);WriteData(0x0b);
    WriteComm(0xD125);WriteData(0x13);
    WriteComm(0xD126);WriteData(0x1d);
    WriteComm(0xD127);WriteData(0x26);
    WriteComm(0xD128);WriteData(0xaa);
    WriteComm(0xD129);WriteData(0x30);
    WriteComm(0xD12A);WriteData(0x3c);
    WriteComm(0xD12B);WriteData(0x4A);
    WriteComm(0xD12C);WriteData(0x63);
    WriteComm(0xD12D);WriteData(0xea);
    WriteComm(0xD12E);WriteData(0x79);
    WriteComm(0xD12F);WriteData(0xa6);
    WriteComm(0xD130);WriteData(0xd0);
    WriteComm(0xD131);WriteData(0x20);
    WriteComm(0xD132);WriteData(0x0f);
    WriteComm(0xD133);WriteData(0x8e);
    WriteComm(0xD134);WriteData(0xff);
    //GAMMA SETING GREEN
    WriteComm(0xD200);WriteData(0x00);
    WriteComm(0xD201);WriteData(0x00);
    WriteComm(0xD202);WriteData(0x1b);
    WriteComm(0xD203);WriteData(0x44);
    WriteComm(0xD204);WriteData(0x62);
    WriteComm(0xD205);WriteData(0x00);
    WriteComm(0xD206);WriteData(0x7b);
    WriteComm(0xD207);WriteData(0xa1);
    WriteComm(0xD208);WriteData(0xc0);
    WriteComm(0xD209);WriteData(0xee);
    WriteComm(0xD20A);WriteData(0x55);
    WriteComm(0xD20B);WriteData(0x10);
    WriteComm(0xD20C);WriteData(0x2c);
    WriteComm(0xD20D);WriteData(0x43);
    WriteComm(0xD20E);WriteData(0x57);
    WriteComm(0xD20F);WriteData(0x55);
    WriteComm(0xD210);WriteData(0x68);
    WriteComm(0xD211);WriteData(0x78);
    WriteComm(0xD212);WriteData(0x87);
    WriteComm(0xD213);WriteData(0x94);
    WriteComm(0xD214);WriteData(0x55);
    WriteComm(0xD215);WriteData(0xa0);
    WriteComm(0xD216);WriteData(0xac);
    WriteComm(0xD217);WriteData(0xb6);
    WriteComm(0xD218);WriteData(0xc1);
    WriteComm(0xD219);WriteData(0x55);
    WriteComm(0xD21A);WriteData(0xcb);
    WriteComm(0xD21B);WriteData(0xcd);
    WriteComm(0xD21C);WriteData(0xd6);
    WriteComm(0xD21D);WriteData(0xdf);
    WriteComm(0xD21E);WriteData(0x95);
    WriteComm(0xD21F);WriteData(0xe8);
    WriteComm(0xD220);WriteData(0xf1);
    WriteComm(0xD221);WriteData(0xfa);
    WriteComm(0xD222);WriteData(0x02);
    WriteComm(0xD223);WriteData(0xaa);
    WriteComm(0xD224);WriteData(0x0b);
    WriteComm(0xD225);WriteData(0x13);
    WriteComm(0xD226);WriteData(0x1d);
    WriteComm(0xD227);WriteData(0x26);
    WriteComm(0xD228);WriteData(0xaa);
    WriteComm(0xD229);WriteData(0x30);
    WriteComm(0xD22A);WriteData(0x3c);
    WriteComm(0xD22B);WriteData(0x4a);
    WriteComm(0xD22C);WriteData(0x63);
    WriteComm(0xD22D);WriteData(0xea);
    WriteComm(0xD22E);WriteData(0x79);
    WriteComm(0xD22F);WriteData(0xa6);
    WriteComm(0xD230);WriteData(0xd0);
    WriteComm(0xD231);WriteData(0x20);
    WriteComm(0xD232);WriteData(0x0f);
    WriteComm(0xD233);WriteData(0x8e);
    WriteComm(0xD234);WriteData(0xff);

    //GAMMA SETING BLUE
    WriteComm(0xD300);WriteData(0x00);
    WriteComm(0xD301);WriteData(0x00);
    WriteComm(0xD302);WriteData(0x1b);
    WriteComm(0xD303);WriteData(0x44);
    WriteComm(0xD304);WriteData(0x62);
    WriteComm(0xD305);WriteData(0x00);
    WriteComm(0xD306);WriteData(0x7b);
    WriteComm(0xD307);WriteData(0xa1);
    WriteComm(0xD308);WriteData(0xc0);
    WriteComm(0xD309);WriteData(0xee);
    WriteComm(0xD30A);WriteData(0x55);
    WriteComm(0xD30B);WriteData(0x10);
    WriteComm(0xD30C);WriteData(0x2c);
    WriteComm(0xD30D);WriteData(0x43);
    WriteComm(0xD30E);WriteData(0x57);
    WriteComm(0xD30F);WriteData(0x55);
    WriteComm(0xD310);WriteData(0x68);
    WriteComm(0xD311);WriteData(0x78);
    WriteComm(0xD312);WriteData(0x87);
    WriteComm(0xD313);WriteData(0x94);
    WriteComm(0xD314);WriteData(0x55);
    WriteComm(0xD315);WriteData(0xa0);
    WriteComm(0xD316);WriteData(0xac);
    WriteComm(0xD317);WriteData(0xb6);
    WriteComm(0xD318);WriteData(0xc1);
    WriteComm(0xD319);WriteData(0x55);
    WriteComm(0xD31A);WriteData(0xcb);
    WriteComm(0xD31B);WriteData(0xcd);
    WriteComm(0xD31C);WriteData(0xd6);
    WriteComm(0xD31D);WriteData(0xdf);
    WriteComm(0xD31E);WriteData(0x95);
    WriteComm(0xD31F);WriteData(0xe8);
    WriteComm(0xD320);WriteData(0xf1);
    WriteComm(0xD321);WriteData(0xfa);
    WriteComm(0xD322);WriteData(0x02);
    WriteComm(0xD323);WriteData(0xaa);
    WriteComm(0xD324);WriteData(0x0b);
    WriteComm(0xD325);WriteData(0x13);
    WriteComm(0xD326);WriteData(0x1d);
    WriteComm(0xD327);WriteData(0x26);
    WriteComm(0xD328);WriteData(0xaa);
    WriteComm(0xD329);WriteData(0x30);
    WriteComm(0xD32A);WriteData(0x3c);
    WriteComm(0xD32B);WriteData(0x4A);
    WriteComm(0xD32C);WriteData(0x63);
    WriteComm(0xD32D);WriteData(0xea);
    WriteComm(0xD32E);WriteData(0x79);
    WriteComm(0xD32F);WriteData(0xa6);
    WriteComm(0xD330);WriteData(0xd0);
    WriteComm(0xD331);WriteData(0x20);
    WriteComm(0xD332);WriteData(0x0f);
    WriteComm(0xD333);WriteData(0x8e);
    WriteComm(0xD334);WriteData(0xff);


    //GAMMA SETING  RED
    WriteComm(0xD400);WriteData(0x00);
    WriteComm(0xD401);WriteData(0x00);
    WriteComm(0xD402);WriteData(0x1b);
    WriteComm(0xD403);WriteData(0x44);
    WriteComm(0xD404);WriteData(0x62);
    WriteComm(0xD405);WriteData(0x00);
    WriteComm(0xD406);WriteData(0x7b);
    WriteComm(0xD407);WriteData(0xa1);
    WriteComm(0xD408);WriteData(0xc0);
    WriteComm(0xD409);WriteData(0xee);
    WriteComm(0xD40A);WriteData(0x55);
    WriteComm(0xD40B);WriteData(0x10);
    WriteComm(0xD40C);WriteData(0x2c);
    WriteComm(0xD40D);WriteData(0x43);
    WriteComm(0xD40E);WriteData(0x57);
    WriteComm(0xD40F);WriteData(0x55);
    WriteComm(0xD410);WriteData(0x68);
    WriteComm(0xD411);WriteData(0x78);
    WriteComm(0xD412);WriteData(0x87);
    WriteComm(0xD413);WriteData(0x94);
    WriteComm(0xD414);WriteData(0x55);
    WriteComm(0xD415);WriteData(0xa0);
    WriteComm(0xD416);WriteData(0xac);
    WriteComm(0xD417);WriteData(0xb6);
    WriteComm(0xD418);WriteData(0xc1);
    WriteComm(0xD419);WriteData(0x55);
    WriteComm(0xD41A);WriteData(0xcb);
    WriteComm(0xD41B);WriteData(0xcd);
    WriteComm(0xD41C);WriteData(0xd6);
    WriteComm(0xD41D);WriteData(0xdf);
    WriteComm(0xD41E);WriteData(0x95);
    WriteComm(0xD41F);WriteData(0xe8);
    WriteComm(0xD420);WriteData(0xf1);
    WriteComm(0xD421);WriteData(0xfa);
    WriteComm(0xD422);WriteData(0x02);
    WriteComm(0xD423);WriteData(0xaa);
    WriteComm(0xD424);WriteData(0x0b);
    WriteComm(0xD425);WriteData(0x13);
    WriteComm(0xD426);WriteData(0x1d);
    WriteComm(0xD427);WriteData(0x26);
    WriteComm(0xD428);WriteData(0xaa);
    WriteComm(0xD429);WriteData(0x30);
    WriteComm(0xD42A);WriteData(0x3c);
    WriteComm(0xD42B);WriteData(0x4A);
    WriteComm(0xD42C);WriteData(0x63);
    WriteComm(0xD42D);WriteData(0xea);
    WriteComm(0xD42E);WriteData(0x79);
    WriteComm(0xD42F);WriteData(0xa6);
    WriteComm(0xD430);WriteData(0xd0);
    WriteComm(0xD431);WriteData(0x20);
    WriteComm(0xD432);WriteData(0x0f);
    WriteComm(0xD433);WriteData(0x8e);
    WriteComm(0xD434);WriteData(0xff);

    //GAMMA SETING GREEN
    WriteComm(0xD500);WriteData(0x00);
    WriteComm(0xD501);WriteData(0x00);
    WriteComm(0xD502);WriteData(0x1b);
    WriteComm(0xD503);WriteData(0x44);
    WriteComm(0xD504);WriteData(0x62);
    WriteComm(0xD505);WriteData(0x00);
    WriteComm(0xD506);WriteData(0x7b);
    WriteComm(0xD507);WriteData(0xa1);
    WriteComm(0xD508);WriteData(0xc0);
    WriteComm(0xD509);WriteData(0xee);
    WriteComm(0xD50A);WriteData(0x55);
    WriteComm(0xD50B);WriteData(0x10);
    WriteComm(0xD50C);WriteData(0x2c);
    WriteComm(0xD50D);WriteData(0x43);
    WriteComm(0xD50E);WriteData(0x57);
    WriteComm(0xD50F);WriteData(0x55);
    WriteComm(0xD510);WriteData(0x68);
    WriteComm(0xD511);WriteData(0x78);
    WriteComm(0xD512);WriteData(0x87);
    WriteComm(0xD513);WriteData(0x94);
    WriteComm(0xD514);WriteData(0x55);
    WriteComm(0xD515);WriteData(0xa0);
    WriteComm(0xD516);WriteData(0xac);
    WriteComm(0xD517);WriteData(0xb6);
    WriteComm(0xD518);WriteData(0xc1);
    WriteComm(0xD519);WriteData(0x55);
    WriteComm(0xD51A);WriteData(0xcb);
    WriteComm(0xD51B);WriteData(0xcd);
    WriteComm(0xD51C);WriteData(0xd6);
    WriteComm(0xD51D);WriteData(0xdf);
    WriteComm(0xD51E);WriteData(0x95);
    WriteComm(0xD51F);WriteData(0xe8);
    WriteComm(0xD520);WriteData(0xf1);
    WriteComm(0xD521);WriteData(0xfa);
    WriteComm(0xD522);WriteData(0x02);
    WriteComm(0xD523);WriteData(0xaa);
    WriteComm(0xD524);WriteData(0x0b);
    WriteComm(0xD525);WriteData(0x13);
    WriteComm(0xD526);WriteData(0x1d);
    WriteComm(0xD527);WriteData(0x26);
    WriteComm(0xD528);WriteData(0xaa);
    WriteComm(0xD529);WriteData(0x30);
    WriteComm(0xD52A);WriteData(0x3c);
    WriteComm(0xD52B);WriteData(0x4a);
    WriteComm(0xD52C);WriteData(0x63);
    WriteComm(0xD52D);WriteData(0xea);
    WriteComm(0xD52E);WriteData(0x79);
    WriteComm(0xD52F);WriteData(0xa6);
    WriteComm(0xD530);WriteData(0xd0);
    WriteComm(0xD531);WriteData(0x20);
    WriteComm(0xD532);WriteData(0x0f);
    WriteComm(0xD533);WriteData(0x8e);
    WriteComm(0xD534);WriteData(0xff);

    //GAMMA SETING BLUE
    WriteComm(0xD600);WriteData(0x00);
    WriteComm(0xD601);WriteData(0x00);
    WriteComm(0xD602);WriteData(0x1b);
    WriteComm(0xD603);WriteData(0x44);
    WriteComm(0xD604);WriteData(0x62);
    WriteComm(0xD605);WriteData(0x00);
    WriteComm(0xD606);WriteData(0x7b);
    WriteComm(0xD607);WriteData(0xa1);
    WriteComm(0xD608);WriteData(0xc0);
    WriteComm(0xD609);WriteData(0xee);
    WriteComm(0xD60A);WriteData(0x55);
    WriteComm(0xD60B);WriteData(0x10);
    WriteComm(0xD60C);WriteData(0x2c);
    WriteComm(0xD60D);WriteData(0x43);
    WriteComm(0xD60E);WriteData(0x57);
    WriteComm(0xD60F);WriteData(0x55);
    WriteComm(0xD610);WriteData(0x68);
    WriteComm(0xD611);WriteData(0x78);
    WriteComm(0xD612);WriteData(0x87);
    WriteComm(0xD613);WriteData(0x94);
    WriteComm(0xD614);WriteData(0x55);
    WriteComm(0xD615);WriteData(0xa0);
    WriteComm(0xD616);WriteData(0xac);
    WriteComm(0xD617);WriteData(0xb6);
    WriteComm(0xD618);WriteData(0xc1);
    WriteComm(0xD619);WriteData(0x55);
    WriteComm(0xD61A);WriteData(0xcb);
    WriteComm(0xD61B);WriteData(0xcd);
    WriteComm(0xD61C);WriteData(0xd6);
    WriteComm(0xD61D);WriteData(0xdf);
    WriteComm(0xD61E);WriteData(0x95);
    WriteComm(0xD61F);WriteData(0xe8);
    WriteComm(0xD620);WriteData(0xf1);
    WriteComm(0xD621);WriteData(0xfa);
    WriteComm(0xD622);WriteData(0x02);
    WriteComm(0xD623);WriteData(0xaa);
    WriteComm(0xD624);WriteData(0x0b);
    WriteComm(0xD625);WriteData(0x13);
    WriteComm(0xD626);WriteData(0x1d);
    WriteComm(0xD627);WriteData(0x26);
    WriteComm(0xD628);WriteData(0xaa);
    WriteComm(0xD629);WriteData(0x30);
    WriteComm(0xD62A);WriteData(0x3c);
    WriteComm(0xD62B);WriteData(0x4A);
    WriteComm(0xD62C);WriteData(0x63);
    WriteComm(0xD62D);WriteData(0xea);
    WriteComm(0xD62E);WriteData(0x79);
    WriteComm(0xD62F);WriteData(0xa6);
    WriteComm(0xD630);WriteData(0xd0);
    WriteComm(0xD631);WriteData(0x20);
    WriteComm(0xD632);WriteData(0x0f);
    WriteComm(0xD633);WriteData(0x8e);
    WriteComm(0xD634);WriteData(0xff);

    //AVDD VOLTAGE SETTING
    WriteComm(0xB000);WriteData(0x05);
    WriteComm(0xB001);WriteData(0x05);
    WriteComm(0xB002);WriteData(0x05);
    //AVEE VOLTAGE SETTING
    WriteComm(0xB100);WriteData(0x05);
    WriteComm(0xB101);WriteData(0x05);
    WriteComm(0xB102);WriteData(0x05);

    //AVDD Boosting
    WriteComm(0xB600);WriteData(0x34);
    WriteComm(0xB601);WriteData(0x34);
    WriteComm(0xB603);WriteData(0x34);
    //AVEE Boosting
    WriteComm(0xB700);WriteData(0x24);
    WriteComm(0xB701);WriteData(0x24);
    WriteComm(0xB702);WriteData(0x24);
    //VCL Boosting
    WriteComm(0xB800);WriteData(0x24);
    WriteComm(0xB801);WriteData(0x24);
    WriteComm(0xB802);WriteData(0x24);
    //VGLX VOLTAGE SETTING
    WriteComm(0xBA00);WriteData(0x14);
    WriteComm(0xBA01);WriteData(0x14);
    WriteComm(0xBA02);WriteData(0x14);
    //VCL Boosting
    WriteComm(0xB900);WriteData(0x24);
    WriteComm(0xB901);WriteData(0x24);
    WriteComm(0xB902);WriteData(0x24);
    //Gamma Voltage
    WriteComm(0xBc00);WriteData(0x00);
    WriteComm(0xBc01);WriteData(0xa0);//vgmp=5.0
    WriteComm(0xBc02);WriteData(0x00);
    WriteComm(0xBd00);WriteData(0x00);
    WriteComm(0xBd01);WriteData(0xa0);//vgmn=5.0
    WriteComm(0xBd02);WriteData(0x00);
    //VCOM Setting
    WriteComm(0xBe01);WriteData(0x3d);//3
    //ENABLE PAGE 0
    WriteComm(0xF000);WriteData(0x55);
    WriteComm(0xF001);WriteData(0xAA);
    WriteComm(0xF002);WriteData(0x52);
    WriteComm(0xF003);WriteData(0x08);
    WriteComm(0xF004);WriteData(0x00);
    //Vivid Color Function Control
    WriteComm(0xB400);WriteData(0x10);
    //Z-INVERSION
    WriteComm(0xBC00);WriteData(0x05);
    WriteComm(0xBC01);WriteData(0x05);
    WriteComm(0xBC02);WriteData(0x05);

    //*************** add on 20111021**********************//
    WriteComm(0xB700);WriteData(0x22);//GATE EQ CONTROL
    WriteComm(0xB701);WriteData(0x22);//GATE EQ CONTROL

    WriteComm(0xC80B);WriteData(0x2A);//DISPLAY TIMING CONTROL
    WriteComm(0xC80C);WriteData(0x2A);//DISPLAY TIMING CONTROL
    WriteComm(0xC80F);WriteData(0x2A);//DISPLAY TIMING CONTROL
    WriteComm(0xC810);WriteData(0x2A);//DISPLAY TIMING CONTROL
    //*************** add on 20111021**********************//
    //PWM_ENH_OE =1
    WriteComm(0xd000);WriteData(0x01);
    //DM_SEL =1
    WriteComm(0xb300);WriteData(0x10);
    //VBPDA=07h
    WriteComm(0xBd02);WriteData(0x07);
    //VBPDb=07h
    WriteComm(0xBe02);WriteData(0x07);
    //VBPDc=07h
    WriteComm(0xBf02);WriteData(0x07);
    //ENABLE PAGE 2
    WriteComm(0xF000);WriteData(0x55);
    WriteComm(0xF001);WriteData(0xAA);
    WriteComm(0xF002);WriteData(0x52);
    WriteComm(0xF003);WriteData(0x08);
    WriteComm(0xF004);WriteData(0x02);
    //SDREG0 =0
    WriteComm(0xc301);WriteData(0xa9);
    //DS=14
    WriteComm(0xfe01);WriteData(0x94);
    //OSC =60h
    WriteComm(0xf600);WriteData(0x60);
    //TE ON
    WriteComm(0x3500);WriteData(0x00);
    //SLEEP OUT 
    WriteComm(0x1100);
    osDelay(120);
    //DISPLY ON
    WriteComm(0x2900);
    osDelay(100);

        
    WriteComm(0x3A00); WriteData(0x55); //如果用24位，则是77；如果你用16位，例如STM32的FSMC，77改为55
    WriteComm(0x3600);WriteData(0x00A3);//这个AB的高5位是旋转屏幕用的，D3位是设置RGB与BGR顺序，低两位是相互镜像X轴与Y轴 

    BSP_LCD_Fill(0,0,799,479,Black);
    HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);
    BSP_LCD_SetLight(499);
}

static void SelectArea(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2)
{
    WriteComm(0x2a00);   
	WriteData(x1>>8);
	WriteComm(0x2a01); 
	WriteData(x1&0xFF);
	WriteComm(0x2a02); 
	WriteData(x2>>8);
	WriteComm(0x2a03); 
	WriteData(x2&0xFF);

	WriteComm(0x2b00);   
	WriteData(y1>>8);
	WriteComm(0x2b01); 
	WriteData(y1&0xFF);
	WriteComm(0x2b02); 
	WriteData(y2>>8);
	WriteComm(0x2b03); 
	WriteData(y2&0xFF);
	WriteComm(0x2c00);
}

void BSP_LCD_DrawPixel(uint16_t x,uint16_t y,uint16_t color)
{
    SelectArea(x,x,y,y);
    Set_RS;
    GPIOE->ODR = color;
    Clr_WR;
    Set_WR;
}

uint16_t BSP_LCD_GetPixel(uint16_t x,uint16_t y)
{
    uint16_t temp;
    //不同于写指令，最后一行使用读指令
    WriteComm(0x2a00);   
	WriteData(x>>8);
	WriteComm(0x2a01); 
	WriteData(x&0xFF);
	WriteComm(0x2a02); 
	WriteData(x>>8);
	WriteComm(0x2a03); 
	WriteData(x&0xFF);

	WriteComm(0x2b00);   
	WriteData(y>>8);
	WriteComm(0x2b01); 
	WriteData(y&0xFF);
	WriteComm(0x2b02); 
	WriteData(y>>8);
	WriteComm(0x2b03); 
	WriteData(y&0xFF);
	WriteComm(0x2e00);
    
    LL_GPIO_SetPinMode(GPIOE,GPIO_PIN_All,GPIO_MODE_INPUT);
    
    TRD_GPIO_Port->BSRR = TRD_Pin << 16;
    TRD_GPIO_Port->BSRR = TRD_Pin;
    
    temp = GPIOE->IDR;
    
    LL_GPIO_SetPinMode(GPIOE,GPIO_PIN_All,GPIO_MODE_OUTPUT_PP);
    
    return temp;
    
}

void BSP_LCD_Fill(uint16_t x,uint16_t y,uint16_t xend,uint16_t yend,uint16_t Color)
{
    uint32_t pixel = (xend-x+1)*(yend-y+1);
	SelectArea(x,xend,y,yend);
	Set_RS;
    GPIOE->ODR = Color;
	for (uint32_t temp=0; temp<pixel; temp++)
	{
		Clr_WR;
        Set_WR;
	}
}


