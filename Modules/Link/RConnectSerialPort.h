#ifndef RCONNECTSERIALPORT_H
#define RCONNECTSERIALPORT_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include"RConnectAbstract.h"


namespace RLink {

class RConnectSerialPort : public RConnectAbstract
{
    Q_OBJECT
public:
explicit RConnectSerialPort(QObject *parent = nullptr);
       ~RConnectSerialPort();

signals:
        void sigGetSerialPortName();
        void sigSetSerialPortName(QStringList serialPortName);

public slots :
            int SlotGetSerialPortName();







public:
    virtual int Connect();
            int Connect(QString portName,QString baudRate,QString dataBits,QString parity,QString stopBits,QString flowControl);
    virtual int DisConnect();
    virtual int Read();
    virtual int Write();
            int Write(QByteArray byteArray);



private:
    QSerialPort * m_serial = nullptr;
};

}




#endif // RCONNECTSERIALPORT_H
