#include "ObjAssociate.h"

void Associate::init_multicamassoc(){
    int i;
    for(i=0;i<JUMLAH_PLAYER;i++){
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

Associate::Associate(){

}

Associate::~Associate(){

}


void Associate::updateMatCam1(Mat Cam1){
    inMatCam1 = Cam1.clone();
    Isset12 = true;
}
void Associate::updateMatCam2(Mat Cam2){
    inMatCam2 = Cam2.clone();
    Isset11 = true;
}
void Associate::updateMatCam3(Mat Cam3){
    inMatCam3 = Cam3.clone();
    Isset10 = true;
}
void Associate::updateMatTrans(Mat CamT){
    inMatCamT = CamT.clone();
    Isset9 = true;
}
void Associate::updateKalmanCam1(QList<DataInputCam> predicCam1){
    predic1 = predicCam1;
    sizePredict1 = predic1.length;
    Isset8 = true;
}
void Associate::updateKalmanCam2(QList<DataInputCam> predicCam2){
    predic2 = predicCam2;
    sizePredict2 = predic2.length;
    Isset7 = true;
}
void Associate::updateKalmanCam3(QList<DataInputCam> predicCam3){
    predic3 = predicCam3;
    sizePredict3 = predic3.length;
    Isset6 = true;
}
void Associate::updateKalmanTrans(QList<DataInputTrans> predicCamT){
    predicTrans = predicCamT;
    sizePredictT = predicTrans.length;
    Isset5 = true;
}
void Associate::updateCurrentCam1(QList<DataInputCam> currCam1){
    currcam1 = currCam1;
    sizeMeas1 = currcam1.length;
    Isset4 = true;
}
void Associate::updateCurrentCam2(QList<DataInputCam> currCam2){
    currcam2 = currCam2;
    sizeMeas2 = currCam2.length;
    Isset3 = true;
}
void Associate::updateCurrentCam3(QList<DataInputCam> currCam3){
    currcam3 = currCam3;
    sizeMeas3 = currcam3.length;
    Isset2 = true;
}
void Associate::updateCurrentTrans(QList<DataInputTrans> currCamT){
    currcamT = currCamT;
    sizeMeasT = currcamT.length;
    Isset1 = true;
}

void Associate::accum_assoc(bool Isinit,bool start_accum){
    int ntoone1=0,ntoone2=0,ntoone3=0,ousted=0,hypo=0,cntoone1=0,cntoone2=0,cntoone3=0;
    int f_1=0,f_2=0,f_3=0;
    int l_1=0,l_2=0,l_3=0;
    Inits = Isinit;    
    if(mulai){
        init_matrices_assoc();
        if(start_accum){
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
            Issetmat = sum_updated_mat();
            /**Tahapan terakhir dari assosiasi ialah mapping data measurement ke object yang terdefinisi**/
        }
        Ismapped = mapping();
    }
}




bool Associate::sum_updated_mat(){
    int i,j;
    association_globe = association1p + association2p + association3p;
}

void Associate::mapping(){
    int i,j;
    Node* getbuf;
    switch(cameras)
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){
            mapping_result = new Node;
            if(association_agrr[i][j]==1){
                getbuf = listgen.searchNode(measure,j);
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
            accumulate_row1[i]=accumulate_row1[i]+inMatCam1.at(i,j);
            accumulate_row2[i]=accumulate_row2[i]+inMatCam2.at(i,j);
            accumulate_row3[i]=accumulate_row3[i]+inMatCam3.at(i,j);
            accumulate_col1[j]=accumulate_col1[j]+inMatCam1.at(i,j);
            accumulate_col2[j]=accumulate_col2[j]+inMatCam1.at(i,j);
            accumulate_col3[j]=accumulate_col3[j]+inMatCam1.at(i,j);
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
                if(inMatCam1.at(k,j)==1){
                    id_obj_occluded1[i].x = (double)j;
                    id_obj_occluded1[i].y = (double)k;
                    i++;
                    }
                }
                n++;
            }
        if(accumulate_col2[j]>1){
            for(k=0;k<23;k++){
                if(inMatCam2.at(k,j)==1){
                    id_obj_occluded2[l].x = (double)j;
                    id_obj_occluded2[l].y = (double)k;
                    l++;
                    }
                }
            o++;
            }
        if(accumulate_col3[j]>1){
            for(k=0;k<23;k++){
                if(inMatCam3.at(k,j)==1){
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
    switch(camr){
        case(1):{
            i=0;
            while(i<sizePredict1){
                if(accumulate_row1[predic1.at(i).id]==0){
                    Potentially_out[j].x = 1.00;
                    Potentially_out[j].y = (double)predic1.at(i).id;
                    j++;
                }
                i++;
            }
            break;
        }
        case(2):{
            i=0;
            while(i<sizePredict2){
                if(accumulate_row1[predic2.at(i).id]==0){
                    Potentially_out[j].x = 2.00;
                    Potentially_out[j].y = (double)predic2.at(i).id;
                    j++;
                }
                i++;
            }
            break;
        }
        case(3):{
            i=0;
            while(i<sizePredict3){
                if(accumulate_row3[predic3.at(i).id]==0){
                    Potentially_out[j].x = 3.00;
                    Potentially_out[j].y = (double)predic3.at(i).id;
                    j++;
                }
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
    switch(camr){
        case(1):{
            i=0;
            while(i<sizeMeas1){
                if(accumulate_col1[measure1.at(i).id]==0){
                    hypothest[j].x = 1.00;
                    hypothest[j].y = measure1.at(i).id;
                    j++;
                }
                i++;
            }
            break;
        }
        case(2):{
            i=0;
            while(i<sizeMeas1){
                if(accumulate_col2[measure2.at(i).id]==0){
                    hypothest[j].x = 2.00;
                    hypothest[j].y = measure2.at(i).id;
                    j++;
                }
                i++;
            }
            break;
        }
        case(3):{
            i=0;
            while(i<sizeMeas3){
                if(accumulate_col3[measure3.at(i).id]==0){
                    hypothest[j].x = 3.00;
                    hypothest[j].y = measure3.at(i).id;
                    j++;
                }
                i++;
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


void Associate::init_matrices_assoc(){
    int i,j;

}


