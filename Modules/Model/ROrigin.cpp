#include"ROrigin.h"

ROrigin::ROrigin()
{
    m_type = "noType";
    m_name = "noName";
    m_val  = "noVal";
}
ROrigin::ROrigin(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)
}
ROrigin::ROrigin(const QString &type,const QString &name,const QString &val)
{
    m_type = type;
    m_name = name;
    m_val  = val;
}
ROrigin::~ROrigin()
{

}


QString ROrigin::type() const
{
    return m_type;
}
QString ROrigin::name() const
{
    return m_name;
}
QString ROrigin::val() const
{
    return m_val;
}
void ROrigin::setType(const QString &type)
{
    m_type = type;
}
void ROrigin::setName(const QString &name)
{
    m_name = name;
}
void ROrigin::setVal(const QString &val)
{
    m_val = val;
}
