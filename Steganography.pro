TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

TARGET = steg

SOURCES += main.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \

include(deployment.pri)
qtcAddDeployment()

