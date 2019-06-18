#include<iostream>
using namespace std;
class stack
{
public:
int key;
stack *next;
void insert()
{
	cout<<"\n\nInsertion of Link"<<endl;
	cout<<"Enter the Key value: ";
	cin>>key;	
}	
void display()
{
	cout<<key<<endl;
}
};
int main()
{
	stack *top,*node,*ptr;
	int flag=0,ch,count=0,flag1=0,i,max;
	cout<<"Implementing Stack Using Linked List"<<endl;
	do
	{
		cout<<"\n\nOption Menu"<<endl;
		cout<<"1) Creation of Stack"<<endl;
		cout<<"2) Push"<<endl;
		cout<<"3) Pop"<<endl;
		cout<<"4) Peek"<<endl;
		cout<<"5) IsFull"<<endl;
		cout<<"6) IsEmpty"<<endl;
		cout<<"7) Traversal"<<endl;
		cout<<"8) Exit Program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n";
		switch(ch)
		{
			case 1:
				if(flag1==0)
				{
					cout<<"Creation of Stack"<<endl;
					flag1=1;
					node = new stack;
					node->insert();
					node->next=NULL;
					top=node;
					count++;
					cout<<"\nStack is created!! Enter the maximum size of stack you want: ";
					cin>>max;
				}
				else
				{
					cout<<"Stack is already created"<<endl;
				}
				break;
			case 2:
				if(flag1==0)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					if(count==max)
					{
						cout<<"Stack is full! Push is not possible"<<endl;
					}
					else
					{
						node = new stack;
						node->insert();
						node->next=top;
						top=node;
						count++;
					}
				}
				break;
			case 3:
				if(flag1==0)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					if(count==0)
					{
						cout<<"Stack is empty!! Deletion is not possible"<<endl;
					}
					else if(count==1)
					{
						ptr=top;
						top=NULL;
						delete ptr;
						count--;
					}
					else 
					{
						ptr=top;
						top=ptr->next;
						delete ptr;
						count--;
					}
				}
				break;
			case 4:
				if(flag1==0)
				{
					cout<<"Stack is not created!!"<<endl;
				}
				else
				{
					cout<<"Peek => Displaying the Top"<<endl;
					if(count==0)
					{
						cout<<"Stack is empty"<<endl;
					}
					else
					{
						top->display();
					}
				}
				break;
			case 5:
				if(flag1==0)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					if(count==max)
					{
						cout<<"Stack is full"<<endl;
					}
					else
					{
						cout<<"Stack is not full"<<endl;
					}
				}
				break;
			case 6:
				if(flag1==0)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					if(count==0)
					{
						cout<<"Stack is empty"<<endl;
					}
					else
					{
						cout<<"Stack is not empty"<<endl;
					}
				}
				break;
			case 7:
				if(flag1==0)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					cout<<"Stack Traversal"<<endl;
					i=0;
					for(ptr=top;ptr!=NULL;ptr=ptr->next)
					{
						cout<<"Displaying the "<<++i<<" Link of the Stack: ";
						ptr->display();
					}
				}
				break;
			case 8:
				flag=1;
				break;
			default: cout<<"Wrong Choice entered! Exiting the code"<<endl; flag=1;
		}
		cout<<"\n\n";
	}while(flag==0);
	cout<<"Thanks for using the code"<<endl;
}
