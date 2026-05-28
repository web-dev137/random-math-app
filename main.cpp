#include <iostream>
#include <decompose/LU/LU.hpp>
#include <matrix/FlatMatrix.hpp>
#include <decompose/LU/Inversion.hpp>
#include <memory>

int main() {
    using namespace LinearAlgebra;
    
    FlatMatrix<double> X = {
        {1,1},
        {1,2},
        {1,3},
        {1,4}
    };

    ColumnVector<double> y = {2,4,5,7};

    auto XT = ~X;
    auto XTX = XT*X;
    auto XTy = XT*y;
    auto lu = LU<double,FlatMatrix<double>>(XTX);
    auto I = Inversion<double,FlatMatrix<double>>(lu);
    auto Xinv = I.inv();
    auto B = Xinv * XTy;
   
    std::cout << "Input data:\n";
    std::cout << "X: " << X << "\n";
    std::cout << "y:" << std::endl;
    for (int i = 0; i < y.size(); i++)
    {
        std::cout<<y[i]<<"\n";
    }
    std::cout << std::endl;

    std::cout << "Computing linear regression coefficients "
            << "B0 and B1 using the least squares method B = (X^T X)^-1 X^T y:\n";

    std::cout << "B0 = " << B[0,0] << "\n";
    std::cout << "B1 = " << B[1,0] << std::endl;
}