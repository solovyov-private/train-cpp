#include <iostream>

/*
 * Hanoi solution finder
*/

const int MAX_BINARY_DIGITS_TO_GEN = 100;

void genBinNumbers(int digitsLeftToGen)
{
    static int digitsCombination[MAX_BINARY_DIGITS_TO_GEN];
    static int top = 0;

    if (digitsLeftToGen == 0) { // base case
        for (int i = 0; i < top; ++i)
            std::cout << digitsCombination[i];
        std::cout << std::endl;
    } else {                    // recursive case
        digitsCombination[top] = 0;
        top++;
        genBinNumbers(digitsLeftToGen - 1);
        top--;

        digitsCombination[top] = 1;
        top++;
        genBinNumbers(digitsLeftToGen - 1);
        top--;
    }
}

int main()
{
    int n;
    std::cin >> n;
    genBinNumbers(n);
    return 0;
}
