#ifndef RCONNECTMANAGER_H
#define RCONNECTMANAGER_H
/**
 * 这个是连接的 对外提供两个接口  1.发送函数（不是槽）RConnectManager::Write(QByteArray&) 2.通知读取数据信号 sigReadBuffer(QByteArray*)
 *            一些小细节 当前连接状态，数据接口，单独建了一个连接的线程，有个bug是线程之间的交互最好是通过信号槽机制
 *
 *            接收数据流程：两种思路
 *            （1）：对应的工作类接收到数据发送readyread信号（这个信号是系统提供的），对数据进行接收得到QByteAray地址，
 *                  然后信号sigReadBuffer(QByteArray*)向上播到Manager类的信号sigReadBuffer(QByteArray*)，
 *                  又Manager类播到ProEngManager类的sigRead(...),进而连接到 Read(...)槽函数
 *                  这个的为了逻辑性，目前是这个,看性能情况换下面一个
 *            （2）：对应的工作类接收到数据发送readyread信号（这个信号是系统提供的）,直接发送信号sigReadBuffer(QByteArray*)到
 *                  RProEng工作类
 *
 *
 *            发送数据流程:
 *            这个简单了，直接单例化然后调用RLink::RConnectManager::Instance->sigWrite(QByteArray&)，这个函数发送一个信号告诉具体的工作类来发送
 * */



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
static RConnectManager* Instance();
~RConnectManager();

//串口部分
signals:
    void sigGetSerialPortName();
    void sigSetSerialPortName(QStringList serialPortNameList);
    void sigReadyRead();
    void sigWrite(QByteArray& writebuffer);
public slots:

public:


//UDP部分


//继承来的
public:
Q_INVOKABLE virtual int Connect();
Q_INVOKABLE         int Connect(QString portName,QString baudRate,QString dataBits,QString parity,QString stopBits,QString flowControl);
Q_INVOKABLE virtual int DisConnect();
Q_INVOKABLE virtual int Read();     //这个没有用
Q_INVOKABLE virtual int Write();    //这个也没有用
Q_INVOKABLE slots   int Write(QByteArray& writebuffer); //好了我知道这个没有用了




//全局
signals:
    void connectDataSourcesChanged(int m_connectDataSources);
    void connectStateChaged(int m_connectState);
    void sigReadBuffer(QByteArray* newQByteArraybuffer);
public:
    int ResetConnect();           //数据源切换时候重新连接信号
    int getConnectDataSources();
    void setConnectDataSources(int index);
    int getConnectState();
    void setConnectState(int state);
public slots:

public:
    Q_PROPERTY( int connectDataSources READ getConnectDataSources WRITE setConnectDataSources NOTIFY connectDataSourcesChanged );    //连接协议
    Q_PROPERTY( int connectState READ getConnectState WRITE setConnectState NOTIFY connectStateChaged);                    //连接状态





private:
    QThread m_connectThread;       //通信的线程 非指针
    int m_connectDataSources ;     //0为串口1为UDP2为本地数据
    int m_connectState;            //0未连接 1连接
    RConnectSerialPort *m_rConnectSerialPort =nullptr;
    static RConnectManager * m_this;
};

}









#endif // RCONNECTMANAGER_H
