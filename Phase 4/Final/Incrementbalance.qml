import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


Page {
    anchors.fill: parent
    Rectangle{
        id: incrementbalancee
        color: "#33AFFF"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        TextField {
            id: textField
            x: 220
            y: 220
            placeholderText: "Enter Here"
        }

        Text {
            id: inc
            x: 83
            y: 45
            width: 337
            height: 34
            text: qsTr("How much money do you want to add to your balance?")
            font.pixelSize: 20
        }

        Dialog{
            id: dialog1
            Text {
                id: text1
            }
        }

        Button
        {
            id: incbutton
            x: 474
            y: 371
            text: "Add"

            onPressed:
            {
                if(manage1.incbalance(textField.text))
                {
                    text1.text = "Incremented Successfully!"
                    dialog1.open()
                    pages.push("OptionPage.qml")
                }
                else
                {
                    text1.text = "Please enter a valid number"
                    dialog1.open()
                }
            }
        }

    }

}

