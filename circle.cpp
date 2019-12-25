#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat img(1000,1000,CV_8UC1,Scalar(0));
    img.at<Vec3b>(500,500) = 255;
    for (int i =0;i<1000;i++){
        for (int j=0;j<1000;j++){
            if((500-i)*(500-i) + (500-j)*(500-j)-20000<1){
                img.at<uchar>(i,j)=255;
            }
            if((250-i)*(250-i) + (500-j)*(500-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
            if((750-i)*(750-i) + (500-j)*(500-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
            if((500-i)*(500-i) + (250-j)*(250-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
            if((500-i)*(500-i) + (750-j)*(750-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
            if((250-i)*(250-i) + (250-j)*(250-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
            if((750-i)*(750-i) + (750-j)*(750-j)-5000<1){
                img.at<uchar>(i,j)=255;
            }
        }
    }
    imshow("w1",img);
    imwrite("obstacle.jpg",img);
    cvWaitKey(0);
    return 0;
}
