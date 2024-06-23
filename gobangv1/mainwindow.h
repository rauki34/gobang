#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMediaPlayer>
//#include <QMediaPlaylist>
#include <QIcon>


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


    void on_pvp_clicked();

    void on_pvc_clicked();

    void on_quit_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
};
#endif // MAINWINDOW_H
