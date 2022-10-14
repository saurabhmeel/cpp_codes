#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv; // to acess the opencv library

struct node{
    int x;
    int y;
};

queue<node>q;

void bfs (Mat img,node p){
    q.push(p);
   
    
    while(!q.empty()){
       node k= q.front();
        if(img.at<uchar>(k.x,k.y+1)==255){
            
            node temp;
            temp.x = k.x;
            temp.y = k.y+1;
            q.push(temp);
            img.at<uchar>(k.x,k.y)= 0;
            img.at<uchar>(temp.x,temp.y)=0;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<uchar>(k.x+1,k.y)==255){
            
            node temp;
            temp.x = k.x+1;
            temp.y = k.y;
            q.push(temp);
            img.at<uchar>(k.x,k.y)= 0;
            img.at<uchar>(temp.x,temp.y)=0;
           namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        
            //q.pop();
        }
        if(img.at<uchar>(k.x,k.y-1)==255){
            node temp;
            temp.x = k.x;
            temp.y = k.y-1;
            q.push(temp);            
            img.at<uchar>(k.x,k.y)= 0;
            img.at<uchar>(temp.x,temp.y)=0;
            
           namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);         
            
            //q.pop();
        }
        if(img.at<uchar>(k.x-1,k.y)==255){
            node temp;
            temp.x = k.x-1;
            temp.y = k.y;
            q.push(temp);
            img.at<uchar>(k.x,k.y)= 0;
            img.at<uchar>(temp.x,temp.y)=0;
          namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
         
            //q.pop();
        }
        q.pop();
    }

}

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat img = imread("binary3.jpg",0);
    int count = 0;
    //binarise image
    for(int i =0;i<img.rows;i++){
        for (int j= 0;j<img.cols;j++){
            if(img.at<uchar>(i,j)>127){
                img.at<uchar>(i,j) = 255;
            }else{
                img.at<uchar>(i,j) = 0;
            }
        }
    }
    node p1;
    for(int i =0;i<img.rows;i++){
        for (int j= 0;j<img.cols;j++){
            if(img.at<uchar>(i,j)==255){
                
                p1.x = i;
                p1.y = j;
                bfs(img,p1);
                count++;
        }
    }
    }
    cout<<count<<endl;
}
