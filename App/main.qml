import QtQuick 2.15
import QtQuick.Window 2.15
import TaoQuick 1.0
import Qt.labs.settings 1.0
import "./QML/Pane"
import "./QML/Dialog"



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


    // 是最上面的框框 我吐了
    TitlePane {
        id: titlePane
        width: parent.width
        height: 30
    }
    //除上面的框框部分,即下面
    Item {
        id: content
        width: parent.width
        anchors {
            top: titlePane.bottom
            bottom: parent.bottom
        }
//        //这个才是小花花  这个东西太吃CPU了
//        CusFPS {
//            anchors {
//                right: parent.right
//                top: parent.top
//                rightMargin: 5
//            }
//        }
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
                        if( subMenuPane.width<=700 &&  parent.x>=0 ){
                        parent.x += mouseX - lastX
                        //console.log("width="+ rightPaneItem.width)
                        }
                        if(parent.x<0){
                            parent.x=0
                        }
                        if(subMenuPane.width >= 700){
                            subMenuMainBoobyLine.x = 700
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


    Snackbar{
        id: snackbar
    }

// 这个玩意有点吃cpu
//    //按键点击的水花
//    ClickShow {
//        anchors.fill: parent
//        anchors.margins: 6
//    }

//    Component.onCompleted:{


//    }







}
