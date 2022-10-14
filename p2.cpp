
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	namedWindow("w1",WINDOW_NORMAL);
	Mat a = imread("joker.jpg",0); //reads the image from path location
	int x = a.rows;
	int y = a.cols;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			a.at<uchar>(i,j)=a.at<uchar>(x-i,j);
			}
	}	
	imshow("w1",a);
	cvWaitKey(0);
	return 0;
}
