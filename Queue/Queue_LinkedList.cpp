#include<iostream>
using namespace std;
class linkedlist
{
	public:
		int key;
		char value;
		string name;
		linkedlist *next;
		linkedlist()
		{
			key=0;
			value='a';
			name="Name";
		}
		void insertion()
		{
			cout<<"Enter the Key value of Link: ";
			cin>>key;
			cout<<"Enter the Character value of the Link: ";
			cin>>value;
			cout<<"Enter the name of the Link: ";
			cin.ignore(); //This is used because of switching from normal data type to string the first switch does not count because of linefeed
			getline(cin,name);
		}
		void display()
		{
			cout<<"Key value of the Link is: "<<key<<endl;
			cout<<"Value of the Link is: "<<value<<endl;
			cout<<"Name of the Link is: "<<name<<endl;
		}
};
int main()
{
	linkedlist *node,*ptr,*front,*p,*rear;
	int flag=0,flag1=0,ch,count=0,travel,pos,d,max; //count counts the total number of links created till now
	cout<<"Queue (FIFO) Application Using the Linked List Structure"<<endl;
	do
	{
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Queue"<<endl;
		cout<<"2) Enqueue"<<endl;
		cout<<"3) Dequeue"<<endl;
		cout<<"4) IsFull"<<endl;
		cout<<"5) IsEmpty"<<endl;
		cout<<"6) Peek"<<endl;
		cout<<"7) Traversal of Queue"<<endl;
		cout<<"8) Exit the program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n";
		switch(ch)
		{
			case 1:
				if(flag1!=0)
				{
					cout<<"Linked List already created!"<<endl;
				}
				else
				{
					cout<<"Creation of Queue\n\n";
					cout<<"Create the first node of the Linked List\n";
					flag1 = 1;
					node = new linkedlist;
					node->insertion();
					node->next=NULL;
					front=node;
					rear=node;
					count++;
					cout<<"\n\nQueue Is created!!!"<<endl;
					cout<<"Enter the Max Size of Queue: ";
					cin>>max;
				}
				break;
			case 2:
				if(flag1==0)
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					cout<<"Insertion of link at the end of the list"<<endl;
					node = new linkedlist;
					node->insertion();
					node->next=NULL;
					rear->next = node;
					count++;
				}
				break;
			case 3:
				if(flag1==0)
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					cout<<"Deletion from beginning"<<endl;
					ptr = front;
					front = ptr->next;
					delete ptr;
					count--;
				}
				break;
			case 4:
				if(flag1==0)
				{
					cout<<"Queue not created!!";
				}
				else
				{
					cout<<"Check for Is Full for Queue"<<endl;
					if(count==max)
					{
						cout<<"Queue is Full"<<endl;
					}
					else
					{
						cout<<"Queue is not full"<<endl;
					}
				}
				break;
			case 5:
				if(flag1 == 0)
				{
					cout<<"Queue is not created"<<endl;
				}
				else
				{
					cout<<"Check for Queue is Empty?"<<endl;
					if(count==0)
					{
						cout<<"Queue is empty"<<endl;
					}
					else
					{
						cout<<"Queue is not empty"<<endl;
					}
				}
				break;
			case 6:
				if(flag1 == 0)
				{
					cout<<"Queue is not created\n";
				}
				else
				{
					cout<<"Displaying the Front of Queue!"<<endl;
					front->display();
				}
				break;
			case 7: 
				if(flag1==0)
				{
					cout<<"Queue not created!"<<endl;
				}
				else
				{
					cout<<"Linked List Traversal\n\n";
					travel=0;
					for(ptr=front;ptr!=NULL;ptr=ptr->next)
					{
						cout<<++travel<<" Link of the List is\n";
						ptr->display();
						cout<<"\n";
					}
				}
				break;
			case 8:
				flag = 1;
				break;
			default: cout<<"Wrong choice Entered!! Exiting program"; flag=1;
		}
		cout<<"\n\n";
	}while(flag!=1);
	cout<<"\nThank you for using the program"<<endl;
}
