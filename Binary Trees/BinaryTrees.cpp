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
		cout<<"Enter an Integer: ";
		cin>>key;
	}
	void show()
	{
		cout<<key<<"\t\t";
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
    {
        root->show();  
	}
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
void Inorder(Tree *node)
{
	if(node==NULL)
	{
		return;
	}
	Inorder(node->left);
	node->show();
	Inorder(node->right);
}
void Preorder(Tree *node)
{
	if(node==NULL)
	{
		return;
	}
	node->show();
	Preorder(node->left);
	Preorder(node->right);
}
void Postorder(Tree *node)
{
	if(node==NULL)
	{
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	node->show();
}
Tree *search(Tree *node,int el)
{
	if(node==NULL)
	{
		return NULL;
	}
	search(node->left,el);
	search(node->right,el);
	if(node->key==el)
	{
		//cout<<node->key;
		return node;
	}
}
int main()
{
	Tree *root=NULL,*node,*ptr;
	int ch,flag=0,el,fleg,ch1;
	cout<<"Binary Tree General Code";
	do
	{
		cout<<"\n\nOption Menu"<<endl;
		cout<<"1) Creation of Tree"<<endl;
		cout<<"2) Insertion"<<endl;
		cout<<"3) Inorder Traversal"<<endl;
		cout<<"4) Pre Order Traversal"<<endl;
		cout<<"5) Post Order Traversal"<<endl;
		cout<<"6) Level Order Traversal"<<endl;
		cout<<"7) Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				if(root==NULL)
				{
					cout<<"Creation of Root of Tree"<<endl;
					root = new Tree;
					root->insert();
					root->left=NULL;
					root->right=NULL;
				}
				else
				{
					cout<<"Tree is already created!!"<<endl;
				}
				break;
			case 2:
				if(root==NULL)
				{
					cout<<"Tree does not exists"<<endl;
				}
				else
				{
					cout<<"Insertion in Binary Tree"<<endl;
					cout<<"Enter the element after which you want to perform insertion: ";
					cin>>el;
					node = search(root,el);
					node->show();
					if(node==NULL)
					{
						cout<<"Cannot find the element in the Tree"<<endl;
					}
					else //if(node->key==el)
					{
						cout<<"Ready for insertion"<<endl;
						fleg=0;
						if((node->left==NULL)&&(node->right==NULL))
						{
							fleg=1;	//can insert to both left and right
						}
						else if((node->left==NULL)&&(node->right!=NULL))
						{
							fleg=2; //insert to left only
						}
						else if((node->left!=NULL)&&(node->right==NULL))
						{
							fleg=3; //insert to right only
						}
						else if((node->left!=NULL)&&(node->right!=NULL))
						{
							fleg=4; //cannot insert
						}
						if(fleg==0)
						{
							cout<<"Cannot insert due to unforeseen circumstances"<<endl;
						}
						else if(fleg==1)
						{
							cout<<"Can insert to both left and right position"<<endl;
							cout<<"Enter which position you want to insert (1 for left/2 for right): ";
							cin>>ch1;
							if(ch1==1)
							{
								cout<<"Insertion at left"<<endl;
							ptr=new Tree;
							ptr->insert();
							ptr->left=NULL;
							ptr->right=NULL;
							node->left=ptr;
							}
							else if(ch1==2)
							{
								cout<<"Insertion at right"<<endl;
							ptr=new Tree;
							ptr->insert();
							ptr->left=NULL;
							ptr->right=NULL;
							node->right=ptr;
							}
							else
							{
								cout<<"Wrong Choice entered!! Cannot insert"<<endl;
							}
						}
						else if(fleg==2)
						{
							cout<<"Insertion at Left"<<endl;
							ptr=new Tree;
							ptr->insert();
							ptr->left=NULL;
							ptr->right=NULL;
							node->left=ptr;
						}
						else if(fleg==3)
						{
							cout<<"Insertion at right"<<endl;
							ptr=new Tree;
							ptr->insert();
							ptr->left=NULL;
							ptr->right=NULL;
							node->right=ptr;
						}
						else if(fleg==4)
						{
							cout<<"Cannot insert as the current node has both childs present"<<endl;
						}
					}
				}
				break;
			case 3:
				if(root==NULL)
				{
					cout<<"Tree does not exists"<<endl;
				}
				else
				{
					cout<<"Inorder Tree Traversal\n\n";
					Inorder(root);
				}
				break;
			case 4:
				if(root==NULL)
				{
					cout<<"Tree does not exist"<<endl;
				}
				else
				{
					cout<<"Pre Order Tree Traversal\n\n";
					Preorder(root);
				}
				break;
			case 5:
				if(root==NULL)
				{
					cout<<"Tree does not exist"<<endl;
				}
				else
				{
					cout<<"Post order Tree Traversal\n\n";
					Postorder(root);
				}
				break;
			case 6:
				if(root==NULL)
				{
					cout<<"Tree does not exist"<<endl;
				}
				else
				{
					cout<<"Level Order Tree Traversal\n\n";
					printLevelOrder(root);
				}
				break;
			case 7:
				flag=1;
				break;
			default: cout<<"Wrong choice entered!! Exiting the program"<<endl; flag=1;
		}
		
	}while(flag==0);
	cout<<"Thank you for using the code"<<endl;
}

