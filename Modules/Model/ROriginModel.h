#ifndef RORIGINMODEL_H
#define RORIGINMODEL_H

#include <QAbstractListModel>
#include "ROrigin.h"

class ROriginModel : public QAbstractListModel
{
    Q_OBJECT
    enum ROriginRoles {
        TypeRole = Qt::UserRole + 1,
        DateRole,
        NameRole,
        ValRole
    };

public:
    using QAbstractListModel::QAbstractListModel;
    //explicit ROriginModel(QObject *parent = nullptr);
    ~ROriginModel();


    //这些是重写QAbstranctListModel的
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    QHash<int,QByteArray> roleNames() const override;


public slots :
    int ROriginModel_unPackROrigin(ROrigin *tempOrigin);


    //......
    void addROrigin( ROrigin *rorigin);       //添加一条数据
    Q_INVOKABLE int SequentiaSearch(const QString & type ,const QString & name)const;   //顺序查找一条数据
    Q_INVOKABLE int SequentiaSearch(const quint8 & type ,const QString & name)const;
    Q_INVOKABLE int searchTypeName(QString type,QString name);          //妈的这个是真的操蛋 js不支持函数重载排查了好久
    Q_INVOKABLE int UpDateVal(const int index , const QString time ,const QVariant  val);
    Q_INVOKABLE int UpDateVal(const int index , const QString time , QByteArray * val);
    Q_INVOKABLE QStringList  TypeFilter(QString type);
    //Q_INVOKABLE QVariant getOrigin(int index);  //妈的返回一个私有对象的指针给js用太危险了程序直接崩了
    Q_INVOKABLE ROrigin* getOrigin(int index);
    Q_INVOKABLE QVariant getOriginVal(int index); //这样  压根不能更新  妈的我加一个代理

//    Q_PROPERTY(QStringList roriginAgency READ roriginAgency WRITE setRoriginAgency NOTIFY roriginAgencyChanged)
//    QString rorginAgency();
//    signals: void roriginAgencyChanged();
//    int



private:
    QList<ROrigin *> m_ROrigins;

};

#endif // RORIGINMODEL_H
