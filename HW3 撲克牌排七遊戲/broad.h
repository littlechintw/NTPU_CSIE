#include <bits/stdc++.h>
#include "cards.cpp"
using namespace std;

class board {
	private:
		int player_num,computer_num;
		cards game_card;
		int hand_card[4][13][2];
		/* player, status{0:hand 1:board 2:trash} */
		/* 0:黑桃 1:愛心 2:梅花 3:方塊 */
		int game[4][3];
		int turn;
		int game_status = 1;
		void show_game_board();
		void reset_printer(int);
		void put_card();
		void change_card_status(int,int,int);
		void show_step(int,int,int);
		int get_put_card_status(int,int);
		int score[4];
		void show_end();
		int computer_play(vector<int>);
	public:
		board();
		bool init_game();
		void show_hand_card(int input_player);
		void start();
		int get_player_num(){
			return player_num;
		};
};
