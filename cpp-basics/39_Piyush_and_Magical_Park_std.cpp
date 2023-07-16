// DATE: 16-07-2023
/* PROGRAM: 39_Piyush and Magical Park_std
[Hackerrank]
Piyush is lost in a magical park which contains N rows and M columns.In order to
get out of park safely and return home, he needs atleast K amount of
strength.Given a N by M pattern, your task is to find weather Piyush can ever
escape the park.

Piyush enters the park with strength S. The park is filled with some obstacles
denoted by ‘.’ , some magical beans denoted by ‘*’ and some blockades denoted as
‘#’. If he encounters an obstacle (.) , strength decreases by 2. If he
encounters a magic bean (’ * ') , his strength increases by 5. Piyush can only
walk row wise, so he starts from left of a row and moves towards right and he
does this for every row. However when he encounters a blockade (#) , he cannot
go any further in his current row and simply jumps to the start of a new line
without losing any strength. Piyush requires a strength of 1 for every step. His
strength should always be greater than K while traversing or else Piyush will
get lost. Assume that Piyush can shift immediately from last of one row to the
start of next one without loss of any strength, help out Piyush to escape the
park. His escape is successful if he is able to return home with atleast K
strength.

Input Format
First line of input contains four integers – N,M,K and S. Next N lines contains
M space separated characters which can be '.', '*' or '#'.

Constraints
1 <= N,M,K,S <= 100

Output Format
Print "Yes" or "No" depending on whether Piyush can escape or not. If the answer
is "Yes", also print the amount of strength he escaped with.

Sample Input
4 4 5 20
. . * .
. # . .
* * . .
. # * *

Sample Output
Yes
13

EXPLANATION
every step strength is -1 except end of row. Strength(S) should be greater than K.
. = -2
* = +5
# = Blocked. Go to next line(row).

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
void magical_park(char a[][100],int m,int n,int k,int s){
	bool success = true;
	for (int i=0; i<n; i++) {
		for (int j= 0; j<m; j++) {
			char ch = a[i][j];

			// check if strength under threshold
			if (s<k){
				success = false;
				break;
			}
			if(ch=='*'){
				s+=5;}
			else if (ch=='.'){
			 	s-=2;}
			else if (ch=='#') {
			 	break;
				}
			// loose 1 point for every move except last
			if(j!=n-1){
				s--;
			}
			// cout<<s<<" ";
		}
		// cout<<endl;
	}
	if (success)
		cout<<"True"<<endl<<s<<endl;
	else
		cout<<"False"<<endl;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,k,s=0;
    cin >> n >> m >> k >> s;
	char obstacle[100][100];
	for (int i=0; i<n; i++) {
		for (int j= 0; j<m; j++) {
			cin>>obstacle[i][j];
			// cout<<obstacle[i][j]<<" ";
		}
		// cout<<endl;
	}
	magical_park(obstacle, m, n,  k, s);
	return 0;
}
