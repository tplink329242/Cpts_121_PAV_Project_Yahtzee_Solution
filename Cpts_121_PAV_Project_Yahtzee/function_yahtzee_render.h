#include "function_yahtzee.h"
#include "function_yathzee_sdl.h"


//global var	
extern char game_yahtzee_array_text[1000][1000];


//init sdl window
SDL_Window* fnc_sdl_create_window();

//create render
SDL_Renderer* fnc_sdl_create_render(SDL_Window* win, Uint32 sdl_current_render_flags);

//create texture from picture
SDL_Texture* fnc_sdl_create_pic_texture(SDL_Renderer* yahtzee_main_window_renderer, const char* location_pic);

//create text texture
SDL_Texture* fnc_sdl_create_text_texture(SDL_Renderer* yahtzee_main_window_renderer, TTF_Font* font, SDL_Color textColor, char msg_user[100]);

//main render thread
int fnc_sdl_render_main(void* yahtzee_shared_data);

//init game text array
void fnc_sdl_init_text_array();

//check if player hit the button
int fnc_check_mouse_click_event_checker(SDL_Rect rect_Play_button);