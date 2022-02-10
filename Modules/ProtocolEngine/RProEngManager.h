#ifndef RPROENGMANAGER_H
#define RPROENGMANAGER_H
/**
 * 这个是管理协议解析的
 *
 *    一、解包数据流：
 *    连接模块RConnectManager的信号sigReadBuffer(QByteArray*)连接到RProEngManager的信号sigRead(QByteArray *)
 *    然后RProEngManager的信号sigRead(QByteArray *)连接到RProEngManager的解析槽函数Read
 *
 *    二、打包数据
 *
 *
 **/




#include <QObject>
#include "Bridge.h"
#include "RProEng.h"
#include "RDataEngDefault.h"
#include <QThread>

class RProEng;

class RProEngManager: public QObject
{
    Q_OBJECT
public:
    explicit RProEngManager(QObject *parent = nullptr);
    ~RProEngManager();
    static RProEngManager* Instance();



signals:
    void sigRead(QByteArray * qByteArrayBuffer);


public:
    RProEng *m_RProEng = nullptr;
    RDataEngDefault *m_RDataEngDefault = nullptr;
    static RProEngManager *m_this ;
private:
    QThread m_RProEngThread;
};




#endif // RPROENGMANAGER_H









