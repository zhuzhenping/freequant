#ifndef FQ_TRADE_TRADEPROVIDER_H
#define FQ_TRADE_TRADEPROVIDER_H

#include <map>
#include <string>
#include <vector>

#include <freequant/strategy/Order.h>

namespace FreeQuant {

class Instrument;
class Bar;

class TradeProviderCallback {
public:
    virtual ~TradeProviderCallback() {}
    virtual void onConnected() = 0;
    virtual void onDisconnected() = 0;
};

class TradeProvider {
public:
    typedef std::map<std::string, std::string> Params;
    class Callback {
    public:
        virtual ~Callback() {}
    };

    virtual ~TradeProvider() {}
    virtual void connect() = 0;
    virtual void connect(const std::string& connection, bool block = false) = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
    virtual std::string name() const = 0;

    virtual std::vector<std::string> availableExchanges() const = 0;
    virtual std::vector<std::string> availableInstruments() const = 0;

    virtual void sendOrder(const FreeQuant::Order& order) = 0;
    virtual void cancelOrder(const FreeQuant::Order& order) = 0;
    virtual void replaceOrder(const FreeQuant::Order& order) = 0;

    virtual void openOrders() const {}
    virtual void fetchOrders(const std::string& symbol, const DateTime& start, const DateTime& end) = 0;
    virtual void fetchTrades(const std::string& symbol, const DateTime& start, const DateTime& end) = 0;
    virtual void updatePosition(const std::string& symbol) = 0;
    virtual void updateIntrument(const std::string& symbol, bool block = false) = 0;
    virtual void updateIntrument(FreeQuant::Instrument& instrument) = 0;

    virtual void updateAccount(bool block = false) = 0;

    virtual bool orderTypeSupported(FreeQuant::Order::OrderType type) = 0;
};

class DefaultTradeProviderCallback : public TradeProvider::Callback {
public:
    void onConnected() {}
    void onDisconnected() {}
};

}

#endif // FQ_TRADE_TRADEPROVIDER_H
