/**
 * @author Lucas BRUTON
 * @file Scheduler.cpp
 * @date 09/10/2021
 * @brief La classe Scheduler est le cerveau du sous marin. 
 * Il récupère régulièrement les données capteurs pour les transmettre au serveur.
 */

#include "Scheduler.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"
#include "Sensor.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <utility>
#include <cmath>
using namespace std; 

Scheduler& Scheduler::operator=(const Scheduler& scheduler) {
    this->m_humiditySensor = scheduler.m_humiditySensor;
    this->m_lightSensor = scheduler.m_lightSensor;
    this->m_pressureSensor = scheduler.m_pressureSensor;
    this->m_temperatureSensor = scheduler.m_temperatureSensor;
    this->m_server = scheduler.m_server;
    this->m_simulationTime = scheduler.m_simulationTime;
    this->m_temperatureSensorSleepTime = scheduler.m_temperatureSensorSleepTime;
    this->m_humiditySensorSleepTime = scheduler.m_humiditySensorSleepTime;
    this->m_pressureSensorSleepTime = scheduler.m_pressureSensorSleepTime;
    this->m_lightSensorSleepTime = scheduler.m_lightSensorSleepTime;

    return *this;
}

void Scheduler::runSimulation() {
    cout << "Lancement de la simulation ...\n\n";

    // On lance un thread par capteur
    std::thread threadTemperatureSensor([&]() {this->sensorDataTransfer(this->m_temperatureSensor, this->m_temperatureSensorSleepTime, round(this->m_simulationTime / this->m_temperatureSensorSleepTime)); });
    std::thread threadHumiditySensor([&]() {this->sensorDataTransfer(this->m_humiditySensor, this->m_humiditySensorSleepTime, round(this->m_simulationTime / this->m_humiditySensorSleepTime)); });
    std::thread threadPressureSensor([&]() {this->sensorDataTransfer(this->m_pressureSensor, this->m_pressureSensorSleepTime, round(this->m_simulationTime / this->m_pressureSensorSleepTime)); });
    std::thread threadLightSensor([&]() {this->sensorDataTransfer(this->m_lightSensor, this->m_lightSensorSleepTime, round(this->m_simulationTime / this->m_lightSensorSleepTime)); });
    
    // On attend la fin de tous les threads
    threadTemperatureSensor.join();
    threadHumiditySensor.join();
    threadPressureSensor.join();
    threadLightSensor.join();

    cout << "Fin de la simulation ...\n";
}