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
node_t *create(int data);
bool find(node_t *head, int n);


int main(void)
{
    node_t *new = create(4);
    bool exists = find(head, 6);
    if (exists)
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

node_t *create(int data)
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

node_t *insert(node_t *head, int n)
{

}

void destroy(node_t *head)
{

}
