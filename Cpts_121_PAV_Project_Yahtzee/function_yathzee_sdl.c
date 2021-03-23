#include "function_yathzee_sdl.h"

SDL_Event fnc_sdl_event_receiver()
{
	SDL_Event yahtzee_event;
	while (SDL_PollEvent(&yahtzee_event))
	{
		return yahtzee_event;
	}
}

int fnc_sdl_event_handler(SDL_Event yahtzee_event, YAHTZEE_GameObjectList mouse_click_list)
{
	YAHTZEE_MouseClickFlag mouse_flag = YAHTZEE_MOUSE_INIT;
	switch (yahtzee_event.type)
	{
	case SDL_QUIT:
	{
		return -1;
	}
	case SDL_MOUSEBUTTONUP:
	{
		//mouse event function handler
		if (yahtzee_event.button.button == SDL_BUTTON_LEFT)
		{
			mouse_flag = fnc_sdl_mouse_event_handler(&mouse_click_list);			
			return mouse_flag;
		}		
	}
	default:
	{
		return mouse_flag;
	}
	}
}

YAHTZEE_MouseClickFlag fnc_sdl_mouse_event_handler(YAHTZEE_GameObjectList* mouse_click_list)
{
	int mouse_state_x = 0, mouse_state_y = 0;
	SDL_GetMouseState(&mouse_state_x, &mouse_state_y);
	
	do
	{
		if (mouse_click_list == NULL)
		{
			break;
		}
		if ((mouse_state_x > mouse_click_list->object_game->rect_object.x) && (mouse_state_x < (mouse_click_list->object_game->rect_object.x + mouse_click_list->object_game->rect_object.w)))
		{
			if ((mouse_state_y > mouse_click_list->object_game->rect_object.y) && (mouse_state_y < (mouse_click_list->object_game->rect_object.y + mouse_click_list->object_game->rect_object.h)))
			{
				if (mouse_click_list->object_game->is_selected == true)
				{
					mouse_click_list->object_game->is_selected = false;
				}
				else mouse_click_list->object_game->is_selected = true;				
				return mouse_click_list->object_game->num_information;
			}
		}
		mouse_click_list = mouse_click_list->next;
	}
	while (mouse_click_list == NULL);
	return YAHTZEE_MOUSE_INIT;
}

int fnc_sdl_event_switcher(int sdl_event_flag,
	int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
	int* val_i_player_selected,
	YAHTZEE_PhaseType* game_phase)
{	
	if (sdl_event_flag == -1)
	{
		return -1;
	}
	fnc_sdl_click_event_switcher(sdl_event_flag, array_dice, val_i_player_selected, game_phase);
	return 0;
}

//switch the variable
void fnc_sdl_click_event_switcher(YAHTZEE_MouseClickFlag mouse_flag,
	int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
	int* val_i_player_selected, 
	YAHTZEE_PhaseType* game_phase)
{
	switch (mouse_flag)
	{
	case YAHTZEE_MOUSE_GAME_RULES_CLICK:
		fnc_update_rules_selected(val_i_player_selected, game_phase);
		break;
	case YAHTZEE_MOUSE_GAME_MAIN_MENU_CLICK:
		//enter the game
		//game phase = in game
		//update render
		//logic process go
		//start game process
		fnc_update_main_menu_selected(val_i_player_selected, game_phase);
		break;
	case YAHTZEE_MOUSE_GAME_DICE_1:
	case YAHTZEE_MOUSE_GAME_DICE_2:
	case YAHTZEE_MOUSE_GAME_DICE_3:
	case YAHTZEE_MOUSE_GAME_DICE_4:
	case YAHTZEE_MOUSE_GAME_DICE_5:
		fnc_update_dice_selected(mouse_flag, array_dice, val_i_player_selected);
		break;
	case YAHTZEE_MOUSE_SCORE_ONES:
	case YAHTZEE_MOUSE_SCORE_TWOS:
	case YAHTZEE_MOUSE_SCORE_THREES:
	case YAHTZEE_MOUSE_SCORE_FOURS:
	case YAHTZEE_MOUSE_SCORE_FIVES:
	case YAHTZEE_MOUSE_SCORE_SIXES:
	case YAHTZEE_MOUSE_SCORE_THREE_OF_A_KIND:
	case YAHTZEE_MOUSE_SCORE_FOUR_OF_A_KIND:
	case YAHTZEE_MOUSE_SCORE_SMALL_STRAIGHT:
	case YAHTZEE_MOUSE_SCORE_LARGE_STRAIGHT:
	case YAHTZEE_MOUSE_SCORE_CHANCE:
	case YAHTZEE_MOUSE_SCORE_FULL_HOUSE:
	case YAHTZEE_MOUSE_SCORE_YAHTZEE:
		*val_i_player_selected = mouse_flag - 7;
		break;
	case YAHTZEE_MOUSE_GAVE_OVER:
		*val_i_player_selected = GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_START_GAME;
		break;
	default:;
	}
}

void fnc_update_dice_selected(YAHTZEE_MouseClickFlag mouse_flag,
	int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
	int* val_i_player_selected)
{
	int selected_dice_number = 0;
	selected_dice_number = mouse_flag - 3;
	*val_i_player_selected = GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_DICE;
	
	if (array_dice[selected_dice_number][1] == true)
	{
		array_dice[selected_dice_number][1] = false;
	}
	else array_dice[selected_dice_number][1] = true;	
}

void fnc_update_rules_selected(int* val_i_player_selected,
	YAHTZEE_PhaseType* game_phase)
{
	*game_phase = YAHTZEE_GAME_MAIN_MENU_RULES;
	*val_i_player_selected = GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_RULES;
	if (*game_phase == YAHTZEE_GAME_MAIN_MENU_RULES)
	{
		*game_phase = YAHTZEE_GAME_MAIN_MENU;
	}
	else *game_phase = YAHTZEE_GAME_MAIN_MENU_RULES;
}

void fnc_update_main_menu_selected(int* val_i_player_selected, YAHTZEE_PhaseType* game_phase)
{
	*game_phase = YAHTZEE_IN_GAME;
	*val_i_player_selected = GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_START_GAME;
}

void fnc_sdl_init_parameter(YAHTZEE_Parameter_Thread* yahtzee_parameter)
{
	fnc_init_player_environment(yahtzee_parameter->array_dice, yahtzee_parameter->array_dice_index, yahtzee_parameter->array_player_score_temp, yahtzee_parameter->array_player_score_official);

	yahtzee_parameter->mouse_flag = 0;
	yahtzee_parameter->yahtzee_num_close_requested = false;
	yahtzee_parameter->yahtzee_phase = YAHTZEE_INIT;
	yahtzee_parameter->mouse_flag = YAHTZEE_MOUSE_INIT;
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

SDL_Window* fnc_sdl_create_window()
{
	SDL_Window* win = SDL_CreateWindow("Cpts 121 PAV 'Yahtzee'",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT, 0);
	if (!win)
	{
		printf_s("Error creating SDL window: %s ", SDL_GetError());
		return NULL;
	}
	return win;
}

SDL_Renderer* fnc_sdl_create_render(SDL_Window* win, Uint32 sdl_current_render_flags)
{
	SDL_Renderer* render = SDL_CreateRenderer(win, -1, sdl_current_render_flags);
	if (!render)
	{
		printf_s("Error creating SDL render: %s ", SDL_GetError());
		return NULL;
	}
	return render;
}

SDL_Texture* fnc_sdl_create_pic_texture(SDL_Renderer* yahtzee_main_window_renderer, const char* location_pic)
{
	SDL_Surface* surface = IMG_Load(location_pic);
	if (surface == NULL)
	{
		printf_s("Error creating SDL surface: %s ", SDL_GetError());
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(yahtzee_main_window_renderer, surface);

	//free surface
	SDL_FreeSurface(surface);

	if (!tex)
	{
		printf_s("Error creating SDL texture: %s ", SDL_GetError());
	}
	return tex;
}

int fnc_sdl_render_main(void* yahtzee_shared_data)
{
	YAHTZEE_Parameter_Thread* parameter_thread_data = yahtzee_shared_data;
	
	//close flag
	boolean* yahtzee_num_close_requested = parameter_thread_data->yahtzee_num_close_requested;

	const Uint32 yahtzee_sdl_render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	const char* location_pic = "sss";
	
	fnc_sdl_init();	

	//init main window
	SDL_Window* yahtzee_main_window = fnc_sdl_create_window();
	SDL_Renderer* yahtzee_main_window_renderer = fnc_sdl_create_render(yahtzee_main_window, yahtzee_sdl_render_flags);
	SDL_Texture* yahtzee_tex_background = fnc_sdl_create_pic_texture(yahtzee_main_window_renderer, location_pic);


	
	while (!yahtzee_num_close_requested)
	{
		// clear the window
		SDL_RenderClear(yahtzee_main_window_renderer);

		//copy the main background
		SDL_RenderCopy(yahtzee_main_window_renderer, yahtzee_tex_background, NULL, NULL);

		//show the render
		SDL_RenderPresent(yahtzee_main_window_renderer);
		//Sleep(500);

		// wait 1/60th of a second
		SDL_Delay(1000 / 30);
	}
	return 0;
}
