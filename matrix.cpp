#include <iostream>
#include <stdexcept>
#include "matrix.h"

Matrix::Matrix() : matr_rows(0), matr_cols(0), matrix (NULL)
{

}

Matrix::Matrix(const Matrix& other)
{
    matrix = new double* [other.matr_rows];
    matr_rows = other.matr_rows;
    matr_cols = other.matr_cols;
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        matrix[i] = new double[matr_cols];
    }
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        for (unsigned j = 0; j < matr_cols; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix(unsigned rows, unsigned cols) : matr_rows(rows), matr_cols(cols)
{
    matrix = new double* [matr_rows];
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        matrix[i] = new double[matr_cols];
    }
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        for (unsigned j = 0; j < matr_cols; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (unsigned i = 0; i < matr_rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


Matrix::Matrix(const Matrix& matr, unsigned row, unsigned col) : matr_rows(matr.matr_rows - 1), matr_cols(matr.matr_cols - 1)
{
    matrix = new double* [matr_rows];
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        matrix[i] = new double[matr_cols];
    }
    for (unsigned i = 0; i < matr.matr_rows; ++i)
    {
        if (i < row)
        {
            for (unsigned j = 0; j < matr.matr_cols; ++j)
            {
                if (j < col)
                       matrix[i][j] = matr.matrix[i][j];
                if (j > col)
                    matrix[i][j - 1] = matr.matrix[i][j];
            }
        }
        if (i > row)
        {
            for (unsigned j = 0; j < matr.matr_cols; ++j)
            {
                if (j < col)
                    matrix[i - 1][j] = matr.matrix[i][j];
                if (j > col)
                    matrix[i - 1][j - 1] = matr.matrix[i][j];
            }
        }
    }
}

double& Matrix::el(unsigned i, unsigned j) const
{
    if (i < matr_rows && j < matr_cols)
    {
        return matrix[i][j];
    }
    else
    {
        throw (std::out_of_range("Array::operator[] wrong index"));
    }
}

Matrix& Matrix::operator = (const Matrix& other)
{
    if (this != &other)
    {
        this->matr_rows = other.matr_rows;
        this->matr_cols = other.matr_cols;
        this->matrix = other.matrix;
    }
    return *this;
}

Matrix Matrix::operator + (const Matrix& right) const
{
    if ((matr_rows == right.matr_rows) && (matr_cols == right.matr_cols))
    {
        Matrix result(matr_rows, matr_cols);
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < matr_cols; ++j)
            {
                result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
            }
        }
        return result;
    }
    else
    {
        Matrix res;
        return res;
    }
}

Matrix Matrix::operator - (const Matrix& right) const
{
    if ((matr_rows == right.matr_rows) && (matr_cols == right.matr_cols))
    {
        Matrix result(matr_rows, matr_cols);
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < matr_cols; ++j)
            {
                result.matrix[i][j] = matrix[i][j] - right.matrix[i][j];
            }
        }
        return result;
    }
    else
    {
        Matrix res;
        return res;
    }
}

Matrix Matrix::operator * (const Matrix& right)  const
{
    if (matr_cols == right.matr_rows)
    {
        Matrix result(matr_rows, right.matr_cols);
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < right.matr_cols; ++j)
            {
                for (unsigned k = 0; k < matr_cols; ++k)
                {
                    result.matrix[i][j] += matrix[i][k] * right.matrix[k][j];
                }
            }
        }
        return result;
    }
    else
    {
        Matrix res;
        return res;
    }
}

Matrix Matrix::operator * (const double scalar)  const
{
    Matrix result(matr_rows, matr_cols);
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        for (unsigned j = 0; j < matr_cols; ++j)
        {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

bool Matrix::operator == (const Matrix& right) const
{
    if (matr_rows == right.matr_rows && matr_cols == right.matr_cols)
    {
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < matr_cols; ++j)
            {
                if (matrix[i][j] != right.matrix[i][j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool Matrix::operator == (const double scalar) const
{
    for (unsigned i = 0; i < matr_rows; ++i)
    {
        for (unsigned j = 0; j < matr_cols; ++j)
        {
            if (i == j)
            {
                if (matrix[i][j] != scalar)
                    return false;
            }
            else
            {
                if (matrix[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool Matrix::operator != (const Matrix& right) const
{
    if (matr_rows != right.matr_rows || matr_cols != right.matr_cols)
    {
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < matr_cols; ++j)
            {
                if (matrix[i][j] != right.matrix[i][j])
                    return true;
            }
        }
        return false;
    }
    return true;
}

Matrix Matrix::elem_preobr_1(unsigned row1, unsigned row2)
{
    if (row1 > 0 && row1 <= matr_rows && row2 > 0 && row2 <= matr_rows)
    {
        Matrix res(*this);
        double temp;
        for (unsigned i = 0; i < matr_cols; ++i)
        {
            temp = res.matrix[row1 - 1][i];
            res.matrix[row1 - 1][i] = res.matrix[row2 - 1][i];
            res.matrix[row2 - 1][i] = temp;
        }
        return res;
    }
    else
    {
        Matrix res;
        return res;
    }
}

Matrix Matrix::elem_preobr_2(unsigned row, double scalar)
{
    if (row > 0 && row <= matr_rows)
    {
        if (scalar != 0)
        {
            Matrix res = Matrix(*this);
            for (unsigned i = 0; i < matr_cols; ++i)
            {
                res.matrix[row - 1][i] = res.matrix[row - 1][i] * scalar;
            }
            return res;
        }
        else
        {
            Matrix res;
            return res;
        }
    }
    else
    {
        Matrix res;
        return res;
    }
}

Matrix Matrix::elem_preobr_3(unsigned row1, unsigned row2, double scalar)
{
    if (row1 > 0 && row1 <= matr_rows && row2 > 0 && row2 <= matr_rows)
    {
        Matrix res = Matrix(*this);
        for (unsigned i = 0; i < matr_cols; ++i)
        {
            res.matrix[row1 - 1][i] += res.matrix[row2 - 1][i] * scalar;
        }
        return res;
    }
    else
    {
        Matrix res;
        return res;
    }
}

double Matrix::determ() const
{
    if (matr_rows == matr_cols)
    {
        if (matr_rows == 1)
        {
            return matrix[0][0];
        }
        else {
            double determ = 0;
            for (unsigned i = 0; i < matr_cols; ++i)
            {
                Matrix minmatr(*this, 0, i);
                if ((i % 2) == 0)
                    determ += matrix[0][i] * minmatr.determ();
                else
                    determ -= matrix[0][i] * minmatr.determ();
            }
            return determ;
        }
    }
    throw ("Not Possible!");
}

Matrix Matrix::operator ! ()
{
    double det = this->determ();
    if (det != 0)
    {
        Matrix A_matr(matr_rows, matr_cols);
        for (unsigned i = 0; i < matr_rows; ++i)
        {
            for (unsigned j = 0; j < matr_cols; ++j)
            {
                Matrix minmatr(*this, i, j);
                {
                    double mindet = minmatr.determ();
                    if (((i + j) % 2) == 0)
                        A_matr.matrix[i][j] = mindet;
                    else
                    {
                        A_matr.matrix[i][j] = -1 * mindet;
                    }
                }
            }
        }
        
        Matrix A_matr_transp = A_matr.transpose();

        double det1 = 1 / det;

        Matrix res = A_matr_transp * det1;

        return res;
    }
    throw ("Not Possible!");
}

Matrix Matrix::transpose() const
{
    Matrix matr_transpose(matr_cols, matr_rows);
    for (unsigned i = 0; i < matr_cols; ++i)
    {
        for (unsigned j = 0; j < matr_rows; ++j)
            matr_transpose.matrix[i][j] = matrix[j][i];
    }
    return matr_transpose;
}

std::istream& operator >> (std::istream& is, Matrix& matr)
{
    for (unsigned i = 0; i < matr.getrows(); ++i)
    {
        for (unsigned j = 0; j < matr.getcols(); ++j)
        {
            is >> matr.el(i, j);
        }
    }
    return is;
}

std::ostream& operator << (std::ostream& os, Matrix& matr)
{
    for (unsigned i = 0; i < matr.getrows(); ++i)
    {
        os << matr.el(i, 0);
        for (unsigned j = 1; j < matr.getcols(); ++j)
        {
            os << " " << matr.el(i, j);
        }
        os << std::endl;
    }
    return os;
}