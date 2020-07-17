#include <bits/stdc++.h>
#include "cards.h"
using namespace std;

cards::cards(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			card[i][j] = false;
	had_printed = 0;
	rand_card[0] = -1;
	rand_card[1] = -1;
}

bool cards::get_rand_card(){
	srand(time(NULL));
	if(had_printed==52)
		return false;
	had_printed++;
	while(true){
		int rand_suit = rand()%4;
		int rand_number = rand()%13;
		if(!card[rand_suit][rand_number]){
			rand_card[0] = rand_suit;
			rand_card[1] = rand_number;
			card[rand_suit][rand_number] = true;
			return true;
		}
	}
}

int cards::get_rand_card_detail(int type){
	if(type==0) return rand_card[0];
	else if(type==1) return rand_card[1];
	else return -1;
}

void cards::reset(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			card[i][j] = false;
	had_printed = 0;
	rand_card[0] = -1;
	rand_card[1] = -1;
}

void cards::reg_card(int suit,int num,bool flag){
	card[suit][num] = flag;
	if(flag) had_printed++;
	else had_printed--;
}
