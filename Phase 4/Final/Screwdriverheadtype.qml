import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


Page {
    id: page

    anchors.fill: parent
    Rectangle{
        id:headtype
        color: "#33AFFF"
        anchors.fill: parent
    }

    RadioButton {
        id: radioButton
        x: 62
        y: 75
        text: qsTr("Slothead")
        onCheckedChanged: if(checked) {manage1.headtypeslot(1)}

    }

    RadioButton {
        id: radioButton1
        x: 62
        y: 121
        text: qsTr("Philipshead")
        onCheckedChanged: if(checked) {manage1.headtypeslot(2)}
    }

    RadioButton {
        id: radioButton2
        x: 62
        y: 167
        text: qsTr("Posizdriv")
        onCheckedChanged: if(checked) {manage1.headtypeslot(3)}
    }

    RadioButton {
        id: radioButton3
        x: 62
        y: 213
        text: qsTr("Torx")
        onCheckedChanged: if(checked) {manage1.headtypeslot(4)}
    }

    RadioButton {
        id: radioButton4
        x: 62
        y: 254
        text: qsTr("Allen")
        onCheckedChanged: if(checked) {manage1.headtypeslot(5)}
    }

    Text {
        id: element
        x: 62
        y: 48
        color: "#000000"
        text: qsTr("What type of headtype do you want?")
        font.pixelSize: 17
    }

    Button {
        id: button
        x: 474
        y: 402
        width: 82
        height: 40
        text: qsTr("Next")
        //RadioButton.checked:
        onClicked:{

            if(radioButton.checked || radioButton1.checked || radioButton2.checked || radioButton3.checked || radioButton4.checked)
            {
                pages.push("Screwdriverheadsize.qml")
            }
            else
            {
                dialog1.open();
            }

        }
    }
    Dialog{
        id: dialog1
        Text {
            id: dlg
            text: qsTr("Choose an option!")
        }
    }

    Image {
        id: image
        x: 359
        y: 93
        width: 230
        height: 217
        source: "10.png"
        fillMode: Image.PreserveAspectFit
    }



}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
