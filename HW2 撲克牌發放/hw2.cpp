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
