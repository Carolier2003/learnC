#include <stdio.h>
#include <stdlib.h>


/// linked tablest
struct std {
    int ID;
    float Score;
    struct std* Next;  /// a structure pointer added
};

/// SQL: 1. select, 2. insert, 3. delete, 4. update
/// 1. select
void std_select(struct std* head) {
    if (head == NULL)
        printf("\nstd_select: empty linked table, nothing to print\n");
    else {
        for (; head != NULL; head = head->Next)
            printf("std_select: ID = %d, Score = %.1f\n", head->ID, head->Score);
        printf("\n\n");
    }
}

/// 2. insert
/// 2.1 insert the 1st one
struct std* std_create(struct std* head, int ID, float Score) {
    if (head != NULL)
        return head;
    head = (struct std*)malloc(sizeof(struct std));
    head->ID = ID;
    head->Score = Score;
    head->Next = NULL;
    std_select(head);
    return head;
};

/// 2.2 insert one std
struct std* std_insert(struct std* head, int ID, float Score) {
    struct std* p1, * p2, * p;
    p = (struct std*)malloc(sizeof(struct std));
    p->ID = ID;
    p->Score = Score;
    p->Next = NULL;

    if (head == NULL)
        head = std_create(head, ID, Score);
    else {
        for (p1 = p2 = head; p->Score <= p1->Score && p1->Next != NULL; p2 = p1, p1 = p1->Next);

        if (p->Score > p1->Score) {
            if (p1 == head) {
                printf("std_insert: new head inserted.\n");
                p->Next = p1;
                head = p;
            }
            else {
                printf("std_insert: internal inserted.\n");
                p2->Next = p;
                p->Next = p1;
            }
        }
        else {
            if (p1->Next == NULL) {
                printf("std_insert: new tail inserted.\n");
                p1->Next = p;
                p->Next = NULL;
            }
            else {
                printf("std_insert: un-known condition.\n");
            }
        }
        std_select(head);
    }
    return head;
};

/// 2.3 insert_x
struct std* std_insert_x(struct std* head) {
    int ID;
    float Score;
    while (1) {
        printf("std_insert_x: please input ID and Score (0, 0 to EXIT): ");
        scanf("%d%f", &ID, &Score);

        if (ID == 0 && Score == 0) {
            printf("std_insert_x: 0 and 0 to EXIT\n");
            break;
        }

        head = std_insert(head, ID, Score);
    }
    return head;
};


/// 3. delete
/// 3.1 delete one
struct std* std_delete(struct std* head, int ID) {
    struct std* p1, * p2;
    struct std* p; /// to free

    if (head == NULL) {
        printf("std_delete: empty linked table, nothing to delete\n");
        return head;
    }

    for (p1 = p2 = head; p1->ID != ID && p1->Next != NULL; p2 = p1, p1 = p1->Next);

    if (p1->ID == ID) {
        p = p1;
        if (p1 == head) {
            printf("std_delete: head deleted.\n");
            head = head->Next;
        }
        else {
            if (p1->Next == NULL) {
                printf("std_delete: tail deleted.\n");
                p2->Next = NULL;
            }
            else {
                printf("std_delete: internal deleted.\n");
                p2->Next = p1->Next;
            }
        }
        free(p);  /// to release the memory via deletion
    }
    else {
        printf("std_delete: ID %d can NOT be found to delete.\n", ID);
    }

    std_select(head);
    return head;
};

/// 3.2 delete_x
struct std* std_delete_x(struct std* head) {
    int ID;
    while (1) {
        printf("std_delete_x: please input the ID to delete (0 to EXIT): ");
        scanf("%d", &ID);

        if (ID == 0) {
            printf("std_delete_x: 0 to EXIT.\n");
            break;
        }

        head = std_delete(head, ID);
    }
    return head;
};


/// 4. update
struct std* std_update_x(struct std* head) {
    int ID;
    float Score;

    while (1) {
        printf("std_update_x: please input ID & Score to update (0, 0 to EXIT): ");
        scanf("%d%f", &ID, &Score);

        if (ID == 0 && Score == 0) {
            printf("std_update_x: 0, 0 to EXIT");
            break;
        }

        head = std_delete(head, ID);
        head = std_insert(head, ID, Score);

    }
    return head;
};



int main() {
    struct std* head = NULL;
    ///head = std_create(head, 3, 33);
    head = std_insert_x(head);
    head = std_delete_x(head);
    head = std_update_x(head);
    system("pause");
    return 0;
}
