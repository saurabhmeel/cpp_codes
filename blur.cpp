//hello
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
    Mat a = imread("lena.png",0);
    //Mat img(1000,1000,CV_8UC1,Scalar(0));
    Mat b = a.clone();
    for(int i =0;i<510;i++){
        for(int j = 0;j<510;j++){
            b.at<uchar>(i,j) = floor((a.at<uchar>(i,j)/16+a.at<uchar>(i+1,j+1)/4+a.at<uchar>(i+1,j)/8+a.at<uchar>(i+2,j)/16+a.at<uchar>(i,j+1)/8+a.at<uchar>(i,j+2)/16+a.at<uchar>(i+1,j+2)/8+a.at<uchar>(i+2,j+1)/8+a.at<uchar>(i+2,j+2)/16));
        }
    }
    /*Mat img = b.clone();
    for(int i =0;i<510;i++){
        for(int j = 0;j<510;j++){
            .at<uchar>(i,j) = floor((a.at<uchar>(i,j)/16+a.at<uchar>(i+1,j+1)/4+a.at<uchar>(i+1,j)/8+a.at<uchar>(i+2,j)/16+a.at<uchar>(i,j+1)/8+a.at<uchar>(i,j+2)/16+a.at<uchar>(i+1,j+2)/8+a.at<uchar>(i+2,j+1)/8+a.at<uchar>(i+2,j+2)/16));

        }
    }*/
    imshow("w1",b);
    cvWaitKey(0);
}
