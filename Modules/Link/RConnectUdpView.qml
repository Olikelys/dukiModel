import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15




Item {
    width: parent.width

    GridLayout{
        width: parent.width
        columns: (b1.width + b2.width) < width ? 2 : 1
        Button{
            id: b1
            //Layout.fillWidth : true
            //Layout.alignment: Qt.AlignHCenter

        }
        Button{
            id: b2
            Layout.alignment:Qt.AlignRight
        }

    }
}
