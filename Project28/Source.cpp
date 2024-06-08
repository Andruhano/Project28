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
        return "���������� �������� ��� ���������� �� " + startPoint + " �� " + endPoint + " �� �������";
    }
};

class WalkingRouteStrategy : public RouteStrategy 
{
public:
    string buildRoute(const string& startPoint, const string& endPoint) const override 
    {
        return "���������� �������� ��� ������ ������������ �� " + startPoint + " �� " + endPoint + " �� ��������� � ���������� ��������";
    }
};

class PublicTransportRouteStrategy : public RouteStrategy 
{
public:
    string buildRoute(const string& startPoint, const string& endPoint) const override 
    {
        return "���������� �������� ��� ������������� ���������� �� " + startPoint + " �� " + endPoint + " � �������������� ���������, ����� � ������� ����������";
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
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    navigator.setStrategy(&walkingStrategy);
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    navigator.setStrategy(&publicTransportStrategy);
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    return 0;
}
