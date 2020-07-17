物件導向實習 12
===

# 1. ( 100% ) 
建立一個text.txt的文字檔案，其內容為英數字交雜的無序碼。
請寫一個程式，該程式可以過濾text.txt檔的非數字字元，並將檔案中的數字由小到大排序，再將結果顯示出來並儲存至output.txt檔案中。
(請用相對路徑讀寫資料！)
(給大家測試資料以方便大家複製 : //測試時可能會改text.txt內容 
Asdf j213k as kfjas 932kk s8aklsd 823kjds
we23f s9ddf 89rgwes asss8
)

![](https://i.imgur.com/4Hhgj7I.png)
![](https://i.imgur.com/ZNPRNlb.png)
![](https://i.imgur.com/QJ4wkTy.png)

## 使用方式

1. 直接打開程式，將自動讀取/輸出

![](https://i.imgur.com/DZrosGE.png)

![](https://i.imgur.com/v6bPnco.png)


## Source Code 說明

- `1.cpp`
    - (Line 4-7): 宣告`text.txt`與`output.txt`的檔案處理
    - (Line 9-18): 利用迴圈將檔案內所有資料讀出並存入`file_text`的`vector`裡
    - (Line 20-37): 利用迴圈逐行逐字確認是否為數字，找到數字後，找尋下一個非數字，之後將數字存入`num_in_file`的`vector`裡
    - (Line 39-50): 輸出結果、排序、輸出排序後結果並存入`output.txt`

## Source Code
`1.cpp`
```c=
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
```