#include "chess.h"

chess::chess(void) : mPt(QPoint(0, 0)), mBlack(false) {}

    // 带参数的构造函数
chess::chess(QPoint pt, bool bBlack) : mPt(pt), mBlack(bBlack) {}

    // 析构函数
chess::~chess(void) {}

