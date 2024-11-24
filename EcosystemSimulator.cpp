#include <iostream>
#include <iomanip>

class Population {
protected:
    double size;  // Tamaño de la población
    double growthRate;  // Tasa de crecimiento
public:
    Population(double size, double growthRate) : size(size), growthRate(growthRate) {}
    virtual void update(double interaction) = 0;  // Método virtual puro
    double getSize() const { return size; }
};

class Prey : public Population {
public:
    Prey(double size, double growthRate) : Population(size, growthRate) {}
    void update(double interaction) override {
        size += (growthRate * size - interaction);
        if (size < 0) size = 0;  // Evitar población negativa
    }
};

class Predator : public Population {
private:
    double mortalityRate;  // Tasa de mortalidad
public:
    Predator(double size, double growthRate, double mortalityRate) 
        : Population(size, growthRate), mortalityRate(mortalityRate) {}

    void update(double interaction) override {
        size += (growthRate * interaction - mortalityRate * size);
        if (size < 0) size = 0;  // Evitar población negativa
    }
};

class Ecosystem {
private:
    Prey* prey;
    Predator* predator;
    double predationRate;  // Tasa de depredación
public:
    Ecosystem(Prey* prey, Predator* predator, double predationRate)
        : prey(prey), predator(predator), predationRate(predationRate) {}

    void simulate(int steps) {
        std::cout << "\nStep\t\tPredator\tPrey\n";
        for (int i = 0; i < steps; ++i) {
            double preyP1 = prey->getSize();
            double predatorP1 = predator->getSize();
            double interaction = predationRate * preyP1 * predatorP1;
            prey->update(interaction);
            predator->update(interaction);

            // Mostrar resultados del paso actual
            std::cout << i + 1 << "\t\t" << std::fixed << std::setprecision(1)
                      << predatorP1 << "\t\t" << std::fixed << std::setprecision(1) << preyP1 << "\n";

            // Verificar si alguna población se extinguió
            if (preyP1 == 0) {
                std::cout << "prey population has gone extinct at step " << i + 1 << ".\n";
                break;  // Salir del ciclo
            }
            if (predatorP1 < 0.1) {
                std::cout << "predator population has gone extinct at step " << i + 1 << ".\n";
                break;  // Salir del ciclo
            }
        }
    }
};


int main() {
    // Especies de presas reales
    double prey_growth_rate[] = {0.15, 0.18, 0.12};  // Crecimiento de tres especies de presas
    std::string prey_names[] = {"Rabbit", "Mouse", "Deer"};

    // Especies de depredadores reales
    double predator_growth_rate[] = {0.02, 0.04, 0.03};  // Crecimiento de tres especies de depredadores
    double predator_mortality_rate[] = {0.15, 0.18, 0.10};  // Mortalidad de tres especies de depredadores
    std::string predator_names[] = {"Wolf", "Puma", "Golden Eagle"};

    int prey_choice, predator_choice, steps;
    double prey_start, predator_start;

    // Pedir al usuario la elección de especies
    std::cout << "Choose a prey species:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ". " << prey_names[i] << "\n";
    }
    std::cout << "Enter the number of the chosen prey species: ";
    std::cin >> prey_choice;

    std::cout << "\nChoose a predator species:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ". " << predator_names[i] << "\n";
    }
    std::cout << "Enter the number of the chosen predator species: ";
    std::cin >> predator_choice;

    // Pedir al usuario la cantidad inicial de presas y depredadores
    std::cout << "\nEnter initial number of prey: ";
    std::cin >> prey_start;

    std::cout << "Enter initial number of predators: ";
    std::cin >> predator_start;

    // Pedir al usuario la cantidad de pasos de simulación
    std::cout << "Enter the number of simulation steps: ";
    std::cin >> steps;

    // Crear las poblaciones de acuerdo con la elección del usuario
    Prey prey(prey_start, prey_growth_rate[prey_choice - 1]);
    Predator predator(predator_start, predator_growth_rate[predator_choice - 1], predator_mortality_rate[predator_choice - 1]);

    // Crear ecosistema con tasa de depredación
    Ecosystem ecosystem(&prey, &predator, 0.005);

    // Simular el número de pasos ingresado por el usuario
    ecosystem.simulate(steps);

    return 0;
}
