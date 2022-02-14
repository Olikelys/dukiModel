#ifndef BRIDGE_H
#define BRIDGE_H
#include <QObject>
#include "RProEngManager.h"
#include "RModelManager.h"


/*
 这个类啥也不干，就连接个个模块的 信号 槽 */


class  RProEngManager;

class Bridge : public QObject
{
    Q_OBJECT;
public:
    explicit Bridge();
             Bridge(QObject *parent);
            ~Bridge();

public: int  ResetConnect();


public: RProEngManager *rProEngManager;
public: RModelManager  *rModelManager;

};



#endif // BRIDGE_H
