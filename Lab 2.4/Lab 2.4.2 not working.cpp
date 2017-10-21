#include <iostream>
using namespace std;
int main(void) {
unsigned short int val;
bool ispalindrome = false;
cout << "value = ";
cin >> val;
int base = val;
  int rev = 0;
  while (val)
  {
    rev = rev * 2 + val % 2;
    val /= 2;
  }
  if (base == rev)
  {
    ispalindrome = true;
  }
  else
  {
    ispalindrome = false;
  }
if(ispalindrome)
cout << base << " is a bitwise palindrome" << endl;
else
cout << base << " is not a bitwise palindrome" << endl;
return 0;
}
