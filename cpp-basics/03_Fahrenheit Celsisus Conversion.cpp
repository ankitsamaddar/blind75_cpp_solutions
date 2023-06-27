// DATE: 27-06-2023
/* PROGRAM: 03_Fahrenheit Celsisus Conversion
Apply the temperature conversion formula celsius = (fahrenheit - 32) * 5 / 9 . Print the value of celsius along with fahrenheit upto 300
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
	int f = 0;
	while(f<=300){
		float c = static_cast<float>(f-32)*5/9;
		cout << f << "F\t"<< c <<"C\n";
		f+=20;
	}
    return 0;
}
