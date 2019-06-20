#include<iostream>
using namespace std;
int main()
{
	cout<<"Circular Queue Using Arrays"<<endl;
	int max,i,front,rear,flag=0,ch,el;
	cout<<"Enter the maximum size of the Queue you want: ";
	cin>>max;
	cout<<"Enter the starting size of the Queue: ";
	cin>>rear;
	int queue[max];
	for(i=0;i<max;i++)
	{
		queue[i]=0; //signify empty queue~!
	}
	for(i=0;i<rear;i++)
	{
		cout<<"Enter the "<<i+1<<" element of the Queue: ";
		cin>>queue[i];
	}
	front=0;
	do
	{
		cout<<"\n\nOption Menu"<<endl;
		cout<<"1) Enqueue"<<endl;
		cout<<"2) Dequeue"<<endl;
		cout<<"3) Traversal"<<endl;
		cout<<"4) Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				cout<<"Enqueue Operation on Circular Queue\n";
				if(front<rear)
				{
					if(((rear==max)&&(front==0))||rear==front-1)
					{
						cout<<"No more insertions are possible"<<endl;
					}
					else if(rear<max)
					{
						cin>>el;
						queue[++rear]=el;
					}
					else if(front>0)
					{
						cin>>el;
						queue[0]=el;
						rear=0;
					}
				}
				else
				{
					if(rear==front-1)
					{
						cout<<"No more insertion are possible"<<endl;
					}
					else
					{
						cin>>el;
						queue[++rear]=el;
					}
				}
				break;
			case 2:
				cout<<"Dequeue Operation on Circular Queue"<<endl;
				if(front==rear)
				{
					cout<<"Deletion is not possible"<<endl;
				}
				else if(front<rear)
				{
					queue[front]=0;
					front=front+1;
				}
				else if(rear<front)
				{
					if(front==max-1)
					{
						queue[front]=0;
						front=0;
					}
					else
					{
						queue[front]=0;
						front=front+1;
					}
				}
				break;
			case 3:
				cout<<"Traversal of Circular Queue"<<endl;
				cout<<"Front: "<<front<<endl;
				cout<<"Rear: "<<rear<<endl;
				cout<<"Max: "<<max<<endl;
				if(front<=rear)
				{
					for(i=front;i<rear;i++)
					{
						cout<<queue[i]<<"\t";
					}
					cout<<"\n";
				}
				else
				{
					for(i=0;i<=rear;i++)
					{
						cout<<queue[i]<<"\t";
					}
					for(i=front;i<max;i++)
					{
						cout<<queue[i]<<"\t";
					}
					cout<<"\n";
				}
				break;
			case 4:
				flag=1;
				break;
			default: cout<<"Wrong choice entered! Exiting the program"<<endl; flag=1;
		}
	}while(flag==0);
	cout<<"Thankyou for using this program"<<endl;
}
