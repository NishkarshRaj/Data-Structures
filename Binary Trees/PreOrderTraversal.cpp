#include<iostream>
using namespace std;
class Tree
{
	public:
	int key;
	Tree *left;
	Tree *right;
	void insert()
	{
		cout<<"Insert: ";
		cin>>key;
	}
	void show()
	{
		cout<<key<<endl;
	}	
};
void print(Tree *node)
{
	if(node==NULL)
	{
		return;
	}
	node->show();
	print(node->left);
	print(node->right);
}
int main()
{
	Tree *root;
	cout<<"Pre Order Traversal of Binary Tree"<<endl;
	cout<<"Enter Integer values when prompted"<<endl;
	root = new Tree;
	root->insert();
	root->left=NULL;
	root->right=NULL;
	root->left = new Tree;
	root->left->insert();
	root->left->left=NULL;
	root->left->right=NULL;
	root->right=new Tree;
	root->right->insert();
	root->right->right=NULL;
	root->right->left=NULL;
	//insertion over
	print(root);
}
