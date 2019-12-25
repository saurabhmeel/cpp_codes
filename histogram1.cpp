#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("highcontrast.PNG",0);
    int max;
    int count[256] = {0};
    
    for(int i=0;i<a.rows;i++){
        for(int j =0;j<a.cols;j++){
            for(int k =0;k<256;k++){
                if(a.at<uchar>(i,j)==k){
                    count[k]++;
                }
            }
        }
    }
    
    int temp[256];
    for(int b =0;b<256;b++){
        temp[b]=count[b];
    }
    sort(temp,temp+256);
    /*for(int i= 0;i<256;i++){
        cout<<temp[i]<<endl;
    }*/
    
    max = temp[255];
    //cout<<max;
    Mat img(256,max,CV_8UC1,Scalar(0));
    for(int i = 0;i<256;i++){
        for(int j =0;j<count[i];j++){
            img.at<uchar>(i,j) = 255;
        }
    }
    imshow("w1",img);
    cvWaitKey(0);

}