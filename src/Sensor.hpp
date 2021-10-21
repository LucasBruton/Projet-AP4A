/**
 * @author Lucas BRUTON
 * @file Sensor.hpp
 * @date 05/10/2021
 * @brief La classe Sensor permet de générer des données qui seront ensuite remontées. 
 * Cette classe est une classe abstraite qui a pour objectif d'être la classe mère des différents types de capteurs. 
 */

#ifndef SENSOR_H
#define SENSOR_H

#include "Type.hpp"

template<class T> class Sensor {
    protected:
        // Cette variable contient les données du capteur
        Type<T> m_data;
    
    protected: 
        /**
         * @brief Cette fonction permet de générer des nouvelles données.
         * Cette fonction est une méthode virtuelle pure.
         * @return T - Nouvelles données "mesurées" par le capteur
         */
        virtual T aleaGenVal() = 0;

    public:
        // Définition de la forme canonique
        Sensor<T>(): m_data(){};
        Sensor<T>(const Sensor& sensor): m_data(sensor.m_data){};
        Sensor<T>& operator=(const Sensor& server) {
            this->m_data = server.m_data;
            return *this;
        };
        virtual ~Sensor<T>(){};

        /**
         * @brief Cette fonction renvoie les données du capteur
         * @return Type
         */
        virtual Type<T>& getData() {
            return this->m_data;
        };
};

#endif // SENSOR_H