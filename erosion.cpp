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
    Mat a = imread("erosion.png",0);
    Mat b = a.clone();
    for(int i=0;i<477;i++){
        for(int j =0;j<637;j++){
            if(a.at<uchar>(i+1,j)==0 ||a.at<uchar>(i+2,j)==0 ||a.at<uchar>(i,j+1)==0 ||a.at<uchar>(i,j+2)==0 ||a.at<uchar>(i+1,j+1)==0||a.at<uchar>(i+1,j+2)==0 ||a.at<uchar>(i+2,j+1)==0 ||a.at<uchar>(i+2,j+2)==0){
                b.at<uchar>(i,j) = 0;
            }
        }
    }
    imshow("w1",b);
    //imwrite("eroded.jpg",b);
    cvWaitKey(0);
}