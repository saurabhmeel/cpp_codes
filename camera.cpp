#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

int main(int,char**){
    VideoCapture cap(0);
    /*if(cap.isOpened()==true){
        return -1;
    }*/
    Mat img;
    Mat img1;
    namedWindow("w1",WINDOW_NORMAL);
    int thrsmin = 10;
    int thrsmax = 25;
    int size = 2;
    /*createTrackbar("Threshhold_Min","w1",&thrsmin,100);
    createTrackbar("Threshhold_Max","w1",&thrsmax,100);
    createTrackbar("Size","w1",&size,10);*/
    thrsmax=150;
    thrsmin=50;
    size=3;
    while(1){
        cap>>img; //loop to capture image
        //Canny(img,img1,50,150,3); exprimentation with edge detection
        imshow("w1",img);
        cvWaitKey(10);
    }

}
