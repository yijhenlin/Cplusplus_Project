#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //初始化
    ui->setupUi(this);
    resize(700,900);
    setStyleSheet("background-color: rgb(105,140,145)");
    srand(time(NULL));
    ui->bomb_1->setPixmap(QPixmap("../Project3/picture/bomb_b.png"));
    ui->bomb_2->setPixmap(QPixmap("../Project3/picture/bomb_b.png"));
    ui->bomb_3->setPixmap(QPixmap("../Project3/picture/bomb_b.png"));
    ui->bomb_1->setVisible(false);
    ui->bomb_2->setVisible(false);
    ui->bomb_3->setVisible(false);
    //背景
    scene = new QGraphicsScene;
    scene->addPixmap(QPixmap("../Project3/picture/background.png"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(506,734);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);

    //敵人
    Enemy *e = new Enemy;
    enemy = &(*e);
    scene->addItem(enemy);
    connect(enemy, SIGNAL(hit_player()), this, SLOT(player_HP()));
    connect(this, SIGNAL(win()), enemy, SLOT(win()));
    connect(this, SIGNAL(lose()), enemy, SLOT(lose()));
    //玩家
    Player *p = new Player;
    player = &(*p);
    scene->addItem(player);
    connect(player, SIGNAL(hit_enemy()), this, SLOT(enemy_HP()));
    connect(player, SIGNAL(hit_enemy_by_bomb()), this, SLOT(enemy_HP_by_bomb()));
    connect(player, SIGNAL(player_miss()), this, SLOT(miss()));
    connect(this, SIGNAL(win()), player, SLOT(win()));
    connect(this, SIGNAL(lose()), player, SLOT(lose()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    HP_p = 100;
    HP_e = 300;
    score = 0;
    num = 0;
    ui->bomb_1->setVisible(false);
    ui->bomb_2->setVisible(false);
    ui->bomb_3->setVisible(false);
    ui->Player_HP->setGeometry(540,320,100,30);
    ui->score->setText("0");
    ui->Enemy_HP->setGeometry(140,40,300,30);
    player->reset();
    enemy->reset();

}

void MainWindow::show_bomb()
{
    num = player->get_b();
    ui->bomb_1->setVisible(false);
    ui->bomb_2->setVisible(false);
    ui->bomb_3->setVisible(false);
    if(num >= 3)ui->bomb_1->setVisible(true);
    if(num >= 6)ui->bomb_2->setVisible(true);
    if(num >= 9)ui->bomb_3->setVisible(true);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(HP_e <= 0 || HP_p <= 0){
        if(e->key() == Qt::Key_Space)reset();
    }
    else player->move_o(e);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(HP_e <= 0 || HP_p <= 0);
    else player->attack_o(event);
}

void MainWindow::player_HP()
{
    HP_p = HP_p - 10;
    ui->Player_HP->setGeometry(540,320,HP_p,30);
    score = score - 10;
    ui->score->setText(QString::number(score));
    if(HP_p <= 0)lose();
}

void MainWindow::enemy_HP()
{
    show_bomb();
    HP_e = HP_e - 20;
    score += player->get_c()*20;
    ui->Enemy_HP->setGeometry(140,40,HP_e,30);
    ui->score->setText(QString::number(score));
    if(HP_e <= 0)win();
}

void MainWindow::enemy_HP_by_bomb()
{
    show_bomb();
    HP_e = HP_e - 50;
    score += player->get_c()*20 + 100;
    ui->Enemy_HP->setGeometry(140,40,HP_e,30);
    ui->score->setText(QString::number(score));
    if(HP_e <= 0)win();
}

void MainWindow::miss()
{
    show_bomb();
}
