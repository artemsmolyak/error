#include "product.h"

Product::Product()
{

}

//Product::Product(QObject *parent):QObject(parent)
//{
//    m_id = 1;
//    m_name = "sdfsdfds";
//}

//Product::Product(int id, QString name, QImage pic, int price):
//    m_id(id), m_name(name), m_pic(pic), m_price(price)
//{

//}

//Product::Product(int id, QString name, int price):
//     m_id(id), m_name(name), m_price(price)
//{

//}

Product::Product(const Product &data)
{
     //m_id = data.m_id;
//    name = data.getName();
//    pic = data.getPic();
//    price = data.getPrice();
}



//int Product::id() const
//{
//    return m_id;
//}

//void Product::setId(int value)
//{
//    m_id = value;
//}

//QString Product::name() const
//{
//    return m_name;
//}

//void Product::setName(const QString &value)
//{
//    m_name = value;
//}

//QImage Product::pic() const
//{
//    return m_pic;
//}

//void Product::setPic(const QImage &value)
//{
//    m_pic = value;
//}

//int Product::price() const
//{
//    return m_price;
//}

//void Product::setPrice(int value)
//{
//    m_price = value;
//}



Product Product::operator =(Product data)
{
//    this->m_id = data.m_id;
////    this->name = data.getName();
////    this->pic = data.getPic();
////    this->price = data.getPrice();

    return *this;
}

Product::~Product()
{

}

//QDataStream& operator <<(QDataStream& stream, const Product& data)
//{
//     stream << data.id() << data.name() << data.price();
//}

//QDataStream& operator >>(QDataStream& stream, Product & data)
//{
//    int id;
//    stream >> id;
//    data.setId(id);

//    QString name;
//    stream >> name;
//    data.setName(name);

//    int price;
//    stream >> price;
//    data.setPrice(price);

//    return stream;
//}
