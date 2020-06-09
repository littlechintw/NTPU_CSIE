#include <bits/stdc++.h>
using namespace std;
int main(){
	string text;
	cin >> text;
	int letter[26] = {0};
	int length = text.size();
	for(int i=0;i<length;i++) letter[char(text[i])-97]++;
	for(int i=0;i<26;i++)
		if(letter[i]>0)
			cout << char(97+i) << " " << letter[i] <<endl;
	return 0;
}
