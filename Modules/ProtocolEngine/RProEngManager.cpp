#include <QDebug>
#include "RProEngManager.h"



RProEngManager::RProEngManager(QObject *parent)
    :QObject(parent)
{
    qDebug()<<"构造RProEngManager";
    Q_UNUSED(parent)
}
RProEngManager::~RProEngManager()
{
qDebug()<<"析构RProEngManager";
}
