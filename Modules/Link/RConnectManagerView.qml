import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0
import QtQuick.Layouts 1.15
import RLink 1.0


Rectangle {
    id:rCManager
    anchors.fill: parent
    color: "transparent"

    Settings{
        property alias rConnectManager_DataSourcesComboBox: rConnectManager_DataSourcesComboBox.currentIndex
        //property alias rConnectManager_ConnectSwitch: rConnectManager_ConnectSwitch.checked

    }
    RConnectManager{
        id:rConnectManager
    }


    //连接选项
    GridLayout{
        id:rCMV_ConnectGridLayout
        anchors{
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            top: parent.top
        }
        columns: (rConnectManager_ConnectLabel.width + rConnectManager_ConnectSwitch.width) < width ? 2 : 1
        Rectangle{
            id: rConnectManager_ConnectLabel
            width: 60
            height: 20
            color: "transparent"
            Label{
                anchors.verticalCenter: parent.verticalCenter
                text: "连接"
                font.pixelSize : 22
                font.bold: true
                Material.foreground: Material.Pink
            }
        }
        Switch{
            id: rConnectManager_ConnectSwitch
            Layout.alignment:Qt.AlignRight
            onCheckedChanged: {
                if(rConnectManager.connectState)   //如果已经连接
                {
                    switch(rConnectManager.connectDataSources)
                    {
                    case 0: {
                        rConnectManager.connectState =checked
                        console.debug("串口关闭连接"+rConnectManager.connectState)
                    }break;
                    case 1: {
                        rConnectManager.connectState =checked
                    }break;
                    case 2: {
                        rConnectManager.connectState =checked
                    }break;
                    default:{
                        rConnectManager.connectState =checked
                    }break;
                    }
                }
                else
                {         //开始连接
                    switch(rConnectManager.connectDataSources)
                    {
                    case 0: {
                        rConnectManager.connectState =checked
                        rConnectManager.Connect(rConnectSerialPortView.rCSPVGL_PortNameComboBox_currentText,
                                                rConnectSerialPortView.rCSPVGL_BaudRateComboBox_currentText,
                                                rConnectSerialPortView.rCSPVGL_DataBitsComboBox_currentText,
                                                rConnectSerialPortView.rCSPVGL_ParityComboBox_currentText,
                                                rConnectSerialPortView.rCSPVGL_StopBitsComboBox_currentText,
                                                rConnectSerialPortView.rCSPVGL_FlowControlComboBox_currentText);
                        //console.debug("串口启动连接"+rConnectManager.connectState)
                    }break;
                    case 1: {
                        rConnectManager.connectState =checked
                    }break;
                    case 2: {
                        rConnectManager.connectState =checked
                    }break;
                    default:{
                        rConnectManager.connectState =checked
                    }break;
                    }

                }
            }
            Component.onCompleted: {
//                console.debug("connectState"+rConnectManager.connectState)
//                console.debug("check"+checked)
                rConnectManager.connectState =checked
//                console.debug("connectState"+rConnectManager.connectState)
//                console.debug("check"+checked)
            }

        }
    }

    //行
    Rectangle{
        id:rCMV_RectangleLine1
        width: parent.width
        height: 4
        anchors{
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            top: rCMV_ConnectGridLayout.bottom
        }
        radius:4
        color: "#DDDDDD"
    }


    //数据源
    GridLayout{
        id:rCMV_DataSourcesGridLayout
        anchors{
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            top: rCMV_RectangleLine1.bottom
        }
        columns: (rCMVDSGL_Label.width + rConnectManager_DataSourcesComboBox.width) <= width ? 2 : 1
        Rectangle{
            id: rCMVDSGL_Label
            width: 80
            height: 30
            color: "transparent"
            Label{
                anchors.verticalCenter: parent.verticalCenter
                text: "数据接口"
                font.pixelSize : 18
            }
        }
        ComboBox{
            id:rConnectManager_DataSourcesComboBox
            height: 100
            Layout.alignment:Qt.AlignRight
            //Material.background: "transparent"
            model:["串口","UDP","本地文件"]
            //currentIndex: rConnectManager.connectDataSources
            onActivated: {
                            rConnectManager.connectDataSources=currentIndex
                //console.log(rConnectManager.connectDataSources)
                //console.log(currentIndex)
                        }
            Component.onCompleted: {
                rConnectManager.connectDataSources = currentIndex
               // console.log(rConnectManager.connectDataSources)
                //console.log(currentIndex)
            }
        }
    }


    Rectangle{
        id:rCMV_RectangleLine2
        width: parent.width
        height: 3
        anchors{
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            top: rCMV_DataSourcesGridLayout.bottom
        }
        //anchors.bottom: rCMV_DataSourcesGridLayout.bottom
        radius:3
        color: "#DDDDDD"

    }








    Item {
        id:rCMV_item3
        anchors{
            top:rCMV_RectangleLine2.bottom
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
        }

        RConnectSerialPortView{
            id:rConnectSerialPortView
            anchors.fill: parent
            visible: 0==rConnectManager_DataSourcesComboBox.currentIndex
        }
        RConnectUdpView{
            id:rConnectUdpView
            anchors.fill: parent
            visible: 1==rConnectManager_DataSourcesComboBox.currentIndex
        }
        RConnectLocalDataView{
            id:rConnectLocalDataView
            anchors.fill: parent
            visible: 2==rConnectManager_DataSourcesComboBox.currentIndex
        }
    }






}
