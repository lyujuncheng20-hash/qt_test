import QtQuick
import QtQuick.Controls
import base.components 1.0
import counter.module 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Counter Example"

    Counter {
        id: myCounter
        count: 0 // 可以赋初值

        onCountChanged: (value) => {
            cppLogger.onCountChanged(value)
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            // 【核心变化】通过 id 访问其实例属性
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
