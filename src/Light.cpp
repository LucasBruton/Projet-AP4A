/**
 * @author Lucas BRUTON
 * @file Light.cpp
 * @date 09/10/2021
 * @brief La classe Light hérite de la classe Sensor et représente un capteur de luminosité
 */

#include "Light.hpp"
#include "Sensor.hpp"
#include "TypeSensor.hpp"
#include "Type.hpp"
#include <chrono>
#include <random>

Light::Light() {
    this->m_data.setData(70);
    this->m_data.setTypeSensor(e_light);
}

Light::Light(const Light& light) {
    this->m_data = light.m_data;
}

Light& Light::operator=(const Light& light) {
    this->m_data = light.m_data;

    return *this;
}

bool Light::aleaGenVal() {
    /*
    * initialisation des variables utilisées pour générer un int aléatoire
    * compris entre previousData - maxChange et previousData + maxChange
    */
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> distribution(0, 1);

    return (bool) distribution(engine);
}

Type<bool>& Light::getData() {
    // Génère des nouvelles données
    this->m_data.setData(this->aleaGenVal());

    return this->m_data;
}