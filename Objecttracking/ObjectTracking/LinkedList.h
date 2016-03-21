#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <stdlib.h>

using namespace std;

struct Node {
	int data_id;
    int camera;
    double val_x;
    double val_y;
    double val_w;
    double val_h;
    double x_trans;
    double y_trans;
    bool flag;
    bool flago;
	Node* next;
};

class LinkedList{
    private:
        /**struct Node *searchNode(struct Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,bool flag);**/
        bool deleteNode(struct Node **head, Node *ptrDel);
        struct Node* reverse(struct Node** head);
        //int compareLinkedList(struct Node *node1, struct Node *node2);
        
    public:
        struct Node *searchNode(struct Node *head, int n);
        void initNode(struct Node *head,int n,int cam,double x,double y,double w, double h,double x_t, double y_t,bool flag,bool flago);
        void addNode(struct Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,bool flag,bool flago);
        void insertFront(struct Node **head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,bool flag,bool flago);
        void copyLinkedList(struct Node *node, struct Node **pNew);
        void deleteLinkedList(struct Node **node);
        //void display(struct Node *head);
};


#endif // LINKEDLIST_H_INCLUDED
