#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int value;              // Data stored in the node
    struct node *next;      // pointer to the next node
};

// Prototypes
struct node *add_to_list(struct node *list, int n);

#endif
