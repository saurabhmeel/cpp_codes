#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

struct node{
    int x,y;
};

queue<node>q1;

void BFS(node t,Mat a){
    q1.push(t);
    while(!q1.empty()){
        
        node t1 = q1.front();
        a.at<uchar>(t.x,t.y) = 0;
        
        if(a.at<uchar>(t.x-1,t.y)==255 && store.at<uchar>(t.x-1,t.y)==0){
            temp.x = t.x -1;
            temp.y = t.y;
            q1.push(temp);
            store.at<uchar>(t.x,t.y)==255;
            store.at<uchar>(t.x-1,t.y)==255;
        }
        if(a.at<uchar>(t.x+1,t.y)==255 && store.at<uchar>(t.x-1,t.y)==0){
             temp.x = t.x+1;
             temp.y = t.y;
             q1.push(temp);
             store.at<uchar>(t.x,t.y)==255;
             store.at<uchar>(t.x+1,t.y)==255;
        }
        if(a.at<uchar>(t.x,t.y-1)==255 && store.at<uchar>(t.x-1,t.y)==0){
             temp.x = t.x;
             temp.y = t.y-1;
             q1.push(temp);
             store.at<uchar>(t.x,t.y)==255;
             store.at<uchar>(t.x,t.y-1)==255;
        }
        if(a.at<uchar>(t.x,t.y+1)==255 && store.at<uchar>(t.x-1,t.y)==0){
            temp.x = t.x;
            temp.y = t.y+1;
            q1.push(temp);
            store.at<uchar>(t.x,t.y)==255;
            store.at<uchar>(t.x,t.y+1)==255;
            
        }
        q1.pop();
        //count++;
    }

}

int main(){
    namedWindow("w1",WINDOW_NORMAL);
    Mat a = imread("Binary1.png",0);
    int l = a.rows;
    int b = a.cols;
    int count = 0;
    queue<struct node>q1;
    struct node t1;
    Mat store(l,b,CV_8UC1,Scalar(0));
    for(int i =0;i<l;i++){
        for(int j =0;j<b;j++){
            if(a.at<uchar>(i,j)>100){
                a.at<uchar>(i,j) = 255;
            }else{
                a.at<uchar>(i,j) = 0;
            }
        }
    }
    for(int i =0;i<l;i++){
        for(int j =0;j<b;j++){
            if(a.at<uchar>(i,j)==255 && store.at<uchar>(i,j)==0){
                t1.x = i;
                t1.y = j;
                q1.push(t1);
                BFS(q1,store,a,count);
                count++;
            }
        }
    }
    cout<<count;



}

