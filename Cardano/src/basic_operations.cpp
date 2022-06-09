
/*****************************************************************************
 * basic_operations.cpp
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

#include "include/basic_operations.h"
#include <typeinfo>

/**
 * @brief operator + this redefinition of the sum operator for two array with same
 * size. If the dimensions of the two matrices do not concide, an exception is throws.
 * @param leftOperand first array.
 * @param rightOperand second array.
 * @return is defined by the dynamic type of the first operand.
 */
Matrix* operator+(const Matrix& leftOperand, const Matrix& rightOperand) {
    if(leftOperand.getRows() != rightOperand.getRows() || leftOperand.getColumns() != rightOperand.getColumns())
        throw exception("The two matrices must be of the same size");

    Matrix* result;
    if(leftOperand.getRows() == leftOperand.getColumns())
        result = new SquareMatrix(leftOperand.getRows());
    else {
        if(leftOperand.getRows() == 1)
            result = new RowVector(leftOperand.getColumns());
        else {
            if(leftOperand.getColumns() == 1)
                result = new ColumnVector(leftOperand.getRows());
            else
                result = new Matrix(leftOperand.getRows(), leftOperand.getColumns());
        }
    }

    for(unsigned int i = 0; i < result->getRows(); ++i)
        for(unsigned int j = 0; j < result->getColumns(); ++j)
            result->setValue(i, j, leftOperand.getValue(i, j) + rightOperand.getValue(i, j));

    return result;
}


/**
 * @brief operator - this redefinition of the different operator for two array with same
 * size. If the dimensions of the two matrices do not concide, an exception is throws.
 * @param leftOperand first array.
 * @param rightOperand second array.
 * @return defined by the dynamic type of the first operand.
 */
Matrix* operator-(const Matrix& leftOperand, const Matrix& rightOperand) {
    if(leftOperand.getRows() != rightOperand.getRows() || leftOperand.getColumns() != rightOperand.getColumns())
        throw exception("The two matrices must be of the same size");

    Matrix* result;
    if(leftOperand.getRows() == leftOperand.getColumns())
        result = new SquareMatrix(leftOperand.getRows());
    else {
        if(leftOperand.getRows() == 1)
            result = new RowVector(leftOperand.getColumns());
        else {
            if(leftOperand.getColumns() == 1)
                result = new ColumnVector(leftOperand.getRows());
            else
                result = new Matrix(leftOperand.getRows(), leftOperand.getColumns());
        }
    }

    for(unsigned int i = 0; i < result->getRows(); ++i)
        for(unsigned int j = 0; j < result->getColumns(); ++j)
            result->setValue(i, j, leftOperand.getValue(i, j) - rightOperand.getValue(i, j));

    return result;
}


/**
 * @brief operator * redefinition of the multiplication operator between a matrix and a scalar.
 */
Matrix* operator*(const Matrix& matrix, double scalar) {
    Matrix* result;
    if(matrix.getRows() == matrix.getColumns())
        result = new SquareMatrix(matrix.getRows());
    else {
        if(matrix.getRows() == 1)
            result = new RowVector(matrix.getColumns());
        else {
            if(matrix.getColumns() == 1)
                result = new ColumnVector(matrix.getRows());
            else
                result = new Matrix(matrix.getRows(), matrix.getColumns());
        }
    }

    for(unsigned int i = 0; i < result->getRows(); ++i)
        for(unsigned int j = 0; j < result->getColumns(); ++j)
            result->setValue(i, j, matrix.getValue(i, j) * scalar);

    return result;
}


/**
 * @brief operator * redefinition of the multiplication operator between a scalar and a matrix.
 */
Matrix* operator*(double scalar, const Matrix& matrix) {
    Matrix* result;
    if(matrix.getRows() == matrix.getColumns())
        result = new SquareMatrix(matrix.getRows());
    else {
        if(matrix.getRows() == 1)
            result = new RowVector(matrix.getColumns());
        else {
            if(matrix.getColumns() == 1)
                result = new ColumnVector(matrix.getRows());
            else
                result = new Matrix(matrix.getRows(), matrix.getColumns());
        }
    }

    for(unsigned int i = 0; i < result->getRows(); ++i)
        for(unsigned int j = 0; j < result->getColumns(); ++j)
            result->setValue(i, j, matrix.getValue(i, j) * scalar);

    return result;
}


/**
 * @brief operator * Redefinition of the product between two arrays.
 * If the number of columns of the first Matrix does not coincide with
 * the number of rows of the second matrix, an exception is thrown.
 * @return is determined by the number of columnsand rows of the result matrix.
 */
Matrix* operator*(const Matrix& leftOperand, const Matrix& rightOperand) {
    if(leftOperand.getColumns() != rightOperand.getRows())
        throw exception("The number of columns of the first matrix must be the same as the numbero of rows of the second matrix");

    Matrix* result;
    if(leftOperand.getRows() == rightOperand.getColumns())
        result = new SquareMatrix(leftOperand.getRows());
    else {
        if(leftOperand.getRows() == 1)
            result = new RowVector(rightOperand.getColumns());
        else {
            if(rightOperand.getColumns() == 1)
                result = new ColumnVector(leftOperand.getRows());
            else
                result = new Matrix(leftOperand.getRows(), rightOperand.getColumns());
        }
    }

    for(unsigned int i = 0; i < result->getRows(); ++i)
        for(unsigned int j = 0; j < result->getColumns(); ++j){
            double t = 0;
            for(unsigned int k = 0; k < leftOperand.getColumns(); ++k)
                t += (leftOperand.getValue(i, k) * rightOperand.getValue(k, j));

            result->setValue(i, j, t);
        }

    return result;
}
