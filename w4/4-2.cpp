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

