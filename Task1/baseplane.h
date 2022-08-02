#ifndef BASEPLANE_H
#define BASEPLANE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
class BasePlane
{
protected:
    QWidget* m_widget;
    int x, y, w, h;
public:
    BasePlane(QWidget*);
    void Draw(QPainter* qp);
    void Move(QPainter* qp);
};

#endif // BASEPLANE_H
