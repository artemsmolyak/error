#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QObject>
#include <QQmlContext>
#include <../CommonFiles/product.h>
#include <../CommonFiles/const.h>


class Client : public QObject
{
    Q_OBJECT

    QTcpSocket * clientSocket;
    QQmlContext *qml_root_context;
    QObject * qml_root;

public:
    Client();
    ~Client();

    void setQmlRootContext(QQmlContext *root);
    void setQmlRoot(QObject *root);

    void sendRequest(Request request, QVector<QString> params = QVector<QString>());

    Q_INVOKABLE void fillMainList();

    //void setMainProductModel(QVector <Product> products);


 public slots:
    void readAnswerFromServer();

signals:
   // void getAnswer(QVector <Product> products);

};

#endif // CLIENT_H
