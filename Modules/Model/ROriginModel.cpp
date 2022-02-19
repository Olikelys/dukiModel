#include "ROriginModel.h"
#include <QDebug>
#include "RModelManager.h"
ROriginModel::ROriginModel(QObject *parent)
    : QAbstractListModel(parent)
{

}
ROriginModel::~ROriginModel()
{
    qDeleteAll(m_ROrigins);
    m_ROrigins.clear();
}

/*********************** start  重写QAbstractListModel    *********************************************/




QVariant ROriginModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (section) {
    case 0: {
        return QVariant("类型");
    }break;
    case 1:{
        return QVariant("名称");
    }break;
    case 2:{
        return QVariant("值");
    }break;
    default:{
        return QVariant("未知");
    }
    }
}
int ROriginModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return m_ROrigins.count();
    // FIXME: Implement me!
}
QVariant ROriginModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    ROrigin* rorigin = m_ROrigins[index.row()];
    switch (role) {
    case ROriginRoles::TypeRole:{
        return rorigin->type();
    }break;
    case ROriginModel::DateRole:{
        return rorigin->date();
    }
    case ROriginRoles::NameRole:{
        return rorigin->name();
    }break;
    case ROriginRoles::ValRole:{
        return rorigin->val();
    }break;
    default:{
        return QVariant();
    }
    }

}
bool ROriginModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i = 0;i<count;i++)
    {
        ROrigin* rorigi = new ROrigin();
        m_ROrigins << rorigi;
    }
    endInsertRows();
    return 0;
}
bool ROriginModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for(int i =row; i<count;i++)
    {
        m_ROrigins.removeAt(i);
    }
    endRemoveRows();
    return 0;
}
QHash<int,QByteArray> ROriginModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[DateRole] = "date";
    roles[NameRole] = "name";
    roles[ValRole ] = "val";
    return roles;
}

/****************** end  重写 QAbstractListModel**********************************************/




/************************************************************************************/



void ROriginModel::addROrigin( ROrigin *rorigin)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_ROrigins << rorigin;
    endInsertRows();
}

int ROriginModel::SequentiaSearch( const QString & type ,const QString & name)const
{
    for(int index =0; index < m_ROrigins.count();index++)
    {
        if(m_ROrigins[index]->name()  == name )
        {
            if(m_ROrigins[index]->type() == type)
            {
                return index;
                qDebug()<<index;
            }
        }
    }
    return -1;
}
int ROriginModel::SequentiaSearch(const quint8 & type ,const QString & name)const
{
    for(int index =0; index < m_ROrigins.count();index++)
    {
        if(m_ROrigins[index]->htype()  == type )
        {
            if(m_ROrigins[index]->name() == name)
            {
                return index;
                qDebug()<<index;
            }
        }
    }
    return -1;
}


int ROriginModel::UpDateVal(const int index , const QString time ,const QVariant  val)
{
    m_ROrigins[index]->setDate(time);
    m_ROrigins[index]->setVal(val);
    return 0;
}
int ROriginModel::UpDateVal(const int index , const QString time , QByteArray * val)
{
    m_ROrigins[index]->setDate(time);
   // m_ROrigins[index]->setVal(val);
    Q_UNUSED(val)
    return 0;
}






/**********************************************************************/
int ROriginModel::ROriginModel_unPackROrigin(ROrigin *tempOrigin)
{
    int tempindex =  SequentiaSearch(tempOrigin->htype(),tempOrigin->name());
   // qDebug()<<"到rOriginModel了"<<tempindex<<tempOrigin->htype()<<tempOrigin->date()<<tempOrigin->name()<<tempOrigin->val();
    if(tempindex == -1)
    {
        addROrigin(tempOrigin);
    }
    else
    {
       beginResetModel();
       UpDateVal(tempindex,tempOrigin->date(),tempOrigin->val() );
       endResetModel();
       delete  tempOrigin;
    }
    return 0;
}
