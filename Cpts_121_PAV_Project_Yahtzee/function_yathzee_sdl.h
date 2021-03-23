/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 4                                            *

* Programming Assignment: A Game of Chance "Craps"               *

* Date: March 10, 2021                                                                           *

* Description: This program Write a program that play the game dice using sdl
*
* File Description: This profile give the function prototype.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA5.htm

*******************************************************************************************/

#ifndef PAVSDLFUNCTIONS_H
#define PAVSDLFUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "function_yahtzee.h"

	typedef enum
	{
		YAHTZEE_INIT,
		YAHTZEE_GAME_MAIN_MENU,
		YAHTZEE_GAME_MAIN_MENU_RULES,
		YAHTZEE_IN_GAME,
		YAHTZEE_GAVE_OVER
		
	}YAHTZEE_PhaseType;

	//game mouse enum
	typedef enum
	{
		YAHTZEE_MOUSE_INIT,
		YAHTZEE_MOUSE_GAME_RULES_CLICK,
		YAHTZEE_MOUSE_GAME_MAIN_MENU_CLICK,
		YAHTZEE_MOUSE_GAME_DICE_1,
		YAHTZEE_MOUSE_GAME_DICE_2,
		YAHTZEE_MOUSE_GAME_DICE_3,
		YAHTZEE_MOUSE_GAME_DICE_4,
		YAHTZEE_MOUSE_GAME_DICE_5,
		YAHTZEE_MOUSE_SCORE_ONES,
		YAHTZEE_MOUSE_SCORE_TWOS,
		YAHTZEE_MOUSE_SCORE_THREES,
		YAHTZEE_MOUSE_SCORE_FOURS,
		YAHTZEE_MOUSE_SCORE_FIVES,
		YAHTZEE_MOUSE_SCORE_SIXES,
		YAHTZEE_MOUSE_SCORE_THREE_OF_A_KIND,
		YAHTZEE_MOUSE_SCORE_FOUR_OF_A_KIND,
		YAHTZEE_MOUSE_SCORE_SMALL_STRAIGHT,
		YAHTZEE_MOUSE_SCORE_LARGE_STRAIGHT,
		YAHTZEE_MOUSE_SCORE_CHANCE,
		YAHTZEE_MOUSE_SCORE_FULL_HOUSE,
		YAHTZEE_MOUSE_SCORE_YAHTZEE,
		YAHTZEE_MOUSE_GAVE_OVER

	}YAHTZEE_MouseClickFlag;

	typedef enum
	{
		YAHTZEE_GAME_OBJECT_TYPE_INIT,
		YAHTZEE_GAME_OBJECT_TYPE_DICE,
		YAHTZEE_GAME_OBJECT_TYPE_TEXT,
		YAHTZEE_GAME_OBJECT_TYPE_PICTURE
		
	}YAHTZEE_GameObjectType;
	
	typedef struct
	{
		YAHTZEE_GameObjectType type_object;
		int num_information;
		int num_object;
		SDL_Texture* tex_object;
		SDL_Rect rect_object;
		boolean is_selected;
		
	}YAHTZEE_GameObject;

	typedef struct YAHTZEE_GameObjectList
	{
		struct YAHTZEE_GameObjectList* prior;
		YAHTZEE_GameObject* object_game;
		struct YAHTZEE_GameObjectList* next;
		
	}YAHTZEE_GameObjectList;

	typedef struct
	{
		//close flag
		boolean* craps_num_close_requested;

		//4 score array
		int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2];
		int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];
		int array_player_score_temp[14];
		int array_player_score_official[14][2];

		//game object struct
		YAHTZEE_PhaseType yahtzee_phase;
		YAHTZEE_MouseClickFlag mouse_flag;
		YAHTZEE_GameObjectList yahtzee_game_object_list;
		YAHTZEE_GameObjectList yahtzee_game_mouse_click_list;
		YAHTZEE_GameObjectList yahtzee_game_dice_list;
		
	}YAHTZEE_Parameter_Thread;



	
		
	//sdl event receiver
	SDL_Event fnc_sdl_event_receiver();

	//sdl event handler
	int fnc_sdl_event_handler(SDL_Event yahtzee_event, YAHTZEE_GameObjectList mouse_click_list);

	//get mouse signal
	YAHTZEE_MouseClickFlag fnc_sdl_mouse_event_handler(YAHTZEE_GameObjectList* mouse_click_list);

	//switch the select flag
	int fnc_sdl_event_switcher(int sdl_event_flag, 
		int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], 
		int* val_i_player_selected,
		YAHTZEE_PhaseType* game_phase);
	
	//switch the mouse select flag
	void fnc_sdl_click_event_switcher(YAHTZEE_MouseClickFlag mouse_flag,
		int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
		int* val_i_player_selected,
		YAHTZEE_PhaseType* game_phase);

	//switch the mouse select flag
	void fnc_update_dice_selected(YAHTZEE_MouseClickFlag mouse_flag,
		int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
		int* val_i_player_selected);

	//switch the rules select flag
	void fnc_update_rules_selected(int* val_i_player_selected,
		YAHTZEE_PhaseType* game_phase);

	//switch the main menu start select flag
	void fnc_update_main_menu_selected(int* val_i_player_selected,
		YAHTZEE_PhaseType* game_phase);

	//init sdl parameter
	void fnc_sdl_init_parameter(YAHTZEE_Parameter_Thread* yahtzee_parameter);

	//init sdl environment
	int fnc_sdl_init();

	//init sdl window
	SDL_Window* fnc_sdl_create_window();

	//create render
	SDL_Renderer* fnc_sdl_create_render(SDL_Window* win, Uint32 sdl_current_render_flags);

	//create texture from picture
	SDL_Texture* fnc_sdl_create_pic_texture(SDL_Renderer* yahtzee_main_window_renderer, const char* location_pic);

	//main render thread
	int fnc_sdl_render_main(void* yahtzee_shared_data);


#ifdef __cplusplus
}
#endif
#endif
