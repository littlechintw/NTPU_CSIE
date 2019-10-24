// 2019/10/17
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include<iostream>
using namespace std;
void binary(int &sum, int n){
	if(n){
		binary(sum,n / 2);
		cout << (n & 1);
		sum += (n & 1);
	}
}
int main(){
	int n;
	while(cin >> n && n){
		int sum = 0;
		cout << "The parity of ";
		binary(sum, n);
		cout << " is " << sum << " (mod 2)." <<endl;
	}
	return 0;
}
