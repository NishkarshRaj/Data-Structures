#include<iostream>
using namespace std;
int main()
{
	int max,n,i,flag=0,ch,top=-1;
	cout<<"Implementing Stacks using Arrays"<<endl;
	cout<<"Enter the Max Size of the Array: ";
	cin>>max;
	int stack[max];
	for(i=0;i<max;i++)
	{
		stack[i]=0;
	}
	do
	{
		cout<<"\n\n";
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Stack"<<endl;
		cout<<"2) Push"<<endl;
		cout<<"3) Pop"<<endl;
		cout<<"4) Peek"<<endl;
		cout<<"5) Traversal"<<endl;
		cout<<"6) Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n";
		switch(ch)
		{
			case 1:
				if(top==-1)
				{
					cout<<"Creation of Stack"<<endl;
					cout<<"Enter the number of elements you want: ";
					cin>>n;
					if(n<0)
					{
						cout<<"Number of elements cannot be negative"<<endl;
					}
					else if(n>max)
					{
						cout<<"Overflow Error"<<endl;
					}
					else
					{
						for(i=0;i<n;i++)
						{
							cout<<"Enter Element: ";
							cin>>stack[i];
						}
						top=n-1;
					}
				}
				else
				{
					cout<<"Stack is already created!!"<<endl;
				}
				break;
			case 2:
				if(top==-1)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					cout<<"Push => Insertion at top"<<endl;
					if(n==max)
					{
						cout<<"Stack is full and push is not possible"<<endl;
					}
					else
					{
						cout<<"Enter element: ";
						cin>>stack[n];
						n++;
						top=n-1;
					}
				}
				break;
			case 3:	
				if(top==-1)
				{
					cout<<"Stack is not created!!"<<endl;
				}
				else
				{
					if(n==0)
					{
						cout<<"Stack is empty"<<endl;
					}
					else if(n==1)
					{
						stack[n-1]=0;
						n--;
						top=0;
					}
					else
					{
						stack[n-1]=0;
						n--;
						top=n-1;
					}
				}
				break;
			case 4:
				if(top==-1)
				{
					cout<<"Stack is not created"<<endl;
				}
				else
				{
					if(n==0)
					{
						cout<<"Stack is empty"<<endl;
					}
					else
					{
						cout<<stack[top];
					}
				}
				break;
			case 5:
				if(top==-1)
				{
					cout<<"Stack is not created!!"<<endl;	
				}
				else if(top==0)
				{
					cout<<"Stack is empty"<<endl;
				}
				else
				{
					cout<<"Traversal of Stack\n"<<endl;
					for(i=top;i>=0;i--)
					{
						cout<<stack[i]<<endl;
					}
				}
				break;
			case 6:
				flag=1;
				break;
			default: cout<<"Wrong Choice! Exiting the program"<<endl; flag=1; 
		}
	}while(flag==0);
}
