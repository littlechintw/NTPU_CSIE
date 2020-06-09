#include <bits/stdc++.h>
using namespace std;
int main(){
	fstream text_file;
    text_file.open("text.txt", ios::in);
    fstream Answer_file;
    Answer_file.open("Answer.txt", ios::out);
    
    string text_cin;
    getline(text_file,text_cin);
    vector<string> text;
    string temp = "";
    for(int i=0;i<text_cin.size();i++){
    	if(text_cin[i]==' '){
    		if(temp!="")
    			if(temp!=","&&temp!=".")
    				text.push_back(temp);
			temp = "";
		}
		else
			temp += text_cin[i];
		if(i==text_cin.size()-1)
			if(temp!=","&&temp!=".")
				text.push_back(temp);
	}
	
	int temp_num = 1;
	sort(text.begin(), text.end());
	for(int i=0;i<text.size();i++){
		if(i==text.size()-1){
			cout << text[i] << " 有" << temp_num << "個" <<endl;
			Answer_file << text[i] << " 有" << temp_num << "個" <<endl;
		}
		else{
			if(text[i]!=text[i+1]){
				cout << text[i] << " 有" << temp_num << "個" <<endl;
				Answer_file << text[i] << " 有" << temp_num << "個" <<endl;
				temp_num = 1;
			}
			else
				temp_num++;
		}
	}
    
	return 0;
}

