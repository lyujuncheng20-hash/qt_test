// main.qml
import QtQuick
import QtQuick.Controls
import app_ui

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 600
    height: 400
    title: "Main Window"

    // 用 StackView 来管理所有的页面跳转
    StackView {
        id: mainStack
        anchors.fill: parent

        // 初始页面设置为下面定义的主页组件
        initialItem: homePage
    }

    // 将主页的内容打包成一个组件（Component）
    Component {
        id: homePage

        Item {
            id: homeLayout

            // 这里放你的主页内容，比如你提到的“图标”
            // 假设用一个简单的 Image + MouseArea 或者 ToolButton 来做图标
            ToolButton {
                id: iconButton
                anchors.centerIn: parent

                // 按钮的外观：可以同时包含图标和文字
                icon.name: "view-refresh" // 如果有系统图标库
                text: "📊\n点击进入计数器"
                font.pixelSize: 14

                // 点击图标后，执行跳转
                onClicked: {
                    // push() 会自动加载 CounterView.qml 并将其作为当前页面显示
                    mainStack.push("counterview/CounterView.qml")
                }
            }
        }
    }
}
