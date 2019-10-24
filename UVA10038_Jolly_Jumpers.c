// 2019/10/24
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include<stdio.h>
int twon (int x,int y){
	int n=x-y;
	if(n>0) return n;
	else return n*(-1);
}
int main(){
	int n,i,fn,sn;
	while(scanf("%d",&n)!=EOF){
		int che[n-1],flag=1;
		for(i=0;i<n-1;i++) che[i]=0;
		scanf("%d",&fn);
		for(i=0;i<n-1;i++){
			scanf("%d",&sn);
			if(flag==1){
				int tt=twon(fn,sn);
				if(tt>n-1||tt<=0) flag=0;
				else{
					if(che[tt-1]==1) flag=0;
					else che[tt-1]=1;
				}
			}
			fn = sn;
		}
		if(flag==0) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	return 0;
}
