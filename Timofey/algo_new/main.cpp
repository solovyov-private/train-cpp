#include <iostream>
#include <cmath>

using namespace std;
double f(double);

struct tPair
{
    int a;
    int b;
};

tPair retPair(int x)
{
    tPair result;

    result.a = x;
    result.b = x * x;
    return result;
}

void modPair(tPair* p)
{
    p->a += 1;
    p->b += 21;
}

int main() {
    double x;
    cin >> x;
    cout << f(x) << endl;

    double s = 0;
    double factor;
    for (int i = 0, factor = 1; i < 10; ++i) {
        s += pow(-1, i) * pow(x, 2 * i + 1);
        factor *= 2 * i * (2 * i +1);
    }
    cout << s << endl;

    tPair p = retPair(x);
    modPair(&p);
    cout << p.a << "\t" << p.b << endl;

    int64_t y;
    double z;

    z = 1.0;
//    y = *(int64_t*)(&z); // NOT RECOMMENDED, use reinterpret_cast
    y = *reinterpret_cast<int64_t*>(&z);
//    y = *static_cast<int64_t*>(&z); // Error

    cout << y << endl;

    return 0;
}

double f(double x)
{
    return 2 * sin(x);
}