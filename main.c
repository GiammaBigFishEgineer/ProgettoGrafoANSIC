#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int key;
    struct Node *next;
};

void stampa_lista (struct Node *testa){
    struct Node* temp = testa;
    if(temp == NULL)
        exit(1);
    while(temp != NULL){
        printf("Key:%d\n",temp->key);
        temp = temp->next;
    }
}

void deleteNodes(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->key < 4) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        deleteNodes(head);
    } else {
        deleteNodes(&((*head)->next));
    }
}

void insertNode(struct Node** head, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node *testa = NULL;
    int i;
    for(i=0;i<10;i++){
        insertNode(&testa,i);
    }
    stampa_lista(testa);
    deleteNodes(&testa);
    printf("Lista aggiornata:\n");
    stampa_lista(testa);
    return 0;
}
