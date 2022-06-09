
/*****************************************************************************
 * matrix.h
 *
 * Created: 08.06.2022 2022 by Alex Povod
 *
 * Copyright (c) 2020. All rights reserved
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/
#ifndef MATRIX_H
#define MATRIX_H

#include <include/exception.h>
#include <iostream>
#include <iomanip>

class Matrix
{
private:
    unsigned int columns;
    unsigned int rows;
    double** data;

public: Matrix(unsigned int rows, unsigned int columns); /// Constructor
        Matrix( const Matrix& temp);    /// Copy constructor

//    Matrix& operator=(const Matrix&);
//    Matrix& operator+(const Matrix&);
//    Matrix& operator-(const Matrix&);
//    Matrix& operator*(const Matrix&);

    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;


    void setValue(unsigned int i, unsigned int j, double value);

    double getValue(unsigned int i, unsigned int j) const;

    virtual Matrix* transpose() const;
    virtual Matrix* triangularize() const;
    virtual unsigned int getRows() const;
    virtual unsigned int getColumns() const;

};

std::ostream& operator <<(std::ostream& os, const Matrix& temp);

#endif // MATRIX_H
