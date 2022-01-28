#ifndef RCONNECTSERIALPORT_H
#define RCONNECTSERIALPORT_H
#include<QtSerialPort/QSerialPort>
#include"RConnectAbstract.h"


namespace RLink {

class RConnectSerialPort : public RConnectAbstract
{
    Q_OBJECT
public:
explicit RConnectSerialPort(QObject *parent = nullptr);
    //~RConnectSerialPort();

public:
    virtual int Connect();
    virtual int DisConnect();
    virtual int Read();
    virtual int Write();
    int Write(QByteArray byteArray);


private:
    QSerialPort * m_serial = nullptr;
};

}




#endif // RCONNECTSERIALPORT_H
