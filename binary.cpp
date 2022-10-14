#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	namedWindow("w1",WINDOW_NORMAL);
	Mat a = imread("fruits.png",1);
	Mat b = a.clone();
	int Red_Min = 0;
	int Red_Max = 0;   
	int Green_Min = 0;
	int Green_Max = 0;
	int Blue_Min = 0;
	int Blue_Max = 0;
	createTrackbar("Red_Min","w1",&Red_Min,255);
	createTrackbar("Red_Max","w1",&Red_Max,255);
	createTrackbar("Green_Min","w1",&Green_Min,255);
	createTrackbar("Green_Max","w1",&Green_Max,255);
	createTrackbar("Blue_Min","w1",&Blue_Min,255);
	createTrackbar("Blue_Max","w1",&Blue_Max,255);
	while(1){
		for(int i=0;i<a.rows;i++){
			for(int j=0;j<a.cols;j++){
				if(a.at<Vec3b>(i,j)[0] >Blue_Min & a.at<Vec3b>(i,j)[0] <Blue_Max & a.at<Vec3b>(i,j)[1] >Green_Min & a.at<Vec3b>(i,j)[1] <Green_Max&& a.at<Vec3b>(i,j)[2] >Red_Min &
     a.at<Vec3b>(i,j)[2] <Red_Max ){
					b.at<Vec3b>(i,j)[0] = 255;
					b.at<Vec3b>(i,j)[1] = 255;
					b.at<Vec3b>(i,j)[2] = 255;
									}else{
					b.at<Vec3b>(i,j)[0] = 0;
					b.at<Vec3b>(i,j)[1] = 0;
					b.at<Vec3b>(i,j)[2] = 0;
					
				}
			}
		}
		
		imshow("w1",b); // to show image window
		cvWaitKey(10);	
	}
	
}	
