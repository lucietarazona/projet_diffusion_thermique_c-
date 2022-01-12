#include "CMatrix.h"

CMatrix::CMatrix(int height, int width, std::vector<double> coefs):
    _height(height),
    _width(width),
    _coefs(coefs)
{}

CMatrix::~CMatrix() {}

int CMatrix::position(const int i, const int j) const //be careful, i and j start from 0!
{
    return _width*i +j; 
}

std::vector<int> CMatrix::dimensions() const
{
    return std::vector<int> ({_height, _width});
}

double CMatrix::get_coef(const int i, const int j) const
{
    int p = position(i,j);
    return _coefs[p];
}

void CMatrix::set_coef(const int i, const int j, const double coef)
{
    int p = position(i,j);
    _coefs[p] = coef;
}


//maths
CMatrix CMatrix::sum(const CMatrix& mat) const
    {
        // on crée une matrice de taille _height*_width, et ses coefficients sont un vecteur de 0 de taille _height*_width
        CMatrix mat_res(_height, _width, std::vector<double>(_height * _width, 0)); 
        for (int i=0;i<_height*_width;i++)
            {
                mat_res._coefs[i]=_coefs[i]+mat._coefs[i];
            }
        return mat_res;
    }

CMatrix CMatrix::sub(const CMatrix& mat) const 
{
    CMatrix mat_res(_height,_width, std::vector<double>(_height*_width,0));
    for (int i=0;i<_height*_width;i++)
    {
        mat_res._coefs[i]=_coefs[i]-mat._coefs[i];
    }
    return mat_res;
}

CMatrix CMatrix::homo(const double lambda) const
    {
      CMatrix mat_res(_height, _width, std::vector<double>(_height * _width, 0));
      for (int i=0;i<_height*_width;i++)
      {
          mat_res._coefs[i]=lambda*_coefs[i];
      }  
      return mat_res;
    }

CMatrix CMatrix::mult(const CMatrix& mat) const
    {
        CMatrix mat_res(_height,mat._width,std::vector<double>(_height*mat._width,0));
        for (int i=0;i<_height;i++)
        {
            for (int j=0;j<mat._width;j++)
            {
                for (int k=0;k<_width;k++)
                {
                    mat_res._coefs[i*mat._width+j]+= _coefs[i*_width+k]*mat._coefs[k*mat._width+j];
                }
            }
        }
        return mat_res;
    }

void CMatrix::display() const
    {
        for (int i=0;i<_height;i++)
        {
            for (int j=0;j<_width;j++)
            {
                std::cout<<_coefs[i*_width+j] << " ";
            }
            std::cout<<std::endl;
        }
    }
