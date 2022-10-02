#include "mview.h"


MView::MView(QWidget *parent)
{
    init();
}

MView::MView(QGraphicsScene *scene, QWidget *parent)
{
    this->setScene(scene);
    init();
}

void MView::init()
{
    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing
                         | QPainter::HighQualityAntialiasing | QPainter::LosslessImageRendering);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
}
