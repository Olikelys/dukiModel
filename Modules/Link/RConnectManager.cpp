#include "RConnectManager.h"


using namespace RLink;



RConnectManager::RConnectManager(QObject *parent)
 :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_rConnectSerialPort = new RConnectSerialPort( parent);

    connect(this,SIGNAL(sigGetSerialPortName() ),m_rConnectSerialPort,SIGNAL(sigGetSerialPortName() ));
    connect(m_rConnectSerialPort,SIGNAL(sigSetSerialPortName( QStringList ) ),this,SIGNAL(sigSetSerialPortName( QStringList ) )  );



}

RConnectManager::~RConnectManager()
{
    delete m_rConnectSerialPort;
}


int RConnectManager::Connect()
{
    return 0;
}
int RConnectManager::Connect(QString portName, \
                             QString baudRate, \
                             QString dataBits, \
                             QString parity, \
                             QString stopBits,\
                             QString flowControl)
{
    m_rConnectSerialPort->Connect( portName, \
                                   baudRate, \
                                   dataBits, \
                                   parity, \
                                   stopBits,\
                                   flowControl);
    return 0 ;
}
int RConnectManager::DisConnect()
{
    return 0;
}
int RConnectManager::Read()
{
    return 0;
}
int RConnectManager::Write()
{
    return 0;
}



int RConnectManager::getConnectDataSources()
{
    return m_connectDataSources;
}
void RConnectManager::setConnectDataSources(int index)
{
    m_connectDataSources=index;
}
int RConnectManager::getConnectState()
{
    return m_connectState;
}
void RConnectManager::setConnectState(int state)
{
    m_connectState=state;
}
