/**
 * @author Lucas BRUTON
 * @file TypeSensor.hpp
 * @date 08/10/2021
 * @brief L'enumération TypeSensor liste les types de capteurs existants.
 */

#ifndef TYPESENSOR_H
#define TYPESENSOR_H

// Liste des types de capteurs
enum TypeSensor {
    // Type de capteur par défaut
    e_default_sensor,

    // Types de capteurs héritant de la classe Sensor
    e_temperature,
    e_pressure,
    e_light,
    e_humidity
};

#endif // TYPESENSOR_H