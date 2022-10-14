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
    Mat c = imread("veg.jpg",0);
    Mat b = c.clone();
    for(int i =0;i<255;i++){
        for(int j =0;j<255;j++){
            int a[9];
            /*for(int m=0;m<3;m++){
                for(int n=0;n<3;n++){
                    for(int k=0;k<9;k++){
                        a[k]= b.at<uchar>(i+m,j+n);
                    }
                }
            }*/
            a[0] = b.at<uchar>(i,j);
            a[1] = b.at<uchar>(i+1,j);
            a[2] = b.at<uchar>(i+2,j);
            a[3] = b.at<uchar>(i,j+1);
            a[4] = b.at<uchar>(i,j+2);
            a[5] = b.at<uchar>(i+1,j+1);
            a[6] = b.at<uchar>(i+1,j+2);
            a[7] = b.at<uchar>(i+2,j+1);
            a[8] = b.at<uchar>(i+2,j+2);
            sort(a,a+9);
            b.at<uchar>(i,j) = a[5];


            
            
        }
    }
    imshow("w1",b); //shows the image window
    cvWaitKey(0);
}
