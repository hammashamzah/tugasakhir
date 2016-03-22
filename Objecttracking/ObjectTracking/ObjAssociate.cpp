#include "ObjAssociate.h"

associate::associate(int cam,int num_p,int num_m,struct Node *p,struct Node *m,int assoc[][23]){
    int i,j;
    num_predictor = num_p;
    num_measurement = num_m;
    num_samples = num_p;
    listgen.copyLinkedList(p,&predictor);
    listgen.copyLinkedList(m,&measurement);
    if(ydl>yul && ydr>yur && xdr>xur && xdl<xur){
        yo =((xdr-xdl)/(((-xdl+xul)/(ydl-yul))+((xdr-xur)/(ydr-yur))))-((ydl+ydr)/2);
    }
    xo =(((((yo*(-xdl+xul))/(ydl-yul))+xdl)+(((yo*(xdr-xur))/(ydr-yur))+(xdr)))/2);
    link_theid();
    if(cam ==camera_max){
        occlusiob_handler();
        in_out_handler();
    }
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            assoc[i][j]= association[i][j];
        }
    }
}

void init_matrices_assoc(){
    int i,j;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            association[i][j]= 0;
        }
    }
}


associate::~associate(){

}


double associate::threshold_coef(double y){
    double threshold_k;
    double konst = (ydl+ydr)/2;
    if(y!=konst){
        threshold_k  = ((y-yo)/(y-konst));
    }
    return (threshold_k);
}

void associate::find_threshold_x(double *x_kanan,double *x_kiri,double y,double x,double y_m){
    double k = threshold_coef(y);
    double th = k*basic_threshold;
    if(y > yo){
        *x_kanan = x+(th/2)-(((x-xo)/(y-yo))*(y_m-y));
        *x_kiri = x-(th/2)-(((x-xo)/(y-yo))*(y_m-y));
    }
}

double associate::find_threshold_y(double y){
    double k = threshold_coef(y);
    double th = k*basic_threshold;
    return th/2;
}


/**Hungarian Algorithms**/
void associate::link_theid(){
    double Euclid_x;
    double Euclid_y;
    int i=0;int j = 0;
    int k = 0;
    double th_xka,th_xki,th_y;
    while(i<num_measurement){
        while(j<num_predictor){
            Euclid_x = predictor->val_x-measurement->val_x;
            Euclid_y = abs(predictor->val_y-measurement->val_y);
            find_threshold_x(&th_xka,&th_xki,measurement->val_y,measurement->val_x,predictor->val_y);
            th_y=find_threshold_y(predictor->val_y);
            if(Euclid_y < th_y){
                if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                    association[predictor->data_id][measurement->data_id] = 1;
                }
            }
            else{
                predictor->data_id = 30;
            }
            predictor = predictor->next;
            measurement = measurement->next;
            j++;
        }
        i++;
    }      
}

void associate::occlusion_handler(){
    empredict.train();


}

void associate::in_out_handler(){



}

