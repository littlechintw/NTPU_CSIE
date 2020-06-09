#include <bits/stdc++.h>
using namespace std;

class UserData{
	public:
		UserData(int = -1, string = "", double = -1, double = -1);
		void setID(int);
		int getID() const;
		void setName(string);
		string getName() const;
		void setHeight(double);
		double getHeight() const;
		void setWeight(double);
		double getWeight() const;
	private:
		int ID;
		char Name[10];
		double Height;
		double Weight;
};

UserData::UserData(int IDValue,string NameValue,double HeightValue,double WeightValue){
	setID(IDValue);
	setName(NameValue);
	setHeight(HeightValue);
	setWeight(WeightValue);
}

int UserData::getID() const{
	return ID;
} 
void UserData::setID(int IDValue){
	ID = IDValue;
}

string UserData::getName() const{
	return Name;
}
void UserData::setName(string NameString){
	int length = NameString.size();
	length = (length < 10 ? length : 9);
	NameString.copy(Name, length);
	Name[length] = '\0';
}

double UserData::getHeight() const{
	return Height;
}
void UserData::setHeight(double HeightValue){
	Height = HeightValue;
}

double UserData::getWeight() const{
	return Weight;
}
void UserData::setWeight(double WeightValue){
	Weight = WeightValue;
}

int main(){
	ifstream inData("data.dat", ios::in|ios::binary);
	fstream outData;
    outData.open("data.txt", ios::out);
	if(!inData){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	outData << left 
	<< setw(8) << "UserID" 
	<< setw(10) << "Name" 
	<< setw(10) << "Height"
	<< setw(10) << "Weight" << endl;
	cout << left 
	<< setw(8) << "UserID" 
	<< setw(10) << "Name" 
	<< setw(10) << "Height"
	<< setw(10) << "Weight" << endl;
	
	UserData user;
	
	inData.read( reinterpret_cast< char * >(&user),sizeof(UserData));
	
	while(inData && !inData.eof()){
		if(user.getID() != -1){
			outData << left 
			<< setw( 8 ) << user.getID()
			<< setw( 10 ) << user.getName()
			<< setw( 10 ) << user.getHeight()
			<< setw( 10 ) << user.getWeight() << endl;
			cout << left 
			<< setw( 8 ) << user.getID()
			<< setw( 10 ) << user.getName()
			<< setw( 10 ) << user.getHeight()
			<< setw( 10 ) << user.getWeight() << endl;
		}	
		inData.read( reinterpret_cast< char * >(&user),sizeof(UserData));
	}
}
