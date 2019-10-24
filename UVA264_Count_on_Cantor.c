// 2019/10/03
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("TERM %d IS ",n);
		int upn=0,stair=1,inin;
		while(upn < n){
			upn += stair;
			stair++;
		}
		stair--;
		inin = upn - n;
		//printf("\n\nstair:%d\nupn:%d\ninin:%d\n\n",stair,upn,inin);
		if(stair % 2 == 0) printf("%d/%d\n",(stair-inin),(1+inin));
		else printf("%d/%d\n",(1+inin),(stair-inin));
	}
	return 0;
}
