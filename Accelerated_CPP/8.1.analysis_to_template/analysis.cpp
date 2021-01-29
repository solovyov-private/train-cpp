#include "analysis.h"

using std::back_inserter;
using std::endl;
using std::ostream;
using std::string;
using std::transform;
using std::vector;

//double doAnalysis(const vector<Student_info>& students,
//                  double ptrAnalysisMethod(const Student_info&))
//{
//    vector<double> grades;
//
//    transform(students.begin(), students.end(),
//              back_inserter(grades), ptrAnalysisMethod);
//    return median(grades);
//}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

void write_analysis(ostream& out,
                    const string& name,
                    double ptrAnalysisMethod(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << doAnalysis(did, ptrAnalysisMethod)
        << ", median(didnt) = " << doAnalysis(didnt, ptrAnalysisMethod) << endl;
}
