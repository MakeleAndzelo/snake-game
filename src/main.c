#include <stdio.h>
#include "../inc/queue.h"
#include "../inc/list.h"

int main() {
    struct list *list = createList(2);



    printList(list);
    removeList(&list);
    return 0;
}