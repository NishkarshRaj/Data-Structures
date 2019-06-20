#include<iostream>
using namespace std;
class Queue
{
	public:
	int key;
	Queue *next;
	void insert()
	{
		cin>>key;
	}
	void show()
	{
		cout<<key;
	}
};
int main()
{
	Queue *node,*ptr,*front=NULL,*rear=NULL;
	int flag=0,ch,count=0,travel;
	cout<<"Circular Queue";
	do
	{
		cout<<"\n\n";
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Circular Queue"<<endl;
		cout<<"2) Enqueue"<<endl;
		cout<<"3) Dequeue"<<endl;
		cout<<"4) Traversal"<<endl;
		cout<<"5) Exit Program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				if(front==NULL)
				{
					cout<<"Creation of Circular Queue"<<endl;
					node = new Queue;
					node->insert();
					front=node;
					rear=node;
					rear->next=front;
					count++;
				}
				else
				{
					cout<<"Circular Queue is already created!!"<<endl;
				}
				break;
			case 2:
				if(front!=NULL)
				{
					//insertion at last!!!
					cout<<"Enqueue => Insertion at Last"<<endl;
					node = new Queue;
					node->insert();
					rear->next=node;
					node->next=front;
					rear=node;
					count++;
				}
				else
				{
					cout<<"Before Insertion! Please create a Circular Queue!!\n";
				}
				break;
			case 3:
				if(front!=NULL)
				{
					cout<<"Dequeue operation"<<endl;
					ptr=front;
					front=ptr->next;
					rear->next=front;
					delete ptr;
					count--;
				}
				else
				{
					cout<<"Cannot Dequeue"<<endl;
				}
				break;
			case 4:
				if(front!=NULL)
				{
					travel=count;
					cout<<"Traversal of Circular Queue\n\n";
					ptr=front;
					while(travel--)
					{
						ptr->show();
						ptr=ptr->next; 
						cout<<"\t";
					}
				}
				else
				{
					cout<<"Cannot traverse Queue because it is either empty or not created yet!!"<<endl;
				}
				break;
			case 5:
				flag=1;
				break;
			default: cout<<"Wrong choice entered!! Exiting the code"<<endl; flag=1;
		}
	}while(flag==0);
	cout<<"Thankyou for using this program"<<endl;
}
