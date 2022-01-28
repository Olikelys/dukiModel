#include "RConnectSerialPort.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>

using namespace RLink ;

RConnectSerialPort::RConnectSerialPort(QObject *parent)
    :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_serial = new QSerialPort;
}


int RConnectSerialPort::Connect()
{
    qInfo()<<"portName"    <<m_serial->portName();
    qInfo()<<"baudRate"    <<m_serial->baudRate();
    qInfo()<<"dataBits"    <<m_serial->dataBits();
    qInfo()<<"parity"      <<m_serial->parity();
    qInfo()<<"stopBits"    <<m_serial->stopBits();
    qInfo()<<"flowControl" <<m_serial->flowControl();

    if(!m_serial->open(QIODevice::ReadWrite))
    {
    return 0;
    }
    else {
        qWarning()<<"串口连接失败";
    }
}

int RConnectSerialPort::DisConnect()
{
     m_serial->close() ;
        return 0;

}

int RConnectSerialPort::Read()
{
    qInfo()<<"串口读"<< m_serial->readAll();
    return 0;
}


int RConnectSerialPort::Write()
{
    return 0;
}
int RConnectSerialPort::Write(QByteArray byteArray)
{
    if(m_serial->write(byteArray))
    {
        return 0;
    }
    else {
        return 1;
    }
}












