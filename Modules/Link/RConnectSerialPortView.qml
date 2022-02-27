import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.15
//import QtQuick.XmlListModel 2.12
import Qt.labs.settings 1.0

Rectangle {
    anchors.fill: parent

    Settings{
        property alias rCSPVGL_BaudRateComboBox_currentIndex:    rCSPVGL_BaudRateComboBox.currentIndex
        property alias rCSPVGL_ParityComboBox_currentIndex:      rCSPVGL_ParityComboBox.currentIndex
        property alias rCSPVGL_DataBitsComboBox_currentIndex:    rCSPVGL_DataBitsComboBox.currentIndex
        property alias rCSPVGL_StopBitsComboBox_currentIndex:    rCSPVGL_StopBitsComboBox.currentIndex
        property alias rCSPVGL_FlowControlComboBox_currentIndex: rCSPVGL_FlowControlComboBox.currentIndex
    }
    property alias rCSPVGL_PortNameComboBox_currentText: rCSPVGL_PortNameComboBox.currentText
    property alias rCSPVGL_BaudRateComboBox_currentText: rCSPVGL_BaudRateComboBox.currentText
    property alias rCSPVGL_ParityComboBox_currentText: rCSPVGL_ParityComboBox.currentText
    property alias rCSPVGL_DataBitsComboBox_currentText: rCSPVGL_DataBitsComboBox.currentText
    property alias rCSPVGL_StopBitsComboBox_currentText: rCSPVGL_StopBitsComboBox.currentText
    property alias rCSPVGL_FlowControlComboBox_currentText: rCSPVGL_FlowControlComboBox.currentText



    Rectangle{
        id: rCSPV_Label
        width: 100
        height: 40
        color: "transparent"
    Label{
        anchors.verticalCenter: parent.verticalCenter
        text: "串口参数配置"
        font.pixelSize : 20
        font.bold: true
        //Material.foreground: Material.Pink
        color: textcolor2
    }
    }


    //端口号
    GridLayout{
        id: rCSPV_GridLoyout_PortName
        width: parent.width
        anchors.top: rCSPV_Label.bottom
        columns: (rCSPVGL_PortNameComboBox.width + rCSPVGL_PortNameLabel.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_PortNameLabel
            width: 80
            height: 5
            color: "transparent"
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text: "端口号"
            color: textcolor
            font.bold: true
            font.pixelSize : 16
        }
        }
        ComboBox{
            id:rCSPVGL_PortNameComboBox
            Material.background: "transparent"
            Material.foreground: "white"
            Layout.alignment:Qt.AlignRight
            onActivated: {
                            //console.log(currentIndex)

                        }
            onPressedChanged: {
                rConnectManager.sigGetSerialPortName()
            }
            function onSigSetSerialPortName(serialPortNameList)
            {
                //console.log(rCSPVGL_PortNameComboBox.model)
                rCSPVGL_PortNameComboBox.model = serialPortNameList
                //console.log(rCSPVGL_PortNameComboBox.model)
            }
            Component.onCompleted: {
                rConnectManager.sigSetSerialPortName.connect(onSigSetSerialPortName);
                rConnectManager.sigGetSerialPortName()


            }
        }
    }

    //波特率
    GridLayout{
        id: rCSPV_GridLoyout_BaudRate
        width: parent.width
        anchors.top: rCSPV_GridLoyout_PortName.bottom
        columns: (rCSPVGL_PortNameComboBox.width + rCSPVGL_PortNameLabel.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_BaudRateabel
            width: 80
            height: 10
            color: "transparent"
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text: "波特率"
            color: textcolor
            font.bold: true
            font.pixelSize : 16
        }
        }
        ComboBox{
            id:rCSPVGL_BaudRateComboBox
            height: 100
            Layout.alignment:Qt.AlignRight
            Material.background: "transparent"
            Material.foreground: "white"
            model:["1200","2400","4800","9600","19200","38400","57600","115200","128000","230400","256000"]
            onActivated: {
                         //console.log(currentText)
                        }
        }
    }

    //校验位
    GridLayout{
        id: rCSPV_GridLoyout_Parity
        width: parent.width
        anchors.top: rCSPV_GridLoyout_BaudRate.bottom
        columns: (rCSPVGL_ParityLable.width + rCSPVGL_ParityComboBox.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_ParityLable
            width: 80
            height: 10
            color: "transparent"
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text: "校验位"
            color: textcolor
            font.bold: true
            font.pixelSize : 16
        }
        }
        ComboBox{
            id:rCSPVGL_ParityComboBox
            width: 100
            height: 100
            Layout.alignment:Qt.AlignRight
            textRole: "key"
            valueRole: "value"
            Material.background: "transparent"
            Material.foreground: "white"
            model:ListModel {
                        ListElement { key: "None"; value: "0" }
                        ListElement { key: "偶"; value: "2" }
                        ListElement { key: "奇"; value: "3" }
                    }
            onActivated: {
                              //console.log(currentValue)

                        }
        }
    }



    //数据位
    GridLayout{
        id: rCSPV_GridLoyout_DataBits
        width: parent.width
        anchors.top: rCSPV_GridLoyout_Parity.bottom
        columns: (rCSPVGL_DataBitsLable.width + rCSPVGL_DataBitsComboBox.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_DataBitsLable
            width: 80
            height: 10
            color: "transparent"
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text: "数据位"
            color: textcolor
            font.bold: true
            font.pixelSize : 16
        }
        }
        ComboBox{
            id:rCSPVGL_DataBitsComboBox
            height: 100
            Layout.alignment:Qt.AlignRight
            Material.background: "transparent"
            Material.foreground: "white"
            model:["8","7","6","5"]
            onActivated: {
                            //console.log(currentIndex)

                        }
        }
    }




    //停止位
    GridLayout{
        id: rCSPV_GridLoyout_StopBits
        width: parent.width
        anchors.top: rCSPV_GridLoyout_DataBits.bottom
        columns: (rCSPVGL_StopBitsLable.width + rCSPVGL_StopBitsComboBox.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_StopBitsLable
            width: 80
            height: 10
            color: "transparent"
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text: "停止位"
            color: textcolor
            font.bold: true
            font.pixelSize : 16
        }
        }
        ComboBox{
            id:rCSPVGL_StopBitsComboBox
            height: 100
            Layout.alignment:Qt.AlignRight
            Material.background: "transparent"
            Material.foreground: "white"
            textRole: "key"
            valueRole: "value"
            model:ListModel {
                        ListElement { key: "1"; value: "1" }
                        ListElement { key: "2"; value: "2" }
                        ListElement { key: "1.5"; value: "3" }
                    }
            onActivated: {
                            //console.log(currentIndex)

                        }
        }
    }

    //流控
    GridLayout{
        id: rCSPV_GridLoyout_FlowControl
        width: parent.width
        anchors.top: rCSPV_GridLoyout_StopBits.bottom
        columns: (rCSPVGL_FlowControlLable.width + rCSPVGL_FlowControlComboBox.width) <= width ? 2 : 1
        Rectangle{
            id: rCSPVGL_FlowControlLable
            width: 80
            height: 10
            color: "transparent"
        Text {
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            font.pixelSize : 16
            color: textcolor
            text: "数据流控"
        }
        }
        ComboBox{
            id:rCSPVGL_FlowControlComboBox
            height: 100
            Layout.alignment:Qt.AlignRight
            Material.background: "transparent"
            Material.foreground: "white"
            textRole: "key"
            valueRole: "value"
            model:ListModel {
                        ListElement { key: "None"; value: "0" }
                        ListElement { key: "Hard"; value: "1" }
                        ListElement { key: "Soft"; value: "2" }
                    }
            onActivated: {
                            //console.log(currentText)

                        }
        }
    }

    Rectangle{
        id:rCSPV_RectangleLine2
        anchors.top: rCSPV_GridLoyout_FlowControl.bottom
        width: parent.width
        height: 3
        color: "#DDDDDD"
        radius: 4
    }







}
