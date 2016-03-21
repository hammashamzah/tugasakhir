#include "preprocessing.h"

void extract_data(struct Node *pNew, player* plays, play_transform* played){
    int i;    
    //Node *pNew = new Node;
    list1.initNode(pNew,plays[0].id,cam,(double)plays[0].play_dat.x,(double)plays[0].play_dat.y,(double)plays[0].play_dat.width, (double)plays[0].play_dat.height,(double)played[0].x_trans,(double)played[0].y_trans,played[0].fl,plays[0].fo);
    for(i=1;i<clusters;i++){
        list1.addNode(pNew,plays[i].id,cam,(double)plays[i].play_dat.x,(double)plays[i].play_dat.y,(double)plays[i].play_dat.width, (double)plays[i].play_dat.height,(double)played[i].x_trans,(double)played[i].y_trans,played[i].fl,plays[i].fo);      
    }
    //return *pNew;
}


void preprocess(bool start,int num_cluster,int num_cluster_k1, int cameras,player* plays, play_transform* played, struct Node *buffer1,struct Node *buffer2){
    clusters1 = clusters;
    clusters = num_cluster;
    cam = cameras;
    Node *buffer = new Node;
    if(start){
        list1.deleteLinkedList(&buffer1);
        extract_data(&*buffer,plays,played);
        list1.copyLinkedList(buffer2,&buffer1);
        list1.deleteLinkedList(&buffer2);
        list1.copyLinkedList(buffer,&buffer2);    
        num_cluster_k1 = clusters1;
        list1.deleteLinkedList(&buffer);
    }
}
