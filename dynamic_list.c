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

int delete(struct list *l, int index) {
    // Sanity check.
    if (index < 0 || index > l->item_count) {
        return -1;
    }
    //remember that both item_count and index are ints, so we have to multiply by the size of ints.
    memmove(l->data + index, l->data + index + 1, (l->item_count - index) * sizeof(int));
    l->item_count--;
    return 0;
}

void print_list(struct list *l) {
    for (int i = 0; i < l->item_count; i++) {
        printf("%d ", l->data[i]);
    } 
    printf("\n");
}

int main() {
    struct list l = {0, 8, NULL};
    l.data = calloc(l.item_count, l.mem_size);
    for (int i = 0; i < 10; i++) {
        append(&l, i);
    }
    print_list(&l);

    delete(&l, 3);
    print_list(&l);
    delete(&l, 8);
    print_list(&l);
    delete(&l, 0);
    print_list(&l);
    return 0;
}