#include "function_yathzee_sdl.h"



void fnc_sdl_init_parameter(YAHTZEE_Parameter_Thread* yahtzee_parameter)
{
	fnc_init_player_environment(yahtzee_parameter->array_dice, yahtzee_parameter->array_dice_index, yahtzee_parameter->array_player_score_temp, yahtzee_parameter->array_player_score_official);

	yahtzee_parameter->mouse_flag = 0;
	yahtzee_parameter->yahtzee_num_close_requested = false;
	yahtzee_parameter->yahtzee_phase = YAHTZEE_INIT;
	yahtzee_parameter->mouse_flag = YAHTZEE_MOUSE_INIT;

	yahtzee_parameter->yahtzee_is_producer_go = true;

	yahtzee_parameter->yahtzee_array_game_object_list[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_TITLE].num_information = YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_TITLE;
	yahtzee_parameter->yahtzee_array_game_object_list[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_PLAY].num_information = YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_PLAY;
	yahtzee_parameter->yahtzee_array_game_object_list[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES].num_information = YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES;

	yahtzee_parameter->thd_bufferLock= SDL_CreateMutex();
	yahtzee_parameter->thd_canConsume = SDL_CreateCond();
	yahtzee_parameter->thd_canProduce = SDL_CreateCond();

	yahtzee_parameter->num_game_score_selected = 0;
	//yahtzee_parameter->array_player_score_official[0][1] = 1;

}

int fnc_sdl_init()
{
	int res = 0;
	res = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
	if (res != 0)
	{
		printf_s("Error for init SDL: %s ", SDL_GetError());
		return 1;
	}
	if (TTF_Init() == -1)
	{
		return 1;
	}
	printf_s("init success!\n");
	return 0;
}
