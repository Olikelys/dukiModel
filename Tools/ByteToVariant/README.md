记录个大坑



内存中  int short 等等基本都是小端存储，网络传输是大端（指先传高位再传低位）

但是很少有人知道具体类型在内存中怎么存储

float  最高位为符号位，依次7位为指数位，后面才是整数位

char  uchar 都是ascii编码的

short ushort int uint long ulong 在内存中都以补码存储的



再来讲讲格式化，这个是区别于内存的编码的 printf用的很爽

如int = 13;

内存中  0xff ff ff 0c (高位默认全1)但是一般传输都是格式化这可太贱了

printf出来的是  30 43  在acsii中  0x30代表1 0x43代表3妈的啊  



所有byte 转过来

```
                    int tempint ;
                    char c1 =0x0c;
                    char c2 =0xff;
                    char * p = (char *)& tempint;
                    *(p+0) =    c1;
                    *(p+1) =    c2;
```

qt 调试  这样就可以看到 hex了

```
qDebug() << "tempint : " <<(void *) tempChar;
```