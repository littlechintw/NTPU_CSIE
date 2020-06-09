#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> Vincent;
	vector<string> Leo;
    string Vincent_cin,Leo_cin;
    
    printf("Vincent's friend: ");
    getline(cin,Vincent_cin);
    
    printf("Leo's friend: ");
    getline(cin,Leo_cin);
    
    string temp = "";
    for(int i=0;i<Vincent_cin.size();i++){
    	if(Vincent_cin[i]==' '){
    		if(temp!="")
    			Vincent.push_back(temp);
			temp = "";
		}
		else
			temp += Vincent_cin[i];
		if(i==Vincent_cin.size()-1)
			Vincent.push_back(temp);
	}
	
	temp = "";
    for(int i=0;i<Leo_cin.size();i++){
    	if(Leo_cin[i]==' '){
    		if(temp!="")
    			Leo.push_back(temp);
			temp = "";
		}
		else
			temp += Leo_cin[i];
		if(i==Leo_cin.size()-1)
			Leo.push_back(temp);
	}

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
	printf("Invitee: ");
	for(int i=0;i<Mix.size();i++)
		cout << Mix[i] << " ";
	printf("\n");
	system("pause");
	return 0;
}

