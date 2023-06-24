/*
Program to input the 2d matrix and print the row having maximum sum.
*/
// matrix[row][column]

#include <iostream>
using namespace std;

int main(){
	int mat[100][100],row,col,sum=0,max=0,pos;
cout << "Enter row & column: ";
cin >>row>>col;
	for (int i=0; i<row; i++) {
		sum=0;
		for (int j= 0; j<col; j++) {
			cout<<"Enter mat["<<i+1<<"]["<<j+1<<"]: ";
			cin >> mat[i][j];
			sum+=mat[i][j];
		}
		if(sum>max){
			max = sum;
			pos = i;
		}
	}

	cout<<"The max sum is in row "<<pos+1<<" and the sum is "<<max<<""<<endl;

	return 0;
}
