import QtQuick 2.15
import QtQuick.Window 2.15
import TaoQuick 1.0
import Qt.labs.settings 1.0
import "./QML/Pane"



Item {
    id: rootBackground
    width: 1440
    height: 960

    //signal   changeScreenStatus(bool isFullScreen)
    property int      menuPaneFlag: 0   //主菜单第几个
    property int   subMenuPaneFlag: 0   //子菜单第几个
    property int  mainBobyPaneFlag: 0   //内容页面第几个
    property bool       fullscreen: false
    Settings{  //设置绑定
        property alias rootBackground_menuPaneFlag: rootBackground.menuPaneFlag
        property alias rootBackground_subMenuPaneFlag: rootBackground.subMenuPaneFlag
        property alias rootBackground_mainBobyPaneFlag: rootBackground.mainBobyPaneFlag

        property alias subMenuPane_width: subMenuMainBoobyLine.x
    }


    //中间的背景图片
    CusImage {
        id: bgImg
        source: "qrc:/Images/Window/flower.jpg"
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        opacity: 0.1
    }
    // 是最上面的框框 我吐了
    TitlePane {
        id: title
        width: parent.width
        height: 30
    }
    //除上面的框框部分,即下面
    Item {
        id: content
        width: parent.width
        anchors {
            top: title.bottom
            bottom: parent.bottom
        }
        //这个才是小花花
        CusFPS {
            anchors {
                right: parent.right
                top: parent.top
                rightMargin: 5
            }
        }
        MenuPane{
            id:menuPane
            width: 40
            height: parent.height
            anchors.left: parent.left
        }
        Item{
            id:rightPaneItem
            height: parent.height
            anchors{
                left:  menuPane.right
                right:  parent.right
            }
        SubMenuPane{
            id:subMenuPane
            width: subMenuMainBoobyLine.x
            height: parent.height
        }
        Rectangle{
            id:subMenuMainBoobyLine
            x:200
            width: 5
            height: parent.height
            color: "#DDDDDD"
            MouseArea{
                id: subMenuMouseArea
                anchors.fill: parent
                property int lastX: 0
                hoverEnabled: true;
                cursorShape: (containsMouse
                              ?Qt.SplitHCursor
                              :Qt.ArrowCursor);
                //
                onPressedChanged: {
                    //按下鼠标记录坐标
                    if(containsPress){
                        lastX = mouseX
                        //console.log("lastX="+ lastX)
                    }

                }
                //
                onPositionChanged: {
                    if(pressed){
                        if(parent.x>=0 && parent.x+parent.width <= rightPaneItem.width){
                        parent.x += mouseX - lastX
                        //console.log("width="+ rightPaneItem.width)
                        }
                        if(parent.x<0){
                            parent.x=0
                        }
                        //console.log("width="+ rightPaneItem.width)


                    }
                }
            }
        }
        MainBobyPane{
            id: mainBobyPane
            height: parent.height
            width: parent.width-subMenuMainBoobyLine.x-subMenuMainBoobyLine.width
            anchors.right: parent.right
        }
        }


    }







}
