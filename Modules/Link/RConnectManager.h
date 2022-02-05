#ifndef RCONNECTMANAGER_H
#define RCONNECTMANAGER_H
#include "RConnectAbstract.h"
#include "RConnectSerialPort.h"
#include <QtQml>

#define RLINK_RCONNECTMANAGER_INITIALIZA   {qmlRegisterType<RLink::RConnectManager>("RLink",1,0,"RConnectManager");}


namespace RLink {




class RConnectManager : public RConnectAbstract
{
    Q_OBJECT
public:
explicit RConnectManager(QObject *parent = nullptr );
~RConnectManager();

//串口部分
signals:
    void sigGetSerialPortName();
    void sigSetSerialPortName(QStringList serialPortNameList);
    void sigtest();
public slots:

public:


//UDP部分

public:
Q_INVOKABLE virtual int Connect();
Q_INVOKABLE         int Connect(QString portName,QString baudRate,QString dataBits,QString parity,QString stopBits,QString flowControl);
Q_INVOKABLE virtual int DisConnect();
Q_INVOKABLE virtual int Read();
Q_INVOKABLE virtual int Write();




//连接全局
signals:
    void connectDataSourcesChanged(int m_connectDataSources);
    void connectStateChaged(int m_connectState);
public:
    int getConnectDataSources();
    void setConnectDataSources(int index);
    int getConnectState();
    void setConnectState(int state);

public:
    Q_PROPERTY( int connectDataSources READ getConnectDataSources WRITE setConnectDataSources NOTIFY connectDataSourcesChanged );    //连接协议
    Q_PROPERTY( int connectState READ getConnectState WRITE setConnectState NOTIFY connectStateChaged);                    //连接状态





private:
   int m_connectDataSources ;     //是串口连接还是udp还是其他
   int m_connectState;
   RConnectSerialPort *m_rConnectSerialPort =nullptr;
};

}









#endif // RCONNECTMANAGER_H
