// CounterView.qml
import QtQuick
import QtQuick.Controls
import "../base"
import counter.module 1.0

Item {
    id: counterPage

    Counter {
        id: myCounter
        count: 0

        onCountChanged: (value) => {
            cppLogger.onCountChanged(value)
        }
    }

    BaseButton {
        text: "⬅ back"
        anchors {
            top: parent.top
            left: parent.left
        }
        onClicked: {
            // mainStack 是在 main.qml 中定义的 StackView 的 id
            mainStack.pop()
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: myCounter.count
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 10

            BaseButton{
                text: "+"
                onClicked: myCounter.increment()
            }

            BaseButton {
                text: "-"
                onClicked: myCounter.decrement()
            }
        }

        BaseButton {
            text: "Reset"
            onClicked: myCounter.reset()
        }
    }
}
