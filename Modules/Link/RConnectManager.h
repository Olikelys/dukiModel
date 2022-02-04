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

public:
Q_INVOKABLE virtual int Connect();
Q_INVOKABLE         int Connect(QString portName,QString baudRate,QString dataBits,QString parity,QString stopBits,QString flowControl);
Q_INVOKABLE virtual int DisConnect();
Q_INVOKABLE virtual int Read();
Q_INVOKABLE virtual int Write();



private:
   int m_connectProtocol = 1;     //是串口连接还是udp
   RConnectSerialPort *m_rConnectSerialPort =nullptr;
};

}









#endif // RCONNECTMANAGER_H
