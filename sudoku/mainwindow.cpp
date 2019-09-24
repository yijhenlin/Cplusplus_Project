#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9;++j){
            ui->Sudoku->setItem(i,j,new QTableWidgetItem(""));
            ui->Sudoku->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
     }
    ui->Pass->setFont(QFont("PASS",32,QFont::Bold,Qt::AlignCenter));
    ui->Pass->setHidden(true);
    ui->Add->setHidden(true);
    ui->Down->setHidden(true);
    connect(ui->Random, SIGNAL(clicked(bool)), this, SLOT(setRandom()));
    connect(ui->Custom, SIGNAL(clicked(bool)), this, SLOT(setCustom()));
    connect(ui->Reset, SIGNAL(clicked(bool)), this, SLOT(Reset()));
    connect(ui->Solve, SIGNAL(clicked(bool)), this, SLOT(Solve()));
    connect(ui->Down, SIGNAL(clicked(bool)), this, SLOT(Down()));
    connect(ui->Add, SIGNAL(clicked(bool)), this, SLOT(Add()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Sudoku_itemChanged(QTableWidgetItem *item)
{
    if(item != NULL && item->text() != ""){
        if(item->text().toInt() > 9 || item->text().toInt() < 1)item->setText("");
        /*qDebug()<<tr("current row：%1，column：%2，text：%3")
                  .arg(item->row())
                  .arg(item->column())
                  .arg(item->text());*/
        int r = 0, c = 0;
        if(MainWindow::Issafe(item, "") == false)item->setTextColor(QColor(255,0,0));
        else item->setTextColor(QColor(0,0,0));
        if(MainWindow::Check(r,c) == true){
            ui->Pass->setText("PASS");
            ui->Pass->setHidden(false);
            //ui->Sudoku->setEnabled(false);
        }
    }
}
