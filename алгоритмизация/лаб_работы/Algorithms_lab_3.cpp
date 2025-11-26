
#include <iostream> 
#include <fstream>  
#include <string>    
#include <vector>  
#include <limits>  
#include <algorithm> 


const std::string TASKS_FILENAME = "tasks.txt";
const std::string OUTPUT_FILENAME = "output.txt";

struct Task {
    std::string title;
    int priority;
    std::string dueDate;
}; 

void clearInputBuffer() {
    std::cin.ignore();
}

std::vector<Task> readTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream inFile(filename);

    std::string line;
    Task currentTask;
    int lineIdentifier = 0; 

    while (std::getline(inFile, line)) {
        if (line.rfind("Название: ", 0) == 0) {
            currentTask.title = line.substr(10*2-2);
            lineIdentifier = 1;
        } else if (line.rfind("Приоритет: ", 0) == 0) {
            currentTask.priority = std::stoi(line.substr(11*2-2));
            lineIdentifier = 2;
        } else if (line.rfind("Срок: ", 0) == 0) {
            currentTask.dueDate = line.substr(6*2-2);
            lineIdentifier = 3;
        } else if (line == "--------------------") { // Разделитель 
            if (lineIdentifier == 3) { //  все поля были прочитаны
                tasks.push_back(currentTask); //  задачу в вектор
                currentTask = Task();
            }
            lineIdentifier = 0;
        }
    }
    if (lineIdentifier == 3) {
        tasks.push_back(currentTask);
    }

    inFile.close();
    return tasks;
}

// --- Функция для записи всех задач из памяти 
void writeTasksToFile(const std::string& filename, const std::vector<Task>& tasks) {
    std::ofstream outFile(filename); 

    for (const auto& task : tasks) {
        outFile << "Название: " << task.title << std::endl;
        outFile << "Приоритет: " << task.priority << std::endl;
        outFile << "Срок: " << task.dueDate << std::endl;
        outFile << "--------------------" << std::endl;
    }

    outFile.close();
}

// ---  для добавления результатов 
void writeResultsToOutputFile(const std::string& content) {
    std::ofstream outFile(OUTPUT_FILENAME, std::ios::out | std::ios::app); 

    outFile << content << std::endl;
    outFile.close();
    std::cout << "Результат операции записан в файл " << OUTPUT_FILENAME << std::endl;
}

// ---  для добавления новой задачи 
void addTask(std::vector<Task>& tasks) { 
    std::string taskName;
    int priority;
    std::string dueDate;

    std::cout << "\n--- Добавление новой задачи ---" << std::endl;
    std::cout << "Введите название задачи: ";
    clearInputBuffer(); 
    std::getline(std::cin, taskName);

    if (taskName.empty()) {
        std::cout << "Добавление задачи отменено." << std::endl;
        return;
    }

    std::cout << "Введите приоритет задачи (целое число, например, 1 - высокий): ";
    while (!(std::cin >> priority)) { // Проверка на корректный ввод числа
        std::cout << "Некорректный ввод. Введите число для приоритета: ";
        std::cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer(); 

    std::cout << "Введите срок выполнения (например, ГГГГ-ММ-ДД): ";
    std::getline(std::cin, dueDate);

    tasks.push_back({taskName, priority, dueDate}); // Добавляем новую задачу в вектор
    std::cout << "Задача '" << taskName << "' добавлена в текущий список." << std::endl;
}

// ---  для поиска задачи по названию и сохранения результата ---
void findTaskAndSave(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "Список задач пуст" << std::endl;
        return;
    }

    std::string searchTitle;
    std::cout << "\n--- Поиск задачи ---" << std::endl;
    std::cout << "Введите название задачи для поиска: ";
    clearInputBuffer(); 
    std::getline(std::cin, searchTitle);

    std::stringstream ss; //  формирования строки вывода 
    ss << "\n--- Результаты поиска по запросу '" << searchTitle << "' ---" << std::endl;

    bool found = false;
    for (const auto& task : tasks) {
        if (task.title.find(searchTitle) != std::string::npos) { // Ищем подстроку
            ss << "  Название: " << task.title << std::endl;
            ss << "  Приоритет: " << task.priority << std::endl;
            ss << "  Срок: " << task.dueDate << std::endl;
            ss << "--------------------" << std::endl;
            found = true;
        }
    }

    if (!found) {
        ss << "Задача с названием, содержащим '" << searchTitle << "', не найдена." << std::endl;
    }

    std::cout << ss.str(); // Выводим результат на консоль
    writeResultsToOutputFile(ss.str()); // Записываем результат в файл
}

// --- Функция для вывода задач по приоритету и сохранения результата ---
void displayTasksByPriorityThresholdAndSave(const std::vector<Task>& tasks) { 
    if (tasks.empty()) {
        std::cout << "Список задач пуст. Нет задач для вывода." << std::endl;
        return;
    }

    int thresholdPriority;
    std::cout << "\n--- Вывод задач по приоритету ---" << std::endl;
    std::cout << "Введите максимальный приоритет (например, 2 для показа задач с приоритетом 1 и 2): ";

    while (!(std::cin >> thresholdPriority)) {
        std::cout << "Некорректный ввод. Введите целое число: ";
        std::cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer(); // Очистка буфера

    std::stringstream ss;
    ss << "\n--- Задачи с приоритетом <= " << thresholdPriority << " ---" << std::endl;
    ss << "---------------------------------" << std::endl;

    bool found = false;
    for (const auto& task : tasks) {
        if (task.priority <= thresholdPriority) {
            ss << "Название: " << task.title << std::endl;
            ss << "Приоритет: " << task.priority << std::endl;
            ss << "Срок: " << task.dueDate << std::endl;
            ss << "--------------------" << std::endl;
            found = true;
        }
    }

    if (!found) {
        ss << "Задач с приоритетом меньше или равным " << thresholdPriority << " не найдено." << std::endl;
    }

    std::cout << ss.str();
    writeResultsToOutputFile(ss.str());
}

// --- Функция для отображения всех задач (на консоль) ---
void displayAllTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "\nСписок задач пуст." << std::endl;
        return;
    }
    std::cout << "\n--- Все задачи ---" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "Задача #" << (i + 1) << ":" << std::endl;
        std::cout << "  Название: " << tasks[i].title << std::endl;
        std::cout << "  Приоритет: " << tasks[i].priority << std::endl;
        std::cout << "  Срок: " << tasks[i].dueDate << std::endl;
        std::cout << "--------------------" << std::endl;
    }
}

// --- Функция для сортировки задач и сохранения результата ---
void sortTasksAndSave(std::vector<Task>& tasks) { // Вектор передается по ссылке для изменения (сортировка)
    if (tasks.empty()) {
        std::cout << "Список задач пуст. Нет задач для сортировки." << std::endl;
        return;
    }

    std::cout << "\n--- Сортировка задач ---" << std::endl;
    std::cout << "Выберите критерий сортировки:" << std::endl;
    std::cout << "1. По приоритету (возрастанию)" << std::endl;
    std::cout << "2. По сроку выполнения (возрастанию)" << std::endl;
    std::cout << "Ваш выбор: ";

    int choice;
    while (!(std::cin >> choice) || (choice < 1 || choice > 2)) {
        std::cout << "Некорректный ввод. Введите 1 или 2: ";
        std::cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer(); 

    std::stringstream ss;
    if (choice == 1) {
        std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.priority < b.priority; // сортировки по приоритету
        });
        ss << "\n--- Задачи отсортированы по приоритету (возрастанию) ---" << std::endl;
    } else { // choice == 2
        std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.dueDate < b.dueDate; // Лямбда-функция для сортировки по сроку
        });
        ss << "\n--- Задачи отсортированы по сроку выполнения (возрастанию) ---" << std::endl;
    }

    // Формируем строку для вывода и записи
    for (size_t i = 0; i < tasks.size(); ++i) {
        ss << "Задача #" << (i + 1) << ":" << std::endl;
        ss << "  Название: " << tasks[i].title << std::endl;
        ss << "  Приоритет: " << tasks[i].priority << std::endl;
        ss << "  Срок: " << tasks[i].dueDate << std::endl;
        ss << "--------------------" << std::endl;
    }

    std::cout << ss.str(); // Выводим на консоль
    writeResultsToOutputFile(ss.str()); // Записываем в output.txt
}


// --- Главная функция программы (меню) ---
int main() {
    clearInputBuffer(); // Очистка буфера при старте программы на всякий случай

    // 1. Читаем все задачи из файла TASKS_FILENAME при запуске программы
    std::vector<Task> tasks = readTasksFromFile(TASKS_FILENAME);

    std::cout << "Добро пожаловать в менеджер задач!" << std::endl;

    int choice;
    do {
        std::cout << "\n--- Главное меню ---" << std::endl;
        std::cout << "1. Добавить новую задачу" << std::endl;
        std::cout << "2. Показать все задачи (на консоль)" << std::endl;
        std::cout << "3. Найти задачу по названию" << std::endl;
        std::cout << "4. Вывести задачи по приоритету" << std::endl;
        std::cout << "5. Отсортировать задачи" << std::endl;
        std::cout << "6. Сохранить изменения и выйти" << std::endl; // Сохраняет текущее состояние tasks в файл
        std::cout << "Ваш выбор: ";

        while (!(std::cin >> choice) || (choice < 1 || choice > 6)) {
            std::cout << "Некорректный ввод. Введите число от 1 до 6: ";
            std::cin.clear();
            clearInputBuffer();
        }
        clearInputBuffer(); // Очистка буфера после cin >> int

        switch (choice) {
            case 1:
                addTask(tasks); // Добавляем в вектор в памяти
                break;
            case 2:
                displayAllTasks(tasks); // Показываем из вектора в памяти
                break;
            case 3:
                findTaskAndSave(tasks); // Ищем в векторе в памяти
                break;
            case 4:
                displayTasksByPriorityThresholdAndSave(tasks); // Выводим из вектора в памяти
                break;
            case 5:
                sortTasksAndSave(tasks); // Сортируем вектор в памяти
                break;
            case 6:
                std::cout << "Сохранение задач в файл " << TASKS_FILENAME << "..." << std::endl;
                writeTasksToFile(TASKS_FILENAME, tasks); // Перезаписываем файл при выходе
                std::cout << "До свидания!" << std::endl;
                break;
            default:
                std::cout << "Неизвестный выбор. Попробуйте еще раз." << std::endl;
                break;
        }
    } while (choice != 6); // Повторяем, пока пользователь не выберет выход

    return 0;
}
