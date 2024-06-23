#ifndef AIBOARD_H
#define AIBOARD_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <QPaintEvent>
#include <QResizeEvent>
#include <cmath>


#define DEFAULT_CHESS_BOARD_COLOR QColor(247, 230, 182, 255)
#define DEFAULT_CHESS_LINE_COLOR QColor(182, 162, 119, 255)
#define DEFAULT_PIECE_A_COLOR QColor(0, 0, 0, 255)
#define DEFAULT_PIECE_B_COLOR QColor(255, 255, 255, 255)


enum PieceMode {
    None, Black, White
};

namespace Ui {
class aiboard;
}

class aiboard : public QWidget
{
    Q_OBJECT

public:
    explicit aiboard(QWidget *parent = nullptr);
     ~aiboard();
    int cellSize = 80;
    int cellNum = 14;
    int startX = 50;
    int startY = 50;
    int pieceR = 35;
    int lianzhuNum = 5;

    QColor chessBoardColor = DEFAULT_CHESS_BOARD_COLOR;
    QColor chessLineColor = DEFAULT_CHESS_LINE_COLOR;
    QColor pieceAColor = DEFAULT_PIECE_A_COLOR;
    QColor pieceBColor = DEFAULT_PIECE_B_COLOR;

    void loadChessMap(int order, QVector<QVector<int>> chessOrder);

protected:
    int order;
    QVector<QVector<int>> chessMap;
    QVector<QVector<int>> chessOrder;

    void boardDraw(QPainter& painter);
    void pointDraw(QPainter& painter);
    void pieceDraw(QPainter& painter);
    virtual void paintEvent(QPaintEvent* e);

    void createNewChessBoard();

    void boardCalculation(int maxLen, int minLen, int& maxStart, int& minStart);
    void boardCalculation(int sameLen);
    void boardResize();
    void resizeEvent(QResizeEvent* e);

private:
    Ui::aiboard *ui;
};

#endif // AIBOARD_H
