import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Page
{
    id: mechaniclogin
    Rectangle
    {
        id: fullcolor
        color : "#33AFFF"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
    }
    Image
    {
        id: mechanicimage
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source: "1.png"
        anchors.fill: parent
        anchors.top: welcome.bottom
    }
    Text
    {
        id: welcome
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        //verticalAlignment: Text.AlignVCenter
        color: "White"
        text: "Welcome to the mechanic app!"
        anchors.rightMargin: 0
        anchors.bottomMargin: 439
        anchors.leftMargin: 0
        anchors.topMargin: 11
        font.pixelSize: 17

    }
    Column
    {
        id: clmn
        width: 220
        height: 134
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        spacing: 2
        anchors.centerIn: parent
        TextField
        {
            id:mechanicname
            placeholderText: "Enter your name"
            onAccepted: money.focus = true
        }
        TextField
        {
            id:money
            placeholderText: "How much money do you have?"
        }
        Button
        {
            id: acceptlogin
            //Button.horizontalCenter: parent
            text: "Let's buy!"
            onPressed:
            {
                if(manage1.mechaniclogin(mechanicname.text, money.text))
                {
                    pages.push("OptionPage.qml")
                }
                else
                {
                    text1.text = "Please enter a valid number"
                    dialog1.open()
                }
            }

        }
        Dialog{
            id: dialog1
            Text {
                id: text1
            }
        }
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
