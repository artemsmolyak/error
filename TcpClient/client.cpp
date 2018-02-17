#include "client.h"
#include <QDataStream>
#include <QHostAddress>
#include <QDebug>



Client::Client()
{
     clientSocket =new QTcpSocket();
     connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readAnswerFromServer()));
     clientSocket->connectToHost(QHostAddress::LocalHost, 55555);

     qDebug() << "wait for connect....";
     clientSocket->waitForConnected();

     qDebug() << "connected";
}

Client::~Client(){
      qDebug() << "destractor";
}


void Client::sendRequest(Request request, QVector<QString> params){

    QByteArray ba;

    QDataStream stream(&ba, QIODevice::ReadWrite);

    qDebug() << "send " <<(Request)request;
    stream<< request;

    for(auto it = params.begin(); it != params.end(); ++it){
           stream<< *it;
    }


    clientSocket->write(ba);
    clientSocket->flush();

}

void Client::fillMainList()
{
    qDebug() << "fillllllllll";

//      connect(this, &Client::getAnswer,  [this] (QVector <Product> products){

//           this->setMainProductModel(products);
//           qDebug() << "have!!!!! " << products.size() << " OK";
//      });

//      sendRequest(getGoods);

}

//void Client::setMainProductModel(QVector<Product> products)
//{
//    QVector<QObject*> productsModel;

//    for(QVector <Product>::iterator it = products.begin(); it != products.end(); ++it){
//        productsModel.append(it);
//    }


 //   qDebug() << "setMainProductModel";

//    Product * pr = new Product();
//    pr->setId(2);
//    pr->setName("name'");
//    pr->setPrice(255);
//    productsModel.append(pr);


//   Product * pr2 = new Product();
//   pr2->setId(2);
//   pr2->setName("name'");
//   pr2->setPrice(255);

//   productsModel.append(pr2);
//   productsModel.append(pr);



    //qml_root_context->setContextProperty("mainModel", QVariant::fromValue(productsModel));
//}


void Client::readAnswerFromServer()
{
    qDebug() << "we ahve answer";
    QByteArray ba =  clientSocket->readAll();

    QDataStream in(&ba, QIODevice::ReadOnly);

     int answerCommand;
      in >> answerCommand;

     qDebug()<<"answer command" << answerCommand;

   switch (answerCommand) {
   case getGoods:
   {
//       QVector <Product> products;
//       in >> products;

//       qDebug() << "products size " <<products.size();

       //emit getAnswer(products);

     }
       break;

   case newUser:

         qDebug() << "user is created";

         break;

   case auth:
         {
           bool answer;
           in >> answer;

           if (answer)
               qDebug() << "user is exist";
           else
               qDebug() << "user is not exist";

           break;
         }
   case testPing:

       break;

    case error:
            {
                 QString errorStr;
                 in >> errorStr;
                 qDebug() << "error" << errorStr;
                 break;
            }

   default:
       break;
   }


     //qDebug() << "answer: "<<answer;
}


void Client::setQmlRootContext(QQmlContext *root)
{
    if (qml_root_context == root)
        return;
    qml_root_context = root;


}


void Client::setQmlRoot(QObject *root)
{
    if (qml_root == root)
        return;

    qml_root = root;
}
