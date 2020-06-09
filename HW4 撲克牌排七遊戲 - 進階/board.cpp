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
