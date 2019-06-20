#include<iostream>
using namespace std;
int main()
{
	int r1,r2,c1,c2,r,c;
	printf("Addition of Two Matrix!!!\n\n");
	printf("Enter the size of the first matrix\n");
	printf("Number of rows: ");
	scanf("%d",&r1);
	printf("Number of columns: ");
	scanf("%d",&c1);
	printf("\n");
	printf("Enter the size of the second matrix\n");
	printf("Number of rows: ");
	scanf("%d",&r2);
	printf("Number of columns: ");
	scanf("%d",&c2);
	printf("\n");
	if((r1==r2)&&(c1==c2))
	{
		cout<<"Matrices are of same size and are compatible to be added!!"<<endl;
		int m1[r1][c1],m2[r2][c2],m3[r1][c1];
		printf("Enter the first matrix values row wise!!\n");
		for(r=0;r<r1;r++)
		{
			for(c=0;c<c1;c++)
			{
				scanf("%d",&m1[r][c]);
			}
		}
		cout<<"Enter the second matrix values row wise"<<endl;
		for(r=0;r<r1;r++)
		{
			for(c=0;c<c2;c++)
			{
				cin>>m2[r][c];
			}
		}
		for(r=0;r<r1;r++)
		{
			for(c=0;c<c1;c++)
			{
				m3[r][c]=m1[r][c]+m2[r][c];
			}
		}
		cout<<"\n\nDisplaying the final matrix after addition\n";
		for(r=0;r<r1;r++)
		{
			for(c=0;c<c1;c++)
			{
				cout<<m3[r][c]<<"\t";
			}
			cout<<"\n";
		}
	}
	else
	{
		cout<<"Matrices are of different size and thus matrix addition is not applicable!!"<<endl;
	}
}
