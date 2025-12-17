#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <iomanip>

class Animal {
protected:
    std::string name;
    std::string species;
    int age;
    std::vector<std::string> healthEvents;

public:
    Animal(const std::string& name = "", const std::string& species = "", int age = 0)
        : name(name), species(species), age(age) {}

    virtual ~Animal() = default;

    virtual void display() const {
        std::cout << "Name: " << name << ", Species: " << species 
                  << ", Age: " << age << " years\n";
        if (!healthEvents.empty()) {
            std::cout << "Health Events: ";
            for (const auto& event : healthEvents) {
                std::cout << event << " ";
            }
            std::cout << "\n";
        }
    }

    virtual std::string getType() const = 0;
    virtual std::string getSpecificInfo() const = 0;
    virtual void setSpecificInfo(const std::string& info) = 0;

    void addHealthEvent(const std::string& event) {
        healthEvents.push_back(event);
    }

    void edit(const std::string& newSpecies, int newAge) {
        species = newSpecies;
        age = newAge;
    }

    const std::string& getName() const { return name; }
    const std::string& getSpecies() const { return species; }
    int getAge() const { return age; }
    const std::vector<std::string>& getHealthEvents() const { return healthEvents; }

    void saveToFile(std::ofstream& file) const {
        file << getType() << ";" << name << ";" << species << ";" << age << ";"
             << getSpecificInfo() << ";";
        
        for (size_t i = 0; i < healthEvents.size(); ++i) {
            file << healthEvents[i];
            if (i < healthEvents.size() - 1) {
                file << "|";
            }
        }
        file << "\n";
    }

    void loadFromFile(const std::string& data) {
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        
        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 6) {
            name = tokens[1];
            species = tokens[2];
            age = std::stoi(tokens[3]);
            setSpecificInfo(tokens[4]);
            
            // Parse health events
            std::stringstream events_ss(tokens[5]);
            std::string event;
            healthEvents.clear();
            while (std::getline(events_ss, event, '|')) {
                if (!event.empty()) {
                    healthEvents.push_back(event);
                }
            }
        }
    }
};

class Bird : public Animal {
private:
    double wingspan;      // in meters
    double flightSpeed;   // average flight speed in km/h

public:
    Bird(const std::string& name = "", const std::string& species = "", int age = 0,
         double wingspan = 0.0, double flightSpeed = 0.0)
        : Animal(name, species, age), wingspan(wingspan), flightSpeed(flightSpeed) {}

    void display() const override {
        std::cout << "[BIRD] ";
        Animal::display();
        std::cout << "Wingspan: " << wingspan << "m, Flight Speed: " 
                  << flightSpeed << " km/h\n";
    }

    std::string getType() const override { return "Bird"; }
    
    std::string getSpecificInfo() const override {
        return std::to_string(wingspan) + "-" + std::to_string(flightSpeed);
    }

    void setSpecificInfo(const std::string& info) override {
        size_t dashPos = info.find('-');
        if (dashPos != std::string::npos) {
            wingspan = std::stod(info.substr(0, dashPos));
            flightSpeed = std::stod(info.substr(dashPos + 1));
        }
    }

    double getFlightSpeed() const { return flightSpeed; }
    double getWingspan() const { return wingspan; }
};

class Mammal : public Animal {
private:
    std::string furType;
    double bodyMass;  // in kg

public:
    Mammal(const std::string& name = "", const std::string& species = "", int age = 0,
           const std::string& furType = "", double bodyMass = 0.0)
        : Animal(name, species, age), furType(furType), bodyMass(bodyMass) {}

    void display() const override {
        std::cout << "[MAMMAL] ";
        Animal::display();
        std::cout << "Fur Type: " << furType << ", Body Mass: " 
                  << bodyMass << " kg\n";
    }

    std::string getType() const override { return "Mammal"; }
    
    std::string getSpecificInfo() const override {
        return furType + "-" + std::to_string(bodyMass);
    }

    void setSpecificInfo(const std::string& info) override {
        size_t dashPos = info.find('-');
        if (dashPos != std::string::npos) {
            furType = info.substr(0, dashPos);
            bodyMass = std::stod(info.substr(dashPos + 1));
        }
    }

    const std::string& getFurType() const { return furType; }
    double getBodyMass() const { return bodyMass; }
};

class AnimalManager {
private:
    std::vector<std::shared_ptr<Animal>> animals;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << "\n";
            return;
        }

        animals.clear();
        std::string line;
        
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            
            std::stringstream ss(line);
            std::string type;
            std::getline(ss, type, ';');
            
            std::shared_ptr<Animal> animal;
            
            if (type == "Bird") {
                animal = std::make_shared<Bird>();
            } else if (type == "Mammal") {
                animal = std::make_shared<Mammal>();
            } else {
                continue;
            }
            
            animal->loadFromFile(line);
            animals.push_back(animal);
        }
        
        std::cout << "Loaded " << animals.size() << " animals from " << filename << "\n";
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot create file " << filename << "\n";
            return;
        }

        for (const auto& animal : animals) {
            animal->saveToFile(file);
        }
        
        std::cout << "Saved " << animals.size() << " animals to " << filename << "\n";
    }

    void displayAll() const {
        std::cout << "\n=== ALL ANIMALS ===\n";
        for (const auto& animal : animals) {
            animal->display();
            std::cout << "-------------------\n";
        }
    }

    void addAnimal() {
        std::string type, name, species, specificInfo;
        int age;
        
        std::cout << "\n=== ADD NEW ANIMAL ===\n";
        std::cout << "Type (Bird/Mammal): ";
        std::cin >> type;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Species: ";
        std::cin >> species;
        std::cout << "Age: ";
        std::cin >> age;
        
        std::shared_ptr<Animal> animal;
        
        if (type == "Bird") {
            double wingspan, flightSpeed;
            std::cout << "Wingspan (m): ";
            std::cin >> wingspan;
            std::cout << "Flight Speed (km/h): ";
            std::cin >> flightSpeed;
            animal = std::make_shared<Bird>(name, species, age, wingspan, flightSpeed);
        } else if (type == "Mammal") {
            std::string furType;
            double bodyMass;
            std::cout << "Fur Type: ";
            std::cin >> furType;
            std::cout << "Body Mass (kg): ";
            std::cin >> bodyMass;
            animal = std::make_shared<Mammal>(name, species, age, furType, bodyMass);
        } else {
            std::cout << "Invalid animal type!\n";
            return;
        }
        
        animals.push_back(animal);
        std::cout << "Animal added successfully!\n";
    }

    void editAnimal() {
        std::cout << "\n=== EDIT ANIMAL ===\n";
        std::cout << "Enter animal number (1-" << animals.size() << "): ";
        int index;
        std::cin >> index;
        
        if (index < 1 || index > static_cast<int>(animals.size())) {
            std::cout << "Invalid index!\n";
            return;
        }
        
        auto& animal = animals[index - 1];
        
        std::string newSpecies;
        int newAge;
        std::string newEvent;
        
        std::cout << "New species: ";
        std::cin >> newSpecies;
        std::cout << "New age: ";
        std::cin >> newAge;
        std::cout << "Add health event: ";
        std::cin >> newEvent;
        
        animal->edit(newSpecies, newAge);
        animal->addHealthEvent(newEvent);
        
        std::cout << "Animal edited successfully!\n";
    }

    void deleteAnimal() {
        std::cout << "\n=== DELETE ANIMAL ===\n";
        std::cout << "Enter animal number (1-" << animals.size() << "): ";
        int index;
        std::cin >> index;
        
        if (index < 1 || index > static_cast<int>(animals.size())) {
            std::cout << "Invalid index!\n";
            return;
        }
        
        animals.erase(animals.begin() + index - 1);
        std::cout << "Animal deleted successfully!\n";
    }

    void filterByAge() {
        std::cout << "\n=== ANIMALS OLDER THAN 5 YEARS ===\n";
        auto filter = [](const std::shared_ptr<Animal>& a) {
            return a->getAge() > 5;
        };
        
        int count = 0;
        for (const auto& animal : animals) {
            if (filter(animal)) {
                animal->display();
                std::cout << "-------------------\n";
                count++;
            }
        }
        std::cout << "Total: " << count << " animals\n";
    }

    void sortByName() {
        auto sortLambda = [](const std::shared_ptr<Animal>& a, const std::shared_ptr<Animal>& b) {
            return a->getName() < b->getName();
        };
        
        std::sort(animals.begin(), animals.end(), sortLambda);
        std::cout << "Animals sorted by name!\n";
    }

    void sortByAge() {
        auto sortLambda = [](const std::shared_ptr<Animal>& a, const std::shared_ptr<Animal>& b) {
            return a->getAge() < b->getAge();
        };
        
        std::sort(animals.begin(), animals.end(), sortLambda);
        std::cout << "Animals sorted by age!\n";
    }

    void findFastestBird() {
        double maxSpeed = 0.0;
        std::shared_ptr<Bird> fastestBird = nullptr;
        
        for (const auto& animal : animals) {
            if (auto bird = std::dynamic_pointer_cast<Bird>(animal)) {
                if (bird->getFlightSpeed() > maxSpeed) {
                    maxSpeed = bird->getFlightSpeed();
                    fastestBird = bird;
                }
            }
        }
        
        if (fastestBird) {
            std::cout << "\n=== FASTEST BIRD ===\n";
            fastestBird->display();
            std::cout << "Flight Speed: " << fastestBird->getFlightSpeed() << " km/h\n";
        } else {
            std::cout << "No birds found!\n";
        }
    }

    void countMammalsOver5Years() {
        auto countLambda = [](const std::shared_ptr<Animal>& a) {
            if (auto mammal = std::dynamic_pointer_cast<Mammal>(a)) {
                return mammal->getAge() > 5;
            }
            return false;
        };
        
        int count = std::count_if(animals.begin(), animals.end(), countLambda);
        std::cout << "\n=== MAMMALS OVER 5 YEARS OLD ===\n";
        std::cout << "Count: " << count << "\n";
        
        // Display them
        for (const auto& animal : animals) {
            if (countLambda(animal)) {
                animal->display();
                std::cout << "-------------------\n";
            }
        }
    }

    void countBySpecies() {
        std::map<std::string, int> speciesCount;
        
        for (const auto& animal : animals) {
            speciesCount[animal->getSpecies()]++;
        }
        
        std::cout << "\n=== SPECIES STATISTICS ===\n";
        for (const auto& [species, count] : speciesCount) {
            std::cout << species << ": " << count << " animals\n";
        }
    }

    void findVaccinatedAnimals() {
        std::vector<std::shared_ptr<Animal>> vaccinated;
        
        auto vaccineFilter = [](const std::shared_ptr<Animal>& a) {
            const auto& events = a->getHealthEvents();
            return std::find(events.begin(), events.end(), "vaccinated") != events.end();
        };
        
        std::copy_if(animals.begin(), animals.end(), std::back_inserter(vaccinated), vaccineFilter);
        
        std::cout << "\n=== VACCINATED ANIMALS ===\n";
        for (const auto& animal : vaccinated) {
            animal->display();
            std::cout << "-------------------\n";
        }
        std::cout << "Total vaccinated: " << vaccinated.size() << " animals\n";
    }

    void searchByName() {
        std::string searchName;
        std::cout << "\n=== SEARCH BY NAME ===\n";
        std::cout << "Enter name to search: ";
        std::cin >> searchName;
        
        bool found = false;
        for (const auto& animal : animals) {
            if (animal->getName().find(searchName) != std::string::npos) {
                animal->display();
                std::cout << "-------------------\n";
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No animals found with name containing: " << searchName << "\n";
        }
    }

    void searchByHealthEvent() {
        std::string event;
        std::cout << "\n=== SEARCH BY HEALTH EVENT ===\n";
        std::cout << "Enter health event to search: ";
        std::cin >> event;
        
        bool found = false;
        for (const auto& animal : animals) {
            const auto& events = animal->getHealthEvents();
            if (std::find(events.begin(), events.end(), event) != events.end()) {
                animal->display();
                std::cout << "-------------------\n";
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No animals found with health event: " << event << "\n";
        }
    }
};

void displayMenu() {
    std::cout << "\n=== ANIMAL MANAGEMENT SYSTEM ===\n";
    std::cout << "1. Load data from file\n";
    std::cout << "2. Save data to file\n";
    std::cout << "3. Display all animals\n";
    std::cout << "4. Add new animal\n";
    std::cout << "5. Edit animal\n";
    std::cout << "6. Delete animal\n";
    std::cout << "7. Sort animals by name\n";
    std::cout << "8. Sort animals by age\n";
    std::cout << "9. Filter animals by age (>5 years)\n";
    std::cout << "10. Find fastest bird\n";
    std::cout << "11. Count mammals over 5 years\n";
    std::cout << "12. Count animals by species\n";
    std::cout << "13. Find vaccinated animals\n";
    std::cout << "14. Search by name\n";
    std::cout << "15. Search by health event\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    AnimalManager manager;
    int choice;
    
    do {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                manager.loadFromFile("animals.txt");
                break;
            case 2:
                manager.saveToFile("animals.txt");
                break;
            case 3:
                manager.displayAll();
                break;
            case 4:
                manager.addAnimal();
                break;
            case 5:
                manager.editAnimal();
                break;
            case 6:
                manager.deleteAnimal();
                break;
            case 7:
                manager.sortByName();
                manager.displayAll();
                break;
            case 8:
                manager.sortByAge();
                manager.displayAll();
                break;
            case 9:
                manager.filterByAge();
                break;
            case 10:
                manager.findFastestBird();
                break;
            case 11:
                manager.countMammalsOver5Years();
                break;
            case 12:
                manager.countBySpecies();
                break;
            case 13:
                manager.findVaccinatedAnimals();
                break;
            case 14:
                manager.searchByName();
                break;
            case 15:
                manager.searchByHealthEvent();
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}
