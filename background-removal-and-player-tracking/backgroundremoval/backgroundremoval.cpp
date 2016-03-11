//opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
//C
#include <stdio.h>
//C++
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

//function declaration
void mask(Mat img);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);

//global variables
Mat frame; //current frame
Mat fgMaskMOG; //fg mask generated by MOG method
//Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
//Ptr<BackgroundSubtractor> pMOG; //MOG Background subtractor
int keyboard;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
vector<KeyPoint> keypoints;


int main(int argc, char* argv[])
{
    //create GUI windows
    namedWindow("Frame");
    //namedWindow("FG Mask MOG");
    namedWindow("FG Mask MOG 2");

    setMouseCallback("Frame", CallBackFunc, NULL);


    SimpleBlobDetector::Params params;
    params.filterByArea = true;
    params.filterByInertia = false;
    params.filterByConvexity = false;
    params.filterByColor = false;
    params.filterByCircularity = false;
    params.minArea = 200;
    //params.maxArea = 40000;
    SimpleBlobDetector blob_detector(params);

    //make morphology element
    Mat element = getStructuringElement(2, Size(3,3), Point(2,2));

    //create Background Subtractor objects
   //NOTE HERE!!!!
    //pMOG= new BackgroundSubtractorMOG(); //MOG approach
    pMOG2 = new BackgroundSubtractorMOG2(); //MOG2 approach

    //create the capture object
    VideoCapture capture("/media/data/dev/code/tugasakhir/background-removal-and-player-tracking/backgroundremoval/videoTA.mp4");
    if(!capture.isOpened()){
        //error in opening the video input
        cerr << "Unable to open video file: " << endl;
        exit(EXIT_FAILURE);
    }else{
        double fps = capture.get(CV_CAP_PROP_FPS);
        cout << "fps:" << fps << "\n";
    }
    //read input data. ESC or 'q' for quitting

    while( (char)keyboard != 'q' && (char)keyboard != 27 ){
        //read the current frame
        if(!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }

        mask(frame);
        //update the background model
        //AND HERE!!!
        //pMOG->operator()(frame, fgMaskMOG);
        pMOG2->operator()(frame, fgMaskMOG);
        //get the frame number and write it on the current frame

        //morphology operation to make object more crisp - opening operation
        morphologyEx(fgMaskMOG, fgMaskMOG, 2, element);
        GaussianBlur(fgMaskMOG, fgMaskMOG, Size(3,3), 0, BORDER_DEFAULT );

        //inverse image
        //cv::threshold(fgMaskMOG, fgMaskMOG, 70, 255, CV_THRESH_BINARY);

        findContours(fgMaskMOG, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

        vector<Rect>boundRect(contours.size());

        for (int i = 0; i < contours.size(); i++)
        {
            boundRect[i] = boundingRect(contours[i]);
        }

        for (int i = 0; i < contours.size(); i++)
        {
            rectangle(fgMaskMOG, boundRect[i].tl(), boundRect[i].br(), Scalar(255,255,255), 2, 8, 0) ;
        }

        drawKeypoints(fgMaskMOG, keypoints, fgMaskMOG, Scalar(255,255,255), DrawMatchesFlags::DEFAULT);

        for(int i = 0; i < keypoints.size(); i++){
            cout << keypoints[i].class_id << " " << keypoints[i].pt.x << " " << keypoints[i].pt.y << "\n";
        }


        stringstream ss;
        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
            cv::Scalar(255,255,255), -1);
        ss << capture.get(CV_CAP_PROP_POS_FRAMES);

        string frameNumberString = ss.str();

        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
            FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));


        //show the current frame and the fg masks
        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG);
        //imshow("FG Mask MOG 2", fgMaskMOG2);
        //get the input from the keyboard
        keyboard = waitKey( 30 );
    }
    //delete capture object
    capture.release();

    //destroy GUI windows
    destroyAllWindows();
    return EXIT_SUCCESS;
}

void mask(Mat img){
    int lineType = 8;

    /*Create some point for mask */
    Point mask_point[1][5];
    mask_point[0][0] = Point(0.0,  0.0);
    mask_point[0][1] = Point(0.0, 400.0);
    mask_point[0][2] = Point(734.0, 400.0);
    mask_point[0][3] = Point(1280.0,664.0);
    mask_point[0][4] = Point(1280.0,0.0);
    const Point * ppt[1] = {mask_point[0]};
    int npt[] = {5};

    fillPoly(img, ppt, npt, 1, Scalar(0,0,0), lineType);
}


void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
}

