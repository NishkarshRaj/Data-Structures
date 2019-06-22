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
/*
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
*/
int main()
{
	Tree *root=NULL,*node,*ptr;
	int ch,flag=0,el,fleg,arr[100],i,ch1;
	//arr 100 contains a level order representation of elements of tree
	//left child on nth key is 2n+1
	//right child of nth key is 2n+2
	//0 value of array means node is NULL currently
	//Initializing the array
	for(i=0;i<100;i++)
	{
		arr[i]=0;
	}
	Tree *p[100]; //creating pointers for all the possible nodes!! overhead i know but solves the problem effectively
	for(i=0;i<100;i++)
	{
		p[i]=NULL;
	}
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
					arr[0]=root->key;
					//cout<<arr[0];
					p[0]=root;
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
					cout<<"Insertion in the Tree"<<endl;
					cout<<"Enter the element whose child you want to insert: ";
					cin>>el;
					fleg=-1;
					for(i=0;i<100;i++)
					{
						if(arr[i]==el)
						{
							fleg=i;
							break;
						}
					}
					if(fleg==(-1))
					{
						cout<<"Element does not exist in the tree!\nCannot perform Insertion!"<<endl;
					}
					else
					{
						cout<<"Element Found!\nChecking for empty child nodes\n";
						if((p[i]->left==NULL)&&(p[i]->right==NULL))
						{
							cout<<"Both the nodes are empty! Enter 1 for left and 2 for right: ";
							cin>>ch1;
							if(ch1==1)
							{
								cout<<"Insertion at Left"<<endl;
								node = new Tree;
								node->insert();
								node->left=NULL;
								node->right=NULL;
								p[i]->left=node;
								p[(2*i)+1]=node;
								arr[(2*i)+1]=node->key;
							}
							else if(ch1==2)
							{
								cout<<"Insertion at Right"<<endl;
								node = new Tree;
								node->insert();
								node->left=NULL;
								node->right=NULL;
								p[i]->right=node;
								p[(2*i)+2]=node;
								arr[(2*i)+2]=node->key;
							}
							else
							{
								cout<<"Invalid Choice! Cannot insert\n";
							}
						}
						else if((p[i]->left==NULL)&&(p[i]->right!=NULL))
						{
							cout<<"Insertion at Left"<<endl;
							node = new Tree;
							node->insert();
							node->left=NULL;
							node->right=NULL;
							p[i]->left=node;
							p[(2*i)+1]=node;
							arr[(2*i)+1]=node->key;
						}
						else if((p[i]->left!=NULL)&&(p[i]->right==NULL))
						{
							cout<<"Insertion at Right"<<endl;
							node = new Tree;
							node->insert();
							node->left=NULL;
							node->right=NULL;
							p[i]->right=node;
							p[(2*i)+2]=node;
							arr[(2*i)+2]=node->key;
						}
						else if((p[i]->left!=NULL)&&(p[i]->right!=NULL))
						{
							cout<<"Both children exists and Insertion is not possible\n";
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

