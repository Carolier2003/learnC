#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义棋盘大小
#define N 8

//定义方向数组
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0 ,1 };

//定义棋子类型
enum Piece { King = 'K', Queen = 'Q', Rook = 'R', Bishop = 'B' };

//判断是否在棋盘内
int inBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

//计算从起始位置到目标位置所需的最少步数
int minSteps(enum Piece piece, int sx, int sy, int tx, int ty) {
    //如果起始位置和目标位置相同，则返回0
    if (sx == tx && sy == ty) return 0;
    //如果是王，则返回两点之间的曼哈顿距离的最大值
    if (piece == King) return abs(sx - tx) > abs(sy - ty) ? abs(sx - tx) : abs(sy - ty);
    //如果是后，则返回两点之间是否在同一条直线或对角线上，是则返回1，否则返回2
    if (piece == Queen) return sx == tx || sy == ty || abs(sx - tx) == abs(sy - ty) ? 1 : 2;
    //如果是车，则返回两点之间是否在同一条直线上，是则返回1，否则返回2
    if (piece == Rook) return sx == tx || sy == ty ? 1 : 2;
    //如果是象，则判断两点之间是否在同一条对角线上，并且颜色相同（即奇偶性相同），是则返回1，否则无法到达返回-1
    if (piece == Bishop) {
        if (abs(sx - tx) != abs(sy - ty)) return -1; //不在对角线上
        if ((sx + sy) % 2 != (tx + ty) % 2) return -1; //颜色不同（奇偶性不同）
        return 1;
    }
}

//将字母转换为数字坐标（a-h -> 0-7）
int letterToNum(char c) {
    return c - 'a';
}

//主函数
int main() {

    int t; //测试数据组数

    scanf("%d", &t); //输入测试数据组数

    while (t--) { //循环处理每组测试数据

        char start[3], target[3]; //起始位置和目标位置

        scanf("%s %s", start, target); //输入起始位置和目标位置

        int sx = letterToNum(start[0]); //将起始位置的字母转换为数字坐标（横坐标）
        int sy = start[1] - '0' - 1;     //将起始位置的数字转换为数字坐标（纵坐标）

        int tx = letterToNum(target[0]); //将目标位置的字母转换为数字坐标（横坐标）
        int ty = target[1] - '0' - 1;     //将目标位置的数字转换为数字坐标（纵坐标）

        printf("%d %d %d %d\n", minSteps(King, sx, sy, tx,
            ty), minSteps(Queen, sx, sy,
                tx,
                ty), minSteps(Rook, sx, sy,
                    tx,
                    ty), minSteps(Bishop, sx, sy,
                        tx,
                        ty));
        //输出王、后、车、象所需的最少步数

    }

}