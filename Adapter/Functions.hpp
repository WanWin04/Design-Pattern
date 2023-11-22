#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>

class IWeatherStation {
public:
    virtual ~IWeatherStation();
    virtual void update() = 0;
    virtual std::string report() = 0;
};

class WeatherStation : public IWeatherStation {
private:
    std::string location;
    int temperature, humidity, chancesOfRain;

public:
    WeatherStation();
    WeatherStation(std::string _location);

    void update() override;
    std::string report() override;
};

class WeatherApp {
public:
    std::vector<IWeatherStation*> stations;
    ~WeatherApp();

    void report();
};

#endif // FUNCTIONS_HPP
