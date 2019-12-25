#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

struct node{
    int x;     //current pixel x coordinate
    int y;      //current pixel y coordinate
    int x1;     //parent x
    int y1;      // parent y
    int cost;       //cost from 0,0
};

queue<node>q;

void djk (Mat img){
    node origin;
    origin.x = 1;;
    origin.y = 1;
    origin.x1 = 1;
    origin.y1 = 1;
    node temp01;
    node temp02;
    node temp10;
    node temp20;
    node temp11;
    node temp12;
    node temp21;
    node temp22;
    int price01;
    int price02;
    int price10;
    int price20;
    int price11;
    int price12;
    int price21;
    int price22;
    q.push(origin);
    node k = q.front();
    
    
    while(!q.empty()){
       
        if(img.at<Vec3b>(k.x,k.y+1)[0]==0 && img.at<Vec3b>(k.x,k.y+1)[1]==0 && img.at<Vec3b>(k.x,k.y+1)[2]==0 && k.x>=0 && k.y+1 < img.cols){
            
            
            temp01.x = k.x;
            temp01.y = k.y+1;
            temp01.x1 = k.x;
            temp01.y1 = k.y;
            temp01.cost = k.cost + 1;
            price01 = temp01.cost;
            q.push(temp01);
            img.at<Vec3b>(k.x,k.y)[0]= 50;
            img.at<Vec3b>(k.x,k.y)[1]= 0;
            img.at<Vec3b>(k.x,k.y)[2]= 0;
            img.at<Vec3b>(temp01.x,temp01.y)[0]=50;
            img.at<Vec3b>(temp01.x,temp01.y)[1]=0;
            img.at<Vec3b>(temp01.x,temp01.y)[2]=0;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x,k.y-1)[0]==0 && img.at<Vec3b>(k.x,k.y-1)[1]==0 && img.at<Vec3b>(k.x,k.y-1)[2]==0 && k.y-1>0){
            
            
            temp02.x = k.x;
            temp02.y = k.y-1;
            temp02.x1 = k.x;
            temp02.y1 = k.y;
            temp02.cost = k.cost + 1;
            price02 = temp02.cost;
            q.push(temp02);
            img.at<Vec3b>(k.x,k.y)[0]=50;
            img.at<Vec3b>(k.x,k.y)[1]=0;
            img.at<Vec3b>(k.x,k.y)[2]=0;
            img.at<Vec3b>(temp02.x,temp02.y)[0]=50;
            img.at<Vec3b>(temp02.x,temp02.y)[1]=0;
            img.at<Vec3b>(temp02.x,temp02.y)[2]=0;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x+1,k.y)[0]==0 && img.at<Vec3b>(k.x+1,k.y)[1]==0 && img.at<Vec3b>(k.x+1,k.y)[2]==0&&k.x+1<img.rows){
            
            
            temp10.x1= k.x+1;
            temp10.y = k.y;
            temp10.x = k.x;
            temp10.y = k.y;
            temp10.cost = k.cost + 1;
            price10 = temp10.cost;
            q.push(temp10);
            img.at<Vec3b>(k.x,k.y)[0]=50;
            img.at<Vec3b>(k.x,k.y)[1]=0;
            img.at<Vec3b>(k.x,k.y)[2]=0;
            img.at<Vec3b>(temp10.x,temp10.y)[0]=50;
            img.at<Vec3b>(temp10.x,temp10.y)[1]=0;
            img.at<Vec3b>(temp10.x,temp10.y)[2]=0;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x-1,k.y)[0]==0 && img.at<Vec3b>(k.x-1,k.y)[1]==0 && img.at<Vec3b>(k.x-1,k.y)[2]==0&&k.x-1>=0){
            
            node temp20;
            temp20.x = k.x-1;
            temp20.y = k.y;
            temp20.x1 = k.x;
            temp20.y1 = k.y;
            temp20.cost = k.cost + 1;
            int price20 = temp20.cost;
            q.push(temp20);
            img.at<Vec3b>(k.x,k.y)[0]=255;
            img.at<Vec3b>(k.x,k.y)[1]=255;
            img.at<Vec3b>(k.x,k.y)[2]=255;
            img.at<Vec3b>(temp20.x,temp20.y)[0]=255;
            img.at<Vec3b>(temp20.x,temp20.y)[1]=255;
            img.at<Vec3b>(temp20.x,temp20.y)[2]=255;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x+1,k.y+1)[0]==0 && img.at<Vec3b>(k.x+1,k.y+1)[1]==0 && img.at<Vec3b>(k.x+1,k.y+1)[2]==0&&k.x+1<img.rows&&k.y+1<img.cols){
            
            
            temp11.x = k.x+1;
            temp11.y = k.y+1;
            temp11.x1 = k.x;
            temp11.y1 = k.y;
            temp11.cost = k.cost + 1;
            price11 = temp11.cost;
            q.push(temp11);
            img.at<Vec3b>(k.x,k.y)[0]=255;
            img.at<Vec3b>(k.x,k.y)[1]=255;
            img.at<Vec3b>(k.x,k.y)[2]=255;
            img.at<Vec3b>(temp11.x,temp11.y)[0]=255;
            img.at<Vec3b>(temp11.x,temp11.y)[1]=255;
            img.at<Vec3b>(temp11.x,temp11.y)[2]=255;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x+1,k.y-1)[0]==0 && img.at<Vec3b>(k.x+1,k.y-1)[1]==0 && img.at<Vec3b>(k.x+1,k.y-1)[2]==0&&k.x+1<1000&&k.y-1>=0){
            
            
            temp12.x = k.x+1;
            temp12.y = k.y-1;
            temp12.x1 = k.x;
            temp12.y1 = k.y;
            temp12.cost = k.cost + 1;
            price12 = temp12.cost;
            q.push(temp12);
            img.at<Vec3b>(k.x,k.y)[0]= 255;
            img.at<Vec3b>(k.x,k.y)[1]= 255;
            img.at<Vec3b>(k.x,k.y)[2]= 255;
            img.at<Vec3b>(temp12.x,temp12.y)[0]=255;
            img.at<Vec3b>(temp12.x,temp12.y)[1]=255;
            img.at<Vec3b>(temp12.x,temp12.y)[2]=255;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x-1,k.y+1)[0]==0 && img.at<Vec3b>(k.x-1,k.y+1)[1]==0 && img.at<Vec3b>(k.x-1,k.y+1)[2]==0&&k.x-1>=0&&k.y+1<1000){
            
            
            temp21.x = k.x-1;
            temp21.y = k.y+1;
            temp21.x1 = k.x;
            temp21.y1 = k.y;
            temp21.cost = k.cost + 1;
            price21 = temp21.cost;
            q.push(temp21);
            img.at<Vec3b>(k.x,k.y)[0]= 255;
            img.at<Vec3b>(k.x,k.y)[1]= 255;
            img.at<Vec3b>(k.x,k.y)[2]= 255;
            img.at<Vec3b>(temp21.x,temp21.y)[0]=255;
            img.at<Vec3b>(temp21.x,temp21.y)[1]=255;
            img.at<Vec3b>(temp21.x,temp21.y)[2]=255;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        if(img.at<Vec3b>(k.x-1,k.y-1)[0]==0 && img.at<Vec3b>(k.x-1,k.y-1)[1]==0 && img.at<Vec3b>(k.x-1,k.y-1)[2]==0&&k.x-1>=0&&k.y-1>=0){
            
          
            temp22.x = k.x-1;
            temp22.y = k.y-1;
            temp22.x1 = k.x;
            temp22.y1 = k.y;
            temp22.cost = k.cost + 1;
            price22 = temp22.cost;
            q.push(temp22);
            img.at<Vec3b>(k.x,k.y)[0]=255;
            img.at<Vec3b>(k.x,k.y)[1]=255;
            img.at<Vec3b>(k.x,k.y)[2]=255;
            img.at<Vec3b>(temp22.x,temp22.y)[0]=255;
            img.at<Vec3b>(temp22.x,temp22.y)[1]=255;
            img.at<Vec3b>(temp22.x,temp22.y)[2]=255;
            namedWindow("window",WINDOW_NORMAL);
			imshow("window",img);
			waitKey(1);
        }
        else if(price01>price02 && price01>price10 && price01>price20 && price01>price11 && price01>price12 && price01>price12 && price01>price21 && price01>price22 ){
            temp01.x = k.x;
            temp01.y = k.y;
            temp01.x1 = k.x1;
            temp01.y1 = k.y1;
            temp01.cost = k.cost;                
        }
        else if(price02>price01 && price02>price10 && price02>price20 && price02>price11 && price02>price12 && price02>price12 && price02>price21 && price02>price22 ){
            temp02.x = k.x;
            temp02.y = k.y;
            temp02.x1 = k.x1;
            temp02.y1 = k.y1;
            temp02.cost = k.cost;                
        }
        else if(price10>price02 && price10>price01 && price10>price20 && price10>price11 && price10>price12 && price10>price12 && price10>price21 && price10>price22 ){
            temp10.x = k.x;
            temp10.y = k.y;
            temp10.x1 = k.x1;
            temp10.y1 = k.y1;
            temp10.cost = k.cost;                
        }
        else if(price20>price02 && price20>price10 && price20>price01 && price20>price11 && price20>price12 && price20>price12 && price20>price21 && price20>price22 ){
            temp20.x = k.x;
            temp20.y = k.y;
            temp20.x1 = k.x1;
            temp20.y1 = k.y1;
            temp20.cost = k.cost;                
        }
        else if(price11>price02 && price11>price10 && price11>price20 && price11>price01 && price11>price12 && price11>price12 && price11>price21 && price11>price22 ){
            temp11.x = k.x;
            temp11.y = k.y;
            temp11.x1 = k.x1;
            temp11.y1 = k.y1;
            temp11.cost = k.cost;                
        }
        else if(price12>price02 && price12>price10 && price12>price20 && price12>price11 && price12>price12 && price12>price01 && price12>price21 && price12>price22 ){
            temp12.x = k.x;
            temp12.y = k.y;
            temp12.x1 = k.x1;
            temp12.y1 = k.y1;
            temp12.cost = k.cost;                
        }
        else if(price21>price02 && price21>price10 && price21>price20 && price21>price11 && price21>price12 && price21>price12 && price21>price01 && price21>price22 ){
            temp21.x = k.x;
            img.at<Vec3b>(temp22.x,temp22.y)[0]=0;
            temp21.y = k.y;
            temp21.x1 = k.x1;
            temp21.y1 = k.y1;
            temp21.cost = k.cost;                
        }
        else if(price22>price02 && price22>price10 && price22>price20 && price22>price11 && price22>price12 && price22>price12 && price22>price21 && price22>price01 ){
            temp22.x = k.x;
            temp22.y = k.y;
            temp22.x1 = k.x1;
            temp22.y1 = k.y1;
            temp22.cost = k.cost;                
        }
        q.pop();
    }

}

int main(){
    Mat img = imread("obstacle.jpg",1);
    djk(img);

}