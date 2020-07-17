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
