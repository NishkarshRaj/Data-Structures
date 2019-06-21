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
int height(Tree *node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
    	int lheight,rheight;
    	lheight = height(node->left);  
        rheight = height(node->right);  
        if (lheight > rheight)
		{
			return(lheight + 1);
		}   
        else return(rheight + 1);  
    }  
}
void printGivenLevel(Tree *root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        root->show();  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  
void printLevelOrder(Tree *root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
    printGivenLevel(root, i);  
}  
int main()
{
	Tree *root;
	cout<<"Breadth First Traversal of Binary Tree"<<endl;
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
	printLevelOrder(root);
}
