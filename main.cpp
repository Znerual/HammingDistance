// HammingDistance.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <algorithm> 
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
#include <stdexcept>
#include "HammingDistance.h"

using namespace std;


int main()
{

    string answer;
    do {

        std::cout << "Calculate Hamming Sets, please specify sequence length:" << endl;
        cin >> SEQUENCE_LENGTH;
        cout << "Set sequence length to " << SEQUENCE_LENGTH << endl;
        cout << "And Hamming distance:" << endl;
        cin >> HAMMING_DISTANCE;
        cout << "Set Hamming distance to " << HAMMING_DISTANCE << endl;

        const unsigned int MAX_NUMBER = 2 << (SEQUENCE_LENGTH * 2 - 1);
        cout << "Leading to a maximum number of " << MAX_NUMBER << endl;

        int group_id = 0;
        int numbers_left = MAX_NUMBER;
        unsigned __int16* group_ids = new unsigned __int16[MAX_NUMBER];
        bool* used_numbers = new bool[MAX_NUMBER];

        string* numbers = new string[MAX_NUMBER];

        // init the numbers array
        for (auto i = 0; i < MAX_NUMBER; i++) {
            string number = int_to_str(i);
            numbers[i] = move(number);
            used_numbers[i] = false;
        }

        cout << "Finished init the array" << endl;

        // take 0 as starting element
        string current_number = int_to_str(0);
        group_ids[0] = 0;
        used_numbers[0] = true;
        numbers_left -= 1;

        // calculate groups until all elements are matched
        while (numbers_left > 0) {

            // fill group_ids array with matching group_id
            for (auto i = 1; i < MAX_NUMBER; i++) {
                if (!used_numbers[i]) {
                    if (get_tetra_hamming_distance(current_number, numbers[i]) <= HAMMING_DISTANCE) {
                        group_ids[i] = group_id;
                        used_numbers[i] = true;
                        numbers_left -= 1;
                    }

                }
            }

            // find next starting number for next group
            group_id += 1;
            cout << "Look at group " << group_id << " with still " << numbers_left << " nmbers left" << endl;
            for (auto i = 1; i < MAX_NUMBER; i++) {
                if (!used_numbers[i]) {
                    current_number = numbers[i];
                    used_numbers[i] = true;
                    group_ids[i] = group_id;
                    numbers_left -= 1;
                    break;
                }
            }
        }

        // write results
        ofstream yaml_file(to_string(SEQUENCE_LENGTH) + "digits" + to_string(HAMMING_DISTANCE) + "hd.yml");
        if (yaml_file.is_open()) {
            cout << "Write result to file" << endl;
            for (auto i = 0; i < MAX_NUMBER; i++) {
                yaml_file << numbers[i] << ": " << group_ids[i] << '\n';
            }
        }
        else {
            cout << "Unable to open file" << endl;
        }


        delete[] group_ids;
        delete[] used_numbers;
        delete[] numbers;

        
        cout << "Caculate another set? (y/n)";
        cin >> answer;
    } while (answer == "y");
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"


// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
