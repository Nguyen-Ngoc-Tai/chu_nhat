#include <iostream>
using namespace std;

//tao cay nhi phan
struct tNode{
	int data;
	tNode *pLeft, *pRight;
};

tNode *root;

//tao cay nhi phan rong
void createEmptyTree(){
	root = NULL;
}

//tao nut moi
tNode *newNode(int data){
	tNode *node = new tNode;
	if(node==NULL){//khong the cap phat bo nho
		exit(1);
	}else{
		node->data = data;
		node->pLeft = NULL;
		node->pRight = NULL;
	}
	return node;
}

//them 1 nut moi vao cay
tNode *insertNode(tNode *node, int value){
	if(node!=NULL){
		if(node->data == value){
			return node;
		}else if(node->data > value){
			node->pLeft = insertNode(node->pLeft, value);
		}else{
			node->pRight = insertNode(node->pRight, value);
		}
	}else{
		node = newNode(value);
	}
	return node;
}

void NLR(tNode *root){
	if(root!=NULL){
		if(root!=NULL){
			cout<<root->data<<" ";
		}
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

//Tim kiem nut theo de quy
tNode *searchNodeByRecursion(tNode *root, int x){
	if(root != NULL ){
		if(root->data == x){
			return root;
		}
		if(root->data > x){
			return searchNodeByRecursion(root->pLeft,x);
		}else{
			return searchNodeByRecursion(root->pRight,x);
		}
	}
	return NULL;
}

//Tim kiem nut khong co de quy
tNode *searchNodeWithoutRecursion(tNode *root, int x){
	tNode *p=root;
	while(p != NULL){
		if(p->data == x){
			return p;
		}else if(p->data > x){
			p = p->pLeft;
		}else{
			p = p->pRight;
		}
	}
	return NULL;
}

//Tim nut co khoa nho nhat
tNode *minValueNode(tNode *node){
	tNode *current = node;
	while(current && current->pLeft != NULL){
		current = current->pLeft;
	}
	return current;
}

//Tim nut co khoa lon nhat
tNode *maxValueNode(tNode *node){
	tNode *current = node; 
	while (current && current->pRight == NULL){
		current = current->pRight;
	}
	return current;
}

//Xoa nut
tNode *deleteNode(tNode *root, int x){
	if(root == NULL){
		return root;
	}
	if(root->data > x){
		root->pLeft = deleteNode(root->pLeft, x);
	}else if(root->data < x){
		root->pRight = deleteNode(root->pRight, x);
	}else{
		tNode *p = root;
		if(root->pLeft == NULL){
			root=root->pRight;
			delete p;
		}else if(root->pRight== NULL){
			root=root->pLeft;
			delete p;
		}else{
			tNode *temp = minValueNode(root->pRight);
			root->data = temp->data;
			root->pRight = deleteNode(root->pRight, temp->data);
		}
	}
	return root;
}
//Giai phong cay
tNode *MakeEmpty(tNode *root){
	if(root){
		MakeEmpty(root->pRight);
			MakeEmpty(root->pLeft);
			delete root;
	}
}

int main()
{
	//tao cay nhi phan tim kiem
	createEmptyTree();
	root = insertNode(root, 8);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 6);
	root = insertNode(root, 7);
	root = insertNode(root, 10);
	root = insertNode(root, 14);
	root = insertNode(root, 4);
	cout<<"Cay ngang voi NLR:";
	NLR(root);
	tNode *temp = searchNodeWithoutRecursion(root, 10);
	if(temp!=NULL){
		cout<<endl<<"Tim x=10";
	}else{
		cout<<endl<<"Khong tim duoc x=10";
	}
	root = deleteNode(root, 3);
	cout<<endl<<"Duyet cay voi nut NLR sau khi xoa nut:";
	NLR(root);
	system("pause");
}