#include <vector>  // vector
#include <numeric>  // numeric
 
using std::vector;
using std::accumulate;
 
// Compute average of elements
// (S6.2.3/115)
double average(const vector<double>& v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
