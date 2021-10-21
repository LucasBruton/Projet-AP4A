/**
 * @author Lucas BRUTON
 * @file Scheduler.cpp
 * @date 30/09/2021
 * @brief La classe Scheduler est le cerveau du sous marin. 
 * Il récupère régulièrement les données capteurs pour les transmettre au serveur.
 */


#include <iostream>
#include "Scheduler.hpp"

using namespace std;

int main(void) {
  unsigned int simulationTime, temperatureSensorSleepTime, humiditySensorSleepTime,
  pressureSensorSleepTime, lightSensorSleepTime;


  cout << "Pendant combien de temps dure la simulation du sous marin (en millisecondes)?\n";
  cin >> simulationTime;
  cout << "Quand est ce que les données du capteur de la température sont récupérées (en millisecondes)?\n";
  cin >> humiditySensorSleepTime;
  cout << "Quand est ce que les données du capteur de l'humidité sont récupérées (en millisecondes)?\n";
  cin >> temperatureSensorSleepTime;
  cout << "Quand est ce que les données du capteur de la pression sont récupérées (en millisecondes)?\n";
  cin >> pressureSensorSleepTime;
  cout << "Quand est ce que les données du capteur de la lumière sont récupérées (en millisecondes)?\n";
  cin >> lightSensorSleepTime;

  if(simulationTime == 0) {
    return EXIT_SUCCESS;
  }

  // Création du scheduler
  Scheduler scheduler(simulationTime, temperatureSensorSleepTime, humiditySensorSleepTime, pressureSensorSleepTime, lightSensorSleepTime);
  // Lancement de la simulation
  scheduler.runSimulation();

  return 0;
}
