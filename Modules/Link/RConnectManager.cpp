#include "RConnectManager.h"


using namespace RLink;



RConnectManager::RConnectManager(QObject *parent)
 :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_rConnectSerialPort = new RConnectSerialPort( parent);

}

RConnectManager::~RConnectManager()
{

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
