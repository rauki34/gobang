#include "chessboard.h"
#include "ui_chessboard.h"
#include "chess.h"
#include "mainwindow.h"

chessboard::chessboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessboard)
    ,player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    player->setMedia(QUrl("qrc:/sound/Counter Clockwise Clock.mp3"));
    player->setVolume(80);
    player->play();
    setFixedSize(CHESS_COLUMNS * RECT_WIDTH  ,CHESS_ROWS * RECT_HEIGHT);
    mIsBlackTurn = true;
}

chessboard::~chessboard()
{
    delete ui;
}


void chessboard::paintEvent(QPaintEvent *e)
{
    DrawChessboard();		//画棋盘
    Drawchesses();			//画棋子
    DrawchessWithMouse();	//画鼠标（当前方的棋子形状）

    update();
}


void chessboard::DrawChessboard()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QColor bc(166, 124, 82);
    QBrush bbrush(bc);
    painter.setBrush(bbrush);
    painter.drawRect(13, 13, (CHESS_COLUMNS-0.5)*RECT_WIDTH, (CHESS_ROWS-0.5)*RECT_HEIGHT);
    QColor brownColor(238, 154, 73);
    QBrush brownBrush(brownColor);
    painter.setBrush(brownBrush);
    painter.setPen(QPen(QColor(Qt::black),2));

    for(int i = 0; i<CHESS_COLUMNS-1; i++)
    {
        for (int j = 0; j<CHESS_ROWS-1; j++)
        {
            painter.drawRect( (i+0.5)*RECT_WIDTH,(j+0.5)*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
        }
    }

    // 绘制棋盘的四条边界线
    painter.setPen(QPen(QColor(Qt::black), 4)); // 加粗边界线
    painter.drawLine(13, 13, (CHESS_COLUMNS-0.25) * RECT_WIDTH, 13); // 上边界
    painter.drawLine(13, (CHESS_ROWS-0.25)*RECT_HEIGHT, (CHESS_COLUMNS-0.25)*RECT_WIDTH, (CHESS_ROWS-0.25)*RECT_HEIGHT); // 下边界
    painter.drawLine(13, 13, 13, (CHESS_ROWS-0.25)*RECT_HEIGHT); // 左边界
    painter.drawLine((CHESS_COLUMNS-0.25)*RECT_WIDTH, 13, (CHESS_COLUMNS-0.25)*RECT_WIDTH, (CHESS_ROWS-0.25)*RECT_HEIGHT); // 右边界

    // 绘制五个小黑点("天元"与"星")
    painter.setPen(QPen(QColor(Qt::black),2));
    painter.setBrush(Qt::black);
    int centerX = (CHESS_COLUMNS-1) / 2 * RECT_WIDTH + RECT_WIDTH / 2;
    int centerY = (CHESS_ROWS-1) / 2 * RECT_HEIGHT + RECT_HEIGHT / 2;
    painter.drawEllipse(centerX - RECT_WIDTH/8, centerY - RECT_HEIGHT/8, RECT_WIDTH/4, RECT_HEIGHT/4);
    painter.drawEllipse(centerX+200 - RECT_WIDTH/8, centerY+200 - RECT_HEIGHT/8, RECT_WIDTH/4, RECT_HEIGHT/4);
    painter.drawEllipse(centerX+200 - RECT_WIDTH/8, centerY-200 - RECT_HEIGHT/8, RECT_WIDTH/4, RECT_HEIGHT/4);
    painter.drawEllipse(centerX-200 - RECT_WIDTH/8, centerY-200 - RECT_HEIGHT/8, RECT_WIDTH/4, RECT_HEIGHT/4);
    painter.drawEllipse(centerX-200 - RECT_WIDTH/8, centerY+200 - RECT_HEIGHT/8, RECT_WIDTH/4, RECT_HEIGHT/4);
}

void chessboard::Drawchesses()
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::SolidPattern)));

    for (int i = 0; i<mchess.size(); i++)
    {
        chess Chess = mchess[i];
        if (Chess.mBlack)
        {
            painter.setBrush(Qt::black);
        }
        else
        {
            painter.setBrush(Qt::white);
        }
        DrawChessAtPoint(painter,Chess.mPt);
    }
}

void chessboard::DrawChessAtPoint(QPainter& painter,QPoint& pt)
{
    //painter.drawRect( (pt.x()+0.5)*RECT_WIDTH,(pt.y()+0.5)*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);

    QPoint ptCenter((pt.x()+0.5)*RECT_WIDTH,(pt.y()+0.5)*RECT_HEIGHT);
    painter.drawEllipse(ptCenter,RECT_WIDTH *2 / 5,RECT_HEIGHT *2 / 5);
}

void chessboard::DrawchessWithMouse()
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::SolidPattern)));

    if (mIsBlackTurn)
    {
        painter.setBrush(Qt::black);
    }
    else
    {
        painter.setBrush(Qt::white);
    }
    //QPoint pt;
    //pt.setX( (QCursor::pos().x() ) / RECT_WIDTH);
    //pt.setY( (QCursor::pos().y() ) / RECT_HEIGHT);

    //DrawChessAtPoint(painter,pt);

    painter.drawEllipse(mapFromGlobal(QCursor::pos()),RECT_WIDTH *2 / 5,RECT_HEIGHT *2 / 5);

}

void chessboard::mousePressEvent(QMouseEvent * e)
{
    //求鼠标点击处的棋子点pt
    QPoint pt;
    pt.setX( (e->pos().x() ) / RECT_WIDTH);
    pt.setY( (e->pos().y() ) / RECT_HEIGHT);
    //使棋子落在棋盘上
    if (pt.x() < 0 || pt.x() >= CHESS_ROWS || pt.y() < 0 || pt.y() >= CHESS_COLUMNS) {
        return; // 无效点击，退出函数
    }

    //如果已存在棋子，就什么也不做
    for (int i = 0; i<mchess.size(); i++)
    {
        chess Chess = mchess[i];
        if (Chess.mPt == pt)
        {
            //已有棋子
            return;
        }
    }

    // 如果棋盘已满，则结束游戏
    if (mchess.size() >= (CHESS_ROWS * CHESS_COLUMNS)) {
        QString str = "棋盘已满，平局！";
        check(str);
    }

    //不存在棋子，就下一个
    chess Chess(pt,mIsBlackTurn);
    mchess.append(Chess);

    //统计8个方向是否五子连
    int nLeft =			CountNearItem(Chess,QPoint(-1,0));
    int nLeftUp =		CountNearItem(Chess,QPoint(-1,-1));
    int nUp =			CountNearItem(Chess,QPoint(0,-1));
    int nRightUp =		CountNearItem(Chess,QPoint(1,-1));
    int nRight =		CountNearItem(Chess,QPoint(1,0));
    int nRightDown =	CountNearItem(Chess,QPoint(1,1));
    int nDown =			CountNearItem(Chess,QPoint(0,1));
    int nLeftDown =		CountNearItem(Chess,QPoint(-1,1));
    if ( (nLeft + nRight) >= 4 ||
        (nLeftUp + nRightDown) >= 4 ||
        (nUp + nDown) >= 4 ||
        (nRightUp + nLeftDown) >= 4 )
    {
        QString str = mIsBlackTurn?"黑方获胜！":"白方获胜！";
        //player->stop();
        /*QMessageBox::information(this, "游戏结束",str,QMessageBox::Yes);
        mchess.clear();
        //NewGame();
        return;*/
        check(str);
   }
    //该另一方下棋了
    mIsBlackTurn = !mIsBlackTurn;
}

int chessboard::CountNearItem(chess Chess,QPoint ptDirection)
{
    int nCount = 0;
    Chess.mPt += ptDirection;

    while (mchess.contains(Chess))
    {
        nCount++;
        Chess.mPt += ptDirection;
    }
    return nCount;
}

void chessboard::returnmenu(){
    MainWindow *w = new MainWindow();
    this->close();
    player->stop();
    w->show();
}

void chessboard::check(QString str){
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("游戏结束");
    msgBox.setText(str+"是否新的一局？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes); // 设置默认按钮为“是”
    int ret = msgBox.exec(); // 弹出消息框并等待用户响应

    // 根据用户的选择执行操作
    if (ret == QMessageBox::Yes) {
        // 用户选择了“是”，开始新游戏
        /*mchess.clear();
        return; // 开始新游戏*/
        player->stop();
        chessboard *w =new chessboard();
        w->show();
        this->close();
    } else {
        // 用户选择了“否”，返回主菜单
        returnmenu();
    }
}

