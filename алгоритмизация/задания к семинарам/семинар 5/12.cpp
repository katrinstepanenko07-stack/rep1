#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() 
{
    std::vector<double> fuel_levels(50);
    std::cout << "Введите 50 значений уровня топлива: ";
    for (int i = 0; i < 50; ++i) {
        std::cin >> fuel_levels[i];
    }
    auto min_it = std::min_element(fuel_levels.begin(), fuel_levels.end());
    auto max_it = std::max_element(fuel_levels.begin(), fuel_levels.end());
    double threshold = *max_it * 0.05;
    bool never_below_threshold = std::all_of(fuel_levels.begin(), fuel_levels.end(),
                                           [threshold](double level) { return level >= threshold; });
    double consumption = fuel_levels[0] - fuel_levels[49];
    std::vector<double> sorted_fuel = fuel_levels;
    std::sort(sorted_fuel.begin(), sorted_fuel.end());
    double median;
    if (sorted_fuel.size() % 2 == 0) {
        median = (sorted_fuel[sorted_fuel.size()/2 - 1] + sorted_fuel[sorted_fuel.size()/2]) / 2;
    } 
    else {
        median = sorted_fuel[sorted_fuel.size()/2];
    }
    
    std::cout << "Минимальный уровень топлива: " << *min_it << std::endl;
    std::cout << "Максимальный уровень топлива: " << *max_it << std::endl;
    
    if (never_below_threshold == true) {
        std::cout << "Уровень топлива никогда не падал ниже 5% от максимального" << std::endl;
    } 
    else {
        std::cout << "Уровень топлива падал ниже 5% от максимального" << std::endl;
    }
    
    std::cout << "Среднее потребление за период: " << consumption << std::endl;
    std::cout << "Медиана уровня топлива: " << median << std::endl;
    
    return 0;
}