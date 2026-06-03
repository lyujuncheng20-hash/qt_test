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

    // 画面遷移（スタック）を管理
    StackView {
        id: mainStack
        anchors.fill: parent
        initialItem: homePage
    }

    Component {
        id: homePage

        Item {
            id: homeLayout

            ToolButton {
                id: iconButton
                anchors.centerIn: parent

                icon.source: "assets/images/info.png"
                icon.width: 32
                icon.height: 32

                text: "カウンターへ"
                font.pixelSize: 14
                display: AbstractButton.TextUnderIcon

                onClicked: {
                    mainStack.push("counterview/CounterView.qml")
                }
            }
        }
    }
}
