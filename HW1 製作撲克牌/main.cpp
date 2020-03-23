#include <bits/stdc++.h>
#include "card.h"
#define RESET "\033[0m"
#define ERROR "\033[31m\033[2m"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    int number,suit;
    cout << "Please fill in the number(1-13)\n> ";
    while(cin>>number){
    	if(number>=1&&number<=13){
    		bool suit_flag = false;
    		while(!suit_flag){
    			cout << "Please fill in the suit\n";
				cout << "1.Spades 2.Hearts 3.Clubs 4.Diamonds\n> ";
				cin >> suit;
				if(suit>=1&&suit<=4){
					suit_flag = true;
					cout << endl;
		    		card new_card(number,suit);
	    			new_card.print_card();
				}
				else cout << ERROR << "Error! The \"suit\" format is uncorrect!\n" << RESET;
			}
		}
		else cout << ERROR << "Error! The \"number\" format is uncorrect!\n" << RESET;
		cout << "Please fill in the number(1-13)\n> ";
	}
	return 0;
}
