#ifndef ITEMLABEL_H
#define ITEMLABEL_H

#include <QLabel>
#include <QObject>
#include <QDrag>
class ItemLabel : public QLabel
{
    Q_OBJECT
public:
    ItemLabel(QString _name, QString _pixmap, QWidget *parent = nullptr);
    ~ItemLabel();

    QString nameString() const;

protected:

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void enterEvent(QEvent *ev) override;
    void leaveEvent(QEvent *ev) override;

    QString name = "base";
    QString mpixmap = nullptr;
};

#endif // ITEMLABEL_H
