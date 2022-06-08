
/*****************************************************************************
 * mainwindow.h
 *
 * Created: 07.06.2022 2022 by Alex Povod
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <include/version.h>
#include <include/exception.h>
#include <include/abortwindow.h>
//#include <include/matrix.h>
#include <include/squarematrix.h>

#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbtnNxM_clicked();

    /// set rows and columns
    void setRows(const QString& value);
    void setColumns(const QString& value);
    void insertValues();

    /** Set for group dim matrix (vector) */
    void on_pBtnEqual_clicked();
    void on_pbtnNxN_clicked();
    void on_pBtn1xN_clicked();
    void on_pBtnNx1_clicked();

    /** Unary opearator */
    void on_unary_clicked();

    /** Display result in plainEdit */
    void result();

private:
    Ui::MainWindow *ui;
    AbortWindow *m_abort;

    unsigned int row_num, column_num;
    bool expectOperand;
    void Abort(const exception& error);

    Matrix* operand;
    Matrix* matrixSum;
    Matrix* matrixFactor;



    double scalarOperand;



};

#endif // MAINWINDOW_H
