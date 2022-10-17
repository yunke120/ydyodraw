#include "mitem.h"

#define Item_Width       40
#define Item_Height      40
#define Item_Width_Div2  20
#define Item_Height_Div2 20

#include <QPainter>
MItem::MItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    this->setAcceptedMouseButtons(Qt::LeftButton /*| Qt::RightButton*/);
    //this->setAcceptHoverEvents(true);
    this->setFlags(  QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   /*| QGraphicsItem::ItemIsFocusable*/);
}

MItem::~MItem()
{

}

QString MItem::nameString() const
{
    return name;
}

void MItem::drawSelectedRect(QPainter *painter)
{
    QRectF rect = this->boundingRect();

    painter->setPen(QPen(QColor(8,255,200), 0, Qt::DashLine));
    painter->setBrush(Qt::NoBrush);

    painter->drawRect(rect.adjusted(-1, -1, 1, 1));
}

void MItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

}

void MItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}

/**********
 *                   Rect
**********/

MItemRect::MItemRect(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Rect";
}

QRectF MItemRect::boundingRect() const
{
    return QRectF(-Item_Width_Div2,-Item_Height_Div2,Item_Width,Item_Height);
}

void MItemRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());

    if(this->isSelected())
        this->drawSelectedRect(painter);
}

/**********
 *                   Ellipse
**********/

MItemEllipse::MItemEllipse(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Ellipse";
}

QRectF MItemEllipse::boundingRect() const
{
    return QRectF(-Item_Width_Div2,-Item_Height_Div2,Item_Width,Item_Height);
}

void MItemEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->boundingRect());

    if(this->isSelected())
        this->drawSelectedRect(painter);
}


/**********
 *                   Text
**********/
MItemText::MItemText(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Text";
    m_text = name;
    m_font.setPixelSize(Item_Width_Div2);
}

QRectF MItemText::boundingRect() const
{
    int size = m_font.pixelSize();
    int count = m_text.size();
    return QRectF(-size/2*count/2,-size/2,size*count/2,size);
}

void MItemText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget); Q_UNUSED(option);

    painter->setRenderHint(QPainter::TextAntialiasing, true);
    painter->setFont(m_font);
    painter->drawText(this->boundingRect(), m_text);

    if(this->isSelected())
        this->drawSelectedRect(painter);
}

#include <QInputDialog>
void MItemText::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    bool ok;
    QString text = QInputDialog::getText(nullptr, nullptr,
                                        tr("Input:"), QLineEdit::Normal,nullptr, &ok);
    if (ok && !text.isEmpty())
    {
        m_text = text;
        update();
    }
}
