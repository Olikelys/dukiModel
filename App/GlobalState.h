#ifndef GLOBALSTATE_H
#define GLOBALSTATE_H
/********************************************************************************************************************
 *
 *
 *
 *    用来维护全局 运行的状态如 启动时间 连接时间 消息总数 消息帧率  图像帧率
 *
 *
 *
 *
 *
 *
 *
 *
 * ********************************************************************************************************/

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>



class GlobalState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString runTime READ runTime NOTIFY RunTimeChanged);
    Q_PROPERTY(QString linkTime READ linkTime NOTIFY LinkTimeChanged);
    Q_PROPERTY(int totalMessageNumber READ totalMessageNumber NOTIFY TotalMessageNumberChanged);
    Q_PROPERTY(int totalImageNumber READ totalImageNumber NOTIFY TotalImageNumberChanged);
    Q_PROPERTY(float messageFps READ messageFps NOTIFY MessageFpsChanged);
    Q_PROPERTY(float imageFps READ imageFps NOTIFY ImageFpsChanged);



public:
    explicit GlobalState(QObject *parent);
    explicit GlobalState();
    ~GlobalState();
    static GlobalState *Instace();



    Q_INVOKABLE QString runTime();
    Q_INVOKABLE QString linkTime();
    Q_INVOKABLE int     totalMessageNumber();
    Q_INVOKABLE int     totalImageNumber();
    Q_INVOKABLE float   messageFps();
    Q_INVOKABLE float   imageFps();

    void AddOnceMessage();    //添加一次 消息
    void AddOnceImage();      //添加一次 图像
    void StartLinkTimer();    //
    void StopLinkTimer();

signals:
    void RunTimeChanged();
    void LinkTimeChanged();
    void TotalMessageNumberChanged();
    void TotalImageNumberChanged();
    void MessageFpsChanged();
    void ImageFpsChanged();

private:
   void timerEvent( QTimerEvent * event ) override;


private:
    QTime  m_RunTime;  // 运行时间
    QTime  m_RunStartTime;  //运行开始的时间
    QTime  m_LinkTime; //连接时间
    QElapsedTimer *m_LinkStartTime = nullptr; //连接启动时间
    int    m_TotalMessageNumber;   //消息总数
    int    m_TotalImageNumber;   //图像总数
    float  m_MessageFps;         //消息帧   一秒钟发了多少就是多少帧
    float  m_ImageFps;          //图像帧
    //int    m_BufferMessageNumber; // 缓存消息数
   // int    m_BufferImageFPs;      //缓存图片数 这个缓存指的是没有加进总数的数量

    static GlobalState* m_this ;





};


















#endif // GLOBALSTATE_H
