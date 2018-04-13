#include <stdio.h>
#include "../inc/queue.h"
#include "../inc/list.h"

int main() {
    struct list *list = createList(2);

    list = insertNode(list, 4);
    list = insertNode(list, 3);
    list = insertNode(list, 1);
    list = deleteNode(list, 3);


    printList(list);
    removeList(&list);
    return 0;
}