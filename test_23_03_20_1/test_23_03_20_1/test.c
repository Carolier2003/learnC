#include <stdio.h>

struct student {
    char id[11];
    char name[21];
    int grade;
} students[200];

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s %d", students[i].id, students[i].name, &students[i].grade);
    }
    struct student temp;
    for (i = 1; i < n ; i++) {
        for (j = 0 ; j < n - i; j++) {
            if (students[j].grade < students[j + 1].grade) {
                temp = students[j + 1];
                students[j + 1] = students[j];
                students[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].grade);
    }
    return 0;
}