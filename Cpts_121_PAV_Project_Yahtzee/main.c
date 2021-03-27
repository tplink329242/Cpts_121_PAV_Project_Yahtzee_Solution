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
#include "function_yahtzee_render.h"
#include "function_yathzee_sdl.h"
#include "function_yahtzee_event.h"


int main(int argc, char* argv[])
{
	//seeds
	srand((unsigned)time(NULL));

	//define core elements
	YAHTZEE_Parameter_Thread yahtzee_parameter;
	fnc_sdl_init_parameter(&yahtzee_parameter);
		
	

	//create sdl thread
	SDL_Thread* thread_render = SDL_CreateThread(fnc_sdl_render_main, "Yahtzee Render Thread", &yahtzee_parameter);

	YAHTZEE_PhaseType yahtzee_phase = YAHTZEE_INIT;



	
	SDL_LockMutex(yahtzee_parameter.thd_bufferLock);
	boolean is_closed = yahtzee_parameter.yahtzee_num_close_requested;
	boolean is_producer_go = yahtzee_parameter.yahtzee_is_producer_go;
	
	yahtzee_phase = YAHTZEE_GAME_MAIN_MENU;
	yahtzee_parameter.yahtzee_phase = yahtzee_phase;
	yahtzee_parameter.yahtzee_is_consumer_go = false;
	SDL_UnlockMutex(yahtzee_parameter.thd_bufferLock);

	
	while (!is_closed)
	{
		SDL_LockMutex(yahtzee_parameter.thd_bufferLock);
		is_closed = yahtzee_parameter.yahtzee_num_close_requested;
		yahtzee_phase = yahtzee_parameter.yahtzee_phase;
		SDL_UnlockMutex(yahtzee_parameter.thd_bufferLock);

		if (yahtzee_phase == YAHTZEE_GAME_MAIN_MENU)
		{
			fnc_init_player_environment(yahtzee_parameter.array_dice, yahtzee_parameter.array_dice_index, yahtzee_parameter.array_player_score_temp, yahtzee_parameter.array_player_score_official);
			SDL_Delay(500);
		}		

		if (yahtzee_phase == YAHTZEE_IN_GAME)
		{
			SDL_LockMutex(yahtzee_parameter.thd_bufferLock);
			fnc_exec_game_one_round(yahtzee_parameter.array_dice, yahtzee_parameter.array_dice_index, yahtzee_parameter.array_player_score_temp);
			yahtzee_parameter.yahtzee_is_consumer_go = true;
			yahtzee_parameter.yahtzee_is_producer_go = false;

			SDL_CondBroadcast(yahtzee_parameter.thd_canConsume);

			printf_s("The roll time has %d times. ", yahtzee_parameter.array_dice[5][0]);

			printf_s("The game score selected num is : %d \n", yahtzee_parameter.num_game_score_selected);

			if (yahtzee_parameter.num_game_score_selected >= 13)
			{
				yahtzee_parameter.yahtzee_phase = YAHTZEE_GAVE_OVER;
			}

			SDL_UnlockMutex(yahtzee_parameter.thd_bufferLock);

			SDL_Delay(100);
		}

		if (yahtzee_phase == YAHTZEE_GAVE_OVER)
		{
			SDL_LockMutex(yahtzee_parameter.thd_bufferLock);
			fnc_init_player_environment(yahtzee_parameter.array_dice, yahtzee_parameter.array_dice_index, yahtzee_parameter.array_player_score_temp, yahtzee_parameter.array_player_score_official);
			SDL_UnlockMutex(yahtzee_parameter.thd_bufferLock);
			SDL_Delay(500);
		}

		SDL_LockMutex(yahtzee_parameter.thd_bufferLock);
		while (!yahtzee_parameter.yahtzee_is_producer_go)
		{
			SDL_CondWait(yahtzee_parameter.thd_canProduce, yahtzee_parameter.thd_bufferLock);
		}
		SDL_UnlockMutex(yahtzee_parameter.thd_bufferLock);
		
		
		SDL_Delay(1000 / 60);
	}
	return 0;
}
