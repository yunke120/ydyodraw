#include "itemlabel.h"


#include <QCursor>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
ItemLabel::ItemLabel(QWidget *parent)
    : QLabel(parent)
{
    this->setMaximumWidth(30);
    this->setMinimumWidth(30);

    this->setMaximumHeight(30);
    this->setMinimumHeight(30);

}

ItemLabel::~ItemLabel()
{

}

QString ItemLabel::nameString() const
{
    return name;
}

void ItemLabel::mouseMoveEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void ItemLabel::mousePressEvent(QMouseEvent *ev)
{
    setCursor(Qt::OpenHandCursor);
    QMimeData *mime = new QMimeData();
//    this->metaObject()->className();
    mime->setData("items", nameString().toLatin1());
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mime);
    drag->setPixmap(*(this->pixmap()));
    drag->setHotSpot(QPoint(width()>>2,height()>>2));

    drag->exec(Qt::CopyAction);
}

void ItemLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    setCursor(Qt::ArrowCursor);
}

void ItemLabel::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    setCursor(Qt::PointingHandCursor);
}

void ItemLabel::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    setCursor(Qt::ArrowCursor);
}

/* Rect */
ItemRectLabel::ItemRectLabel(QWidget *parent)
    : ItemLabel(parent)
{
    name = "Rect";
    QImage image(":/Resource/images/Rect.png");
    this->setPixmap(QPixmap::fromImage(image.scaled(30,30)));
}

/* Ellipse */
ItemEllipseLabel::ItemEllipseLabel(QWidget *parent)
    : ItemLabel(parent)
{
    name = "Ellipse";
    QImage image(":/Resource/images/Ellipse.png");
    this->setPixmap(QPixmap::fromImage(image.scaled(30,30)));
}














// https://www.cnblogs.com/liushui-sky/p/6559973.html
