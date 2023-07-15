// DATE: Sa- 0-/15/
/* PROGRAM: 36_2D Array
2D Array INPUT AND OUTPUT for the specified dimensions where N rows and M columns are inputs. Also input the elements of the 2D Array and print the elements of the 2D array.
INPUT
4 5 1 2 1 2 1 3 1 3 1 3 5 4 5 4 5 1 1 1 1 1
OUTPUT
1 2 1 2 1
3 1 3 1 3
5 4 5 4 5
1 1 1 1 1

EXPLANATION
To dynamically assign a 2D int array in C++ :

1.Declare a pointer to a pointer of type int: int **arr;
- We use a pointer to a pointer is because a 2D array is essentially an array of arrays. The first pointer points to an array of pointers, where each pointer points to a row of integers. arr[int*,int*,int*,....]

2.Allocate memory for the rows: arr = new int*[n];
- int* as each pointer is a row of integers. So we dynamically assign column for each row interation like an array using arr[row] = new int[m] .

3.Allocate memory for the columns in each row: for (int row = 0; row < n; row++) { arr[row] = new int[m]; }
- We allocate an array of integers inside an array of integer pointers.

To access an element in the array, you can use the row and column indices: arr[i][j].
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int n,m=0;
	cin >> n>>m;
	cin.get();
	int **arr=new int*[n]; // n
	for(int row=0;row<n;row++){
		arr[row]=new int[m]; // for each row we are creating an array of m length column
		for(int col=0;col<m;col++){
			cin >> arr[row][col];
			cout << arr[row][col]<<" ";
		}
		cout <<endl;
	}
    return 0;
}
