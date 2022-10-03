#ifndef ITEMLABEL_H
#define ITEMLABEL_H

#include <QLabel>
#include <QMetaObject>
#include <QObject>
#include <QDrag>
class ItemLabel : public QLabel
{
    Q_OBJECT
public:
    ItemLabel(QWidget *parent = nullptr);
    ~ItemLabel();

    QString nameString() const;

protected:

    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
    virtual void enterEvent(QEvent *ev) override;
    virtual void leaveEvent(QEvent *ev) override;

    QString name = "base";
};


class ItemRectLabel : public ItemLabel
{
    Q_OBJECT
public:
    ItemRectLabel(QWidget *parent = nullptr);
};

class ItemEllipseLabel : public ItemLabel
{
    Q_OBJECT
public:
    ItemEllipseLabel(QWidget *parent = nullptr);
};


#endif // ITEMLABEL_H
