import QtQuick
import QtQuick.Controls
import counter.module 1.0 // 导入你定义的模块

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Counter"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            // 【修改】使用大写的类名 Counter 访问单例属性
            text: Counter.count
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 10

            Button {
                text: "+"
                // 【修改】调用单例方法
                onClicked: Counter.increment()
            }

            Button {
                text: "-"
                // 【修改】调用单例方法
                onClicked: Counter.decrement()
            }
        }

        Button {
            text: "Reset"
            // 【修改】调用单例方法
            onClicked: Counter.reset()
        }
    }
}
