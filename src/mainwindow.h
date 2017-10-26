#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QLabel>

#define COM -1
#define MAN 1
#define ROW 3
#define COL 3
#define MAX_NUM 1000;

#define AIZZ 3  // 人工智障
#define AIZN 1  // 人工智能
#define AIZS 0  // 人工智神

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<QPushButton *> btnList;

private:
    Ui::MainWindow *ui;

    QLabel *labelLevel, *labelFirst;
    QRadioButton *radioBtnManVSCom, *radioBtnManVSMan, *radioBtnLevel1, *radioBtnLevel2, *radioBtnLevel3, *radioBtnManFirst, *radioBtnComFirst;

    // 棋子位置
    struct Move
    {
        int x;
        int y;
    };

    // 是否为圈下子
    bool isCircle;

    // 人人对战 = 1， 人机对战 = 0
    int gameType;

    // 难度类型：人工智障, 人工智能, 人工智神
    int levelType;

    //玩家
    int player;

    //最好的一步
    Move bestMove;

    //当前深度
    int currentDepth;

    // 圈的棋盘
    int _cirCleMapNum[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    // 叉的棋盘
    int _crossMapNum[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };

    //棋盘
    int board[3][3] = {
        { 0,0,0 },
        { 0,0,0 },
        { 0,0,0 }
    };

    // 临时棋盘
    int tempBoard[3][3] = {
        { 0,0,0 },
        { 0,0,0 },
        { 0,0,0 }
    };

    void isWin();
    bool isDraw();
    void clearMapNum();

    int a_isWin();
    bool a_isDraw();
    int a_evaluteMap();
    void a_makeMove(Move curMove);
    void a_unMakeMove(Move curMove);
    int a_getMoveList(Move moveList[]);
    int a_miniMaxsearch(int depth);
    void a_printBoard();
    int a_com_play();
    int a_man_play(QPushButton *btn);
    void checkComFirst();
    void ManVSMan(QPushButton *btn);
    void ManVSCom(QPushButton *btn);

public slots:
    void btnClick();
    void ending();
    void radioBtnClick();
};

#endif // MAINWINDOW_H
