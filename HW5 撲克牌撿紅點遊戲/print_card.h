#include <bits/stdc++.h>
using namespace std;

void print_card_line(int,int,int);
void print_card_number(int,int,int);
void print_card_space();
void print_card_suit(int,int);
void print_card_setcolor(int,int);

void print_board_card(int print_card[4][3]){
	for(int column=0;column<3;column++){
		for(int line=1;line<=10;line++){
			for(int suit=0;suit<4;suit++)
				print_card_line(line,suit+1,print_card[suit][column]+1);
			printf("\n");
		}
		printf("\n");
	}
}

void print_card(vector<int> print_card,int show_id){
	int all_card = print_card.size();
	int a_row = 8;
	int row = all_card/a_row;
	if(all_card%a_row!=0) row++;
	for(int r=0;r<row;r++){
		int line_num = all_card%a_row;
		if(all_card/a_row>0) line_num = a_row;
		for(int line=1;line<=10;line++){
			for(int i=0;i<line_num;i++)
				print_card_line(line,print_card[r*a_row+i]/100+1,print_card[r*a_row+i]%100+1);
			printf("\n");
		}
		if(show_id){
			for(int i=0;i<line_num;i++){
				printf(" ");
				setColor(143);
				if((r*a_row+i+1)/10>0)
					printf(" %d             ",r*a_row+i+1);
				else
					printf(" %d              ",r*a_row+i+1);
				setColor(7);
			}
		}
		printf("\n\n");
		all_card -= a_row;
	}
}

void print_card_line(int line,int suit,int number){
	printf(" ");
	if(line==1){
		if(number==0) print_card_space();
		else print_card_number(1, suit, number);
	}
	else if(line==2)
		print_card_space();
	else if(line==3)
		print_card_space();
	else if(line==4){
		if(number==0) print_card_suit(1, 0);
		else print_card_suit(1, suit);
	}
	else if(line==5){
		if(number==0) print_card_suit(2, 0);
		else print_card_suit(2, suit);
	}
	else if(line==6){
		if(number==0) print_card_suit(3, 0);
		else print_card_suit(3, suit);
	}
	else if(line==7){
		if(number==0) print_card_suit(4, 0);
		else print_card_suit(4, suit);
	}
	else if(line==8)
		print_card_space();
	else if(line==9)
		print_card_space();
	else if(line==10){
		if(number==0) print_card_space();
		else print_card_number(2, suit, number);
	}
}

void print_card_number(int direction,int suit,int number){
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

void print_card_space(){
	print_card_setcolor(1, 0);
	printf("                ");
	print_card_setcolor(2, 0);
}

void print_card_suit(int line,int suit){
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
	else if(suit==0){
		if(line==1)
			printf("    *      *    ");
		if(line==2)
			printf("      *  *      ");
		if(line==3)
			printf("      *  *      ");
		if(line==4)
			printf("    *      *    ");
	}
	print_card_setcolor(2, suit);
}

void print_card_setcolor(int mode,int suit){
	if(mode==1){
		if(suit%2==1) setColor(240);
		else setColor(252);
	}
	else{
		setColor(7);
	}
}
