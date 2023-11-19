#ifndef __REST__

#define __REST__

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>                //Qt libraries
#include <QObject>
#include <QtCore>
#include <QUrl>

#include <iostream> //CPP libraries
#include <string>

// #define Q_OBJECT

namespace Rest
{

    class RestHttpHandler: public QObject
    {
            Q_OBJECT

        public:
            RestHttpHandler(QObject* parent = nullptr);
            ~RestHttpHandler();

            void                set_endpoint(const std::string &);
            std::string         get_endpoint() const;
            void                produce_data();
            QByteArray          buffer() const;
            void                close();

        signals:
            void done();

        public slots:
            void                done_producing(QNetworkReply *);
    

        private:

            QNetworkAccessManager* nam;
            
            QByteArray _buffer;
            std::string _endpoint;
        };
    }

#endif