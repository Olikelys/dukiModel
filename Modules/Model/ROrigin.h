#ifndef RORIGIN_H
#define RORIGIN_H
/********************************************************
 *
 *   奶奶的 qt的 moc不支持 泛型编程  只能用QVariant了
 *
 *
 *
 *
 * **************************************************/

#include <QObject>
#include <QVariant>

class ROrigin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString val READ val WRITE  setVal NOTIFY valChanged)

public:
    explicit ROrigin();
    explicit ROrigin(QObject *parent);
             ROrigin(const QString type,const QString name,const QString val);  //这个和上一个构造函数是老的不能用了
             ROrigin(const quint8 type,const QString date,const QString name,const QVariant val);
             ROrigin(const quint8 type,const QString date,const QString name,const QByteArray *val);//事实证明指针太危险了还是引用吧
    ~ROrigin();


    quint8  htype() const;
    QString type() const;
    QString date() const;
    QString name() const;
    QString &name() ;
    QString val()  const;
    void setType(const QString &type);
    void setDate(const QString &date);
    void setName(const QString &name);
    void setVal(const QString &val);   //这个单单设置 m_val 本质上没有更新mval;
    void setVal(const QVariant val );   //
signals:
    void typeChanged();
    void dateChanged();
    void nameChanged();
    void valChanged();

private:
    QString m_type;                //这里 type 可以整成键值对的那种
    QString m_date;
    QString m_name;
    QString m_val;                 // val 也是

    quint8 mtype;
    QVariant mval;
    QVariant * mpval = nullptr;


};











#endif // RORIGIN_H
