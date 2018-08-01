/*************************************************

 Filename:      playcontrols.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该文件可创建一个视频播放管理组。从左到右包括停止、后退、播放/暂停、快进、音量调节 按钮。
                继承自Widget，通过适当的设置可完成对视频的相应控制。

 Others:  仿照QT实例写的

 FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明
   1. volume: int
        声音滑块的位置，相关联的函数有：
        int volume() const;
        void setVolume(int volume);
        void changeVolume(int volume);

   2. muted: bool
        是否静音，相关联的函数有：
        bool isMuted() const;
        void setMuted(bool muted);
        void changeMuting(bool muting);
        void muteClicked();

   3. state：State
        播放状态，相关联的函数有：
        void setState(State state);
        State state() const;
   4. 返回播放/后退速度
    qreal playbackRate() const;

    除此之外还有下列信号
signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeRate(qreal rate);

    以及一个私有的函数
private slots:
    void playClicked();     // 播放/暂停按钮被点击的事件

 History:        // 修改历史记录列表，每条修改记录应包括修改日期、修改

                 // 者及修改内容简述

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/
#ifndef PLAYCONTROLS_H
#define PLAYCONTROLS_H

#include <QMediaPlayer>
#include <QWidget>
#include <QStyle>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QAbstractSlider;
class QComboBox;
QT_END_NAMESPACE

enum State{PLAYING,PAUSE,STOP};     //自定义的播放状态：播放、暂停、停止

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    PlayerControls(QWidget *parent = 0);    //构造函数

    //QMediaPlayer::State state() const;
    int volume() const;                     //返回当前音量
    bool isMuted() const;                   //返回是否静音，是返回1，否返回0
    qreal playbackRate() const;             //返回播放/后退速度
    State state() const;                    //返回当前状态

public slots:
    void setState(State state);             //设置播放状态
    void setVolume(int volume);             //设置音量
    void setMuted(bool muted);              //设置是否静音

signals:
    // 发射各个按钮被按下的信号
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeVolume(int volume);
    void changeMuting(bool muting);
    void changeRate(qreal rate);

private slots:
    void playClicked();                 //视频播放响应函数
    void muteClicked();                 //音量响应函数

private:
    State playerState;
    bool playerMuted;
    QAbstractButton *playButton;
    QAbstractButton *stopButton;
    QAbstractButton *nextButton;
    QAbstractButton *previousButton;
    QAbstractButton *muteButton;
    QAbstractSlider *volumeSlider;
};
#endif // PLAYCONTROLS_H
