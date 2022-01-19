#include <iostream>
#include <vector>

#include "includes/CMatrix.h"
#include "includes/lin_solve.h"

void tests()
{
    {
    //position test
    std::cout<<"position test"<<std::endl;
    std::vector<double> coefs_T({4,8,6,2,3,9});
    CMatrix T(2,3,coefs_T);
    std::cout<<"T="<<std::endl;
    T.display();
    int p=T.position(1,2);//indice correspondant à la DEUXIEME ligne et TROISIEME colonne (les indices commencent à 0)
    std::cout<<"position de (1,2)="<<p<<std::endl;
   
    //dimension test
    std::cout<<"dimension = "<<T.dimensions()[0]<<" "<<T.dimensions()[1]<<std::endl;
    
    //get test
    std::cout<<"get 2D test"<<std::endl;
    std::cout<<"coef (1,2)= "<<T.get_coef_2D(1,2)<<std::endl; // coef de la deuxième ligne et troisième colonne
    
    //set test
    std::cout<<"set 2D test"<<std::endl;
    T.set_coef_2D(1,2,25);
    std::cout<<"coef (1,2) becomes 25"<<std::endl;
    T.display();

    //transpose test
    std::cout<<"transpose test"<<std::endl;
    CMatrix mat_res=T.transpose();
    mat_res.display();
    }
    
    {
    //addition test
    std::cout<<"addition test"<<std::endl;
    std::vector<double> coefs_A({1,2,3,4});
    std::vector<double> coefs_B({5,6,7,8});
    CMatrix A(2,2,coefs_A);
    CMatrix B(2,2,coefs_B);
    CMatrix C=A.sum(B);
    std::cout<<"matrix 1"<<std::endl;
    A.display();
    std::cout<<"matrix 2"<<std::endl;
    B.display();
    std::cout<<"result"<<std::endl;
    C.display();
    }

    {
    //substraction test
    std::cout<<"substraction test"<<std::endl;
    std::vector<double> coefs_D({1,2,3,4});
    std::vector<double> coefs_E({3,2,6,1.5});
    CMatrix D(2,2,coefs_D);
    CMatrix E(2,2,coefs_E);
    CMatrix F=D.sub(E);
    std::cout<<"matrix 1"<<std::endl;
    D.display();
    std::cout<<"matrix 2"<<std::endl;
    E.display();
    std::cout<<"result"<<std::endl;
    F.display();
    }

    {
    //scalar multiplication test
    std::cout<<"scalar multiplication test"<<std::endl;
    std::vector<double> coefs_G({2.5,3,4.1,2});
    CMatrix G(2,2,coefs_G);
    double a {3.5};
    CMatrix H=G.homo(a);
    std::cout<<"matrix"<<std::endl;
    G.display();
    std::cout<<"scalar = "<<a<<std::endl;
    std::cout<<"result"<<std::endl;
    H.display();
    }

    {
    //matrix multiplication test
    std::cout<<"matrix multiplication test"<<std::endl;
    std::vector<double> coefs_I({1,5,0,2,3,2});
    std::vector<double> coefs_J({7,0,6});
    CMatrix I(2,3,coefs_I);
    CMatrix J(3,1,coefs_J);
    CMatrix K=I.mult(J);
    std::cout<<"matrix 1"<<std::endl;
    I.display();
    std::cout<<"matrix 2"<<std::endl;
    J.display();
    std::cout<<"result"<<std::endl;
    K.display();
    }

    {
    //linear system solving test
    std::cout<<"linear system solving test"<<std::endl;
    std::vector<double> coefs_L({2,0,0,2});
    std::vector<double> coefs_M({4,8});
    CMatrix L(2,2,coefs_L);
    CMatrix M(2,1,coefs_M);
    CMatrix init (2,1, {0,0});
    CMatrix res = lin_solve(L, M, init, 0.01);
    res.display();
    }


}

