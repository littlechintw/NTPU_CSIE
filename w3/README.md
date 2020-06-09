物件導向實習 3
===

# 1. (40%) 由使用者輸入任意字串，Output中顯示個字母出現的次數。

## 使用方式

1. 輸入字串之後按下 Enter
2. 印出有使用什麼字母及數量

![](https://i.imgur.com/sukwPe4.png)

## Source Code 說明

- (Line 4) `string text;` : 使用 string 宣告
- (Line 6) `int letter[26] = {0};` : 建立一個 array 儲存字母資訊
- (Line 7) `int length = text.size();` : 計算 data 變數的資料字母數量
- (Line 8) `for(int i=0;i<length;i++) letter[char(text[i])-97]++;` : 使用迴圈紀錄字母

## Source Code

```c=
#include <bits/stdc++.h>
using namespace std;
int main(){
	string text;
	cin >> text;
	int letter[26] = {0};
	int length = text.size();
	for(int i=0;i<length;i++) letter[char(text[i])-97]++;
	for(int i=0;i<26;i++)
		if(letter[i]>0)
			cout << char(97+i) << " " << letter[i] <<endl;
	return 0;
}
```

# 2. (60% - 題/12) 建立一個存款(Interest)類別,其資料成員與成員函數如下
(A)定義private資料成員principal、rate、term,分別存放本金、年利率、存款期數 
(B)定義建構子(constructor),並設定所有資料成員的初值principle = 100000、rate = 0.024、term = 12 
\(C\)定義public成員函數set為多載函數，可取得不同傳入參數set(principal)及set(principal, term) 
(D)定義public成員函數amount,計算本利和=本金*(1+年利率/12)的期數次方 
(E)在main程式中撰寫一個驅動程式，設置2個人customerA與costomerB，可輸入customerA的本金與customerB的本金及存款期數，並輸出兩人的本利和

## 使用方式

1. 輸入 customerA 的本金與 customerB 的本金及存款期數
2. 輸出 customerA 與 customerB 的本利和

## Source Code 說明

- (Line 4-12) `class Interest` : 建立一個 class 為 Interest
    - private
        - 有 principal, rate, term 變數，分別為本金、年利率、存款期數
    - public
        - `Interest()` : 宣告時預設動作 (Line 20)
        - `set(double input_principal)` : 設置本金值
        - `set(double input_principal,double input_term)` : 設置本金、存款期數值
        - `amount()` : 計算本利和
- (Line 14-18) `Interest()` : 使用預設值

## Source Code

```c=
#include <bits/stdc++.h>
using namespace std;

class Interest {
	private:
		double principal,rate,term;
	public:
		Interest();
		void set(double input_principal);
		void set(double input_principal,double input_term);
		double amount();
};

Interest::Interest(){
	principal = 100000;
	rate = 0.024;
	term = 12;
}

void Interest::set(double input_principal){
	principal = input_principal;
}

void Interest::set(double input_principal,double input_term){
	principal = input_principal;
	term = input_term;
}

double Interest::amount(){
	double num=principal;
	for(int i=0;i<term;i++) num*=(1+(rate/12));
	return num;
}

int main(){
	int customerA_p;
	int customerB_p,customerB_t;
	Interest a,b;
	cout << "customerA 的本金為\n";
	cin >> customerA_p;
	a.set(customerA_p);
	cout << "customerB 的本金、存款期數為\n";
    cin >> customerB_p >> customerB_t;
    b.set(customerB_p,customerB_t);
    cout << "customerA 的本利和:" << a.amount() <<endl;
    cout << "customerB 的本利和:" << b.amount() <<endl;
	return 0;
}
```