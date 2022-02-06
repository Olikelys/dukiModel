#include "RConnectManager.h"


using namespace RLink;



RConnectManager::RConnectManager(QObject *parent)
 :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_rConnectSerialPort = new RConnectSerialPort( parent);
    m_rConnectSerialPort->moveToThread(&m_connectThread);

    connect(this,SIGNAL(sigGetSerialPortName() ),m_rConnectSerialPort,SIGNAL(sigGetSerialPortName() ));
    connect(m_rConnectSerialPort,SIGNAL(sigSetSerialPortName( QStringList ) ),this,SIGNAL(sigSetSerialPortName( QStringList ) )  );
    connect(m_rConnectSerialPort, SIGNAL( sigReadyRead() ), this, SIGNAL( sigReadyRead() ));
    //connect(this,SIGNAL( sigReadyRead() ),this,SLOT([=](){ qDebug("12"); }));
    m_connectThread.start();

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
    if( 0 ==m_rConnectSerialPort->Connect( portName, \
                                   baudRate, \
                                   dataBits, \
                                   parity, \
                                   stopBits,\
                                   flowControl))
    {
        setConnectState(1);
    }
    return 0 ;
}
int RConnectManager::DisConnect()
{
    switch (m_connectDataSources) {
    case 0 :{//串口的关闭
        if( 0 == m_rConnectSerialPort->DisConnect())
        {
            setConnectState(0);
        }
        else {
            qDebug()<<"无法关闭串口";
        }
    }break;
    default:{}break;
    }
    //qDebug()<<"state"<<m_connectState;
    return 0;
}
int RConnectManager::Read()
{
    m_rConnectSerialPort->Read();
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



int RConnectManager::ResetConnect()
{
    switch (m_connectDataSources) {
    case 0:{

    }break;
    case 1:{

    }break;
    case 2:{

    }break;
    default:{

    }
    }
    return 0;
}
