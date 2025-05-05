#include <QApplication>  // Include QApplication header for Qt applications
#include "MazeSolverGui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Initialize the QApplication

    MazeSolverGui window;  // Create the MazeSolverGui window
    window.show();  // Show the window

    return app.exec();  // Start the Qt event loop
}

