###### tags: `NTPU`

# HW5 撲克牌撿紅點遊戲 Docs

Worked in `Windows 10` & `codeblock`
If you get an error say `redefined`, you may have to delete second line.

## Features

- 可選擇玩家數量 ( 2 到 4 )
- 可選擇電腦數量
- 防錯輸入
- 儲存遊戲紀錄
- 防止遊戲紀錄遭異常更改

## How to use

1. 如無發現遊戲紀錄或上局已結束則跳出輸入玩家、電腦數量
![](https://i.imgur.com/Q4pew7l.png)

2. 如發現遊戲紀錄則檢查檔案正確性並詢問是否恢復遊戲
![](https://i.imgur.com/qBk4aeP.png)

3. 等待玩家就位畫面，資訊包含玩家、局數、分數
![](https://i.imgur.com/NueKwt3.png)

4. 輸入牌 ID 出牌
![](https://i.imgur.com/wKpbLzF.png)

5. 自動判斷要放到海底或是吃掉
![](https://i.imgur.com/PwejWP5.png)

6. 當場上有兩張以上可選擇吃掉的牌，將詢問要吃哪張牌
![](https://i.imgur.com/yhG7Vzl.png)

6. 當到了電腦的回合，將會自動出牌
![](https://i.imgur.com/mC3qEGG.png)

7. 自動棄牌時畫面
![](https://i.imgur.com/qYIp3vF.png)

8. 結束後顯示贏家與各玩家分數
![](https://i.imgur.com/7AmtZMu.png)

9. 可選擇重新玩或結束
![](https://i.imgur.com/g9omXtr.png)

## Operator Overloading

1. 判斷分數
`board.cpp` [461~465]: 
```c=
bool player::operator>=(const player &p) {
	if(score>=p.score)
		return true;
	return false;
}
```
2. 新增儲存資料
`board.cpp` [475~479]: 
```c=
Save_game Save_game::operator+=(string d) {
	data.push_back(d); 
	Save_game tmp(data);
	return tmp;
}
```

## Source Code Detail

- `board.cpp`
    - [12~77] `bool board::init()`: 調整與初始化必要參數，輸入時有防錯功能
    - [79~84] `void board::start()`: 開始遊戲
        - [80] 呼叫 `init()` 初始化遊戲
        - [81~82] 呼叫 `next_status()` 繼續遊戲
        - [83] 呼叫 `end_page()` 呈現結果
    - [86~93] `void board::next_status()`: 印出準備、選牌畫面
    - [95~109] `void board::prepare_page()`: 呼叫 `show_game_board` 印出目前場上狀況並等待玩家
    - [91~121] `void board::reset_printer(int mode)` : 依照相對應模式調整遊戲畫面
    - [111~205] `void board::game_page()`: 印出手牌並要求玩家丟出
        - [121~125] 建立一 vector 並存入目前手牌
        - [128~147] 判斷為真人或電腦局數
            - [129~144] 印出手牌並選擇
            - [153] 呼叫 `computer_play()` 並回傳出牌結果
        - [149~157] 建立一 vector 並存入可從海底拿的牌
        - [159~204] 如有兩張以上可拿，則要求使用者再次挑選要拿哪張牌
    - [207~229] `void board::show_step(int card,int mode,int score)`: 印出該動作為何，如本局有分數產生則顯示分數
    - [231~266] `void board::end_page()`: 印出最後結果
    - [268~275] `void board::show_game_board()`: 呼叫`print_card()`印出場上狀態
    - [277~298] `int board::computer_play(vector<int> cards,int mode)`: 電腦自動選牌
    - [300~310] `int board::take_one_card()`: 抽張牌放入海底
    - [312~322] `int board::add_score(int card,int now_turn)`: 為玩家新增分數
    - [324~336] `void board::save_game_as_file()`: 將遊戲資料儲存
        - [276~279] 呼叫`Save_game`的`class`
        - [327~333] 利用 Operator Overloading 技術新增內容至`Save_game`的`class`
        - [335] 儲存
    - [338~438] `int board::read_game_as_file()`: 將遊戲資料取出並檢查
    - [446~448] `void player::set_card(int suit,int number, int mode)`: 設定玩家的某張牌狀態
    - [450~452] `int player::read_card(int suit,int number)`: 回傳玩家的某張牌狀態
    - [454~459] `void player::reset()`: 將玩家的牌狀態全部重設
    - [461~465] `bool player::operator>=(const player &p)`: 將`>=`運算子改寫
    - [461~465] `bstring player::save_str()`: 將該玩家的牌狀態製作成一字串以便儲存
    - [461~465] `Save_game Save_game::operator+=(string d)`: 將`+=`運算子改寫
    - [481~491] `void Save_game::save_it()`: 將遊戲資料儲存

- `cards.cpp`
    - [5~12] 初始化各值
    - [31~35] `int cards::get_rand_card_detail(int type)`
        - 取得隨機牌內容的 `public` function。
        - 這個 function 會取得取得隨機牌的內容(花色、號碼)。
    - [37~44] `void cards::reset_card()`
        - 重設牌的 `public` function。
        - 這個 function 會重設牌。
    - [46~50] `void cards::reg_card(int suit,int num,bool flag)`: 註冊牌狀態

- `print_card.h`
    - [10~19] `void print_board_card(int print_card[4][3])`
        - 印出場上的牌狀況
    - [21~48] `void print_card(vector<int> print_card,int show_id)`
        - 印出所以可出的牌並依照參數是否給予 ID
    - [50~84] `void cards::print_card_line(int line,int suit,int number)`
        - `line` 為要輸出的一排的第幾行、`suit` 為花色、`number` 為數字。
        - 這個 function 會呼叫 `print_card_number` 或 `print_card_space` 或 `print_card_suit` 輸出。
    - [86~106] `void cards::print_card_number(int direction,int suit,int number)`
        - `direction` 為上方或下方、`suit` 為花色、`number` 為數字。
        - 這個 function 會根據位置輸出數字。
    - [108~112] `void cards::print_card_space()`
        - 這個 function 會輸出牌空白處。
    - [114~167] `void cards::print_card_suit(int line,int suit)`
        - `line` 為行數、`suit` 為花色。
        - 這個 function 會根據行數輸出花色。
    - [169~177] `void cards::print_card_setcolor(int mode,int suit)`
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

bool board::init(){
	int flag = read_game_as_file();
	if(flag == -1) cout << "The file cannot work! Maybe someone want to crack it?" <<endl;
	if(flag != 1){
		turn = 0;
		game_status = 0;
		game_card.reset();
		for(int i=0;i<4;i++)
			a_player[i].reset();
		cover_card.reset();
		printf("Now, you can select how many player you want to play with!(2-4)\n> ");
		int input_player;
		bool player_flag = true;
		while(player_flag){
			cin >> input_player;
			if(input_player>=2&&input_player<=4){
				player_num = input_player;
				for(int i=0;i<input_player;i++){
					for(int j=0;j<24/input_player;j++){
						if(game_card.get_rand_card()){
							int temp_suit = game_card.get_rand_card_detail(0);
							int temp_number = game_card.get_rand_card_detail(1);
							a_player[i].set_card(temp_suit, temp_number, 1);
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
				printf("Oh! You only can fill in 2 to 4!\n> ");
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
		for(int i=0;i<4;i++){
			if(game_card.get_rand_card()){
				int temp_suit = game_card.get_rand_card_detail(0);
				int temp_number = game_card.get_rand_card_detail(1);
				cover_card.set_card(temp_suit, temp_number, 1);
			}
			else{
				printf("Error! There are some problem!");
				return false;
			}
		}
		return true;
	}
}

void board::start(){
	init();
	while(game_status<24)
		next_status();
	end_page();
}

void board::next_status(){
	prepare_page();
	game_page();
	if(turn+1 == player_num)
		turn = 0;
	else turn++;
	game_status++;
}

void board::prepare_page(){
	system("cls");
	setColor(78);
	printf("  It's Player-%d's time!!!   ",turn+1);
	printf("Game-%d   ",game_status+1);
	printf("Score: %d  \n",a_player[turn].read_score());
	setColor(7);
	printf("\n");
	show_game_board();
	printf("\n");
	for(int i=0;i<10;i++)
		printf("Wait For Player-%d...\n",turn+1);
	printf("\n");
	system("pause");
}

void board::game_page(){
	system("cls");
	setColor(112);
	printf("  It's Player-%d's time!!!   ",turn+1);
	printf("Game-%d   ",game_status+1);
	printf("Score: %d  \n",a_player[turn].read_score());
	setColor(7);
	printf("\n");
	show_game_board();
	printf(" ===================================================================\n");
	vector<int> hand_card_temp;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(a_player[turn].read_card(i,j)==1)
				hand_card_temp.push_back(i*100+j);
	
	int card_id;
	if(turn<player_num-computer_num){
		print_card(hand_card_temp,1);
		bool cin_flag = true;
		while(cin_flag){
			printf("Which card you want to take out?(Card Number)\n> ");
			cin >> card_id;
			if(card_id<=hand_card_temp.size()&&card_id>0){
				cin_flag = false;
				card_id--;
				setColor(7);
			}
			else{
				setColor(12);
				printf("Error! You can't take this card!\n");
			}
				
		}
	}
	else
		card_id = computer_play(hand_card_temp,0);
	
	vector<int> can_take;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(cover_card.read_card(i,j)==1){
				if(j>=9&&hand_card_temp[card_id]%100==j)
					can_take.push_back(i*100+j);
				else if(hand_card_temp[card_id]%100+j==8)
					can_take.push_back(i*100+j);
			}
	
	if(can_take.size()==0){
		a_player[turn].set_card(hand_card_temp[card_id]/100, hand_card_temp[card_id]%100, 0);
		cover_card.set_card(hand_card_temp[card_id]/100, hand_card_temp[card_id]%100, 1);
		show_step(hand_card_temp[card_id],1,0);
	}
	else if(can_take.size()==1){
		a_player[turn].set_card(hand_card_temp[card_id]/100, hand_card_temp[card_id]%100, 2);
		a_player[turn].set_card(can_take[0]/100, can_take[0]%100, 2);
		cover_card.set_card(can_take[0]/100, can_take[0]%100, 0);
		take_one_card();
		int temp_s = 0;
		temp_s += add_score(hand_card_temp[card_id],turn);
		temp_s += add_score(can_take[0],turn);
		show_step(hand_card_temp[card_id]*1000 + can_take[0],0,temp_s);
	}
	else{
		printf("\n");
		int combine_card_id;
		print_card(can_take,1);
		bool cin_flag = true;
		if(turn>=player_num-computer_num){
			cin_flag = false;
			combine_card_id = computer_play(can_take,1);
		}
		while(cin_flag){
			printf("\nWhich card you want to combine with?(Card Number)\n> ");
			cin >> combine_card_id;
			if(combine_card_id<=can_take.size()&&combine_card_id>0){
				cin_flag = false;
				combine_card_id--;
				setColor(7);
			}
			else{
				setColor(12);
				printf("Error! You can't combine with this card!\n");
			}
		}
		a_player[turn].set_card(hand_card_temp[card_id]/100, hand_card_temp[card_id]%100, 2);
		a_player[turn].set_card(can_take[combine_card_id]/100, can_take[combine_card_id]%100, 2);
		cover_card.set_card(can_take[combine_card_id]/100, can_take[combine_card_id]%100, 0);
		take_one_card();
		int temp_s = 0;
		temp_s += add_score(hand_card_temp[card_id],turn);
		temp_s += add_score(can_take[combine_card_id],turn);
		show_step(hand_card_temp[card_id]*1000 + can_take[combine_card_id],0,temp_s);
	}
}

void board::show_step(int card,int mode,int score){
	system("cls");
	save_game_as_file();
	printf("Player-%d ",turn+1);
	if(mode==0){
		printf("take the cards\n\n");
		vector<int> temp;
		temp.push_back(card/1000);
		temp.push_back(card%1000);
		print_card(temp,0);
	}
	else if(mode==1){
		printf("take out the cards\n\n");
		vector<int> temp;
		temp.push_back(card);
		print_card(temp,0);
	}
	
	if(score>0)
		printf("And get %d point(s)!\n\n",score);
	
	system("pause");
}

void board::end_page(){
	system("cls");
	printf("The winner is...\n");
	printf("----------------\n");
	
	for(int i=0;i<player_num;i++){
		bool flag = true;
		for(int j=0;j<player_num;j++)
			if(!(a_player[i]>=a_player[j]))
				flag = false;
		if(flag)
			printf("    Player-%d\n",i+1);
	}
		
	printf("----------------\n\n\n");
	for(int i=0;i<player_num;i++)
		printf("Player-%d get %d point(s)!\n\n",i+1,a_player[i].read_score());
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
	if(next_status)
		start();
}

void board::show_game_board(){
	vector<int> cards;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(cover_card.read_card(i,j)==1)
				cards.push_back(i*100+j);
	print_card(cards,0);
}

int board::computer_play(vector<int> cards,int mode){
	srand( time(NULL) );
    int rand_n = rand();
	if(mode==1) return (rand_n%cards.size());
	vector<int> sea_cards;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(cover_card.read_card(i,j)==1)
				sea_cards.push_back(i*100+j);
    for(int i=0;i<cards.size();i++){
    	for(int j=0;j<sea_cards.size();j++){
    		if(cards[i]%100+sea_cards[j]%100==8)
    			return i;
		}
	}
	for(int i=0;i<cards.size();i++){
		if(cards[i]/100==0)
    		return i;
	}
	
	return (rand_n%cards.size());
}

int board::take_one_card(){
	if(game_card.get_rand_card()){
		int temp_suit = game_card.get_rand_card_detail(0);
		int temp_number = game_card.get_rand_card_detail(1);
		cover_card.set_card(temp_suit, temp_number, 1);
	}
	else{
		printf("Error! There are some problem from take a random card!");
		return -1;
	}
}

int board::add_score(int card,int now_turn){
	int s = 0;
	if(card==0) s = 10;
	else if((card/100)%2==1){
		if(card%100==0) s = 20;
		else if(card%100>8) s = 10;
		else s = (card%100)+1;
	}
	a_player[now_turn].set_score(s);
	return s;
}

void board::save_game_as_file(){
	Save_game data;
	
	if(game_status<23) data += "0";
	else data += "1";
	data += to_string(player_num);
	data += to_string(computer_num);
	for(int i=0;i<player_num;i++)
		data += a_player[i].save_str();
	data += cover_card.save_str();
		
	data.save_it();
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
	
	player_num = stoi(file_data[1]);
	computer_num = stoi(file_data[2]);
	
	int game_status_temp = 24;
	
	for(int i=0;i<player_num;i++){
		vector<string> game_temp;
		string temp = file_data[3+i];
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
		
		for(int j=0;j<4;j++)
			for(int k=0;k<13;k++){
				a_player[i].set_card(j,k,stoi(game_temp[j*13+k]));
				if(stoi(game_temp[j*13+k])==1)
					game_status_temp--;
				if(stoi(game_temp[j*13+k])==2)
					add_score(100*j+k,i);
				if(stoi(game_temp[j*13+k])!=0)
					game_card.reg_card(j,k,true);
			}
	}
	
	vector<string> cover_card_temp;
	string temp = file_data[3+player_num];
	string temp_text = "";
	for(int i=0;i<temp.size();i++){
    	if(temp[i]=='l'){
    		if(temp!="")
    			cover_card_temp.push_back(temp_text);
			temp_text = "";
		}
		else
			temp_text += temp[i];
		if(i==temp.size()-1)
			cover_card_temp.push_back(temp_text);
	}
	
	for(int j=0;j<4;j++){
		for(int k=0;k<13;k++){
			cover_card.set_card(j,k,stoi(cover_card_temp[j*13+k]));
			if(stoi(cover_card_temp[j*13+k])!=0)
				game_card.reg_card(j,k,true);
		}
	}
	
	int turn_temp = game_status_temp % 4;
	
	turn = turn_temp;
	game_status = game_status_temp;
	
	printf("\nOkay, you can play the game after you press any button!\n\n");
	system("pause");
	return 1;
}

player::player(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			cards[i][j] = 0;
}

void player::set_card(int suit,int number, int mode){
	cards[suit][number] = mode;
}

int player::read_card(int suit,int number){
	return cards[suit][number];
}

void player::reset(){
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			cards[i][j] = 0;
	score = 0;
}

bool player::operator>=(const player &p) {
	if(score>=p.score)
		return true;
	return false;
}

string player::save_str(){
	string temp = "";
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			temp += to_string(cards[i][j]) + 'l';
	return temp;
}

Save_game Save_game::operator+=(string d) {
	data.push_back(d); 
	Save_game tmp(data);
	return tmp;
}

void Save_game::save_it(){
	fstream save_game_file;
	save_game_file.open("LastGame.txt", ios::out);
	fstream save_check_file;
	save_check_file.open("LastGameC.txt", ios::out);
	
	for(int i=0;i<data.size();i++){
		save_game_file << data[i] <<endl;
		save_check_file << md5_en(data[i]) <<endl;
	}
}
```

- `board.h`
```c=
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
		void reset();
		bool get_rand_card();
		int get_rand_card_detail(int);
		void reg_card(int,int,bool);
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
	printf("| Picking up is a little red     v1.0 |\n");
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