#ifndef REFLECT_H
#define REFLECT_H

#include <QtCore>
#include <QObject>

class Reflect
{
public:
    template<typename T>
    static void registerClass()
    {
        constructors().insert( T::staticMetaObject.className(), &constructorHelper<T> );
    }

    static QObject* newInstance( const QByteArray& className, QWidget* parent = nullptr )
    {
        Constructor constructor = constructors().value( className );
        if ( constructor == nullptr )
            return nullptr;
        return (*constructor)( parent );
    }

private:
    typedef QObject* (*Constructor)( QWidget* parent );

    template<typename T>
    static QObject* constructorHelper( QWidget* parent )
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
