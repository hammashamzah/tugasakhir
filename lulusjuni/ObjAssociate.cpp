#include "ObjAssociate.h"

void Associate::init_multicamassoc(){
    int i;
    for(i=0;i<23;i++){
        accumulate_col1[i]      =0;
        accumulate_col2[i]      =0;
        accumulate_col3[i]      =0;
        accumulate_row1[i]      =0;
        accumulate_row2[i]      =0;
        accumulate_row3[i]      =0;
        id_obj_occluded1[i].x   =0;
        id_obj_occluded1[i].y   =0;
        id_obj_occluded2[i].x   =0;
        id_obj_occluded2[i].y   =0;
        id_obj_occluded3[i].x   =0;
        id_obj_occluded3[i].y   =0;
        hypothest[i].x          =0;
        hypothest[i].y          =0;
        Potentially_out[i].x    =0;
        Potentially_out[i].y    =0;
    }
}

Associate::Associate(bool start,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th){
    mulai = start;
    XDL = xdl;
    XDR = xdr;
    XUL = xul;
    XUR = xur;
    YDL = ydl;
    YDR = ydr;
    YUL = yul;
    YUR = yur;
    THETA = pixel_th;
}

Associate::~Associate(){

}


void Associate::accum_assoc(bool Isinit,struct Node* predictor1,struct Node* predictor2,struct Node* predictor3,struct Node* measurement1,struct Node* measurement2,struct Node* measurement3,int num_p1,int num_p2,int num_p3,int num_m1,int num_m2,int num_m3){
    int ntoone1=0,ntoone2=0,ntoone3=0,ousted=0,hypo=0,cntoone1=0,cntoone2=0,cntoone3=0,validate=0;
    int f_1=0,f_2=0,f_3=0;
    int l_1=0,l_2=0,l_3=0;
    Inits = Isinit;    
    if(mulai){
        nump1 = num_p1;
        nump2 = num_p2;
        nump3 = num_p3;
        numm1 = num_m1;
        numm2 = num_m2;
        numm3 = num_m3;
        predic1 = predictor1;
        predic2 = predictor2;
        predic3 = predictor3;
        measure1 = measurement1;
        measure2 = measurement2;
        measure3 = measurement3;
        init_matrices_assoc();
        cam_associate( 1, nump1,numm1,predic1,measure1);
        cam_associate( 2, nump2,numm2,predic2,measure2);
        cam_associate( 3, nump3,numm3,predic3,measure3);
        /**Membuat array jumlah collumn dan row untuk melakukan pengecekan N-> 1, 1-> 1, camera transition**/    
        update_arracc();
        /**melakukan pencacahan kejadian**/
        /**untuk sementara tidak ada feedback jika jumlah validate lebih besar dari 23 atau kurang dari 23**/
        /**Jadi asumsi validate selalu sama dengan 23**/
        /*for N->1 assoc*/
        set_Ntoone(ntoone1,ntoone2,ntoone3,cntoone1,cntoone2,cntoone3);
        /*menghandle predicted id yang keluar dari kamera*/
        pot_ousted(0,1,l_1);
        pot_ousted(l_1,2,l_2);
        pot_ousted(l_2,3,l_3);
        /*menghandle id yang baru masuk ke kamera*/
        update_hypothesis(0,1,f_1);
        update_hypothesis(f_1,2,f_2);
        update_hypothesis(f_2,3,f_3);
        validate = (nump1+nump2+nump3)-(ousted)+(hypo)+(ntoone1+ntoone2+ntoone3)-(cntoone1+cntoone2+cntoone3);
        /**melakukan assosiasi array yang terbentuk pada hypothesis terhadap id yang hilang pada salah satu kamera**/
        /**Setelah kondisi ini ketiga assosiacion matrices telah menghandle masalah camera transition**/
        associate_losthyp(l_3,f_3);
        /**Membentuk matrik assosiasi agregat dari ketiga kamera ini yang digunakan untuk mapping**/
        sum_updated_mat();
        
        /**Tahapan terakhir dari assosiasi ialah mapping data measurement ke object yang terdefinisi**/
        mapping();
    }
}




void Associate::sum_updated_mat(){
    int i,j;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            association_agrr[i][j] = association1p[i][j]+association2p[i][j]+association3p[i][j];
        }
    }
}

void Associate::mapping(){
    int i,j;
    Node* getbuf;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            mapping_result = new Node;
            if(association_agrr[i][j]==1){
                getbuf = listgen.searchNode(measure1,j);
                mapping_result->data_id = i;
                mapping_result->val_x = getbuf->val_x;
                mapping_result->val_y = getbuf->val_y;
                mapping_result->x_trans = getbuf->x_trans;
                mapping_result->y_trans = getbuf->y_trans;
                mapping_result->vx_trans = getbuf->vx_trans;
                mapping_result->vy_trans = getbuf->vy_trans;
                mapping_result->camera = getbuf->camera;
                mapping_result->next = getbuf->next;
            }
        }
    
    }
}

void Associate::associate_losthyp(int number_lost,int number_found){
    int i,j;
    for(i=0;i<number_lost;i++){
        for(j=0;j<number_found;j++){
            if(association_globe[(int)Potentially_out[i].y][(int)hypothest[j].y]==1){
                if(hypothest[j].x==1.00){
                    association1p[(int)Potentially_out[i].y][(int)hypothest[j].y]=1;
                }
                else if(hypothest[j].x==2.00){
                    association2p[(int)Potentially_out[i].y][(int)hypothest[j].y]=1;                        
                }
                else if(hypothest[j].x==3.00){
                    association3p[(int)Potentially_out[i].y][(int)hypothest[j].y]=1;
                }
            }
        }
    }
}

void Associate::update_arracc(){
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

void Associate::set_Ntoone(int &occ1,int &occ2,int &occ3,int &clus_occ1,int &clus_occ2,int &clus_occ3){
    int i,j,k,l,m,n,o,p;
    i=0;l=0;m=0;
    n =0;o=0;p=0;
    while(j<23){
        if(accumulate_col1[j]>1){
            for(k=0;k<23;k++){
                if(association1p[k][j]==1){
                    id_obj_occluded1[i].x = (double)j;
                    id_obj_occluded1[i].y = (double)k;
                    i++;
                    }
                }
                n++;
            }
        if(accumulate_col2[j]>1){
            for(k=0;k<23;k++){
                if(association2p[k][j]==1){
                    id_obj_occluded2[l].x = (double)j;
                    id_obj_occluded2[l].y = (double)k;
                    l++;
                    }
                }
            o++;
            }
        if(accumulate_col3[j]>1){
            for(k=0;k<23;k++){
                if(association3p[k][j]==1){
                    id_obj_occluded3[m].x = (double)j;
                    id_obj_occluded3[m].y = (double)k;
                    m++;
                    }
                }
            p++;
        }
    j++;            
    }
    occ1 = i;
    occ2 = l;
    occ3 = m;
    clus_occ1 = n;
    clus_occ2 = o;
    clus_occ3 = p;
}

void Associate::pot_ousted(int init,int camr,int &fin){
    int i =0;
    int j =init;
    Node* curr1 = predic1;
    Node* curr2 = predic2;
    Node* curr3 = predic3;
    switch(camr){
        case(1):{
            while(i<nump1){
                if(accumulate_row1[curr1->data_id]==0){
                    Potentially_out[j].x = 1.00;
                    Potentially_out[j].y = (double)curr1->data_id;
                    j++;
                }
                curr1 = curr1->next;
                i++;
            }
            break;
        }
        case(2):{
            while(i<nump2){
                if(accumulate_row1[curr2->data_id]==0){
                    Potentially_out[j].x = 2.00;
                    Potentially_out[j].y = (double)curr2->data_id;
                    j++;
                }
                curr2 = curr2->next;
                i++;
            }
            break;
        }
        case(3):{
            while(i<nump3){
                if(accumulate_row3[curr3->data_id]==0){
                    Potentially_out[j].x = 3.00;
                    Potentially_out[j].y = (double)curr3->data_id;
                    j++;
                }
                curr3 = curr3->next;
                i++;
            }
            break;
        }
        default:break;
    }
    fin = j;
}



void Associate::update_hypothesis(int init,int camr,int &fin){
    int i=0;
    int j=init;
    Node* meas1 = measure1;
    Node* meas2 = measure2;
    Node* meas3 = measure3;
    switch(camr){
        case(1):{
            while(i<numm1){
                if(accumulate_col1[meas1->data_id]==0){
                    hypothest[j].x = 1.00;
                    hypothest[j].y = meas1->data_id; 
                j++;
                }
            i++;
            meas1 = meas1->next;
            }
            break;
        }
        case(2):{
            while(i<numm2){
                if(accumulate_col2[meas2->data_id]==0){
                    hypothest[j].x = 2.00;
                    hypothest[j].y = meas2->data_id; 
                j++;
                }
            i++;
            meas2 = meas2->next;
            }
            break;
        }
        case(3):{
            while(i<numm3){
                if(accumulate_col3[meas3->data_id]==0){
                    hypothest[j].x = 3.00;
                    hypothest[j].y = meas3->data_id; 
                j++;
                }
            i++;
            meas3 = meas3->next;
            }
            break;
        }
        default:break;
    }
    fin = j;
}


/**FSM ini dibuat hanya untuk algoritma yang masih dalam pengembangan jadi sampai sekarang masih belum diperlukan**

int Associate::FSM(int prev_state,bool Isinit,bool set_id,bool onetoN,bool Ntoone,bool onetoone,int flag,bool emptyrow){
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
                return(state_Normal);
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

*****************************************************************************************************************************************/

void Associate::cam_associate(int cam,int num_p,int num_m,struct Node *p,struct Node *m){
    num_predictor = num_p;
    num_measurement = num_m;
    cameras = cam;
    listgen.copyLinkedList(p,&predictor);
    listgen.copyLinkedList(m,&measurement);
    
    if(YDL>YUL && YDR>YUR && XDR>XUR && XDL<XUR){
        yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
    }
    xo =(((((yo*(-XDL+XUL))/(YDL-YUL))+XDL)+(((yo*(XDR-XUR))/(YDR-YUR))+(XDR)))/2);
    link_theid(cameras);
}

void Associate::init_matrices_assoc(){
    int i,j;
    num_trans1 = 0;
    num_trans2 = 0;
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            association1p[i][j]= 0;
            association2p[i][j]= 0;
            association3p[i][j]= 0;
            association_globe[i][j]= 0;
            association_agrr[i][j]=0;
        }
    }
    for(i=0;i<23;i++){
        obj_cam[i]=0;
        meas_cam[i]=0;    
    }
}


double Associate::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}


double Associate::threshold_coef(double y){
    double threshold_k;
    double konst = (YDL+YDR)/2;
    if(y!=konst){
        threshold_k  = ((y-yo)/(y-konst));
    }
    return (threshold_k);
}

void Associate::find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m){
    double k = threshold_coef(y);
    double th = k*THETA;
    if(y > yo){
        x_kanan = x+(th/2)-(((x-xo)/(y-yo))*(y_m-y));
        x_kiri = x-(th/2)-(((x-xo)/(y-yo))*(y_m-y));
    }
}

double Associate::find_threshold_y(double y){
    double k = threshold_coef(y);
    double th = k*THETA;
    return th/2;
}

/**Hungarian Algorithms**/
void Associate::link_theid(int cam){
    double Euclid_x;
    double Euclid_y;
    int i=0, j = 0;
    double th_xka,th_xki,th_y;
    switch(cam){
     case(1):{
            while(i<num_measurement){
                Node* buffer = new Node;
                listgen.copyLinkedList(predictor,&buffer);
                while(j<num_predictor && buffer->next != NULL){
                    Euclid_x = buffer->val_x-measurement->val_x;
                    Euclid_y = abs(buffer->val_y-measurement->val_y);
                    find_threshold_x(th_xka,th_xki,measurement->val_y,measurement->val_x,buffer->val_y);
                    th_y=find_threshold_y(buffer->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, buffer->x_trans, buffer->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association1p[buffer->data_id][measurement->data_id] = 1;
                        }
                    }
                    if(euclid_r < threshold_glob){
                        association_globe[buffer->data_id][measurement->data_id] = 1;
                    }
                    buffer = buffer->next;
                    j++;
                }
                listgen.deleteLinkedList(&buffer);
                measurement = measurement->next;
                i++;
            }
            break;
         }
     case(2):{
            while(i<num_measurement){
                Node* buffer = new Node;
                listgen.copyLinkedList(predictor,&buffer);
                while(j<num_predictor&& buffer->next != NULL){
                    Euclid_x = buffer->val_x-measurement->val_x;
                    Euclid_y = abs(buffer->val_y-measurement->val_y);
                    find_threshold_x(th_xka,th_xki,measurement->val_y,measurement->val_x,buffer->val_y);
                    th_y=find_threshold_y(predictor->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, buffer->x_trans, buffer->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association2p[buffer->data_id][measurement->data_id] = 1;
                        }
                    }
                    if(euclid_r < threshold_glob){
                        association_globe[buffer->data_id][measurement->data_id] = 1;
                    }                    
                    buffer = buffer->next;
                    j++;
                }
                listgen.deleteLinkedList(&buffer);
                measurement = measurement->next;
                i++;
            }
            break;
         }
     case(3):{
            while(i<num_measurement){
                Node* buffer = new Node;
                listgen.copyLinkedList(predictor,&buffer);
                while(j<num_predictor&& buffer->next != NULL){
                    Euclid_x = buffer->val_x-measurement->val_x;
                    Euclid_y = abs(predictor->val_y-measurement->val_y);
                    find_threshold_x(th_xka,th_xki,measurement->val_y,measurement->val_x,buffer->val_y);
                    th_y=find_threshold_y(predictor->val_y);
                    double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, buffer->x_trans, buffer->y_trans);
                    if(Euclid_y < th_y){
                        if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                            association3p[buffer->data_id][measurement->data_id] = 1;
                        }
                    }
                    
                    if(euclid_r < threshold_glob){
                        association_globe[buffer->data_id][measurement->data_id] = 1;
                    }
                    buffer = buffer->next;
                    j++;
                }
                listgen.deleteLinkedList(&buffer);
                measurement = measurement->next;
                i++;
            }
            break;
         }
    default:break;
    }
}



