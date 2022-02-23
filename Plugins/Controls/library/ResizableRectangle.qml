import QtQuick 2.0
import QtQuick.Controls 2.12
import TaoQuick 1.0

Rectangle {
    id:root
    color: "transparent"
    smooth: true
    antialiasing: true



    property string path: ""
    property string controlType: ""
    property string name: "右键双击改名字"
    property bool borderVisble: true               //边框是否可见
    property bool nameVisble: true
    x :100
    y :100
    width:   250
    height:  250
    rotation: 0
    //内部属性
    property color resizeBordercolor: "red"        //边框颜色
    property bool isMenu: false


    //对外信号
    signal clicked(real x, real y)
    signal rightDoubleClicked(real x, real y)
    signal leftDoubleClicked(real x, real y)
    signal rectAndRotation(int type,int val)   //实时修改这五个参数
    onXChanged:  if(isMenu){rectAndRotation(0,x)}
    onYChanged:  if(isMenu){rectAndRotation(1,y)}
    onWidthChanged: if(isMenu){rectAndRotation(2,width)}
    onHeightChanged: if(isMenu){rectAndRotation(3,height)}
    onRotationChanged: if(isMenu){rectAndRotation(4,rotation)}
    /****************         基类 拥有的上下文
    controlType:控件类型
    name:
    x:
    y:
    width:
    height:
    rotation:  旋转角度
    borderVisble:  边框是否可见
    nameVisble: 名字是否可见



*****************************************************************************************************************/
    //这个有颜色的框
    Rectangle {
        border.color: resizeBordercolor
        border.width: 2
        radius: resizeBorder.borderMargin
        anchors.fill: resizeBorder
        anchors.margins: resizeBorder.borderMargin + 2
        color: "transparent"
        visible: borderVisble || isMenu
    }
    //鼠标移动区域
    MouseArea {
        id: dragItem
        anchors.fill: resizeBorder
        anchors.margins: resizeBorder.borderMargin * 2
        cursorShape: isMenu ? Qt.SizeAllCursor :Qt.ArrowCursor
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        drag.target:   isMenu ? root: null
        drag.minimumX:0
        drag.maximumX:mainBobyPane.width-root.width
        drag.minimumY: 0
        drag.maximumY:mainBobyPane.height-root.height
        onClicked: {
            root.clicked(x, y)
        }
        onDoubleClicked: {
            if( mouse.button == Qt.RightButton)
            {
                root.rightDoubleClicked(x, y)
            }
            else{
                root.leftDoubleClicked(x, y)
            }

        }

   }
    //可以 调大小的框
    ResizeBorder{
       id: resizeBorder
       width: parent.width + borderMargin * 2
       height: parent.height + borderMargin * 2
       anchors.centerIn: parent
       visible: isMenu


       readonly property int borderMargin: 6 //边框大小
       property var controller: parent

       //这个是旋转的
       Rectangle {
           color: "red"
           width: parent.borderMargin * 1.6
           height: width
           radius: width / 2
           visible: true
           anchors {
               top: parent.top
               horizontalCenter: parent.horizontalCenter
               topMargin: -16
           }
           Image {
               id: rotateCursor
               source: "qrc:/Controls/library/Image/rotate.png"
               visible: rotateArea.containsMouse | rotateArea.pressed
               x: rotateArea.mouseX - width / 2
               y: rotateArea.mouseY - height / 2
           }
           MouseArea {
               id: rotateArea
               anchors.centerIn: parent
               width: parent.width * 2
               height: parent.height * 2
               hoverEnabled: true
               property int lastX: 0
               onContainsMouseChanged: {
                   if (containsMouse) {
                       cursorShape = Qt.BlankCursor
                   } else {
                       cursorShape = Qt.ArrowCursor
                   }
               }
               onPressedChanged: {
                   if (rotateArea.containsPress) {
                       lastX = mouseX
                   }
               }
               onPositionChanged: {
                   if (pressed) {
                       var t = root.rotation + (mouseX - lastX) / 5
                       t = t % 360
                       root.rotation = t
                   }
               }
           }
           ToolTip {
               id: toolTip
               x: rotateArea.mouseX + 30
               y: rotateArea.mouseY
               visible: rotateArea.pressed
               text: parseInt(resizeBorder.controller.rotation) + "°"
               background: Rectangle{
                   color: "#7f7f7f"
                   radius: 3
               }
           }
       }



   }

    function getBasic_ctx()
    {
        var ctx = {
            "path" : path,
            "controlType":controlType,
            "name":name,
            "borderVisble":borderVisble,
            "nameVisble":nameVisble,
            "x":x,
            "y":y,
            "width":width,
            "height":height,
            "rotation":rotation

        }
        return ctx
    }

    function setBasic_ctx(ctx)
    {
        path = ctx.path
        controlType = ctx.controlType
        name = ctx.name
        borderVisble = ctx.borderVisble
        nameVisble = ctx.nameVisble
        x = ctx.x
        y = ctx.y
        width = ctx.width
        height = ctx.height
        rotation = ctx.rotation
    }


}
