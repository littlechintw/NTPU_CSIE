// 2019/9/12
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		int mix;
		scanf("%d %d",&x,&y);
		if(x%2==0){
			x+=1;
		}
		if(y%2==0){
			y-=1;
		}
		mix = (x+y)*((y-x)/2+1)/2;
		printf("Case %d: %d\n",i+1,mix);
	}
}
