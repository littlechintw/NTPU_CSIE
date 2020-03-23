#include <bits/stdc++.h>
using namespace std;
int prime_factor_lower(int n){
	if(n==1||n==0) return 0;
	for(int i=2;i<=n;i++){
		if(n%i==0) return i;
	}
	return -1;
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//    cout.tie(0);
    
    for(;;){
    	cout << "請輸入數字:";
    	int num;
    	cin >> num;
    	if(num==0) return 0;
    	cout << num << "的質因數分解為";
    	int array_max = num+1;
    	int check[array_max]={0};
    	while(prime_factor_lower(num)){
    		int n = prime_factor_lower(num);
    		check[n]++;
    		num /= n;
		}
		int flag = 0;
		for(int i=0;i<array_max;i++){
//			cout << i << ": " << check[i] <<endl;
//			cout << "-" << flag++ <<endl;
			if(check[i]>1){
				if(flag==0){
					cout << i << "^" << check[i];
					flag=1;
				}
				else cout << "*" << i << "^" << check[i];
			}
			else if(check[i]==1){
				if(flag==0){
					cout << i;
					flag=1;
				}
				else cout << "*" << i;
			}
		}
		cout << endl << endl;
	}
    
	 
	return 0;
}

