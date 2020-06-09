物件導向實習 4
===

# 1. (40%) 寫一C++程式，檢查Taiwan身分證號碼(10碼)是否正確。
a) 定義一個check函數，接收呼叫敘述傳遞的字串指標參數，然後檢查號碼是否正確，最後回傳true或false給呼叫敘述。 

b) 在main函數中，定義一個字串指標，由鍵盤輸入依身分證號碼並存入指標位址，然後呼叫並傳遞字串指標給check函數，取得true或false後輸出號碼是否正確

## 使用方式

1. 輸入字串之後按下 Enter
2. 印出輸入的值與正確性

![](https://i.imgur.com/rGwcg0E.png)

![](https://i.imgur.com/GLvLCtb.png)

![](https://i.imgur.com/ndq9ioD.png)


## Source Code 說明

- (Line 4) `bool check(string * pointer)` : 接收呼叫敘述傳遞的字串指標參數
- (Line 5-13): 然後檢查號碼是否正確
- (Line 22-23): 傳遞字串指標給check函數，並判斷是否正確

## Source Code

```c=
#include <bits/stdc++.h>
using namespace std;

bool check(string * pointer){
	string ID = *pointer;
	if(ID.size()!=10)
		return false;
	if(char(ID[0])<'A'||char(ID[0])>'Z')
		return false;
	for(int i=1;i<10;i++)
		if(char(ID[i])<'0'||char(ID[i])>'9')
			return false;
	return true;
}

int main(){
	printf("Please Enter an ID Number:");
    string id;
    string * pointer = &id;
    cin >> id;
    cout << "Input:" << *pointer <<endl;
	if(check(pointer)) printf("Correct!");
	else printf("Incorrect!!!!!");
	return 0;
}
```

# 2. (60%) 請製作一個簡易Project，分別使用「標頭檔、實作檔、主程式檔」三個檔案，讓使用者輸入的24小時制時間能套用成12小時制的時間格式(a.m./p.m,) (各20%)
a) Time.h (標頭檔)： 
宣告名為 TIME 的類別 
定義private資料成員  Hour、Minute、Second分別存放時、分、秒。 
定義建構函數(constructor) 
定義public成員函數 setTime與showTime 

b) Time.cpp (實作檔)： 
實作建構函數(constructor)，並設定所有資料成員的初值為0。 
實作setTime函數，需可輸入3個整數參數時(0~23)、分(0~59)、秒(0~59) 
實作showTime函數，可顯示12小時制時間 

c) main.cpp (主程式檔)： 
需求如附圖範例，需顯示以下資訊： 
設定新時間、顯示新時間，若有預防輸入錯誤措施及連續輸入功能更好。


## 使用方式

1. 印出初始時間
2. 持續設定新時間，如發生錯誤即顯示

![](https://i.imgur.com/IRJzAWy.png)

## Source Code 說明

- `main.cpp`
    - (Line 5) `TIME clock;` : 宣告 clock 為 TIME 物件
    - (Line 10-18): 可連續更新時間，如遇到輸入錯誤會提示並重新輸入
- `Time.h`
    - (Line 4-11) `class TIME` : 建立一個 class 為 TIME
        - private
            - 有 Hour、Minute、Second 變數，分別存放時、分、秒
        - public
            - `TIME()` : 宣告時預設動作
            - `bool setTime(int H,int M,int S)
` : 判斷格式是否正確並設定
            - `void   showTime();` : 印出時間
- `Time.cpp`
    
    - (Line 4-8) `TIME::TIME()
` : 使用預設值
    - (Line 10-17) `bool TIME::setTime(int H,int M,int S)` : 判斷格式是否正確並設定
    - (Line 19-24) `void TIME::showTime()` : 印出時間

## Source Code

`main.cpp`
```c=
#include <bits/stdc++.h>
#include "Time.cpp"
using namespace std;
int main(){
	TIME clock;
	printf("初始時間：");
	clock.showTime();
	printf("\n請設定時間：\n");
	int h,m,s;
    while(cin >> h >> m >> s){
    	if(clock.setTime(h,m,s)){
    		printf("設定的時間為：");
    		clock.showTime();
		}
		else
			printf("錯誤！設定的時間有誤");
		printf("\n請設定時間：\n");
	}
	return 0;
}

```

`Time.h`
```c=
#include <bits/stdc++.h>
using namespace std;

class TIME {
	private:
		int Hour, Minute, Second;
	public:
		TIME();
		bool setTime(int H,int M,int S);
		void showTime();
};
```

`Time.cpp`
```c=
#include "Time.h"
using namespace std;

TIME::TIME(){
	Hour = 0;
	Minute = 0;
	Second = 0;
}

bool TIME::setTime(int H,int M,int S){
	if(H<0||H>23) return false;
	if(M<0||M>59) return false;
	if(S<0||S>59) return false;
	Hour = H;
	Minute = M;
	Second = S;
}

void TIME::showTime(){
	if(Hour<12)
		printf("%02d:%02d:%02dAM",Hour,Minute,Second);
	else
		printf("%02d:%02d:%02dPM",Hour-12,Minute,Second);
}
```