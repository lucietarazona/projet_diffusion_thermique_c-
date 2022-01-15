#include <iostream>
#include <vector>
#include <string>

#include "includes/CMatrix.h"
#include "includes/tests.h"

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
   int Nx {100};
   int Nt {100};
   double delta_t = tf/Nt;
   double delta_x = xf/Nx;
   
   CMatrix K(Nx,Nx,std::vector<double>(Nx*Nx,0));
   for (int i=0;i<Nx;i++)
   {
       for(int j=0;j<Nx;j++)
       {
           if (i==j)
           {
               K.set_coef(i,i,-2);
           }
           else if ((i==j-1)||(j==i-1));
           {
               int p1 = K.position(i,j-1);
               int p2 = K.position(i-1,j);
               K.set_coef(i,j-1,1);
               K.set_coef(i-1,j,1);
           }
       }
   }
   K.display();
   
    
    }
}