#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

int main(){
    cvNamedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("smallcube.jpg",1);
    Mat img(1000,1000,CV_8UC3,Scalar(0,0,0));
    
}