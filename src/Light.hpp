/**
 * @author Lucas BRUTON
 * @file Light.hpp
 * @date 09/10/2021
 * @brief La classe Light hérite de la classe Sensor et représente un capteur de luminosité
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"
#include "Type.hpp"


class Light : public Sensor<bool> {
    public:
        // Définition de la forme canonique
        Light();
        Light(const Light& light);
        virtual ~Light(){};
        Light& operator=(const Light& light);

        /**
         * @brief Cette fonction renvoie des nouvelles données mesurer par le capteur
         * @return Type
         */
        virtual Type<bool>& getData();

        /**
         * @brief Cette fonction génère des nouvelles données
         * @return bool
         */
        virtual bool aleaGenVal(); 
};

#endif // LIGHT_H