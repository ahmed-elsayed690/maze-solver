#include "maze_solver_gui.h"
#include <QPainter>
#include <QPen>
#include <QMessageBox>

MazeSolverGui::MazeSolverGui(QWidget *parent)
    : QMainWindow(parent), centralWidget(new QWidget(this)), gridLayout(new QGridLayout(centralWidget)) {

    setWindowTitle("Maze Solver");
    setFixedSize(400, 400);  // Set a fixed size for the window

    // Create buttons and layout
    playButton = new QPushButton("Play", this);
    solveButton = new QPushButton("Solve", this);
    editButton = new QPushButton("Edit Maze", this);
    setStartExitButton = new QPushButton("Set Start & Exit", this);
    statusLabel = new QLabel("Use buttons to interact with the maze.", this);

    gridLayout->addWidget(playButton, 0, 0);
    gridLayout->addWidget(solveButton, 0, 1);
    gridLayout->addWidget(editButton, 0, 2);
    gridLayout->addWidget(setStartExitButton, 1, 0, 1, 3);
    gridLayout->addWidget(statusLabel, 2, 0, 1, 3);

    setCentralWidget(centralWidget);

    // Initialize the maze
    srand(time(0));  // Initialize random seed
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
            visited[i][j] = false;
        }
    }

    // Randomly clear some paths
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            if (rand() % 4 != 0) {
                maze[i][j] = EMPTY;
            }
        }
    }

    // Connect signals and slots
    connect(playButton, &QPushButton::clicked, this, &MazeSolverGui::onPlayButtonClicked);
    connect(solveButton, &QPushButton::clicked, this, &MazeSolverGui::onSolveButtonClicked);
    connect(editButton, &QPushButton::clicked, this, &MazeSolverGui::onEditButtonClicked);
    connect(setStartExitButton, &QPushButton::clicked, this, &MazeSolverGui::onSetStartExitButtonClicked);
}

MazeSolverGui::~MazeSolverGui() {}

void MazeSolverGui::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    int cellWidth = width() / COLS;
    int cellHeight = height() / ROWS;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            QRect cell(j * cellWidth, i * cellHeight, cellWidth, cellHeight);

            if (maze[i][j] == WALL) {
                painter.fillRect(cell, Qt::black);
            } else if (maze[i][j] == START) {
                painter.fillRect(cell, Qt::green);
            } else if (maze[i][j] == EXIT) {
                painter.fillRect(cell, Qt::red);
            } else if (maze[i][j] == PATH) {
                painter.fillRect(cell, Qt::lightGray);
            } else {
                painter.fillRect(cell, Qt::white);
            }

            painter.drawRect(cell);
        }
    }
}

void MazeSolverGui::onPlayButtonClicked() {
    statusLabel->setText("Playing the maze...");
    // Add logic for interactive play
    play();
}

void MazeSolverGui::onSolveButtonClicked() {
    statusLabel->setText("Solving the maze...");
    solveMaze();
}

void MazeSolverGui::onEditButtonClicked() {
    editMaze();
}

void MazeSolverGui::onSetStartExitButtonClicked() {
    setStartExit();
}

void MazeSolverGui::movePlayer(int direction) {
    int newX = player.x + dirX[direction];
    int newY = player.y + dirY[direction];

    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] != WALL) {
        maze[player.x][player.y] = PATH;
        player.x = newX;
        player.y = newY;
        maze[player.x][player.y] = START;
        update();  // Update the GUI after moving
    }
}

bool MazeSolverGui::dfs(Position start) {
    stack<Position> s;
    s.push(start);
    visited[start.x][start.y] = true;

    while (!s.empty()) {
        Position currentPos = s.top();
        s.pop();

        if (currentPos.x == exit.x && currentPos.y == exit.y) {
            maze[currentPos.x][currentPos.y] = EXIT;
            update();  // Update GUI
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentPos.x + dirX[i];
            int newY = currentPos.y + dirY[i];

            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && !visited[newX][newY] && maze[newX][newY] != WALL) {
                visited[newX][newY] = true;
                s.push({ newX, newY });
                maze[newX][newY] = PATH;
            }
        }

        update();  // Update GUI
    }
    return false;
}

void MazeSolverGui::solveMaze() {
    if (dfs(start)) {
        QMessageBox::information(this, "Maze Solved", "Path to exit found!");
    } else {
        QMessageBox::information(this, "No Path", "No path found!");
    }
}

void MazeSolverGui::setStartExit() {
    bool valid = false;
    while (!valid) {
        bool ok;
        int startX = QInputDialog::getInt(this, "Set Start Position", "Enter Start X (0-9):", 0, 0, 9, 1, &ok);
        int startY = QInputDialog::getInt(this, "Set Start Position", "Enter Start Y (0-9):", 0, 0, 9, 1, &ok);
        int exitX = QInputDialog::getInt(this, "Set Exit Position", "Enter Exit X (0-9):", 0, 0, 9, 1, &ok);
        int exitY = QInputDialog::getInt(this, "Set Exit Position", "Enter Exit Y (0-9):", 0, 0, 9, 1, &ok);

        if (ok && startX >= 0 && startX < ROWS && startY >= 0 && startY < COLS && exitX >= 0 && exitX < ROWS && exitY >= 0 && exitY < COLS && (startX != exitX || startY != exitY)) {
            start = { startX, startY };
            exit = { exitX, exitY };
            maze[start.x][start.y] = START;
            maze[exit.x][exit.y] = EXIT;
            player = start;  // Place player at start position
            valid = true;
        } else {
            QMessageBox::warning(this, "Invalid Input", "Invalid start or exit positions.");
        }
    }
}

void MazeSolverGui::editMaze() {
    // Implement maze editing feature here
}
