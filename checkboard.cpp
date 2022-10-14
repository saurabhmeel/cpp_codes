#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"     //prints a checkboard
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	namedWindow("w1",WINDOW_NORMAL);
	Mat img(8,8,CV_8UC1,Scalar(0));
	//nested for loops
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i%2==0 && j%2!=0)
			img.at<CV_8UC1>(i,j) = 255;
		}
	}
	cvWaitKey(0);
	return 0;
}
