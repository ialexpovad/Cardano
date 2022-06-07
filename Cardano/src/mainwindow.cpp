
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


void MainWindow::on_pbtnNxM_clicked()
{
    QMessageBox* dimensionsWindow = new QMessageBox;
    QGridLayout* dimensionsLayout = new QGridLayout;
    dimensionsWindow->setWindowTitle("Size NxM");

    QLineEdit* rowsEdit = new QLineEdit(dimensionsWindow);
    rowsEdit->setFixedSize(40, 20);
    rowsEdit->setAlignment(Qt::AlignRight);
    rowsEdit->setInputMask("D0");
    dimensionsLayout->addWidget(new QLabel("Rows:", dimensionsWindow), 1, 1, 1, 1);
    dimensionsLayout->addWidget(rowsEdit, 3, 1, 1, 1);

    connect(rowsEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setRows(const QString&)));
    connect(rowsEdit, SIGNAL(returnPressed()), dimensionsWindow, SLOT(close()));
    connect(rowsEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QLineEdit* columnsEdit = new QLineEdit(dimensionsWindow);
    columnsEdit->setFixedSize(40, 20);
    columnsEdit->setAlignment(Qt::AlignRight);
    columnsEdit->setInputMask("D0");
    dimensionsLayout->addWidget(new QLabel("Columns:", dimensionsWindow), 1, 3, 1, 1);
    dimensionsLayout->addWidget(columnsEdit, 3, 3, 1, 1);

    connect(columnsEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setColumns(const QString&)));
    connect(columnsEdit, SIGNAL(returnPressed()), dimensionsWindow, SLOT(close()));
    connect(columnsEdit, SIGNAL(returnPressed()), this, SLOT(insertValues()));

    QPushButton* next = new QPushButton("Next", dimensionsWindow);
    dimensionsLayout->addWidget(next, 5, 2, 1, 1);

    connect(next, SIGNAL(clicked()), dimensionsWindow, SLOT(close()));
    connect(next, SIGNAL(clicked()), this, SLOT(insertValues()));

    delete dimensionsWindow->layout();

    dimensionsWindow->setLayout(dimensionsLayout);
    dimensionsWindow->show();

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
