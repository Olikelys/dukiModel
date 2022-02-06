#ifndef RPROENGMANAGER_H
#define RPROENGMANAGER_H
#include <QObject>
#include "Bridge.h"


class RProEngManager: public QObject
{
    Q_OBJECT
public:
    explicit RProEngManager(QObject *parent);
            ~RProEngManager();
};




#endif // RPROENGMANAGER_H
