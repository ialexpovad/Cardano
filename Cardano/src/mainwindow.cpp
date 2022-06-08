
/*****************************************************************************
 * mainwindow.cpp
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
#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle(VER_ORIGINALFILENAME_STR);
    setWindowIcon(QIcon (":/img/logo/m_logo.png"));
    setFixedSize(700, 200);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pbtnNxM_clicked this SLOT from push-button sets the
 * size of the Matrix [NxM] (rectangle) in the pop-up window
 */
void MainWindow::on_pbtnNxM_clicked()
{
    QMessageBox* w = new QMessageBox;
    QGridLayout* _dimLayout = new QGridLayout;
    w->setWindowTitle("Set rect matrix");

    QLineEdit* _rowEdit = new QLineEdit(w);
    _rowEdit->setFixedSize(50, 20);
    _rowEdit->setAlignment(Qt::AlignCenter);
    _rowEdit->setInputMask("D0");
    _dimLayout->addWidget(new QLabel("Rows:", w), 0, 0, 1, 1);
    _dimLayout->addWidget(_rowEdit, 0, 1, 1, 1);

    connect(_rowEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setRows(const QString&)));
    connect(_rowEdit, SIGNAL(returnPressed()), w, SLOT(close()));
    connect(_rowEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QLineEdit* _colEdit = new QLineEdit(w);
    _colEdit->setFixedSize(50, 20);
    _colEdit->setAlignment(Qt::AlignCenter);
    _colEdit->setInputMask("D0");
    _dimLayout->addWidget(new QLabel("Columns:", w), 1, 0, 1, 1);
    _dimLayout->addWidget(_colEdit, 1, 1, 1, 1);

    connect(_colEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setColumns(const QString&)));
    connect(_colEdit, SIGNAL(returnPressed()), w, SLOT(close()));
    connect(_colEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QPushButton* next = new QPushButton("Next", w);
    _dimLayout->addWidget(next, 2, 0, 1, 1);

    connect(next, SIGNAL(clicked()), w, SLOT(close()));
    connect(next, SIGNAL(clicked()), this, SLOT(insertValues()));

    delete w->layout();

    w->setLayout(_dimLayout);
    w->show();

}

/**
 * @brief MainWindow::on_pbtnNxN_clicked  this SLOT from push-button sets the
 * size of the Matrix (square) in the pop-up window
 */
void MainWindow::on_pbtnNxN_clicked()
{
    QMessageBox* w = new QMessageBox;
    QGridLayout* _dimLayout = new QGridLayout;
    w->setWindowTitle("Set square matrix");

    QLineEdit* _dimEdit = new QLineEdit(w);
    _dimEdit->setFixedSize(80, 20);
    _dimEdit->setAlignment(Qt::AlignCenter);
    _dimLayout->addWidget(new QLabel("Rows = Columns:", w), 0, 1, 1, 1);
    _dimLayout->addWidget(_dimEdit, 0, 2, 1, 1);
    _dimLayout->setColumnMinimumWidth(1, 20);
    _dimLayout->setColumnMinimumWidth(3, 20);

    connect(_dimEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setRows(const QString&)));
    connect(_dimEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setColumns(const QString&)));
    connect(_dimEdit, SIGNAL(returnPressed()), w, SLOT(close()));
    connect(_dimEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QPushButton* next = new QPushButton("Next", w);
    _dimLayout->addWidget(next, 1, 2, 1, 1);

    connect(next, SIGNAL(clicked()), w, SLOT(close()));
    connect(next, SIGNAL(clicked()), this, SLOT(insertValues()));

    delete w->layout();
    w->setLayout(_dimLayout);
    w->show();
}

/**
 * @brief MainWindow::on_pBtnNx1_clicked this SLOT from push-button sets the
 * size of the matrix (vector N x 1 - column) in the pop-up window.
 */
void MainWindow::on_pBtnNx1_clicked()
{
    QMessageBox* w = new QMessageBox;
    QGridLayout* _dimLayout = new QGridLayout;
    w->setWindowTitle("Column vector");
    /// sets number columns of vector
    column_num = 1;

    QLineEdit* _dimEdit = new QLineEdit(w);
    _dimEdit->setFixedSize(80, 20);
    _dimEdit->setAlignment(Qt::AlignCenter);
    _dimLayout->addWidget(new QLabel("Rows:", w), 0, 1, 1, 1);
    _dimLayout->addWidget(_dimEdit, 0, 2, 1, 1);
    _dimLayout->setColumnMinimumWidth(1, 20);
    _dimLayout->setColumnMinimumWidth(3, 20);
    connect(_dimEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setRows(const QString&)));
    connect(_dimEdit, SIGNAL(returnPressed()), w, SLOT(close()));
    connect(_dimEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QPushButton* next = new QPushButton("Next", w);
    _dimLayout->addWidget(next, 1, 2, 1, 1);

    connect(next, SIGNAL(clicked()), w, SLOT(close()));
    connect(next, SIGNAL(clicked()), this, SLOT(insertValues()));

    delete w->layout();
    w->setLayout(_dimLayout);
    w->show();

}

/**
 * @brief MainWindow::on_pBtn1xN_clicked this SLOT from push-button sets the
 * size of the matrix (vector 1 x N - row) in the pop-up window.
 */
void MainWindow::on_pBtn1xN_clicked()
{
    QMessageBox* w = new QMessageBox;
    QGridLayout* _dimLayout = new QGridLayout;
    w->setWindowTitle("Row vector");
    /// sets number rows of vector
    row_num = 1;

    QLineEdit* _dimEdit = new QLineEdit(w);
    _dimEdit->setFixedSize(80, 20);
    _dimEdit->setAlignment(Qt::AlignCenter);
    _dimLayout->addWidget(new QLabel("Columns:", w), 0, 1, 1, 1);
    _dimLayout->addWidget(_dimEdit, 0, 2, 1, 1);
    connect(_dimEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setColumns(const QString&)));
    connect(_dimEdit, SIGNAL(returnPressed()), w, SLOT(close()));
    connect(_dimEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QPushButton* next = new QPushButton("Next", w);
    _dimLayout->addWidget(next, 1, 2, 1, 1);
    connect(next, SIGNAL(clicked()), w, SLOT(close()));
    connect(next, SIGNAL(clicked()), this, SLOT(insertValues()));

    _dimLayout->setColumnMinimumWidth(1, 20);
    _dimLayout->setColumnMinimumWidth(3, 20);

    delete w->layout();
    w->setLayout(_dimLayout);
    w->show();

}



/**
 * @brief MainWindow::setRows slot, in which setting value rows matrix
 * @param value int 1..n
 */
void MainWindow::setRows(const QString &value)
{

}

/**
 * @brief MainWindow::setColumns slot, in which setting value columns matrix
 * @param value int 1..n
 */
void MainWindow::setColumns(const QString &value)
{

}

void MainWindow::insertValues()
{

}

void MainWindow::on_pBtnEqual_clicked()
{

}



