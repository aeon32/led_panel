/************************************************************************
 * file:	YQNetCom.h
 * brief:	Header file of Network communication library in network part
 * author:	niu.zhimin
 * date:	2017-11-01
 ***********************************************************************/
#ifndef _YQNETCOM_H
#define _YQNETCOM_H
#ifdef _WIN32
#ifdef YQNETCOM_EXPORTS
#define LEDNETSDK_API extern "C" __declspec(dllexport)
#else
#define LEDNETSDK_API extern "C" __declspec(dllimport)
#endif
//#define _JAVA
#ifdef _JAVA
#define _CALL_STD __cdecl
#else
#define _CALL_STD __stdcall
#endif
#else
#define LEDNETSDK_API
#define BYTE unsigned char
#define _CALL_STD  
#endif


typedef  struct card
{
    char ip[20];           //\BF\D8\D6\C6\C6\F7\B5\D8ַ
    char barcode[17];       //\BF\D8\D6\C6\C6\F7\CC\F5\D0\CE\C2\EB
} card_unit;



typedef struct _CARD_SERVER
{
	char barcode[17];//\BF\D8\D6\C6\C6\F7\CC\F5\D0\CE
} server_card;


#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
LEDNETSDK_API int _CALL_STD init_sdk();

LEDNETSDK_API int _CALL_STD release_sdk();
#endif

LEDNETSDK_API int _CALL_STD search_card(BYTE* cards, int* card_count);

LEDNETSDK_API unsigned long _CALL_STD create_radio();
LEDNETSDK_API int _CALL_STD search_cardSend(unsigned long radio);
LEDNETSDK_API int _CALL_STD search_cardRecv(unsigned long radio,BYTE* cards, int* card_count);
LEDNETSDK_API void _CALL_STD destroy_radio(unsigned long radio);

// \BA\AF\CA\FD\A3\BA	set_screen_ip
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7ip
//			char* submark\A3\BA\CD\F8\B9\D8
//			char* gateway\A3\BA\D7\D3\CD\F8\D1\DA\C2\EB
//			char* dns_server: \D3\F2\C3\FB\B7\FE\CE\F1\C6\F7\B5\D8ַ
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7IP\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD set_screen_shadow_net_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark);

// \BA\AF\CA\FD\A3\BA	set_screen_wifi_ip
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7ip
//			char* submark\A3\BA\CD\F8\B9\D8
//			char* gateway\A3\BA\D7\D3\CD\F8\D1\DA\C2\EB
//			char* dns_server: \D3\F2\C3\FB\B7\FE\CE\F1\C6\F7\B5\D8ַ
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7IP\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

// \BA\AF\CA\FD\A3\BA	set_screen_auto_ip
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7\D7Զ\AF\BB\F1ȡIP\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_auto_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// \BA\AF\CA\FD\A3\BA	set_screen_auto_wifi_ip
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7\D7Զ\AF\BB\F1ȡIP\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_auto_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// \BA\AF\CA\FD\A3\BA	set_screen_mac
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			char* mac\A3\BA\BF\D8\D6\C6\C6\F7mac
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7MAC\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// \BA\AF\CA\FD\A3\BA	set_screen_wifi_mac
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			char* mac\A3\BA\BF\D8\D6\C6\C6\F7mac
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7MAC\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_wifi_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// \BA\AF\CA\FD\A3\BA	set_screen_server
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			int server_mode\A3\BAserver(1)\A3\BA\C6\D5ͨ\B7\FE\CE\F1\C6\F7ģʽ\A3\BBcloud(2) \A3\BA\D4\C6ƽ̨\B7\FE\CE\F1\C6\F7ģʽ\A3\BBoff(0)\A3\BA\B9رշ\FE\CE\F1\C6\F7ģʽ\A3\BB
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7MAC\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* server_ip, unsigned short port, int server_mode);

// \BA\AF\CA\FD\A3\BA	enable_screen_server
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			int server_mode\A3\BAserver(1)\A3\BA\C6\D5ͨ\B7\FE\CE\F1\C6\F7ģʽ\A3\BBcloud(2) \A3\BA\D4\C6ƽ̨\B7\FE\CE\F1\C6\F7ģʽ\A3\BBoff(0)\A3\BA\B9رշ\FE\CE\F1\C6\F7ģʽ\A3\BB
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7MAC\B5\D8ַ
LEDNETSDK_API int _CALL_STD enable_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int server_mode);

// \BA\AF\CA\FD\A3\BA	set_screen_install_address
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* install_address\A3\BA\BF\D8\D6\C6\C6\F7\B0\B2װ\B5\D8ַ
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7IP\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_screen_install_address(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* install_address);

LEDNETSDK_API int _CALL_STD set_web_user_id(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* user_id);

LEDNETSDK_API int _CALL_STD send_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size);

LEDNETSDK_API void _CALL_STD query_rate(unsigned long playlist, long long * total,long long * cur,int* rate,int* remainsec,int* taskcount,int* completecount);

LEDNETSDK_API void _CALL_STD cancel_send_program(unsigned long playlist);

LEDNETSDK_API void _CALL_STD add_video_md5(unsigned long playlist, _TEXT_CHAR* md5, _TEXT_CHAR* file_path);

LEDNETSDK_API int _CALL_STD clear_material(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

LEDNETSDK_API int _CALL_STD clear_all_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

#pragma region insert list
LEDNETSDK_API void _CALL_STD add_insert_list(unsigned long playlist, int insert_list_count, int insert_list_duration);
#pragma endregion insert list

#pragma region program
LEDNETSDK_API unsigned long _CALL_STD create_playlist(int w, int h, int device_type);

LEDNETSDK_API void _CALL_STD delete_playlist(unsigned long playlist);

LEDNETSDK_API void _CALL_STD delete_dynamic(unsigned long dynamic_area);

LEDNETSDK_API unsigned long _CALL_STD create_program(_TEXT_CHAR* name);

LEDNETSDK_API unsigned long _CALL_STD create_video();

LEDNETSDK_API unsigned long _CALL_STD create_pic();

LEDNETSDK_API unsigned long _CALL_STD create_text();

LEDNETSDK_API unsigned long _CALL_STD create_colortext();

LEDNETSDK_API unsigned long _CALL_STD create_time();

LEDNETSDK_API unsigned long _CALL_STD create_calendar();

LEDNETSDK_API unsigned long _CALL_STD create_sensor();

LEDNETSDK_API unsigned long _CALL_STD create_db();

LEDNETSDK_API unsigned long _CALL_STD create_audio();

LEDNETSDK_API unsigned long _CALL_STD create_broder();

LEDNETSDK_API unsigned long _CALL_STD create_dynamic();

LEDNETSDK_API int _CALL_STD add_video(unsigned long program, unsigned long video_area, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, _TEXT_CHAR* clone_str);

LEDNETSDK_API int _CALL_STD add_pic(unsigned long program, unsigned long pic_area, int x, int y, int w, int h, int transparency);

LEDNETSDK_API int _CALL_STD add_broder(unsigned long program, unsigned long broder_area, int x, int y, int w, int h, int transparency);

// \BA\AF\CA\FD\A3\BA	add_dynamic
// \B7\B5\BB\D8ֵ\A3\BA	
// \B2\CE\CA\FD\A3\BA	
//			IntPtr tree\A3\BA\B6\AF̬\C7\F8\BD\DAĿ\BDڵ\E3\BE\E4\B1\FA
//			IntPtr area_tree\A3\BA\B6\AF̬\C7\F8\C7\F8\D3\F2\BDڵ\E3\BE\E4\B1\FA
//			int x/y/w/h:\B6\AF̬\C7\F8\C7\F8\D3\F2\D7\F8\B1\EA\BAͿ\ED\B8\DF
//			int relative_program:\B9\D8\C1\AA\B5Ľ\DAĿ\A3\AC\BC\B4\CB\F9Ҫ\B9\D8\C1\AA\B5Ľ\DAĿ\D0\F2\BA\C5(\BD\DAĿ\C1б\ED\D6е\C4 order \D7ֶ\CE("0","1",...))
//		int run_mode:\B6\AF̬\C7\F8\D4\CB\D0з\BDʽ\A3\AC0ȫ\BEֲ\A5\B7Ŷ\AF̬\C7\F8/1ȫ\BEֶ\AF̬\C7\F8\BD\DAĿ/2ȫ\BEֶ\AF̬\C7\F8\BD\DAĿ/3\B0󶨲\A5\B7Ŷ\AF̬\C7\F8\A3\AC\B9\D8\C1\AA\BD\DAĿ\BF\AAʼ\B2\A5\B7\C5ʱ\B2\A5\B7Ŷ\AF̬\C7\F8\A3\ACֱ\B5\BD\B9\D8\C1\AA\BD\DAĿ\B2\A5\B7\C5\CD\EA\B1\CF/4\B0󶨲\A5\B7Ŷ\AF̬\C7\F8\A3\AC\B9\D8\C1\AA\BD\DAĿ\BF\AAʼ\B2\A5\B7\C5ʱ\B2\A5\B7Ŷ\AF̬\C7\F8\A3\AC\CF\D4ʾ\CD\EAһ\B1\E9\BA\F3\B1\BE\C2ֲ\BB\D4\D9\CF\D4ʾ/5\B0󶨲\A5\B7Ŷ\AF̬\C7\F8\A3\AC\B9\D8\C1\AA\BD\DAĿ\BF\AAʼ\B2\A5\B7\C5ʱ\B2\A5\B7Ŷ\AF̬\C7\F8\A3\AC\CF\D4ʾ\CD\EAһ\B1\E9\BA\F3\BE\B2ֹ\CF\D4ʾ\B8ö\AF̬\C7\F8\B5\C4\D7\EE\BA\F3һ\B8\F6unit/6\B0󶨲\A5\B7Ŷ\AF̬\C7\F8\A3\AC\B9\D8\C1\AA\BD\DAĿ\B2\A5\B7\C5\CD\EA\BA󲥷Ŷ\AF̬\C7\F8
//			update_frequency\A3\BA\B7ſ\D5""\BC\B4\BF\C9 
//			transparency:͸\C3\F7\B6\C8
// ˵\C3\F7\A3\BA	\CC\ED\BCӶ\AF̬\C7\F8
LEDNETSDK_API int _CALL_STD add_dynamic(unsigned long program, unsigned long dynamic_area, int dynamic_id, int x, int y, int w, int h, int relative_program, int run_mode, _TEXT_CHAR* update_frequency, int transparency);


LEDNETSDK_API int _CALL_STD add_colorful_subtitle(unsigned long program, unsigned long colorful_subtitle_area, int x, int y, int w, int h);

LEDNETSDK_API int _CALL_STD add_db(unsigned long program, unsigned long db_area, int x, int y, int w, int h, int transparency);

LEDNETSDK_API int _CALL_STD add_text(unsigned long program, unsigned long text_area, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);

LEDNETSDK_API int _CALL_STD add_clock(unsigned long program, int x, int y, int w, int h, int transparency, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* hour_color, _TEXT_CHAR* minute_color, _TEXT_CHAR* second_color, _TEXT_CHAR* bg_image);

LEDNETSDK_API int _CALL_STD add_count(unsigned long program, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* target_date, _TEXT_CHAR* target_time, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int content_x, int content_y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* add_enable);

LEDNETSDK_API int _CALL_STD add_time(unsigned long program, unsigned long time_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te);

LEDNETSDK_API int _CALL_STD add_calendar(unsigned long program, unsigned long calendar_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te);

LEDNETSDK_API int _CALL_STD add_sensor(unsigned long program, int x, int y, int w, int h, int transparency, 
	_TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_color, _TEXT_CHAR* thresh_fontcolor, _TEXT_CHAR* bg_color, 
	_TEXT_CHAR* content_sensor, int content_x, int content_y, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int update_time);

LEDNETSDK_API int _CALL_STD add_animation(unsigned long program, int x, int y, int w, int h, int transparency, int display_effects, int display_density, int display_size, _TEXT_CHAR* direction, int display_speed, _TEXT_CHAR* animation_color, int taper);

LEDNETSDK_API int _CALL_STD add_audio(unsigned long program, unsigned long audio_area);

LEDNETSDK_API int _CALL_STD add_video_unit(unsigned long video_area, int volume, int scale_mode, int source, int play_time, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD add_broder_unit(unsigned long broder_area, int duration, int broder_w, int texture_w, int stunt_type, int stunt_speed, int flicker_grade, _TEXT_CHAR* src_path, _TEXT_CHAR* flicker_path);

LEDNETSDK_API int _CALL_STD add_pic_unit(unsigned long pic_area, int stay_time, int display_effects, int display_speed, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD add_text_unit_img(unsigned long text_area, int stay_time, int display_speed, int last_move_width, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD add_text_unit_text(unsigned long text_area, int stay_time, int display_speed, _TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_alignment, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

LEDNETSDK_API int _CALL_STD add_colorful_hollowunit(unsigned long colorful_subtitle_area, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* hollow_file);

LEDNETSDK_API int _CALL_STD add_colorful_fontunit(unsigned long colorful_subtitle_area, _TEXT_CHAR* file, int display_effects, int display_speed, int stay_time, int wave_effects, int wave_count, int wave_speed, int wave_amplitude);

LEDNETSDK_API int _CALL_STD add_time_unit(unsigned long time_area, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes);

LEDNETSDK_API int _CALL_STD add_calendar_unit(unsigned long calendar_area, _TEXT_CHAR* mode, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* text_content);

LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, _TEXT_CHAR* db_type, _TEXT_CHAR* db_ip,  unsigned short db_port,  _TEXT_CHAR* user_name,  _TEXT_CHAR* user_pwd,  _TEXT_CHAR* db_name, int update_time, int stay_time, int display_effects, int display_speed,  _TEXT_CHAR* bg_odd_color,  _TEXT_CHAR* bg_even_color, _TEXT_CHAR* text_odd_color, _TEXT_CHAR* text_even_color,  _TEXT_CHAR* font_name, int font_size, int font_bold, int font_italic, int font_underline, int font_strikeout, int font_noAntialias, _TEXT_CHAR* align_h_type, _TEXT_CHAR* align_v_type, _TEXT_CHAR* auto_lf , _TEXT_CHAR* headtype, _TEXT_CHAR* row_to_column, int linear, int line_w, int paint_table, _TEXT_CHAR* line_color, int row_count, int column_count, int row_h, int column_w, _TEXT_CHAR* cmd_data, _TEXT_CHAR* cmd_fieldname , _TEXT_CHAR* bg_img);

LEDNETSDK_API int _CALL_STD add_audio_unit(unsigned long audio_area, int volume, _TEXT_CHAR* src_path);

// \BA\AF\CA\FD\A3\BA	add_dynamic_unit
// \B7\B5\BB\D8ֵ\A3\BA	
// \B2\CE\CA\FD\A3\BA	
//			dynamic_area\A3\BA\B6\AF̬\C7\F8\C7\F8\D3\F2\BDڵ\E3\BE\E4\B1\FA
//			int dynamic_type:\B6\AF̬\B5\A5Ԫ\C0\E0\D0\CD
//			int display_effects:\CCؼ\BC\C0\E0\D0\CD
//			int display_speed\A3\BA\CCؼ\BC\CBٶ\C8
//			int stay_time:\CCؼ\BCͣ\C1\F4ʱ\BC\E4
//			file_path:Ԫ\CB\D8·\BE\B6\A3\BA\CEı\BE\C0\E0\B5\C4֧\B3\D6txt\B8\F1ʽ
//			gif_flag:0\B7\C7GIF\A3\BB1GIF\C0\E0\D0ͣ\A8\D4ݲ\BB֧\B3ֶ\AF̬\B2\A5\B7ţ\AC\D7\F7Ϊ\C6\D5ͨͼƬ\B2\A5\B7ţ\A9
//			bg_color\A3\BA\B1\B3\BE\B0\D1\D5ɫ
//			font_size\A3\BA\D7\D6\CC\E5\B4\F3С
//			font_color:\D7\D6\CC\E5\D1\D5ɫ
//			font_attributes\A3\BA\B0\FC\C0\A8\A1\B0bold\A1\B1\A1\A2\A1\B0italic\A1\B1\A1\A2\A1\B0normal\A1\B1\A3\AC\C6\E4\D6С\B0bold\A1\B1\BA͡\B0italic\A1\B1\BF\C9\D2\D4ͨ\B9\FD\A1\B0&\A1\B1\BD\F8\D0\D0\D7\E9\BA\CF
//			font_name\A3\BA\D7\D6\CC\E5
//			align_h:ˮƽ\B6\D4\C6뷽ʽ0\BE\D3\D7\F3/1\BE\D3\D3\D2/2\BE\D3\D6\D0
//			align_v:\B4\B9ֱ\B6\D4\C6뷽ʽ0\BE\D3\C9\CF/1\BE\D3\CF\C2/2\BE\D3\D6\D0
//\D2\D4\CF\C2\C8\FD\B8\F6Ϊ\CA\D3Ƶ\CA\F4\D0ԣ\AC\D4ݲ\BB֧\B3\D6\CA\D3Ƶ
//			volumn\A3\BA\D2\F4\C1\BF
//			scale_mode\A3\BA\CB\F5\B7\C5ģʽ\A3\AC\B4\B0\BFڱ\C8\C0\FD0/ԭʼ\B1\C8\C0\FD1
//			rolation_mode\A3\BA\D0\FDת\BDǶ\C8
LEDNETSDK_API int _CALL_STD add_dynamic_unit(unsigned long dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time,_TEXT_CHAR* file_path, int gif_flag, _TEXT_CHAR* bg_color, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* font_attributes, _TEXT_CHAR* align_h, _TEXT_CHAR* align_v, int volumn, int scale_mode, int rolation_mode);

LEDNETSDK_API int _CALL_STD add_program_in_playlist(unsigned long playlist, unsigned long program, int play_mode, int play_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, int play_week);

/*
\C9\E8\D6\C3\CAǷ\F1ͬ\B2\BD\B2\A5\B7\C5
*/
LEDNETSDK_API int _CALL_STD set_playlist_style(unsigned long playlist, int sync_display, int startH, int startM, int startS, int endH, int endM, int endS);
#pragma endregion program

#pragma region bulletin
LEDNETSDK_API int _CALL_STD play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long bulletin_list);

// \BA\AF\CA\FD\A3\BA	query_bulletin
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			_TEXT_CHAR* names\A3\BA\B5\B1ǰ\BF\D8\D6\C6\C6\F7\C9\CF\CB\F9\D3й\AB\B8\E6\C3\FB\B3ƣ\AC\B6\E0\B8\F6ʹ\D3÷ֺŸ\F4\BF\AA
// ˵\C3\F7\A3\BA	\B2\E9ѯ\B9\AB\B8\E6
LEDNETSDK_API int _CALL_STD query_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);

LEDNETSDK_API int _CALL_STD create_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);

// \BA\AF\CA\FD\A3\BA	delete_bulletin
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			_TEXT_CHAR* names\A3\BAָ\B6\A8ɾ\B3\FD\B5Ĺ\AB\B8\E6\C3\FB\B3ƣ\AC\B6\E0\B8\F6ʹ\D3÷ֺŸ\F4\BF\AA
// ˵\C3\F7\A3\BA	ɾ\B3\FDָ\B6\A8\B9\AB\B8\E6
LEDNETSDK_API int _CALL_STD delete_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);

LEDNETSDK_API int _CALL_STD stop_play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

// \BA\AF\CA\FD\A3\BA	add_bulletin
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
// ˵\C3\F7\A3\BA	\CC\ED\BCӹ\AB\B8沢\C7\D2\C9\FA\B4\E6xml\CEļ\FE\A3\AC\B2\A2\C7Ҽ\C7¼\B5\BDplay_list\C0\E0\D6У\BB\B7\BD\B1\E3\D4\DA\C9ϴ\AB\CEļ\FE\B5\C4ʱ\BA\F2ʹ\D3\C3\CEļ\FEmd5\BC\B0·\BE\B6
LEDNETSDK_API int _CALL_STD add_bulletin(_TEXT_CHAR* tmp_path, unsigned long playlist, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
#pragma endregion bulletin

LEDNETSDK_API int _CALL_STD check_screen_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pid, unsigned short device_type);

// \BA\AF\CA\FD\A3\BA	play_program
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			_TEXT_CHAR* path\A3\BA\B2\A5\B7Ž\DAĿ·\BE\B6
// ˵\C3\F7\A3\BA	\B2\A5\B7\C5ָ\B6\A8\BD\DAĿ
LEDNETSDK_API int _CALL_STD play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD stop_play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

LEDNETSDK_API int _CALL_STD lock_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* program_name);

LEDNETSDK_API int _CALL_STD get_screen_parameters(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, BYTE* cards);

LEDNETSDK_API int _CALL_STD reboot(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

LEDNETSDK_API int _CALL_STD restart_app(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

LEDNETSDK_API int _CALL_STD check_time(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

LEDNETSDK_API int _CALL_STD lock_screen(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int lock);

LEDNETSDK_API int _CALL_STD set_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int brightness);

LEDNETSDK_API int _CALL_STD set_screen_auto_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);

LEDNETSDK_API int _CALL_STD set_screen_cus_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count);

LEDNETSDK_API int _CALL_STD set_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int volumn);

LEDNETSDK_API int _CALL_STD set_screen_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int turnonoff_status);

// \BA\AF\CA\FD\A3\BA	screen_cus_turnonoff
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			struct CustomerTurnOnOffScreenData* turnonoff\A3\BA\B6\A8ʱ\BF\AA\B9ػ\FA\BDṹ\CC\E5
//			int data_count\A3\BA\B6\A8ʱ\BF\AA\B9ػ\FA\BDṹ\CC\E5\B8\F6\CA\FD\A3\AC\C8\E7\B9\FB\B4\AB\C8\EBΪ0ʱ\A3\AC\B1\EDʾȡ\CF\FB\B6\A8ʱ\BF\AA\B9ػ\FA\A3\BB\B7\F1\D4\F2\B1\EDʾ\C9\E8\D6ö\A8ʱ\BF\AA\B9ػ\FA
// ˵\C3\F7\A3\BA	\B6\A8ʱ\BF\AA\B9ػ\FA
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long turnonoff);

LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);

#pragma region customer turn onoff
LEDNETSDK_API unsigned long _CALL_STD create_turnonoff();

LEDNETSDK_API void _CALL_STD add_turnonoff(unsigned long turnonoff, int action, _TEXT_CHAR* time);

LEDNETSDK_API void _CALL_STD delete_turnonoff(unsigned long turnonoff);
#pragma endregion customer turn onoff

LEDNETSDK_API int _CALL_STD set_apn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);

LEDNETSDK_API int _CALL_STD set_screen_logo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, int screen_w, int screen_h, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD set_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int screenrotation);

LEDNETSDK_API int _CALL_STD set_fold_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);

LEDNETSDK_API int _CALL_STD set_screen_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);

LEDNETSDK_API int _CALL_STD set_screen_ip_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);

LEDNETSDK_API int _CALL_STD set_screen_led_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);

LEDNETSDK_API int _CALL_STD set_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int output_type);

LEDNETSDK_API int _CALL_STD set_screen_name(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_name);

LEDNETSDK_API int _CALL_STD set_screen_timezone(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);

LEDNETSDK_API int _CALL_STD get_screen_disk_list(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_cur_disk(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_disk_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);

LEDNETSDK_API int _CALL_STD set_screen_storage_media(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff);

LEDNETSDK_API int _CALL_STD get_screen_send_program_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);

LEDNETSDK_API int _CALL_STD get_firmware_version(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);

LEDNETSDK_API int _CALL_STD update_firmware(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path);
LEDNETSDK_API unsigned int _CALL_STD net_getcode(char* ip, unsigned short port);
LEDNETSDK_API unsigned long _CALL_STD net_login(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD set_xser_cmd(unsigned long post,int cmd,_TEXT_CHAR* content, int len, _TEXT_CHAR* recv_data, int* recv_cmd, int* recv_status, int* recv_len);
LEDNETSDK_API int _CALL_STD net_logout(unsigned long post);

LEDNETSDK_API int _CALL_STD get_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);

LEDNETSDK_API int _CALL_STD get_screen_mac(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* mac);

LEDNETSDK_API int _CALL_STD get_screen_capture(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, int captureW, int captureH);

LEDNETSDK_API int _CALL_STD download_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);

#pragma region WIFI
LEDNETSDK_API int _CALL_STD  get_ssid_list(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* values);

LEDNETSDK_API int _CALL_STD  set_ap_property(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, char* wifi_ip);

LEDNETSDK_API int _CALL_STD  connect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD  disconnect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid);

LEDNETSDK_API int _CALL_STD  query_wifi_status(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_status);

// \BA\AF\CA\FD\A3\BA	set_wifi_screen_mac
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* pid\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			_TEXT_CHAR* barcode\A3\BA\BF\D8\D6\C6\C6\F7Ψһ\C2\EB
//			char* mac\A3\BA\BF\D8\D6\C6\C6\F7mac
// ˵\C3\F7\A3\BA	\C9\E8\D6ÿ\D8\D6\C6\C6\F7WIFI MAC\B5\D8ַ
LEDNETSDK_API int _CALL_STD set_wifi_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac);
#pragma endregion WIFI

#pragma region Font
// \BA\AF\CA\FD\A3\BA	query_font
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* fontfile\A3\BA\D7ֿ\E2\CEļ\FE·\BE\B6
//			_TEXT_CHAR* fontname\A3\BA\D7ֿ\E2\CEļ\FE\C3\FB
// ˵\C3\F7\A3\BA	\B2\E9ѯ\D7ֿ\E2
LEDNETSDK_API int _CALL_STD query_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);

// \BA\AF\CA\FD\A3\BA	install_font
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			unsigned long font\A3\BA\D7ֿ\E2\CEļ\FE·\BE\B6\BA\CD\CEļ\FE\C3\FB
// ˵\C3\F7\A3\BA	\B0\B2װ\D7ֿ\E2
LEDNETSDK_API int _CALL_STD install_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font);

// \BA\AF\CA\FD\A3\BA	delete_font
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			_TEXT_CHAR* fontname\A3\BA\D7ֿ\E2\CEļ\FE\C3\FB
// ˵\C3\F7\A3\BA	ж\D4\D8\D7ֿ\E2
LEDNETSDK_API int _CALL_STD delete_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font);

#pragma region customer font
LEDNETSDK_API unsigned long _CALL_STD create_font();

LEDNETSDK_API void _CALL_STD add_font(unsigned long font, _TEXT_CHAR* system_font, _TEXT_CHAR* custom_font);

LEDNETSDK_API void _CALL_STD delete_add_font(unsigned long font, _TEXT_CHAR* font_name);

LEDNETSDK_API void _CALL_STD delete_create_font(unsigned long font);
#pragma endregion customer font
#pragma endregion Font

#pragma region sensor manage
LEDNETSDK_API unsigned long _CALL_STD create_manage_sensor();

LEDNETSDK_API void _CALL_STD add_manage_sensor(unsigned long sensor, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int relay_type, int relay_switch);

LEDNETSDK_API void _CALL_STD delete_add_sensor(unsigned long sensor, int sensor_index);

LEDNETSDK_API void _CALL_STD delete_create_sensor(unsigned long sensor);

LEDNETSDK_API int _CALL_STD get_sensor_bus(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus);

LEDNETSDK_API int _CALL_STD query_seeksensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD get_sensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, BYTE* sensors, int* sensors_count);

LEDNETSDK_API int _CALL_STD set_relay_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int setOrCancel, int update_time, unsigned long sensors);

LEDNETSDK_API int _CALL_STD set_screenonoff_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
#pragma endregion sensor

#pragma region dynamic
// \BA\AF\CA\FD\A3\BA	update_dynamic
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			unsigned long playlist\A3\BA\B6\AF̬\C7\F8\BD\DAĿ\BE\E4\B1\FA
//			int immediately_play\A3\BAָ\B6\A8һ\B8\F6\B9\D8\C1\AA\C1\CB\C6\D5ͨ\BD\DAĿ\B5Ķ\AF̬\C7\F8 ID\A3\A8\B1\D8\D0\EB\CA\C7 dynamics \B2\CE\CA\FD\D6д\E6\D4ڵ\C4 id\A3\A9
//			int conver\A3\BA\CAǷ񸲸\C7\C6\D5ͨ\BD\DAĿ\A3\AC\BC\B4\CAǷ\F1ֻ\B2\A5\B7Ŷ\AF̬\C7\F8\A3\AC"0"\A3\BA\B6\AF̬\C7\F8\BA\CD\C6\D5ͨ\BD\DAĿ\B9\B2\B4沥\B7ţ\AC"1"\A3\BAֹͣ\B2\A5\B7\C5\C6\D5ͨ\BD\DAĿ\A3\ACֻ\B2\A5\B7Ŷ\AF̬\C7\F8\BD\DAĿ
//			int onlyUpdate\A3\BA\CAǷ\F1ֻ\B8\FC\D0¶\AF̬\C7\F8\A3\BBֻ\B8\FC\D0¶\AF̬\C7\F8"0"\A3\BB\C7\E5\BF\D5ԭ\C0\B4\B5Ķ\AF̬\C7\F8\BA\F3\D4ٸ\FC\D0¶\AF̬\C7\F8"1"
// ˵\C3\F7\A3\BA	\B8\FC\D0¶\AF̬\C7\F8
LEDNETSDK_API int _CALL_STD update_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);

// \BA\AF\CA\FD\A3\BA	update_dynamic_small
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			unsigned long playlist\A3\BA\B6\AF̬\C7\F8\BD\DAĿ\BE\E4\B1\FA
//			int immediately_play\A3\BAָ\B6\A8һ\B8\F6\B9\D8\C1\AA\C1\CB\C6\D5ͨ\BD\DAĿ\B5Ķ\AF̬\C7\F8 ID\A3\A8\B1\D8\D0\EB\CA\C7 dynamics \B2\CE\CA\FD\D6д\E6\D4ڵ\C4 id\A3\A9
//			int conver\A3\BA\CAǷ񸲸\C7\C6\D5ͨ\BD\DAĿ\A3\AC\BC\B4\CAǷ\F1ֻ\B2\A5\B7Ŷ\AF̬\C7\F8\A3\AC"0"\A3\BA\B6\AF̬\C7\F8\BA\CD\C6\D5ͨ\BD\DAĿ\B9\B2\B4沥\B7ţ\AC"1"\A3\BAֹͣ\B2\A5\B7\C5\C6\D5ͨ\BD\DAĿ\A3\ACֻ\B2\A5\B7Ŷ\AF̬\C7\F8\BD\DAĿ
//			int onlyUpdate\A3\BA\CAǷ\F1ֻ\B8\FC\D0¶\AF̬\C7\F8\A3\BBֻ\B8\FC\D0¶\AF̬\C7\F8"0"\A3\BB\C7\E5\BF\D5ԭ\C0\B4\B5Ķ\AF̬\C7\F8\BA\F3\D4ٸ\FC\D0¶\AF̬\C7\F8"1"
// ˵\C3\F7\A3\BA	\B8\FC\D0¶\AF̬\C7\F8\C4\DA\C8\DD\C9ٵ\C4
LEDNETSDK_API int _CALL_STD update_dynamic_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);

// \BA\AF\CA\FD\A3\BA	update_dynamic_unit
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			unsigned long playlist\A3\BA\B6\AF̬\C7\F8\BD\DAĿ\BE\E4\B1\FA
// ˵\C3\F7\A3\BA	\B8\FC\D0¶\AF̬\C7\F8\CBز\C4
LEDNETSDK_API int _CALL_STD update_dynamic_unit(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);

// \BA\AF\CA\FD\A3\BA	update_dynamic_unit_small
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
//			unsigned long playlist\A3\BA\B6\AF̬\C7\F8\BD\DAĿ\BE\E4\B1\FA
// ˵\C3\F7\A3\BA	\B8\FC\D0¶\AF̬\C7\F8\CBزģ\AC\CBزĽ\CFС\B5\C4ʱ\BA\F2ʹ\D3\C3
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);

// \BA\AF\CA\FD\A3\BA	clear_dynamic
// \B7\B5\BB\D8ֵ\A3\BA	\B3ɹ\A6\B7\B5\BB\D80\A3\BBʧ\B0ܷ\B5\BBش\ED\CE\F3\BA\C5
// \B2\CE\CA\FD\A3\BA	
//			char* ip\A3\BA\BF\D8\D6\C6\C6\F7\B5\D8ַ
//			unsigned short port\A3\BA\B6˿\DA
//			_TEXT_CHAR* user_name\A3\BA\B5\C7¼\C3\FB
//			_TEXT_CHAR* user_pwd\A3\BA\B5\C7¼\C3\DC\C2\EB
// ˵\C3\F7\A3\BA	\C7\E5\BFն\AF̬\C7\F8
LEDNETSDK_API int _CALL_STD clear_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
#pragma endregion dynamic

#pragma region proxy
LEDNETSDK_API int _CALL_STD Get_Port_Barcode(_TEXT_CHAR* pid);

LEDNETSDK_API int _CALL_STD Get_Port_Pid(_TEXT_CHAR* pid);

LEDNETSDK_API  void _CALL_STD Get_CardList(BYTE* cards, int* card_count);

LEDNETSDK_API int _CALL_STD Start_Native_Server(int port);

LEDNETSDK_API void _CALL_STD Stop_Server();
#pragma endregion proxy
LEDNETSDK_API int _CALL_STD SearchCards(card_unit *cards);
LEDNETSDK_API int _CALL_STD get_screeninfo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type);
LEDNETSDK_API int _CALL_STD get_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int *volumn);
LEDNETSDK_API int _CALL_STD get_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, short* brightness);
LEDNETSDK_API int _CALL_STD get_screen_onoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff);
LEDNETSDK_API int _CALL_STD set_static_ip(_TEXT_CHAR* barcode,char* ip,char *submark,char *gateway);
LEDNETSDK_API int _CALL_STD set_auto_ip(_TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD get_netinfo(char *ip,_TEXT_CHAR* barcode,char* mask,char* gate,int *ipmode);
 #ifdef __cplusplus
}
#endif
#endif
