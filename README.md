# Video-personnel-search-software
说明：可添加登记员工个人信息，用于员工管理。可通过陌生人模式查找视频中未登记的人员。可通过指定人查找方式，在视频中仅识别指定人员。 
     演示视频链接如下：http://url.cn/5WhWo4K?sf=uri 
     
注意事项： 
    原项目由QT5.4的mingw版本构建，使用opencv3.0版本的库文件。 
    
使用方法： 

    使用QT打开pro文件后，需要根据你的机器修改如下几部分。 
    
    1.INCLUDEPATH += D:\software\QT5.4\opencv_use\include\opencv \ 
              D:\software\QT5.4\opencv_use\include\opencv2 \ 
              D:\software\QT5.4\opencv_use\include 
              
      此处应添加opencv的库目录，注意不能有中文字符。 
      
    2.LIBS += D:\software\QT5.4\opencv_use\lib\libopencv*.a 
    
      此处同上修改为对应地址。 
      
    修改了上面两部分之后，应该就可以正常编译了。如有问题，可联系QQ1373759560 
     
调试须知： 

    1.在src/settings.cpp文件中，构造函数Settings()中对应文件可进行修改。 
    
      s_strangers     在视频中检测到陌生人的默认储存位置 
      
      s_video         默认打开的视频地址 
      
      s_faceCascade   人脸分类器的地址 
      
      s_modelPCA      人脸特征xml文件的位置 
      
    2.主界面窗口函数为findpeoplewindow.cpp，其中有几个参数需说明一下。 
    
      strangerRate    陌生人保存频率，由于部分视频的帧率较高，导致生成陌生人数量过多，严重时会导致软件卡死，
      
                      通过调节该参数可控制每张储存一张。 
                      
      threshold       置信度阈值，此为判断是否会判定为陌生人的标尺。 
      
    3.tipdialog是一个提示窗，通过new tipDialog(0,tr("内容")); 即可弹出一个提示框。 
    
    4.5-1.mp4是我在调试时使用的视频，你也可以使用你自己的。
    
    5.类Video用于控制视频的播放。 
    
