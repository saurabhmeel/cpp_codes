#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("cube.jpg",0);
    Mat b = a.clone();
    Mat c = a.clone();
    Mat img(1000,1000,CV_8UC1,Scalar(0));
    int thrsX = 0;
    int thrsY = 0;
    createTrackbar("Threshhold_X","w1",&thrsX,255);
    createTrackbar("Threshhold_Y","w1",&thrsY,255);
    while(1){
        for(int i =0;i<997;i++){
            for(int j=0;j<997;j++){
                if((a.at<uchar>(i,j)*(-1)+a.at<uchar>(i+1,j)*(0)+a.at<uchar>(i+2,j)*(1)+a.at<uchar>(i,j+1)*(-2)+a.at<uchar>(i+1,j+1)*(0)+a.at<uchar>(i+2,j+1)*(2)+a.at<uchar>(i,j+2)*(-1)+a.at<uchar>(i+1,j+2)*(0)+a.at<uchar>(i+2,j+2)*(1))>thrsX){
                    b.at<uchar>(i+1,j+1) = 255;
                }else{
                    b.at<uchar>(i+1,j+1) = 0;
                }
            }
        }
        for(int i =0;i<997;i++){
            for(int j=0;j<997;j++){
                if((a.at<uchar>(i,j)*(1)+a.at<uchar>(i+1,j)*(2)+a.at<uchar>(i+2,j)*(1)+a.at<uchar>(i,j+1)*(0)+a.at<uchar>(i+1,j+1)*(0)+a.at<uchar>(i+2,j+1)*(0)+a.at<uchar>(i,j+2)*(-1)+a.at<uchar>(i+1,j+2)*(-2)+a.at<uchar>(i+2,j+2)*(-1))>thrsY){
                    c.at<uchar>(i+1,j+1) = 255;
                }else{
                    c.at<uchar>(i+1,j+1) = 0;
                }
            }
        }
        for(int i =0;i<1000;i++){
            for(int j=0;j<1000;j++){
                img.at<uchar>(i,j) = b.at<uchar>(i,j) + c.at<uchar>(i,j);
            }
        }
        imshow("w1",img);
		cvWaitKey(10);
    }
}