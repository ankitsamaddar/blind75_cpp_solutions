#include <iostream>
#include <string>

using namespace std;
int main(){
	string a;
	string b;
	string c;
	int i =0;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	// replace vowels by %
	while(i<a.length()){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			a[i]='%';
		}
		i++;
	}
	i=0;
	// replace consonants by #
	while(i<b.length()){
		if(b[i]!='a'&&b[i]!='e'&&b[i]!='i'&&b[i]!='o'&&b[i]!='u'){
			b[i]='#';
		}
		i++;
	}
	i=0;
	// capitalize
	while(i<c.length()){
		if(c[i]>='a'&&c[i]<='z'){
			c[i]=c[i]-32;
		}
		i++;
	}
	string result=a+b+c;
	cout << result;
	return 0;
}
