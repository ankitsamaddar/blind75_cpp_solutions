/*
Series: 1,1,2,3,4, 9,8,27,16,81,32,243,64,729,128,2187...
This series is a mixture of 2 series -
all the odd terms in this series form a geometric series and  -> prev odd terms *2
all the even terms form yet another geometric series. -> prev even term *3

Write a program to find the Nth term in the series.
*/

#include<iostream>
using namespace std;
int main(){
	int a,b,n;
	cout<<"Enter Nth Term: ";
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		if (i%2==0){
			if(i>2){
				a=a*3;
			}
			else{
				a=1;
			}
		}
		else{
			if(i>1){
				b=b*2;
			}
			else{
				b=1;
			}
		}
	}
	if(n%2==0){
		cout <<a;
	}
	else{
		cout<<b;
	}
	return 0;
}
