#include<iostream>
using namespace std;
int main()
{
	int r1,c1,i,j,r2,c2,flag,k;
	cout<<"Matrix Multiplication (Naive Method)"<<endl;
	cout<<"Enter the matrix 1 details"<<endl;
	cout<<"Number of Rows: ";
	cin>>r1;
	cout<<"Number of columns: ";
	cin>>c1;
	cout<<"Enter the matrix 2 details"<<endl;
	cout<<"Number of rows: ";
	cin>>r2;
	cout<<"Number of columns: ";
	cin>>c2;
	if((r1==c2)&&(c1==r2))
	{
		cout<<"Matrix 1 * Matrix 2 and Matrix 2 * Matrix 1 both possible!!\nPlease note that both are not same thing!!"<<endl;
		cout<<"Press 1 for Matrix 1 * Matrix 2"<<endl;
		cout<<"Press 2 for Matrix 2 * Matrix 1"<<endl;
		cout<<"I must warn you! If you press anything except 1 and 2 I will exit the code :)\n";
		cin>>flag;
	}
	else if(c2==r1)
	{
		cout<<"Matrix 2 * Matrix 1 is possible"<<endl;
		flag=2;
	}
	else if(c1==r2)
	{
		cout<<"Matrix 1 * Matrix 2 is possible"<<endl;
		flag=1;
	}
	else
	{
		cout<<"Matrices are incompatible to be multiplied"<<endl;
		flag=0;
	}
	if(flag==0)
	{
		cout<<"Sorry but I must exit the code now!!\nBut hey! Before I leave I have a tip:\nFor Matrix Multiplication row of one matrix must be equal to column of other matrix in size";
	}
	else if((flag==1)||(flag==2))
	{
		int mat1[r1][c1],mat2[r2][c2];
		printf("\nOkays! So let's multiply the matrices now\n");
		printf("\n\nEnter %d values row wise for the first matrix\n",r1*c1);
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cin>>mat1[i][j];
			}
		}
		printf("\n\nEnter %d values row wise for the second matrix\n",r2*c2);
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				cin>>mat2[i][j];
			}
		}
		if(flag==1)
		{
			cout<<"\nMatrix 1 * Matrix 2\n\n";
			int mat[r1][c2];
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					mat[i][j]=0;
					for(k=0;k<r2;k++)
					{
						mat[i][j]+=mat1[i][k]+mat2[k][j];
					}
				}
			}
			cout<<"Displaying the final matrix"<<endl;
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					cout<<mat[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
		else if(flag==2)
		{
			cout<<"\nMatrix 2 * Matrix 1\n\n";
			int mat[r2][c1];
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c1;j++)
				{
					mat[i][j]=0;
					for(k=0;k<r1;k++)
					{
						mat[i][j]+=mat2[i][k]+mat1[k][j];
					}
				}
			}
			cout<<"Displaying the final matrix"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c1;j++)
				{
					cout<<mat[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
	}
	else
	{
		cout<<"I did warn you!! You chose wrong! Good bye:)\n";
	}
}
