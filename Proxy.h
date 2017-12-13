//
// Created by Paweł Kulig on 12.12.2017.
//

#ifndef WZORCE2_PROXY_H
#define WZORCE2_PROXY_H


#include <string>

class Weather;

class Proxy {
    Weather *w_p;
    static int counter;

public:
    Proxy();

    virtual ~Proxy();

    Weather *checkWeather();

    //void setWeather(Weather *w);

};

class Weather
{
    std::string name;
    int time;
    int beufortScale;
    int id;
    static int nextId;

public:
    Weather()
    {
        name = "sunny";
        time = 1;
        beufortScale = 2;
        id = nextId++;
    }

    const std::string &getName() const;

    void setName(const std::string &name);

    int getTime() const;

    void setTime(int time);

    int getBeufortScale() const;

    void setBeufortScale(int beufortScale);

    int getId() const;

    void setId(int id);

};


#endif //WZORCE2_PROXY_H
