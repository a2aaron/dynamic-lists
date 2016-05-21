#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int item_count;
    int mem_size;
    int *data;
};
/* Appends the value to the end of a target list.
 * Reallocates if there isn't enough memory.
 */
void append(struct list *l, int value) {
    l->data[l->item_count] = value;

    l->item_count++;
    if (l->item_count > l->mem_size) {
        l->mem_size *= 2;
        if (l->mem_size == 0) {
            l->mem_size = 8;
            realloc(l->data, l->mem_size * sizeof(int));
        }
    }
}

int pop(struct list *l) {
    if (l->item_count == 0) {
        return -1;
    }

    l->item_count--;
    int popped = l->data[l->item_count];
    return popped;

}

int main() {
    struct list l = {0, 8, NULL};
    l.data = calloc(l.item_count, l.mem_size);
    append(&l, 4);
    append(&l, 5);
    append(&l, 6);
    for (int i = 0; i < l.item_count; i++) {
        printf("%d\n", l.data[i]);
    }
    int popped = pop(&l);
    int popped2 = pop(&l);
    int popped3 = pop(&l);
    int popped4 = pop(&l);
    printf("Popped: %d\n", popped);
    printf("Popped: %d\n", popped2);
    printf("Popped: %d\n", popped3);
    printf("Popped: %d\n", popped4);

    return 0;
}