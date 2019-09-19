// 2019/9/19
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<b||(a+b)%2==1||(a-b)%2==1) printf("impossible\n");
		else if(a==b) printf("%d 0\n",a);
		else printf("%d %d\n",((a+b)/2),((a-b)/2));
	}
	return 0;
}
