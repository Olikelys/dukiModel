#include <QDebug>
#include "RProEngManager.h"
#include "RConnectManager.h"

RProEngManager * RProEngManager::m_this = nullptr;

RProEngManager::RProEngManager(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)
    m_this = this;
    m_RProEng = new RProEng();
    m_RProEng->moveToThread(&m_RProEngThread);
    m_RDataEngDefault = new RDataEngDefault();
    m_RDataEngDefault->moveToThread(&m_RProEngThread);
    connect(this,SIGNAL( sigRead(QByteArray*) ),m_RProEng, SLOT( Read(QByteArray*) ));
    m_RProEngThread.start();

}
RProEngManager::~RProEngManager()
{
qDebug()<<"析构RProEngManager";
m_RProEngThread.wait();
m_RProEngThread.deleteLater();
delete m_RDataEngDefault;
delete m_RProEng;

}

RProEngManager* RProEngManager::Instance()
{
    return m_this;
}




