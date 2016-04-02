#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
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

#endif // NODE_H
