#include <QDebug>
#include "RProEngManager.h"
#include "RConnectManager.h"

RProEngManager * RProEngManager::m_this = nullptr;

RProEngManager::RProEngManager(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)
    m_this = this;
    m_RProEng = new RProEng(this);


    connect(this,SIGNAL( sigRead(QByteArray*) ),this,SLOT(Read(QByteArray*) ) );

}
RProEngManager::~RProEngManager()
{
qDebug()<<"析构RProEngManager";
}

RProEngManager* RProEngManager::Instance()
{
    return m_this;
}



void RProEngManager::Read(QByteArray* qByteArrayBuffer)
{
    m_RProEng->Read(qByteArrayBuffer);

}
