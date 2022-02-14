#include "RConnectManager.h"
#include "RProEngManager.h"
#include "GlobalState.h"

using namespace RLink;

RConnectManager*  RConnectManager::m_this= nullptr;


RConnectManager::RConnectManager(QObject *parent)
 :RConnectAbstract(parent)
{
    Q_UNUSED(parent)
    m_this=this;
    m_rConnectSerialPort = new RConnectSerialPort( parent);
    m_rConnectSerialPort->moveToThread(&m_connectThread);

    connect(this,SIGNAL(sigGetSerialPortName() ),m_rConnectSerialPort,SIGNAL(sigGetSerialPortName() ));  //信号向下传递：获取端口名
    connect(m_rConnectSerialPort,SIGNAL(sigSetSerialPortName( QStringList ) ),this,SIGNAL(sigSetSerialPortName( QStringList ) )  ); //得到端口名后向上传递:
    connect(m_rConnectSerialPort, SIGNAL( sigReadyRead() ), this, SIGNAL( sigReadyRead() ));             //串口传上来的接收数据信号

    connect(m_rConnectSerialPort,SIGNAL(sigReadBuffer(QByteArray*) ),this,SIGNAL(sigReadBuffer(QByteArray*) ) );
    connect(this,SIGNAL(sigReadBuffer(QByteArray*) ),RProEngManager::Instance(),SIGNAL(sigRead(QByteArray*) ) );

    connect(this,SIGNAL(sigWrite(QByteArray& )),m_rConnectSerialPort,SLOT(Write(QByteArray&)));
    m_connectThread.start();

}
RConnectManager* RConnectManager::Instance()
{
    return m_this;
}

RConnectManager::~RConnectManager()
{
    delete m_rConnectSerialPort;
    m_connectThread.quit();
    m_connectThread.wait();
    m_connectThread.deleteLater();
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
        GlobalState::Instace()->StartLinkTimer();
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
            GlobalState::Instace()->StopLinkTimer();
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

//这个函数用不到
int RConnectManager::Write(QByteArray & writebuffer)
{
    switch (m_connectDataSources) {
    case 0:{//串口
            m_rConnectSerialPort->Write(writebuffer);
    }break;
    case 1:{//

    }break;
    case 2:{

    }break;
    default:{

    }

    }
    return 0;
}
