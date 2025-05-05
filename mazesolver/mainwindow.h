#ifndef MAZE_SOLVER_GUI_H
#define MAZE_SOLVER_GUI_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPen>

#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 10;  // Maze rows
const int COLS = 10;  // Maze columns
const char WALL = '#';
const char EMPTY = ' ';
const char START = 'S';
const char EXIT = 'E';
const char PATH = '.';

struct Position {
    int x, y;
};

class MazeSolverGui : public QMainWindow {
    Q_OBJECT

private:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *playButton, *solveButton, *editButton, *setStartExitButton;
    QLabel *statusLabel;
    char maze[ROWS][COLS];
    Position start, exit, player;
    bool visited[ROWS][COLS];

    // Directions: right, down, left, up
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {1, 0, -1, 0};

public:
    MazeSolverGui(QWidget *parent = nullptr);
    ~MazeSolverGui();

    void printMaze();
    void movePlayer(int direction);
    bool dfs(Position start);
    void solveMaze();
    void setStartExit();
    void editMaze();
    void play();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onPlayButtonClicked();
    void onSolveButtonClicked();
    void onEditButtonClicked();
    void onSetStartExitButtonClicked();
};

#endif // MAZE_SOLVER_GUI_H
