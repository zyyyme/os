#include <stdio.h>
#include <stdlib.h>

struct Node;

struct Node
{
    int value;
    struct Node *next;
};

void print_list(struct Node* head) {
    if (head->next == NULL) {
        printf("\n");
    } else {
        struct Node *node = head->next;

        while (node->next != NULL) {
            printf("%d - ", node->value);
            node = node->next;
        }

        printf("%d \n", node->value);
    }


}

void insert_node(struct Node* head, int value) {
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;

}

void delete_node(struct Node* head, int value) {
    struct Node *current = head;
    struct Node *predecessor = head;

    while(current->next != NULL) {
        predecessor = current;
        current = current->next;

        if (current->value == value) {
            predecessor->next = current->next;
            break;
        }
    }
} 

int main() {
    struct Node head;
    head.next = NULL;
    
    // Prints nothing
    print_list(&head);

    insert_node(&head, 3);
    insert_node(&head, 5);
    insert_node(&head, 7);

    // 3 - 5 - 7
    print_list(&head);

    delete_node(&head, 5);

    // 3 - 7
    print_list(&head);

    return 0;    
}