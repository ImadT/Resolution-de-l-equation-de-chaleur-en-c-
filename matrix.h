#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>

namespace ensiie {

  class Matrix {
    private:
      int nl_, nc_;
      double* data_;

      

    public:
      Matrix(int nl, int nc = 1);
      Matrix(const Matrix& m);
      ~Matrix();

      int get_nl() const { return nl_; }
      int get_nc() const { return nc_; }

      bool same_size(const Matrix& m) const;

      double operator()(int l, int c = 0) const;
      double& operator()(int l, int c = 0);
      Matrix& operator=(const Matrix& m);

      friend std::ostream& operator<<(std::ostream& st, const Matrix& m);
  };
}

#endif