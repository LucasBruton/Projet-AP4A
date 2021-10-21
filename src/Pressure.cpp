/**
 * @author Lucas BRUTON
 * @file Pressure.cpp
 * @date 09/10/2021
 * @brief La classe Pressure hérite de la classe Sensor et représente un capteur de pression.
 */

#include "Pressure.hpp"
#include "Sensor.hpp"
#include "TypeSensor.hpp"
#include "Type.hpp"
#include <chrono>
#include <random>

Pressure::Pressure() {
    this->m_data.setData(1000000);
    this->m_data.setTypeSensor(e_pressure);
}

Pressure::Pressure(const Pressure& pressure) {
    this->m_data = pressure.m_data;
}

Pressure& Pressure::operator=(const Pressure& pressure) {
    this->m_data = pressure.m_data;

    return *this;
}

int Pressure::aleaGenVal() {
    // Cette variable contiendra les nouvelles données générer par le capteur.
    int newData;

    /*
    * initialisation des variables utilisées pour générer un int aléatoire
    * compris entre previousData - maxChange et previousData + maxChange
    */
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> distribution(this->m_data.getData() - this->MAX_TEMPERATURE_CHANGE, this->m_data.getData() + this->MAX_TEMPERATURE_CHANGE);

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

Type<int>& Pressure::getData() {
    // Génère des nouvelles données
    this->m_data.setData(this->aleaGenVal());

    return this->m_data;
}