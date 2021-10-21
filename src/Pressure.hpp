/**
 * @author Lucas BRUTON
 * @file Pressure.hpp
 * @date 09/10/2021
 * @brief La classe Pressure hérite de la classe Sensor et représente un capteur de pression
 */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"
#include "Type.hpp"


class Pressure : public Sensor<int> {
    private:
            /*
        * Valeur minimale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const int MIN_TEMPERATURE = 900000;
        /*
        * Valeur maximale que le capteur renvoie.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const int MAX_TEMPERATURE = 1100000;
        /*
        * Cette valeur correspond à la différence maximale que le capteur renvoie vis-à-vis 
        * de la valeur précédente.
        * Cette valeur constante est utilisé dans la fonction aleaGenval()
        */
        const int MAX_TEMPERATURE_CHANGE = 50000;

    public:
        // Définition de la forme canonique
        Pressure();
        Pressure(const Pressure& pressure);
        virtual ~Pressure(){};
        Pressure& operator=(const Pressure& pressure);

        /**
         * @brief Cette fonction renvoie des nouvelles données mesurer par le capteur
         * @return Type
         */
        virtual Type<int>& getData();

        /**
         * @brief Cette fonction génère des nouvelles données
         * @return int
         */
        virtual int aleaGenVal(); 
};

#endif // PRESSURE_H