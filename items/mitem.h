#ifndef MITEM_H
#define MITEM_H

#include <QGraphicsItem>

class MItem : public QGraphicsObject
{
    Q_OBJECT
public:
    MItem(QGraphicsItem *parent = nullptr);
    ~MItem();

    QString nameString() const;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) = 0;

protected:
    QString name = "base";
};


class MItemRect : public MItem
{
    Q_OBJECT
public:
    MItemRect(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};


class MItemEllipse : public MItem
{
    Q_OBJECT
public:
    MItemEllipse(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#include <QFont>
class MItemText : public MItem
{
    Q_OBJECT
public:
    MItemText(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QFont m_font;
    QString m_text;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MITEM_H
