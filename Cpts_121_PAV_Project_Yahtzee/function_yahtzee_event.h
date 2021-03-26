#include "function_yahtzee.h"
#include "function_yathzee_sdl.h"

//main event thread
int fnc_sdl_event_main(void* yahtzee_shared_data);

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
