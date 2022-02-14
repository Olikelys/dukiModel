#include "RModelManager.h"

RModelManager * RModelManager::m_this = nullptr;

RModelManager::RModelManager()
{
   m_this= this;
}
RModelManager::RModelManager(QObject *parent)
{
    Q_UNUSED(parent)
    m_this= this;
}
RModelManager::~RModelManager()
{

}
RModelManager *RModelManager::Instance()
{
    return m_this;
}


ROriginModel * RModelManager::rOriginModel() const
{
    return originModel.get();
}
void RModelManager::setROriginModel(ROriginModel *rmodel)
{
    if( originModel.get() == rmodel)
    {
        return;
    }
    originModel.reset(rmodel);
}
