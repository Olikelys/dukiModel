import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.15


Item {

    anchors.fill: parent
    clip: true


    DropShadow
    {
        anchors.fill: dSV_R
        radius: 8.0
        samples: 16
        color: "#7b40f2"
        source: dSV_R
     }
    Rectangle{
        id:dSV_R
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 10
            topMargin: 22
        }
        height: 120
        color: "#7b40f2"//"transparent"
        radius: 20
    }

    Item {
        id: dSVHeaderItem
        anchors.fill: dSV_R
        clip: true
        GridLayout{
            id:dSVHI_DataGridLayout
            anchors{
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 14
                top: parent.top
                topMargin: 14
            }
            Item{
                width: 60
                height: 20
            Text{
                anchors.verticalCenter: parent.verticalCenter
                text: "源数据"
                font.pixelSize : 22
                font.bold: true
                color: "white"
            }}
            Image {
                width: 18
                height: 18
                Layout.alignment:Qt.AlignRight
                source: "qrc:/Images/Window/more_white.png"
            }
        }
        Rectangle{
            id:dSVHI_RecatgleLine1
            height: 4
            anchors{
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
                top: dSVHI_DataGridLayout.bottom
                topMargin: 14
            }
            radius:4
            color: "#DDDDDD"
        }

        Row {
            id: dSVHI_TotalItem
            anchors{
                top: dSVHI_RecatgleLine1.top
                topMargin: 18
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
            }
            Text{
                text: "变量总数:"
                font.bold: true
                font.pixelSize : 18
                color: "white"
                width: 80
                height: 30
            }
            Text{
                text: "?"
                font.bold: true
                font.pixelSize : 18
                color: "white"
                width: 40
                height: 30
            }
            Image {
                width: 18
                height: 18
                source: "qrc:/Images/Window/updata.png"
            }
        }
    }


    Item {
        id: dSVHeadDateItem
        anchors{
            top: dSV_R.bottom
            topMargin: 20
            right: dSV_R.right
            left: dSV_R.left
        }
        height: 38
        Row{
            spacing: 10
            Rectangle{
                border.color: "#7b40f2"
                border.width: 2
                height: dSVHeadDateItem.height
                width: 100
                radius: 10
                color: "transparent"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize : 18
                    font.bold: true
                    text: "变量类型"
                    color: "white"
                }
            }
            Rectangle{
                border.color: "#7b40f2"
                border.width: 2
                height: dSVHeadDateItem.height
                width: 120
                radius: 10
                color: "transparent"
                Text {
                    font.pixelSize : 18
                    font.bold: true
                    anchors.centerIn: parent
                    text: "上次更新"
                    color: "white"
                }
            }
            Rectangle{
                border.color: "#7b40f2"
                border.width: 2
                height: dSVHeadDateItem.height
                width: 120
                radius: 10
                color: "transparent"
                Text {
                    font.pixelSize : 18
                    font.bold: true
                    anchors.centerIn: parent
                    text: "变量名"
                    color: "white"
                }
            }
            Rectangle{
                border.color: "#7b40f2"
                border.width: 2
                clip: true
                height: dSVHeadDateItem.height
                width: dSVHeadDateItem.width -370>0 ? dSVHeadDateItem.width -370 : 1
                radius: 10
                color: "transparent"
                Text {
                    //clip: true
                    font.pixelSize : 18
                    font.bold: true
                    anchors.centerIn: parent
                    text: "值"
                    color: "white"
                }
            }
        }
    }


    Item{
        id:dSVH_ListViewItem
        anchors{
            top: dSVHeadDateItem.bottom
            topMargin: 20
            left: dSV_R.left
            right: dSV_R.right
            bottom: parent.bottom
        }
        height: 400
        ListView{
            anchors.fill: parent
            model: rModeManager.rOriginModel
            delegate: dataTableDelegate
        }
    }
    Component{
        id:dataTableDelegate
        Rectangle{
            radius: 10
            color: dTD_MouseArea.containsMouse  ? "#7b40f2" : "transparent"
            width: dSVH_ListViewItem.width
            height: 30
            MouseArea{
                id:dTD_MouseArea
                anchors.fill: parent
                hoverEnabled: true
            }

            Row{
                anchors.left: parent.left
                anchors.leftMargin: 10
                spacing: 10
                Rectangle{
                    height: dSVHeadDateItem.height
                    width: 100
                    radius: 10
                    color: "transparent"
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        font.pixelSize : 18
                        font.bold: true
                        text: "·"+type
                        color: type == "char"     ? "#33CC99"     :
                               type == "float"    ? "#FFCC99"     :
                               type == "hex"      ? "#FFFF00"     :
                               type == "string"   ? "#CCFFFF"     : "white"




                    }
                }
                Rectangle{
                    height: dSVHeadDateItem.height
                    width: 120
                    radius: 10
                    color: "transparent"
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        font.pixelSize : 18
                        font.bold: true
                        text: date
                        color: "white"
                    }
                }
                Rectangle{
                    height: dSVHeadDateItem.height
                    width: 120
                    radius: 10
                    color: "transparent"
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        font.pixelSize : 18
                        font.bold: true
                        text: name
                        color: "white"
                    }
                }
                Rectangle{
                    clip: true
                    height: dSVHeadDateItem.height
                    width: dSVHeadDateItem.width -370>0 ? dSVHeadDateItem.width -370 : 1
                    radius: 10
                    color: "transparent"
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        font.pixelSize : 18
                        font.bold: true
                        text: val
                        color: "white"
                    }
                }
            }
        }

    }




}
