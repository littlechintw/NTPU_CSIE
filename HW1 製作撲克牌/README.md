###### tags: `NTPU`

# HW1 撲克牌製作 Docs

Worked in `Windows 10`

## Features

- Add a card and print it

## How to use

1. Fill in the card's number (If you fill in a wrong data, you will get an ERROR!)

![](https://i.imgur.com/UL4vI6Z.png)

2. Fill in the card's suit (If you fill in a wrong data, you will get an ERROR!)

![](https://i.imgur.com/BmGvzTd.png)

3. Get a card & Add another card

![](https://i.imgur.com/OdfkUxo.png)

4. If fill in 0, it will leave the program

![](https://i.imgur.com/ikGhK7V.png)


## Source Code Detail

- `card.h`
    - a class about card
        - private
            - variables is to protect the data
        - publish
            - `print_card` function
              Use this function can print the card
            - `print_card_number` function
              This function is used for `print_card` function. When direction = 1, it will print number on the left, when direction = 2, it will print number on the right.
            - `print_card_suit` function
              This function is used for `print_card` function. It will print the suit.
            - `print_card_setcolor` function
              This function is used for `print_card` function. When mode = 1, it will change the color by the variable, 'suit', when mode = 0, it will change the color to default.

## Source Code

- `main.cpp`
```c=
#include <bits/stdc++.h>
#include "card.h"
using namespace std;

int main(){
    int number,suit;
    printf("Please fill in the number(1-13)\n> ");
    while(cin>>number){
    	if(number>=1&&number<=13){
    		bool suit_flag = false;
    		while(!suit_flag){
    			printf("Please fill in the suit\n");
				printf("1.Spades 2.Hearts 3.Clubs 4.Diamonds\n> ");
				cin >> suit;
				if(suit>=1&&suit<=4){
					suit_flag = true;
					printf("\n");
		    		card new_card(number,suit);
	    			new_card.print_card();
				}
				else {
                    setColor(12);
                    printf("Error! The \"suit\" format is uncorrect!\n");
                    setColor(7);
				}
			}
		}
		else if(number == 0) {
			printf("Bye~\n");
			return 0;
		}
		else{
            setColor(12);
            printf("Error! The \"number\" format is uncorrect!\n");
            setColor(7);
		}
		printf("Please fill in the number(1-13)\n> ");
	}
	return 0;
}
```

- `card.h`
```c=
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void setColor(int color);

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
	printf("This is your card!(%d-%d)\n",number,suit);
	print_card_number(1);
	print_card_suit();
	print_card_number(2);
	printf("\n");
}

void card::print_card_number(int direction){
	print_card_setcolor(1);
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
	print_card_setcolor(2);
}

void card::print_card_suit(){
	for(int i=0;i<2;i++){
		print_card_setcolor(1);
		printf("                ");
		print_card_setcolor(2);
	}
	if(suit==1){
		print_card_setcolor(1);
		printf("       /\\       ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      /  \\      ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("       ||       ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      ----      ");
		print_card_setcolor(2);
	}
	else if(suit==2){
		print_card_setcolor(1);
		printf("     /\\  /\\     ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("     \\    /     ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      \\  /      ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("       \\/       ");
		print_card_setcolor(2);
	}
	else if(suit==3){
		print_card_setcolor(1);
		printf("       /\\       ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      /\\/\\      ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("       ||       ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      ----      ");
		print_card_setcolor(2);
	}
	else if(suit==4){
		print_card_setcolor(1);
		printf("       /\\       ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      /  \\      ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("      \\  /      ");
		print_card_setcolor(2);
		print_card_setcolor(1);
		printf("       \\/       ");
		print_card_setcolor(2);
	}
	for(int i=0;i<2;i++){
		print_card_setcolor(1);
		printf("                ");
		print_card_setcolor(2);
	}
}

void card::print_card_setcolor(int mode){
	if(mode==1){
		printf(" ");
		if(suit%2==1) setColor(240);
		else setColor(252);
	}
	else{
		setColor(7);
		printf(" \n");
	}
}

void setColor(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}
```