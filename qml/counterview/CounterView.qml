// CounterView.qml
import QtQuick
import QtQuick.Controls
import base.components 1.0
import counter.module 1.0

Item {
    id: counterPage
    // 让子页面自动填满父容器（StackView）
    anchors.fill: parent

    Counter {
        id: myCounter
        count: 0

        onCountChanged: (value) => {
            cppLogger.onCountChanged(value)
        }
    }

    // 建议加一个返回主页的按钮，方便切回去
    Button {
        text: "⬅ 返回主页"
        anchors {
            top: parent.top
            left: parent.left
            margin: 10
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
