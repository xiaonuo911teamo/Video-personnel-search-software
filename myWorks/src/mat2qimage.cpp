/*******************************************************
    该程序段来源于网络
********************************************************/
#include "mat2qimage.h"

QImage  Mat2QImage(cv::Mat cvImg)
{
    QImage qImg;
    if(cvImg.channels()==3)                             //3 channels color image
    {

        cv::cvtColor(cvImg,cvImg,CV_BGR2RGB);
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols, cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1)                    //grayscale image
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    return qImg;
}
