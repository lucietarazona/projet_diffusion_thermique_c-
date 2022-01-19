#include "includes/euler_imp.h"
#include "includes/lin_solve.h"

CMatrix euler_imp_1D_step(const int Nx, const double delta_t, const CMatrix& K, const CMatrix& T, const double epsilon)
{
    CMatrix Id (Nx,Nx, std::vector<double>(Nx*Nx,0));
    for (int i=0; i<Nx;i++)
    {
        Id.set_coef_2D(i,i,1);
    }
    CMatrix A = Id.sub(K.homo(delta_t));
    CMatrix x0 (Nx,1,std::vector<double>(Nx,0));
    CMatrix T_step = lin_solve(A, T, x0, epsilon);
    return T_step;
}