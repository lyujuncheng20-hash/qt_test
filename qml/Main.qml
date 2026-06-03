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

        // 🟢 修复核心：作为页面的根 Item，去掉所有的 anchors 属性！
        // StackView 会自动接管这个 Item 的大小和位置
        Item {
            id: homeLayout

            ToolButton {
                id: iconButton
                // ✅ 子控件可以安全地使用 anchors.centerIn: parent 居中在 Item 里
                anchors.centerIn: parent

                // 1. 图标路径
                icon.source: "assets/images/info.png"
                icon.width: 32
                icon.height: 32

                // 2. 按钮文字与字体
                text: "点击进入计数器"
                font.pixelSize: 14

                // 3. 布局（让文字显示在图标下方）
                display: AbstractButton.TextUnderIcon

                // 4. 点击事件
                onClicked: {
                    mainStack.push("counterview/CounterView.qml")
                }
            }
        }
    }
}
