#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�������̴�С
#define N 8

//���巽������
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0 ,1 };

//������������
enum Piece { King = 'K', Queen = 'Q', Rook = 'R', Bishop = 'B' };

//�ж��Ƿ���������
int inBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

//�������ʼλ�õ�Ŀ��λ����������ٲ���
int minSteps(enum Piece piece, int sx, int sy, int tx, int ty) {
    //�����ʼλ�ú�Ŀ��λ����ͬ���򷵻�0
    if (sx == tx && sy == ty) return 0;
    //����������򷵻�����֮��������پ�������ֵ
    if (piece == King) return abs(sx - tx) > abs(sy - ty) ? abs(sx - tx) : abs(sy - ty);
    //����Ǻ��򷵻�����֮���Ƿ���ͬһ��ֱ�߻�Խ����ϣ����򷵻�1�����򷵻�2
    if (piece == Queen) return sx == tx || sy == ty || abs(sx - tx) == abs(sy - ty) ? 1 : 2;
    //����ǳ����򷵻�����֮���Ƿ���ͬһ��ֱ���ϣ����򷵻�1�����򷵻�2
    if (piece == Rook) return sx == tx || sy == ty ? 1 : 2;
    //����������ж�����֮���Ƿ���ͬһ���Խ����ϣ�������ɫ��ͬ������ż����ͬ�������򷵻�1�������޷����ﷵ��-1
    if (piece == Bishop) {
        if (abs(sx - tx) != abs(sy - ty)) return -1; //���ڶԽ�����
        if ((sx + sy) % 2 != (tx + ty) % 2) return -1; //��ɫ��ͬ����ż�Բ�ͬ��
        return 1;
    }
}

//����ĸת��Ϊ�������꣨a-h -> 0-7��
int letterToNum(char c) {
    return c - 'a';
}

//������
int main() {

    int t; //������������

    scanf("%d", &t); //���������������

    while (t--) { //ѭ������ÿ���������

        char start[3], target[3]; //��ʼλ�ú�Ŀ��λ��

        scanf("%s %s", start, target); //������ʼλ�ú�Ŀ��λ��

        int sx = letterToNum(start[0]); //����ʼλ�õ���ĸת��Ϊ�������꣨�����꣩
        int sy = start[1] - '0' - 1;     //����ʼλ�õ�����ת��Ϊ�������꣨�����꣩

        int tx = letterToNum(target[0]); //��Ŀ��λ�õ���ĸת��Ϊ�������꣨�����꣩
        int ty = target[1] - '0' - 1;     //��Ŀ��λ�õ�����ת��Ϊ�������꣨�����꣩

        printf("%d %d %d %d\n", minSteps(King, sx, sy, tx,
            ty), minSteps(Queen, sx, sy,
                tx,
                ty), minSteps(Rook, sx, sy,
                    tx,
                    ty), minSteps(Bishop, sx, sy,
                        tx,
                        ty));
        //��������󡢳�������������ٲ���

    }

}