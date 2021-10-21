/**
 * @author Lucas BRUTON
 * @file Server.cpp
 * @date 30/09/2021
 * @brief La classe serveur stocke et affiche les données des capteurs
 */

#include "Server.hpp"
#include "Type.hpp"
#include "TypeSensor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

Server& Server::operator=(const Server& server) {
    this->m_consolActivation = server.m_consolActivation;
    this->m_logActivation = server.m_logActivation;
    this->m_logDirectory = server.m_logDirectory;
    return *this;
}

void Server::logData(const string &nameFile, const string &data) {
    fs::path directory = this->m_logDirectory;

    // Si le dossier de logs n'existe pas, il sera créé
    if(!fs::exists(directory)) {
        fs::create_directory(directory);
    }
    // Ecriture dans le fichier de logs
    ofstream file;
    /** 
    * Si le fichier n'existe pas, il sera créé, puis les données seront ajoutées.
    * Si le fichier existe et qu'il contient du contenu, les données seront ajouté à la suite du contenu existant.
    */
    file.open(this->m_logDirectory + nameFile, ios::app);
    file << data << endl;
    file.close();
}