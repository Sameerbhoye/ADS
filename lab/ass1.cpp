/*
Implement a problem of number of zeroes. 
Statement: Given an array of 1s and 0s which has all 1s first 
followed by all 0s? Find the number of 0s. Count the number of 
zeroes in the given array. 
Input: arr[] = {1, 1, 1, 1, 0, 0}                     Output: 2 
Input: arr[] = {1, 0, 0, 0, 0}                          Output: 4 

*/

#include<iostream>
using namespace std;
int count_zeros(int arr[], int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==0)
        {
            if(arr[mid-1]==1  || mid==0)
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
            if(arr[mid+1]==0 || mid==n-1)
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
    cout<<"Enter the array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int a=count_zeros(arr,n);
    cout<<"Number of zeros in given array is : "<<a;

    return 0;
}








































