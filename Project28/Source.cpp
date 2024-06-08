#include <iostream>
#include <string>
using namespace std;

class RouteStrategy 
{
public:
    virtual ~RouteStrategy() = default;
    virtual string buildRoute(const string& startPoint, const string& endPoint) const = 0;
};

class CarRouteStrategy : public RouteStrategy 
{
public:
    string buildRoute(const string& startPoint, const string& endPoint) const override 
    {
        return "Построение маршрута для автомобиля от " + startPoint + " до " + endPoint + " по дорогам";
    }
};

class WalkingRouteStrategy : public RouteStrategy 
{
public:
    string buildRoute(const string& startPoint, const string& endPoint) const override 
    {
        return "Построение маршрута для пешего передвижения от " + startPoint + " до " + endPoint + " по тротуарам и пешеходным дорожкам";
    }
};

class PublicTransportRouteStrategy : public RouteStrategy 
{
public:
    string buildRoute(const string& startPoint, const string& endPoint) const override 
    {
        return "Построение маршрута для общественного транспорта от " + startPoint + " до " + endPoint + " с использованием автобусов, метро и другого транспорта";
    }
};

class Navigator 
{
    RouteStrategy* strategy;
public:
    Navigator(RouteStrategy* initialStrategy) : strategy(initialStrategy) {}

    void setStrategy(RouteStrategy* newStrategy) 
    {
        strategy = newStrategy;
    }

    string buildRoute(const string& startPoint, const string& endPoint) const 
    {
        return strategy->buildRoute(startPoint, endPoint);
    }
};

int main() 
{
    system("chcp 1251");

    CarRouteStrategy carStrategy;
    WalkingRouteStrategy walkingStrategy;
    PublicTransportRouteStrategy publicTransportStrategy;

    Navigator navigator(&carStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    navigator.setStrategy(&walkingStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    navigator.setStrategy(&publicTransportStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    return 0;
}
