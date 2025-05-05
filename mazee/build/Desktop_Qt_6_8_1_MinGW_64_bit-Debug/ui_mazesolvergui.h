/********************************************************************************
** Form generated from reading UI file 'mazesolvergui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZESOLVERGUI_H
#define UI_MAZESOLVERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazeSolverGui
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MazeSolverGui)
    {
        if (MazeSolverGui->objectName().isEmpty())
            MazeSolverGui->setObjectName("MazeSolverGui");
        MazeSolverGui->resize(800, 600);
        centralwidget = new QWidget(MazeSolverGui);
        centralwidget->setObjectName("centralwidget");
        MazeSolverGui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MazeSolverGui);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MazeSolverGui->setMenuBar(menubar);
        statusbar = new QStatusBar(MazeSolverGui);
        statusbar->setObjectName("statusbar");
        MazeSolverGui->setStatusBar(statusbar);

        retranslateUi(MazeSolverGui);

        QMetaObject::connectSlotsByName(MazeSolverGui);
    } // setupUi

    void retranslateUi(QMainWindow *MazeSolverGui)
    {
        MazeSolverGui->setWindowTitle(QCoreApplication::translate("MazeSolverGui", "MazeSolverGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazeSolverGui: public Ui_MazeSolverGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZESOLVERGUI_H
