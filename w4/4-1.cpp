#include <bits/stdc++.h>
using namespace std;

bool check(string * pointer){
	string ID = *pointer;
	if(ID.size()!=10)
		return false;
	if(char(ID[0])<'A'||char(ID[0])>'Z')
		return false;
	for(int i=1;i<10;i++)
		if(char(ID[i])<'0'||char(ID[i])>'9')
			return false;
	return true;
}

int main(){
	printf("Please Enter an ID Number:");
    string id;
    string * pointer = &id;
    cin >> id;
    cout << "Input:" << *pointer <<endl;
	if(check(pointer)) printf("Correct!");
	else printf("Incorrect!!!!!");
	return 0;
}

