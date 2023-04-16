#include<stdio.h>
#include<string.h>
int Count;
struct student {
    char sno[20], name[20];
    int math, english, chinese, sum;
};

void print(struct student stu) {
    printf("%s %s %d %d %d %d\n", stu.sno, stu.name, stu.math, stu.english, stu.chinese, stu.sum);
}

void query_stu(struct student s[], char* name) {
    /*********Begin*********/
    //遍历结构体数组，找到与name相同的学生，并打印其信息
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].name, name) == 0) {
            print(s[i]);
        }
    }
    /*********End**********/
}

void delete_stu(struct student s[], char* sno) {
    /*********Begin*********/
    //遍历结构体数组，找到与sno相同的学生，并将其后面的元素依次向前移动一位
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].sno, sno) == 0) {
            for (int j = i + 1; j < Count; j++) {
                s[j - 1] = s[j];
            }
            Count--; 
            break;
        }
    }
    /*********End**********/
}

void update_stu(struct student s[], char* sno, int math, int english, int chinese) {
    /*********Begin*********/
    //遍历结构体数组，找到与sno相同的学生，并更新其成绩和总分
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].sno, sno) == 0) {
            s[i].math = math;
            s[i].english = english;
            s[i].chinese = chinese;
            s[i].sum = math + english + chinese;
            break;
        }
    }
    /*********End**********/
}

int main(void)
{
    int n, q;
    struct student students[50];
    scanf("%d%d", &n, &q);
    Count = n;
    for (int i = 0; i < n; i++) {
        /*********Begin*********/
        //输入每个学生的信息，并计算总分
        scanf("%s%s%d%d%d", &students[i].sno,
            &students[i].name,
            &students[i].math,
            &students[i].english,
            &students[i].chinese);
        students[i].sum =
            students[i].math +
            students[i].english +
            students[i].chinese;
        /*********End**********/
    }
    while (q--) {
        int op;
        scanf("%d", &op);
        char sno[20], name[20];
        if (op == 1) {
            scanf("%s", name);
            query_stu(students, name);
        }
        else if (op == 2) {
            int a, b, c;
            scanf("%s%d%d%d", sno, &a, &b, &c);
            update_stu(students, sno, a, b, c);
            for (int i = 0; i < Count; i++)
                print(students[i]);
        }
        else {
            scanf("%s", sno);
            delete_stu(students, sno);
            for (int i = 0; i < Count - 1; i++)
                print(students[i]);
        }
    }
    return 0;
}