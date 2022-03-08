![image-20220308135520970](https://cdn.jsdelivr.net/gh/runhey/imgStg1/img/202203081355795.png)

# dukiModel -- 智能车一站式开发平台

+ dukiModel地址  [github](https://github.com/runhey/dukiModel)|[gitee](https://gitee.com/duki/dukimodel)
+ 软件下载   [地址](https://duki-model.oss-cn-chengdu.aliyuncs.com/dukiModel-win64-Beta1.0.0.rar)
+ 文档网站  [duki.cc](https://www.duki.cc/)
+ 文档项目 [github](https://github.com/runhey/duki-web)| [gitee](https://gitee.com/duki/duki-web)

### 一、简介

------

对标[VOFA+](https://vofa.plus/)。支持串口、UDP连接，为各位车友提供简便操作交互界面并展示反馈数据。基于控件可以高自由度配置UI界面，甚至可以自定义控件，满足各届赛题开发调试需求。除此之外还提供日志输出和数据的本地存储以便复盘运行状况。引入了分布式开发调试，插件形式实时数据交互，便捷开发。

### 二、主要特点

+ **分布式**
+ **多类型源数据**
+ **高灵活度控件**
+ **自定义指令**
+ **复盘系统**

### 三、项目说明

程序框架图

![dukiModel架构](https://cdn.jsdelivr.net/gh/runhey/imgStg1/img/202203081429799.png)

本项目使用Qt c++/qml进行开发(window 、5-15-2 、MinGW64构建工具)，影子构建即可

写得菜轻点喷，菜鸡准备考研所以是随缘更新了

**项目进度**

- [x] 协议设计

- [x] 串口接口
- [ ] UDP接口
- [ ] 数据持久化及复盘系统
- [x] 源数据引擎
- [ ] 指令模型
- [x] 日志输出
- [ ] 插件调试
- [x] 状态展示

下面是控件

- [ ] 按钮
- [ ] 开关
- [ ] 滑块
- [ ] 灯
- [ ] 图像
- [ ] 曲线
- [x] 能量槽
- [ ] 仪表

