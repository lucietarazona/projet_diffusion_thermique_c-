#include <iostream>
#include <vector>

#include "includes/CMatrix.h"
#include "includes/lin_solve.h"

CMatrix lin_solve(const CMatrix& A, const CMatrix& b, CMatrix& x0, const double& epsilon)
{
    int k {0};
    CMatrix rk=b.sub(A.mult(x0));
    int nb_lin = rk.dimensions()[0];
    //CMatrix rk1 (nb_lin,1, std::vector<double>(nb_lin, 0));
    CMatrix pk=rk;
    CMatrix xk=x0;
    CMatrix results (x0.dimensions()[0],1,std::vector<double>(x0.dimensions()[0],0));
    while (rk.max_coef()>epsilon)
        {
            double den = pk.transpose().mult(A.mult(pk)).max_coef();
            double num = rk.transpose().mult(rk).max_coef();
            double ak = num / den;
            CMatrix xk1 = xk.sum(pk.homo(ak));
            CMatrix rk1 = rk.sub(A.mult(pk).homo(ak));
            //if (rk1.max_coef()>epsilon)
            double num2 = rk1.transpose().mult(rk1).max_coef();
            double den2 = rk.transpose().mult(rk).max_coef();
            double bk = num2 / den2; 
            CMatrix pk1 = rk1.sum(pk.homo(bk));
            for (int i=0;i<nb_lin;i++) //rk:=rk1
            {
                rk.set_coef_1D(i, rk1.get_coef_1D(i));
            }
            for (int i=0;i<nb_lin;i++) //pk:=pk1
            {
                pk.set_coef_1D(i, pk1.get_coef_1D(i));
            }
             k+=1;
            
            for (int i=0;i<nb_lin;i++)
            {
                results.set_coef_1D(i,xk1.get_coef_1D(i));
            }
            //std::cout<<rk1.max_coef()<<std::endl;

        }
        return results;
}


