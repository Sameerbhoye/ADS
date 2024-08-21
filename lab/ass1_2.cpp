/*
Implement a problem of move all zeroes to end of array. 
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 
9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.  
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0}; 
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
 */

#include<iostream>
using namespace std;
int movezerostoend(int arr[], int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        
    }
}
int main()
{
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array Elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return 0;
}