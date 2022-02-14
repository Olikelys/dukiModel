#include "GlobalState.h"
#include <QDebug>


GlobalState* GlobalState::m_this = nullptr;

GlobalState::GlobalState(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)
    m_this = this;
    startTimer(1000); //一秒一次
    m_RunTime.setHMS(0,0,0); // = QTime::currentTime(); //开机直接启动
    m_RunStartTime.restart();
    m_TotalMessageNumber = 0;
    m_TotalImageNumber = 0;
    m_MessageFps = 0 ;
    m_ImageFps = 0 ;
}
GlobalState::GlobalState()
{
    m_this = this;
    startTimer(1000); //一秒一次
    m_RunTime.setHMS(0,0,0); // = QTime::currentTime(); //开机直接启动
    m_RunStartTime.start();
    m_TotalMessageNumber = 0;
    m_TotalImageNumber = 0;
    m_MessageFps = 0 ;
    m_ImageFps = 0 ;

}
GlobalState::~GlobalState()
{

}
GlobalState* GlobalState::Instace()
{
    if(m_this == nullptr)
    {
        m_this = new GlobalState();
    }
    return m_this;
}

/**********************************************************************************/

void GlobalState::AddOnceMessage()
{
    m_MessageFps++;
}
void GlobalState::AddOnceImage()
{
    m_ImageFps++;
}
void GlobalState::StartLinkTimer()
{
    m_LinkTime.setHMS(0,0,0);
    m_LinkStartTime = new QElapsedTimer;
    m_LinkStartTime->start();
}
void GlobalState::StopLinkTimer()
{
    m_LinkTime.setHMS(0,0,0);
    delete m_LinkStartTime;
    m_LinkStartTime = nullptr;
}




/**********************************************************************************************/

void GlobalState::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    emit MessageFpsChanged();
    emit ImageFpsChanged();
    m_TotalMessageNumber +=m_MessageFps;
    m_MessageFps= 0;
    m_TotalImageNumber +=m_ImageFps;
    m_ImageFps = 0;
    //更新 运行时间
    m_RunTime.setHMS(0,0,0);
    m_RunTime = m_RunTime.addMSecs( m_RunStartTime.elapsed() );

    //更新 连接时间
    if(m_LinkStartTime != nullptr)
    {
        m_LinkTime.setHMS(0,0,0);
        m_LinkTime = m_LinkTime.addMSecs( m_LinkStartTime->elapsed() );
        emit LinkTimeChanged();
    }
    emit RunTimeChanged();
    emit TotalMessageNumberChanged();
    emit TotalImageNumberChanged();


    //qDebug()<<"m_TotalMessageNumber"<<m_TotalMessageNumber;
    //qDebug()<<m_RunTime.addMSecs( m_RunStartTime.elapsed() ).toString("hh-mm-ss");
    //qDebug()<<m_LinkTime.toString("hh-mm-ss");
}


QString GlobalState::runTime()
{
     return m_RunTime.toString("hh:mm:ss") ;
}

QString GlobalState::linkTime()
{
     return m_LinkTime.toString("hh:mm:ss") ;
}
int GlobalState::totalMessageNumber()
{
    return m_TotalMessageNumber;
}
int GlobalState::totalImageNumber()
{
    return m_TotalImageNumber;
}
float GlobalState::messageFps()
{
    return m_MessageFps;
}
float GlobalState::imageFps()
{
    return m_ImageFps;
}



