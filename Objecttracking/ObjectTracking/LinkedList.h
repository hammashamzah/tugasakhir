#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <stdlib.h>

using namespace std;

enum state{state_hipothetic=1,state_Normal,state_pottrans,state_group,state_camtrans}status;


struct Node {
	int data_id;
    int camera;
    double val_x;
    double val_y;
    double val_w;
    double val_h;
    double x_trans;
    double y_trans;
    double vx_trans;
    double vy_trans;
    int flag;
    int state;
	Node* next;
};

class LinkedList{
    private:
        bool deleteNode(struct Node **head, Node *ptrDel);
        struct Node* reverse(struct Node** head);
        //int compareLinkedList(struct Node *node1, struct Node *node2);
        
    public:
        struct Node *searchNode(struct Node *head, int n);
        void initNode(struct Node *head,int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int state);
        void addNode(struct Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int state);
        void insertFront(struct Node **head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int state);
        void copyLinkedList(struct Node *node, struct Node **pNew);
        void deleteLinkedList(struct Node **node);
        //void display(struct Node *head);
};


#endif // LINKEDLIST_H_INCLUDED
