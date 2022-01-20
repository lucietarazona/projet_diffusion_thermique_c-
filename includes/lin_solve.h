#pragma once
#include <iostream>
#include <vector>

#include "CMatrix.h"

CMatrix lin_solve(const CMatrix& A, const CMatrix& b, const CMatrix& x0, const double epsilon);