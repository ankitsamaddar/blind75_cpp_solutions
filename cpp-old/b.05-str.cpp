/*
Check if a string has reserved keyword
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
	string key[] ={"Hello","Hi","Bye"};
	string str;
	int c1;
	cin>>str;
	//use raw string literals(R), which preserve all spaces, newlines, and indentations
	string str2 = R"(
Google is best platform to learn
It is used by students to gain knowledge
It is really helpful)";
	cout<<str2;
	for (int i =0;i<3;i++){
		if (str==key[i])
			c1=1;
	}
	if (c1==1){
			cout<<str<<" is a reserved keyword.";
		}
	else{
		cout<<str<<" is not a reserved keyword.";
	}
	return 0;
}
