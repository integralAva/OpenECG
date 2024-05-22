#define GUILITE_ON
#include "GuiLite.h"
#include "System.h"
#include "bsp_lcd.h"

#include "DataCenter.h"

extern "C" void ECG_CalcBMP_function(ECG_BMP_CH ch);

void delay_ms(unsigned short nms)
{
    osDelay(nms);
}

const int UI_WIDTH = 800;
const int UI_HEIGHT = 480;

/////////////////////////// UI //////////////////////////////////
static c_wave_ctrl *p_wave;


enum WND_ID
{
    //wave
	ID_ROOT = 1,
	ID_WAVE1,
	ID_WAVE2,
	ID_WAVE3,
    ID_WAVE4,
    //button
    ID_BUTTON_WAVE1,
    ID_BUTTON_WAVE2,
    ID_BUTTON_WAVE3,
    ID_BUTTON_WAVE4,
    //wave_speed
    ID_BTSP_WAVE1,
    ID_BTSP_WAVE2,
    ID_BTSP_WAVE3,
    ID_BTSP_WAVE4,
    //control button
    ID_EBMP_SEL
    
};

typedef enum{
    CH_I,
    CH_II,
    CH_III,
    CH_aVR,
    CH_aVL,
    CH_aVF,
    CH_V,
    CH_RESP
}ecg_channel;

typedef enum{
    CH_SP_1X = 1,
    CH_SP_2X,
    CH_SP_3X
}channel_speed;

typedef enum{
    LEAD_I = 1,
    LEAD_II,
    LEAD_III
}ecg_calc_bmp_tag;

struct wave_channel_speed{
    channel_speed wave1_sp;
    channel_speed wave2_sp;
    channel_speed wave3_sp;
    channel_speed wave4_sp;
}wave_speed_lab;

struct wave_channel{
    ecg_channel wave1_ch;
    ecg_channel wave2_ch;
    ecg_channel wave3_ch;
    ecg_channel wave4_ch;
    int32_t *wave1_data;
    int32_t *wave2_data;
    int32_t *wave3_data;
    int32_t *wave4_data;
}wave_lab;

struct {
    ecg_calc_bmp_tag bmp_channel;
}o_button_lab;


class c_waveUI : public c_wnd
{
	virtual void on_init_children(void) {
        //init var
        wave_lab.wave1_ch = CH_I;
        wave_lab.wave2_ch = CH_II;
        wave_lab.wave3_ch = CH_V;
        wave_lab.wave4_ch = CH_RESP;
        o_button_lab.bmp_channel = LEAD_III;
        button_update(ID_BUTTON_WAVE1,&wave_lab.wave1_ch,&wave_lab.wave1_data);
        button_update(ID_BUTTON_WAVE2,&wave_lab.wave2_ch,&wave_lab.wave2_data);
        button_update(ID_BUTTON_WAVE3,&wave_lab.wave3_ch,&wave_lab.wave3_data);
        button_update(ID_BUTTON_WAVE4,&wave_lab.wave4_ch,&wave_lab.wave4_data);
        wave_speed_lab.wave1_sp = CH_SP_2X;
        wave_speed_lab.wave1_sp = CH_SP_2X;
        wave_speed_lab.wave1_sp = CH_SP_1X;
        wave_speed_lab.wave1_sp = CH_SP_1X;
        
        
        //Link Button
        ((c_button*)get_wnd_ptr(ID_BUTTON_WAVE1))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked);
		((c_button*)get_wnd_ptr(ID_BUTTON_WAVE2))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked);
		((c_button*)get_wnd_ptr(ID_BUTTON_WAVE3))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked);
		((c_button*)get_wnd_ptr(ID_BUTTON_WAVE4))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked);
        //button_speed
        ((c_button*)get_wnd_ptr(ID_BTSP_WAVE1))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked_speed);
		((c_button*)get_wnd_ptr(ID_BTSP_WAVE2))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked_speed);
		((c_button*)get_wnd_ptr(ID_BTSP_WAVE3))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked_speed);
		((c_button*)get_wnd_ptr(ID_BTSP_WAVE4))->set_on_click((WND_CALLBACK)&c_waveUI::on_clicked_speed);
        //button_ecg_bmp
        ((c_button*)get_wnd_ptr(ID_EBMP_SEL))->set_on_click((WND_CALLBACK)&c_waveUI::on_click_bmp);
        
        //Link Wave
		p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE1);
		p_wave->set_wave_speed(2);
		p_wave->set_wave_color(GL_RGB(0, 255, 0));
		p_wave->set_wave_in_out_rate(1000, 20);
		p_wave->set_wave(&m_wave_buffer1);
		p_wave->set_max_min(4000, -3000);

		p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE2);
		p_wave->set_wave_speed(2);
		p_wave->set_wave_color(GL_RGB(0, 255, 0));
		p_wave->set_wave_in_out_rate(1000, 20);
		p_wave->set_wave(&m_wave_buffer2);
		p_wave->set_max_min(4000, -3000);

		p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE3);
		p_wave->set_wave_speed(1);
		p_wave->set_wave_color(GL_RGB(41, 189, 189));
		p_wave->set_wave_in_out_rate(1000, 20);
		p_wave->set_wave(&m_wave_buffer3);
		p_wave->set_max_min(4000, -3000);
        
        p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE4);
		p_wave->set_wave_speed(1);
		p_wave->set_wave_color(GL_RGB(255, 255, 0));
		p_wave->set_wave_in_out_rate(1000, 20);
		p_wave->set_wave(&m_wave_buffer4);
		p_wave->set_max_min(5000, 0);
	}
	virtual void on_paint(void)
	{
		c_rect rect;
		get_screen_rect(rect);
		m_surface->fill_rect(rect, GL_RGB(0, 0, 0), m_z_order);
	}
    void on_clicked(int ctrl_id, int param)
    {
        ecg_channel *waven;
        int32_t **wave_datan;
        switch(ctrl_id){
            case ID_BUTTON_WAVE1:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE1);
                waven = &wave_lab.wave1_ch;
                wave_datan = &wave_lab.wave1_data;
                break;
            case ID_BUTTON_WAVE2:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE2);
                waven = &wave_lab.wave2_ch;
                wave_datan = &wave_lab.wave2_data;
                break;
            case ID_BUTTON_WAVE3:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE3);
                waven = &wave_lab.wave3_ch;
                wave_datan = &wave_lab.wave3_data;
                break;
            case ID_BUTTON_WAVE4:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE4);
                waven = &wave_lab.wave4_ch;
                wave_datan = &wave_lab.wave4_data;
                break;
        }
        if(*waven >= CH_RESP) *waven = CH_I;
        else *waven = (ecg_channel)(*waven + 1);
        p_wave->clear_data();
        p_wave->clear_wave();
        
        button_update(ctrl_id,waven,&*wave_datan);
    }
    void button_update(int ctrl_id,ecg_channel *waven,int32_t **wave_datan)
    {
        c_button* button = (c_button*)get_wnd_ptr(ctrl_id);
        char *str;
        switch(*waven)
        {
            case CH_I:str = (char*)"I";*wave_datan = &ECG_Data.Lead_I; break;
            case CH_II:str = (char*)"II";*wave_datan = &ECG_Data.Lead_II; break;
            case CH_III:str = (char*)"III";*wave_datan = &ECG_Data.Lead_III; break;
            case CH_aVR:str = (char*)"aVR";*wave_datan = &ECG_Data.Lead_aVR; break;
            case CH_aVL:str = (char*)"aVL";*wave_datan = &ECG_Data.Lead_aVL; break;
            case CH_aVF:str = (char*)"aVF";*wave_datan = &ECG_Data.Lead_aVF; break;
            case CH_V:str = (char*)"V";*wave_datan = &ECG_Data.Lead_V; break;
            case CH_RESP:str = (char*)"RESP";*wave_datan = &ECG_Data.Resp; break;
        }
        button->set_font_color(GL_RGB(255,255,255));
        button->set_str(str);
        button->show_window();
    }
    void on_clicked_speed(int ctrl_id, int param)
    {
        channel_speed *waven;
        char *str;
        c_button* button = (c_button*)get_wnd_ptr(ctrl_id);
        switch(ctrl_id){
            case ID_BTSP_WAVE1:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE1);
                waven = &wave_speed_lab.wave1_sp;
                break;
            case ID_BTSP_WAVE2:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE2);
                waven = &wave_speed_lab.wave2_sp;
                break;
            case ID_BTSP_WAVE3:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE3);
                waven = &wave_speed_lab.wave3_sp;
                break;
            case ID_BTSP_WAVE4:
                p_wave = (c_wave_ctrl*)get_wnd_ptr(ID_WAVE4);
                waven = &wave_speed_lab.wave4_sp;
                break;
        }
        if(*waven >= CH_SP_3X) *waven = CH_SP_1X;
        else *waven = (channel_speed)(*waven + 1);
        p_wave->clear_wave();
        p_wave->set_wave_speed(*waven);
        switch(*waven)
        {
            case CH_SP_1X:str = (char*)"20ms"; break;
            case CH_SP_2X:str = (char*)"10ms"; break;
            case CH_SP_3X:str = (char*)"6ms"; break;
        }
        button->set_font_color(GL_RGB(255,255,255));
        button->set_str(str);
        button->show_window();
    }
    void on_click_bmp(int ctrl_id, int param)
    {
        char *str;
        ecg_calc_bmp_tag *btn = &o_button_lab.bmp_channel;
        c_button* button = (c_button*)get_wnd_ptr(ID_EBMP_SEL);
        
        if(*btn >= LEAD_III) *btn = LEAD_I;
        else *btn = (ecg_calc_bmp_tag)(*btn + 1);
        
        switch(o_button_lab.bmp_channel)
        {
            case LEAD_I:
                str = (char*)"I";
                ECG_CalcBMP_function(bmp_LEAD_I);
                break;
            case LEAD_II:
                str = (char*)"II";
                ECG_CalcBMP_function(bmp_LEAD_II);
                break;
            case LEAD_III:
                str = (char*)"III";
                ECG_CalcBMP_function(bmp_LEAD_III);
                break;
        }
        button->set_font_color(GL_RGB(255,255,255));
        button->set_str(str);
        button->show_window();
    }
public:
	c_wave_buffer m_wave_buffer1;
	c_wave_buffer m_wave_buffer2;
	c_wave_buffer m_wave_buffer3;
    c_wave_buffer m_wave_buffer4;
};

//////////////////////// layout UI ////////////////////////
//surface
static c_waveUI s_waveUI;
//wave
static c_wave_ctrl s_wave1;
static c_wave_ctrl s_wave2;
static c_wave_ctrl s_wave3;
static c_wave_ctrl s_wave4;
//button
static c_button s_button_wave1;
static c_button s_button_wave2;
static c_button s_button_wave3;
static c_button s_button_wave4;
//button_speed
static c_button s_btsp_wave1;
static c_button s_btsp_wave2;
static c_button s_btsp_wave3;
static c_button s_btsp_wave4;
//button_ecg_bmp
static c_button s_bt_ecg_bmp;
//tool
static WND_TREE s_myUI_children[] =
{
    //WAVE
	{&s_wave1, ID_WAVE1, 0, 0, 20, 600, 120, NULL},
	{&s_wave2, ID_WAVE2, 0, 0, 160, 600, 120, NULL},
	{&s_wave3, ID_WAVE3, 0, 0, 300, 600, 80, NULL},
    {&s_wave4, ID_WAVE4, 0, 0, 400, 600, 80, NULL},
    //button_select
    {&s_button_wave1, ID_BUTTON_WAVE1, "None", 0, 0, 120, 20, NULL},
    {&s_button_wave2, ID_BUTTON_WAVE2, "None", 0, 140, 120, 20, NULL},
    {&s_button_wave3, ID_BUTTON_WAVE3, "None", 0, 280, 120, 20, NULL},
    {&s_button_wave4, ID_BUTTON_WAVE4, "None", 0, 380, 120, 20, NULL},
    //button_speed
    {&s_btsp_wave1, ID_BTSP_WAVE1, "10ms", 130, 0, 120, 20, NULL},
    {&s_btsp_wave2, ID_BTSP_WAVE2, "10ms", 130, 140, 120, 20, NULL},
    {&s_btsp_wave3, ID_BTSP_WAVE3, "20ms", 130, 280, 120, 20, NULL},
    {&s_btsp_wave4, ID_BTSP_WAVE4, "20ms", 130, 380, 120, 20, NULL},
    //button_ecg_bmp
    {&s_bt_ecg_bmp, ID_EBMP_SEL, "III", 700, 0, 100, 20, NULL},
	{ NULL,0,0,0,0,0,0 }
};

extern const LATTICE_FONT_INFO ASCII_FONT_16;
extern const LATTICE_FONT_INFO ASCII_FONT_12;
extern const LATTICE_FONT_INFO Number_FONT_72;
void load_resource()
{
	c_theme::add_font(FONT_DEFAULT, &ASCII_FONT_12);
    c_theme::add_font(FONT_CUSTOM1, &ASCII_FONT_16);
    c_theme::add_font(FONT_CUSTOM2, &Number_FONT_72);
	//for button
	c_theme::add_color(COLOR_WND_FONT, GL_RGB(255, 255, 255));
	c_theme::add_color(COLOR_WND_NORMAL, GL_RGB(0, 0, 0));
	c_theme::add_color(COLOR_WND_PUSHED, GL_RGB(33, 42, 53));
	c_theme::add_color(COLOR_WND_FOCUS, GL_RGB(45, 170, 225));
	c_theme::add_color(COLOR_WND_BORDER, GL_RGB(46, 59, 73));
}

//////////////////////// start UI ////////////////////////
//static c_display* s_display;
static c_surface* s_surface;

void create_ui(int screen_width, int screen_height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op)
{
    load_resource();
    
    static c_surface_no_fb surface_no_fb(UI_WIDTH, UI_HEIGHT, color_bytes, gfx_op, Z_ORDER_LEVEL_0);
    static c_display display(NULL, screen_width, screen_height, &surface_no_fb);
    s_surface = &surface_no_fb;
    //s_display = &display;


	s_waveUI.set_surface(s_surface);
	s_waveUI.connect(NULL, ID_ROOT, 0, 0, 0, UI_WIDTH, UI_HEIGHT, s_myUI_children);
	s_waveUI.show_window();
    
	unsigned int wave_index = 0;
    
	while(1)
	{
        
        s_waveUI.m_wave_buffer1.write_wave_data(*wave_lab.wave1_data);
		s_waveUI.m_wave_buffer2.write_wave_data(*wave_lab.wave2_data);
        s_waveUI.m_wave_buffer3.write_wave_data(*wave_lab.wave3_data);
        s_waveUI.m_wave_buffer4.write_wave_data(*wave_lab.wave4_data);
        thread_sleep(5);
        s_waveUI.m_wave_buffer1.write_wave_data(*wave_lab.wave1_data);
		s_waveUI.m_wave_buffer2.write_wave_data(*wave_lab.wave2_data);
        s_waveUI.m_wave_buffer3.write_wave_data(*wave_lab.wave3_data);
        s_waveUI.m_wave_buffer4.write_wave_data(*wave_lab.wave4_data);
        thread_sleep(5);
        s_waveUI.m_wave_buffer1.write_wave_data(*wave_lab.wave1_data);
		s_waveUI.m_wave_buffer2.write_wave_data(*wave_lab.wave2_data);
        s_waveUI.m_wave_buffer3.write_wave_data(*wave_lab.wave3_data);
        s_waveUI.m_wave_buffer4.write_wave_data(*wave_lab.wave4_data);
        thread_sleep(5);
		s_waveUI.m_wave_buffer1.write_wave_data(*wave_lab.wave1_data);
		s_waveUI.m_wave_buffer2.write_wave_data(*wave_lab.wave2_data);
        s_waveUI.m_wave_buffer3.write_wave_data(*wave_lab.wave3_data);
        s_waveUI.m_wave_buffer4.write_wave_data(*wave_lab.wave4_data);
        thread_sleep(5);
		s_wave1.refresh_wave(wave_index);
		s_wave2.refresh_wave(wave_index);
		s_wave3.refresh_wave(wave_index);
        s_wave4.refresh_wave(wave_index);
		wave_index++;
	}
    
}

//////////////////////// interface for all platform ////////////////////////
extern "C" void startGUI(int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op)
{
	create_ui(width, height, color_bytes, gfx_op);
}

extern "C" void GUI_Touch_update(int x, int y,uint8_t state)
{
	state ? s_waveUI.on_touch(x, y, TOUCH_DOWN) : s_waveUI.on_touch(x, y, TOUCH_UP);
}

extern "C" void GUI_KEY_update(unsigned int key)
{
	s_waveUI.on_navigate(NAVIGATION_KEY(key));
}

extern "C" void GUI_Draw_BigNum(uint16_t x,uint16_t y,short num,uint32_t color,uint32_t bk)
{
    if(num != 0) 
    c_word::draw_value(s_surface,Z_ORDER_LEVEL_0,num,0,x,y,c_theme::get_font(FONT_CUSTOM2),color,bk);
    else 
    c_word::draw_string(s_surface,Z_ORDER_LEVEL_0,"-?-",x,y,c_theme::get_font(FONT_CUSTOM2),color,bk);
}

extern "C" void GUI_Show_SysValue(void)
{
    char str[50];
    sprintf(str,"Bat:%d%%(%.2fv)  CoreTemp:%.2fC  CPU:%d%%",SystemState.PWR_BAT,
                                                            SystemState.battery_vot,
                                                            SystemState.core_temp,
                                                            SystemState.CPU_usage);
    c_word::draw_string(s_surface,Z_ORDER_LEVEL_0,str,260,0,c_theme::get_font(FONT_DEFAULT),
                        GL_RGB(0xFF,0xFF,0xFF),GL_ARGB(0xFF,33,33,33));
}
