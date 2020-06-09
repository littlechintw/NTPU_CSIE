物件導向實習 7
===

# 1. ( 50% ) 請使用<vector> :  
Vincent和Leo想邀請他們的朋友參加派對，他們請你寫一程式做到下列功能
    - (a)	(15%) 讓 Vincent 輸入他朋友的名字清單。這些名字會儲存在容器(container)內,然後以排序的順序顯示。 
    - (b)	(15%) 讓 Leo 輸入他朋友的名字清單。這些名字會儲存在第二個容器(container), 然後以排序的順序顯示。 
    - (c)	(20%) 建立第三個容器(container)合併前兩個清單,刪除重複者並顯示此容器 (container)的內容。

範例：
```
Input: Vincent’s friend : Mary  John  Trump   Elizabeth 
        Leo ‘s friend : John  Tim   Annabel  Leonardo 
Output : Invitee : Mary John Trump Elizabeth Tim Annabel Leonardo
```


## 使用方式

1. 輸入 Vincent 的朋友
2. 輸入 Leo 的朋友
3. 印出所有參加者

![](https://i.imgur.com/6li6jtx.png)


## Source Code 說明

- `1.cpp`
    - (Line 4-5): 宣告`Vincent`和`Leo`的 vector
    - (Line 9,12): 使用 getline 讀取整行
    - (Line 14-38): 將輸入的單行文字做整理，並存入 vector
    - (Line 40): 宣告`Mix`的 vector
    - (Line 41-54): 判斷`Mix`內是否有重複的參與者，如沒有就加入新的參與者

## Source Code
`1.cpp`
```c=
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> Vincent;
	vector<string> Leo;
    string Vincent_cin,Leo_cin;
    
    printf("Vincent's friend: ");
    getline(cin,Vincent_cin);
    
    printf("Leo's friend: ");
    getline(cin,Leo_cin);
    
    string temp = "";
    for(int i=0;i<Vincent_cin.size();i++){
    	if(Vincent_cin[i]==' '){
    		if(temp!="")
    			Vincent.push_back(temp);
			temp = "";
		}
		else
			temp += Vincent_cin[i];
		if(i==Vincent_cin.size()-1)
			Vincent.push_back(temp);
	}
	
	temp = "";
    for(int i=0;i<Leo_cin.size();i++){
    	if(Leo_cin[i]==' '){
    		if(temp!="")
    			Leo.push_back(temp);
			temp = "";
		}
		else
			temp += Leo_cin[i];
		if(i==Leo_cin.size()-1)
			Leo.push_back(temp);
	}

	vector<string> Mix;
	for(int i=0;i<Vincent.size();i++){
		bool flag = true;
		for(int j=0;j<Mix.size();j++)
			if(Mix[j]==Vincent[i]) flag = false;
		if(flag)
			Mix.push_back(Vincent[i]);
	}
	for(int i=0;i<Leo.size();i++){
		bool flag = true;
		for(int j=0;j<Mix.size();j++)
			if(Mix[j]==Leo[i]) flag = false;
		if(flag)
			Mix.push_back(Leo[i]);
	}
	printf("Invitee: ");
	for(int i=0;i<Mix.size();i++)
		cout << Mix[i] << " ";
	printf("\n");
	return 0;
}
```

# 2. ( 50% ) 請使用vector實作時做出動態的二維陣列，可輸入指定的行數、列數及值，格式如以下範例圖。
![](https://i.imgur.com/EOlywBH.png)

## 使用方式

1. 輸入 column size、row size、Array data
2. 印出二維陣列
3. 輸入下一筆資料

![](https://i.imgur.com/kjpKWLN.png)


## Source Code 說明

- `2.cpp`
    - (Line 5): 宣告`table`的 vector 二維陣列
    - (Line 6-17): 使用 getline 讀取整行，並處理資料，且發現 cin 與 getline 並用時會發生錯誤
    - (Line 20-32): 將輸入的單行文字做整理，並存入暫存的 vector
    - (Line 34-40): 存入`table`的 vector 二維陣列
    - (Line 42-46): 印出二維陣列

## Source Code
`2.cpp`
```c=
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
```