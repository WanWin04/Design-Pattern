#include "Functions.hpp"

class NewStation {
public:
    NewStation();
    NewStation(std::string _location);

    void update();
    std::string n_report(int choice);

private:
    std::string location;
    int temperature, humidity, chancesOfRain;
};

class ObjectAdaperStation : public IWeatherStation {
public:
    ObjectAdaperStation();
    ObjectAdaperStation(NewStation* ns);

    void update() override;
    std::string report() override;

private:
    NewStation* nSt;
};

class ClassAdapterStation : public IWeatherStation, public NewStation {
public:
    ClassAdapterStation();
    ClassAdapterStation(std::string _location);

    void update() override;
    std::string report() override;
};

int main() {
    WeatherApp wa;
    wa.stations.push_back(new ObjectAdaperStation(new NewStation("ROME")));
    wa.stations.push_back(new ClassAdapterStation("AMSTERDAM"));
    wa.report();

    return 0;
}
