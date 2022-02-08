#ifndef RPROENG_H
#define RPROENG_H
#include "RProEngManager.h"

#define PUSH 0X01
#define REQUEST 0X02
#define REPLY 0X03
#define KEEPALIVE 0X04
#define ERRER  0x05


#define CHARTTOUINT32(x1,x2,x3,x4)  (x1 & 0x000000ff)|(x2 & 0x0000ff00)|(x3 & 0x00ff0000)|(x4 & 0xff000000)
//#define UINT32TOCHART(c1,c2,c3,c4,u32)   c1= u32 & 0xff; c2 = (u32>>8) & 0xff; c3 = (u32>>16) & 0xff; c4 = (u32>>24) & 0xff;

class RProEng :public QObject
{
    Q_OBJECT
public:
    explicit RProEng(QObject *parent = nullptr);
            ~RProEng();

signals:

public :
    int Read(QByteArray * qByteArrayBuffer);    //接收数据的接口



private:
    //int SplitFrame();    //分离帧：数据流的切分，切成一帧 防止粘包粘包断包
    //int ParseMsg();      //进行协议解析
    //int ParseData();     //扔给数据引擎解析



public:
QByteArray m_revbuffer;  //用来存储缓存数据的

QByteArray flagheader = QByteArray::fromHex("be90");
quint32    datalength;
char       datatype ;


};















#endif // RPROENG_H
