#include <bits/stdc++.h>
#include "ClientData.h"
using namespace std;
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
