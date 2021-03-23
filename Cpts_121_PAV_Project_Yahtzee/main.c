/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 5                                            *

* Programming Assignment: The Game of Yahtzee               *

* Date: March 15, 2021                                                                           *

* Description: This program Write a program that play the game dice using sdl
*
* File Description: This profile include the main entertance.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA5.htm

*******************************************************************************************/

#include "function_yahtzee.h"
#include "function_yathzee_sdl.h"



int main(int argc, char* argv[])
{
	//seeds
	srand((unsigned)time(NULL));

	//define key arrays
	int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2];
	int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];
	int array_player_score_temp[14];
	int array_player_score_official[14][2];
	
	fnc_init_player_environment(array_dice, array_dice_index, array_player_score_temp, array_player_score_official);


	//init render thread num
	int num_thread_return_number = 0;


	SDL_Thread* thread_render = SDL_CreateThread(fnc_sdl_render_main, "Yahtzee Render Thread", NULL);

	
	
	
	return 0;
}
