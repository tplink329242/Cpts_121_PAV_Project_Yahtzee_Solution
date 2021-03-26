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
		
	//lock
	SDL_mutex* bufferLock = NULL;
	bufferLock = SDL_CreateMutex();

	//signal
	SDL_cond* canProduce = NULL;
	SDL_cond* canConsume = NULL;
	canProduce = SDL_CreateCond();
	canConsume = SDL_CreateCond();
	

	//create sdl thread
	SDL_Thread* thread_render = SDL_CreateThread(fnc_sdl_render_main, "Yahtzee Render Thread", &yahtzee_parameter);

	YAHTZEE_PhaseType yahtzee_phase = YAHTZEE_INIT;



	
	SDL_mutexP(bufferLock);
	boolean is_closed = yahtzee_parameter.yahtzee_num_close_requested;
	yahtzee_phase = YAHTZEE_GAME_MAIN_MENU;
	yahtzee_parameter.yahtzee_phase = yahtzee_phase;
	yahtzee_parameter.yahtzee_is_consumer_go = false;
	SDL_mutexV(bufferLock);

	
	while (!is_closed)
	{
		SDL_mutexP(bufferLock);
		is_closed = yahtzee_parameter.yahtzee_num_close_requested;
		yahtzee_phase = yahtzee_parameter.yahtzee_phase;
		SDL_mutexV(bufferLock);

		if (yahtzee_phase == YAHTZEE_IN_GAME)
		{
			SDL_mutexP(bufferLock);
			fnc_exec_game_one_round(yahtzee_parameter.array_dice, yahtzee_parameter.array_dice_index, yahtzee_parameter.array_player_score_temp);			
			yahtzee_parameter.yahtzee_is_consumer_go = true;
			SDL_mutexV(bufferLock);
			SDL_CondSignal(canConsume);
		

			
		}


		
		//SDL_Delay(1000 / 60);
	}
	return 0;
}
