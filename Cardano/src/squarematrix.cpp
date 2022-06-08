
/*****************************************************************************
 * squarematrix.cpp
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
#include "include/squarematrix.h"
/**
 * @brief SquareMatrix::SquareMatrix - constructor with 1 argument
 * square matrix NxN
 * @param width -- num of rows (columns) matrix
 */
SquareMatrix::SquareMatrix(unsigned int width) : Matrix(width, width) {}


/**
 * @brief SquareMatrix::SquareMatrix
 * @param temp
 */
SquareMatrix::SquareMatrix(const Matrix & temp) : Matrix(temp)
{
    if(temp.getColumns() != temp.getRows())
        throw exception("Invalid conversion from Matrix to SquareMatrix");
}
/**
 * @brief SquareMatrix::transpose
 * @return
 */
SquareMatrix* SquareMatrix::transpose() const
{
//    return new SquareMatrix(*Matrix::transpose());
    SquareMatrix* temp = new SquareMatrix(getRows());
    for(unsigned int i = 0; i < getRows(); ++i)
        for(unsigned int j = 0; j < getColumns(); ++j)
            setValue(i, j, getValue(j, i));
    return temp;
}
/**
 * @brief SquareMatrix::triangularize
 * @return
 */
SquareMatrix* SquareMatrix::triangularize() const
{
    return new SquareMatrix(*Matrix::triangularize());
}
/**
 * @brief SquareMatrix::identityMatrix
 * @return
 */
SquareMatrix* SquareMatrix::identityMatrix() const
{
    SquareMatrix* temp = new SquareMatrix(getRows());
    for(unsigned int i = 0; i < getRows(); ++i)
        setValue(i, i, 1);
    return temp;
}

/**
 * @brief SquareMatrix::determinant method defend determinant matrix.
 * @return value determinant in double.
 */
double SquareMatrix::determinant() const {
    if(getRows() == 2)
        return (getValue(0,0) * getValue(1,1)) - (getValue(0,1) * getValue(1,0));

    if(getRows() == 3)
        return (getValue(0,0) * getValue(1,1) * getValue(2,2)) +
                (getValue(0,1) * getValue(1,2) * getValue(2,0)) +
                (getValue(0,2) * getValue(1,0) * getValue(2,1)) -
                (getValue(2,0) * getValue(1,1) * getValue(0,2)) -
                (getValue(2,1) * getValue(1,2) * getValue(0,0)) -
                (getValue(2,2) * getValue(1,0) * getValue(0,1));

    Matrix* temp = triangularize();
    double det = 1;

    for(unsigned int i = 0; i < getRows(); ++i)
        det *= temp->getValue(i, i);

    delete temp;
    return det;
}

/**
 * @brief SquareMatrix::inverseMatrix
 * @return
 */
SquareMatrix* SquareMatrix::inverseMatrix() const
{
    if(determinant() == 0)
        throw exception("Matrix not invertible");

    Matrix* B = new Matrix(getRows(), getColumns() * 2);
    SquareMatrix* result = new SquareMatrix(getRows());
    for(int i = 0; i < getRows(); ++i){
        for(int j = 0; j < getColumns(); ++j)
            B->setValue(i, j, getValue(i, j));
        B->setValue(i, getColumns() + i, 1);
    }
    B = B->triangularize();
    for(int j = getColumns() - 1; j >= 0; --j){
        double pivot = B->getValue(j, j);
        for(int k = j; k < B->getColumns(); ++k)
            B->setValue(j, k, B->getValue(j, k) / pivot);
        for(int i = j - 1; i >= 0; --i){
            if(B->getValue(i, j) != 0){
                double coeff = - B->getValue(i, j);
                for(int k = j; k < B->getColumns(); ++k)
                    B->setValue(i, k, (B->getValue(j, k) * coeff) + B->getValue(i, k));
            }
        }
    }
    for(unsigned int i = 0; i < getRows(); ++i)
        for(unsigned int j = 0; j < getColumns(); ++j)
            result->setValue(i, j, B->getValue(i, j + getColumns()));
    return result;
}

