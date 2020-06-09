#include <bits/stdc++.h>
#ifndef CLIENTDATA_H
#define CLIENTDATA_H
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
#endif
