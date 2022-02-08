#ifndef RPROENGMANAGER_H
#define RPROENGMANAGER_H
#include <QObject>
#include "Bridge.h"
#include "RProEng.h"

class RProEng;

class RProEngManager: public QObject
{
    Q_OBJECT
public:
    explicit RProEngManager(QObject *parent = nullptr);
    ~RProEngManager();
    static RProEngManager* Instance();



signals:
    void sigRead(QByteArray * qByteArrayBuffer);

public slots:
    void Read(QByteArray * qByteArrayBuffer);

public:
    RProEng *m_RProEng = nullptr;
    static RProEngManager *m_this ;

};




#endif // RPROENGMANAGER_H









