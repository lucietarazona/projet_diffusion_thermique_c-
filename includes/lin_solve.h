#include <iostream>
#include <vector>

#include "CMatrix.h"

std::vector<double> lin_solve(const CMatrix& A, const CMatrix& b, CMatrix& x0, const double& epsilon);