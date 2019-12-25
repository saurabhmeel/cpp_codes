#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("joker.jpg",1);
    int x = a.rows;
	int y = a.cols;
    Mat b(y,x,CV_8UC3,Scalar(0,0,0));
    for(int i =0;i<x;i++){
        for(int j=0;j<y;j++){
			b.at<Vec3b>(j,x-i)[0] = a.at<Vec3b>(i,j)[0];
            b.at<Vec3b>(j,x-i)[1] = a.at<Vec3b>(i,j)[1];
            b.at<Vec3b>(j,x-i)[2] = a.at<Vec3b>(i,j)[2];    
        }
    }
    imshow("w1",b);
    cvWaitKey(0);
    return 0;
}
	
