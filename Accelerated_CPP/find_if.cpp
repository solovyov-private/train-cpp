#include <algorithm>
#include <iostream>

int main () {
  auto myvector = {1, 2, 3, 4, 5};

  auto it = std::find_if_not(myvector.begin(), myvector.end(), [](int number){return number % 2 == 0;});
  if (it != myvector.end()) {
    std::cout << "Even element found in myvector: " << *it << '\n';
  } else {
    std::cout << "No even element found in myvector\n";
  }

  return 0;
}
