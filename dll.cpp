//https://www.geeksforgeeks.org/doubly-linked-list/
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

//從頭加node
void push(Node** first_node, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*first_node);//reference
    new_node->prev = NULL;
    if((*first_node) != NULL)
        (*first_node)->prev = new_node;
    (*first_node) = new_node;
}

//從尾巴加node
void append(Node** first_node, int data){
    Node* new_node = new Node();
    Node* last = (*first_node);
    new_node->data = data;
    new_node->next = NULL;
    if((*first_node) == NULL){
        new_node->prev = NULL;
        (*first_node) = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

void printList(Node* node){
    Node* last;
    while(node != NULL){
        cout << " " << node->data << " ";
        last = node; //for Reverse
        node = node->next;
    }
    //Reverse
    while(last != NULL){
        cout << " " << last->data << " ";
        last = last->prev;
    }
}

int main(){
    Node* head = NULL;
    
    append(&head, 6);
    push(&head, 7); 

    printList(head);

    return 0;
}