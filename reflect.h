#ifndef REFLECT_H
#define REFLECT_H

#include <QByteArray>
#include <QMetaObject>
#include <QHash>
#include <QGraphicsObject>
class Reflect
{
public:
    template<typename T>
    static void registerClass()
    {
        constructors().insert( T::staticMetaObject.className(), &constructorHelper<T> );
    }

    static QGraphicsObject* createObject( const QByteArray& className, QGraphicsObject* parent = NULL )
    {
        Constructor constructor = constructors().value( className );
        if ( constructor == NULL )
            return NULL;
        return (*constructor)( parent );
    }

private:
    typedef QGraphicsObject* (*Constructor)( QGraphicsObject* parent );

    template<typename T>
    static QGraphicsObject* constructorHelper( QGraphicsObject* parent )
    {
        return new T( parent );
    }

    static QHash<QByteArray, Constructor>& constructors()
    {
        static QHash<QByteArray, Constructor> instance;
        return instance;
    }
};


#endif // REFLECT_H
