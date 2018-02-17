#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include "QString"
#include <QImage>

class Product : public QObject
{
    Q_OBJECT

//    int m_id;
//    QString m_name;
//    QImage m_pic;
//    int m_price;


//    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
//    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
//    Q_PROPERTY(int price READ price WRITE setPrice NOTIFY priceChanged)


public:
    Product();
//    Product(QObject *parent = NULL);
//    Product(int id, QString name, QImage pic,  int price);
//    Product(int id, QString name, int price);

    Product(const Product &data);
    Product operator=(Product prod);

    ~Product();

//    int id() const;
//    void setId(int value);

//    QString name() const;
//    void setName(const QString &value);

//    QImage pic() const;
//    void setPic(const QImage &value);

//    int price() const;
//    void setPrice(int value);


public slots:


signals:
//    void idChanged();
//    void nameChanged();
//    void priceChanged();
};


//QDataStream& operator <<(QDataStream& stream, const Product& data);

//QDataStream& operator >>(QDataStream& stream, Product& data);

//Q_DECLARE_METATYPE(Product)

#endif // PRODUCT_H
