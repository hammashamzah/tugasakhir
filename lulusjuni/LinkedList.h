#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <node.h>
using namespace std;



class LinkedList{
    private:
        bool deleteNode(Node **head, Node *ptrDel);
        Node* reverse(Node** head);

        //int compareLinkedList(struct Node *node1, struct Node *node2);

        
    public:
        Node *searchNode(Node *head, int n);
        void initNode(Node *head,int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void addNode(Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void insertFront(Node **head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status);
        void copyLinkedList(Node *node, Node **pNew);
        void deleteLinkedList(Node **node);
        //void display(struct Node *head);
};


#endif // LINKEDLIST_H_INCLUDED
