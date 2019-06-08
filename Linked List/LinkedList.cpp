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
	linkedlist *node,*ptr,*start,*p;
	int flag=0,flag1=0,ch,travel,pos,count=0,d; //count counts the total number of links created till now
	cout<<"Basic Single Linked List Code"<<endl;
	do
	{
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Linked List"<<endl;
		cout<<"2) Insertion at beginning"<<endl;
		cout<<"3) Insertion at the End"<<endl;
		cout<<"4) Insertion at any point"<<endl;
		cout<<"5) Deletion from beginning"<<endl;
		cout<<"6) Deletion from end"<<endl;
		cout<<"7) Deletion from any point"<<endl;
		cout<<"8) Traversal of Linked List"<<endl;
		cout<<"9) Exit the program"<<endl;
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
					cout<<"Creation of Linked List\n\n";
					cout<<"Create the first node of the Linked List\n";
					flag1 = 1;
					node = new linkedlist;
					node->insertion();
					node->next=NULL;
					start=node;
					count++;
				}
				break;
			case 2:
				if(flag1==0)
				{
					cout<<"Linked list is not created!!"<<endl;
				}
				else
				{
					cout<<"Insertion at beginning"<<endl;
					node = new linkedlist;
					node->insertion();
					node->next=start;
					start=node;
					count++;
				}
				break;
			case 3:
				if(flag1==0)
				{
					cout<<"Linked list is not created"<<endl;
				}
				else
				{
					cout<<"Insertion of link at the end of the list"<<endl;
					node = new linkedlist;
					node->insertion();
					node->next=NULL;
					for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
					ptr->next=node;
					count++;
				}
				break;
			case 4:
				if(flag1==0)
				{
					cout<<"Linked list is not created!"<<endl;
				}
				else
				{
					cout<<"Insertion at any point"<<endl;
					cout<<"Enter the position where you want to insert the link: ";
					cin>>pos;
					if(pos<1)
					{
						cout<<"Insertion not possible due to underflow"<<endl;
					}
					else if(pos>(count+1))
					{
						cout<<"Insertion not possible due to overflow";
					}
					else if(pos==1)
					{
						//insertion at beginning
						node = new linkedlist;
						node->insertion();
						node->next=start;
						start=node;
						count++;
					}
					else if(pos==count+1)
					{
						//insertion at end
						node = new linkedlist;
						node->insertion();
						node->next=NULL;
						for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
						ptr->next=node;
						count++;
					}
					else
					{
						d=1;
						for(ptr=start;d<pos-1;ptr=ptr->next)
						{
							d++;
						}
						node = new linkedlist;
						node->insertion();
						node->next=ptr->next;
						ptr->next=node;
						count++;
					}
				}
				break;
			case 5:
				if(flag1==0)
				{
					cout<<"Linked list is not created"<<endl;
				}
				else
				{
					cout<<"Deletion from beginning"<<endl;
					ptr = start;
					start = ptr->next;
					delete ptr;
					count--;
				}
				break;
			case 6:
				if(flag1==0)
				{
					cout<<"Linked list is not created\n";
				}
				else
				{
					for(ptr=start;ptr->next!=NULL;p=ptr,ptr=ptr->next);
					p->next=NULL;
					delete ptr;
					count--;
				}
				break;
			case 7:
				if(flag1==0)
				{
					cout<<"Linked List is not created"<<endl;
				}
				else
				{
					cout<<"Deletion at any point"<<endl;
					cout<<"Enter the position where you want to delete the node: ";
					cin>>pos;
					if(pos<1)
					{
						cout<<"Deletion impossible because of underflow"<<endl;
					}
					else if(pos>count)
					{
						cout<<"Deletion impossible due to overflow"<<endl;
					}
					else if(pos==1)
					{
						//deletion from beginning
						ptr = start;
						start = ptr->next;
						delete ptr;
						count--;
					}
					else if(pos == count)
					{
						//deletion from end
						for(ptr=start;ptr->next!=NULL;p=ptr,ptr=ptr->next);
						p->next=NULL;
						delete ptr;
						count--;
					}
					else
					{
						ptr=start;
						pos--;
						while(pos--)
						{
							p=ptr;
							ptr=ptr->next;
						}
						p->next=ptr->next;
						delete ptr;
						count--;
					}
				}
				break;
			case 8: 
				if(flag1==0)
				{
					cout<<"Linked List not created!"<<endl;
				}
				else
				{
					cout<<"Linked List Traversal\n\n";
					travel=0;
					for(ptr=start;ptr!=NULL;ptr=ptr->next)
					{
						cout<<++travel<<" Link of the List is\n";
						ptr->display();
						cout<<"\n";
					}
				}
				break;
			case 9:
				flag = 1;
				break;
			default: cout<<"Wrong choice Entered!! Exiting program"; flag=1;
		}
		cout<<"\n\n";
	}while(flag!=1);
	cout<<"\nThank you for using the program"<<endl;
}
