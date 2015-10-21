#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playBotton_clicked()
{
    QMediaPlayer* player;
    player = new QMediaPlayer;
    // ...
    player->setMedia(QUrl::fromLocalFile("A:/Music/01 Nightwish - The Poet And The Pendulum.flac"));
    player->setVolume(50);
    player->play();
}

void MainWindow::on_browseBotton_clicked()
{
    QFileDialog *dialog = new QFileDialog;
    dialog->setFileMode(QFileDialog::Directory);
    dialog->setOption(QFileDialog::ShowDirsOnly);
    dialog->exec();
}
