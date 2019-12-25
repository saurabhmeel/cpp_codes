#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("A3.png",0);
    int l = a.rows;
    int k = a.cols;
    int m = floor(sqrt(l*l+k*k));
    Mat img(361,m,CV_8UC1,Scalar(0));
    Mat out(l,k,CV_8UC1,Scalar(0));
    for(int i =0;i<a.rows;i++){
        for(int j = 0;j<a.cols;j++){
            if(a.at<uchar>(i,j)==255){
                for(int t=0;t<361;t++){
                    int r = floor(i*cos(t*3.14/180)+j*sin(t*3.14/180));
                    if(r>=0){
                        img.at<uchar>(t,abs(r))++;
                    }    
                        
                }
            }
        }
    }

    for(int i =0;i<361;i++){
        for(int j = 0;j<m;j++){
                if(img.at<uchar>(i,j)>80){
                    Point p1,p2;
                    int x1 =80;
                    int x2 =800;
                    int y1=(j-x1*(cos(i*3.14/180)))/sin(i*3.14/180);
                    int y2=(j-x2*(cos(i*3.14/180)))/sin(i*3.14/180);
                    p1.x = x1;
                    p1.y = y1;
                    p2.x = x2;
                    p2.y = y2;
                    line(out,p1,p2,Scalar(255),3,CV_AA);
                }
            
        }
    }
    imshow("w1",out);
    cvWaitKey(0);
}