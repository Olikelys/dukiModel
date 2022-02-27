#ifndef RORIGINAGENCY_H
#define RORIGINAGENCY_H
#include <QObject>
#include <QVariant>
#include <QtQml>

//加一个代理 来连接model 和 控件
//具体:每一个控件至少持有一个代理，并将属性绑定到代理的val上 model的val值改变通知这个代理
#define RORIGINAGENCY_INITIALIZA {qmlRegisterType<ROriginAgency>("RLink",1,0,"ROriginAgency");}


class ROriginAgency  :public QObject
{
    Q_OBJECT
public:
    explicit ROriginAgency(QObject *parent = nullptr);

    Q_PROPERTY(QVariant agencyVal READ agencyVal WRITE setAgencyVal NOTIFY agencyValChanged)

    QVariant agencyVal()const;
    void setAgencyVal(const QVariant val);

public :
Q_INVOKABLE bool setAgency(QString type,  QString name);//设置指向model的引索


signals:
    void agencyValChanged();

public slots: void slotSetAgencyVal( QVariant& val);  //通知到的



private:
    QString m_AgencyType;
    QString m_AgencyName;
    QVariant m_AgencyVal;
};












#endif // RORIGINAGENCY_H
