#ifndef RMODELMANAGER_H
#define RMODELMANAGER_H
/****************************************************************************************
 *
 *      统一管理 ROrigin源数据模型 和 RCommand指令模型
 *
 *
 *
 *
 *
 *
 *
 *
 * ***********************************************************************************/
#include "ROriginModel.h"


class RModelManager :public QObject
{
    Q_OBJECT
    Q_PROPERTY( ROriginModel* rOriginModel READ rOriginModel WRITE setROriginModel NOTIFY rOriginModelChanged)

public:
    explicit RModelManager(QObject *parent);
    RModelManager();
    ~RModelManager();
    static RModelManager* Instance();

    ROriginModel *rOriginModel() const;
    void setROriginModel(ROriginModel *rmodel);
signals:
    void rOriginModelChanged();

public:
    QScopedPointer<ROriginModel> originModel;


private:
    static RModelManager * m_this;

};


















#endif // RMODELMANAGER_H
