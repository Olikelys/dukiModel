import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import "./style.js" as Style
/*
    进度球控件
*/
Item{
    id:controlRoot

    //数据
    property real   value:0               //当前进度值(0~1)

    //文本样式
    property bool   textVisible:true                    //是否显示进度文本
    property int    textSize:canvas.width*0.2           //字体大小
    property color  textColor:Style.color_textBlack     //字体颜色
    property string textFamily:Style.string_textFamily  //字体族

    //波浪样式
    property int    spacing:5                       //外环到波浪的间距
    property color  bgColor:"white"                 //外环与波浪之间的背景颜色
    property int    borderWidth:8                   //外环宽度
    property color  borderColor:__currentWaveColor  //外环颜色
    property var    waveColorPolicy:[               //波浪颜色配置：value最大值,color达到最值时对应颜色
        {"value":0,"color":"transparent"},
        {"value":0.5,"color":Style.color_flatGreen},
        {"value":0.75,"color":Style.color_flatYellow},
        {"value":1,"color":Style.color_flatRed}
    ]
    property int    waveA:13                        //波浪振幅（影响波浪起伏高度）
    property int    waveSpeed:8                     //波浪速度（影响波浪动画速度）
    property bool   enableAnimation:true            //是否开启动画
    property int    animationTime:50                //动画更新频率

    //内部数据
    property color  __currentWaveColor          //当前波浪的颜色
    property int    __outerR:canvas.width/2-5   //外环半径
    property int    __innerR:canvas.width/2-5-borderWidth-spacing+8 //内部填充区域半径
    property int    __detalAngle: 0             //用于计算sinx(x+__detalAngle)，以形成波浪形状

    width: 150
    height: 150
    onValueChanged: {
        canvas.requestPaint()
    }

    Canvas{
        id: canvas
        height: Math.ceil(controlRoot.width,controlRoot.height)
        width: canvas.height
        anchors.centerIn: parent

        Text{
            anchors.centerIn: parent
            font.pixelSize: textSize
            font.family: textFamily
            color:textColor
            text: value*100+"%"
        }

        Timer{
            id: timer
            running: enableAnimation
            repeat: true
            interval: animationTime
            onTriggered:{
                __detalAngle+=waveSpeed
                canvas.requestPaint();
            }
        }

        onPaint: {
            var value
            if(controlRoot.value<0){
                value =0
            }else if(controlRoot.value>1){
                value =1
            }else{
                value = controlRoot.value
            }

            var ctx = getContext("2d");
            ctx.clearRect(0, 0, canvas.width, canvas.height);   //绘制前先清空画布

            //绘制外圈
            ctx.reset()
            ctx.beginPath();
            ctx.strokeStyle = borderColor;
            ctx.fillStyle = bgColor
            ctx.lineWidth = borderWidth
            ctx.arc(canvas.width/2, canvas.width/2, __outerR, 0, 2*Math.PI);
            ctx.stroke();
            ctx.fill()

            //在内部裁剪出一个圆形区域，用于填充颜色
            ctx.beginPath();
            ctx.arc(canvas.width/2, canvas.width/2, __innerR, 0, 2*Math.PI);
            ctx.clip();

            //计算波浪颜色
            var color
            for(var a in waveColorPolicy){
                if(value<=waveColorPolicy[a].value){
                    color = waveColorPolicy[a].color
                    break
                }
            }
            __currentWaveColor = color

            //绘制第一层波浪（浅色）
            ctx.save()
            ctx.translate(parent.width/2,parent.height/2)
            var y2 = __innerR-2*__innerR*value      //波纹高度的Y
            ctx.moveTo(-__innerR,0)
            ctx.beginPath()
            ctx.fillStyle = Qt.lighter(color,1.2)
            if(enableAnimation){
                for(var i2=0;i2<__innerR*2;i2++){
                    ctx.lineTo(-__innerR+i2,y2+waveA*Math.sin((i2+__detalAngle)*Math.PI/180+value*Math.PI-2*Math.PI))
                }
            }else{
                ctx.moveTo(-__innerR,y2)
                ctx.lineTo(__innerR,y2)
            }
            ctx.lineTo(__innerR,__innerR)
            ctx.lineTo(-__innerR,__innerR)
            ctx.closePath()
            ctx.fill()
            ctx.restore()

            //绘制第二层波浪（深色）
            ctx.save()
            ctx.translate(parent.width/2,parent.height/2)
            var y = __innerR-2*__innerR*value
            ctx.moveTo(-__innerR,0)
            ctx.beginPath()
            ctx.fillStyle = color
            if(enableAnimation){
                for(var i=0;i<__innerR*2;i++){
                    ctx.lineTo(-__innerR+i,y+waveA*Math.sin((i+__detalAngle)*Math.PI/180+20*value*Math.PI))
                }
            }else{
                ctx.moveTo(-__innerR,y)
                ctx.lineTo(__innerR,y)
            }
            ctx.lineTo(__innerR,__innerR)
            ctx.lineTo(-__innerR,__innerR)
            ctx.closePath()
            ctx.fill()
            ctx.restore()
        }
    }
}
