#include <iostream>
#include <vector>

#include "CMatrix.h"

CMatrix lin_solve(const CMatrix& A, const CMatrix& b, CMatrix& x0, const double& epsilon);