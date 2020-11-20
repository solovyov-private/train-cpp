#include <iostream>

using namespace std;

class QuickFindUF
{
    private:
        int* id;
        size_t size;

    public:
        QuickFindUF(int N) {
            size = N;
            id = new int[N];

            for (int i = 0; i < N; i++)
                id[i] = i;
        }

        ~QuickFindUF() {
            delete [] id;
        }

        int root (int i) {
            while (i != id[i]) {
                i = id [i];
            }

            return i;
        }

        bool isRelated(int p, int q) {
            return root(p) == root(q);
        }

        void Union(int p, int q) {
            int i = root(p);
            int j = root(q);
            id[i] = j;
        }
};

int main() {
    const int A = 10000;

    QuickFindUF* qf = new QuickFindUF(A);

    qf->Union(1, 2);
    qf->Union(2, 3);
    qf->Union(3, 4);
    qf->Union(4, 5);
    qf->Union(5, 6);
    qf->Union(6, 7);
    qf->Union(7, 8);
    qf->Union(8, 9);

    cout << qf->isRelated(4, 8) << endl;

    delete qf;
}
