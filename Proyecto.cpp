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
        std::cout << "Step\tPrey\tPredator\n";
        for (int i = 0; i < steps; ++i) {
            double interaction = predationRate * prey->getSize() * predator->getSize();
            prey->update(interaction);
            predator->update(interaction);

            // Mostrar resultados del paso actual
            std::cout << i + 1 << "\t" << std::fixed << std::setprecision(2)
                      << prey->getSize() << "\t" << predator->getSize() << "\n";
        }
    }
};

int main() {
    // Crear poblaciones iniciales
    Prey prey(100.0, 0.1);  // 100 presas con una tasa de crecimiento del 10%
    Predator predator(10.0, 0.01, 0.1);  // 10 predadores con tasas específicas

    // Crear ecosistema con tasa de depredación
    Ecosystem ecosystem(&prey, &predator, 0.005);

    // Simular 50 pasos
    ecosystem.simulate(50);

    return 0;
}
