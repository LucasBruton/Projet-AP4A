/**
 * @author Lucas BRUTON
 * @file Temperature.hpp
 * @date 08/10/2021
 * @brief La classe Temperature hérite de la classe Sensor et représente un capteur de température
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"
#include "Type.hpp"


class Temperature : public Sensor<float> {
    private:
        /*
        * Valeur minimale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MIN_TEMPERATURE = 10.0f;
        /*
        * Valeur maximale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MAX_TEMPERATURE = 20.0f;
        /*
        * Cette valeur correspond à la différence maximale que le capteur renvoie vis-à-vis 
        * de la valeur précédente.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const float MAX_TEMPERATURE_CHANGE = 2.0f;

    public:
        // Définition de la forme canonique
        Temperature();
        Temperature(const Temperature& temperature);
        virtual ~Temperature(){};
        Temperature& operator=(const Temperature& temperature);

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

#endif // TEMPERATURE_H