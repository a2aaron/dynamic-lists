#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int item_count;
    int mem_size;
    int *data;
};

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

int main() {
    struct list l = {0, 8, NULL};
    l.data = calloc(l.item_count, l.mem_size);
    append(&l, 4);
    append(&l, 5);
    append(&l, 6);
    for (int i = 0; i < l.item_count; i++) {
        printf("%d\n", l.data[i]);
    }
    return 0;
}