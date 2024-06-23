#ifndef CHESS_H
#define CHESS_H

#pragma once
#include <QPoint>

class chess
{
public:
    chess(void);
    chess(QPoint pt,bool bBlack);
    ~chess(void);

    //重载"=="操作符，判等需要颜色和位置都相同
    bool operator==(const chess &t1)const
    {
        return ((mPt == t1.mPt) && (mBlack == t1.mBlack));
    }

    QPoint mPt;
    bool mBlack;
private:


};


#endif // CHESS_H
