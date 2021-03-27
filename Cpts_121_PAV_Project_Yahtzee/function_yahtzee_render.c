#include "function_yahtzee_render.h"
#include "function_yahtzee_event.h"

char game_yahtzee_array_text[1000][1000];

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

SDL_Texture* fnc_sdl_create_text_texture(SDL_Renderer* yahtzee_main_window_renderer, TTF_Font* font, SDL_Color textColor, char msg_user[100])
{
	SDL_Surface* msg_input = TTF_RenderUTF8_Solid(font, msg_user, textColor);
	SDL_Texture* yahtzee_fonts = SDL_CreateTextureFromSurface(yahtzee_main_window_renderer, msg_input);
	SDL_FreeSurface(msg_input);
	return yahtzee_fonts;
}



int fnc_sdl_render_main(void* yahtzee_shared_data)
{
	YAHTZEE_Parameter_Thread* parameter_thread_data = yahtzee_shared_data;
	SDL_Event yahtzee_event;
	fnc_sdl_init_text_array();

	


	//mouse
	int mouse_state_x = 0, mouse_state_y = 0;

	
	SDL_LockMutex(parameter_thread_data->thd_bufferLock);
	//close flag
	boolean yahtzee_num_close_requested = parameter_thread_data->yahtzee_num_close_requested;
	SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);

	const Uint32 yahtzee_sdl_render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	const char* location_pic = "res/pic/mainmenu.jpg";

	fnc_sdl_init();

	//init main window
	SDL_Window* yahtzee_main_window = fnc_sdl_create_window();
	SDL_Renderer* yahtzee_main_window_renderer = fnc_sdl_create_render(yahtzee_main_window, yahtzee_sdl_render_flags);
	SDL_Texture* yahtzee_tex_background = fnc_sdl_create_pic_texture(yahtzee_main_window_renderer, location_pic);


	TTF_Font* font = TTF_OpenFont("res/data/calibri.ttf", 25);
	TTF_Font* font_medium = TTF_OpenFont("res/data/calibri.ttf", 50);
	TTF_Font* font_big = TTF_OpenFont("res/data/calibri.ttf", 80);
	SDL_Color textColor = { 0, 0, 255 };
	SDL_Color textColor_Fuchsia = { 255, 0, 255 };

	

	//menu elements
	SDL_Texture* tex_main_menu_title;
	SDL_Texture* tex_roll_Rules;
	SDL_Texture* tex_Play_button;
	SDL_Texture* tex_Rule_button;

	
	SDL_Rect rect_main_menu_title;
	SDL_Rect rect_roll_Rules;
	SDL_Rect rect_Play_button;
	SDL_Rect rect_Rule_button;

	tex_main_menu_title = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_medium, textColor, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_TITLE]);
	tex_Play_button = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_big, textColor, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_PLAY]);
	tex_Rule_button = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_big, textColor, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES]);
	tex_roll_Rules = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font, textColor, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES_PRINTED]);

	SDL_QueryTexture(tex_main_menu_title, NULL, NULL, &rect_main_menu_title.w, &rect_main_menu_title.h);
	SDL_QueryTexture(tex_roll_Rules, NULL, NULL, &rect_roll_Rules.w, &rect_roll_Rules.h);
	SDL_QueryTexture(tex_Play_button, NULL, NULL, &rect_Play_button.w, &rect_Play_button.h);
	SDL_QueryTexture(tex_Rule_button, NULL, NULL, &rect_Rule_button.w, &rect_Rule_button.h);


	rect_main_menu_title.x = 300;
	rect_main_menu_title.y = 100;

	rect_roll_Rules.x = 0;
	rect_roll_Rules.y = 0;

	rect_Play_button.x = 600;
	rect_Play_button.y = 400;

	rect_Rule_button.x = 600;
	rect_Rule_button.y = 600;


	//in game elements
	char c_user_score[10];
	
	SDL_Texture* tex_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM];
	SDL_Texture* tex_score_name[14];
	SDL_Texture* tex_score_num[14];
	SDL_Texture* tex_roll_again;
	
	
	SDL_Rect rect_dice;
	SDL_Rect rect_dice_big;
	SDL_Rect rect_dice_array[5];
	
	SDL_Rect rect_score_name;
	SDL_Rect rect_score_num;

	SDL_Rect rect_roll_again;

	
	while (!yahtzee_num_close_requested)
	{
		// clear the window
		SDL_RenderClear(yahtzee_main_window_renderer);

		//copy the main background
		SDL_RenderCopy(yahtzee_main_window_renderer, yahtzee_tex_background, NULL, NULL);
		

		
		SDL_LockMutex(parameter_thread_data->thd_bufferLock);
		yahtzee_num_close_requested = parameter_thread_data->yahtzee_num_close_requested;
		YAHTZEE_PhaseType yahtzee_phase = parameter_thread_data->yahtzee_phase;
		SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);

		
		while (SDL_PollEvent(&yahtzee_event))
		{
			if (yahtzee_event.type == SDL_QUIT)
			{
				//close flag
				SDL_LockMutex(parameter_thread_data->thd_bufferLock);
				parameter_thread_data->yahtzee_num_close_requested = true;
				SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
			}
			
		}
		SDL_LockMutex(parameter_thread_data->thd_bufferLock);
		//close flag
		
		SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
		
		switch (yahtzee_phase)
		{
		case YAHTZEE_GAME_MAIN_MENU:
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_main_menu_title, NULL, &rect_main_menu_title);
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_Play_button, NULL, &rect_Play_button);
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_Rule_button, NULL, &rect_Rule_button);



			if (yahtzee_event.type == SDL_MOUSEBUTTONUP)
			{
				yahtzee_event.type = SDL_FIRSTEVENT;
				if (yahtzee_event.button.button == SDL_BUTTON_LEFT)
				{
				    
					if (fnc_check_mouse_click_event_checker(rect_Play_button))
					{
						//enter a new session
						SDL_LockMutex(parameter_thread_data->thd_bufferLock);
						parameter_thread_data->yahtzee_phase = YAHTZEE_IN_GAME;
						parameter_thread_data->array_dice[5][0] = 3;
						SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
					}
					if (fnc_check_mouse_click_event_checker(rect_Rule_button))
					{
						//close flag
						SDL_LockMutex(parameter_thread_data->thd_bufferLock);
						parameter_thread_data->yahtzee_phase = YAHTZEE_GAME_MAIN_MENU_RULES;
						SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
						printf_s("Rules has been activated!\n");
					}
				}				
			}
			break;
		case YAHTZEE_GAME_MAIN_MENU_RULES:
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_main_menu_title, NULL, &rect_main_menu_title);
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_roll_Rules, NULL, &rect_roll_Rules);
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_Play_button, NULL, &rect_Play_button);
			SDL_RenderCopy(yahtzee_main_window_renderer, tex_Rule_button, NULL, &rect_Rule_button);

			if (yahtzee_event.type == SDL_MOUSEBUTTONUP)
			{
				yahtzee_event.type = SDL_FIRSTEVENT;
				if (yahtzee_event.button.button == SDL_BUTTON_LEFT)
				{
					if (fnc_check_mouse_click_event_checker(rect_Play_button))
					{
						//close flag
						SDL_LockMutex(parameter_thread_data->thd_bufferLock);
						parameter_thread_data->yahtzee_phase = YAHTZEE_IN_GAME;
						SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
					}
					if (fnc_check_mouse_click_event_checker(rect_Rule_button))
					{
						//close flag
						SDL_LockMutex(parameter_thread_data->thd_bufferLock);
						parameter_thread_data->yahtzee_phase = YAHTZEE_GAME_MAIN_MENU;
						SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
					}
				}
				
			}
			break;

		case YAHTZEE_IN_GAME:

			SDL_LockMutex(parameter_thread_data->thd_bufferLock);
			while (!parameter_thread_data->yahtzee_is_consumer_go)
			{
				SDL_CondWait(parameter_thread_data->thd_canConsume, parameter_thread_data->thd_bufferLock);

			}		
			SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
			
			rect_dice.x = 900;
			rect_dice.y = 50;
			rect_dice.w = 50;
			rect_dice.h = 50;

			rect_dice_big.x = 890;
			rect_dice_big.y = 40;
			rect_dice_big.w = 70;
			rect_dice_big.h = 70;


			SDL_LockMutex(parameter_thread_data->thd_bufferLock);
			//render dice
			for (int i = 0; i < 5; ++i)
			{
				rect_dice.y += 100;
				rect_dice_big.y += 90;
				tex_dice[i] = fnc_sdl_create_pic_texture(yahtzee_main_window_renderer, sdl_pick_up_dice(parameter_thread_data->array_dice[i][0]));

				rect_dice_array[i] = rect_dice;
				
				if (parameter_thread_data->array_dice[i][1] == true)
				{
					SDL_RenderCopy(yahtzee_main_window_renderer, tex_dice[i], NULL, &rect_dice_big);
					rect_dice_array[i] = rect_dice_big;
				}
				else SDL_RenderCopy(yahtzee_main_window_renderer, tex_dice[i], NULL, &rect_dice);
			}
			
			
			parameter_thread_data->yahtzee_is_producer_go = false;
			SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);


			rect_score_name.x = 50;
			rect_score_name.y = 10;

			
			//render score name
			for (int i = 5; i < 19; ++i)
			{
				tex_score_name[i - 5] = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_medium, textColor, game_yahtzee_array_text[i]);
				SDL_QueryTexture(tex_score_name[i - 5], NULL, NULL, &rect_score_name.w, &rect_score_name.h);
				rect_score_name.y += 50;
				SDL_RenderCopy(yahtzee_main_window_renderer, tex_score_name[i - 5], NULL, &rect_score_name);
			}


			rect_score_num.x = 500;
			rect_score_num.y = 10;

			
			//render score number
			for (int i = 0; i < 14; ++i)
			{
				tex_score_num[i] = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_medium, textColor, _itoa(parameter_thread_data->array_player_score_temp[i], c_user_score, 10));
				SDL_QueryTexture(tex_score_num[i], NULL, NULL, &rect_score_num.w, &rect_score_num.h);
				rect_score_num.y += 50;
				SDL_RenderCopy(yahtzee_main_window_renderer, tex_score_num[i], NULL, &rect_score_num);
			}

			//render roll again number


			
			SDL_LockMutex(parameter_thread_data->thd_bufferLock);
			if (parameter_thread_data->array_dice[5][0] > 0)
			{
				tex_roll_again = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_big, textColor_Fuchsia, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_BUTTON_ROLL_DICE]);
			}
			else
			{
				tex_roll_again = fnc_sdl_create_text_texture(yahtzee_main_window_renderer, font_big, textColor, game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_BUTTON_ROLL_DICE]);
			}
			SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);

			
			SDL_QueryTexture(tex_roll_again, NULL, NULL, &rect_roll_again.w, &rect_roll_again.h);
			
			rect_roll_again.x = 650;
			rect_roll_again.y = 650;

			SDL_RenderCopy(yahtzee_main_window_renderer, tex_roll_again, NULL, &rect_roll_again);


			
			
			if (yahtzee_event.type == SDL_MOUSEBUTTONUP)
			{
				yahtzee_event.type = SDL_FIRSTEVENT;
				//check dice
				for (int i = 0; i < 5; ++i)
				{
					if (fnc_check_mouse_click_event_checker(rect_dice_array[i]))
					{
						//close flag
						SDL_LockMutex(parameter_thread_data->thd_bufferLock);
						if (parameter_thread_data->array_dice[i][1] == true)
						{
							parameter_thread_data->array_dice[i][1] = false;
						}
						else parameter_thread_data->array_dice[i][1] = true;
						SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
					}
				}
				//check roll again button
				SDL_LockMutex(parameter_thread_data->thd_bufferLock);
				if (parameter_thread_data->array_dice[5][0] > 0)
				{
					if (fnc_check_mouse_click_event_checker(rect_roll_again))
					{
						parameter_thread_data->yahtzee_is_consumer_go = false;
						parameter_thread_data->yahtzee_is_producer_go = true;
						parameter_thread_data->array_dice[5][0]--;
						SDL_CondBroadcast(parameter_thread_data->thd_canProduce);
					}	
				}
				SDL_UnlockMutex(parameter_thread_data->thd_bufferLock);
			
			}
			break;

			
							
		default:;
		}

		
		//show the render
		SDL_RenderPresent(yahtzee_main_window_renderer);
		//Sleep(500);

		
		if (yahtzee_phase == YAHTZEE_IN_GAME)
		{
			//destroy dice tex
			for (int i = 0; i < 5; ++i)
			{
				SDL_DestroyTexture(tex_dice[i]);
			}

			//destroy score name
			for (int i = 5; i < 19; ++i)
			{
				SDL_DestroyTexture(tex_score_name[i - 5]);
			}

			//render score number
			for (int i = 0; i < 14; ++i)
			{
				SDL_DestroyTexture(tex_score_num[i]);
			}
			SDL_DestroyTexture(tex_roll_again);		
		}

		
		
		
		

		// wait 1/60th of a second
		SDL_Delay(1000 / 60);
	}
	return 0;
}

void fnc_sdl_init_text_array()
{
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_TITLE], "Hello Welcome to Yahtzee!");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_PLAY], "Play Now!");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES], "Rules");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_MAIN_MENU_RULES_PRINTED], "The objective of the game is to score points by rolling five dice to make certain combinations. The dice can be rolled up to three times in a turn to try to make various scoring combinations and dice must remain in the box. A game consists of thirteen rounds. After each round the player chooses which scoring category is to be used for that round. Once a category has been used in the game, it cannot be used again. The scoring categories have varying point values, some of which are fixed values and others for which the score depends on the value of the dice. A Yahtzee is five-of-a-kind and scores 50 points, the highest of any category. The winner is the player who scores the most points");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_TOTAL_SCORE], "Total Score:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_ONES], "Ones:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_TWOS], "Twos:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_THREES], "Threes:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_FOURS], "Fours:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_FIVES], "Fives:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_SIXES], "Sixes:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_THREE_OF_A_KIND], "Three of a kind:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_FOUR_OF_A_KIND], "Four of a kind:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_SMALL_STRAIGHT], "Small straight:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_LARGE_STRAIGHT], "Large straight:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_CHANCE], "Chance:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_FULL_HOUSE], "Full house:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_SCORE_YAHTZEE], "Yahtzee:");
	strcpy(game_yahtzee_array_text[YAHTZEE_GAME_OBJECT_NAME_BUTTON_ROLL_DICE], "Roll again!");
}


int fnc_check_mouse_click_event_checker(SDL_Rect rect_Play_button)
{
	int mouse_state_x;
	int mouse_state_y;
	SDL_GetMouseState(&mouse_state_x, &mouse_state_y);
	
	if ((mouse_state_x > rect_Play_button.x) && (mouse_state_x < (rect_Play_button.x + rect_Play_button.w)))
	{
		if ((mouse_state_y > rect_Play_button.y) && (mouse_state_y < (rect_Play_button.y + rect_Play_button.h)))
		{
			return 1;
		}
	}
	return 0;
}