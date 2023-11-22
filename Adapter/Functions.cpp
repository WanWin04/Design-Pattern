#include "Functions.hpp"

IWeatherStation::~IWeatherStation() {}

WeatherStation::WeatherStation() : location("Unknown"), temperature(0), humidity(0), chancesOfRain(0) {}

WeatherStation::WeatherStation(std::string _location) : location(_location), temperature(0), humidity(0), chancesOfRain(0) {}

void WeatherStation::update() {
    temperature = rand() % 20 + 15;
    humidity = rand() % 100;
    chancesOfRain = rand() % 100;
}

std::string WeatherStation::report() {
    return location +
        " STATION:" + "\n\tTemperature: " + std::to_string(temperature) +
        "\n\tHumidity: " + std::to_string(humidity) +
        "%\n\tChances Of Rain: " + std::to_string(chancesOfRain) + "%\n";
}

WeatherApp::~WeatherApp() {
    for (IWeatherStation* station : stations) {
        delete station;
    }
}

void WeatherApp::report() {
    for (IWeatherStation* station : stations) {
        station->update();
        std::cout << station->report();
    }
}
