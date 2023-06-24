/*
Scheme:
He first turns and travels 10 units of distance
His second turn is upward for 20 units
Third turn is to the left for 30 units
Fourth turn is the downward for 40 units
Fifth turn is to the right(again) for 50 units
… And thus he travels, every time increasing the travel distance by 10 units. -> dis += 10
*/

// R -> x+dis
// U -> y+dis
// L -> x-dis
// D -> y-dis
// A -> x+dis -> needed as go back to first condition

/*
Test Cases
Case 1
Input : 3
Expected Output :-20 20

Case 2
Input: 4
Expected Output: -20 -20

Case 3
Input : 5
Expected Output : 30 -20

Case 4
Input : 7
Expected Output : 90 50
*/

#include <iostream>
using namespace std;
int main(){
	int dis=10,x=0,y=0;
	int n;
	cin>>n;
	char dir ='R' ; // first is right
	for(int i = 1;i<=n;i++){

		if (dir=='R'){
			x=x+dis;
			dir='U';
		}
		else if (dir=='L'){
			x=x-dis;
			dir='D';
		}
		else if (dir=='U'){
			y=y+dis;
			dir='L';
		}
		else if (dir=='D'){
			y=y-dis;
			dir='A';
		}
		else if (dir=='A'){
			x=x+dis;
			dir='R';
		}
		dis+=10;
	}

	cout << x<<" "<<y;
	return 0;
}

