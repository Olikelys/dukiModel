import QtQuick 2.15
import QtQuick.Window 2.15
import TaoQuick 1.0
import Qt.labs.settings 1.0
import QtGraphicalEffects 1.0
import "./QML/Pane"
import "./QML/Dialog"


Rectangle {

   width: 1440
   height: 960
   color:"transparent"
   radius: 10
   clip: true
Rectangle {
    id: rootBackground
    anchors{
        fill:parent
        margins: view.isMax ? 10 :0
    }
    radius: 10
    clip: true

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




    //除上面的框框部分,即下面
    Item {
        id: content
        anchors.fill: parent
//        width: parent.width
//        anchors {
//            top: parent.bottom
//            bottom: parent.bottom
//        }
        MenuPane{
            id:menuPane
            width: 40
            height: parent.height
            anchors.left: parent.left
        }
        Rectangle{
            id:rightPaneItem
            color:"#eceff3"
            height: parent.height
            anchors{
                left:  menuPane.right
                right:  parent.right
            }

            //这个是一行移动分割线
            Item{
                id:subMenuMainBoobyLine
                x:200
                width: 10
                height: parent.height -120
                anchors.top: parent.top
                //radius: 2
                //color: "#F00097"
                opacity: 0.1
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

            SubMenuPane{
                id:subMenuPane
                width: subMenuMainBoobyLine.x
                height: parent.height
            }

            //标题栏
            TitlePane{
                id: titlePane
                height:50
                anchors{
                    top: parent.top
                    left: subMenuMainBoobyLine.right
                    right: parent.right
                }
            }

            //状态栏
            Rectangle{
                id:main_Rect11
                anchors{
                    top: mainBobyPane.bottom
                    topMargin: 20
                    right: parent.right
                }
                radius:80
                height: statusPane.height+radius
                width: statusPane.width + 20
            }
            Rectangle{
                id:main_Bect12
                anchors{
                    top: mainBobyPane.bottom
                    topMargin: 20
                    right: parent.right
                    bottom: parent.bottom

                }
                width: 100

            }
            StatusPane{
                id:statusPane
                height:100
                width: parent.width-subMenuMainBoobyLine.x-subMenuMainBoobyLine.width
                anchors{
                    bottom :parent.bottom
                    left: subMenuMainBoobyLine.right
                    right: parent.right
                }

            }


            //主体
            MainBobyPane{
                id: mainBobyPane
                anchors{
                    left: subMenuMainBoobyLine.right
                    right: parent.right
                    top: titlePane.bottom
                    bottom: statusPane.top
                    margins: 10
                    topMargin: 0
                }
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
}
