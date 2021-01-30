#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int value)
{
    node* head = (node *)malloc(sizeof(node));
    head->data = value;
    head->next = NULL;
    return head;
}

void insert(node *head, int value)
{
    if (!head) return;
    node *curr = head;
    node *new_node = create(value);

    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new_node;
}

node *search(node *head, int value)
{
    if (!head) return NULL;
    node *curr = head;

    while (curr) {
        if (curr->data == value) {
            return curr;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}

void delete(node *head, int value)
{
    if (!head) return;
    node *curr = head;
    node *prev = NULL;

    while (curr) {
        if (curr->data != value) {
            prev = curr;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }
}

int list_size(node *head)
{
    if (!head) return 0;
    else {
        return 1 + list_size(head->next);
    }
}

void print_list(node *head)
{
    if (!head) {
        puts("Head is null");
        return;
    }
    node *curr = head;
    while (curr->next) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

int main()
{
    // Testing
    node *head = create(0);
    insert(head, 3);
    insert(head, 5);
    insert(head, 7);
    node *found = search(head, 7);
    if (found) {
        printf("Found a node, value = %d\n", found->data);
    } else {
        puts("Did not find a node with value 7");
    }
    printf("Size after insert: %d\n", list_size(head));
    print_list(head);
    delete(head, 3);
    printf("Size after delete: %d\n", list_size(head));
    delete(head, 66);
    printf("Size after delete: %d\n", list_size(head));
    print_list(head);
    return 0;
}



