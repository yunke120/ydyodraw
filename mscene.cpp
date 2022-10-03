#include "mscene.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDebug>
MScene::MScene(QObject *parent)
    : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QColor("#cdcdcd"));
}

MScene::~MScene()
{

}

void MScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasFormat("items"))
        event->setAccepted(true);
}

void MScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasFormat("items"))
        event->setAccepted(true);
}

void MScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QByteArray data = event->mimeData()->data("items");
    qDebug() << QString(data);
//    QGraphicsItem *item = new
}
