#include "includes/CMatrix.h"

CMatrix::CMatrix(int height, int width, std::vector<double> coefs):
    _height(height),
    _width(width),
    _coefs(coefs)
{}

CMatrix::~CMatrix() {}

int CMatrix::position(const int i, const int j) const //be careful, i and j start from 0!
{
    if (_width*i+j < _width*_height)
    {
        return _width*i +j;
    }
    else
    {
        std::cout<<"position out of range"<<std::endl;
        return 0;
    }
     
}

std::vector<int> CMatrix::dimensions() const
{
    return std::vector<int> ({_height, _width});
}

double CMatrix::get_coef_1D(const int i) const
{
    if (i<_width*_height)
    {
        return _coefs[i];
    }
    else
    {
        std::cout<<"get_coef_1D out of range"<<std::endl;
        return 1.0;
    }
    
}
double CMatrix::get_coef_2D(const int i, const int j) const//be careful, i and j start from 0!
{
    if (i<_height && j<_width)
    {
        int p = position(i,j);
        return _coefs[p];
    }
    else
    {
        std::cout<<"get_coef_2D out of range"<<std::endl;
        return 2.0;
    }
    
}

void CMatrix::set_coef_1D(const int i, const double coef)
{
    if (i<_width*_height)
    {
        _coefs[i] = coef;
    }
    else
    {
        std::cout<<"set_coef_1D out of range"<<std::endl;
    }
    
}

void CMatrix::set_coef_2D(const int i, const int j, const double coef)//be careful, i and j start from 0!
{
    if (i<_height && j<_width)
    {
        int p = position(i,j);
        _coefs[p] = coef;
    }
    else
    {
        std::cout<<"set_coef_2D out of range"<<std::endl;
    }
    
}

CMatrix CMatrix::transpose() const
{
    CMatrix mat_res(_width,_height,std::vector<double>(_width*_height,0));
    for (int i=0;i<_width;i++)
    {
        for (int j=0;j<_height;j++)
        {
            int p1=mat_res.position(i,j);
            int p2=position(j,i);
            mat_res._coefs[p1]=_coefs[p2];
        }
    }
    return mat_res;
}


//maths
CMatrix CMatrix::sum(const CMatrix& mat) const
    {
        if (_height == mat._height && _width == mat._width)
        {
        // on crée une matrice de taille _height*_width, et ses coefficients sont un vecteur de 0 de taille _height*_width
        CMatrix mat_res(_height, _width, std::vector<double>(_height * _width, 0)); 
        for (int i=0;i<_height*_width;i++)
            {
                mat_res._coefs[i]=_coefs[i]+mat._coefs[i];
            }
        return mat_res;
        }
        else
        {
            std::cout<<"sum error : different dimensions matrices"<<std::endl;
            return mat;
        }
        
    }

CMatrix CMatrix::sub(const CMatrix& mat) const 
{
    if (_height == mat._height && _width == mat._width)
    {
     CMatrix mat_res(_height,_width, std::vector<double>(_height*_width,0));
    for (int i=0;i<_height*_width;i++)
    {
        mat_res._coefs[i]=_coefs[i]-mat._coefs[i];
    }
    return mat_res;
    }
    else 
    {
        std::cout<<"sub error : different dimensions matrices"<<std::endl;
        return mat;
    }

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
        if (_width == mat._height)
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
        else
        {
            std::cout<<"mult error : not compatible matrices"<<std::endl;
            return mat;
        }

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

double CMatrix::max_coef()const
{
    double max {0};
    if (_coefs[0]>=0)
    {
        max = _coefs[0];
    }
    else
    {
        max = -_coefs[0];
    }
    
    for (int i=0;i<_height*_width;i++)
    {
        if (_coefs[i]>=0 && _coefs[i]>max)
        {
            max = _coefs[i];
        }
        else if (_coefs[i]<0 && -_coefs[i]>max)
        {
            max = -_coefs[i];
        }
    }
    return max;
}
