#include<iostream>
using namespace std;
int main()
{
	int arr[20],key,low,high,mid,n;
	cout<<"Enter no of the array elements to be inserted :";
	cin>>n;
	cout<<"Enter the array Elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}


	cout<<"\nEnter the array element  to be Searched : " ;
	cin>>key;
	low=0;
	high=n-1;
	int f=0,c=0;

	
	while(low<=high)
	{
		c++;
		mid=(low+high)/2;
		if(key==arr[mid])
		{
			cout<<"Element found at location,"<<mid <<endl;
			f=1;
			break;
		}
		else if(key<arr[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}

		
	}

	if(f==0)
	cout<<"array element not found ! ";
	cout<<c;

return 0;
}
