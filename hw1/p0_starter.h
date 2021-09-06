//===----------------------------------------------------------------------===//
//
//
//
// p0_starter.h
//
// Identification: src/include/primer/p0_starter.h
//
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <memory>
#include <stdexcept>
#include <vector>


//#include "common/exception.h"

namespace scudb {

/**
 * The Matrix type defines a common
 * interface for matrix operations.
 */
template <typename T>
class Matrix {
 protected:
  /**
   * TODO(P0): Add implementation
   * 
   * Construct a new Matrix instance.
   * @param rows The number of rows
   * @param cols The number of columns
   *
   */
  Matrix(int rows, int cols) {
      cols_ = cols;
      rows_ = rows;

  }

  /** The number of rows in the matrix */
  int rows_;
  /** The number of columns in the matrix */
  int cols_;

  /**
   * TODO(P0): Allocate the array in the constructor.
   * TODO(P0): Deallocate the array in the destructor.
   * A flattened array containing the elements of the matrix.
   */
  T *linear_;

 public:
  /** @return The number of rows in the matrix */
  virtual int GetRowCount() const = 0;

  /** @return The number of columns in the matrix */
  virtual int GetColumnCount() const = 0;

  /**
   * Get the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @return The (i,j)th matrix element
   * @throws OUT_OF_RANGE if either index is out of range
   */
  virtual T GetElement(int i, int j) const = 0;

  /**
   * Set the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @param val The value to insert
   * @throws OUT_OF_RANGE if either index is out of range
   */
  virtual void SetElement(int i, int j, T val) = 0;

  /**
   * Fill the elements of the matrix from `source`.
   *
   * Throw OUT_OF_RANGE in the event that `source`
   * does not contain the required number of elements.
   *
   * @param source The source container
   * @throws OUT_OF_RANGE if `source` is incorrect size
   */
  virtual void FillFrom(const std::vector<T> &source) = 0;

  /**
   * Destroy a matrix instance.
   * TODO(P0): Add implementation
   */
  virtual ~Matrix() = default;
};

/**
 * The RowMatrix type is a concrete matrix implementation.
 * It implements the interface defined by the Matrix type.
 */
template <typename T>
class RowMatrix : public Matrix<T> {
 public:
  /**
   * TODO(P0): Add implementation
   *
   * Construct a new RowMatrix instance.
   * @param rows The number of rows
   * @param cols The number of columns
   */
  RowMatrix(int rows, int cols) : Matrix<T>(rows, cols) {
      data_ = new T*[rows];
      for (int i = 0; i < rows; i++) {
          data_[i] = new T[cols];
      }
  }

  /**
   * TODO(P0): Add implementation
   * @return The number of rows in the matrix
   */
  int GetRowCount() const override {
      return this->rows_;}

  /**
   * TODO(P0): Add implementation
   * @return The number of columns in the matrix
   */
  int GetColumnCount() const override { return this->cols_;}

  /**
   * TODO(P0): Add implementation
   *
   * Get the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @return The (i,j)th matrix element
   * @throws OUT_OF_RANGE if either index is out of range
   */
  T GetElement(int i, int j) const override {
      if(i>this->rows_||j>this->cols_||i<0||j<0){
          throw std::out_of_range("OUT_OF_RANGE");
      }
      else return data_[i-1][j-1];
  }

  /**
   * Set the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @param val The value to insert
   * @throws OUT_OF_RANGE if either index is out of range
   */
  void SetElement(int i, int j, T val) override {
      if(i>this->rows_||j>this->cols_||i<=0||j<=0){
          throw std::out_of_range("OUT_OF_RANGE");
      }
      else{
          data_[i-1][j-1] = val;
      }
  }

  /**
   * TODO(P0): Add implementation
   *
   * Fill the elements of the matrix from `source`.
   *
   * Throw OUT_OF_RANGE in the event that `source`
   * does not contain the required number of elements.
   *
   * @param source The source container
   * @throws OUT_OF_RANGE if `source` is incorrect size
   */
  void FillFrom(const std::vector<T> &source) override {
      int size = this->rows_*this->cols_;
      if(source.size() != size){
          throw std::out_of_range("OUT_OF_RANGE");
      }
      else{
          for(int i = 0; i<this->rows_; i++){
              for(int j = 0; j<this->cols_; j++){
                  data_[i][j] = source[i*this->cols_+j];
              }
          }
      }
  }

  /**
   * TODO(P0): Add implementation
   *
   * Destroy a RowMatrix instance.
   */
  ~RowMatrix() override = default;

 private:
  /**
   * A 2D array containing the elements of the matrix in row-major format.
   *
   * TODO(P0):
   * - Allocate the array of row pointers in the constructor.
   * - Use these pointers to point to corresponding elements of the `linear` array.
   * - Don't forget to deallocate the array in the destructor.
   */
  T **data_;
};

/**
 * The RowMatrixOperations class defines operations
 * that may be performed on instances of `RowMatrix`.
 */
template <typename T>
class RowMatrixOperations {
 public:
  /**
   * Compute (`matrixA` + `matrixB`) and return the result.
   * Return `nullptr` if dimensions mismatch for input matrices.
   * @param matrixA Input matrix
   * @param matrixB Input matrix
   * @return The result of matrix addition
   */
  static std::unique_ptr<RowMatrix<T>> Add(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB) {
    // TODO(P0): Add implementation
      if(matrixA->GetColumnCount()!=matrixB->GetColumnCount()||matrixA->GetRowCount()!=matrixB->GetRowCount()){
          return std::unique_ptr<RowMatrix<T>>(nullptr);
      }
      else {
          RowMatrix<T> *matrixAdd = new RowMatrix<T>(matrixB->GetRowCount(), matrixB->GetColumnCount());
          for (int i = 1; i <= matrixB->GetRowCount(); i++) {
              for (int j = 1; j <= matrixB->GetColumnCount(); j++) {
                  T temp = matrixA->GetElement(i, j) + matrixB->GetElement(i, j);
                  matrixAdd->SetElement(i,j,temp);
              }
          }
          return std::unique_ptr<RowMatrix<T>>(matrixAdd);
      }
  }

  /**
   * Compute the matrix multiplication (`matrixA` * `matrixB` and return the result.
   * Return `nullptr` if dimensions mismatch for input matrices.
   * @param matrixA Input matrix
   * @param matrixB Input matrix
   * @return The result of matrix multiplication
   */
  static std::unique_ptr<RowMatrix<T>> Multiply(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB) {
    // TODO(P0): Add implementation
      if(matrixA->GetColumnCount()!=matrixB->GetRowCount()){
          return std::unique_ptr<RowMatrix<T>>(nullptr);
      }
      else {
          RowMatrix<T> *matrixMul = new RowMatrix<T>(matrixA->GetRowCount(), matrixB->GetColumnCount());
          for (int i = 1; i <= matrixA->GetRowCount(); i++) {
              for (int j = 1; j <= matrixB->GetColumnCount(); j++) { 
                  T temp;
                  for(int k = 1; k<=matrixA->GetColumnCount(); k++) {
                      if (k == 1) {
                          temp = matrixA->GetElement(i, k) * matrixB->GetElement(k, j);
                      }
                      else temp += matrixA->GetElement(i, k) * matrixB->GetElement(k, j);                
                  }
                  matrixMul->SetElement(i, j, temp);
              }
          }
          return std::unique_ptr<RowMatrix<T>>(matrixMul);
      }
  }

  /**
   * Simplified General Matrix Multiply operation. Compute (`matrixA` * `matrixB` + `matrixC`).
   * Return `nullptr` if dimensions mismatch for input matrices.
   * @param matrixA Input matrix
   * @param matrixB Input matrix
   * @param matrixC Input matrix
   * @return The result of general matrix multiply
   */
  static std::unique_ptr<RowMatrix<T>> GEMM(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB,
                                            const RowMatrix<T> *matrixC) {
      if(matrixA->GetColumnCount()!=matrixB->GetRowCount()||matrixA->GetRowCount()!=matrixC->GetRowCount()||matrixB->GetColumnCount()!=matrixC->GetColumnCount()){
          return std::unique_ptr<RowMatrix<T>>(nullptr);
      }
      else {
          RowMatrix<T> *matrixAdd = new RowMatrix<T>(matrixA->GetRowCount(), matrixB->GetColumnCount());
          for (int i = 1; i <= matrixA->GetRowCount(); i++) {
              for (int j = 1; j <= matrixB->GetColumnCount(); j++) {
                  T temp;
                  for(int k = 1; k<=matrixA->GetColumnCount(); k++) {
                      if (k == 1) {
                          temp = matrixA->GetElement(i, k) * matrixB->GetElement(k, j);
                      }
                      else temp += matrixA->GetElement(i, k) * matrixB->GetElement(k, j);
                  }
                  temp += matrixC->GetElement(i,j);
                  matrixAdd->SetElement(i, j, temp);
              }
          }

          return std::unique_ptr<RowMatrix<T>>(matrixAdd);
      }
  }
};
}  // namespace scudb
