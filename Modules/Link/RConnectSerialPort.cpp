#include "RConnectSerialPort.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QThread>

using namespace RLink ;

RConnectSerialPort::RConnectSerialPort(QObject *parent)
    :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_serial = new QSerialPort;
    connect(this,SIGNAL(sigGetSerialPortName()),this,SLOT(SlotGetSerialPortName()));
    connect( m_serial,SIGNAL(readyRead() ) ,this,SIGNAL(sigReadyRead())   );
    connect(this,SIGNAL( sigReadyRead()), this, SLOT(SlotReadyRead()));
}

RConnectSerialPort::~RConnectSerialPort()
{
    if(m_serial->isOpen())
        {
            m_serial->clear();
            m_serial->close();
        }
    delete m_serial;
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
        return 1;
    }
}

int RConnectSerialPort::Connect(QString portName, \
                             QString baudRate, \
                             QString dataBits, \
                             QString parity, \
                             QString stopBits,\
                             QString flowControl)
{
    m_serial->setPortName(portName);
    if(!m_serial->open(QIODevice::ReadWrite))
    {
        qWarning()<<"Open error";
        return 10;
    }

    switch (baudRate.toInt()) {
    case 1200:{
        m_serial->setBaudRate(QSerialPort::Baud1200);
        break;
    }
    case 2400:{
        m_serial->setBaudRate(QSerialPort::Baud2400);
        break;
    }
    case 4800:{
        m_serial->setBaudRate(QSerialPort::Baud4800);
        break;
    }
    case 9600:{
        m_serial->setBaudRate(QSerialPort::Baud9600);
        break;
    }
    case 19200:{
        m_serial->setBaudRate(QSerialPort::Baud19200);
        break;
    }
    case 38400:{
        m_serial->setBaudRate(QSerialPort::Baud38400);
        break;
    }
    case 57600:{
        m_serial->setBaudRate(QSerialPort::Baud57600);
        break;
    }
    case 115200:{
        m_serial->setBaudRate(QSerialPort::Baud115200);
        break;
    }
    default:{
        qWarning()<<"打开失败没有这个波特率";
        return 20;
    }
    }


    switch (dataBits.toInt()) {
    case 6:{
        m_serial->setDataBits(QSerialPort::Data6);
        break;
    }
    case 7:{
        m_serial->setDataBits(QSerialPort::Data7);
        break;
    }
    case 8:{
        m_serial->setDataBits(QSerialPort::Data8);
        break;
    }
    default:{
        qWarning()<<"没有这个数据位";
        return 30;
    }
    }

    switch (parity.toInt()) {
    case 0:{
        m_serial->setParity(QSerialPort::NoParity);         //校验位设置为0
        break;
    }
    case 2:{
        m_serial->setParity(QSerialPort::EvenParity);
        break;
    }
    case 3:{
        m_serial->setParity(QSerialPort::OddParity);
        break;
    }
    default:{
        qWarning()<<"没有这个校验位";
        return 40;
    }
    }

    switch (stopBits.toInt()) {
    case 1:{
        m_serial->setStopBits(QSerialPort::OneStop);
        break;
    }
    case 2:{
        m_serial->setStopBits(QSerialPort::TwoStop);
        break;
    }
    case 3:{
        m_serial->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    }
    default:{
        qWarning()<<"没有这个停止位";
        return 50;
    }
    }

    switch (flowControl.toInt()) {
    case 0:{
        m_serial->setFlowControl(QSerialPort::NoFlowControl);
        break;
    }
    case 1:{
        m_serial->setFlowControl(QSerialPort::HardwareControl);
        break;
    }
    case 2:{
        m_serial->setFlowControl(QSerialPort::SoftwareControl);
        break;
    }
    default:{
        qWarning()<<"无该流控";
        return 60;
    }
    }
    return 0;
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





int RConnectSerialPort::SlotGetSerialPortName()
{

    QStringList serialPortName;
    foreach( QSerialPortInfo serialInfo ,QSerialPortInfo::availablePorts()  )
    {
        serialPortName.append(serialInfo.portName());
    }
//    foreach(QString str, serialPortName)
//    {
//        qDebug()<<"33"<<str;
//    }

    emit sigSetSerialPortName( serialPortName );
//    foreach(QSerialPortInfo serialInfo ,QSerialPortInfo::availablePorts() )
//    {
//        qDebug()<<"portName:"<<serialInfo.portName();
//        qDebug()<<"description:"<<serialInfo.description();
//        qDebug()<<"manufacturer:"<<serialInfo.manufacturer();
//        qDebug()<<"serialnumber:"<<serialInfo.serialNumber();
//        //qDebug()<<"systemlocation:"<<m_serialInfo.systemlocation();
//    }
    return 0;
}



int RConnectSerialPort::SlotReadyRead()
{
    //qDebug()<<"缓冲区大小"<<m_serial->readBufferSize()<<"接受的值"<<m_serial->readAll();
    QByteArray test = m_serial->readAll();
    qDebug()<<test;
    return 0;
}







