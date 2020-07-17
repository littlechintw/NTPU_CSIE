#include <bits/stdc++.h>
#include "cards.cpp"
using namespace std;

class player {
	private:
		int cards[4][13];
		/* player, status{0:no 1:hand 2:done} */
		/* 0:黑桃 1:愛心 2:梅花 3:方塊 */
		int score = 0;
	public:
		player();
		void set_card(int suit,int number, int mode);
		int read_card(int suit,int number);
		int read_score(){
			return score;
		};
		void set_score(int num){
			score += num;
		};
		void reset();
		string save_str();
		bool operator>=(const player&);
};

class Save_game {
	private:
		vector<string> data;
	public:
		Save_game(){
		};
		Save_game(vector<string> d){
			for(int i=0;i<d.size();i++)
				data.push_back(d[i]); 
		};
		Save_game(string d){
			data.push_back(d);
		};
		Save_game operator+=(string);
		void save_it();
};

class board {
	private:
		cards game_card;
		int player_num;
		int computer_num;
		player a_player[4];
		player cover_card;
		int turn = 0;
		int game_status = 0;
		void next_status();
		void prepare_page();
		void game_page();
		void show_game_board();
		void end_page();
		int computer_play(vector<int>,int);
		void show_step(int,int,int);
		int take_one_card();
		int add_score(int,int);
		void save_game_as_file();
		int read_game_as_file();
	public:
		board();
		bool init();
		void start();
};
