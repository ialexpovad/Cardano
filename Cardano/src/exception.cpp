
/*****************************************************************************
 * exception.cpp
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
#include "include/exception.h"
/**
 * @brief exception::exception constructor, that corresponds to the exception type.
 * @param s
 */
exception::exception(const QString& s) : type(s) { }
/**
 * @brief exception::getStr method for exception, for that the object was created.
 * @return
 */
QString exception::getType() const { return type; }


