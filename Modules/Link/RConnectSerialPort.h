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
        void sigReadyRead();
        void sigReadBuffer(QByteArray* newQByteArraybuffer);

public slots :
            int SlotGetSerialPortName();
            int SlotReadyRead();
            int Write(QByteArray &writebuffer);  //在子线程下交互依靠信号槽机制






public:
    virtual int Connect();
            int Connect(QString portName,QString baudRate,QString dataBits,QString parity,QString stopBits,QString flowControl);
    virtual int DisConnect();
    virtual int Read();
    virtual int Write();




private:
    QSerialPort * m_serial = nullptr;
};

}




#endif // RCONNECTSERIALPORT_H
