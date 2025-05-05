#include <QApplication>
#include "maze_solver_gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MazeSolverGui w;
    w.show();
    return a.exec();
}
