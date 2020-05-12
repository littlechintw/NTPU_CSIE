###### tags: `NTPU`

# HW2 撲克牌發放 Docs

Worked in `Windows 10`

## Features

- 依照使用者設定發放多張撲克牌，在同一副撲克牌不會有相同花色與數字
- 使用者可以設定一排要發放幾張牌
- 更新撲克牌為一整副 (整副牌發完自動更新 / 使用者自行更新)
- 防錯輸入

## How to use

1. 輸入要拿的卡片數量 (如果輸入不對的數字，將會印出 ERROR!)
   `可輸入的資料範圍將會依照當時狀況有所調整`
![](https://i.imgur.com/lMyciwY.png)

2. 輸入一排的卡片數量 (如果輸入不對的數字，將會印出 ERROR!)
   `可輸入的資料範圍將會依照當時狀況有所調整`
![](https://i.imgur.com/FN7zXgu.png)

3. 繼續輸入要拿的卡片數量 (如果輸入不對的數字，將會印出 ERROR!)
   `可輸入的資料範圍將會依照當時狀況有所調整`
![](https://i.imgur.com/NhO5S23.png)

4. 可輸入 -1 更新排組
![](https://i.imgur.com/2qqs5E8.png)

5. 當整副牌已發完，將自動更新牌組
![](https://i.imgur.com/ccNufxq.png)


## Source Code Detail

- `cards.cpp`
    - [6~13] 初始化各值
    - [15~27] `bool cards::print_card(int card_num,int group_num)`
        - 輸出牌的 `public` function。
        - `card_num` 為總共輸出的牌數量、`group_num` 為一排的牌數量。
        - 這個 function 會根據還未輸出的牌數量與一牌的牌數量呼叫 `print_card_group` function 輸出。
    - [29~61] `bool cards::print_card_group(int card_num)`
        - 輸出單排牌的 `private` function。
        - `card_num` 為要輸出的一排的牌數量。
        - 這個 function 會呼叫 `get_rand_card` 取得隨機值並確認是否重複；判斷是否可以繼續輸出，如可以，再呼叫 `print_card_line` 輸出。
    - [63~85] `void cards::print_card_line(int line,int suit,int number)`
        - 輸出牌其中一行的 `private` function。
        - `line` 為要輸出的一排的第幾行、`suit` 為花色、`number` 為數字。
        - 這個 function 會呼叫 `print_card_number` 或 `print_card_space` 或 `print_card_suit` 輸出。
    - [87~107] `void cards::print_card_number(int direction,int suit,int number)`
        - 輸出牌數字的 `private` function。
        - `direction` 為上方或下方、`suit` 為花色、`number` 為數字。
        - 這個 function 會根據位置輸出數字。
    - [109~113] `void cards::print_card_space()`
        - 輸出牌空白處的 `private` function。
        - 這個 function 會輸出牌空白處。
    - [115~158] `void cards::print_card_suit(int line,int suit)`
        - 輸出牌花色的 `private` function。
        - `line` 為行數、`suit` 為花色。
        - 這個 function 會根據行數輸出花色。
    - [160~168] `void cards::print_card_setcolor(int mode,int suit)`
        - 設置顏色的 `private` function。
        - `mode` 為模式、`suit` 為花色。
        - 這個 function 會根據模式、花色調整輸出顏色。
    - [170~185] `bool cards::get_rand_card()`
        - 取得隨機牌的 `private` function。
        - 這個 function 會取得還未發出的一張牌。
    - [187~194] `void cards::reset_card()`
        - 重設牌的 `public` function。
        - 這個 function 會重設牌。

## Source Code

- `main.cpp`
```c=
#include <bits/stdc++.h>
#include "cards.cpp"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	init_print();
	int number, group;
	cards new_cards;
	printf("How many cards do you want to take? (1-%d)\n> ", 52-new_cards.get_had_printed());
	while(cin >> number){
		if(number>52-new_cards.get_had_printed()){
			setColor(12);
            printf("Error! You take so many cards!!!!\n> ");
            setColor(7);
		}
		else if(number<=0&&number!=-1){
			setColor(12);
            printf("Error! You will not take any cards!!!!\n> ");
            setColor(7);
		}
		else if(number == -1){
			new_cards.reset_card();
			printf("I have renewed yor cards!\n");
			printf("How many cards do you want to take? (1-%d)\n> ", 52-new_cards.get_had_printed());
		}
		else{
			bool group_flag = false;
			printf("How many cards do you want to show in a line? (1-%d)\n> ", number);
			while(!group_flag){
				cin >> group;
				if(group>number){
					setColor(12);
		            printf("Error! You can only display %d cards in a row at most.\n> ", number);
		            setColor(7);
				}
				else if(group<=0){
					setColor(12);
		            printf("Error! You will not take any cards in a row!!!!\n> ");
		            setColor(7);
				}
				else{
					group_flag = true;
					bool flag = new_cards.print_card(number, group);
					if(flag){
						printf("How many cards do you want to take? (1-%d)\n", 52-new_cards.get_had_printed());
						printf("Or you can fill in -1 to renew the cards!\n> ");
					}
					else{
						new_cards.reset_card();
						printf("I have given you all the cards! So I renew your cards!\n");
						printf("How many cards do you want to take? (1-%d)\n> ", 52-new_cards.get_had_printed());
					}
				}
			}
		}
	} 
	return 0;
}
```

- `cards.h`
```c=
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
```

- `cards.cpp`
```c=
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
```