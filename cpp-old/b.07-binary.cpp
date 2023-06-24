#include <iostream>

using namespace std;

void todecimal(int binary){
	int i=1,decimal;
	while(binary>0){
		decimal+= (binary%10)*i;
		binary=binary/10;
		i=i*2;
	}
	cout<<decimal;
}

void tobinary(int n){
	int i=1,binary;
	while(n!=0){
		binary+=(n%2)*i;
		n=n/2;
		i=i*10;
	}
	cout<<binary<<endl;
	todecimal(binary);
}

int main() {
int n,i=1,binary=0;
cin>>n;
tobinary(n);

return 0;
}
