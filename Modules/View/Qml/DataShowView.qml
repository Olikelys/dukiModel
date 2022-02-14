import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Item {

    anchors.fill: parent
    clip: true
    ListView{
        anchors.fill:parent
        //anchors.centerIn: parent
        model: rModeManager.rOriginModel
        delegate: dataTableDelegate
    }
    Component{
        id:dataTableDelegate
        Item{
            //anchors.fill: parent
            width: subMenuPane.width
            height: 40
            Rectangle{
                id:rType
                height: parent.height
                width: subMenuPane.width/3
                anchors.right: rName.left
                border.width: 1
                border.color: "black"
                Text {
                    id:textType
                    clip: true
                    anchors.centerIn: parent
                    text: type
                }
            }
            Rectangle{
                id:rName
                anchors.right: rVal.left
                height: parent.height
                width: subMenuPane.width/3
                border.width: 1
                border.color: "black"
                Text {
                    id:textName
                    clip: true
                    anchors.centerIn: parent
                    text: name
                }
            }
            Item{
                id:rVal
                height: parent.height
                width: subMenuPane.width/3
                anchors.right: parent.right
                //Layout.alignment:Qt.AlignRight
                //border.width: 1
                //border.color: "black"
                Text {
                    id:textVal
                    clip: true
                    anchors.centerIn: parent
                    text: val
                }

        }

        }

    }


}
