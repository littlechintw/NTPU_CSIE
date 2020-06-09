#include <bits/stdc++.h>
#include "ClientData.h"
using namespace std;

void outputLine(ostream &output, const UserData &record){
	output << left << setw(10) << record.getID() << setw(10) << record.getName() << setw(10) << record.getHeight() << setw(10) << record.getWeight() << fixed << showpoint << endl;
}

int main(){
	ifstream inCredit("data.dat", ios::in | ios::binary);
    if(!inCredit){
    	cerr << "File could not be opened." <<endl;
    	exit(1);
	}
	
	cout << left << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Height" << setw(10) << "Weight";
	UserData user;
	inCredit.read(reinterpret_cast<char *>(&user),sizeof(UserData));
	
	while(inCredit&&!inCredit.eof()){
		if(user.getID() != 0 )
			outputLine(cout, user);
	
		inCredit.read(reinterpret_cast<char * >(&user),sizeof(UserData));
	}
}
