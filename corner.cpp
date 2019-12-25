#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

int main(){
    Mat img = imread("Binary1.png",0);
    //Mat dst = Mat::zeros( img.size(), CV_32FC1 );
    Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
    cornerHarris(img,a,2,3,0.04);
    imshow("w1",a);
    cvWaitKey(0);
}