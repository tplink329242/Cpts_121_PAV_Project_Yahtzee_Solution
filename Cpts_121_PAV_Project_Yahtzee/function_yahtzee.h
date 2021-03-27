/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 5                                            *

* Programming Assignment: A Game of Chance "Craps"               *

* Date: March 10, 2021                                                                           *

* Description: This program Write a program that play the game dice using sdl
*
* File Description: This profile give the function prototype.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA5.htm

*******************************************************************************************/

#ifndef PAVFUNCTIONS_H
#define PAVFUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

//def base marco
#define _CRT_SECURE_NO_WARNINGS
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//def game marco
#define GAME_YAHTZEE_TYPE_SCORE_ONES 1	
#define GAME_YAHTZEE_TYPE_SCORE_TWOS 2	
#define GAME_YAHTZEE_TYPE_SCORE_THREES 3		
#define GAME_YAHTZEE_TYPE_SCORE_FOURS 4
#define GAME_YAHTZEE_TYPE_SCORE_FIVES 5
#define GAME_YAHTZEE_TYPE_SCORE_SIXES 6
#define GAME_YAHTZEE_TYPE_SCORE_THREE_OF_A_KIND 7
#define GAME_YAHTZEE_TYPE_SCORE_FOUR_OF_A_KIND 8
#define GAME_YAHTZEE_TYPE_SCORE_SMALL_STRAIGHT 9
#define GAME_YAHTZEE_TYPE_SCORE_LARGE_STRAIGHT 10
#define GAME_YAHTZEE_TYPE_SCORE_CHANCE 11
#define GAME_YAHTZEE_TYPE_SCORE_FULL_HOUSE 12
#define GAME_YAHTZEE_TYPE_SCORE_YAHTZEE 13

#define GAME_YAHTZEE_VALUE_MAX_DICE_FACE 6
#define GAME_YAHTZEE_VALUE_MAX_DICE_NUM 5
#define GAME_YAHTZEE_VALUE_SCORE_YAHTZEE 50
#define GAME_YAHTZEE_VALUE_SCORE_SMALL_STRAIGHT 30
#define GAME_YAHTZEE_VALUE_SCORE_LARGE_STRAIGHT 40
#define GAME_YAHTZEE_VALUE_SCORE_FULL_HOUSE 25

#define GAME_YAHTZEE_VALUE_MAX_DIE_TRYING 3
#define GAME_YAHTZEE_VALUE_MAX_GAME_OBJECT_ELEMENTS 300

#define GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_WAIT_FOR 0	
#define GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_DICE 15
#define GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_RULES 16
#define GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_START_GAME 17
#define GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_CONTINUE_ROLLING 18

	
	
//std library	
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>
#include <stdbool.h>
#include <string.h>

//SDL Config
#include "include/SDL.h"
#include "include/SDL_timer.h"
#include "include/SDL_image.h"
#include "include/SDL_ttf.h"
#include "include/SDL_thread.h"

//include sdl_func
#include "function_yathzee_sdl.h"

#pragma comment(lib ,"lib/x64/SDL2.lib")
#pragma comment(lib ,"lib/x64/SDL2main.lib")
#pragma comment(lib ,"lib/x64/SDL2_image.lib")


	

/*************************************************************
* Function: roll_die(void)                                  *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function should randomly generate a     *
* value between 1 and 6, inclusively.                       *
* contains real numbers.                                    *
* Input parameters: void                                    *
* Returns: int                                              *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
	int roll_die(void);
	
	/*************************************************************
	 * Function: fnc_calc_score(int array_dice_index[6], int type_score)*
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int type_score);

	/*************************************************************
	 * Function: fnc_calc_score_ones(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_ones(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_twos(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_twos(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_twos(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_threes(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_threes(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_fours(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_fours(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_fives(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_fives(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_sixes(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);
	
	/*************************************************************
	 * Function: fnc_calc_score_sixes(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_three_of_a_kind(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_three_of_a_kind(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_four_of_a_kind(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_four_of_a_kind(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_small_straight(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_small_straight(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_large_straight(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);
	
	/*************************************************************
	 * Function: fnc_calc_score_large_straight(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_chance(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_chance(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_full_house(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/*************************************************************
	 * Function: fnc_calc_score_full_house(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_calc_score_yahtzee(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);

	/**************************************************************
	 * Function: fnc_calc_score_yahtzee(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_array_init(int array[], int size);

	//logic function start here:

	/**************************************************************
	 * Function: fnc_update_dices(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_update_dices(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2]);

	/**************************************************************
	 * Function: fnc_array_dices_to_index(void)                       *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_array_dices_to_index(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE]);
	
	/*************************************************************
	 * Function: fnc_freeze_array_dices(void)                    *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_freeze_array_dices(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_dice_selected[GAME_YAHTZEE_VALUE_MAX_DICE_NUM]);

	/*************************************************************
	 * Function: fnc_loaded_player_score(void)                    *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_loaded_player_score(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int array_dice_score_temp[14]);

	/*************************************************************
	 * Function: fnc_confirm_player_score(void)                    *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_confirm_player_score(int array_dice_score_temp[14], int array_dice_score_official[14][2], int player_selected);

	/*************************************************************
	 * Function: fnc_init_2d_array(void)                         *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_init_2d_array(int array_dice_score_temp[][2], int size);

	/*************************************************************
	 * Function: fnc_calc_sum_score(void)                         *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_calc_sum_score(int array_dice_score_official[14][2]);

	/*************************************************************
	 * Function: fnc_exec_main_game(void)                         *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_exec_game_one_round(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int array_player_score_temp[14]);

	/*************************************************************
	 * Function: fnc_exec_main_game(void)                         *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	int fnc_exec_round_game(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int array_player_score_temp[14], int array_player_score_official[14][2], int* val_i_player_selected);

	/*************************************************************
 * Function: fnc_exec_main_game(void)                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function should randomly generate a     *
 * value between 1 and 6, inclusively.                       *
 * contains real numbers.                                    *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
	int fnc_exec_main_game(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int array_player_score_temp[14], int array_player_score_official[14][2], int* val_i_player_selected);

	/*************************************************************
	 * Function: fnc_wait_event_signal()                         *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_wait_event_signal(int* val_i_player_selected);

	/*************************************************************
	 * Function: fnc_init_player_environment()                   *
	 * Date Created:                                             *
	 * Date Last Modified:                                       *
	 * Description: This function should randomly generate a     *
	 * value between 1 and 6, inclusively.                       *
	 * contains real numbers.                                    *
	 * Input parameters: void                                    *
	 * Returns: int                                              *
	 * Preconditions:                                            *
	 * Postconditions:                                           *
	 *************************************************************/
	void fnc_init_player_environment(int(*array_dice)[2], int* array_dice_index, int* array_player_score_temp, int(*array_player_score_official)[2]);

	//pickup pictures
	const char* sdl_pick_up_dice(int numbers);



	
#ifdef __cplusplus
}
#endif
#endif
