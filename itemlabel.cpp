#include "itemlabel.h"


#include <QCursor>
#include <QDrag>
#include <QMimeData>

ItemLabel::ItemLabel(QString _name, QString _pixmap, QWidget *parent)
    : QLabel(parent)
    , name(_name)
    , mpixmap(_pixmap)
{

    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QImage image(mpixmap);
    this->setPixmap(QPixmap::fromImage(image));
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
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}

void ItemLabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
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

