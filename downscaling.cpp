#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

int main(){
    cvNamedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("cube.jpg",1);
    Mat img(500,500,CV_8UC3,Scalar(0,0,0));
    for(int i =0;i<500;i++){
        for(int j =0;j<500;j++){
            img.at<Vec3b>(i,j)[0] = a.at<Vec3b>(2*i,2*j)[0];
            img.at<Vec3b>(i,j)[1] = a.at<Vec3b>(2*i,2*j)[1];
            img.at<Vec3b>(i,j)[2] = a.at<Vec3b>(2*i,2*j)[2];
        }
    }
    imshow("w1",img);
    cout<<img.rows<<" "<<img.cols;
    imwrite("smallcube.jpg",img);
    cvWaitKey(0);
}