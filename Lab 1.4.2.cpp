#include <iostream>
using namespace std;
int main(void) {
int i, j, k;
cout << "Enter i: ";
cin >> i;
cout << "I= " << i;
cout << "Enter j: ";
cin >> j;
cout << "j= " << j;
// increment i by 2
     i+=2;
// decrement j by i
     j-=i;
// divide i by j giving k
     k = i/j;
// increment k by k
     k+=k;
// decrement k by 1
     k--;
// assign k modulo i to j
     k = abs(i*j);
// increment k by k added to i
     k+= k+i;
// increment k by k divided by j
     k+= k/j;
// assing k times k times k to k
     k=k*k*k;
// increment k by i times j
    k = (k+i)*j;
cout << endl << k;
return 0;
}
