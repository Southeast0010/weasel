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
    player->setMedia(QUrl::fromLocalFile(ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->text()));
    player->setVolume(50);
    player->play();
}

void MainWindow::on_browseBotton_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setViewMode(QFileDialog::Detail);
    int res = dialog.exec();
    QDir directory;

    if (res) {
        directory = dialog.selectedFiles()[0];
        QStringList filesList = directory.entryList(QDir::Files);
        QString fileName;
        int i = 1;
        foreach(fileName, filesList) {
            qDebug() << "FileName " << fileName;
            ui->tableWidget->setRowCount(i);
            ui->tableWidget->setItem(i-1, 0, new QTableWidgetItem(fileName));
            ui->tableWidget->setItem(i-1, 3, new QTableWidgetItem(directory.filePath(fileName)));
            i++;
        }
    }
}
