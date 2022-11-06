#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_redButton_clicked();
    void on_greenButton_clicked();
    void on_blueButton_clicked();

private:
    Ui::MainWindow *ui;

signals:
    void setColor(QColor);
};
#endif // MAINWINDOW_H
