#include <bits/stdc++.h>
using namespace std;
int main(){
	fstream text_file;
    text_file.open("./text.txt", ios::in);
    fstream output_file;
    output_file.open("./output.txt", ios::out);
    
    vector<string> file_text;
    bool cin_flag = false;
    while(!cin_flag){
    	string text_cin;
    	getline(text_file,text_cin);
    	if(text_cin=="")
    		cin_flag = true;
    	else
    		file_text.push_back(text_cin);
	}
	
    vector<int> num_in_file;
    for(int i=0;i<file_text.size();i++){
    	int temp = 0;
    	for(int j=0;j<file_text[i].size();j++){
    		if(char(file_text[i][j])>='0'&&char(file_text[i][j])<='9'){
    			temp *= 10;
    			temp += int(file_text[i][j]) - int('0');
			}
			else{
				if(temp>0){
					num_in_file.push_back(temp);
					temp = 0;
				}
			}
		}
		if(temp>0)
			num_in_file.push_back(temp);
	}
    
    for(int i=0;i<num_in_file.size();i++)
		cout << num_in_file[i] << " ";
	cout << endl;
	
	sort(num_in_file.begin(),num_in_file.end());
    
    for(int i=0;i<num_in_file.size();i++){
    	cout << num_in_file[i] << " ";
    	output_file << num_in_file[i] << " ";
	}
	cout << endl;
	output_file << endl;
	
	return 0;
}
