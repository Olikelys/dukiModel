#ifndef RCONNECTABSTRACT_H
#define RCONNECTABSTRACT_H
#include <QObject>




namespace RLink {

class RConnectAbstract : public QObject
{
    Q_OBJECT

public:
    explicit RConnectAbstract(QObject *parent = nullptr);



public:
    virtual int Connect() = 0;
    virtual int DisConnect() = 0;
    virtual int Read() = 0;
    virtual int Write() = 0;



};







}





#endif // RCONNECTABSTRACT_H



