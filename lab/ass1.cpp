#include<iostream>
using namespace std;
int countzeros(int arr[],int n)
{
	int low=0;
	int high=n-1;
        int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==0)
		{
			if(arr[mid-1]==1  ||  mid==0)
			{
				return n-mid;
			}
			else 
			{
				high=mid-1;
			}
		}
		else 
		{
			if(arr[mid+1]==0 || mid==n-1 )
			{
				return n-(mid+1);
			}
			else
			{
				low=mid+1;
			}
		}
	}
}
int main()
{
	
	int n;
	cout<<"Enter the size of an array:";
	cin>>n;
	int arr[n];
	cout<<"Enter the array Elements :";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int a=countzeros(arr, n);
	cout<<"Number of Zeros in given array is : "<<a;

	return 0;

}
