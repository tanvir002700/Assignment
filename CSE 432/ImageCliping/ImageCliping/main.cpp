//
//  main.cpp
//  ImageCliping
//
//  Created by Tanvir Hasan on 7/25/15.
//  Copyright (c) 2015 Tanvir Hasan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
class POINT{
    private:
        int x,y;
    public:
        POINT(int x=0,int y=0):x(x),y(y){};
    int getX(){return x;}
    int getY(){return y;}
    int area2(const POINT &p1,const POINT &p2)const{
        return (p2.x-x)*(p1.y-y)-(p1.x-x)*(p2.y-y);
    }
    int dist2(const POINT &b)const{
        int dx=x-b.x,dy=y-b.y;return dx*dx+dy*dy;
    }
    bool operator==(const POINT &b)const{
        return x==b.x and y==b.y;
    }
    bool operator<(const POINT &b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};
POINT P0;
bool angle_comp(POINT a,POINT b)
{
    if(P0.area2(a,b)==0)
    {
        return P0.dist2(a)<P0.dist2(b);
    }
    int d1x=a.getX()-P0.getX(),d1y=a.getY()-P0.getY();
    int d2x=b.getX()-P0.getX(),d2y=b.getY()-P0.getY();
    return (atan2((double)d1y,(double)d1x)-atan2((double)d2y,(double)d2x))<0;
}
class Polygon{
    private:
        vector<POINT>polygon;
        int Max;
        int trun(POINT p0,POINT p1,POINT p2){
            int result=(p2.getX()-p0.getX())*(p1.getY()-p0.getY())-(p1.getX()-p0.getX())*(p2.getY()-p0.getY());
            if(result>0)return 1;
            if(result < 0)return -1;
            return result;
        }
        bool on_segment(POINT pi,POINT pj,POINT pk){
            int minx=min(pi.getX(),pj.getX());int maxx=max(pi.getX(),pj.getX());
            int miny=min(pi.getY(),pj.getY());int maxy=max(pi.getY(),pj.getY());
            if(pk.getX()>=minx&&pk.getX()<=maxx&&pk.getY()>=miny&&pk.getY()<=maxy)return true;
            return false;
        }
        bool Segment_intersect(POINT p1,POINT p2,POINT p3,POINT p4){
            int d1=trun(p3,p4,p1);
            int d2=trun(p3,p4,p2);
            int d3=trun(p1,p2,p3);
            int d4=trun(p1,p2,p4);
            if((d1*d2<0)&&(d3*d4<0))return true;
            //if(d1==0&&on_segment(p3,p4,p1))return true;
            //if(d2==0&&on_segment(p3,p4,p2))return true;
            if(d3==0&&on_segment(p1,p2,p3))return true;
            //if(d4==0&&on_segment(p1,p2,p4))return true;
            return false;
        }
    public:
        Polygon(const vector<POINT>&v){
            Max=-1000;
            polygon=v;
            int i,N=(int)polygon.size();
            int po=0;
            for ( i=0; i<N; i++)
            {
                Max=max(Max,polygon[i].getX());
                if(polygon[i].getY() < polygon[po].getY() || (polygon[i].getY()== polygon[po].getY() && polygon[i].getX() < polygon[po].getX()))po=i;
            }
            P0 = polygon[po];
            sort(polygon.begin(),polygon.end(),angle_comp);
        }
        bool InsidePolygon(POINT p){
            POINT inf(Max+100,p.getY()+1);
            int intersect=0;
            int N=(int)polygon.size();
            for(int i=0;i<N;i++){
                POINT p1=polygon[i];
                POINT p2=polygon[(i+1)%N];
                if(Segment_intersect(p1,p2,p,inf)){
                    intersect++;
                }
            }
            return (intersect%2==1);
        }
    void pirnt(){
        for (int i=0; i<polygon.size(); i++) {
            cout<<polygon[i].getX()<<" "<<polygon[i].getY()<<endl;
        }
    }
};
class ImageClip{
    private:
        Mat RET;
        vector<POINT>point;
    public:
        ImageClip(const Mat &m,vector<POINT> &p){
            m.copyTo(RET);
            point=p;
        }
        Mat getClipDate(){
            Polygon poli(point);
            poli.pirnt();
            for (int i=0; i<RET.size().height; i++) {
                for (int j=0; j<RET.size().width; j++) {
                    int x=j;
                    int y=RET.size().height-i;
                    Vec3b color=RET.at<Vec3b>(i,j);
                    if(!poli.InsidePolygon(POINT(x,y))){
                        color=Vec3b(0,0,0);
                    }
                    RET.at<Vec3b>(i,j)=color;
                }
            }
            return RET;
        }
};

int main(int argc, const char * argv[]) {
    Mat Data;
    //Data=imread("che.jpg");
    Data=imread("pic.png");
    if(!Data.data){
        cout<<"file can't read"<<endl;
        return 0;
    }
    namedWindow("original image",WINDOW_AUTOSIZE);
    imshow("original image", Data);
    cout<<Data.rows<<" "<<Data.cols<<endl;
    cout<<"Enter Number of point "<<endl;
    int N;
    while (cin>>N and N) {
        vector<POINT>v;
        for (int i=0; i<N; i++) {
            int x,y;
            cin>>x>>y;
            v.push_back(POINT(x,y));
        }
        ImageClip A(Data,v);
        Mat Clip;
        A.getClipDate().copyTo(Clip);
        namedWindow("clip image",WINDOW_AUTOSIZE);
        imshow("clip image", Clip);
        waitKey(0);
        cvDestroyWindow("clip image");
        cout<<"Enter Number of point "<<endl;
    }
    cvDestroyAllWindows();
    return 0;
}
/*
 polygon input:
 3
 100 100
 400 100
 200 400
 
 4
 39 64
 400 64
 39 400
 400 400
 
 
 5
 50 50
 100 300
 280 350
 300 100
 100 100
 
 5
 50 50
 300 30
 400 200
 250 300
 40 330
 
 6
 100 250
 100 150
 200 50
 300 150
 300 250
 200 400
 */