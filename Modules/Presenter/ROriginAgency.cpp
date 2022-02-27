#include "ROriginAgency.h"
#include "RModelManager.h"

ROriginAgency::ROriginAgency(QObject *parent )
{
    Q_UNUSED(parent)
       m_AgencyType ="noType";
       m_AgencyName ="noName";
       m_AgencyVal  = "noval";
}

QVariant ROriginAgency::agencyVal() const
{
    return m_AgencyVal;
}
void ROriginAgency::setAgencyVal(const QVariant val)
{
    m_AgencyVal = val;
    emit agencyValChanged();
}

//设置代理
bool ROriginAgency::setAgency( QString type, QString name)
{
    if(m_AgencyType == "noType" && m_AgencyName == "noName") //如果还没有设置
    {
        int index = RModelManager::Instance()->rOriginModel()->SequentiaSearch(type,name);
        if(index == -1){return 0;}
        m_AgencyName = name;
        m_AgencyType = type;
        setAgencyVal(RModelManager::Instance()->rOriginModel()->getOrigin(index)->agencyVal());//绑定顺带更新一下
        connect(RModelManager::Instance()->rOriginModel()->getOrigin(index),\
                SIGNAL( agencyValChanged(QVariant&) ),\
                this,\
                SLOT(slotSetAgencyVal( QVariant&) ) );
       // m_AgencyVal = RModelManager::Instance()->rOriginModel()->getOrigin(index)->val();
    }
    else if(type == m_AgencyType && name == m_AgencyName)//如果已经是当前的代理了
    {

    }
    else//新的
    {
        int index = RModelManager::Instance()->rOriginModel()->SequentiaSearch(m_AgencyType,m_AgencyName);
        disconnect(RModelManager::Instance()->rOriginModel()->getOrigin(index),\
                SIGNAL( agencyValChanged(QVariant&) ),\
                this,\
                SLOT(slotSetAgencyVal(QVariant&) ) );
        index = RModelManager::Instance()->rOriginModel()->SequentiaSearch(type,name);
        if(index == -1){return 0;}
        m_AgencyName = name;
        m_AgencyType = type;
        setAgencyVal(RModelManager::Instance()->rOriginModel()->getOrigin(index)->agencyVal());//绑定顺带更新一下
        connect(RModelManager::Instance()->rOriginModel()->getOrigin(index),\
                SIGNAL( agencyValChanged(QVariant&) ),\
                this,\
                SLOT(slotSetAgencyVal( QVariant&) ) );
    }
    return 1;

}

//这个是代理连接的槽
void ROriginAgency::slotSetAgencyVal( QVariant& val)
{
    setAgencyVal(val);

}
