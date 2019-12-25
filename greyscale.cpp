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
    Mat b = a.clone();
    int x = a.rows;
    int y = a.cols;
    for(int i =0;i<x;i++){
        for(int j=0;j<y;j++){
            b.at<Vec3b>(i,j)[0]= floor(0.114*b.at<Vec3b>(i,j)[0]+0.587*b.at<Vec3b>(i,j)[1]+0.299*b.at<Vec3b>(i,j)[2]);
            b.at<Vec3b>(i,j)[1]= floor(0.114*b.at<Vec3b>(i,j)[0]+0.587*b.at<Vec3b>(i,j)[1]+0.299*b.at<Vec3b>(i,j)[2]);
            b.at<Vec3b>(i,j)[2]= floor(0.114*b.at<Vec3b>(i,j)[0]+0.587*b.at<Vec3b>(i,j)[1]+0.299*b.at<Vec3b>(i,j)[2]);

        }
    }
    imshow("w1",b);
    //imwrite("greyscale.jpg",b);
    cvWaitKey(0);
}