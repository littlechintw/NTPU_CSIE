#include <bits/stdc++.h>
using namespace std;

class cards {
	private:
		bool card[4][13];
		int had_printed;
		int rand_card[2];
	public:
		cards();
		int get_had_printed(){
			return had_printed;
		};
		void reset();
		bool get_rand_card();
		int get_rand_card_detail(int);
		void reg_card(int,int,bool);
};
