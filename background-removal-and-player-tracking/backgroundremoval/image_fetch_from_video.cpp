#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <omp.h>
#include <stdio.h>

using namespace std;
using namespace cv;


int main(){
    VideoCapture cap("realmadrid.mp4");
    if(!cap.isOpened()){
        return -1;
    }

    cap.set(CV_CAP_PROP_POS_MSEC, 786000);

    Mat frame;
    int counter = 0;
    char buffer[200];
    for(counter = 0; counter < 1000; counter++){
        cap >> frame;

        int k = waitKey(30);
        if(k > 0){
            if(k == 27 || frame.empty()){
                break;
            }
        }

        sprintf(buffer, "/home/hammas/code/ta/background-removal-and-player-tracking/backgroundremoval/images/%d.jpeg",counter);
        imwrite(buffer, frame);
        //imshow("frames", frame);

    }
    cap.release();
    return 0;
}

