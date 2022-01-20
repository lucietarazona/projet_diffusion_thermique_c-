#include <iostream>
#include <vector>

#include "CMatrix.h"
#include "lin_solve.h"

CMatrix euler_imp_1D_step(const int Nx, const double delta_t, const CMatrix& K, const CMatrix& T, const double epsilon) ;