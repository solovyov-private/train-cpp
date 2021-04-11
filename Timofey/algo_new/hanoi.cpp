#include <iostream>

/*
 * Hanoi solution finder
 * param i: srart pin 
 * param k: finish pin 
 * param n: number of disks
*/

void hanoi(int i, int k, int n)
{
    if (n == 1) {
        std::cout << "Put disk " << n << " from pin "
                  << i << " on pin " << k << "\n";
    }
    else {
        int tmp = 6 - i - k; // third pin
        hanoi(i, tmp, n-1);
        std::cout << "Put disk " << n << " from pin "
                  << i << " on pin " << k << "\n";
        hanoi(tmp, k, n - 1);
    }
}

int main()
{
    hanoi(1, 2, 5);
    return 0;
}
