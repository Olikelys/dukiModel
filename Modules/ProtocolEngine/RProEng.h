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
#define BYTETO8(C1)        C1
#define BYTETO16(c1,c2)        ((c1 & 0x00ff)|(c2 & 0xff00))
#define BYTETO32(c1,c2,c3,c4)  ((c1 & 0x000000ff)|(c2 & 0x0000ff00)|(c3 & 0x00ff0000)|(c4 & 0xff000000))
#define BYTETO64(c1,c2,c3,c4,c5,c6,c7,c8)  ( (c1 & 0x00000000000000ff)| \
                                             (c2 & 0x000000000000ff00)| \
                                             (c3 & 0x0000000000ff0000)| \
                                             (c4 & 0x00000000ff000000)| \
                                             (c5 & 0x000000ff00000000)| \
                                             (c6 & 0x0000ff0000000000)| \
                                             (c7 & 0x00ff000000000000)| \
                                             (c8 & 0xff00000000000000) )


class RProEng :public QObject
{
    Q_OBJECT
public:
    explicit RProEng(QObject *parent = nullptr);
            ~RProEng();

signals:

public slots : int Read(QByteArray * qByteArrayBuffer);    //接收数据的接口



private:
    //int SplitFrame();    //分离帧：数据流的切分，切成一帧 防止粘包粘包断包
    //int ParseMsg();      //进行协议解析
    //int ParseData();     //扔给数据引擎解析



public:
QByteArray m_revbuffer;  //用来存储缓存数据的

QByteArray flagheader = QByteArray::fromHex("eb90");
quint32    datalength;
char       datatype ;
char       messagetype;


};









#define RHEX      0X01
#define RSTRING   0X02
#define RCHAR     0X03
#define RUCHAR    0X04
#define RSHORT    0X05
#define RUSHORT   0X06
#define RINT      0X07
#define RUINT     0X08
#define RLONG     0X09
#define RULONG    0X0A
#define RFLOART   0X0B
#define RDOUBLE   0X0C
#define RINT8     0X10
#define RINT16    0X11
#define RINT32    0X12
#define RINT64    0X13
#define RUINT8    0X14
#define RUINT16   0X15
#define RUINT32   0X16
#define RUINT64   0X17





#endif // RPROENG_H
