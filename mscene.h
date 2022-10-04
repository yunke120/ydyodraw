#ifndef MSCENE_H
#define MSCENE_H

#include <QGraphicsScene>

class MScene : public QGraphicsScene
{
public:
    explicit MScene(QObject *parent = nullptr);
    ~MScene();

private:
    QPointF releasePoint;
    QByteArray getItemClassName(QByteArray &name) const;

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

};

#endif // MSCENE_H
