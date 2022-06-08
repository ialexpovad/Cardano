
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


