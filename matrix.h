#ifndef Matrix_H
#define Matrix_H

class Matrix
{
        unsigned matr_rows;
        unsigned matr_cols;
        double** matrix;

    public:
        Matrix ();
        Matrix (unsigned, unsigned);
        Matrix (const Matrix&);
        Matrix (const Matrix&, unsigned, unsigned);
        ~Matrix ();

        double& el     (unsigned, unsigned) const;
        unsigned& getrows() {return matr_rows;}
        unsigned& getcols() {return matr_cols;}        

        Matrix& operator =  (const Matrix &);
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
        Matrix transpose() const;
};

std::istream& operator >> (std::istream& is, Matrix& matr);
std::ostream& operator << (std::ostream& os, Matrix& matr);

#endif