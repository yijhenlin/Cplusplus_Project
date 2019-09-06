#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableWidgetItem>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setElement(int row, int column, QString value);
    bool Check(int &row, int &column);
    bool Issafe(QTableWidgetItem *item, QString value);
    bool Solvable();
private slots:
    void setRandom();

    void setCustom();

    void Reset();

    void on_Sudoku_itemChanged(QTableWidgetItem *item);

    void Solve();

    void Add();

    void Down();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
