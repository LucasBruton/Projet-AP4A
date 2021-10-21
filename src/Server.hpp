/**
 * @author Lucas BRUTON
 * @file Server.hpp
 * @date 30/09/2021
 * @brief La classe serveur stocke et affiche les données des capteurs
 */

#ifndef SERVER_H
#define SERVER_H

#include "Type.hpp"
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Server {
    private:
        // Si true, le serveur affichera les données dans la console
        bool m_consolActivation;
        // Si true, le serveur stockera les données dans des fichiers de logs
        bool m_logActivation;
        // Cette variable contient le chemin du dossier des logs
        std::string m_logDirectory;

    public:
        // Définition de la forme canonique
        Server(): m_consolActivation(true), m_logActivation(true), m_logDirectory("logs/"){};
        Server(const Server& server): m_consolActivation(server.m_consolActivation), m_logActivation(server.m_logActivation), m_logDirectory(server.m_logDirectory){};
        virtual ~Server(){};
        Server& operator=(const Server& server);

        /**
         * @brief Ce constructeur permet de personnaliser les attibuts de la classe Serveur
         * @param consolActivation - Si true, le serveur affichera les données dans la console
         * @param logActivation - Si true, le serveur stockera les données dans des fichiers de logs
         * @param logDirectory - chemin du directory où seront stocker les logs
         */
        Server(const bool& consolActivation, const bool& logActivation, const std::string& logDirectory): 
            m_consolActivation(consolActivation), m_logActivation(logActivation), 
            m_logDirectory(logDirectory) {};

        /**
         * @brief Cette fonction permet de visualer / stocker les données 
         * @return void
         * @param type - Les données à visuliser ou à stocker
         */
        template<class T> void dataRcv(Type<T>& type) {
            // Si m_consolActivation est true, les données sont affichées dans la console
            if(this->m_consolActivation) {
                this->consolWrite(type);
            }
            // Si m_logActivation est true, les données sont stocker dans des fichiers de log
            if(this->m_logActivation) {
                this->fileWrite(type);
            }
        };

                /**
         * @brief Cette fonction stocke une chaine de caractères dans un fichier
         * @return void
         * @param nameFile - le fichier dans lequel les données sont stocker
         * @param data - la chaine de caractères à stocker dans nameFile 
         */
        void logData(const std::string& nameFile, const std::string& data);

        /**
         * @brief Cette fonction permet de modifier l'attribut m_logActivation
         * @return void
         * @param activation - La valeur de ce paramètre sera affecté à m_logActivation
         */
        void setLogActivation(bool& activation);
        
        /**
         * @brief Cette fonction permet de modifier l'attribut m_consolActivation
         * @return void
         * @param activation - La valeur de ce paramètre sera affecté à m_consolActivation
         */
        void setConsolActivation(bool& activation);

        /**
         * @brief Cette fonction renvoie la valeur de l'attribut m_logActivation 
         * @return bool
         */
        bool getLogActivation();

        /**
         * @brief Cette fonction renvoie la valeur de l'attribut m_consolActivation 
         * @return bool
         */
        bool getConsolActivation();
    
    private: 
        /**
         * @brief Cette fonction détermine dans quel fichier les données sont stocker
         * @return void
         * @param type - Les données à stocker
         */
        template<class T> void fileWrite(Type<T>& type) {
            TypeSensor sensorType = type.getTypeSensor();

            if(sensorType == e_humidity) {
                std::stringstream stream;
                stream << std::setprecision(1) << std::fixed << type.getData();
                this->logData("humidity.log", stream.str() + "%");
            }else if(sensorType == e_light) {
                this->logData("light.log", (type.getData()? "On" : "Off"));
            }else if(sensorType == e_pressure) {
                this->logData("pressure.log", std::to_string(type.getData()) + " Pa");
            }else if(sensorType == e_temperature) {
                std::stringstream stream;
                stream << std::setprecision(1) << std::fixed << type.getData();
                this->logData("temperature.log", stream.str() + "°C");
            }
        };

        /**
         * @brief Cette fonction affiche les données
         * @return void
         * @param type - Les données à afficher
         */
        template<class T> void consolWrite(Type<T>& type) {
            TypeSensor sensorType = type.getTypeSensor();

            if(sensorType == e_humidity) {
                std::cout << "Taux de humidité: " << std::setprecision(1) << std::fixed << type.getData() << "%" << std::endl << std::endl;
            }else if(sensorType == e_light) {
                std::cout << "La lumière est " << (type.getData() ? "allumée" : "éteinte") << std::endl << std::endl;
            }else if(sensorType == e_pressure) {
                std::cout << "Pression: " << type.getData() << " Pa" << std::endl << std::endl;
            }else if(sensorType == e_temperature) {
                std::cout << "Température: " << std::setprecision(1) << std::fixed << type.getData() << "°C" << std::endl << std::endl;
            }
        };


};

#endif // SERVER_H

