#include "includes/CMatrix.h"
#include "includes/euler_exp.h"


CMatrix euler_exp_1D_step(const double delta_t, const CMatrix& K, const CMatrix& T)
{
    CMatrix modif1 = K.mult(T);
    CMatrix modif2 = modif1.homo(delta_t);
    CMatrix T_step = T.sub(modif2);
    return T_step;
}