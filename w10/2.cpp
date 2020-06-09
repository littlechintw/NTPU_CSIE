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

int ID_input_check(){
	int ID;
	cout << "請輸入 UserID (1~10, 0 則離開)\n> ";
	while(true){
		cin >> ID;
		if(ID>=1&&ID<=10) return ID;
		else if(ID==0){
			printf("輸入結束，已建立 data.dat\n");
			return 0;
		}
		else printf("輸入錯誤，請重新輸入\n> ");
	}
}

int main(){
	int ID;
	string Name;
	double Height;
	double Weight;
	fstream outCredit("data.dat", ios::out | ios::binary);
	
	if(!outCredit){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	UserData blank;
    for(int i=0;i<10;i++)
        outCredit.write(reinterpret_cast<const char*>(&blank),sizeof(UserData));
	
	UserData user;
	ID = ID_input_check();
	while(ID>0&&ID<=10){
		cout << "輸入 User Name, Height, Weight\n> ";
		cin >> Name;
		cin >> Height;
		cin >> Weight;
		
		user.setID(ID);
		user.setName(Name);
		user.setHeight(Height);
		user.setWeight(Weight);

		outCredit.seekp((user.getID()-1) * sizeof(UserData));
		outCredit.write(reinterpret_cast<const char *>(&user),sizeof(UserData));

		ID = ID_input_check();
	}
}
