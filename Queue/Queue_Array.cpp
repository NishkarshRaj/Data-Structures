#include<iostream>
using namespace std;
int main()
{
	int max,front=-1,rear=-1,i,flag=0,ch,n;
	cout<<"General Queue Implementation using Arrays"<<endl;
	cout<<"Enter the maximum size of the Queue you want: ";
	cin>>max;
	int que[max];
	for(i=0;i<max;i++)
	{
		que[i]=0;
	}
	do
	{
		cout<<"\n\n";
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Queue"<<endl;
		cout<<"2) Enqueue"<<endl;
		cout<<"3) Deque"<<endl;
		cout<<"4) Peek"<<endl;
		cout<<"5) Traversal"<<endl;
		cout<<"6) Exit the program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n";
		switch(ch)
		{
			case 1:
				if(front==(-1))
				{
					cout<<"Creation of Queue"<<endl;
					cout<<"Enter the number of elements you want in the queue: ";
					cin>>n;
					if((n<=max)&&(n>0))
					{
						for(i=0;i<n;i++)
						{
							cout<<"Enter the "<<i+1<<" element of the Queue: "<<endl;
							cin>>que[i];
						}
						front=0;
						rear=n-1;
					}
					else if(n>max)
					{
						cout<<"Overflow Error!!"<<endl;
					}
					else
					{
						cout<<"Error Encountered! Insertion not possible!"<<endl;
					}
				}
				else
				{
					cout<<"Queue is already created!"<<endl;
				}
				break;
			case 2:
				if(front==(-1))
				{
					cout<<"Queue is not not created!!!";
				}
				else
				{
					cout<<"Enqueue => Insertion at last"<<endl;
					if(n == max)
					{
						cout<<"Queue is full! No insertion possible"<<endl;
					}
					else if(n<max)
					{
						cout<<"Enter the element you want to insert: ";
						cin>>que[n];
						n++;
						rear=n-1;
					}
				}
				break;
			case 3:
				if(front==(-1))
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					cout<<"Dequeue Operation => Deletion at beginning"<<endl;
					if(n==0)
					{
						cout<<"Queue is empty! No deletion possible"<<endl;
					}
					else
					{
						for(i=0;i<n-1;i++)
						{
							que[i]=que[i+1];
						}
						que[n-1]=0;
						n--;
						rear=n-1;
					}
				}	
				break;
			case 4:
				if(front==(-1))
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					if(n==0)
					{
						cout<<"Queue is empty! Nothing to peek"<<endl;
					}
					else
					{
						cout<<que[0];
					}
				}
				break;
			case 5:
				if(front==(-1))
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					cout<<"Traversal of the Queue"<<endl;
					for(i=0;i<n;i++)
					{
						cout<<i+1<<" Element of the queue is: "<<que[i]<<endl;
					}
				}
				break;
			case 6:
				flag = 1;
			 	break;
			default: cout<<"Wrong Value inserted"<<endl;
			flag=1;
		}
	}while(flag!=1);
	cout<<"Thank you for using this code!";
}
