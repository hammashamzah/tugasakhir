#include "ObjAssociate.h"




associate::associate(bool isInit,struct Node* predictor1,struct Node* predictor2,struct Node* predictor3,struct Node* measurement1,struct Node* measurement2,struct Node* measurement3,int num_p1,int num_p2,int num_p3,int num_m1,int num_m2,int num_m3,int assoc[][23]){
    Inits = isInit;
    nump1 = num_p1;
    nump2 = num_p2;
    nump3 = num_p3;
    numm1 = num_m1;
    numm2 = num_m2;
    numm3 = num_m3;
    (*predic1) = predictor1;
    (*predic2) = predictor2;
    (*predic3) = predictor3;
    (*measure1) = measurement1;
    (*measure2) = measurement2;
    (*measure3) = measurement3;
    cam_associate( 1, nump1,numm1,predic1,measure1);
    cam_associate( 2, nump2,numm2,predic2,measure2);
    cam_associate( 3, nump3,numm3,predic3,measure3);
    
}

void associate::single_camera_checking(int cam,struct Node*measure,struct Node**res,int hypothesis_id){
    Node* res_New;
    switch(cam){
        case(1):{
                    if(numm1 > nump1){
                        check_hypothesis(cam,measure);
                    }
                    if(numm1 =< nump1){
                        check_occlusion(measure);
                        check_transform_cam(measure);
                    }
        }
        case(2):{
                    if(numm2 > nump2){
                        check_hypothesis(cam,measure);
                    }
                    if(numm2 =< nump2){
                        check_occlusion(measure);
                        check_transform_cam(measure);
                    }
        }
                    
        case(3):{
                    if(numm3 > nump3){
                        check_hypothesis(cam,measure);
                    }
                    if(numm3 =< nump3){
                        check_occlusion(measure);
                        check_transform_cam(measure);
                    }        
        }
    }
}


void associate::check_hypothesis(int cmr,struct Node* meas,bool* is_hypothesis, int id_dummy){
    switch(cmr){
        case(1):{
                *is_hypothesis=(accumulate_col1[meas->data_id]==0)
                break;}
        case(2):{
                *is_hypothesis=(accumulate_col2[meas->data_id]==0)
                break;}
        case(3):{
                *is_hypothesis=(accumulate_col3[meas->data_id]==0)
                break;}
        default:break;
    }
    if(is_hypothesis == true){
        meas->state = state_hipothetic;
        id_dummy = meas->data_id;
    }
}


void associate::init_multicamassoc(){
    int i;
    for(i=0;i<23;i++){
        accumulate_col1[i]=0;
        accumulate_col2[i]=0;
        accumulate_col3[i]=0;
        accumulate_row1[i]=0;
        accumulate_row2[i]=0;
        accumulate_row3[i]=0;
    }
}

void associate::update_arracc(){
    int i,j;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            accumulate_row1[i]=accumulate_row1[i]+association1p[i][j];
            accumulate_row2[i]=accumulate_row2[i]+association2p[i][j];
            accumulate_row3[i]=accumulate_row3[i]+association3p[i][j];
            accumulate_col1[j]=accumulate_col1[j]+association1p[i][j];
            accumulate_col2[j]=accumulate_col2[j]+association2p[i][j];
            accumulate_col3[j]=accumulate_col3[j]+association3p[i][j];
        }
    }
}

bool associate::Isemptyrow(struct Node* predict){
    switch(predict->cam){
        case(1):return(accumulate_row1[predict->data_id]==0);break;
        case(2):return(accumulate_row2[predict->data_id]==0);break;
        case(3):return(accumulate_row3[predict->data_id]==0);break;
    }
}

bool associate::Isonetoone(struct Node* predict){
    switch(predict->cam){
        case(1):return(accumulate_row1[predict->data_id]==1);break;
        case(2):return(accumulate_row2[predict->data_id]==1);break;
        case(3):return(accumulate_row3[predict->data_id]==1);break;
    }
}




void associate::IsNtoone(bool *Ntone,struct Node* measuree){
    int i,j;
    j=0;
    switch(measuree->cam){
        case(1):{
                    Ntone = (accumulate_col1[measuree->data_id]>1);
                    while((i<accumulate_col1[measuree->data_id])||(j<23)){
                        if(association1p[j][measuree->data_id]==1){
                            id_obj_occluded[i] = j;
                            i++;
                        }
                        j++;
                    }
                    break;}
        case(2):{
                    Ntone = (accumulate_col2[measuree->data_id]>1);
                    while((i<accumulate_col2[measuree->data_id])||(j<23)){
                        if(association2p[j][measuree->data_id]==1){
                            id_obj_occluded[i] = j;
                            i++;
                        }
                        j++;
                    }
                    break;}
        case(3):{
                    Ntone = (accumulate_col3[measuree->data_id]>1);
                    while((i<accumulate_col3[measuree->data_id])||(j<23)){
                        if(association3p[j][measuree->data_id]==1){
                            id_obj_occluded[i] = j;
                            i++;
                        }
                        j++;
                    }
                    break;}
    }
}


void associate::setting_id(Node* measuree){
    switch(measuree->cam){
        case(1):;break;
            
        case(2):;break;
        case(3):;break;
    
    
    }

}



int associate::FSM(int prev_state,bool Isinit,bool set_id,bool onetoN,bool Ntoone,bool onetoone,int flag,bool emptyrow){
    switch(prev_state){
        case(state_hipothetic):{
            if(set_id){
                return(state_Normal);
            }
            if(flag){
                return(state_pottrans);
            }
        break;
        }
        case(state_Normal):{
            if(flag!=0){
                return(state_pottrans);
            }
            if(Ntoone){
                return(state_group);
            }
            if(onetoone){
                return(state_Normal)
            }
            break;
        }
        case(state_pottrans):{
            if(onetoone){
                return(state_Normal);
            }
            if(emptyrow){
                return(state_camtrans);
            }
        break;
        }
        case(state_group):{
            if(onetoone){
                return(state_Normal);
            }
            if(Ntoone){
                return(state_group);
            };
            break;
        }
    }
}

void associate::cam_associate(int cam,int num_p,int num_m,struct Node *p,struct Node *m){
    int i,j;
    init_matrices_assoc();
    num_predictor = num_p;
    num_measurement = num_m;
    cameras = cam;
    listgen.copyLinkedList(p,&predictor);
    listgen.copyLinkedList(m,&measurement);
    if(ydl>yul && ydr>yur && xdr>xur && xdl<xur){
        yo =((xdr-xdl)/(((-xdl+xul)/(ydl-yul))+((xdr-xur)/(ydr-yur))))-((ydl+ydr)/2);
    }
    xo =(((((yo*(-xdl+xul))/(ydl-yul))+xdl)+(((yo*(xdr-xur))/(ydr-yur))+(xdr)))/2);
    link_theid(cameras);
}

void init_matrices_assoc(){
    int i,j;
    num_trans1 = 0;
    num_trans2 = 0;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            association1[i][j]= 0;
            association2[i][j]= 0;
            association3[i][j]= 0;
            association1p[i][j]= 0;
            association2p[i][j]= 0;
            association3p[i][j]= 0;
            association_globe[i][j]= 0;
        }
        accumulation_row    [i]=0;
        accumulation_column [i]=0;
        Isocclusion_valid   [i]=false;
    }
    for(i-0;i<3;i++){
        obj_cam[i]=0;
        meas_cam[i]=0;    
    }
}


associate::~associate(){

}


double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
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
void associate::link_theid(int cam){
    double Euclid_x;
    double Euclid_y;
    int i=0;int j = 0;
    int k = 0;
    double th_xka,th_xki,th_y;
    switch(cam){
     case(1):{
            while(i<num_measurement){
                while(j<num_predictor){
                    Euclid_x = predictor->val_x-measurement->val_x;
                    Euclid_y = abs(predictor->val_y-measurement->val_y);
                    find_threshold_x(&th_xka,&th_xki,measurement->val_y,measurement->val_x,predictor->val_y);
                    th_y=find_threshold_y(predictor->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, predictor->x_trans, predictor->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association1p[predictor->data_id][measurement->data_id] = 1;
                        }
                    }
                    if(euclid_r < threshold_glob){
                        association1[predictor->data_id][measurement->data_id] = 1;
                    }
                    predictor = predictor->next;
                    measurement = measurement->next;
                    j++;
                }
                i++;
            }
            break;
         }
     case(2):{
            while(i<num_measurement){
                while(j<num_predictor){
                    Euclid_x = predictor->val_x-measurement->val_x;
                    Euclid_y = abs(predictor->val_y-measurement->val_y);
                    find_threshold_x(&th_xka,&th_xki,measurement->val_y,measurement->val_x,predictor->val_y);
                    th_y=find_threshold_y(predictor->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, predictor->x_trans, predictor->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association2p[predictor->data_id][measurement->data_id] = 1;
                        }
                    }
                    if(euclid_r < threshold_glob){
                        association2[predictor->data_id][measurement->data_id] = 1;
                    }                    predictor = predictor->next;
                    measurement = measurement->next;
                    j++;
                }
                i++;
            }
            break;
         }
     case(3):{
            while(i<num_measurement){
                while(j<num_predictor){
                    Euclid_x = predictor->val_x-measurement->val_x;
                    Euclid_y = abs(predictor->val_y-measurement->val_y);
                    find_threshold_x(&th_xka,&th_xki,measurement->val_y,measurement->val_x,predictor->val_y);
                    th_y=find_threshold_y(predictor->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, predictor->x_trans, predictor->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association3p[predictor->data_id][measurement->data_id] = 1;
                        }
                    }
                    
                    if(euclid_r < threshold_glob){
                        association3[predictor->data_id][measurement->data_id] = 1;
                    }
                    predictor = predictor->next;
                    measurement = measurement->next;
                    j++;
                }
                i++;
            }
            break;
         }
    default:{;break;}
    }
}

double associate::eigen_distance(double x_measure, double x_obj, double y_measure, double y_obj){
    return(sqrt(((x_measure-x_obj)*(x_measure-x_obj))+((y_measure-y_obj)*(y_measure-y_obj))));
}



