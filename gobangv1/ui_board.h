/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board
{
public:

    void setupUi(QWidget *board)
    {
        if (board->objectName().isEmpty())
            board->setObjectName(QString::fromUtf8("board"));
        board->resize(607, 550);
        board->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/chessboard.jpg);"));

        retranslateUi(board);

        QMetaObject::connectSlotsByName(board);
    } // setupUi

    void retranslateUi(QWidget *board)
    {
        board->setWindowTitle(QCoreApplication::translate("board", "\345\274\210gobang", nullptr));
    } // retranslateUi

};

namespace Ui {
    class board: public Ui_board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
