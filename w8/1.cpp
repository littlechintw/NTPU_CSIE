#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> Vincent;
	vector<string> Leo;
    string Vincent_cin,Leo_cin;
    fstream Vincent_file;
    fstream Leo_file;
    fstream invitee_file;
    Vincent_file.open("Vincent.txt", ios::in);
    Leo_file.open("Leo.txt", ios::in);
    invitee_file.open("invitee.txt", ios::out);
    
    string data_temp;
    
    printf("Vincent's friend:\n-----\n");
    while(getline(Vincent_file,data_temp)){
		cout << data_temp <<endl;
		Vincent.push_back(data_temp);
	}
	printf("-----\n\n");
    
    printf("Leo's friend:\n-----\n");
    while(getline(Leo_file,data_temp)){
		cout << data_temp <<endl;
		Leo.push_back(data_temp);
	}
	printf("-----\n\n");

	vector<string> Mix;
	for(int i=0;i<Vincent.size();i++){
		bool flag = true;
		for(int j=0;j<Mix.size();j++)
			if(Mix[j]==Vincent[i]) flag = false;
		if(flag)
			Mix.push_back(Vincent[i]);
	}
	for(int i=0;i<Leo.size();i++){
		bool flag = true;
		for(int j=0;j<Mix.size();j++)
			if(Mix[j]==Leo[i]) flag = false;
		if(flag)
			Mix.push_back(Leo[i]);
	}
	printf("Invitee:\n-----\n");
	for(int i=0;i<Mix.size();i++){
		cout << Mix[i] << "\n";
		invitee_file << Mix[i] << "\n";
	}
	printf("-----\n");
	return 0;
}

