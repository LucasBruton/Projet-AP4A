/**
 * @author Lucas BRUTON
 * @file Humidity.cpp
 * @date 09/10/2021
 * @brief La classe Humidity hérite de la classe Sensor et représente un capteur de humidité
 */

#include "Humidity.hpp"
#include "Sensor.hpp"
#include "TypeSensor.hpp"
#include "Type.hpp"
#include <chrono>
#include <random>

Humidity::Humidity() {
    this->m_data.setData(51.5f);
    this->m_data.setTypeSensor(e_humidity);
}

Humidity::Humidity(const Humidity& humidity) {
    this->m_data = humidity.m_data;
}

Humidity& Humidity::operator=(const Humidity& humidity) {
    this->m_data = humidity.m_data;

    return *this;
}

float Humidity::aleaGenVal() {
    // Cette variable contiendra les nouvelles données générer par le capteur.
    float newData;

    /*
    * initialisation des variables utilisées pour générer un int aléatoire
    * compris entre previousData - maxChange et previousData + maxChange
    */
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_real_distribution<float> distribution(this->m_data.getData() - this->MAX_TEMPERATURE_CHANGE, this->m_data.getData() + this->MAX_TEMPERATURE_CHANGE);

    /*
    * newData = [previousData - maxChange; previousData + maxChange]
    * Si newData < MIN_TEMPERATURE, alors newData = MIN_TEMPERATURE.
    * Si newData > MAX_TEMPERATURE, alors newData = MAX_TEMPERATURE;
    */
    newData = distribution(engine);
    if(newData < this->MIN_TEMPERATURE) {
        newData = this->MIN_TEMPERATURE;
    }else if(newData > this->MAX_TEMPERATURE) {
        newData = this->MAX_TEMPERATURE;
    }

    return newData;
}

Type<float>& Humidity::getData() {
    // Génère des nouvelles données
    this->m_data.setData(this->aleaGenVal());

    return this->m_data;
}