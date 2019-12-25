//define matrix of 100x100 with right diagonal upper half white and lower half black
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat img(100,100,CV_8UC1,Scalar(0));
        for(int i = 0;i<100;i++){
		for(int j = 0;j<100;j++){
			if(i<=j){
				img.at<uchar>(i,j) = 255;
				}
			}
		}
	namedWindow("w1",WINDOW_NORMAL);
	imshow("w1",img);
	cvWaitKey(0);
	return 0;
}
