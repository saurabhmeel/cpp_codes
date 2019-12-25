#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("joker.jpg",0);
    Mat b = a.clone();
	int x = a.rows;
	int y = a.cols;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			b.at<uchar>(i,j)=a.at<uchar>(x-i,j);
			}
	}	
	imshow("w1",b);
	cvWaitKey(0);
	return 0;
}