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
    Mat img;
    namedWindow("w1",WINDOW_NORMAL);
    namedWindow("w2",WINDOW_NORMAL);

    /*int thrsmin = 10;
    int thrsmax = 25;
    int size = 2;*/
    /*createTrackbar("Threshhold_Min","w1",&thrsmin,100);
    createTrackbar("Threshhold_Max","w1",&thrsmax,100);
    createTrackbar("Size","w1",&size,10);*/
    /*thrsmax=150;
    thrsmin=50;
    size=3;*/
    while(1){
        cap>>img;
        Mat a(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
        for(int i =0;i<img.rows;i++){
            for (int j = 0;j<a.cols;j++){
                if(img.at<Vec3b>(i,j)[0]<50 && img.at<Vec3b>(i,j)[1]<50 && img.at<Vec3b>(i,j)[2]>200){
                    a.at<Vec3b>(i,j)[0]=255;
                    a.at<Vec3b>(i,j)[1]=255;
                    a.at<Vec3b>(i,j)[2]=255; 
                }
            }
        }
        // Canny(img,a,50,150,3);
        imshow("w2",img);
        imshow("w1",a);
        cvWaitKey(10);
    }

}