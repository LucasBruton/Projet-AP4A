/**
 * @author Lucas BRUTON
 * @file Type.hpp
 * @date 08/10/2021
 * @brief La classe Type représente les données générer par les capteurs.
 */

#ifndef TYPE_H
#define TYPE_H

#include "TypeSensor.hpp"

template<class T> class Type {
    private:
        // Cette variable stocke les données générer par un capteur.
        T m_data;
        // Cette variable contient le type du capteur
        TypeSensor m_typeSensor;

    public:
        // Définition de la forme canonique
        Type<T>(): m_data(0), m_typeSensor(e_default_sensor){};
        Type<T>(const Type<T>& type): m_data(type.m_data), m_typeSensor(type.m_typeSensor){};
        Type<T>& operator=(const Type<T>& type) {
            this->m_data = type.m_data;
            this->m_typeSensor = type.m_typeSensor;

            return *this;
        };
        virtual ~Type<T>(){};

        /**
         * @brief Constructeur de la classe type
         * @param data - Les données générer par les capteurs
         * @param sensor - Type du capteur qui a générer les données
         */
        Type<T>(const T& data, const TypeSensor& sensor): m_data(data), m_typeSensor(sensor){};
        
        /**
         * @brief Cette fonction renvoie les données 
         * @return T
         */
        T getData() {
            return this->m_data;
        }

        /**
         * @brief Cette fonction permet de modifier la valeur des données stocker dans un objet Type
         * @return void
         * @param data - nouvelle valeur des données
         */
        void setData(const T& data) {
            this->m_data = data;
        }

        /**
         * @brief Cette fonction renvoie type du capteur
         * @return TypeSensor
         */
        TypeSensor getTypeSensor() {
            return this->m_typeSensor;
        }

        /**
         * @brief Cette fonction permet de modifier le type de capteur
         * @return void
         * @param type - nouveau type de capteur
         */
        void setTypeSensor(const TypeSensor& type) {
            this->m_typeSensor = type;
        }

};

#endif // TYPE_H
