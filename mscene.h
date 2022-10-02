#ifndef MSCENE_H
#define MSCENE_H

#include <QGraphicsScene>

class MScene : public QGraphicsScene
{
public:
    explicit MScene(QObject *parent = nullptr);
    ~MScene();
};

#endif // MSCENE_H
