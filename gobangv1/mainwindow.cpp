#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessboard.h"
#include "aiboard.h"
#include "aichess.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    //this->setWindowIcon(QIcon(":/image/icon.ico"));
    resize(1280,720);
    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);     // 设置无边框
    player->setMedia(QUrl("qrc:/sound/If I Can Stop One Heart From Breaking.mp3"));
    player->setVolume(80);
    player->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}


//双人对战
void MainWindow::on_pvp_clicked()
{
    //QMessageBox::information(this, "双人对战", "开发中暂不支持，敬请期待！");
    this->close();
    chessboard *w = new chessboard();
    w->show();
    player->stop();
    //this->close();
}

//人机对战
void MainWindow::on_pvc_clicked()
{
    aichess *w = new aichess();
    w->show();
    player->stop();
    this->close();
}

//退出游戏
void MainWindow::on_quit_clicked()
{
    //QMessageBox::information(this,"退出游戏","再见!");
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("退出");
    msgBox.setText("是否退出游戏？");
    //自定义确认和取消button
    QPushButton *confirmButton = msgBox.addButton("确认", QMessageBox::AcceptRole);
    QPushButton *cancelButton = msgBox.addButton("取消", QMessageBox::RejectRole);
    int ret=msgBox.exec(); // 显示对话框并等待用户响应
    if (ret == QMessageBox::AcceptRole) {
        this->close();
    }
}

/*void MainWindow::PlayBackgroundMusic()
{
    QMediaPlayer *player = new QMediaPlayer(this);
    //player->setMedia(QUrl::fromLocalFile("C:\\Users\\rauki\\Desktop\\gobang\\build-gobangv1-Desktop_Qt_5_15_2_MinGW_32_bit-Debug\\If I Can Stop One Heart From Breaking.mp3"));
    player->setMedia(QUrl("qrc:/sound/If I Can Stop One Heart From Breaking.mp3"));
    player->setVolume(80);
    player->play();
}
*/
