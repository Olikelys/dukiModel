#include "log4qml.h"
#include <QMutex>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>
#include <QDir>


QString  Log4Qml::Log4QmlPath = "";
QString  Log4Qml::Log4QmlName = "";


void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString message = "";
    if (context.file != nullptr)
    {
        QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
        QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
        QString current_date = QString("(%1)").arg(current_date_time);
        message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(msg).arg(context_info);
    }
    else
    {
        message = msg;
    }

    QFile file("log.txt");
    file.setFileName(QString("%1\/%2").arg("log").arg(Log4Qml::Log4QmlName));
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}




Log4Qml::Log4Qml(QString log4path)
{

    QDir dir;
    dir.mkdir("log");
    Log4Qml::Log4QmlPath = log4path;
    Log4Qml::Log4QmlName = QString("%1.%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd#hh#mm")).arg("txt");

    //qDebug()<<"path:"<<Log4Qml::Log4QmlPath<<"name :"<<Log4Qml::Log4QmlName<<
    //回调函数注册到QT中   是重定向

    qInstallMessageHandler(outputMessage);

}

QString Log4Qml::getLog4QmlPath(void)
{
    return Log4Qml::Log4QmlPath;
}

void Log4Qml::setLog4QmlPath(QString log4qmlpath)
{
    Log4Qml::Log4QmlPath=log4qmlpath;
}

QString Log4Qml::getLog4QmlName(void)
{
    return Log4Qml::Log4QmlName;
}

void Log4Qml::setLog4QmlName(QString log4qmlname)
{
    Log4Qml::Log4QmlName = log4qmlname;
}

void Log4Qml::qDebug_Info(int type, QString strInfo)
{
    QMessageLogContext context;
    context.file = nullptr;
    outputMessage((QtMsgType)type, context, strInfo);
}
