#include<iostream>
#include <bits/stdc++.h> //Standard CPP Library
using namespace std;
int main()
{
	int flag=0,ch,i,flag1=0,n,arr[100],flag2,el,pos;
	for(i=0;i<100;i++)
	{
		arr[i]=0; //initializing the array to default value
	}
	cout<<"Code for Array Data Structure"<<endl;
	do
	{
		cout<<"Option Menu\n\n";
		cout<<"1) Creation of Array"<<endl;
		cout<<"2) Insertion of element in the array"<<endl;
		cout<<"3) Deletion of element in the array"<<endl;
		cout<<"4) Searching an element in the array"<<endl;
		cout<<"5) Sorting the array in Ascending Order"<<endl;
		cout<<"6) Sorting the array in Descending Order"<<endl;
		cout<<"7) Display the array"<<endl;
		cout<<"8) Exit the Program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n\n";
		switch(ch)
		{
			case 1:
				if(flag1==0)
				{
					flag1=1;
					cout<<"Creation of Array"<<endl;
					cout<<"Enter the size of the array you want to create :";
					cin>>n;
					for(i=0;i<n;i++)
					{
						cout<<"Enter the "<<i+1<<" element of the array: ";
						cin>>arr[i];
					}
				}
				else
				{
					cout<<"Array is already created!"<<endl;
				}
				break;
			case 2:
				if(flag1==0)
				{
					cout<<"Array not created and Insertion not possible!"<<endl;
				}
				else if(n==99)
				{
					cout<<"Array is full and no more insertion is possible"<<endl;
				}
				else
				{
					cout<<"Insertion in the array!"<<endl;
					cout<<"Enter the position where you want to insert an element: ";
					cin>>pos;
					if(pos<0)
					{
						cout<<"Underflow Error"<<endl;
					}
					else if(pos>99)
					{
						cout<<"Overflow Error"<<endl;
					}
					else
					{
						pos = pos-1; //Position is index + 1
						cout<<"Insertion is possible!"<<endl;
						cout<<"Enter the element you want to insert: ";
						cin>>el;
						if(pos>=n)
						{
							arr[pos]=el;
						}
						else
						{
							//insertion between already created array elements
							for(i=n-1;i>=pos;i--)
							{
								arr[i+1]=arr[i];
							}
							arr[pos]=el;
						}
						n++;
					}
				}
				break;
			case 3:
				if(flag1==0)
				{
					cout<<"Array not created and deletion not possible"<<endl;
				}
				else
				{
					cout<<"Deletion of Element from the Array"<<endl;
					cout<<"Enter the position from which you want to delete the array element: ";
					cin>>pos;
					pos=pos-1;
					if((pos<0)||(pos>=n))
					{
						cout<<"No element exists at the given position and thus deletion is not possible"<<endl;
					}
					else
					{
						arr[pos]=0;
					}
				}
				break;
			case 4:
				if(flag1==0)
				{
					cout<<"Array has not been created and thus searching is not possible!"<<endl;
				}
				else
				{
					flag2=0;
					cout<<"Searching for an element in the array"<<endl;
					cout<<"Enter the element you want to search in the array: ";
					cin>>el;
					for(i=0;i<n;i++)
					{
						if(arr[i]==el)
						{
							flag2=i+1;
							break;
						}
					}
					if(flag2==0)
					{
						cout<<"Element not found"<<endl;
					}
					else
					{
						cout<<"Element found at "<<flag2<<" position!"<<endl;
					}
				}
				break;
			case 5:
				if(flag1==0)
				{
					cout<<"Array not created and thus sorting is not possible"<<endl;
				}
				else
				{
					sort(arr,arr+n); //Using inbuilt sort function of CPP library
				}
				break;
			case 6:
				if(flag1==0)
				{
					cout<<"Array not created and thus sorting is not possible"<<endl;
				}
				else
				{
					sort(arr,arr+n,greater<int>()); //Using inbuilt sort function of CPP library
				}
				break;
			case 7:
				if(flag1==0)
				{
					cout<<"Array is not created and thus cannot be displayed!"<<endl;
				}
				else
				{
					cout<<"Displaying the array\n\n";
					for(i=0;i<n;i++)
					{
						cout<<"The "<<i+1<<" element of the array is: "<<arr[i]<<endl;
					}
				}
				break;
			case 8: flag =1;
				break;
			default: cout<<"Wrong Choice Entered!! Exiting the program"; flag = 1;
		}
		cout<<"\n\n\n";
	}while(flag!=1);
	cout<<"Thank You for using this program!";
}
