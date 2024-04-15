#ifndef Matrix_HPP
#define Matrix_HPP

#include <iostream>
#include <fstream>

template <typename T>
class Matrix
{
        size_t matr_rows;
        size_t matr_cols;
        T** matrix;

    public:
        Matrix () : matr_rows(0), matr_cols(0), matrix (NULL)// пустой
        {}

        Matrix (size_t rows, size_t cols) : matr_rows(rows), matr_cols(cols), matrix (NULL)//с заданными размерами
        {
            /*matrix = new double* [matr_rows];
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
            }*/
        }

        Matrix (const Matrix<T> &other)//копирования
        {
            matrix = new T* [other.matr_rows];
            matr_rows = other.matr_rows;
            matr_cols = other.matr_cols;
            for (unsigned i = 0; i < matr_rows; ++i)
            {
                matrix[i] = new T[matr_cols];
            }
            for (unsigned i = 0; i < matr_rows; ++i)
            {
                for (unsigned j = 0; j < matr_cols; ++j)
                {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }

        Matrix (const Matrix<T>& matr, size_t row, size_t col)//создание алгебраического дополнения
        {
            matrix = new T* [matr_rows];
            for (unsigned i = 0; i < matr_rows; ++i)
            {
                matrix[i] = new T[matr_cols];
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

        Matrix (std::ifstream& is)//считывание из файла
        {
            if (is.is_open())
            {
                is >> matr_rows;
                is >> matr_cols;

                matrix = new T* [matr_rows];
                
                for (size_t i = 0; i < matr_rows; ++i)
                {
                    matrix[i] = new T[matr_cols];
                }   
                for (size_t i = 0; i < matr_rows; ++i)
                {
                    for (size_t j = 0; j < matr_cols; ++j)
                    {
                        is >> matrix[i][j];
                    }
                }
            }

            else
            {
                throw "Stream is not opened";
            }
        }

        ~Matrix ()//деструктор
        {
            for (unsigned i = 0; i < matr_rows; ++i) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        T& el (size_t i, size_t j) const //возврат элемента
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

        size_t& getrows() {return matr_rows;} //возврат количества строк
        size_t& getcols() {return matr_cols;} //возврат количества столбцов

        /*Matrix& operator =  (const Matrix &);
        Matrix operator +   (const Matrix &) const;
        Matrix operator -   (const Matrix &) const;
        Matrix operator *   (const Matrix &) const;
        Matrix operator *   (const double)   const;
        bool   operator ==  (const Matrix &) const;
        bool   operator ==  (const double)   const;
        bool   operator !=  (const Matrix &) const;

        Matrix elem_preobr_1 (unsigned, unsigned);
        Matrix elem_preobr_2 (unsigned, double);
        Matrix elem_preobr_3 (unsigned, unsigned, double);
        
        double determ () const;
        Matrix operator ! ();
        Matrix transpose() const;*/
};

/*std::istream& operator >> (std::istream& is, Matrix& matr)
{
    for (unsigned i = 0; i < matr.getrows(); ++i)
    {
        for (unsigned j = 0; j < matr.getcols(); ++j)
        {
            is >> matr.el(i, j);
        }
    }
    return is;
}*/

template <typename T> // вывод матрицы
std::ostream& operator << (std::ostream& os, Matrix<T>& matr)
{
    for (size_t i = 0; i < matr.getrows(); ++i)
    {
        os << matr.el(i, 0);
        for (size_t j = 1; j < matr.getcols(); ++j)
        {
            os << " " << matr.el(i, j);
        }
        os << std::endl;
    }
    return os;
}

#endif