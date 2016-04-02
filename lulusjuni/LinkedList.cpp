#include "LinkedList.h"


// only for the 1st Node
void LinkedList::initNode( Node *head,int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag, int status){
	head->data_id = n;
    head->camera = cam;
	head->val_x = x;
	head->val_y = y;
	head->val_w = w;
	head->val_h = h;
    head->x_trans = x_t;
    head->y_trans = y_t;
    head->vx_trans = vx;
    head->vx_trans = vy;
    head->flag = flag;
    head->state = status;
	head->next =NULL;
}

// apending
void LinkedList::addNode( Node *head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag,int status) {
	Node *newNode = new Node;
	newNode->data_id = n;
	newNode->camera = cam;
	newNode->val_x = x;
	newNode->val_y = y;
	newNode->val_w = w;
	newNode->val_h = h;
    newNode->x_trans = x_t;
    newNode->y_trans = y_t;
	newNode->vx_trans = vx;
    newNode->vx_trans = vy;
    newNode->flag = flag;
    newNode->state = status;
	newNode->next = NULL;
	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void LinkedList::insertFront(Node **head, int n,int cam,double x,double y,double w, double h,double x_t, double y_t,double vx,double vy,int flag,int status) {
	Node *newNode = new Node;
	newNode->data_id = n;
	newNode->camera = cam;
	newNode->val_x = x;
	newNode->val_y = y;
	newNode->val_w = w;
	newNode->val_h = h;
    newNode->x_trans = x_t;
    newNode->y_trans = y_t;
    newNode->vx_trans = vx;
    newNode->vx_trans = vy;
    newNode->flag = flag;
    newNode->state = status;
    newNode->next = *head;
	*head = newNode;
}


struct Node*LinkedList::searchNode(Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data_id == n) return cur;
		cur = cur->next;
	}
	//cout << "No Node " << n << " in list.\n";
}

bool LinkedList::deleteNode(Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

/* reverse the list */
Node* LinkedList::reverse(Node** head)
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	/* make parent as tail */
	parent->next = NULL;
	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

/* Creating a copy of a linked list */
void LinkedList::copyLinkedList(Node *node,Node **pNew)
{
	if(node != NULL) {
		*pNew = new Node;
		(*pNew)->data_id = node->data_id;
    	(*pNew)->camera = node->camera;
        (*pNew)->val_x = node->val_x;
		(*pNew)->val_y = node->val_y;
		(*pNew)->val_w = node->val_w;
		(*pNew)->val_h = node->val_h;
        (*pNew)->x_trans = node->x_trans;
        (*pNew)->y_trans = node->y_trans;
        (*pNew)->vx_trans = node->vx_trans;
		(*pNew)->vx_trans = node->vy_trans;
        (*pNew)->flag = node->flag;
		(*pNew)->state = node->state;	
		(*pNew)->next = NULL;
		copyLinkedList(node->next, &((*pNew)->next));
	}
}

/* Compare two linked list */
/* return value: same(1), different(0) */
/**int compareLinkedList(struct Node *node1, struct Node *node2)
{
	static int flag;

	 both lists are NULL 
	if(node1 == NULL && node2 == NULL) {
		flag = 1;
	}
	else {
		if(node1 == NULL || node2 == NULL) 
			flag = 0;
		else if(node1->data != node2->data) 
			flag = 0;
		else
			compareLinkedList(node1->next, node2->next);
	}

	return flag;
}**/

void LinkedList::deleteLinkedList(Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}
/**
void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}**/
