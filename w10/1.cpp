#include <bits/stdc++.h>
using namespace std;
int main(){
	fstream text_file;
    text_file.open("text.txt", ios::in);
    
    string text_cin;
    getline(text_file,text_cin);
    string temp = "";
    
    string t_start,t_end;
    printf("請輸入要尋找的單字\n> ");
    cin >> t_start >> t_end;
    cout << t_start << " 與 " << t_end << " 之間全部的字串\n";
    
    bool flag = false;
    
    for(int i=0;i<text_cin.size();i++){
    	if(text_cin[i]==' '){
    		if(temp!="")
    			if(temp!=","&&temp!="."){
    				if(flag){
    					cout << temp << " ";
    					if(temp==t_end){
    						flag = false;
    						break;
						}
					}
    				else{
    					if(temp==t_start){
							cout << temp << " ";
							flag = true;
						} 
					}
				}
			temp = "";
		}
		else
			temp += text_cin[i];
		if(i==text_cin.size()-1){
			if(temp!=","&&temp!="."){
				if(flag){
					cout << temp << " ";
					if(temp==t_end){
						flag = false;
						break;
					}
				}
				else{
					if(temp==t_start){
						cout << temp << " ";
						flag = true;
					} 
				}
			}
		}
	}
	return 0;
}

