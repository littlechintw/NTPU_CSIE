#include <bits/stdc++.h>
using namespace std;
void print_it(int n[2][3]){
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout << "\t" << n[i][j];
		}
		cout << endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int a[2][3]={4,7,-1,2,9,7},b[2][3]={6,6,0,2,5,6};
    cout << "A =" <<endl;
    print_it(a);
    cout << "B =" <<endl;
    print_it(b);
    cout << "A + B =" <<endl;
    int c[2][3];
    for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
			c[i][j] = a[i][j] + b[i][j];
	print_it(c);
	return 0;
}

