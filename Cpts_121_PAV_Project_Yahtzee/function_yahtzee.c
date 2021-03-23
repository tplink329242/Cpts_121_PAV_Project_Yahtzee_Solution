#include "function_yahtzee.h"

int roll_die(void)
{	
	return rand() % 6 + 1;
}

int fnc_calc_score(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int type_score)
{
	switch (type_score)
	{
		case GAME_YAHTZEE_TYPE_SCORE_ONES:
			return fnc_calc_score_ones(array_dice_index);
		
		case GAME_YAHTZEE_TYPE_SCORE_TWOS:
			return fnc_calc_score_twos(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_THREES:
			return fnc_calc_score_threes(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_FOURS:
			return fnc_calc_score_fours(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_FIVES:
			return fnc_calc_score_fives(array_dice_index);
		
		case GAME_YAHTZEE_TYPE_SCORE_SIXES:
			return fnc_calc_score_sixes(array_dice_index);
				
		case GAME_YAHTZEE_TYPE_SCORE_THREE_OF_A_KIND:
			return fnc_calc_score_three_of_a_kind(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_FOUR_OF_A_KIND:
			return fnc_calc_score_four_of_a_kind(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_SMALL_STRAIGHT:
			return fnc_calc_score_small_straight(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_LARGE_STRAIGHT:
			return fnc_calc_score_large_straight(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_CHANCE:
			return fnc_calc_score_chance(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_FULL_HOUSE:
			return fnc_calc_score_full_house(array_dice_index);

		case GAME_YAHTZEE_TYPE_SCORE_YAHTZEE:
			return fnc_calc_score_yahtzee(array_dice_index);

		default:
			return -1;
	}
}

int fnc_calc_score_ones(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[0] * GAME_YAHTZEE_TYPE_SCORE_ONES;
}

int fnc_calc_score_twos(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[1] * GAME_YAHTZEE_TYPE_SCORE_TWOS;
}

int fnc_calc_score_threes(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[2] * GAME_YAHTZEE_TYPE_SCORE_THREES;
}

int fnc_calc_score_fours(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[3] * GAME_YAHTZEE_TYPE_SCORE_FOURS;
}

int fnc_calc_score_fives(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[4] * GAME_YAHTZEE_TYPE_SCORE_FIVES;
}

int fnc_calc_score_sixes(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	return array_dice_index[5] * GAME_YAHTZEE_TYPE_SCORE_SIXES;
}

int fnc_calc_score_three_of_a_kind(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int sum_score = 0;
	
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] >= 3)
		{
			sum_score = array_dice_index[0] * GAME_YAHTZEE_TYPE_SCORE_ONES +
				array_dice_index[1] * GAME_YAHTZEE_TYPE_SCORE_TWOS +
				array_dice_index[2] * GAME_YAHTZEE_TYPE_SCORE_THREES +
				array_dice_index[3] * GAME_YAHTZEE_TYPE_SCORE_FOURS +
				array_dice_index[4] * GAME_YAHTZEE_TYPE_SCORE_FIVES +
				array_dice_index[5] * GAME_YAHTZEE_TYPE_SCORE_SIXES;
			
			return sum_score;
		}
	}
	return 0;
}

int fnc_calc_score_four_of_a_kind(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int sum_score = 0;
	
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] >= 4)
		{
			sum_score = array_dice_index[0] * GAME_YAHTZEE_TYPE_SCORE_ONES +
				array_dice_index[1] * GAME_YAHTZEE_TYPE_SCORE_TWOS +
				array_dice_index[2] * GAME_YAHTZEE_TYPE_SCORE_THREES +
				array_dice_index[3] * GAME_YAHTZEE_TYPE_SCORE_FOURS +
				array_dice_index[4] * GAME_YAHTZEE_TYPE_SCORE_FIVES +
				array_dice_index[5] * GAME_YAHTZEE_TYPE_SCORE_SIXES;
			
			return sum_score;
		}
	}
	return 0;
}

int fnc_calc_score_small_straight(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int count_small_straight = 0;
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] != 0)
		{
			count_small_straight++;
		}
		else
		{
			count_small_straight = 0;
		}
		if (count_small_straight == 4)
		{
			return GAME_YAHTZEE_VALUE_SCORE_SMALL_STRAIGHT;
		}
	}
	return 0;
}

int fnc_calc_score_large_straight(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int count_small_straight = 0;
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] != 0)
		{
			count_small_straight++;
		}
		else
		{
			count_small_straight = 0;
		}
		if (count_small_straight == 5)
		{
			return GAME_YAHTZEE_VALUE_SCORE_LARGE_STRAIGHT;
		}
	}
	return 0;
}

int fnc_calc_score_chance(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int sum_score = 0;
	sum_score = array_dice_index[0] * GAME_YAHTZEE_TYPE_SCORE_ONES +
				array_dice_index[1] * GAME_YAHTZEE_TYPE_SCORE_TWOS +
				array_dice_index[2] * GAME_YAHTZEE_TYPE_SCORE_THREES +
				array_dice_index[3] * GAME_YAHTZEE_TYPE_SCORE_FOURS +
				array_dice_index[4] * GAME_YAHTZEE_TYPE_SCORE_FIVES +
				array_dice_index[5] * GAME_YAHTZEE_TYPE_SCORE_SIXES;
	return sum_score;
}

int fnc_calc_score_full_house(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	int count_full_house_small = 0,count_full_house_large = 0;
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] == 3)
		{
			count_full_house_large = 1;
		}
		if (array_dice_index[i] == 2)
		{
			count_full_house_small = 1;
		}
	}
	if (count_full_house_large == 1 && count_full_house_small == 1)
	{
		return GAME_YAHTZEE_VALUE_SCORE_FULL_HOUSE;
	}	
	return 0;
}

int fnc_calc_score_yahtzee(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
	{
		if (array_dice_index[i] == GAME_YAHTZEE_VALUE_MAX_DICE_NUM)
		{
			return GAME_YAHTZEE_VALUE_SCORE_YAHTZEE;
		}
	}
	return 0;
}

void fnc_array_init(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = 0;
	}
}

void fnc_update_dices(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2])
{
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_NUM; ++i)
	{
		if (array[i][1] != true)
		{
			array[i][0] = roll_die();
		}
	}
}

void fnc_array_dices_to_index(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE])
{
	fnc_array_init(array_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_NUM; ++i)
	{
		switch (array[i][0])
		{
		case 1:
			array_index[0]++;
			break;
		case 2:
			array_index[1]++;
			break;
		case 3:
			array_index[2]++;
			break;
		case 4:
			array_index[3]++;
			break;
		case 5:
			array_index[4]++;
			break;
		case 6:
			array_index[5]++;
			break;
		default:;
		}
	}
	
}

void fnc_freeze_array_dices(int array[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2], int array_dice_selected[GAME_YAHTZEE_VALUE_MAX_DICE_NUM])
{
	for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_NUM; ++i)
	{
		array[i][1] = array_dice_selected[i];
	}
}

void fnc_loaded_player_score(int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE], int array_dice_score_temp[14])
{
	for (int i = 1; i < 14; ++i)
	{
		array_dice_score_temp[i] = fnc_calc_score(array_dice_index, i);
	}
}

void fnc_confirm_player_score(int array_dice_score_temp[14], int array_dice_score_official[14][2], int player_selected)
{
	if (player_selected != 13)
	{
		array_dice_score_official[player_selected][0] = array_dice_score_temp[player_selected];
		array_dice_score_official[player_selected][1] = 1;
	}
	else if (player_selected != 0)
	{
		//special rules: If the player throws a Yahtzee and has already filled the Yahtzee box with a score of 50, they score a Yahtzee bonus
		//and get an extra 100 points. However, if they throw a Yahtzee and have filled the Yahtzee category with a score of 0, they do not get a Yahtzee bonus.
		if (array_dice_score_official[13][1] == 0)
		{
			array_dice_score_official[player_selected][0] = array_dice_score_temp[player_selected];
			array_dice_score_official[13][1] = 1;
		}
		else
		{
			if (array_dice_score_official[player_selected][0] >= 50)
			{
				array_dice_score_official[player_selected][0] += 100;
			}
			else if (array_dice_score_official[player_selected][0] == 0)
			{
				array_dice_score_official[player_selected][0] = 0;
			}
		}
	}
}

void fnc_init_2d_array(int array_dice_score_temp[][2], int size)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j= 0; j < size; ++j)
		{
			array_dice_score_temp[j][i] = 0;
		}
	}
}

void fnc_calc_sum_score(int array_dice_score_official[14][2])
{
	int calc_sum = 0;
	for (int i = 1; i < 14; ++i)
	{
		calc_sum += array_dice_score_official[i][0];
	}
	array_dice_score_official[0][0] = calc_sum;
}

int fnc_exec_game_one_round(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
	int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE],
	int array_player_score_temp[14],
	int array_player_score_official[14][2])
{	
	//start rolling
	fnc_update_dices(array_dice);

	//transform array to index
	fnc_array_dices_to_index(array_dice, array_dice_index);

	//calc player score
	fnc_loaded_player_score(array_dice_index, array_player_score_temp);

	return 0;
}

int fnc_exec_round_game(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
	int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE],
	int array_player_score_temp[14],
	int array_player_score_official[14][2],
	int *val_i_player_selected)
{
	//init array val
	//init array
	fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
	fnc_array_init(array_player_score_temp, 14);

	//init 2d array
	fnc_init_2d_array(array_dice, GAME_YAHTZEE_VALUE_MAX_DICE_NUM);

	//init var
	int val_i_die_trying = GAME_YAHTZEE_VALUE_MAX_DIE_TRYING;
		
	//game start
	while (val_i_die_trying > 0  && *val_i_player_selected == 0)
	{
		fnc_exec_game_one_round(array_dice, array_dice_index, array_player_score_temp, array_player_score_official);
		
		//check if score has been freeze and force to select
		//get score select
		//make correct choice

		//check if want to roll other dice
		//update dice select

		//exec program
		fnc_wait_event_signal(val_i_player_selected);
		
		//check conditions
		for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
		{
			if (array_dice_index[i] == 5 && val_i_die_trying == 1)
			{
				val_i_die_trying += 1;
			}
		}

		//do another round
		val_i_die_trying--;

		//clear data
		fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
		fnc_array_init(array_player_score_temp, 14);

		if (*val_i_player_selected < GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_DICE && *val_i_player_selected > 0)
		{
			//confirm player score
			fnc_confirm_player_score(array_player_score_temp, array_player_score_official, *val_i_player_selected);
			//calc sum
			fnc_calc_sum_score(array_player_score_official);

			*val_i_player_selected = GAME_YAHTZEE_VALUE_MOUSE_PLAYER_SELECT_WAIT_FOR;
			break;
		}
	}	
	return array_player_score_official[0][0];
}

int fnc_exec_main_game(int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2],
                       int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE],
                       int array_player_score_temp[14],
                       int array_player_score_official[14][2],
                       int* val_i_player_selected)
{
	int num_sum_top_score = 0;

	fnc_init_player_environment(array_dice, array_dice_index, array_player_score_temp, array_player_score_official);
	
	for (int i = 0; i < 14; ++i)
	{
		if (array_player_score_official[i][1] == 0)
		{
			fnc_exec_round_game(array_dice, array_dice_index, array_player_score_temp, array_player_score_official, val_i_player_selected);
		}
	}

	//game over phase
	for (int i = 1; i < 7; ++i)
	{
		num_sum_top_score += num_sum_top_score;
	}

	if (num_sum_top_score >= 63)
	{
		array_player_score_official[0][0] += 35;
	}
	
	return array_player_score_official[0][0];
}

void fnc_wait_event_signal(int* val_i_player_selected)
{
	while (*val_i_player_selected == 0)
	{
		SDL_Delay(1000 / 60);
	}
}

void fnc_init_player_environment(int(*array_dice)[2], int* array_dice_index, int* array_player_score_temp, int(*array_player_score_official)[2])
{
	//init array
	fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
	fnc_array_init(array_player_score_temp, 14);

	//init 2d array
	fnc_init_2d_array(array_dice, GAME_YAHTZEE_VALUE_MAX_DICE_NUM);
	fnc_init_2d_array(array_player_score_official, 14);
}
