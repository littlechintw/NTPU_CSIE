// 2019/9/19
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int all=0;
		while(n>=3){
			all += (n/3)*3;
			n = n/3+n%3;
		}
		if(n==2) all++;
		all += n;
		printf("%d\n",all);
	}
	return 0;
}
