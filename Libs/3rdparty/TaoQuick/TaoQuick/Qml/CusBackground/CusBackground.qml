import QtQuick 2.9
import QtQuick.Controls 2.2
import ".."
import "../.."
Rectangle {
    color: CusConfig.backgroundColor
    radius: 10
    MouseArea {
        id: backgroundArea
        anchors.fill: parent
        onClicked: {
            focus = true
        }
    }
}
