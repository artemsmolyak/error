import QtQuick 2.7

Item {
//    button1.onClicked: {
//        console.log("Button 1 clicked.");
//    }
//    button2.onClicked: {
//        console.log("Button 2 clicked.");
//    }

    Component.onCompleted: {
        client.fillMainList();
        //console.log("client.fillMainList();" + mainModel.size())
    }


    ListModel {
        id : contactModel
        ListElement {
            name: "555 3264"
            price: "3"
        }
        ListElement {
            name: "555 8426"
            price: "43"
        }
        ListElement {
            name: "555 0473"
            price: "32"
        }
    }


    Component {
            id: contactDelegate
            Item {
                width: 180; height: 40
                Column {
                    Text { text: '<b>Price:</b> ' + price }
                    Text { text: '<b>Name:</b> ' + name }
                }
            }
        }

    ListView{
        model: mainModel
       anchors.fill: parent
       delegate: contactDelegate
//           Rectangle{
//           width: 100
//           height: 100
//           Text{
//               anchors.fill: parent
//               text:name
//           }
//       }

    }
}
