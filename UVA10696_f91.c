// 2019/9/18
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==0) return 0;
		printf("f91(%d) = %d\n",n,f91(n));
	}
}

int f91(int n){
	if(n<=100) return (f91(f91(n+11)));
	else return (n-10);
}
