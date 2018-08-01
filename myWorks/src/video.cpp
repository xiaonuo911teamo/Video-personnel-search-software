#include "video.h"

Video::Video()
{
    rate=v.get(CV_CAP_PROP_FRAME_COUNT);
}

Video::~Video()
{

}

void Video::setVideo(string s)
{
    v.open(s);
    rate=v.get(CV_CAP_PROP_FRAME_COUNT);
}

void Video::set(int ID, double pos)
{
    v.set(ID,pos);
}

double Video::get(int ID)
{
    return v.get(ID);
}

Mat Video::getNextFrame(int num)
{
    int i=0;
    Mat frame;
    for(i=0;i<num;i++)
    {
        v>>frame;
        if(!frame.empty())
            break;
    }
    return frame;
}

bool Video::isOpened()
{
    return v.isOpened();
}
