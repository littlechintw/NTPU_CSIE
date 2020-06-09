物件導向實習 9
===

# 1. ( 100% ) 印出每個單字所出現的次數。
請將給定的”text.txt”檔案做讀入的動作，並將檔案中所出現的英文單字做整理，然後印出單字個別出現的次數，最後將統計結果輸出至”Answer.txt”中。

// *text.txt之內容*
```Trust-based recommendation methods assume the additional knowledge of a trust network among users and can better deal with cold start users , since users only need to be simply connected to the trust network .```

![](https://i.imgur.com/VLw4skI.png)


## 使用方式

1. 直接打開 exe 檔案
2. 將自動處理並輸出資料，螢幕亦印出相關資訊

![](https://i.imgur.com/9345WQq.png)

![](https://i.imgur.com/1sKROkb.png)


## Source Code 說明

- `1.cpp`
    - (Line 4-7): 宣告`text.txt`和`Answer.txt`的檔案處理
    - (Line 10-25): 讀取整行 txt 檔案內資訊並切割存入`text`的 vector
    - (Line 28): 對 vector 做 sort (排序)
    - (Line 29-43): 按順序輸出並處理、計算重複的單字
        - (Line 32, 37): 印出相關資訊並存到 `Answer.txt`

## Source Code
`1.cpp`
```c=
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

```