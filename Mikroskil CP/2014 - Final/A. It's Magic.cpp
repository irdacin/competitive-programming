#include <iostream>
using namespace std;

int main(){
	short k,n;
	cin >> k >> n;
	cout << "Think of a number, any number"<< endl << "Multiply it by " << k << endl << "Add " << k*n << " to your number\nNow, divide your total by " << k << endl <<"Finally, subtract the result from the first number you pick\nBRAVO!!!\nYour answer is " << n << endl;
	return 0;
}