import QtQuick 2.0
import QtQuick.Controls 2.12
import TaoQuick 1.0

Rectangle {
    id:root
    color: "transparent"
    smooth: true
    antialiasing: true
    //rotation: 87

    width:   250
    height:  250
    property bool resizeBorderVisible : true       //边框是否可见
    property color resizeBordercolor: "red"        //边框颜色


    signal clicked(real x, real y)
    signal rightDoubleClicked(real x, real y)
    signal leftDoubleClicked(real x, real y)

   ResizeBorder{
       width: parent.width + borderMargin * 2
       height: parent.height + borderMargin * 2
       anchors.centerIn: parent
       visible: resizeBorderVisible


       readonly property int borderMargin: 10 //边框大小
       property var controller: parent





       //这个有颜色的框
       Rectangle {
           border.color: resizeBordercolor
           border.width: 2
           radius: parent.borderMargin
           anchors.fill: parent
           anchors.margins: parent.borderMargin + 2
           color: "transparent"
       }
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
       }

       //鼠标移动区域
       MouseArea {
           id: dragItem
           anchors.fill: parent
           anchors.margins: parent.borderMargin * 2
           cursorShape: Qt.SizeAllCursor
            acceptedButtons: Qt.LeftButton | Qt.RightButton
           drag.target: root
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
                   //console.debug("右键双击")
                   root.rightDoubleClicked(x, y)
               }
               else{
                   root.leftDoubleClicked(x, y)
               }

           }

      }

   }

}
