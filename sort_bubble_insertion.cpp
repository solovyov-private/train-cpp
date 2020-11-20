#include <cmath>
#include <iostream>

using namespace std;

void sortB(int*, int);
void sortI(int*, int);

int main(int argc, char* argv[]) {
    srand(time(NULL));

    void (* sortByMethod[2])(int*, int) = {sortB, sortI};

    int size;
    int method;

    cout << "Array size: ";
    cin >> size;

    cout << "Select method: \n"
         << "1\tbubble\n"
         << "2\tinsertion\n";
    cout << "Method: ";
    cin >> method;

    int A[size];

    for (int i=0; i < size; i++) {
        A[i] = rand() % size * 2;
    }

    sortByMethod[--method](A, size);

    for (int i=0; i < size; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}

void sortB(int* A, int size) {
    cout << "Bubble\n";
    bool isSorted = 0;
    int tmp;

    while (! isSorted){
        isSorted = 1;
        for (int i=0; i < size-1; i++) {
            if (A[i+1] < A[i]){
                tmp      = A[i];
                A[i]     = A[i+1];
                A[i+1]   = tmp;
                isSorted = 0;
            }
        }
    }

}

void sortI(int* A, int size) {
    cout << "Insertion\n";
    int tmp;

    for (int i = 1; i < size; i++){
        for (int j = i; A[j] < A[j-1] && j > 0; j--) {
            tmp     = A[j-1];
            A[j-1]  = A[j];
            A[j]    = tmp;
        }
    }
}
