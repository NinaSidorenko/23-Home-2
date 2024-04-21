#include <iostream>
#include <fstream>
#include "matrix.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{

    Matrix<double> m;
    /*Matrix<double> m1(3, 4);
    Matrix<double> m2 (m1);*/

    std::ifstream in("matrix.txt");

    /*Matrix <int> m3 (in);
    cout << m3.el(1, 1) << endl;

    cout << m1.getrows() << endl;
    cout << m2.getcols() << endl;

    cout << m3;

    std::ifstream in1("matrix.txt");*/
    if (in.is_open())
    {
        in >> m;
    }

    /*cout << m.getrows() << endl;
    cout << m;*/

    Matrix <int> m4;
    cin >> m4;

    /*Matrix<int> m5 = m + m4;

    Matrix<int> m6 = m - m4;

    cout << m5;

    cout << m6;

    Matrix <int> m7 = m*m4;

    cout << m7;*/

    Matrix<double> m8 = m * 3.5;
    cout << m8;

    Matrix<int> m9 = m.zero_matr (5);
    cout << m9;

    Matrix<int> m10 = m.one_matr (5);
    cout << m10;

    Matrix <int> m11 = m4.transpose();
    cout << m11;

    double d = m.determ();
    cout << d << endl;
/*try
{
    Matrix <double> m12 = !m4;
    cout << m12;
}
catch(const std::string& e)
{
    std::cerr << e << '\n';
}*/
    /*unsigned cols;
    cin >> rows;
    cin >> cols;

    Matrix<int> matrix(rows, cols);
    cin >> matrix;
    cout << matrix;

    unsigned rows1;
    unsigned cols1;
    cin >> rows1;
    cin >> cols1;

    Matrix matrix1(rows1, cols1);
    cin >> matrix1;

    std::ifstream in("matrix.txt");
    if (in.is_open())
    {
        in >> matrix1;
    }

    std::ofstream out("matrix1.txt");
    if (out.is_open())
    {
        out << matrix1;
    }

    Matrix matr3 = matrix + matrix1;
    cout << matr3 << endl;

    Matrix matr4 = matrix - matrix1;
    cout << matr4 << endl;

    Matrix matr5 = matrix*matrix1;
    cout << matr5 << endl;

    matr5 = matrix * 2;
    cout << matr5 << endl;

    cout << (matrix == matrix1) << endl;
    cout << (matrix != matrix1) << endl;
    cout << (matrix == 3) << endl;
    cout << (matrix1 == 3) << endl;

    Matrix matr7 = matrix.elem_preobr_1(1, 2);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_1(3, 2);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_2(3, 2);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_2(2, 2);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_2(3, 0);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_3(3, 2, 2);
    cout << matr7 << endl;

    matr7 = matrix.elem_preobr_3(1, 2, 2);
    cout << matr7 << endl;

    cout << (matrix.determ()) << endl;
    cout << (matrix1.determ()) << endl;

    Matrix matr = !matrix;
    cout << matr;
    
    Matrix one = matr * matrix;
    cout << one;

    Matrix transp = matrix.transpose();
    cout << transp;*/

    return 0;
}