import QtQuick
import QtQuick.Controls
import counter.module 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Counter"


    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: counter_instance.count //この部分はProperty Bindingです。counter.count が変更されると 自動的に画面が更新されます。
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 10

            Button {
                text: "+"
                onClicked: counter_instance.increment()
            }

            Button {
                text: "-"
                onClicked: counter_instance.decrement()
            }
        }

        Button {
            text: "Reset"
            onClicked: counter_instance.reset()
        }
    }
}
