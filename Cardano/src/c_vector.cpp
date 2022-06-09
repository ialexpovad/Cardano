
/*****************************************************************************
 * c_vector.cpp
 *
 * Created: 09.06.2022 2022 by Alex Povod
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
#include "include/c_vector.h"
#include "include/r_vector.h"

/**
 * @brief c_vector::c_vector - constructor.
 * @param rows set a column vector object with a size of num of rows x 1.
 */
c_vector::c_vector(unsigned int rows) : Vector(rows, 1) { }

/**
 * @brief c_vector::setValue  method sets the value of the invocation column vector element
 * to position row value.
 */
void c_vector::setValue(unsigned int row, double value) { Matrix::setValue(row, 0, value); }


/**
 * @brief c_vector::triangularize
 * @return returns a copy of the triangularized invocation vector,
 * that is, where all elements (i, j) with j < i are equal to 0.
 */
c_vector* c_vector::triangularize() const
{
    c_vector* temp = new c_vector(getRows());
    Matrix* aux = Matrix::triangularize();
    for(unsigned int i = 0; i < getRows(); ++i)
        temp->setValue(i, aux->getValue(0, i));
    delete aux;
    return temp;
}

/**
 * @brief c_vector::transpose method
 * @return transposed invocation column vector, then returns a pointer
 * to an object of type row vector.
 */
Vector* c_vector::transpose() const
{
    r_vector* temp = new r_vector(getRows());
    for(unsigned int i = 0; i < getRows(); ++i)
        temp->setValue(i, getValue(i));
    return temp;
}

/**
 * @brief c_vector::euclideanNorm
 * @return the invocation vector norm.
 */
double  c_vector::euclideanNorm() const
{
    double result = 0;
    for(unsigned int i = 0; i < getRows(); ++i)
        result += (pow(getValue(i), 2));
    return sqrt(result);
}

/**
 * @brief ColumnVector::getColumns method.
 * @return  number of columns of the invocation vector, i.e. always returns 1.
 */
unsigned int c_vector::getColumns() const { return 1; }

/**
 * @brief c_vector::getValue method.
 * @param i-component position.
 * @return  value of the invocation vector element to position i.
 */
double c_vector::getValue(unsigned int i) const { return Matrix::getValue(i, 0); }
