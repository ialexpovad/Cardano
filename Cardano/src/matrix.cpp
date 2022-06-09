
/*****************************************************************************
 * matrix.cpp
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
#include "include/matrix.h"

/**
 * @brief Matrix::Matrix - constructor
 * With 2 argument. Create object Matrix of size height and width
 * and then sets all values to 0 using the setValue(height,width) method.
 * @param height array (num of rows)
 * @param width array (num of columns)
 */
Matrix::Matrix(unsigned int height, unsigned int width) : rows(height), columns(width)
{
    data = new double* [rows];
    for(unsigned int i = 0; i < rows; ++i)
    {   data[i] = new double[columns];
        for(unsigned int j = 0; j < columns; ++j)
            setValue(i, j, 0);
    }
}

/**
 * @brief Matrix::Matrix - copy constructor
 * @param temp -- temporary variable
 */
Matrix::Matrix(const Matrix &temp) : rows(temp.rows), columns(temp.columns)
{
    data = new double* [rows];
    for(unsigned int i = 0; i < rows; ++i)
    {
        data[i] = new double[columns];
        for(unsigned int j = 0; j < columns; ++j)
            setValue(i, j, temp.getValue(i, j));
    }
}

/**
 * @brief Matrix::setValue
 * @param i-component of matrix (vector)
 * @param j-component of matrix (vector)
 * @param value of matrix
 */
void Matrix::setValue(unsigned int i, unsigned int j, double value)
{
    if(i > rows || j > columns)
        throw exception("Size Error");
    data[i][j] = value;

}
/**
 * @brief Matrix::getValue method for getting components i and j of array.
 * @param i-component.
 * @param j-component.
 * @return double array.
 */
double Matrix::getValue(unsigned int i, unsigned int j) const
{
    if(i > rows || j > columns)
        throw exception("Size Error");
    return data[i][j];
}
/**
 * @brief Matrix::operator =
 * @param temp
 * @return
 */
Matrix& Matrix::operator=(const Matrix& temp)
{
    rows = temp.rows;
    columns = temp.columns;
    if(data)
    {
        for(unsigned int i = 0; i < rows; ++i)
            delete [] data[i];
        delete [] data;
    }
    data = new double* [rows];
    for(unsigned int i = 0; i < rows; ++i){
        data[i] = new double[columns];
        for(unsigned int j = 0; j < columns; ++j)
            setValue(i, j, temp.getValue(i, j));
    }
    return *this;
}

/**
 * @brief Matrix::~Matrix Virtual Distructor.
 */
Matrix::~Matrix(){
    if(data)
    {
        for(unsigned int i = 0; i < rows; ++i)
            delete [] data[i];
        delete [] data;
    }
}
/**
 * @brief Matrix::transpose method returns a copy of transposed matrix.
 * @return matrix.
 */
Matrix* Matrix::transpose() const
{
    Matrix* temp = new Matrix(columns, rows);
    for(unsigned int i = 0; i < temp->rows; ++i)
        for(unsigned int j = 0; j < temp->columns; ++j)
            temp->setValue(i, j, data[j][i]);
    return temp;
}

/**
 * @brief Matrix::triangularize  method returns a copy of triangularized matrix.
 * @return
 */
Matrix* Matrix::triangularize() const {
    Matrix* temp = new Matrix(*this);
    unsigned int counter = rows > columns ? columns : rows;

    for(unsigned int j = 0; j < counter; ++j){
        bool firstNull = (temp->data[j][j] == 0);
        for(unsigned int i = j + 1; i < rows; ++i)
            if(temp->data[i][j] != 0){
                if(firstNull){
                    double* aux = new double[columns];
                    for(unsigned int k = 0; k < columns; ++k)
                        aux[k] = temp->data[i][k];

                    temp->data[i] = temp->data[j];
                    temp->data[j] = aux;
                    delete[] aux;
                    firstNull = false;
                }
                else{
                    double coeff = -(temp->data[i][j] / temp->data[j][j]);
                    for(unsigned int k = 0; k < columns; ++k){
                        temp->data[j][k] *= coeff;
                        temp->data[i][k] += temp->data[j][k];
                    }
                }
            }
    }
    return temp;
}
/**
 * @brief Matrix::getRows - get method for the number of rows of the matrix.
 * @return
 */
unsigned int Matrix::getRows() const { return rows; }

/**
 * @brief Matrix::getColumns - get method for the number of columns of the matrix.
 * @return
 */
unsigned int Matrix::getColumns() const { return columns; }


/**
 * @brief Matrix::operator == overloading the equality operator between two matrices.
 * @param m - matrix
 * @return
 */
bool Matrix::operator==(const Matrix& temp) const
{
    /* From size of matrices */
    if(rows != temp.rows || columns != temp.columns)
        return false;
    /* From data of matrices */
    for(unsigned int i = 0; i < rows; ++i)
        for(unsigned int j = 0; j < columns; ++j)
            if(data[i][j] != temp.data[i][j])
                return false;

    return true;
}
/**
 * @brief Matrix::operator != overloading the not equality operator between two matrices.
 * @param m
 * @return
 */
bool Matrix::operator!=(const Matrix& temp) const
{
    /* From size of matrices */
    if(rows != temp.rows || columns != temp.columns)
        return true;
    /* From data of matrices */
    for(unsigned int i = 0; i < rows; ++i)
        for(unsigned int j = 0; j < columns; ++j)
            if(data[i][j] != twmp.data[i][j])
                return true;
    return false;
}
/**
 * @brief operator << redefining the output operator for an array.
 * @param os
 * @param temp
 * @return
 */
std::ostream& operator <<(std::ostream& os, const Matrix& temp)
{
    os << std::setprecision(2) << std::fixed;
    for(unsigned int i = 0; i < temp.getRows(); ++i){
        for(unsigned int j = 0; j < temp.getColumns(); ++j)
            os << std::setw(8) << temp.getValue(i, j) << ' ';
        os << std::endl;
    }
    return os;
}

