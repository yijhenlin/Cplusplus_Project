#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

void MainWindow::setElement(int r, int c, QString v)
{
    ui->Sudoku->item(r,c)->setText(v);
    ui->Sudoku->item(r,c)->setFlags(Qt::ItemIsEditable);
    ui->Sudoku->item(r,c)->setTextColor(QColor(0,0,0));
    ui->Sudoku->item(r,c)->setBackgroundColor(QColor(172,172,172));
}

void MainWindow::Reset()
{
    ui->Sudoku->clear();
    ui->Pass->setHidden(true);
    ui->Sudoku->setEnabled(true);
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9;++j){
            ui->Sudoku->setItem(i,j,new QTableWidgetItem(""));
            ui->Sudoku->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void MainWindow::setRandom()
{
    Reset();
    srand(time(NULL));
    int r = (rand()%6)+1;
    switch (r){
        case 1:
        setElement(0,0,QString::number(1));
        setElement(1,1,QString::number(5));
        setElement(2,2,QString::number(8));
        setElement(3,3,QString::number(2));
        setElement(4,4,QString::number(9));
        setElement(5,5,QString::number(8));
        setElement(6,6,QString::number(6));
        setElement(7,7,QString::number(4));
        setElement(8,8,QString::number(5));
        setElement(0,4,QString::number(4));
        setElement(0,8,QString::number(7));
        setElement(1,5,QString::number(2));
        setElement(1,7,QString::number(9));
        setElement(2,6,QString::number(4));
        setElement(3,1,QString::number(7));
        setElement(3,8,QString::number(8));
        setElement(4,2,QString::number(6));
        setElement(4,6,QString::number(1));
        setElement(5,0,QString::number(3));
        setElement(5,7,QString::number(5));
        setElement(6,2,QString::number(1));
        setElement(7,1,QString::number(2));
        setElement(7,3,QString::number(8));
        setElement(8,0,QString::number(6));
        setElement(8,4,QString::number(3));
        break;
        case 2:
        setElement(0,1,QString::number(3));
        setElement(0,2,QString::number(4));
        setElement(0,4,QString::number(5));
        setElement(0,5,QString::number(6));
        setElement(0,7,QString::number(9));
        setElement(0,8,QString::number(8));
        setElement(2,0,QString::number(8));
        setElement(2,1,QString::number(1));
        setElement(2,3,QString::number(3));
        setElement(2,4,QString::number(7));
        setElement(2,6,QString::number(6));
        setElement(2,7,QString::number(2));
        setElement(3,1,QString::number(2));
        setElement(3,2,QString::number(3));
        setElement(3,4,QString::number(6));
        setElement(3,5,QString::number(5));
        setElement(3,7,QString::number(7));
        setElement(3,8,QString::number(9));
        setElement(5,0,QString::number(7));
        setElement(5,1,QString::number(9));
        setElement(5,3,QString::number(2));
        setElement(5,4,QString::number(3));
        setElement(5,6,QString::number(4));
        setElement(5,7,QString::number(5));
        setElement(6,1,QString::number(4));
        setElement(6,2,QString::number(1));
        setElement(6,4,QString::number(9));
        setElement(6,5,QString::number(8));
        setElement(6,7,QString::number(6));
        setElement(6,8,QString::number(2));
        setElement(8,0,QString::number(9));
        setElement(8,1,QString::number(7));
        setElement(8,3,QString::number(6));
        setElement(8,4,QString::number(4));
        setElement(8,6,QString::number(3));
        setElement(8,7,QString::number(8));
        break;
        case 3:
        setElement(0,1,QString::number(3));
        setElement(0,2,QString::number(4));
        setElement(0,4,QString::number(7));
        setElement(0,5,QString::number(8));
        setElement(0,7,QString::number(2));
        setElement(0,8,QString::number(9));
        setElement(2,0,QString::number(8));
        setElement(2,1,QString::number(7));
        setElement(2,3,QString::number(5));
        setElement(2,4,QString::number(2));
        setElement(2,6,QString::number(3));
        setElement(2,7,QString::number(1));
        setElement(3,1,QString::number(1));
        setElement(3,2,QString::number(2));
        setElement(3,4,QString::number(5));
        setElement(3,5,QString::number(6));
        setElement(3,7,QString::number(9));
        setElement(3,8,QString::number(8));
        setElement(5,0,QString::number(6));
        setElement(5,1,QString::number(9));
        setElement(5,3,QString::number(3));
        setElement(5,4,QString::number(8));
        setElement(5,6,QString::number(2));
        setElement(5,7,QString::number(5));
        setElement(6,1,QString::number(4));
        setElement(6,2,QString::number(1));
        setElement(6,4,QString::number(6));
        setElement(6,5,QString::number(2));
        setElement(6,7,QString::number(8));
        setElement(6,8,QString::number(3));
        setElement(8,0,QString::number(7));
        setElement(8,1,QString::number(2));
        setElement(8,3,QString::number(9));
        setElement(8,4,QString::number(4));
        setElement(8,6,QString::number(1));
        setElement(8,7,QString::number(6));
        break;
        case 4:
        setElement(0,1,QString::number(4));
        setElement(0,2,QString::number(8));
        setElement(0,3,QString::number(5));
        setElement(0,5,QString::number(2));
        setElement(0,8,QString::number(1));
        setElement(1,2,QString::number(5));
        setElement(1,4,QString::number(1));
        setElement(2,1,QString::number(2));
        setElement(2,2,QString::number(1));
        setElement(2,3,QString::number(6));
        setElement(2,5,QString::number(4));
        setElement(2,7,QString::number(9));
        setElement(2,8,QString::number(5));
        setElement(3,0,QString::number(5));
        setElement(3,1,QString::number(3));
        setElement(3,2,QString::number(9));
        setElement(3,6,QString::number(1));
        setElement(3,7,QString::number(4));
        setElement(3,8,QString::number(7));
        setElement(4,0,QString::number(8));
        setElement(4,3,QString::number(7));
        setElement(4,4,QString::number(4));
        setElement(4,5,QString::number(1));
        setElement(4,8,QString::number(9));
        setElement(5,0,QString::number(4));
        setElement(5,1,QString::number(1));
        setElement(5,2,QString::number(7));
        setElement(5,6,QString::number(6));
        setElement(5,7,QString::number(8));
        setElement(5,8,QString::number(2));
        setElement(6,0,QString::number(1));
        setElement(6,1,QString::number(8));
        setElement(6,3,QString::number(4));
        setElement(6,5,QString::number(9));
        setElement(6,6,QString::number(7));
        setElement(6,7,QString::number(2));
        setElement(7,4,QString::number(6));
        setElement(7,6,QString::number(4));
        setElement(8,0,QString::number(7));
        setElement(8,3,QString::number(2));
        setElement(8,5,QString::number(3));
        setElement(8,6,QString::number(9));
        setElement(8,7,QString::number(1));
        break;
        case 5:
        setElement(0,0,QString::number(6));
        setElement(0,2,QString::number(8));
        setElement(0,5,QString::number(3));
        setElement(0,6,QString::number(7));
        setElement(0,7,QString::number(2));
        setElement(0,8,QString::number(1));
        setElement(1,1,QString::number(5));
        setElement(1,2,QString::number(9));
        setElement(1,4,QString::number(1));
        setElement(1,6,QString::number(6));
        setElement(1,7,QString::number(4));
        setElement(2,2,QString::number(7));
        setElement(2,3,QString::number(4));
        setElement(2,5,QString::number(6));
        setElement(2,6,QString::number(5));
        setElement(3,1,QString::number(9));
        setElement(3,3,QString::number(7));
        setElement(3,4,QString::number(3));
        setElement(3,5,QString::number(5));
        setElement(4,1,QString::number(6));
        setElement(4,2,QString::number(3));
        setElement(4,4,QString::number(2));
        setElement(4,6,QString::number(9));
        setElement(4,7,QString::number(7));
        setElement(5,3,QString::number(6));
        setElement(5,4,QString::number(9));
        setElement(5,5,QString::number(4));
        setElement(5,7,QString::number(1));
        setElement(6,2,QString::number(5));
        setElement(6,3,QString::number(1));
        setElement(6,5,QString::number(2));
        setElement(6,6,QString::number(4));
        setElement(7,1,QString::number(2));
        setElement(7,2,QString::number(4));
        setElement(7,4,QString::number(7));
        setElement(7,6,QString::number(3));
        setElement(7,7,QString::number(9));
        setElement(8,0,QString::number(7));
        setElement(8,1,QString::number(8));
        setElement(8,2,QString::number(6));
        setElement(8,3,QString::number(3));
        setElement(8,6,QString::number(1));
        setElement(8,8,QString::number(2));
        break;
        case 6:
        setElement(0,1,QString::number(6));
        setElement(0,2,QString::number(3));
        setElement(0,3,QString::number(2));
        setElement(0,5,QString::number(8));
        setElement(0,6,QString::number(9));
        setElement(0,8,QString::number(5));
        setElement(1,2,QString::number(2));
        setElement(1,4,QString::number(5));
        setElement(1,6,QString::number(8));
        setElement(1,8,QString::number(6));
        setElement(2,3,QString::number(1));
        setElement(2,5,QString::number(6));
        setElement(2,7,QString::number(4));
        setElement(2,8,QString::number(2));
        setElement(3,0,QString::number(2));
        setElement(3,2,QString::number(4));
        setElement(3,6,QString::number(5));
        setElement(3,7,QString::number(6));
        setElement(3,8,QString::number(7));
        setElement(4,0,QString::number(3));
        setElement(4,3,QString::number(7));
        setElement(4,4,QString::number(6));
        setElement(4,5,QString::number(5));
        setElement(4,8,QString::number(4));
        setElement(5,0,QString::number(6));
        setElement(5,1,QString::number(5));
        setElement(5,2,QString::number(7));
        setElement(5,6,QString::number(1));
        setElement(5,8,QString::number(8));
        setElement(6,0,QString::number(5));
        setElement(6,1,QString::number(3));
        setElement(6,3,QString::number(6));
        setElement(6,5,QString::number(4));
        setElement(7,0,QString::number(8));
        setElement(7,2,QString::number(9));
        setElement(7,4,QString::number(1));
        setElement(7,6,QString::number(6));
        setElement(8,0,QString::number(7));
        setElement(8,2,QString::number(6));
        setElement(8,3,QString::number(8));
        setElement(8,5,QString::number(9));
        setElement(8,6,QString::number(4));
        setElement(8,7,QString::number(5));
        break;

    }

}

void MainWindow::setCustom()
{
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9;++j){
            if(ui->Sudoku->item(i,j)->text() > 0){
                if(ui->Sudoku->item(i,j)->textColor() == QColor(255,0,0))Reset();
                else setElement(i,j,ui->Sudoku->item(i,j)->text());
            }
        }
    }
}

bool MainWindow::Check(int &r, int &c)
{
    for(r = 0;r < 9;++r){
        for(c = 0;c < 9;++c){
            if(ui->Sudoku->item(r,c)->text() == "" || ui->Sudoku->item(r,c)->textColor() == QColor(255,0,0))
                return false;
        }
    }
    return true;
}

bool MainWindow::Issafe(QTableWidgetItem *item, QString value)
{
    if(value == "")value = item->text();
    for(int i = 0;i < 9;++i){
            if(value == ui->Sudoku->item(i,item->column())->text() && i != item->row()){
            return false;
            }
            if(value == ui->Sudoku->item(item->row(),i)->text() && i != item->column()){
            return false;
            }
        }
    int r = item->row()-item->row()%3;
    int c = item->column()-item->column()%3;
    for(int i = r;i < r+3;++i){
            for(int j = c;j < c+3;++j){
                    if(value == ui->Sudoku->item(i,j)->text() && i != item->row() && j != item->column()){
                    return false;
                    }
                }
        }
    return true;
}

bool MainWindow::Solvable()
{
    int r = 0, c = 0;
    if(Check(r, c) == true){
        return true;
    }
    for(int i = 1;i <= 9;++i){
        if(Issafe(ui->Sudoku->item(r,c), QString::number(i)) == true){
            ui->Sudoku->item(r,c)->setText(QString::number(i));
            if(Solvable() == true){
                return true;
            }
            ui->Sudoku->item(r,c)->setText("");
        }
    }
    return false;
}

void MainWindow::Solve()
{
    if(Solvable() == true){
        ui->Pass->setHidden(true);
    }
    else{
        ui->Pass->setText("unsolvable");
        ui->Pass->setFont(QFont("unsolvable",18,QFont::Bold,Qt::AlignCenter));
        ui->Pass->setHidden(false);
    }
}


void MainWindow::Add()
{
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9;++j){
            if(ui->Sudoku->item(i,j)->text() > 0){
                int x = ui->Sudoku->item(i,j)->text().toInt();
                if(x == 9)ui->Sudoku->item(i,j)->setText("1");
                else
                ui->Sudoku->item(i,j)->setText(QString::number(x+1));
            }
        }
    }
}


void MainWindow::Down()
{

    int x[9][9];
    int zero[9][9] = {0};
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9;++j){
            x[i][j] = ui->Sudoku->item(i,j)->text().toInt();
        }
    }
    for(int j = 0;j < 9;++j){
        for(int i = 0;i < 9;++i){
            if(x[i][j] == 0)zero[i][j] = 1;
        }
    }
    Reset();
    for(int i = 0;i < 9;++i){
        for(int j = 8;j >= 0;--j){
            if(zero[j][i] == 0){    //has number
                for(int k = 8;k >= 0;--k){
                    if(zero[k][i] == 1){ //find empty
                        if(k <= j){
                            ui->Sudoku->item(j,i)->setText(QString::number(x[j][i]));
                            break;
                        }
                        else{
                            ui->Sudoku->item(k,i)->setText(QString::number(x[j][i]));
                            x[k][i] = x[j][i];
                            x[j][i] = 0;
                            zero[j][i] = 1;
                            zero[k][i] = 0;
                            break;
                        }
                    }
                    else if(k == 0 && zero[k][i] == 0){
                        ui->Sudoku->item(j,i)->setText(QString::number(x[j][i]));
                        ui->Pass->setHidden(true);
                    }
                }
            }
        }
    }
}
