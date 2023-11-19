#include "rest_http_handler.hpp"

#include <QDebug>

namespace Rest
{
    RestHttpHandler::RestHttpHandler(QObject* parent)
    : QObject(parent), 
      nam(new QNetworkAccessManager()) {

        connect(nam, &QNetworkAccessManager::finished, this, &RestHttpHandler::done_producing);
      }
    RestHttpHandler::~RestHttpHandler(){
        if (nam) nam->deleteLater();
    }
    void RestHttpHandler::set_endpoint(const std::string& endpoint){ _endpoint = endpoint; }

    std::string RestHttpHandler::get_endpoint() const { return _endpoint; }

    void RestHttpHandler::produce_data(){
        auto valid_url = QUrl(QString::fromStdString(this->get_endpoint()));
        nam->get(QNetworkRequest(valid_url));
    }

    void RestHttpHandler::done_producing(QNetworkReply *data){
        _buffer = data->readAll();

        emit done();
    }

    void RestHttpHandler::close(){ if (nam) nam->deleteLater(); }

    QByteArray RestHttpHandler::buffer() const { return _buffer; }
}