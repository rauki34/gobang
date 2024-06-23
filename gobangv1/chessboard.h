#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include "chess.h"
#include <QPainter>
#include <QEvent>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QString>


namespace Ui {
class chessboard;
}

#define CHESS_ROWS		15
#define CHESS_COLUMNS	15
#define RECT_WIDTH		50
#define RECT_HEIGHT		50


class chessboard : public QWidget
{
    Q_OBJECT

public:
    explicit chessboard(QWidget *parent = nullptr);
    ~chessboard();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);


private:
    void DrawChessboard();
    void Drawchesses();
    void check(QString str);
    void DrawchessWithMouse();
    void returnmenu();
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);

    //统计某个方向(共8个方向)上的相连个数，用QPoint表示统计方向，如(1,1)表示右下方,（-1,0）表示向左
    int CountNearItem(chess Chess,QPoint ptDirection);

private:
    Ui::chessboard *ui;

    QVector<chess> mchess;
    bool mIsBlackTurn;//黑棋下

    QMediaPlayer *player;
};

#endif // CHESSBOARD_H
