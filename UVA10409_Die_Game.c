// 2019/9/26
// Created by littlechin
// Copyright littlechin. All rights reserved.

#include <stdio.h>
#include <string.h>
int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==0) return 0;
		int up=1,down=6,north=2,south=5,east=4,west=3;
		int i=0;
		for(i=0;i<n;i++){
			char act[10];
			scanf("%s",act);
			if(act[0]=='n'){
				int ss = down;
				down = north;
				north = up;
				up = south;
				south = ss;
			}
			else if(act[0]=='e'){
				int ss = down;
				down = east;
				east = up;
				up = west;
				west = ss;
			}
			else if(act[0]=='s'){
				int ss = down;
				down = south;
				south = up;
				up = north;
				north = ss;
			}
			else if(act[0]=='w'){
				int ss = down;
				down = west;
				west = up;
				up = east;
				east = ss;
			}
		}
		printf("%d\n",up);
	}
	return 0;
}
