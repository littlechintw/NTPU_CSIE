物件導向實習 11
===

# 1. ( 50% ) 上週的延伸題
請寫一個程式能夠讀取上週練習程式所產生的dat檔，將有存取過的欄位資料輸出成txt 檔，如下圖！

![](https://i.imgur.com/HMFzVOQ.png)

## 使用方式

1. 直接打開程式，將自動讀取/輸出

![](https://i.imgur.com/psDT2aW.png)

![](https://i.imgur.com/7I0BV56.png)

## Source Code 說明

- `1.cpp`
    - (Line 4-20): 建立名為`UserData`的 class
    - (Line 22-58): 定義`UserData`的 class 的 function
    - (Line 61-63): 開啟 binary 與 txt 檔
    - (Line 68-77): 寫入並印出第一行欄位
    - (Line 81-97): 讀取資料並判斷 ID 欄位，最後寫入並印出資料

## Source Code
`1.cpp`
```c=
#include <bits/stdc++.h>
using namespace std;

class UserData{
	public:
		UserData(int = -1, string = "", double = -1, double = -1);
		void setID(int);
		int getID() const;
		void setName(string);
		string getName() const;
		void setHeight(double);
		double getHeight() const;
		void setWeight(double);
		double getWeight() const;
	private:
		int ID;
		char Name[10];
		double Height;
		double Weight;
};

UserData::UserData(int IDValue,string NameValue,double HeightValue,double WeightValue){
	setID(IDValue);
	setName(NameValue);
	setHeight(HeightValue);
	setWeight(WeightValue);
}

int UserData::getID() const{
	return ID;
} 
void UserData::setID(int IDValue){
	ID = IDValue;
}

string UserData::getName() const{
	return Name;
}
void UserData::setName(string NameString){
	int length = NameString.size();
	length = (length < 10 ? length : 9);
	NameString.copy(Name, length);
	Name[length] = '\0';
}

double UserData::getHeight() const{
	return Height;
}
void UserData::setHeight(double HeightValue){
	Height = HeightValue;
}

double UserData::getWeight() const{
	return Weight;
}
void UserData::setWeight(double WeightValue){
	Weight = WeightValue;
}

int main(){
	ifstream inData("data.dat", ios::in|ios::binary);
	fstream outData;
    outData.open("data.txt", ios::out);
	if (!inData){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	outData << left 
	<< setw(8) << "UserID" 
	<< setw(10) << "Name" 
	<< setw(10) << "Height"
	<< setw(10) << "Weight" << endl;
	cout << left 
	<< setw(8) << "UserID" 
	<< setw(10) << "Name" 
	<< setw(10) << "Height"
	<< setw(10) << "Weight" << endl;
	
	UserData user;
	
	inData.read( reinterpret_cast< char * >(&user),sizeof(UserData));
	
	while(inData && !inData.eof()){
		if(user.getID() != -1){
			outData << left 
			<< setw( 8 ) << user.getID()
			<< setw( 10 ) << user.getName()
			<< setw( 10 ) << user.getHeight()
			<< setw( 10 ) << user.getWeight() << endl;
			cout << left 
			<< setw( 8 ) << user.getID()
			<< setw( 10 ) << user.getName()
			<< setw( 10 ) << user.getHeight()
			<< setw( 10 ) << user.getWeight() << endl;
		}	
		inData.read( reinterpret_cast< char * >(&user),sizeof(UserData));
	}
}
```

# 2. ( 50% ) (注意:請使用friend的方式寫程式)
必X客請你們幫忙寫出一個程式能讓消費者選擇pizza餅皮(芝心、薄脆、鬆厚)、大小(大、中、小)、配料(鳳梨、玉米、起司、蟹肉條、番茄、青椒、臘肉、火腿、牛肉)，並算出Pizza最終價格，其中，小的為300元，中的為420元，大的為510元，配料為每個30元。

(1) 須讓消費者依序輸入餅皮、大小、配料，實際範例參考附圖。
(2) 其中配料須讓消費者重複輸入不同配料，輸入0視為結束配料選擇。若輸入重複配料則必須發出錯誤訊息並重新詢問。

![](https://i.imgur.com/0CiEY7I.png)

![](https://i.imgur.com/v7JbgVU.png)


## 使用方式

1. 選擇餅皮 (錯誤輸入判斷)
![](https://i.imgur.com/SYQrCAa.png)

2. 選擇大小 (錯誤輸入判斷)
![](https://i.imgur.com/ZmJsu9C.png)

3. 選擇配料 (錯誤、重複輸入判斷)
![](https://i.imgur.com/51mtOPq.png)

4. 印出結果
![](https://i.imgur.com/KRzMN5j.png)



## Source Code 說明

- `2.cpp`
    - (Line 16-41): 建立名為`Pizza`的 class
        - (Line 21-25): 利用`friend`連接函數
    - (Line 43-47): 判斷配料是否已用過
    - (Line 49-62): 將數值寫進`Pizza`的 class
    - (Line 64-97): 將 Pizza 最後結果呈現
    - (Line 99-147): 輸入 Pizza 的相關資訊，並輸出最後結果

## Source Code
`2.cpp`
```c=
#include <bits/stdc++.h>
using namespace std;

class Pizza;
bool compare(Pizza&, int);
void set_cake_crust(Pizza&, int);
void set_size(Pizza&, int);
bool set_ingredients(Pizza&, int);
void show_pizza(Pizza&, int);
string ingredients_name[9] = {
	"鳳梨",   "玉米", "起司",
	"蟹肉條", "番茄", "青椒",
	"臘肉",   "火腿", "牛肉"
};

class Pizza{
	public:
		Pizza(int input_cake_crust){
			cake_crust = input_cake_crust;
		};
		friend bool compare(Pizza&, int);
		friend void set_cake_crust(Pizza&, int);
		friend void set_size(Pizza&, int);
		friend bool set_ingredients(Pizza&, int);
		friend void show_pizza(Pizza&, int);
		int get_cake_crust(){
			return cake_crust;
		};
		int get_size(){
			return size;
		};
		int get_ingredients(int n){
			if(n>=0&&n<=8)
				return ingredients[n];
			return -1;
		};
	private:
		int cake_crust;
		int size;
		int ingredients[9] = {0};
};

bool compare(Pizza& the_pizza, int ingredients){
	if(the_pizza.ingredients[ingredients-1]==0)
		return true;
	else return false;
}

void set_cake_crust(Pizza& the_pizza, int cake_crust){
	the_pizza.cake_crust = cake_crust;
}

void set_size(Pizza& the_pizza, int size){
	the_pizza.size = size;
}

bool set_ingredients(Pizza& the_pizza, int ingredients){
	if(compare(the_pizza, ingredients)){
		the_pizza.ingredients[ingredients-1] = 1;
	}
	else printf("這個配料選過了，請重新選擇!\n");
}

void show_pizza(Pizza& the_pizza){
	printf("你的 Pizza :\n");
	int prize = 0;
	printf("餅皮: ");
	if(the_pizza.get_cake_crust() == 1) printf("芝心\n");
	else if(the_pizza.get_cake_crust() == 2) printf("薄脆\n");
	else if(the_pizza.get_cake_crust() == 3) printf("鬆厚\n");
	printf("大小: ");
	if(the_pizza.get_size() == 1){
		prize += 300;
		printf("小\n");
	} 
	else if(the_pizza.get_size() == 2){
		prize += 420;
		printf("中\n");
	}
	else if(the_pizza.get_size() == 3){
		prize += 510;
		printf("大\n");
	}
	printf("配料: ");
	int ingredients_flag = 0;
	for(int i=0;i<9;i++){
		if(the_pizza.get_ingredients(i) == 1){
			prize += 30;
			if(ingredients_flag==0)
				cout << ingredients_name[i];
			else
				cout << " & " << ingredients_name[i];
			ingredients_flag++;
		}
	}
	printf("\n\n你的 Pizza 價格: $%d\n謝謝惠顧!!\n", prize);
}

int main(){
	printf("選擇 Pizza 餅皮:\n");
    printf("1. 芝心\n");
    printf("2. 薄脆\n");
    printf("3. 鬆厚\n");
    bool input_flag = true;
    int input;
	while(input_flag){
    	printf("> ");
    	cin >> input;
    	if(input>=1&&input<=3)
    		input_flag = false;
    	else printf("輸入錯誤，請重新輸入!\n");
	}
	Pizza a_pizza(input);
	
	printf("選擇 Pizza 大小:\n");
    printf("1. 小\n");
    printf("2. 中\n");
    printf("3. 大\n");
    input_flag = true;
	while(input_flag){
    	printf("> ");
    	cin >> input;
    	if(input>=1&&input<=3)
    		input_flag = false;
    	else printf("輸入錯誤，請重新輸入!\n");
	}
	set_size(a_pizza,input);
	
	printf("選擇 Pizza 配料:\n");
	for(int i=0;i<9;i++){
		printf("%d. ",i+1);
		cout << ingredients_name[i] <<endl;
	}
	input_flag = true;
	while(input_flag){
    	printf("> ");
    	cin >> input;
    	if(input>=0&&input<=9){
    		if(input==0) input_flag = false;
    		else set_ingredients(a_pizza,input);
		}
    	else printf("輸入錯誤，請重新輸入!\n");
	}
	
	show_pizza(a_pizza);
	return 0;
}

```