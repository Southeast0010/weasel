#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include "myplayer.h"
#include "settingdialog.h"

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
    myPlayer::getInstance()->play(ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->text());
}

void MainWindow::on_pauseButton_clicked()
{
    myPlayer::getInstance()->pause();
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



void MainWindow::on_settingsBotton_clicked()
{
    SettingDialog settings;
    settings.exec();
}
