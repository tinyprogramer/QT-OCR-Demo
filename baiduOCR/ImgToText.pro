#-------------------------------------------------
#
# Project created by QtCreator 2021-02-12T21:01:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImgToText
TEMPLATE = app

INCLUDEPATH += ./aip-cpp-sdk-4.15.4 \
    E:/github/jsoncpp-1.9.4/jsoncpp-1.9.4/include \
    E:/github/curl-7.75.0_2-win64-mingw/curl-7.75.0-win64-mingw/include \
    $$quote(C:/Program Files/OpenSSL/include)
#    E:/github/openssl-1.1.1i/openssl-1.1.1i/include

LIBS += E:/github/curl-7.75.0_2-win64-mingw/curl-7.75.0-win64-mingw/lib/libcurl.dll.a \
    -LE:/github/jsoncpp-1.9.4/jsoncpp-1.9.4/build/lib/Release -ljsoncpp \
    -L$$quote(C:/Program Files/OpenSSL/lib) -llibcrypto

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
        mainwindow.h \
    aip-cpp-sdk-4.15.4/base/base.h \
    aip-cpp-sdk-4.15.4/base/base64.h \
    aip-cpp-sdk-4.15.4/base/http.h \
    aip-cpp-sdk-4.15.4/base/utils.h \
    aip-cpp-sdk-4.15.4/face.h \
    aip-cpp-sdk-4.15.4/image_censor.h \
    aip-cpp-sdk-4.15.4/image_classify.h \
    aip-cpp-sdk-4.15.4/image_search.h \
    aip-cpp-sdk-4.15.4/kg.h \
    aip-cpp-sdk-4.15.4/nlp.h \
    aip-cpp-sdk-4.15.4/ocr.h \
    aip-cpp-sdk-4.15.4/speech.h \
    aip-cpp-sdk-4.15.4/video_censor.h \
    aip-cpp-sdk-4.15.4/voice_censor.h \
    mainwindow.h

FORMS += \
        mainwindow.ui
