// DATE: 17-07-2023
/* PROGRAM: 41_Staircase Search_std

Search in Row & Column wise sorted Array

Given a row and column-wise sorted array of integers, write a program to find a
specific element in the array using a staircase search algorithm. The program
should take the array, its dimensions, and the target element as input and
return the row and column indices of the target element if found, or "Not Found"
if not found.

Input Format:
The first line of input contains two integers n and m, representing the number
of rows and columns of the array, respectively. The next n lines contain m
integers each, representing the elements of the array. The last line of input
contains the target element.

Output Format:
If the target element is found in the array, output "Found at (i,j)", where i
and j are the row and column indices of the target element, respectively. If the
target element is not found in the array, output "Not Found".

Sample Input:
4 4
35 45 55 65
40 50 60 70
52 54 62 73
57 58 64 75
73

Sample Output:
Found at (2,3)

EXPLANATION
- Takes N Steps
The algorithm for staircase search is as follows:
• Start at the top-right corner of the array. (arr[0][m-1])
• If the target element is equal to the current element, return "Found at (i,j)".
• If the target element is less than the current element, move left one column.
• If the target element is greater than the current element, move down one row.
• Repeat steps 2-4 until the target element is found or the search goes out of
bounds.

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

void display(int **arr, int n,int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void staircaseSearch(int **arr, int n, int m,int k) {
	int row=0,col=m-1;
	while (row<n and col>=0) {
		if (arr[row][col]==k) {
			cout<<"Found at "<<"("<<row<<","<<col<<")";
			return;
		}
		else if (arr[row][col]>k) { // k is less than current, move left
			col--;
		}
		else if (arr[row][col]<k) { // k is more than current, move down
			row++;
		}
	}
	cout<<"Not Found";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,k=0;
    cin >> n>>m;
	int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
      arr[i]= new int[m];
	  for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
	cin>>k;
	staircaseSearch(arr, n, m, k);
	// display(arr, n,m);
    return 0;
}
