#include <bits/stdc++.h>
using namespace std;

void setColor(int color);

class cards {
	private:
		bool card[4][13];
		int had_printed;
		bool print_card_group(int);
		void print_card_line(int,int,int);
		void print_card_space();
		void print_card_number(int,int,int);
		void print_card_suit(int,int);
		void print_card_setcolor(int,int);
		int rand_card[2];
		bool get_rand_card();
	public:
		cards();
		int get_had_printed(){
			return had_printed;
		};
		bool print_card(int,int);
		void reset_card();
};
