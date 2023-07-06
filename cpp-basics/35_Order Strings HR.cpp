// DATE: 05-07-2023
/* PROGRAM: 35_Order Strings HR
https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/shell-sort-command
Given a list of 'n' strings S0.S1.S2....Sn-1,each consisting of digits and spaces, the number of spaces is the same for each entry, the goal is to implement a variation of a sort command. None of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it. Spaces are used to divide string into columns, which can be used as keys in comparisons.

The program has to support the required parameters:

key: integer denoting the column used as a key in comparisons. The left-most column is denoted by 1.

reversed: boolean variable indicating whether to reverse the result of comparisons

comparison-type: either lexicographic or numeric. Lexicographic means that we use Lexicographical order where for example 122<13. Numeric means that we compare the strings by their numerical values, so 13<122. If the comparison type is numeric and numeric values of keys of si and sj are equal for i<j, then si is considered strictly smaller than sj because it comes first.
INPUT
3
92 022
82 12
77 13
2 false numeric

OUTPUT
82 12
77 13
92 022

EXPLANATION
- c_str() function in C++ converts a string to an array of characters and terminates this array with a null character at the end. It is present in the <cstring> header of the C++ library.
- pair<data_type1, data_type2> Pair_name used to combine together two values that may be of different data types. The first element is referenced as ‘Pair_name.first’ and the second element as ‘Pair_name.second’ and the order is fixed (first, second).
*/
// @ankitsamaddar @2023
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string extactStringAtKey(string str,int key){
	char* s = strtok((char *)str.c_str()," ");
	while (key>1) {
		s = strtok(NULL, " ");
		key--;
	}
	return (string)s;
}
int strToInt(string s){
	int ans=0,p=1;
	for(int i=s.length()-1;i>=0;i--){
		ans+=((s[i]-'0')*p);
		p*=10;
	}
	return ans;
}
bool numericCompare(pair<string, string> s1,pair<string, string> s2){
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return strToInt(key1) < strToInt(key2);
}
bool lexioCompare(pair<string, string> s1,pair<string, string> s2){
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1<key2;
}
int main() {
    int n,i,key=0;
    cin >> n;
	cin.get();
	string* a = new string[n];
	while (i<n) {
		getline(cin,a[i]);
		i++;
	}
	string reversal, ordering;
	cin>>key>>reversal>> ordering;
	pair<string, string> strPair[100];

	for(int i = 0;i<n;i++){
		strPair[i].first = a[i];
		strPair[i].second = extactStringAtKey(a[i], key);
	}
	// sort
	if(ordering=="numeric"){
		sort(strPair,strPair+n,numericCompare);
	}
	else{
		sort(strPair,strPair+n,lexioCompare);
	}
	// reversal
	if (reversal=="true"){
		for (int i =0; i<n-2; i++) {
			swap(strPair[i],strPair[n-i-1]);
		}
	}
	// Print the output
	for(int i = 0;i<n;i++){
	cout<<strPair[i].first<<"\n";
	}
    return 0;
}
