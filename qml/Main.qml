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

        //画面遷移（縦型・横型移動とフェードイン・アウト）の制御
        pushEnter: Transition {
            // 新しい画面を右端（mainStack.width）から左（0）へ滑り込ませる（OutCubicで滑らかに減速）
            PropertyAnimation { property: "x"; from: mainStack.width; to: 0; duration: 400; easing.type: Easing.OutCubic }
            // 同時に、不透明度を0から1へ変化（フェードイン）
            PropertyAnimation { property: "opacity"; from: 0; to: 1; duration: 400 }
        }

        pushExit: Transition {
            // 古い画面を左側へ少し押し出す
            PropertyAnimation { property: "x"; to: -mainStack.width * 0.3; duration: 400; easing.type: Easing.OutCubic }
            // 同時に、不透明度を下げていく（フェードアウト）
            PropertyAnimation { property: "opacity"; to: 0; duration: 400 }
        }

        popEnter: Transition {
            // 戻る際：前の画面を左の奥から定位置（0）へ戻す
            PropertyAnimation { property: "x"; from: -mainStack.width * 0.3; to: 0; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; from: 0; to: 1; duration: 400 }
        }

        popExit: Transition {
            // 戻る際：現在の画面を右端へ滑り出させて消す
            PropertyAnimation { property: "x"; to: mainStack.width; duration: 400; easing.type: Easing.OutCubic }
            PropertyAnimation { property: "opacity"; to: 0; duration: 400 }
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
