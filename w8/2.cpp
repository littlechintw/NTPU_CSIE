#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> A;
    set<int> B;
    int A_num,B_num,cin_temp;
    
    printf("請輸入 A 與 B 集合的 size\n> ");
    cin >> A_num >> B_num;
    
    printf("請輸入 A 集合元素\n> ");
    for(int i=0;i<A_num;i++){
        cin >> cin_temp;
        A.insert(cin_temp);
    }
    printf("請輸入 B 集合元素\n> ");
    for(int i=0;i<B_num;i++){
        cin >> cin_temp;
        B.insert(cin_temp);
    }
    
    set<int> output;
    
    printf("\n聯集: ");
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
    
    output.clear();
        
    printf("\n交集: ");
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
        
    output.clear();
        
    printf("\n差集: ");
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(output, output.begin()));
    for(set<int>::iterator i=output.begin(); i!=output.end(); i++)
    	cout << *i << " ";
    	
    printf("\n");
    return 0;
}
