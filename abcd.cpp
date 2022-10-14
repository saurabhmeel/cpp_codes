#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
//hello
using namespace std;
using namespace cv;

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat img = imread("red.jpg",1);
    int a,b,c;
    a = img.at<Vec3b>(200,200)[0];
    b = img.at<Vec3b>(200,200)[1];
    c = img.at<Vec3b>(200,200)[2];
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    imshow("w1",img);
    cvWaitKey(0);
}
