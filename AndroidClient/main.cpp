#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <../TcpClient/client.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Client client;
    QQmlContext * context = engine.rootContext();
    context->setContextProperty("client", &client);
    client.setQmlRootContext(context);
    client.setQmlRoot(engine.rootObjects().value(0));


    //engine.setOfflineStoragePath(QDir::homePath() + "/AndroidDiary");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
