#include<stdio.h>
int main()
{
	int n,size,i;
	printf("Array of Strings code!\n");
	printf("Enter the size of the array you want: ");
	scanf("%d",&n);
	printf("Enter maximum String size: ");
	scanf("%d",&size);
	char str[n][size];
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element of the array: ",i+1);
		scanf("%s",&str[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("The %d element of the Array of String is: %s\n",i+1,str[i]);
	}
}
