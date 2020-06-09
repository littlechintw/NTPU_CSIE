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
