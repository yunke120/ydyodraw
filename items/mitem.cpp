#include "mitem.h"

#include <QPainter>
MItem::MItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

MItem::~MItem()
{

}

QString MItem::nameString() const
{
    return name;
}

/**********
 *                   Rect
**********/

MItemRect::MItemRect(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Rect";
}

MItemRect::~MItemRect()
{

}

QRectF MItemRect::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void MItemRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());
}

/**********
 *                   Ellipse
**********/

MItemEllipse::MItemEllipse(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Ellipse";
}

MItemEllipse::~MItemEllipse()
{

}

QRectF MItemEllipse::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void MItemEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->boundingRect());
}
