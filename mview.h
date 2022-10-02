#ifndef MVIEW_H
#define MVIEW_H

#include <QGraphicsView>

class MView : public QGraphicsView
{
public:
    explicit MView(QWidget *parent = nullptr);
    explicit MView(QGraphicsScene *scene, QWidget *parent = nullptr);

protected:

    void init(void);
};

#endif // MVIEW_H
