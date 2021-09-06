#include <iostream>
#include "p0_starter.h"
using namespace scudb;
void printMatrix(RowMatrix<int> matrix) {
    for (int i = 1; i <= matrix.GetRowCount(); i++) {
        for (int j = 1; j <= matrix.GetColumnCount(); j++) {
            std::cout <<matrix.GetElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

int main() {
    RowMatrix<int> matrixA(2, 3), matrixB(3, 4), matrixC(2, 4), matrixD(2, 4);
    std::vector<int> a(5, 1), b(11, 2), c(8, 3), test(5,1);
    a.insert(a.begin() + 3, 5);
    b.insert(b.begin() + 4, 5);
    try{
        matrixA.FillFrom(test);
    }catch (std::out_of_range &e){
        std::cout<<"OUT_OF_RANGE"<<std::endl;
    }
    try {
        matrixA.FillFrom(a);
        matrixB.FillFrom(b);
        matrixC.FillFrom(c);
        matrixD.FillFrom(c);

    }
    catch (std::out_of_range & e) {
        std::cout << "OUT_OF_RANGE" << std::endl;
    }
    matrixA.SetElement(2, 2, 7);

    std::cout << matrixA.GetRowCount() << matrixA.GetColumnCount() << matrixA.GetElement(2, 1) << matrixA.GetElement(2, 2)
         << std::endl;

    std::unique_ptr<RowMatrix<int>> matrixOp(new RowMatrix<int>(matrixC.GetRowCount(),matrixC.GetColumnCount()));
    matrixOp = RowMatrixOperations<int>::Add(&matrixC, &matrixD);
    printMatrix(*matrixOp);

    matrixOp = RowMatrixOperations<int>::Multiply(&matrixA,&matrixB);
    printMatrix(*matrixOp);

    matrixOp = RowMatrixOperations<int>::GEMM(&matrixA,&matrixB,&matrixC);
    printMatrix(*matrixOp);

	return 0; 
}


