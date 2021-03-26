#include "CppUnitTest.h"
#include "../Cpts_121_PAV_Project_Yahtzee/function_yahtzee.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PAVUnitTest
{
	TEST_CLASS(PAVUnitTest_score)
	{
	public:
		
		TEST_METHOD(Test_calc_score_1_6)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE] = { 0 };
			
			for (int i = 0; i < GAME_YAHTZEE_VALUE_MAX_DICE_FACE; ++i)
			{
				array_dice_index[i] = 5;
			}
			Assert::AreEqual(5 * 1, fnc_calc_score_ones(array_dice_index));
			Assert::AreEqual(5 * 2, fnc_calc_score_twos(array_dice_index));
			Assert::AreEqual(5 * 3, fnc_calc_score_threes(array_dice_index));
			Assert::AreEqual(5 * 4, fnc_calc_score_fours(array_dice_index));
			Assert::AreEqual(5 * 5, fnc_calc_score_fives(array_dice_index));
			Assert::AreEqual(5 * 6, fnc_calc_score_sixes(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_3_of_a_kind)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			array_dice_index[3] = 3;
			array_dice_index[4] = 2;
			
			Assert::AreEqual(22, fnc_calc_score_three_of_a_kind(array_dice_index));
			Assert::AreEqual(0, fnc_calc_score_four_of_a_kind(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_4_of_a_kind)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			array_dice_index[3] = 4;
			array_dice_index[4] = 1;

			Assert::AreEqual(21, fnc_calc_score_four_of_a_kind(array_dice_index));
			Assert::AreEqual(21, fnc_calc_score_three_of_a_kind(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_small_straight)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			//1234
			array_dice_index[0] = 1;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[5] = 1;

			Assert::AreEqual(30, fnc_calc_score_small_straight(array_dice_index));
			Assert::AreEqual(0, fnc_calc_score_large_straight(array_dice_index));

			//2345
			array_dice_index[0] = 0;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 2;
			array_dice_index[5] = 0;

			Assert::AreEqual(30, fnc_calc_score_small_straight(array_dice_index));
			Assert::AreEqual(0, fnc_calc_score_large_straight(array_dice_index));

			//3456
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 1;
			array_dice_index[5] = 1;
			array_dice_index[0] = 1;
			array_dice_index[1] = 0;

			Assert::AreEqual(30, fnc_calc_score_small_straight(array_dice_index));
			Assert::AreEqual(0, fnc_calc_score_large_straight(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_large_straight)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			//12345
			array_dice_index[0] = 1;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 1;
			array_dice_index[5] = 0;

			Assert::AreEqual(30, fnc_calc_score_small_straight(array_dice_index));
			Assert::AreEqual(40, fnc_calc_score_large_straight(array_dice_index));

			//23456
			array_dice_index[0] = 0;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 1;
			array_dice_index[5] = 1;

			Assert::AreEqual(30, fnc_calc_score_small_straight(array_dice_index));
			Assert::AreEqual(40, fnc_calc_score_large_straight(array_dice_index));			
		}
		
		TEST_METHOD(Test_calc_score_chance)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			//12345
			array_dice_index[0] = 1;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 1;
			array_dice_index[5] = 0;

			Assert::AreEqual(15, fnc_calc_score_chance(array_dice_index));

			//23456
			array_dice_index[0] = 0;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 1;
			array_dice_index[5] = 1;

			Assert::AreEqual(20, fnc_calc_score_chance(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_full_house)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			array_dice_index[0] = 0;
			array_dice_index[1] = 0;
			array_dice_index[2] = 0;
			array_dice_index[3] = 2;
			array_dice_index[4] = 3;
			array_dice_index[5] = 0;

			Assert::AreEqual(25, fnc_calc_score_full_house(array_dice_index));

			array_dice_index[0] = 2;
			array_dice_index[1] = 3;
			array_dice_index[2] = 0;
			array_dice_index[3] = 0;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			Assert::AreEqual(25, fnc_calc_score_full_house(array_dice_index));

			array_dice_index[0] = 2;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			Assert::AreEqual(0, fnc_calc_score_full_house(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_yahtzee)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);

			array_dice_index[0] = 5;
			array_dice_index[1] = 0;
			array_dice_index[2] = 0;
			array_dice_index[3] = 0;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			Assert::AreEqual(50, fnc_calc_score_yahtzee(array_dice_index));

			array_dice_index[0] = 0;
			array_dice_index[1] = 5;
			array_dice_index[2] = 0;
			array_dice_index[3] = 0;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			Assert::AreEqual(50, fnc_calc_score_yahtzee(array_dice_index));

			array_dice_index[0] = 2;
			array_dice_index[1] = 1;
			array_dice_index[2] = 1;
			array_dice_index[3] = 1;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			Assert::AreEqual(0, fnc_calc_score_full_house(array_dice_index));
		}

		TEST_METHOD(Test_calc_score_sum)
		{
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];
			int array_score[13];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
			fnc_array_init(array_score, 13);

			array_dice_index[0] = 5;
			array_dice_index[1] = 0;
			array_dice_index[2] = 0;
			array_dice_index[3] = 0;
			array_dice_index[4] = 0;
			array_dice_index[5] = 0;

			for (int i = 1; i < 14; ++i)
			{
				array_score[i - 1] = fnc_calc_score(array_dice_index, i);
			}

			Assert::AreEqual(5, array_score[GAME_YAHTZEE_TYPE_SCORE_ONES - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_TWOS - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_THREES - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_FOURS - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_FIVES - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_SIXES - 1]);
			Assert::AreEqual(5, array_score[GAME_YAHTZEE_TYPE_SCORE_THREE_OF_A_KIND - 1]);
			Assert::AreEqual(5, array_score[GAME_YAHTZEE_TYPE_SCORE_FOUR_OF_A_KIND - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_SMALL_STRAIGHT - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_LARGE_STRAIGHT - 1]);
			Assert::AreEqual(5, array_score[GAME_YAHTZEE_TYPE_SCORE_CHANCE - 1]);
			Assert::AreEqual(0, array_score[GAME_YAHTZEE_TYPE_SCORE_FULL_HOUSE - 1]);
			Assert::AreEqual(50, array_score[GAME_YAHTZEE_TYPE_SCORE_YAHTZEE - 1]);

			Logger::WriteMessage("score test complete!\n");
		}

		TEST_METHOD(Test_game_exec_one_round)
		{
			//define key arrays
			int array_dice[GAME_YAHTZEE_VALUE_MAX_DICE_NUM][2];
			int array_dice_index[GAME_YAHTZEE_VALUE_MAX_DICE_FACE];
			int array_player_score_temp[14];
			int array_player_score_official[14][2];

			fnc_array_init(array_dice_index, GAME_YAHTZEE_VALUE_MAX_DICE_FACE);
			fnc_array_init(array_player_score_temp, 14);

			//init 2d array
			fnc_init_2d_array(array_dice, GAME_YAHTZEE_VALUE_MAX_DICE_NUM);
			fnc_init_2d_array(array_player_score_official, 14);

			fnc_exec_game_one_round(array_dice, array_dice_index, array_player_score_temp, array_player_score_official);
		}
	};
}
