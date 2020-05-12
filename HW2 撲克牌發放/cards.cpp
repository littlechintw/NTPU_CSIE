#include <bits/stdc++.h>
#include <windows.h>
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

bool cards::print_card(int card_num,int group_num){
	while(card_num>0){
		bool flag;
		if(card_num/group_num)
			flag = print_card_group(group_num);
		else
			flag = print_card_group(card_num);
		if(!flag) return false;
		card_num -= group_num;
	}
	if(had_printed==52) return false;
	return true;
}

bool cards::print_card_group(int card_num){
	int print_card[card_num][2];
	int accept_card = 0;
	for(int i=0;i<card_num;i++){
		if(get_rand_card()){
			accept_card++;
			print_card[i][0] = rand_card[0] + 1;
			print_card[i][1] = rand_card[1] + 1;
		}
		else break;
	}
	if(accept_card){
		for(int line=1;line<=10;line++){
			for(int card=0;card<accept_card;card++)
				print_card_line(line,print_card[card][0],print_card[card][1]);
			printf("\n");
		}
		if(accept_card!=card_num){
			setColor(14);
			printf("Warning! There are not so many cards can give you!qq\n");
			setColor(7);
			return false;
		}
	}
	else{
		setColor(12);
		printf("Error! There are not so many cards can give you!qq\n");
		setColor(7);
		return false;
	}
	printf("\n");
	return true;
}

void cards::print_card_line(int line,int suit,int number){
	printf(" ");
	if(line==1)
		print_card_number(1, suit, number);
	if(line==2)
		print_card_space();
	if(line==3)
		print_card_space();
	if(line==4)
		print_card_suit(1, suit);
	if(line==5)
		print_card_suit(2, suit);
	if(line==6)
		print_card_suit(3, suit);
	if(line==7)
		print_card_suit(4, suit);
	if(line==8)
		print_card_space();
	if(line==9)
		print_card_space();
	if(line==10)
		print_card_number(2, suit, number);
}

void cards::print_card_number(int direction,int suit,int number){
	print_card_setcolor(1, suit);
	if(direction==1) printf(" ");
	else{
		for(int i=0;i<13;i++) printf(" ");
		if(number!=10) printf(" ");
	}

	if(number == 1) printf("A");
	else if(number == 11) printf("J");
	else if(number == 12) printf("Q");
	else if(number == 13) printf("K");
	else printf("%d",number);

	if(direction==1){
		for(int i=0;i<13;i++) printf(" ");
		if(number!=10) printf(" ");
	}
	else printf(" ");
	print_card_setcolor(2, suit);
}

void cards::print_card_space(){
	print_card_setcolor(1, 0);
	printf("                ");
	print_card_setcolor(2, 0);
}

void cards::print_card_suit(int line,int suit){
	print_card_setcolor(1, suit);
	if(suit==1){
		if(line==1)
			printf("       /\\       ");
		if(line==2)
			printf("      /  \\      ");
		if(line==3)
			printf("       ||       ");
		if(line==4)
			printf("      ----      ");
	}
	else if(suit==2){
		if(line==1)
			printf("     /\\  /\\     ");
		if(line==2)
			printf("     \\    /     ");
		if(line==3)
			printf("      \\  /      ");
		if(line==4)
			printf("       \\/       ");
	}
	else if(suit==3){
		if(line==1)
			printf("       /\\       ");
		if(line==2)
			printf("      /\\/\\      ");
		if(line==3)
			printf("       ||       ");
		if(line==4)
			printf("      ----      ");
	}
	else if(suit==4){
		if(line==1)
			printf("       /\\       ");
		if(line==2)
			printf("      /  \\      ");
		if(line==3)
			printf("      \\  /      ");
		if(line==4)
			printf("       \\/       ");
	}
	print_card_setcolor(2, suit);
}

void cards::print_card_setcolor(int mode,int suit){
	if(mode==1){
		if(suit%2==1) setColor(240);
		else setColor(252);
	}
	else{
		setColor(7);
	}
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

void cards::reset_card(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			card[i][j] = false;
	had_printed = 0;
	rand_card[0] = -1;
	rand_card[1] = -1;
}

void setColor(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void init_print(){
	printf("=======================================\n");
	printf("|        Dealer  Machine  v1.0        |\n");
	printf("---------------------------------------\n");
	printf("|         Creater: littlechin         |\n");
	printf("---------------------------------------\n");
	printf("| You can take cards by this machine! |\n");
	printf("=======================================\n\n");
}
