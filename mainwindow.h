#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playBotton_clicked();

    void on_browseBotton_clicked();

    void on_pauseButton_clicked();

    void on_settingsBotton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
