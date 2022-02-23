import QtQuick 2.0
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12


Item {
    id:basicMenu
    //clip: true
    width: parent.width
    implicitHeight: cITI_BacisMenu.opened ? 390 : 190

    signal closeMenu()       //点击关闭按钮触发
    signal deleteMenu()      //点击删除按钮触发


    property string path: ""
    property string controlType: ""
    property alias  name: textInputName.text
    property alias  borderVisble: borderVisablCheckBox.checked
    property alias  nameVisble: nameVisableCheckBox.checked
    property alias  xx: textInputX.text
    property alias  yy: textInputY.text
    property alias  wwidth: textInputWidth.text
    property alias  hheight: textInputHeight.text
    property alias  rrotation: textInputRotation.text

    DropShadow
    {
        anchors.fill: rMI_DropShadow
        radius: 8.0
        samples: 16
        color: "#7b40f2"
        source: rMI_DropShadow
     }
    Rectangle{
        id:rMI_DropShadow
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
        id: rMI_TextItem
        anchors.fill: rMI_DropShadow
        clip: true
        Button{
             anchors{
                 right: parent.right
                 //rightMargin: 4
                 top:parent.top
                 //topMargin: 4
             }
             background: Rectangle{
                 anchors.fill: parent
                 color: "transparent"
             }
             icon.source:"qrc:/Controls/library/Image/close.png"
             icon.color:"transparent"
             icon.width: 30
             icon.height: 30
             onClicked:{           
                 basicMenu.closeMenu()
             }
             ToolTip{
                 visible: parent.hovered
                 delay: 800
                 text: "关闭菜单后配置生效"
                 background: Rectangle{
                     color: "#7f7f7f"
                     radius: 3
                 }
             }
        }
        GridLayout{
            id:rMITI_GridLayout
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
            TextInput{
                id: textInputName
                anchors.verticalCenter: parent.verticalCenter
                text: "给他写一个名字吧"
                font.pixelSize : 22
                font.bold: true
                maximumLength: 14
                color: "white"
            }}
        }
        Rectangle{
            id:cITI_RectangleLine1
            height: 4
            anchors{
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
                top: rMITI_GridLayout.bottom
                topMargin: 14
            }
            radius:4
            color: "#DDDDDD"
        }

        RowLayout{
            anchors.top: cITI_RectangleLine1.bottom
            anchors.topMargin: 10
            width: parent.width  
            Button{
                 Layout.alignment:Qt.AlignTop
                 background: Rectangle{
                     anchors.fill: parent
                     color: "transparent"
                 }
                 icon.source: "qrc:/Controls/library/Image/delete.png"
                 icon.color:"transparent"
                 icon.width:24
                 icon.height: 24
                 onClicked:{
                     basicMenu.deleteMenu()
                 }
            }
            Text{
                height:  24

                text: "删除"
                font.pixelSize : 16
                font.bold: true
                color: "white"
            }



            CheckBox{
                id:borderVisablCheckBox
                Material.theme: "Dark"

            }
            Text{
                height:  24
                text: "边框可见"
                font.pixelSize : 16
                font.bold: true
                color: "white"
            }



            CheckBox{
                id:nameVisableCheckBox
                Material.theme: "Dark"
            }
            Text{
                height:  24
                text: "名字可见"
                font.pixelSize : 16
                font.bold: true
                color: "white"
            }



        }


    }

    //基础配置
    Column {
        id: cITI_BacisMenu
        clip: true
        spacing: 10
        anchors{
            top: rMI_DropShadow.bottom
            topMargin: 10
            right: rMI_DropShadow.right
            left: rMI_DropShadow.left
        }
        property bool opened: false
        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            radius: 10
            color: "#FF9900"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    cITI_BacisMenu.opened = !cITI_BacisMenu.opened
                }
            }
            Text {
                anchors{
                    left: parent.left
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                font.pixelSize : 20
                font.bold: true
                color: "white"
                text:"基础设置"
            }
            Image {
                anchors{
                    right: parent.right
                    rightMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                source: cITI_BacisMenu.opened ? "qrc:/Controls/library/Image/leftclose.png" : "qrc:/Controls/library/Image/downopen.png"
            }
        }

        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            color: "transparent"
            opacity: 0.7
            radius: 5
            visible: parent.opened
            border.width: 1
            border.color: "white"
            Rectangle{
                id: textX
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                }
                width: 40
                radius: 5
                opacity: 0.7
                Text {

                    anchors{
                        left: parent.left
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    text: "x:"
                    font.pixelSize : 20
                    font.bold: true
                    color: "white"
                }

            }
            TextInput{
                id: textInputX
                anchors{
                    left: textX.right
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
                text: "5"
                font.pixelSize : 20
                font.bold: true
                color: "white"
                validator: RegExpValidator{
                    regExp: /[0-9]+/
                }

                maximumLength: 4
                onTextChanged: {
                    if(text  >= mainBobyPane.width  )
                    {
                    console.debug(text)
                    }
                }
            }
        }
        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            color: "transparent"
            opacity: 0.7
            radius: 5
            visible: parent.opened
            border.width: 1
            border.color: "white"
            Rectangle{
                id: textY
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                }
                width: 40
                radius: 5
                opacity: 0.7
                Text {

                    anchors{
                        left: parent.left
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    text: "y:"
                    font.pixelSize : 20
                    font.bold: true
                    color: "white"
                }

            }
            TextInput{
                id:textInputY
                anchors{
                    left: textY.right
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
                text: "88"
                font.pixelSize : 20
                font.bold: true
                color: "white"
                validator: RegExpValidator{
                    regExp: /[0-9]+/
                }

                maximumLength: 4
                onTextChanged: {
                    if(text  >= mainBobyPane.width  )
                    {
                    console.debug(text)
                    }
                }
            }
        }
        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            color: "transparent"
            opacity: 0.7
            radius: 5
            visible: parent.opened
            border.width: 1
            border.color: "white"
            Rectangle{
                id: textWidth
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                }
                width: 90
                radius: 5
                opacity: 0.7
                Text {

                    anchors{
                        left: parent.left
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    text: "width:"
                    font.pixelSize : 20
                    font.bold: true
                    color: "white"
                }

            }
            TextInput{
                id:textInputWidth
                anchors{
                    left: textWidth.right
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
                text: "100"
                font.pixelSize : 20
                font.bold: true
                color: "white"
                validator: RegExpValidator{
                    regExp: /[0-9]+/
                }

                maximumLength: 4
                onTextChanged: {
                    if(text  >= mainBobyPane.width  )
                    {
                    console.debug(text)
                    }
                }
            }
        }
        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            color: "transparent"
            opacity: 0.7
            radius: 5
            visible: parent.opened
            border.width: 1
            border.color: "white"
            Rectangle{
                id: textHeight
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                }
                width: 90
                radius: 5
                opacity: 0.7
                Text {

                    anchors{
                        left: parent.left
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    text: "height:"
                    font.pixelSize : 20
                    font.bold: true
                    color: "white"
                }

            }
            TextInput{
                id:textInputHeight
                anchors{
                    left: textHeight.right
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
                text: "5"
                font.pixelSize : 20
                font.bold: true
                color: "white"
                validator: RegExpValidator{
                    regExp: /[0-9]+/
                }

                maximumLength: 4
                onTextChanged: {
                    if(text  >= mainBobyPane.width  )
                    {
                    console.debug(text)
                    }
                }
            }
        }
        Rectangle{
            width: rMI_DropShadow.width
            height: 30
            color: "transparent"
            opacity: 0.7
            radius: 5
            visible: parent.opened
            border.width: 1
            border.color: "white"
            Rectangle{
                id: textRotation
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                }
                width: 110
                radius: 5
                opacity: 0.7
                Text {

                    anchors{
                        left: parent.left
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    text: "rotation:"
                    font.pixelSize : 20
                    font.bold: true
                    color: "white"
                }

            }
            TextInput{
                id:textInputRotation
                anchors{
                    left: textRotation.right
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
                text: "5"
                font.pixelSize : 20
                font.bold: true
                color: "white"
                validator: RegExpValidator{
                    regExp: /[0-9]+/
                }

                maximumLength: 3
                onTextChanged: {
                    if(text  >= 360 )
                    {
                       snackbar.open("角度只能0-360之间")
                        text = 0
                    }
                }
            }
        }

    }



//   Button{
//       onClicked: {
//           var ddd = getBasic_ctx()
//           ddd.path = "i kown path"
//           ddd.controlType = "wavyporgress"
//           ddd.name = "i kown name"
//           ddd.borderVisble = true
//           ddd.nameVisble  = true
//           ddd.x = 33
//           ddd.y = 44
//           ddd.width = 55
//           ddd.height = 66
//           ddd.rotation =77
//           setBasic_ctx(ddd)
//       }
//   }


   function getBasic_ctx()
   {
       var ctx = {
           "path" : path,
           "controlType":controlType,
           "name":name,
           "borderVisble":borderVisble,
           "nameVisble":nameVisble,
           "x":xx,
           "y":yy,
           "width":wwidth,
           "height":hheight,
           "rotation":rrotation

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
       xx = ctx.x
       yy = ctx.y
       wwidth = ctx.width
       hheight = ctx.height
       rrotation = ctx.rotation
   }



}
