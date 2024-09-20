/*
Implement a problem of maxmize profit by trading stocks based given rate per day 
statement: Given an array arr[] of n positive integers which denotes the cost of a selling and buying stock on each of the N days. The task is to find the maximize profit that can be earned by buying a stack on or selling all previously bought stocks on a particular day 
Input: arr[]={2,3,5} 
output 
Input: arr[]={8 .,5,1}
output: 0
   
*/

#include<iostream>
using namespace std;
int maxpro(int* prices, int n  )
{
	int p=0;int cd =n-1;
	while(cd>0)
	{
		int day=cd-1;
	
	while (day>=0 && (prices[cd]>prices[day]))
	{
		p+=(prices[cd]-prices[day]);
		day--;
	}
		cd=day;
	}
	return p;

}


int main()
{
	cout<<"Enter total number of prices : ";
	int s;
	cin>>s;
	int prices[s];
	cout<<"Enter prices : ";
	for(int i=0; i<s;i++)
	{
		cin>>prices[i];
	}
	int n=sizeof(prices)/sizeof(prices[0]);
	cout<<maxpro(prices,n );

	return 0;
}










