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
		YAHTZEE_MOUSE_CONTINUE_ROLLING,
		YAHTZEE_MOUSE_GAVE_OVER,

	}YAHTZEE_MouseClickFlag;

	typedef enum
	{
		YAHTZEE_GAME_OBJECT_TYPE_INIT,
		YAHTZEE_GAME_OBJECT_TYPE_DICE,
		YAHTZEE_GAME_OBJECT_TYPE_TEXT,
		YAHTZEE_GAME_OBJECT_TYPE_PICTURE
		
	}YAHTZEE_GameObjectType;

	typedef enum
	{
		YAHTZEE_GAME_OBJECT_NAME_INIT,
		YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_TITLE,
		YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_PLAY,
		YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES,
		YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES_PRINTED,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_TOTAL_SCORE,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_ONES,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_TWOS,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_THREES,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_FOURS,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_FIVES,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_SIXES,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_THREE_OF_A_KIND,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_FOUR_OF_A_KIND,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_SMALL_STRAIGHT,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_LARGE_STRAIGHT,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_CHANCE,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_FULL_HOUSE,
		YAHTZEE_GAME_OBJECT_NAME_SCORE_YAHTZEE,
		YAHTZEE_GAME_OBJECT_NAME_BUTTON_ROLL_DICE,

	}YAHTZEE_GameObjectName;


	
	
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
		boolean yahtzee_num_close_requested;

		//thread lock
		boolean yahtzee_is_consumer_go;
		boolean yahtzee_is_producer_go;

		SDL_cond* thd_canProduce;
		SDL_cond* thd_canConsume;
		SDL_mutex* thd_bufferLock;

		//4 score array
		int array_dice[6][2];  // the 6th use for store the dice times
		int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];
		int array_player_score_temp[14];
		int array_player_score_official[14][2];



		//game object struct
		YAHTZEE_PhaseType yahtzee_phase;


		//struct do not use
		YAHTZEE_MouseClickFlag mouse_flag;
		YAHTZEE_GameObjectList yahtzee_game_object_list;
		YAHTZEE_GameObjectList yahtzee_game_mouse_click_list;
		YAHTZEE_GameObjectList yahtzee_game_dice_list;

		YAHTZEE_GameObject yahtzee_array_game_object_list[GAME_YAHTZEE_VALUE_MAX_GAME_OBJECT_ELEMENTS];
		YAHTZEE_GameObject yahtzee_array_game_render_list[GAME_YAHTZEE_VALUE_MAX_GAME_OBJECT_ELEMENTS];
		YAHTZEE_GameObject yahtzee_array_game_dice_list[GAME_YAHTZEE_VALUE_MAX_DICE_NUM];
		
		
	}YAHTZEE_Parameter_Thread;

	

	//init sdl parameter
	void fnc_sdl_init_parameter(YAHTZEE_Parameter_Thread* yahtzee_parameter);

	//init sdl environment
	int fnc_sdl_init();

	


#ifdef __cplusplus
}
#endif
#endif
