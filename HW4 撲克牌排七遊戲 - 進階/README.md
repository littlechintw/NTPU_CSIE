###### tags: `NTPU`

# HW4 撲克牌排七 - 進階版 Docs

Worked in `Windows 10` & `codeblock`
If you get an error say `redefined`, you may have to delete second line.

## Features

- 可選擇玩家數量 ( 2 或 4 )
- 可選擇電腦數量
- 防錯輸入
- 儲存遊戲紀錄
- 防止遊戲紀錄遭異常更改

## How to use

1. 如無發現遊戲紀錄或上局已結束則跳出輸入玩家、電腦數量
![](https://i.imgur.com/KvhyYGt.png)

2. 如發現遊戲紀錄則檢查檔案正確性並詢問是否恢復遊戲
![](https://i.imgur.com/89uRafN.png)

2. 等待玩家就位畫面，資訊包含玩家、局數、遺失分數
![](https://i.imgur.com/JM1bj1s.png)

3. 第一局僅可選擇 `黑桃 7`
![](https://i.imgur.com/f4jbAjn.png)

4. 輸入牌 ID 出牌
![](https://i.imgur.com/BSE7Rnk.png)

5. 自動判斷為放到牌面或是丟棄
![](https://i.imgur.com/neOgR8t.png)

6. 當到了電腦的回合，將會自動出牌
![](https://i.imgur.com/QAgHQRz.png)

7. 自動棄牌時畫面
![](https://i.imgur.com/2hJeJpl.png)

8. 結束後顯示贏家與各玩家分數
![](https://i.imgur.com/gG1BmQu.png)

9. 可選擇重新玩或結束
![](https://i.imgur.com/OxRKshm.png)


## Source Code Detail

- `board.cpp`
    - [12~68] `bool board::init_game()`: 調整與初始化必要參數，輸入時有防錯功能
    - [79~85] `void board::start()`: 開始遊戲
        - [81] 呼叫 `reset_printer()` 調整遊戲畫面
        - [80~83] 呼叫 `put_card()` 開啟遊戲
        - [84] 呼叫 `show_end()` 呈現結果
    - [87~89] `void board::reset_printer(int mode)`: 呼叫 `print_board_card` 印出目前場上狀況
    - [91~121] `void board::reset_printer(int mode)` : 依照相對應模式調整遊戲畫面
    - [123~163] `void board::put_card()`: 印出手牌並要求玩家丟出
        - [124~132] 建立一 vector 並依局數判斷需放進那些牌
        - [135~153] 判斷為真人或電腦局數
            - [136~150] 印出手牌並選擇
            - [153] 呼叫 `computer_play()` 並回傳出牌結果
        - [155] 呼叫 `get_put_card_status()` 並取得該牌可用狀態，出牌或丟棄
        - [156] 呼叫 `change_card_status()` 並改變該牌的狀態
        - [157] 呼叫 `show_step()` 並印出並提示玩家該牌處理結果
    - [165~178] `void board::change_card_status(int suit,int number,int status)`: 更改指定牌狀態
    - [180~191] `void board::show_step(int suit,int num,int step)`: 印出並提示玩家該牌處理結果
    - [193~212] `int board::get_put_card_status(int suit,int num)`: 取得該牌可用狀態，出牌或丟棄
    - [214~246] `void board::show_end()`: 印出最後結果
    - [248~273] `int board::computer_play(vector<int> cards)`: 電腦自動選牌
    - [275~309] `void board::save_game_as_file()`: 將遊戲資料儲存
        - [276~279] 建立讀取檔案的 `fstream`
        - [291~309] 寫遊戲資料到檔案內，其中包含 hash 後之值
    - [311~390] `int board::read_game_as_file()`: 將遊戲資料取出並檢查

- `cards.cpp`
    - [5~12] 初始化各值
    - [31~35] `int cards::get_rand_card_detail(int type)`
        - 取得隨機牌內容的 `public` function。
        - 這個 function 會取得取得隨機牌的內容(花色、號碼)。
    - [37~44] `void cards::reset_card()`
        - 重設牌的 `public` function。
        - 這個 function 會重設牌。

- `print_card.h`
    - [10~19] `void print_board_card(int print_card[4][3])`
        - 印出場上的牌狀況
    - [21~46] `void print_card(vector<int> print_card)`
        - 印出所以可出的牌並給予 ID
    - [48~82] `void cards::print_card_line(int line,int suit,int number)`
        - `line` 為要輸出的一排的第幾行、`suit` 為花色、`number` 為數字。
        - 這個 function 會呼叫 `print_card_number` 或 `print_card_space` 或 `print_card_suit` 輸出。
    - [84~104] `void cards::print_card_number(int direction,int suit,int number)`
        - `direction` 為上方或下方、`suit` 為花色、`number` 為數字。
        - 這個 function 會根據位置輸出數字。
    - [106~110] `void cards::print_card_space()`
        - 這個 function 會輸出牌空白處。
    - [112~165] `void cards::print_card_suit(int line,int suit)`
        - `line` 為行數、`suit` 為花色。
        - 這個 function 會根據行數輸出花色。
    - [167~175] `void cards::print_card_setcolor(int mode,int suit)`
        - 設置顏色的 `private` function。
        - `mode` 為模式、`suit` 為花色。
        - 這個 function 會根據模式、花色調整輸出顏色。

## Source Code

- `main.cpp`
```c=
#include <bits/stdc++.h>
#define _WIN32_WINNT 0x0500
// If use codeblock, you can ignor it.
// If you get an error say `redefined`, you may have to delete second line.
#include<windows.h>
#include "functions.h"
#include "board.cpp"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
	init_print();
	board game;
	game.init_game();
	game.start();

	return 0;
}
```

- `board.cpp`
```c=
#include <bits/stdc++.h>
#include "broad.h"
#include "print_card.h"
#include "md5.h"
using namespace std;

board::board(){
	printf("Here is a new game.\n");
	printf("And... Get started!!!\n\n");
}

bool board::init_game(){
	int flag = read_game_as_file();
	if(flag == -1) cout << "The file cannot work! Maybe someone want to crack it?" <<endl;
	if(flag != 1){
		game_card.reset_card();
		game_status = 1;
		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++)
				game[i][j] = -1; 
			score[i] = 0;
		}
		printf("Now, you can select how many player you want to play with!(2 or 4)\n> ");
		int input_player;
		bool player_flag = true;
		while(player_flag){
			cin >> input_player;
			if(input_player==2||input_player==4){
				player_num = input_player;
				for(int i=0;i<input_player;i++){
					for(int j=0;j<52/input_player;j++){
						if(game_card.get_rand_card()){
							int temp_suit = game_card.get_rand_card_detail(0);
							int temp_number = game_card.get_rand_card_detail(1);
							hand_card[temp_suit][temp_number][0] = i,
							hand_card[temp_suit][temp_number][1] = 0;
							if(temp_suit==0&&temp_number==6) turn = i;
						}
						else{
							printf("Error! There are some problem!");
							return false;
						}
					}
				}
				player_flag = false;
			}
			else{
				setColor(12);
				printf("Oh! You only can fill in 2 or 4!\n> ");
				setColor(7);
			}
		}
		printf("How many computer you want to play with?(0-%d)\n> ",input_player);
		int input_computer;
		bool computer_flag = true;
		while(computer_flag){
			cin >> input_computer;
			if(input_computer>=0&&input_computer<=input_player)
				computer_num = input_computer,
				computer_flag = false;
			else{
				setColor(12);
				printf("Oh! You only can fill in 0-%d!\n> ",input_player);
				setColor(7);
			}
		}
	}
}

void board::show_hand_card(int input_player){
	printf("You are Player-%d\n",input_player+1);
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(hand_card[i][j][0]==input_player)
			    printf("%d-%d\n",i,j);
	printf("----------\n");
}

void board::start(){
	while(game_status<=52){
		reset_printer(1);
		put_card();
	}
	show_end();
}

void board::show_game_board(){
	print_board_card(game);
}

void board::reset_printer(int mode){
	system("cls");
	if(mode==1){
		setColor(78);
		printf("  It's Player-%d's time!!!   ",turn+1);
		printf("Game-%d   ",game_status);
		printf("Drop %d point(s)  \n",score[turn]);
		setColor(7);
		printf("\n");
		show_game_board();
		printf("\n");
		for(int i=0;i<10;i++)
			printf("Wait For Player-%d...\n",turn+1);
		printf("\n");
		system("pause");
		if(turn<player_num-computer_num)
			reset_printer(2);
	}
	else if(mode==2){
		setColor(112);
		printf("  It's Player-%d's time!!!   ",turn+1);
		printf("Game-%d   ",game_status);
		printf("Drop %d point(s)  \n",score[turn]);
		setColor(7);
		printf("\n");
		show_game_board();
		printf(" ===================================================================\n");
		if(game_status == 1)
			printf("Player-%d have Spades 7!\n\n",turn+1);
	}
}

void board::put_card(){
	vector<int> hand_card_temp;
	if(game_status==1)
		hand_card_temp.push_back(006);
	else{
		for(int i=0;i<4;i++)
			for(int j=0;j<13;j++)
				if(hand_card[i][j][0]==turn&&hand_card[i][j][1]==0)
					hand_card_temp.push_back(i*100+j);
	}
	
	int card_id;
	if(turn<player_num-computer_num){
		print_card(hand_card_temp);
		bool cin_flag = true;
		while(cin_flag){
			printf("Which card you want to take out?(Card Number)\n> ");
			cin >> card_id;
			if(card_id<=hand_card_temp.size()&&card_id>0){
				cin_flag = false;
				setColor(7);
			}
			else{
				setColor(12);
				printf("Error! You can't take this card!\n");
			}
				
		}
	}
	else
		card_id = computer_play(hand_card_temp) + 1;
		
	int action = get_put_card_status(hand_card_temp[card_id-1]/100,hand_card_temp[card_id-1]%100);
	change_card_status(hand_card_temp[card_id-1]/100,hand_card_temp[card_id-1]%100,action);
	show_step(hand_card_temp[card_id-1]/100,hand_card_temp[card_id-1]%100,action);
	game_status++;
	turn++;
	if(turn==player_num) turn -= player_num;
	save_game_as_file();
	system("pause");
}

void board::change_card_status(int suit,int number,int status){
	hand_card[suit][number][1] = status;
	if(status==1){
		if(number==6)
			game[suit][1] = 6;
		else if(number>6)
			game[suit][0] = number;
		else if(number<6)
			game[suit][2] = number;	
	}
	else if(status==2){
		score[turn] += number+1;
	}
}

void board::show_step(int suit,int num,int step){
	system("cls");
	if(step==1)
		printf("Player-%d put this card on the board!\n\n",turn+1);
	else if(step==2)
		printf("This card is in player-%d's trash can!\n\n",turn+1);
	for(int line=1;line<=10;line++){
		print_card_line(line,suit+1,num+1);
		printf("\n");
	}
	printf("\n");
}

int board::get_put_card_status(int suit,int num){
	if(num==6) return 1;
	else if(num==5||num==7){
		if(game[suit][1]==-1)
			return 2;
		else return 1;
	}
	else{
		if(num<5){
			if(game[suit][2]==num+1)
				return 1;
			else return 2;
		}
		if(num>7){
			if(game[suit][0]==num-1)
				return 1;
			else return 2;
		}
	}
}

void board::show_end(){
	system("cls");
	printf("The winner is...\n");
	printf("----------------\n");
	int min = 999999;
	for(int i=0;i<player_num;i++)
		if(min>score[i]) min = score[i];
	for(int i=0;i<player_num;i++)
		if(min==score[i])  printf("    Player-%d\n",i+1);
	printf("----------------\n\n\n");
	for(int i=0;i<player_num;i++)
		printf("Player-%d drop %d point(s)!\n\n",i+1,score[i]);
	printf("\n");
	system("pause");
	printf("\nPlay again?\n\n");
	int next_status;
	bool cin_status = true;
	while(cin_status){
		printf("Press 1 to replay or 0 to stop the program\n> ");
		cin >> next_status;
		if(next_status==0||next_status==1)
			cin_status = false;
		else{
			setColor(12);
			printf("Error! Only can press 1 or 0!\n");
			setColor(7);
		}
	}
	if(next_status){
		init_game();
		start();
	}
}

int board::computer_play(vector<int> cards){
	int min = 12;
	for(int i=0;i<cards.size();i++){
		if(cards[i]%100 == 6)
			return i;
		if(cards[i]%100<min) min = cards[i]%100;
	}
	for(int i=0;i<cards.size();i++){
		if(cards[i]%100 == 5||cards[i]%100 == 7){
			if(game[cards[i]/100][1]!=0)
				return i;
		}
		else if(cards[i]%100<5){
			if(game[cards[i]/100][2]==cards[i]%100+1)
				return i;
		}
		else if(cards[i]%100>7){
			if(game[cards[i]/100][0]==cards[i]%100-1)
				return i;
		}
	}
	for(int i=0;i<cards.size();i++){
		if(cards[i]%100 == min)
			return i;
	}
}

void board::save_game_as_file(){
	fstream save_game_file;
	save_game_file.open("LastGame.txt", ios::out);
	fstream save_check_file;
	save_check_file.open("LastGameC.txt", ios::out);  
	string card_save = "";
	string game_save = "";
	string turn_save = to_string(turn);
	string game_status_save = to_string(game_status);
	string computer_num_save = to_string(computer_num);
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			card_save += to_string(hand_card[i][j][0]),
			card_save += "o",
			card_save += to_string(hand_card[i][j][1]),
			card_save += "O";
	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			game_save += to_string(game[i][j]) + "l";
	if(game_status>52) save_game_file << "1\n";
	else save_game_file << "0\n";
	save_game_file << card_save << "\n";
	save_game_file << game_save << "\n";
	save_game_file << turn_save << "\n";
	save_game_file << game_status_save << "\n";
	save_game_file << computer_num_save << "\n";
	
	if(game_status>52) save_check_file << md5_en("1") << "\n";
	else save_check_file << md5_en("0") << "\n";
	save_check_file << md5_en(card_save) << "\n";
	save_check_file << md5_en(game_save) << "\n";
	save_check_file << md5_en(turn_save) << "\n";
	save_check_file << md5_en(game_status_save) << "\n";
	save_check_file << md5_en(computer_num_save) << "\n";
}

int board::read_game_as_file(){
	fstream save_game_file;
	save_game_file.open("LastGame.txt", ios::in);
	fstream save_check_file;
	save_check_file.open("LastGameC.txt", ios::in);
	
	if(!save_game_file||!save_check_file) return 0;
	
	vector<string> file_data;
	string data_temp;
    while(getline(save_game_file,data_temp))
		file_data.push_back(data_temp);
	vector<string> check_data;
    while(getline(save_check_file,data_temp))
		check_data.push_back(data_temp);
	
	for(int c=0;c<check_data.size();c++){
		if(md5_en(file_data[c])!=check_data[c])
			return -1;
	}
	
	if(file_data[0]=="1") return 0;
	printf("I find you have a game still not finish!");
	bool last_game_flag = true;
	string cin_text;
	while(last_game_flag){
		printf("Do you want to play it?(y/n)\n> ");
		setColor(7);
		cin >> cin_text;
		if(cin_text=="y"||cin_text=="Y")
			last_game_flag = false;
		else if(cin_text=="n"||cin_text=="N")
			return 0;
		else setColor(12);
	}
	
	vector<string> game_temp;
	string temp = file_data[2];
	string temp_text = "";
	for(int i=0;i<temp.size();i++){
    	if(temp[i]=='l'){
    		if(temp!="")
    			game_temp.push_back(temp_text);
			temp_text = "";
		}
		else
			temp_text += temp[i];
		if(i==temp.size()-1)
			game_temp.push_back(temp_text);
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
			game[i][j] = stoi(game_temp[i*3+j]);
		score[i] = 0;
	}
	
	temp = file_data[1];
	int max_player = -1;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			char data_temp = temp[((i*13+j)*4)];
			hand_card[i][j][0] = int(data_temp)-48;
			if(max_player<hand_card[i][j][0]) max_player=hand_card[i][j][0];
			data_temp = temp[((i*13+j)*4+2)];
			hand_card[i][j][1] = int(data_temp)-48;
			if(hand_card[i][j][1]==2) score[hand_card[i][j][0]] += j+1;
		}
	}
	player_num = max_player + 1;
	
	game_card.reset_card();
	turn = stoi(file_data[3]);
	game_status = stoi(file_data[4]);
	computer_num = stoi(file_data[5]);
	
	printf("\nOkay, you can play the game after you press any button!\n\n");
	system("pause");
	return 1;
}
```

- `board.h`
```c=
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
		void save_game_as_file();
		int read_game_as_file();
	public:
		board();
		bool init_game();
		void show_hand_card(int input_player);
		void start();
		int get_player_num(){
			return player_num;
		};
};
```

- `cards.cpp`
```c=
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

void cards::reset_card(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			card[i][j] = false;
	had_printed = 0;
	rand_card[0] = -1;
	rand_card[1] = -1;
}
```

- `cards.h`
```c=
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
		void reset_card();
		bool get_rand_card();
		int get_rand_card_detail(int);
};
```

- `functions.h`
```c=
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void setColor(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void init_print(){
	printf("=======================================\n");
	printf("| Sevens                         v1.0 |\n");
	printf("---------------------------------------\n");
	printf("| Creater: littlechin                 |\n");
	printf("---------------------------------------\n");
	printf("| Copyright (c) 2020 littlechin       |\n");
	printf("=======================================\n\n");
}
```

- `print_card.h`
```c=
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

void print_card(vector<int> print_card){
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
		for(int i=0;i<line_num;i++){
			printf(" ");
			setColor(143);
			if((r*a_row+i+1)/10>0)
				printf(" %d             ",r*a_row+i+1);
			else
				printf(" %d              ",r*a_row+i+1);
			setColor(7);
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
```

- `md5.h`
```c=
#include <bits/stdc++.h>
using namespace std;

class md5 {
    private:
        uint32_t a0_;
        uint32_t b0_;
        uint32_t c0_;
        uint32_t d0_;

        array<uint32_t, 16> m_array_;
        array<uint32_t, 16>::iterator m_array_first_;

        static const array<uint32_t, 64> k_array_;
        static const array<uint32_t, 64> s_array_;

    private:
        static uint32_t left_rotate(uint32_t x, uint32_t c) {
            return (x << c) | (x >> (32 - c));
        }

        template <class OutputIterator>
        static void uint32_to_byte(uint32_t n, OutputIterator & first) {

            *first++ = n & 0xff;
            *first++ = (n >> 8) & 0xff;
            *first++ = (n >> 16) & 0xff;
            *first++ = (n >> 24) & 0xff;
        }

        template <class OutputIterator>
        static void uint32_to_hex(uint32_t n, OutputIterator & first) {
            const char * hex_chars = "0123456789abcdef";            

            uint32_t b;

            b = n & 0xff;
            *first++ = hex_chars[b >> 4];
            *first++ = hex_chars[b & 0xf];

            b = (n >> 8) & 0xff;
            *first++ = hex_chars[b >> 4];
            *first++ = hex_chars[b & 0xf];

            b = (n >> 16) & 0xff;
            *first++ = hex_chars[b >> 4];
            *first++ = hex_chars[b & 0xf];

            b = (n >> 24) & 0xff;
            *first++ = hex_chars[b >> 4];
            *first++ = hex_chars[b & 0xf];
        }

    private:
        void reset_m_array() {
            m_array_first_ = m_array_.begin();
        }

        template <class InputIterator>
        void bytes_to_m_array(InputIterator & first, array<uint32_t, 16>::iterator m_array_last) {
            for (; m_array_first_ != m_array_last; ++m_array_first_) {
                *m_array_first_ = *first++;
                *m_array_first_ |= *first++ << 8;
                *m_array_first_ |= *first++ << 16; 
                *m_array_first_ |= *first++ << 24;
            }
        }

        template <class InputIterator>
        void true_bit_to_m_array(InputIterator & first, ptrdiff_t chunk_length) {
            switch (chunk_length % 4) {
                case 0:
                    *m_array_first_++ = 0x00000080;
                    break;
                case 1:
                    *m_array_first_++ = *first++;
                    *m_array_first_ |= 0x00008000;
                    break;
                case 2:
                    *m_array_first_++ = *first++; 
                    *m_array_first_ |= *first++ << 8;
                    *m_array_first_ |= 0x00800000;
                    break;
                case 3:
                    *m_array_first_++ = *first++;
                    *m_array_first_ |= *first++ << 8;
                    *m_array_first_ |= *first++ << 16;
                    *m_array_first_ |= 0x80000000;
                    break;
            }
        }

        void zeros_to_m_array(array<uint32_t, 16>::iterator m_array_last) {
            for (; m_array_first_ != m_array_last; ++m_array_first_) {
                *m_array_first_ = 0;
            }
        }

        void original_length_bits_to_m_array(uint64_t original_length_bits) {
            original_length_bits &= 0xffffffffffffffff;
            *m_array_first_++ = (original_length_bits) & 0x00000000ffffffff;
            *m_array_first_++ = (original_length_bits & 0xffffffff00000000) >> 32;
        }

        void hash_chunk() {
            uint32_t A = a0_;
            uint32_t B = b0_;
            uint32_t C = c0_;
            uint32_t D = d0_;

            uint32_t F;
            unsigned int g;

            for (unsigned int i = 0; i < 64; ++i) {
                if (i < 16) {
                    F = (B & C) | ((~B) & D);
                    g = i;
                }
                else if (i < 32) {
                    F = (D & B) | ((~D) & C);
                    g = (5 * i + 1) & 0xf; 
                }
                else if (i < 48) {
                    F = B ^ C ^ D;
                    g = (3 * i + 5) & 0xf;
                }
                else {
                    F = C ^ (B | (~D));
                    g = (7 * i) & 0xf;
                }

                uint32_t D_temp = D;
                D = C;
                C = B;
                B += left_rotate(A + F + k_array_[i] + m_array_[g], s_array_[i]);
                A = D_temp;
            }

            a0_ += A;
            b0_ += B;
            c0_ += C;
            d0_ += D;
        }

    public:
        template <class InputIterator>
        void update(InputIterator first, InputIterator last) {

            uint64_t original_length_bits = distance(first, last) * 8;

            ptrdiff_t chunk_length;
            while ((chunk_length = distance(first, last)) >= 64) {
                reset_m_array();
                bytes_to_m_array(first, m_array_.end());
                hash_chunk();
            }

            reset_m_array();
            bytes_to_m_array(first, m_array_.begin() + chunk_length / 4);
            true_bit_to_m_array(first, chunk_length);

            if (chunk_length >= 56) {
                zeros_to_m_array(m_array_.end());
                hash_chunk();

                reset_m_array();
                zeros_to_m_array(m_array_.end() - 2);
                original_length_bits_to_m_array(original_length_bits);
                hash_chunk();
            }
            else {
                zeros_to_m_array(m_array_.end() - 2);
                original_length_bits_to_m_array(original_length_bits);
                hash_chunk();
            }
        }   

    public:
        md5()
          : a0_(0x67452301),
            b0_(0xefcdab89),
            c0_(0x98badcfe),
            d0_(0x10325476)
        {}

        template <class Container> 
        void digest(Container & container) {
            container.resize(16);
            auto it = container.begin();

            uint32_to_byte(a0_, it);
            uint32_to_byte(b0_, it);
            uint32_to_byte(c0_, it);
            uint32_to_byte(d0_, it);
        }

        template <class Container>
        void hex_digest(Container & container) {
            container.resize(32);
            auto it = container.begin();

            uint32_to_hex(a0_, it);
            uint32_to_hex(b0_, it);
            uint32_to_hex(c0_, it);
            uint32_to_hex(d0_, it);
        }
};

const array<uint32_t, 64> md5::k_array_ = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const array<uint32_t, 64> md5::s_array_ = {
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

string md5_en(string data){
    string data_hex_digest;

    md5 hash;
    hash.update(data.begin(), data.end());
    hash.hex_digest(data_hex_digest);

    return data_hex_digest;
}
```