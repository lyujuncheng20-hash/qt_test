// qml/Main.qml
import QtQuick
import QtQuick.Controls

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

        // 1. 进入新页面时的动画 (Push)
        pushEnter: Transition {
            PropertyAnimation { property: "x"; from: mainStack.width; to: 0; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; from: 0; to: 1; duration: 400 }
        }
        pushExit: Transition {
            PropertyAnimation { property: "x"; from: 0; to: -mainStack.width; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; from: 1; to: 0; duration: 400 }
        }

        // 2. 返回上一页时的动画 (Pop)
        popEnter: Transition {
            PropertyAnimation { property: "x"; from: -mainStack.width; to: 0; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; from: 0; to: 1; duration: 400 }
        }
        popExit: Transition {
            PropertyAnimation { property: "x"; from: 0; to: mainStack.width; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; from: 1; to: 0; duration: 400 }
        }
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
