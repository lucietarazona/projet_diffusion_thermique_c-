#include <iostream>
#include <vector>

#include "includes/CMatrix.h"
#include "includes/lin_solve.h"

CMatrix lin_solve(const CMatrix& A, const CMatrix& b, const CMatrix& x0, const double epsilon)
{
    CMatrix rk = b.sub(A.mult(x0));
    int nb_lin = rk.dimensions()[0];
    CMatrix pk = rk;
    CMatrix xk = x0;
    CMatrix results (x0.dimensions()[0],1,std::vector<double>(x0.dimensions()[0],0));
    while (rk.max_coef()>epsilon)
        {
            CMatrix C = A.mult(pk);
            CMatrix pkt = pk.transpose();
            CMatrix D = pkt.mult(C);
            double den = D.max_coef();

            CMatrix rkt = rk.transpose();
            CMatrix N = rkt.mult(rk);
            double num = N.max_coef();
            double ak = num / den;

            CMatrix apk = pk.homo(ak);
            CMatrix xk1 = xk.sum(apk);
            CMatrix F = A.mult(apk);
            CMatrix rk1 = rk.sub(F);

            for (int i=0;i<nb_lin;i++) // récupération du résultat de la boucle
            {
                results.set_coef_1D(i,xk1.get_coef_1D(i));
            }

            CMatrix rk1t = rk1.transpose();
            CMatrix N2 = rk1t.mult(rk);
            double num2 = N2.max_coef();
            //den2 = num;
            double bk = num2 / num; 
            CMatrix bpk = pk.homo(bk);
            CMatrix pk1 = rk1.sum(bpk);

            for (int i=0;i<nb_lin;i++) //rk:=rk1
            {
                rk.set_coef_1D(i, rk1.get_coef_1D(i));
            }
            for (int i=0;i<nb_lin;i++) //pk:=pk1
            {
                pk.set_coef_1D(i, pk1.get_coef_1D(i));
            }

        }
        return results;
}


