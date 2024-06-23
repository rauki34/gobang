/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *title;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pvp;
    QPushButton *pvc;
    QPushButton *quit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Pictures/\346\210\220\346\277\221\351\241\272.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(800, 600));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{border-image: url(:/new/prefix1/image/boki.jpg);}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setMinimumSize(QSize(800, 250));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(80);
        font.setBold(true);
        title->setFont(font);
        title->setMouseTracking(false);
        title->setTabletTracking(false);
        title->setTextFormat(Qt::AutoText);
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(800, 350));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_3, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        pvp = new QPushButton(widget_2);
        pvp->setObjectName(QString::fromUtf8("pvp"));
        pvp->setMinimumSize(QSize(400, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font1.setPointSize(42);
        pvp->setFont(font1);
        pvp->setFocusPolicy(Qt::StrongFocus);
        pvp->setAutoFillBackground(false);
        pvp->setCheckable(false);
        pvp->setFlat(true);

        gridLayout_2->addWidget(pvp, 0, 1, 1, 1);

        pvc = new QPushButton(widget_2);
        pvc->setObjectName(QString::fromUtf8("pvc"));
        pvc->setMinimumSize(QSize(400, 80));
        pvc->setFont(font1);
        pvc->setFlat(true);

        gridLayout_2->addWidget(pvc, 2, 1, 1, 1);

        quit = new QPushButton(widget_2);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setMinimumSize(QSize(400, 80));
        quit->setFont(font1);
        quit->setFlat(true);

        gridLayout_2->addWidget(quit, 4, 1, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
        pvp->setText(QCoreApplication::translate("MainWindow", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        pvc->setText(QCoreApplication::translate("MainWindow", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
