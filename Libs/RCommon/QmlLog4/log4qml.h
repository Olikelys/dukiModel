#ifndef LOG4QML_H
#define LOG4QML_H
/*!
 *@file log4qml.h
 *@brief Qml写日志
 *@version 1.0
 *@section LICENSE Copyright (C) 2022-2103 CamelSoft Corporation
 *@author runhey
*/
#include <QObject>

class Log4Qml: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Log4QmlPath READ getLog4QmlPath WRITE setLog4QmlPath);
    Q_PROPERTY(QString Log4QmlName READ getLog4QmlName WRITE setLog4QmlName);

public:
    static  QString Log4QmlPath ;
    static  QString Log4QmlName ;
public:
    Log4Qml(QString log4path);
    Q_INVOKABLE void setLog4QmlPath(QString log4qmlpath);
    Q_INVOKABLE void setLog4QmlName(QString log4qmlname);
    Q_INVOKABLE QString getLog4QmlPath(void);
    Q_INVOKABLE QString getLog4QmlName(void);


    Q_INVOKABLE void qDebug_Info(int type, QString strInfo);
};



#endif // LOG4QML_H
