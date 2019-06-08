#include<iostream>
using namespace std;
int main()
{
	int flag=0,ch,n,i,max,flag1=0,el,pos;
	cout<<"Array Implementation of Linked List"<<endl;
	cout<<"Enter the max size of array you want to use: ";
	cin>>max;
	int arr[max];
	for(i=0;i<max;i++)
	{
		arr[i] = 0;
	}
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
				if(flag1==0)
				{
					cout<<"Creation of Linked List"<<endl;
					cout<<"Enter the number of elements you want in the Linked List: ";
					cin>>n;
					if(n<=max)
					{
						flag1=1;
						for(i=0;i<n;i++)
						{
							cout<<"Enter the "<<i+1<<" element of the linked list: ";
							cin>>arr[i];
						}
					}
					else
					{
						cout<<"Linked List not created because size provided exceeds the max size\n";
					}
				}
				else
				{
					cout<<"Linked List is already created!!";
				}
				break;
			case 2:
				if(flag1==0)
				{
					cout<<"Linked List not created\n";
				}
				else if(n==max)
				{
					cout<<"Linked list is full and Insertion is not possible";
				}
				else
				{
					cout<<"Insertion at the first index"<<endl;
					for(i=n-1;i>=0;i--)
					{
						arr[i+1]=arr[i];
					}
					cout<<"Enter the element you want to insert: ";
					cin>>el;
					arr[0]=el;
					n++;
				}
				break;
			case 3:
				if(flag1==0)
				{
					cout<<"Linked List not created\n";
				}
				else if(n==max)
				{
					cout<<"Linked list is full and Insertion is not possible";
				}
				else
				{
					cout<<"Insertion at the Last index"<<endl;
					cout<<"Enter the element you want to insert: ";
					cin>>el;
					arr[n]=el;
					n++;
				}
				break;
			case 4:
				if(flag1==0)
				{
					cout<<"Linked List not created\n";
				}
				else if(n==max)
				{
					cout<<"Linked list is full and Insertion is not possible";
				}
				else
				{
					cout<<"Insertion at the any index"<<endl;
					cout<<"Enter the position where you want to insert the value: ";
					cin>>pos;
					pos=pos-1;
					if(pos<0)
					{
						cout<<"Under Flow"<<endl;
					}
					if(pos>=max-1)
					{
						cout<<"Over Flow"<<endl;
					}
					else if(pos>=n)
					{
						cout<<"Enter the element you want to insert: ";
						cin>>el;
						arr[pos]=el;
						n=pos+1;
					}
					else
					{
						for(i=n-1;i>=pos-1;i--)
						{
							arr[i+1]=arr[i];
						}
						cout<<"Enter the element you want to insert: ";
						cin>>el;
						arr[pos]=el;
						n++;
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
					for(i=1;i<n;i++)
					{
					arr[i-1]=arr[i];
					}
					arr[n-1]=0;
					n--;
				}
				break;
			case 6:
				if(flag1==0)
				{
					cout<<"Linked list is not created"<<endl;
				}
				else
				{
					arr[n-1]=0;
					n--;
				}
				break;
			case 7:
				if(flag1==0)
				{
					cout<<"Linked list is not created"<<endl;
				}
				else
				{
					cout<<"Enter the position of deletion: ";
					cin>>pos;
					if(pos<0)
					{
						cout<<"Under flow Error! Deletion not possible\n";
					}
					else if(pos>n-1)
					{
						cout<<"Overflow Error! Deletion not possible";
					}
					else
					{
						for(i=pos;i<n;i++)
						{
							arr[i-1]=arr[i];
						}
						arr[n-1]=0;
						n--;
					}
				}
				break;
			case 8:
				if(flag1==0)
				{
					cout<<"Linked list not created!"<<endl;
				}
				else
				{
					cout<<"Linked List Traversal\n\n";
					for(i=0;i<n;i++)
					{
						cout<<"The "<<i+1<<" element of the array is: "<<arr[i]<<endl;
					}
				}
				break;
			case 9: flag = 1;
				break;
			default: cout<<"Wrong Choice entered! Exiting the program"<<endl; flag=1;
		}
		cout<<"\n\n";
	}while(flag==0);
	cout<<"Thank you for using the program!"<<endl;
}
