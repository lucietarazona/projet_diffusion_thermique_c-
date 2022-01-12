#pragma once
#include <iostream>
#include <vector>

class CMatrix
{
public:
    CMatrix(int height, int width, std::vector<double> coefs);
    ~CMatrix();
    int position(const int i, const int j) const ;
    std::vector<int> dimensions() const ;
    double get_coef(const int i, const int j) const;
    void set_coef(const int i, const int j, const double coef);
    CMatrix sum(const CMatrix& mat) const;
    CMatrix sub(const CMatrix& mat) const;
    CMatrix homo(const double lambda) const;
    CMatrix mult(const CMatrix& mat) const;
    void display() const;

private: 
   const int _height;
   const int _width;
   std::vector<double> _coefs;

};
