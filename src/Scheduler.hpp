/**
 * @author Lucas BRUTON
 * @file Scheduler.hpp
 * @date 09/10/2021
 * @brief La classe Scheduler est le cerveau du sous marin. 
 * Il récupère régulièrement les données capteurs pour les transmettre au serveur.
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <thread>
#include <chrono>
#include <mutex>

class Scheduler {
    private:
        // Capteurs
        Temperature m_temperatureSensor;
        Humidity m_humiditySensor;
        Pressure m_pressureSensor;
        Light m_lightSensor;
        Server m_server;

        // Ce mutex est utilisé pour éviter que le serveur traite les données de plusieurs capteurs en même temps
        std::mutex m_mutexServer;

        /**
         * Nombre de fois que le scheduler va récupérer les données du capteur 
         * avant de terminer la simulation du sous marin.
         */
        unsigned int m_simulationTime;

        // Tempe d'attente entre chaque récupération des données des capteurs
        unsigned int m_temperatureSensorSleepTime;
        unsigned int m_humiditySensorSleepTime;
        unsigned int m_pressureSensorSleepTime;
        unsigned int m_lightSensorSleepTime;

    public:
        // Définition de la forme canonique
        Scheduler(): m_temperatureSensor(), m_humiditySensor(), m_pressureSensor(), 
            m_lightSensor(), m_server(true, true, "logs_sensors/"), m_mutexServer(), 
            m_simulationTime(10000), m_temperatureSensorSleepTime(1000), 
            m_humiditySensorSleepTime(1500), m_pressureSensorSleepTime(2000), 
            m_lightSensorSleepTime(2500) {};
        Scheduler(const Scheduler& scheduler): m_temperatureSensor(scheduler.m_temperatureSensor), 
            m_humiditySensor(scheduler.m_humiditySensor), m_pressureSensor(scheduler.m_pressureSensor), 
            m_lightSensor(scheduler.m_lightSensor), m_server(scheduler.m_server), m_mutexServer(), 
            m_simulationTime(scheduler.m_simulationTime), m_temperatureSensorSleepTime(scheduler.m_temperatureSensorSleepTime), 
            m_humiditySensorSleepTime(scheduler.m_humiditySensorSleepTime), m_pressureSensorSleepTime(scheduler.m_pressureSensorSleepTime), 
            m_lightSensorSleepTime(scheduler.m_lightSensorSleepTime) {};
        virtual ~Scheduler(){};
        Scheduler& operator=(const Scheduler& scheduler);

        /**
         * @brief Ce constructeur permet de définir le nombre de fois que le scheduler va récupérer les données des capteurs
         * et la durée d'attente entre chaque récupération.
         * @param simulationTime - Durée de la simulation
         * @param temperatureSensorSleepTime - temps d'attente en millisecondes entre chaque récupération des données du capteur de température
         * @param humiditySensorSleepTime - temps d'attente en millisecondes entre chaque récupération des données du capteur d'humidité
         * @param pressureSensorSleepTime - temps d'attente en millisecondes entre chaque récupération des données du capteur de pression
         * @param lightSensorSleepTime - temps d'attente en millisecondes entre chaque récupération des données du capteur de lumière
         */
        Scheduler(const unsigned int& simulationTime, const unsigned int& temperatureSensorSleepTime, const unsigned int& humiditySensorSleepTime,
        const unsigned int& pressureSensorSleepTime, const unsigned int& lightSensorSleepTime): 
        m_temperatureSensor(), m_humiditySensor(), m_pressureSensor(), m_lightSensor(), m_server(true, true, "logs_sensors/"),
        m_simulationTime(simulationTime), m_temperatureSensorSleepTime(temperatureSensorSleepTime), 
        m_humiditySensorSleepTime(humiditySensorSleepTime), m_pressureSensorSleepTime(pressureSensorSleepTime), 
        m_lightSensorSleepTime(lightSensorSleepTime) {};

        /**
         * @brief Cette fonction lance la simulation du sous marin en lancant un thread pour chaque capteur.
         * @return void
         */
        void runSimulation();


        /**
         * @brief Cette fonction lance la récupération + le transfère des données d'un capteur au serveur.
         * @param sensor - capteur donet les données sont récupérés et envoyés 
         * @param sleepTime - temps entre chaque récupération des données
         * @param numberOfIterations - nombre de fois que les données sont récupérées
         * @return void
         */
        template<class T> void sensorDataTransfer(Sensor<T>& sensor, int sleepTime, int numberOfIterations) {
            for(int i = 1; i <= numberOfIterations; ++i) {
                // On vérouille le mutex puisque this->m_server est une ressource critique
                this->m_mutexServer.lock();
                this->m_server.dataRcv(sensor.getData());
                // On déverouille le mutex
                this->m_mutexServer.unlock();
                
                // Si i < numberOfIterations, le thread s'endort?
                if(i != numberOfIterations) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
                }
            }
        };
};

#endif
