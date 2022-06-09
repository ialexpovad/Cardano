
/*****************************************************************************
 * r_vector.cpp
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
#include "include/r_vector.h"
#include "include/c_vector.h"


/**
 * @brief r_vector::r_vector - constructor.
 * @param columns set a row vector object with a size of 1 x num of columns.
 */
r_vector::r_vector(unsigned int columns) : Vector(1, columns) { }

/**
 * @brief r_vector::setValue method sets the value of the invocation row vector element
 * to position column value.
 */
void r_vector::setValue(unsigned int columns, double value) { Matrix::setValue(0, columns, value); }

/**
 * @brief r_vector::triangularize
 * @return returns a copy of the triangularized invocation vector,
 * that is,where all elements (i, j) with < < i are equal to 0.
 */
r_vector* r_vector::triangularize() const
{
    r_vector* temp = new r_vector(getColumns());
    Matrix* aux = Matrix::triangularize();
    for(unsigned int i = 0; i < getColumns(); ++i)
        temp->setValue(i, aux->getValue(0, i));
    delete aux;
    return temp;
}

/**
 * @brief r_vector::transpose method
 * @return returns the transposed invocation row vector,
 * then returns a pointer to an object of type column vector.
 */
Vector* r_vector::transpose() const
{
    c_vector* temp = new c_vector(getColumns());
    for(unsigned int j = 0; j < getColumns(); ++j)
        temp->setValue(j, getValue(j));
    return temp;
}
/**
 * @brief r_vector::euclideanNorm method returns the invocation vector norm.
 * @return double value.
 */
double r_vector::euclideanNorm() const
{
    double result = 0;
    for(unsigned int j = 0; j < getColumns(); ++j)
        result += (pow(getValue(j), 2));
    return sqrt(result);
}

/**
 * @brief RowVector::getRows method
 * @return number of rows of the invocation vector, i.e. always returns 1.
 */
unsigned int r_vector::getRows() const { return 1; }

/**
 * @brief RowVector::getValue method
 * @param j-component position.
 * @return  value of the invocation vector element to position j
 */
double r_vector::getValue(unsigned int j) const { return Matrix::getValue(0, j); }

