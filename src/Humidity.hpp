/**
 * @author Lucas BRUTON
 * @file Humidity.hpp
 * @date 09/10/2021
 * @brief La classe Humidity hérite de la classe Sensor et représente un capteur de humidité
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"
#include "Type.hpp"


class Humidity : public Sensor<float> {
    private: 
        /*
        * Valeur minimale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MIN_TEMPERATURE = 40.0f;
        /*
        * Valeur maximale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MAX_TEMPERATURE = 70.0f;
        /*
        * Cette valeur correspond à la différence maximale que le capteur renvoie vis-à-vis 
        * de la valeur précédente.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MAX_TEMPERATURE_CHANGE = 5.0f;

    public:
        // Définition de la forme canonique
        Humidity();
        Humidity(const Humidity& humidity);
        virtual ~Humidity(){};
        Humidity& operator=(const Humidity& humidity);

        /**
         * @brief Cette fonction renvoie des nouvelles données mesurer par le capteur
         * @return Type
         */
        virtual Type<float>& getData();

        /**
         * @brief Cette fonction génère des nouvelles données
         * @return float
         */
        virtual float aleaGenVal(); 
};

#endif // HUMIDITY_H