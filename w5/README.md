物件導向實習 5
===

# 1 試參考老師上課提供的二元樹的程式並修改使其功能有 :  **( 100% )**
```
1.1 預設root為50 
    新增節點　 ( 25% ) 
1.2 印出最小值 ( 25% ) 
1.3 印出最大值 ( 25% ) 
1.4 列印目前樹中所有的節點(以Inorder方式呈現) ( 25% ) 
NOTE: 須以二元樹結構存取值，若未設計預防輸入錯誤措施將斟酌扣分！
```

## 使用方式

1. 選擇要使用的行動項目
   - 1: 新增節點 
   - 2: 列印目前的節點(inorder) 
   - 3: 列印最小的node 
   - 4: 列印最大的node 
   - 0: 結束程式
2. 依照行動項目做任何動作
   - 1: 新增節點
       - 即在二元樹中新增節點 
   - 2: 列印目前的節點(inorder)
       - 列印出所有節點並依照小到大排序
   - 3: 列印最小的node
       - 列印出所有節中最小的項目
   - 4: 列印最大的node 
       - 列印出所有節中最大的項目
   - 0: 結束程式
       - 直接結束程式

![](https://i.imgur.com/KFPN3GJ.png)

## Source Code 說明

- `main.cpp`
    - (Line 5): 宣告一個`BiTree`項目為`tree`
    - (Line 15): 判斷輸入行動項目時的正確性
    - (Line 16-29): 判斷要新增的節點資料是否正確，如不正確則請使用者重新填寫，正確即 call `Insert` function 新增節點
    - (Line 30): call `Print` function 列印出所有節點並依照小到大排序
    - (Line 31): call `Print_Min` function 列印出所有節中最小的項目
    - (Line 32): call `Print_Max` function 列印出所有節中最大的項目
    - (Line 33): 直接結束程式
- `BiTree.cpp`
    - (Line 5-7): 預設 root 為 50
    - (Line 42-47): 找到最左邊的 Node (最小) 並列印
    - (Line 49-54): 找到最右邊的 Node (最大) 並列印

## Source Code
`main.cpp`
```c=
#include "Node.cpp"
#include "BiTree.cpp"

int main() {
	BiTree tree;
	while(true){
		printf("請選擇行動項目\n");
		printf("1.新增節點 ");
		printf("2:列印目前的節點(inorder) ");
		printf("3:列印最小的node ");
		printf("4:列印最大的node ");
		printf("0:結束程式\n> ");
		int mode;
		cin >> mode;
		if(mode>=0&&mode<=4){
			if(mode==1){
				bool mode_1_flag = false;
				while(!mode_1_flag){
					printf("請輸入要新增的節點(1~100)\n> ");
					int insert_num;
					cin >> insert_num;
					if(insert_num>=1&&insert_num<=100){
						mode_1_flag = true;
						tree.Insert(insert_num); 
					}
					else
						printf("Error! 請輸入正確的範圍");
				}
			}
			else if(mode==2) tree.Print();
			else if(mode==3) tree.Print_Min();
			else if(mode==4) tree.Print_Max();
			else return 0;
		}
		else printf("Error! 選擇的項目不合法\n");
	}
	return 0;
}
```

`BiTree.h`
```c=
#ifndef BITREE_H
#define BITREE_H

#include "Node.h" 

class BiTree {
	Node *root; 
	void PrintCall(Node*); 
public: 
	BiTree(); 
	void Insert(int); 
	void Print();
	void Print_Min();
	void Print_Max();
};

#endif
```

`BiTree.cpp`
```c=
#include "BiTree.h" 
#include <iostream> 
using namespace std; 

BiTree::BiTree() { 
	root = new Node(50); 
}

void BiTree::Insert(int n) {
	Node *tmp = root; 

	while ( tmp->GetNum() != n ) { 
		if ( tmp->GetNum() < n ) { 
			if ( tmp->GetRight() != NULL ) {
				tmp = tmp->GetRight(); 
			}
			else {
				//tmp = new Node(n);
				tmp->SetRight(new Node(n));
				break;  
			}
		}
		else {
			if ( tmp->GetLeft() != NULL ) {
				tmp = tmp->GetLeft(); 
			}
			else {
				//tmp = new Node(n); 
				tmp->SetLeft(new Node(n));
				break; 
			}
		}
	}	

}

void BiTree::Print() { 
	PrintCall(root); 
	cout << endl; 
}

void BiTree::Print_Min() { 
	Node *tmp = root;
	while(tmp->GetLeft()!=NULL)
		tmp = tmp->GetLeft();
	cout << tmp->GetNum() <<endl;
}

void BiTree::Print_Max() { 
	Node *tmp = root;
	while(tmp->GetRight()!=NULL)
		tmp = tmp->GetRight();
	cout << tmp->GetNum() <<endl; 
}

void BiTree::PrintCall(Node *tmp) { 
	if ( tmp->GetLeft() != NULL ) 
		PrintCall( tmp->GetLeft() );

	cout << tmp->GetNum() << " ";  

	if ( tmp->GetRight() != NULL ) 
		PrintCall( tmp->GetRight() ); 
}
```

`Node.h`
```c=
#ifndef NODE_H 
#define NODE_H

#include <iostream> 
using namespace std; 

class Node {
	int num; 
	Node *left, *right; 
public: 
	Node(int, Node* = NULL, Node* = NULL);
	void SetNum(int);
	int GetNum(); 
	void SetLeft(Node*);
	Node* GetLeft(); 
	void SetRight(Node*);
	Node* GetRight();   
}; 

#endif
```

`Node.cpp`
```c=
#include "Node.h"

Node::Node(int n, Node *l, Node *r) { 
	SetNum(n); 
	SetLeft(l);
	SetRight(r); 
}

void Node::SetNum(int n) { 
	num = n; 
}

int Node::GetNum() {
	return num;
}

void Node::SetLeft(Node *l) { 
	left = l;
}

Node *Node::GetLeft() { 
	return left; 
}

void Node::SetRight(Node *r) { 
	right = r; 
}

Node *Node::GetRight() {
	return right; 
}
```