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
//~RConnectManager();

public:
virtual int Connect();
virtual int DisConnect();
virtual int Read();
virtual int Write();



private:
   int m_connectProtocol = 1;     //是串口连接还是udp
   RConnectSerialPort *m_rConnectSerialPort; //


};

}









#endif // RCONNECTMANAGER_H
