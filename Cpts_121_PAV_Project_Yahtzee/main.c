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

	//define core elements
	YAHTZEE_Parameter_Thread yahtzee_parameter;
	fnc_sdl_init_parameter(&yahtzee_parameter);
		
	//init render thread num
	int num_thread_return_number = 0;




	
	SDL_Thread* thread_render = SDL_CreateThread(fnc_sdl_render_main, "Yahtzee Render Thread", &yahtzee_parameter);

	
	
	
	return 0;
}
