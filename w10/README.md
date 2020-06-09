物件導向實習 10
===

# 1. ( 50% ) 上週的延伸題
請將給的 ”text.txt” 檔案做讀入的動作，讓使用者輸入兩個單字，可以印出”text.txt”文件中兩個單字之間全部的單字。

// *text.txt之內容*
```Trust-based recommendation methods assume the additional knowledge of a trust network among users and can better deal with cold start users , since users only need to be simply connected to the trust network .```

![](https://i.imgur.com/DIhwZhH.png)

## 使用方式

1. 輸入兩字串
2. 輸出兩字串間的字串

![](https://i.imgur.com/TII7OD0.png)

## Source Code 說明

- `1.cpp`
    - (Line 4-5): 宣告`text.txt`和`Answer.txt`的檔案處理
    - (Line 11-14): 輸入兩字串以尋找
    - (Line 18-57): 讀取整行 txt 檔案內資訊並切割及尋找開頭的字串，如發現找到開頭文字即輸出字串，當讀取到結尾文字即結束輸出

## Source Code
`1.cpp`
```c=
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
```

# 2. ( 50% )請寫一程式讓使用者以random-access方式儲存class中為單位的資料 (編號、姓名、身高、體重) ，請存成.dat檔
a)class名稱為UserData且含有的資料分別是ID(int型態) Name(char型態，[10])、Height(double型態) Weight(double型態)對應的是編號、姓名、身高、體重
b)建立空白radom-access file的程式請與寫檔的程式合併
c)沒有資料的預設值改為-1、空白file改為10個

建議參考正課ppt 64頁開始的程式碼 (可於附檔下載 )，
![](https://i.imgur.com/6KCT7OC.png)

## 使用方式

1. 輸入欲設定 UserID (如輸入 0 則退出)
2. 輸入姓名身高體重
3. 將資料存進 `data.dat`

![](https://i.imgur.com/VcMHoyb.png)

## Source Code 說明

- `2.cpp`
    - (Line 4-20): 建立名為`UserData`的 class
    - (Line 22-58): 定義`UserData`的 class 的 function
    - (Line 60-72): 輸入 ID 並檢查的 function
    - (Line 79): 開啟檔案
    - (Line 92-107): 輸入 ID 與其他資訊，並存入檔案

## Source Code
`2.cpp`
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

int ID_input_check(){
	int ID;
	cout << "請輸入 UserID (1~10, 0 則離開)\n> ";
	while(true){
		cin >> ID;
		if(ID>=1&&ID<=10) return ID;
		else if(ID==0){
			printf("輸入結束，已建立 data.dat\n");
			return 0;
		}
		else printf("輸入錯誤，請重新輸入\n> ");
	}
}

int main(){
	int ID;
	string Name;
	double Height;
	double Weight;
	fstream outCredit("data.dat", ios::out | ios::binary);
	
	if(!outCredit){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	UserData blank;
    for(int i=0;i<10;i++)
        outCredit.write(reinterpret_cast<const char*>(&blank),sizeof(UserData));
	
	UserData user;
	ID = ID_input_check();
	while(ID>0&&ID<=10){
		cout << "輸入 User Name, Height, Weight\n> ";
		cin >> Name;
		cin >> Height;
		cin >> Weight;
		
		user.setID(ID);
		user.setName(Name);
		user.setHeight(Height);
		user.setWeight(Weight);

		outCredit.seekp((user.getID()-1) * sizeof(UserData));
		outCredit.write(reinterpret_cast<const char *>(&user),sizeof(UserData));

		ID = ID_input_check();
	}
}
```