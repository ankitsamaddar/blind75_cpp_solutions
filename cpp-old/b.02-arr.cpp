/*
Number series: 0 0 2 1 4 2 6 3 8 4
find Nth Term
*/

#include<iostream>
using namespace std;
int main(){
	int arr[30];
	cout << "Enter the number: ";
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		if (i%2==0){
			if(i>1)
				arr[i]=arr[i-2]+2;
		}
		else{
			arr[i]=arr[i-1]/2;
		}
	}
	cout<<arr[n];
	return 0;
}
