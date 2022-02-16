import QtQuick 2.0
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15

Item {
    width: statusPane.width
    clip: true


    GridLayout{
        anchors.centerIn: parent
        columns: 6*150+50 <parent.width ? 6 : 3
        rowSpacing: 10

        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_runTime
                width: parent.width
                height: parent.height
                color: "#66CCCC"
                Text {
                    id: itemRunTime
                    anchors.centerIn: parent
                    color: "white"
                    text:"工作时间:"+globalState.runTime
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_runTime
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_runTime
            }
        }
        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_linkTime
                width: parent.width
                height: parent.height
                color: "#6699CC"
                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text:"连接时间:"+globalState.linkTime
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_linkTime
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_linkTime
            }
        }
        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_totalMessageNumber
                width: parent.width
                height: parent.height
                color: "#FF99CC"
                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text:"消息总数:"+globalState.totalMessageNumber
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_totalMessageNumber
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_totalMessageNumber
            }
        }
        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_messageFps
                width: parent.width
                height: parent.height
                color: "#FF9900"
                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text:"消息fps:"+globalState.messageFps
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_messageFps
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_messageFps
            }
        }
        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_totalImageNumber
                width: parent.width
                height: parent.height
                color: "#993366"
                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text:"图像总数:"+globalState.totalImageNumber
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_totalImageNumber
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_totalImageNumber
            }
        }
        Item{
            width: 150
            height: 30
            Rectangle{
                id: sPIG_imageFps
                width: parent.width
                height: parent.height
                color: "#CC3399"
                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text:"图像fps:"+globalState.imageFps
                }
                radius: 8
            }
            DropShadow{
                anchors.fill: sPIG_imageFps
                radius: 8.0
                samples: 16
                color: "#dd000000"
                source: sPIG_imageFps
            }
        }




    }


//    GridView{
//        id:sP_GridView
//        anchors.fill: parent
//        model: sP_ListModel
//        delegate: sP_GridDelegate
//    }

//    ListModel{
//        id: sP_ListModel
//        ListElement{
//            textVal : globalState_RunTime
//            rectColor: "#a8cd98"
//        }
//        ListElement{
//            textVal : globalState.linkTime
//            rectColor: "#a8cd98"
//        }
//        ListElement{
//            textVal : globalState.totalMessageNumber
//            rectColor: "#a8cd98"
//        }
//        ListElement{
//            textVal : globalState.messageFps
//            rectColor: "#a8cd98"
//        }
//        ListElement{
//            textVal : globalState.totalImageNumber
//            rectColor: "#a8cd98"
//        }
//        ListElement{
//            textVal : globalState.imageFps
//            rectColor: "#a8cd98"
//        }
//    }
//    Component{
//        id:sP_GridDelegate
//        Item{
//            width: 150
//            height: 30
//            Rectangle{
//                id:sPGD_ItemRec
//                anchors.centerIn: parent
//                color: data.rectColor
//                Text {
//                    anchors.centerIn: parent
//                    color: "white"
//                    text: data.textVal
//                }
//            }
//            DropShadow{
//                anchors.fill: sPGD_ItemRec
//                radius: 8.0
//                samples: 16
//                color: "#dd000000"
//                source: sPGD_ItemRec
//            }
//        }
//    }


}
