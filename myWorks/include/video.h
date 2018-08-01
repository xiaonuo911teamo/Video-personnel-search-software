#ifndef VIDEO_H
#define VIDEO_H

#include <opencv.hpp>
#include <opencv2/face.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class Video
{
public:
    Video();
    ~Video();
    void getFrame(int k);
    void setShowIamge();
    void setVideo(string s);
    double get(int ID);
    void set(int ID,double pos);
    bool isOpened();
    Mat getNextFrame(int num);  //取接下来的第num帧
    double rate; //FPS

private:
    VideoCapture v;

};

#endif // VIDEO_H
