
/*****************************************************************************
 * r_vector.h
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
#ifndef R_VECTOR_H
#define R_VECTOR_H

#include "vector.h"

class r_vector : public Vector
{
public:
    r_vector(unsigned int columns);

    void setValue(unsigned int column, double value);
    r_vector* triangularize() const;
    Vector* transpose() const;
    double euclideanNorm() const;

    unsigned int getRows() const;
    double getValue(unsigned int j) const;

};

#endif // R_VECTOR_H
