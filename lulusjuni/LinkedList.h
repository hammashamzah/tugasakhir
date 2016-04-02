#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <node.h>
using namespace std;



class LinkedList{
    private:
        bool deleteNode(struct Node **head, Node *ptrDel);
        struct Node* reverse(struct Node** head);

        //int compareLinkedList(struct Node *node1, struct Node *node2);

        
    public:
        struct Node *searchNode(struct Node *head, int n);
        void initNode(struct Node *head,int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void addNode(struct Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void insertFront(struct Node **head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void copyLinkedList(struct Node *node, struct Node **pNew);
        void deleteLinkedList(struct Node **node);
        //void display(struct Node *head);
};


#endif // LINKEDLIST_H_INCLUDED
