#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

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
   double tf {0.5};
   double xf {1};
   int Nx {10};
   int Nt {1000};
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
    for (int i=0; i<Nx-1; i++)
    {
        T.set_coef_1D(i, 0.5+sin(2*M_PI*i*delta_x)-0.5*cos(2*M_PI*i*delta_x));
        temp.set_coef_2D(0,i, T.get_coef_1D(i));
    }
    T.set_coef_1D(Nx-1,0);
    temp.set_coef_2D(0, Nx-1, 0);
    //T.display(); up to you

   for (int i=1;i<Nt;i++)
   {
       CMatrix T1=euler_exp_1D_step(delta_t, K, T);
       T1.set_coef_1D(0,0);     //conditions on x=0 and x=L
       T1.set_coef_1D(Nx-1,0);
       //T1.display(); up to you
       //std::cout<<"\n"<<std::endl;

       for (int j=0;j<Nx;j++)
       {
           temp.set_coef_2D(i,j,T1.get_coef_1D(j));
       }
       for (int i=0;i<Nx;i++)
       {
           T.set_coef_1D(i, T1.get_coef_1D(i));
       }

   }
    //temp.display(); up to you

    //exporting to txt
    std::ofstream values_exp_file ("values_temp.txt");
    for (int i=0;i<Nt;i++)
    {
        for (int j=0;j<Nx;j++)
        {
            values_exp_file<<temp.get_coef_2D(i,j)<<";";
        }
        values_exp_file<<"\n";
    }
    values_exp_file.close();

    
    }
}