#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// build single list structure
typedef struct node
{
    int data;
    struct node *next;
} node_t;

//global var pointing at head
struct node *head = NULL;
// struct node *currect = NULL;

// Prototypes
node_t *insertFirst(int data);
bool find(node_t *head, int n);
void printList(node_t *head);
void push(node_t *head, int data);
int pop(node_t **head);



int main(void)
{
    node_t *new = insertFirst(4);
    bool exists = find(head, 6);
    if (exists)
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

// Insert link at the first location
node_t *insertFirst(int data)
{
    node_t *link = malloc(sizeof(node_t));
    if (link == NULL) {
        EXIT_FAILURE;
    }
    link->data = data;
    link->next = head;
    head = link;
    return link;
}

bool find(node_t *head, int data)
{
    node_t *trav = head;
    do
    {
        if (trav->data == data)
            return true;
        else
            trav = trav->next;
    } while (trav->next);
    return false;
}


void destroy(node_t *head)
{

}

void printList(node_t *head) 
{
    node_t *current = head;
    // Start from the beginning
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void push(node_t *head, int data)
{
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    //Now we can add a new variable
    current->next = (note_t *) malloc(sizeof(vode_t));
    current->next->data = data;
    current->next->next = NULL;
}

int pop(node_t **head)
{
    int retval = -1;
    node_t *next_node = NULL;
    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)-data;
    free(*head);
    *head = next_node;
    return retval;
}
