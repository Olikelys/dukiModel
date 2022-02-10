#ifndef RDATAENGABSTRACT_H
#define RDATAENGABSTRACT_H

#include <QObject>



class RDataEngAbstract :public QObject
{
    Q_OBJECT
public:
    explicit RDataEngAbstract(QObject *parent = nullptr);
    ~RDataEngAbstract();

    virtual int UnPack(QByteArray * unPackDataBuffer) = 0;
    virtual QByteArray* Pack(QByteArray* packDataBuffer) = 0;


};

#endif // RDATAENGABSTRACT_H
