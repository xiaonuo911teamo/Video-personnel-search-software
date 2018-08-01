#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T12:16:32
#
#-------------------------------------------------

QT       += core gui
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myWorks
TEMPLATE = app


SOURCES += src/addpeopledialog.cpp \
    src/configuredialog.cpp \
    src/findpeoplewindow.cpp \
    src/main.cpp \
    src/mat2qimage.cpp \
    src/people.cpp \
    src/peoplelistitem.cpp \
    src/playcontrols.cpp \
    src/registereddialog.cpp \
    src/registeredpeopledialog.cpp \
    src/settings.cpp \
    src/strangersdialog.cpp \
    src/tinystr.cpp \
    src/tinyxml.cpp \
    src/tinyxmlerror.cpp \
    src/tinyxmlparser.cpp \
    src/tipdialog.cpp \
    src/video.cpp

INCLUDEPATH += D:\software\QT5.4\opencv_use\include\opencv \
        D:\software\QT5.4\opencv_use\include\opencv2 \
        D:\software\QT5.4\opencv_use\include \
        -l include

LIBS += D:\software\QT5.4\opencv_use\lib\libopencv*.a

HEADERS  += include/addpeopledialog.h \
    include/configuredialog.h \
    include/findpeoplewindow.h \
    include/mat2qimage.h \
    include/people.h \
    include/peoplelistitem.h \
    include/playcontrols.h \
    include/registereddialog.h \
    include/registeredpeopledialog.h \
    include/settings.h \
    include/strangersdialog.h \
    include/tinystr.h \
    include/tinyxml.h \
    include/tipdialog.h \
    include/ui_addpeopledialog.h \
    include/ui_configuredialog.h \
    include/ui_findpeoplewindow.h \
    include/ui_registereddialog.h \
    include/ui_registeredpeopledialog.h \
    include/ui_strangersdialog.h \
    include/ui_tipdialog.h \
    include/video.h

FORMS    += ui/addpeopledialog.ui \
    ui/configuredialog.ui \
    ui/findpeoplewindow.ui \
    ui/registereddialog.ui \
    ui/registeredpeopledialog.ui \
    ui/strangersdialog.ui \
    ui/tipdialog.ui
