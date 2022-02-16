#include "ROrigin.h"
#include "RProEng.h"
#include <QDebug>

ROrigin::ROrigin()
{
    m_type = "noType";
    m_date = "nodate";
    m_name = "noName";
    m_val  = "noVal";
}
ROrigin::ROrigin(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)
}
ROrigin::ROrigin(const QString type,const QString name,const QString val)
{
    m_type = type;
    m_date = "nodate";
    m_name = name;
    m_val  = val;
}
ROrigin::ROrigin(const quint8 type,const QString date,const QString name,const QVariant val)
{
    mtype = type;
    m_date = date;
    m_name = name;
    mval  = val;
    switch ( mtype ) {
    case RHEX:     {m_type="hex";m_val = mval.toByteArray().toHex();}break;
    case RSTRING:   {m_type="string"; m_val = mval.toString();}break;
    case RCHAR:    {m_type="char"; m_val = mval.toChar(); }break;
    case RUCHAR:    {m_type="uchar"; m_val = mval.toByteArray()  ; }break;
    case RSHORT:    {m_type="short"; m_val = mval.toString(); }break;
    case RUSHORT:    {m_type="ushort"; m_val = mval.toString(); }break;
    case RINT:    {m_type="int"; m_val = mval.toString(); }break;
    case RUINT:    {m_type="uint"; m_val = mval.toString(); }break;
    case RLONG:    {m_type="long"; m_val = mval.toByteArray(); }break;
    case RULONG:    {m_type="ulong"; m_val = mval.toString(); }break;
    case RFLOAT:    {m_type="float"; m_val = mval.toString(); }break;
    case RDOUBLE:    {m_type="double"; m_val = mval.toString(); }break;
    case RINT8:    {m_type="int8"; m_val = mval.toString(); }break;
    case RINT16:    {m_type="int16"; m_val = mval.toString(); }break;
    case RINT32:    {m_type="int32"; m_val = mval.toString(); }break;
    case RINT64:    {m_type="int64"; m_val = mval.toString(); }break;
    case RUINT8:    {m_type="uint8"; m_val = mval.toString(); }break;
    case RUINT16:    {m_type="uint16"; m_val = mval.toString(); }break;
    case RUINT32:    {m_type="uint32"; m_val = mval.toString(); }break;
    case RUINT64:    {m_type="uint64"; m_val = mval.toString(); }break;
    default:         {m_type ="no type";m_val = mval.toString();}
    }
    qDebug()<<"构造函数:"<<m_type<<m_date<<m_name<<m_val;
}
ROrigin::~ROrigin()
{

}


QString ROrigin::type() const
{
    return m_type;
}
QString ROrigin::date() const
{
    return m_date;
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
void ROrigin::setDate(const QString &date)
{
    m_date = date;
}
void ROrigin::setName(const QString &name)
{
    m_name = name;
}
void ROrigin::setVal(const QString &val)
{
    m_val = val;
}
