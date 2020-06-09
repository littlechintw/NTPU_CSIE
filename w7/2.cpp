#include <bits/stdc++.h>
using namespace std;
int main(){
	while(1){
		vector<vector<int>> table;
		int column, row;
		string data_cin;
		string int_cin_temp;
		printf("input\n");
		printf("column size = ");
		getline(cin,int_cin_temp);
		column = stoi(int_cin_temp);
		printf("   row size = ");
		getline(cin,int_cin_temp);
		row = stoi(int_cin_temp);
		printf("Array data  = ");
	    getline(cin,data_cin);
	    
	    printf("output\n");
	    vector<int> vector_temp;
	    string temp = "";
	    for(int i=0;i<data_cin.size();i++){
	    	if(data_cin[i]==' '){
	    		if(temp!="")
	    			vector_temp.push_back(stoi(temp));
				temp = "";
			}
			else
				temp += data_cin[i];
			if(i==data_cin.size()-1)
				vector_temp.push_back(stoi(temp));
		}
		
		vector<int> save_temp;
		for(int i=0;i<column;i++){
			for(int j=0;j<row;j++)
				save_temp.push_back(vector_temp[i*row+j]);
			table.push_back(save_temp);
			save_temp.clear();
		}
		
		for(int i=0;i<table.size();i++){
	        for(int j=0;j<table[i].size();j++)
	            cout << table[i][j] << " ";
	        printf("\n");
	    }
	    
	    printf("\n");
	}
	return 0;
}

