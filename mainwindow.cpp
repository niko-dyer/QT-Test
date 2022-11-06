#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(this,
                &MainWindow::setColor,
                ui->pixelEditor,
                &Canvas::setCurrentColor);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_redButton_clicked() {
    ui->redButton->setStyleSheet("border: 5px solid black; background-color: red;");
    ui->blueButton->setStyleSheet("background-color: blue;");
    ui->greenButton->setStyleSheet("background-color: green;");
    emit setColor(Qt::red);
}


void MainWindow::on_greenButton_clicked() {
    ui->greenButton->setStyleSheet("border: 5px solid black; background-color: green;");
    ui->redButton->setStyleSheet("background-color: red;");
    ui->blueButton->setStyleSheet("background-color: blue;");
    emit setColor(Qt::green);
}


void MainWindow::on_blueButton_clicked() {
    ui->blueButton->setStyleSheet("border: 5px solid black; background-color: blue;");
    ui->redButton->setStyleSheet("background-color: red;");
    ui->greenButton->setStyleSheet("background-color: green;");
    emit setColor(Qt::blue);
}

