#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "includes/CMatrix.h"
#include "includes/tests.h"
#include "includes/euler_exp.h"

int main (int argc, char** argv)
{
    if (argc > 1) //enter anything to launch test
    {
        tests();
    }
    else
    {
   double tf {1};
   double xf {1};
   int Nx {10};
   int Nt {10};
   double delta_t = tf/Nt;
   double delta_x = xf/Nx;
   
   CMatrix K(Nx,Nx,std::vector<double>(Nx*Nx,0));
   for (int i=0;i<Nx;i++)
   {
       for(int j=0;j<Nx;j++)
       {
           if (i==j)
           {
               K.set_coef_2D(i,i,-2);
           }
           else if ((i==j-1)||(j==i-1))
           {
               K.set_coef_2D(i,j,1);
           }
       }
   }
   //K.display(); to check K


    //matrix keeping all temperature values
    CMatrix temp(Nt,Nx,std::vector<double>(Nt*Nx,0));

    //temperature initialization and values in temp
    CMatrix T(Nx,1,std::vector<double>(Nx*1,0));
    for (int i=0; i<Nx; i++)
    {
        T.set_coef_1D(i, 0.5+sin(2*M_PI*i*delta_x)-0.5*cos(2*M_PI*i*delta_x));
        temp.set_coef_2D(0,i, T.get_coef_1D(i));
    }
    T.display();

   for (int i=1;i<Nt;i++)
   {
       CMatrix T1=euler_exp_1D_step(delta_t, K, T);
       T1.set_coef_1D(0,0);     //conditions on x=0 and x=L
       T1.set_coef_1D(Nx-1,0);
       T1.display();
       std::cout<<"\n"<<std::endl;

       for (int j=0;j<Nx;j++)
       {
           temp.set_coef_2D(i,j,T1.get_coef_1D(j));
       }

   }
    temp.display();

   
    
    }
}