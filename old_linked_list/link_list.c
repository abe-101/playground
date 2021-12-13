#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// build single list structure
typedef struct node
{
    int val;
    struct node *next;
} node_t;

//global var pointing at head
node_t *head = NULL;
// note_t *currect = NULL;

// Prototypes
bool find(node_t **head, int n);
void print_list(node_t *head);
node_t *push_front(node_t **head, int value);
int pop_front(node_t **head);
void destroy_list(node_t *head);



int main(void)
{
    node_t *new = push_front(&head, 6);
    bool exists = find(&head, 6);
    if (exists)
        printf("Found\n");
    else
        printf("Not found\n");
    node_t *two = push_front(&head, 23);
    print_list(head);
    pop_front(&head);
    destroy_list(head);
    return 0;
}

// Insert link at the first location
node_t *push_front(node_t **head, int value) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        EXIT_FAILURE;
    }
    node->val = value;
    node->next = *head;

    *head = node;
    return node;
}

bool find(node_t **head, int value)
{
    node_t *trav = *head;
    while (trav)
    {
        if (trav->val == value)
            return true;
        else
            trav = trav->next;
    } 
    return false;
}


void destroy_list(node_t *head)
{
    node_t *current = head;

    while(current) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

void print_list(node_t *head) 
{
    node_t *current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }

    printf("\n");
}

int pop_front(node_t **head) {
    if (*head == NULL) {
        printf("Unable to pop_front an emtpy list.");
        exit(EXIT_FAILURE);
    }

    int value = (*head)->val;

    node_t *front = *head;
    *head = front->next;

    free(front);

    return value;
}



