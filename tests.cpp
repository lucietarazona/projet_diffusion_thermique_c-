#include <iostream>
#include <vector>

#include "includes/CMatrix.h"

void tests()
{
    //position test
    std::cout<<"position test"<<std::endl;
    std::vector<double> coefs_T({4,8,6,2,3,5});
    CMatrix T(2,3,coefs_T);
    T.display();
    int p=T.position(2,3);
    std::cout<<p<<std::endl;
    //dimension test
    std::cout<<"dimension"<<T.dimensions()[0]<<" "<<T.dimensions()[1]<<std::endl;
    //get test
    std::cout<<"coef (1,2)"<<T.get_coef(1,2)<<std::endl;
    //set test
    T.set_coef(1,2,25);
    T.display();
    
    //addition test
    std::cout<<"addition test"<<std::endl;
    std::vector<double> coefs_A({1,2,3,4});
    std::vector<double> coefs_B({5,6,7,8});
    CMatrix A(2,2,coefs_A);
    CMatrix B(2,2,coefs_B);
    CMatrix C=A.sum(B);
    A.display();
    B.display();
    C.display();

    //substraction test
    std::cout<<"substraction test"<<std::endl;
    std::vector<double> coefs_D({1,2,3,4});
    std::vector<double> coefs_E({3,2,6,1.5});
    CMatrix D(2,2,coefs_D);
    CMatrix E(2,2,coefs_E);
    CMatrix F=D.sub(E);
    D.display();
    E.display();
    F.display();

    //scalar multiplication test
    std::cout<<"scalar multiplication test"<<std::endl;
    std::vector<double> coefs_G({2.5,3,4.1,2});
    CMatrix G(2,2,coefs_G);
    double a {3.5};
    CMatrix H=G.homo(a);
    G.display();
    H.display();

    //matrix multiplication test
    std::cout<<"matrix multiplication test"<<std::endl;
    std::vector<double> coefs_I({1,5,0,2,3,2});
    std::vector<double> coefs_J({7,0,6});
    CMatrix I(2,3,coefs_A);
    CMatrix J(3,1,coefs_B);
    CMatrix K=A.mult(B);
    I.display();
    J.display();
    K.display();
}

