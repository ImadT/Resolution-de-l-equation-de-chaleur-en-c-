#include "matrix.h"
#include <stdio.h>
#include "string.h"

namespace ensiie {
  
  Matrix::Matrix(int nl, int nc) {
    if (nl <= 0 || nc <= 0) {
      throw "invalid size";
    }
    nl_ = nl;
    nc_ = nc;
    data_ = new double[nl * nc];
  }

  Matrix::Matrix(const Matrix& m) : Matrix(m.get_nl(), m.get_nc()) {
    memcpy(data_, m.data_, m.get_nl() * m.get_nc() * sizeof(double));
  }

  Matrix::~Matrix() {
    delete[] data_;
  }

  bool Matrix::same_size(const Matrix& m) const {
    return nl_ == m.nl_ && nc_ == m.nc_;
  }

    double Matrix::operator()(int l, int c) const {
    if (l < 0 || l >= get_nl() || c < 0 || c >= get_nc()) {
      throw "wrong indexes";
    }

    return data_[c + get_nc() * l];
  }

  double& Matrix::operator()(int l, int c) {
    if (l < 0 || l >= get_nl() || c < 0 || c >= get_nc()) {
      throw "wrong indexes";
    }

    return data_[c + get_nc() * l];
  }

  std::ostream& operator<<(std::ostream& st, const Matrix& m) {
    for (int i = 0; i < m.nl_; i++) {
      for (int j = 0; j < m.nc_; j++) {
        st << m(i, j);
        if (j < m.nc_ - 1) {
          st << " ";
        }
      }

      st << std::endl;
    }
    return st;
  }
}