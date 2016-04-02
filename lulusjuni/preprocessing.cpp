#include "preprocessing.h"


void Preprocess::extract_data(player* plays, play_transform* played){
    int i;    
    Node *pNew = new Node;
    list1.initNode(pNew,plays[0].id,cam,(double)plays[0].play_dat.x,(double)plays[0].play_dat.y,(double)plays[0].play_dat.width, (double)plays[0].play_dat.height,(double)played[0].x_trans,(double)played[0].y_trans,0,0,played[0].fl,1);
    for(i=1;i<clusters;i++){
        list1.addNode(pNew,plays[i].id,cam,(double)plays[i].play_dat.x,(double)plays[i].play_dat.y,(double)plays[i].play_dat.width, (double)plays[i].play_dat.height,(double)played[i].x_trans,(double)played[i].y_trans,0,0,played[0].fl,1);
    }
}


Preprocess::Preprocess(bool start){
    proc_start = start;
}

Preprocess::~Preprocess(){

}

void Preprocess::accum_preprocess(int num_cluster,int &num_cluster_k1, int cameras,player* plays, play_transform* played){
    clusters1 = clusters;
    clusters = num_cluster;
    if(proc_start){
        extract_data(plays,played);
        list1.copyLinkedList(buff2,&buff1);
        list1.deleteLinkedList(&buff2);
        list1.copyLinkedList(pNew,&buff2);    
        num_cluster_k1 = clusters1;
        list1.deleteLinkedList(&pNew);
        while(buff1 != NULL) {
                    current_dat1 = new Node;
                    current_dat1->data_id = buff1->data_id;
                    current_dat1->val_x= buff1->val_x;
                    current_dat1->val_y = buff1->val_y;
                    current_dat1->val_h= buff1->val_h;
                    current_dat1->val_w = buff1->val_w;
                    current_dat1->x_trans= buff1->x_trans;
                    current_dat1->y_trans= buff1->y_trans;
                    current_dat1->vx_trans= buff1->vx_trans;
                    current_dat1->vy_trans= buff1->vy_trans;
                    current_dat1->flag= buff1->flag;
                    current_dat1->camera= cameras;
                    current_dat1->state= buff1->state;
                    current_dat1->next = buff1->next;
                }
                while(buff2 != NULL) {
                    prev_dat1 = new Node;
                    prev_dat1->data_id = buff2->data_id;
                    prev_dat1->val_x= buff2->val_x;
                    prev_dat1->val_y = buff2->val_y;
                    prev_dat1->val_h= buff2->val_h;
                    prev_dat1->val_w = buff2->val_w;
                    prev_dat1->x_trans= buff2->x_trans;
                    prev_dat1->y_trans= buff2->y_trans;
                    prev_dat1->vx_trans= buff2->vx_trans;
                    prev_dat1->vy_trans= buff2->vy_trans;
                    prev_dat1->flag= buff2->flag;
                    prev_dat1->camera= cameras;
                    prev_dat1->state= buff2->state;
                    prev_dat1->next = buff2->next;
                }
      }
}
