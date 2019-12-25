#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("fruits.png",1);
    double x = a.rows;
    double y = a.cols;
    double t = 0.5;
    int r = floor(sqrt(x*x+y*y));
    Mat img(2*r,2*r,CV_8UC3,Scalar(0,0,0));
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){

            img.at<Vec3b>(floor(x/2)+floor(i*cos(t)+j*sin(t)),floor(y/2)+floor(i*cos(t)-j*sin(t)))[0] = a.at<Vec3b>(i,j)[0];
            img.at<Vec3b>(floor(x/2)+floor(i*cos(t)+j*sin(t)),floor(y/2)+floor(i*cos(t)-j*sin(t)))[1] = a.at<Vec3b>(i,j)[1];
            img.at<Vec3b>(floor(x/2)+floor(i*cos(t)+j*sin(t)),floor(y/2)+floor(i*cos(t)-j*sin(t)))[2] = a.at<Vec3b>(i,j)[2];
        }
    }
    imshow("w1",img);
    
    cvWaitKey(0);

}