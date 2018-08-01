#include "playcontrols.h"

#include <QBoxLayout>
#include <QSlider>
#include <QToolButton>
#include <QComboBox>

PlayerControls::PlayerControls(QWidget *parent)
    : QWidget(parent)
    , playerState(STOP)
    , playerMuted(false)
    , playButton(0)
    , stopButton(0)
    , nextButton(0)
    , previousButton(0)
    , muteButton(0)
    , volumeSlider(0)
{
    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));

    stopButton = new QToolButton(this);
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setEnabled(false);

    connect(stopButton, SIGNAL(clicked()), this, SIGNAL(stop()));

    nextButton = new QToolButton(this);
    nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(nextButton, SIGNAL(clicked()), this, SIGNAL(next()));

    previousButton = new QToolButton(this);
    previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    connect(previousButton, SIGNAL(clicked()), this, SIGNAL(previous()));

    muteButton = new QToolButton(this);
    muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    connect(muteButton, SIGNAL(clicked()), this, SLOT(muteClicked()));

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);

    connect(volumeSlider, SIGNAL(sliderMoved(int)), this, SIGNAL(changeVolume(int)));

    QBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(stopButton);
    layout->addWidget(previousButton);
    layout->addWidget(playButton);
    layout->addWidget(nextButton);
    layout->addWidget(muteButton);
    layout->addWidget(volumeSlider);
    setLayout(layout);
}

State PlayerControls::state() const
{
    return playerState;
}

void PlayerControls::setState(State state)
{
    if (state != playerState)
    {
        playerState = state;

        switch (state)
        {
        case STOP:
            stopButton->setEnabled(false);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        case PLAYING:
            stopButton->setEnabled(true);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        case PAUSE:
            stopButton->setEnabled(true);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        }
    }
}

int PlayerControls::volume() const
{
    return volumeSlider ? volumeSlider->value() : 0;
}

void PlayerControls::setVolume(int volume)
{
    if (volumeSlider)
        volumeSlider->setValue(volume);
}

bool PlayerControls::isMuted() const
{
    return playerMuted;
}

void PlayerControls::setMuted(bool muted)
{
    if (muted != playerMuted)
    {
        playerMuted = muted;

        muteButton->setIcon(style()->standardIcon(muted
                ? QStyle::SP_MediaVolumeMuted
                : QStyle::SP_MediaVolume));
    }
}

void PlayerControls::playClicked()
{
    switch (playerState)
    {
    case STOP:
    case PAUSE:
        emit play();    //发射play()信号
        break;
    case PLAYING:
        emit pause();   //发射pause()信号
        break;
    }
}

void PlayerControls::muteClicked()
{
    emit changeMuting(!playerMuted);
}
