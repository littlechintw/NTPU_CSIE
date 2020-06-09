物件導向實習 8
===

# 1. ( 50% ) 本題為上周延伸題，請使用 <vector> :  
Vincent和Leo想邀請他們的朋友參加派對，他們請你寫一程式做到下列功能
(a)	(15%) 從名稱為Vincent.txt的文字檔讀入Vincent他的朋友清單，一行一個朋友。這些名字會儲存在容器(container)內，然後以輸入的順序顯示。
(b)	(15%) 從名稱為Leo.txt的文字檔讀入Leo他的朋友清單，一行一個朋友。這些名字會儲存在第二個容器(container)，然後以輸入的順序顯示。
(c)	(20%) 合併兩個清單，刪除重複者，並將結果放入invitee.txt中，一個朋友一行。


## 使用方式

1. 直接打開 exe 檔案
2. 將自動處理並輸出資料，螢幕亦印出相關資訊

![](https://i.imgur.com/loTNNjS.png)

![](https://i.imgur.com/iIVuMS4.png)


## Source Code 說明

- `1.cpp`
    - (Line 4-5): 宣告`Vincent`和`Leo`的 vector
    - (Line 16-28): 讀取整行 txt 檔案內資訊並存入 vector
    - (Line 30): 宣告`Mix`的 vector
    - (Line 31-44): 判斷`Mix`內是否有重複的參與者，如沒有就加入新的參與者
    - (Line 45-50): 印出相關資訊並存到 `invitee.txt`

## Source Code
`1.cpp`
```c=
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> Vincent;
	vector<string> Leo;
    string Vincent_cin,Leo_cin;
    fstream Vincent_file;
    fstream Leo_file;
    fstream invitee_file;
    Vincent_file.open("Vincent.txt", ios::in);
    Leo_file.open("Leo.txt", ios::in);
    invitee_file.open("invitee.txt", ios::out);
    
    string data_temp;
    
    printf("Vincent's friend:\n-----\n");
    while(getline(Vincent_file,data_temp)){
		cout << data_temp <<endl;
		Vincent.push_back(data_temp);
	}
	printf("-----\n\n");
    
    printf("Leo's friend:\n-----\n");
    while(getline(Leo_file,data_temp)){
		cout << data_temp <<endl;
		Leo.push_back(data_temp);
	}
	printf("-----\n\n");

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
	printf("Invitee:\n-----\n");
	for(int i=0;i<Mix.size();i++){
		cout << Mix[i] << "\n";
		invitee_file << Mix[i] << "\n";
	}
	printf("-----\n");
	return 0;
}
```

# 2. ( 50% ) 寫一程式可執行集合運算 i.e 聯集(Union); 交集(Intersection); 差集(Difference) 
hint: 使用 set_union, set_difference and set_intersection functions
(請至C++ Reference 查看如何使用function)
輸入 :
讓使用者輸入 m & n 分別表示集合A與B的大小，接著再個別輸入A中的m個元素及B中n個元素
輸出 :
		將聯集(A U B)；交集( A & B)；差集(A - B)的結果分別顯示出來

**範例:**
		Input :
請輸入A與B集合的size : 
4 5
請輸入A集合元素 :
1 2 3 4
請輸入B集合元素 :
3 4 5 6 7
Output :
				聯集: 1 2 3 4 5 6 7
交集: 3 4
差集 : 1 2


## 使用方式

1. 輸入 A 與 B 集合的 size
2. 輸入 A 集合元素
3. 輸入 B 集合元素
4. 印出聯集、交集、差集

![](https://i.imgur.com/vbFa4dB.png)



## Source Code 說明

- `2.cpp`
    - (Line 4-5): 宣告`A`和`B`的 set
    - (Line 8-20): 輸入各參數
    - (Line 24-27): 利用`set_union`找`聯集`並印出結果
    - (Line 31-34): 利用`set_intersection`找`交集`並印出結果
    - (Line 38-41): 利用`set_difference`找`差集`並印出結果

## Source Code
`2.cpp`
```c=
#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> A;
    set<int> B;
    int A_num,B_num,cin_temp;
    
    printf("請輸入 A 與 B 集合的 size\n> ");
    cin >> A_num >> B_num;
    
    printf("請輸入 A 集合元素\n> ");
    for(int i=0;i<A_num;i++){
        cin >> cin_temp;
        A.insert(cin_temp);
    }
    printf("請輸入 B 集合元素\n> ");
    for(int i=0;i<B_num;i++){
        cin >> cin_temp;
        B.insert(cin_temp);
    }
    
    set<int> output;
    
    printf("\n聯集: ");
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
    
    output.clear();
        
    printf("\n交集: ");
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
        
    output.clear();
        
    printf("\n差集: ");
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
    	
    printf("\n");
    return 0;
}
```