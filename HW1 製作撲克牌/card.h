#include <bits/stdc++.h>
#define RESET "\033[0m"
#define BLACK "\033[47m\033[30m\033[2m"
#define RED   "\033[47m\033[31m\033[2m"
using namespace std;

class card {
	private:
		int number=0,suit=0;
	public:
		card(int x,int y);
		void print_card();
		void print_card_number(int direction); 
		void print_card_suit();
		void print_card_setcolor(int mode);
};

card::card(int x,int y){
	number = x;
	suit = y;
}

void card::print_card(){
	cout << "This is your card!(" << number << "-" << suit << ")\n";
	print_card_number(1);
	print_card_suit();
	print_card_number(2);
	cout << "\n";
}

void card::print_card_number(int direction){
	print_card_setcolor(1);
	if(direction==1) cout << " ";
	else{
		for(int i=0;i<13;i++) cout << " ";
		if(number!=10) cout << " ";
	}
	
	if(number == 1) cout << "A";
	else if(number == 11) cout << "J";
	else if(number == 12) cout << "Q";
	else if(number == 13) cout << "K";
	else cout << number;
	
	if(direction==1){
		for(int i=0;i<13;i++) cout << " ";
		if(number!=10) cout << " ";
	}
	else cout << " ";
	print_card_setcolor(2);
}

void card::print_card_suit(){
	for(int i=0;i<2;i++){
		print_card_setcolor(1);
		cout << "                ";
		print_card_setcolor(2);
	}
	if(suit==1){
		print_card_setcolor(1);
		cout << "       /\\       ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      /  \\      ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "       ||       ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      ----      ";
		print_card_setcolor(2);
	}
	else if(suit==2){
		print_card_setcolor(1);
		cout << "     /\\  /\\     ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "     \\    /     ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      \\  /      ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "       \\/       ";
		print_card_setcolor(2);
	}
	else if(suit==3){
		print_card_setcolor(1);
		cout << "       /\\       ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      /\\/\\      ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "       ||       ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      ----      ";
		print_card_setcolor(2);
	}
	else if(suit==4){
		print_card_setcolor(1);
		cout << "       /\\       ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      /  \\      ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "      \\  /      ";
		print_card_setcolor(2);
		print_card_setcolor(1);
		cout << "       \\/       ";
		print_card_setcolor(2);
	}
	for(int i=0;i<2;i++){
		print_card_setcolor(1);
		cout << "                ";
		print_card_setcolor(2);
	}
}

void card::print_card_setcolor(int mode){
	if(mode==1){
		cout << " ";
		if(suit%2==1) cout << BLACK;
		else cout << RED;
	}
	else{
		cout << RESET;
		cout << " \n";
	}
}
