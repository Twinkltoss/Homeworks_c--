#include <iostream>
#include<stack>
#include <queue>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;
//Задание. 1
//Реализуйте шаблонные функции для поиска максимума,
//минимума, сортировки массива(любым алгоритмом сортировки), двоичного поиска в массиве, 
// замены элемента массива на переданное значение.
template <typename T> T Min_Val(T* arr,T size) {
	T min = arr[0];
	for (T i = 0; i < size; i++)	{
		if (min > arr[i])min = arr[i];
	}
	return min;
}
template <typename T> T Max_Val(T* arr, T size) {
	T max = arr[0];
	for (T i = 0; i < size; i++) {
		if (max < arr[i])max = arr[i];
	}
	return max;
}
template <typename T> void Sort(T* arr, T size) {
	for (T i = 0; i < size; i++) {
		for (T j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
template <typename T> T Binary_Search(T* arr, T size,const T& val) {
	int begin=0;
	int end=size-1;
	while (begin<=end) {
		int mid = begin + (end - begin) / 2;
		if (arr[mid]==val) {
			return mid;
		}
		else if (arr[mid]<val) {
			begin = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return -1;
}
template <typename T> void Replace_elem(T* arr,T ind,const T& val) {
	arr[ind] = val;
}
template <typename T>void Print_Arr(T* arr, int size) {
	for (T i = 0; i < size; i++) {
		std::cout << arr[i] << "  ";
	}
}

//Задание.2
//Создайте шаблонный класс матрица.Необходимо реализовать динамическое выделение памяти, очистку памяти,
//заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические
//операции с помощью перегруженных операторов(+, –,
//	*, / ), поиск максимального и минимального элемента.
 
template <class T> class Matrix {
	T** matrix;
	size_t size;
public:
	Matrix(size_t size) :size{ size } {
		matrix = new T * [size];
		for (size_t i = 0; i < size; i++) {
			matrix[i] = new T[size];
		}
	}
	Matrix(const Matrix& other) {
		matrix = new T * [size];
		for (size_t i = 0; i < size; i++){
			matrix[i] = new T[size];
			for (size_t j = 0; j < size; j++){
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}
	void Manual_Filling() {
		for (size_t i = 0; i < size; i++){
			system("cls");
			for (size_t j = 0; j < size; j++) {
				cout << "Enter value for [" << i << "][" << j << "] = ";
				cin >> matrix[i][j];
			}
		}
	}
	void Random_Filling() {
		for (size_t i = 0; i < size; i++){
			for (size_t j = 0; j < size; j++) {
				matrix[i][j] = rand() % 78;
			}
		}
	}
	void Min() {
		size_t min = matrix[0][0];
		size_t indexI,indexJ;
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++){
				if (min > matrix[i][j]) {
					min=matrix[i][j];
					indexI = i;
					indexJ = j;
				}
			}
		}
		cout << "Minimum value [" << indexI << "][" << indexJ << "]=" << min;
	}
	void Max() {
		size_t max = matrix[0][0];
		size_t indexI, indexJ;
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				if (max < matrix[i][j]) {
					max = matrix[i][j];
					indexI = i;
					indexJ = j;
				}
			}
		}
		cout << "Maximum value [" << indexI << "][" << indexJ << "]=" << max;
	}
	Matrix& operator=(const Matrix& other) {
		for (size_t i = 0; i < size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		size = other.size;
		matrix = new T * [size];
		for (size_t i = 0; i < size; i++) {
			matrix[i] = new T [size];
			for (size_t j = 0; j < size; j++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}
	Matrix operator+(const Matrix& other)const {
		Matrix temp(size);
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}	
		return temp;
	}
	Matrix operator-(const Matrix& other)const {
		Matrix temp(size);
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
			}
		}
		return temp;
	}
	Matrix operator*(const Matrix& other)const {
		Matrix temp(size);
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				temp.matrix[i][j] = matrix[i][j] * other.matrix[i][j];
			}
		}
		return temp;
	}
	Matrix operator/(const Matrix& other)const {
		Matrix temp(size);
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				temp.matrix[i][j] = matrix[i][j] / other.matrix[i][j];
			}
		}
		return temp;
	}
	void Show_Matrix() {
		for (size_t i = 0; i < size; i++){			
			for (size_t j = 0; j < size; j++) {
				cout << matrix[i][j]<<"\t";
			}
			cout << "\n\n";
		}
	}
	~Matrix() {
		for (size_t i = 0; i < size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

//Задание. 3
//Есть строка символов, признаком конца, которой является; .В строке могут быть фигурные, круглые, квадратные скобки.
// Скобки могут быть открывающими и закрывающими.
//Необходимо проверить корректность расстановки скобок.
//При этом необходимо, чтобы выполнились следующие правила :
//1. Каждая открывающая скобка должна иметь справа такую же закрывающую.
//Обратное также должно быть верно.
//2. Открывающие и закрывающие пары скобок разных
//типов должны быть правильно расположены по отношению друг к другу.
//■ Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));
//■ Пример неправильной строки : ([x - y - z}*[x + 2y) - {z + 4x)].
//Если все правила соблюдены выведите информационное
//сообщение о корректности строки, иначе покажите строку
//до места возникновения первой ошибки.
bool isOpeningBracket(char c) {
	return c == '(' || c == '{' || c == '[';
}
bool isClosingBracket(char c) {
	return c == ')' || c == '}' || c == ']';
}
bool isMatchingPair(char opening, char closing) {
	return (opening == '(' && closing == ')') ||
		(opening == '{' && closing == '}') ||
		(opening == '[' && closing == ']');
}
void checkBrackets(const string& str) {
	stack<char> bracketStack;
	size_t errorPos = string::npos;
	for (size_t i = 0; i < str.length(); ++i) {
		char c = str[i];
		if (isOpeningBracket(c)) {
			bracketStack.push(c);
		}
		else if (isClosingBracket(c)) {
			if (bracketStack.empty() || !isMatchingPair(bracketStack.top(), c)) {
				errorPos = i;
				break;
			}
			bracketStack.pop();
		}
		if (c == ';') {
			break;
		}
	}
	if (errorPos == string::npos && !bracketStack.empty()) {
		errorPos = str.find(';');
	}
	if (errorPos != string::npos) {
		cout << "Ошибка в позиции " << errorPos + 1 << ". Строка до места ошибки:\n";
		cout << str.substr(0, errorPos + 1) << endl;
	}
	else {
		cout << "Строка корректна." << endl;
	}
}

//Задание 3-1.
//Создать имитационную модель "остановка маршрутных
//такси". Необходимо вводить следующую информацию:
//среднее время между появлениями пассажиров на остановке в разное время суток, среднее время между появлениями маршруток на остановке в разное время суток,
//тип остановки(конечная или нет).Необходимо определить : среднее время пребывание человека на остановке,
//достаточный интервал времени между приходами маршруток, чтобы на остановке находилось не более N людей
//одновременно.Количество свободных мест в маршрутке является случайной величиной.

class Random {
public:
	Random() {
		generator.seed(time(nullptr));
	}
	int nextInt(int min, int max) {
		uniform_int_distribution<int> distribution(min, max);
		return distribution(generator);
	}
	double nextDouble(double min, double max) {
		uniform_real_distribution<double> distribution(min, max);
		return distribution(generator);
	}
	double nextExponential(double mean) {
		exponential_distribution<double> distribution(1.0 / mean);
		return distribution(generator);
	}
private:
	mt19937 generator;
};
class Passenger {
public:
	Passenger(int arrivalTime) : arrivalTime(arrivalTime), boardingTime(-1) {}

	int getArrivalTime() const { return arrivalTime; }
	int getBoardingTime() const { return boardingTime; }
	void setBoardingTime(int time) { boardingTime = time; }
	int getWaitingTime() const {
		return boardingTime - arrivalTime;
	}
private:
	int arrivalTime;
	int boardingTime;
};
class Minibus {
public:
	Minibus(int capacity, int arrivalTime)
		: capacity(capacity), arrivalTime(arrivalTime) {
	}
	int getCapacity() const { return capacity; }
	int getArrivalTime() const { return arrivalTime; }
	void boardPassengers(queue<Passenger>& passengers, int currentTime) {
		int boarded = 0;
		while (!passengers.empty() && boarded < capacity) {
			passengers.front().setBoardingTime(currentTime);
			passengers.pop();
			boarded++;
		}
	}
private:
	int capacity;
	int arrivalTime;
};
class BusStop {
public:
	BusStop(bool isTerminal) : isTerminal(isTerminal), totalPassengers(0), totalWaitingTime(0) {}
	void addPassenger(int time) {
		passengers.push(Passenger(time));
		totalPassengers++;
	}
	void addMinibus(int capacity, int time) {
		Minibus bus(capacity, time);
		minibuses.push(bus);
	}
	void processMinibusArrival(int currentTime) {
		if (!minibuses.empty()) {
			Minibus& bus = minibuses.front();
			bus.boardPassengers(passengers, currentTime);
			queue<Passenger> temp = passengers;
			while (!temp.empty()) {
				if (temp.front().getBoardingTime() != -1) {
					totalWaitingTime += temp.front().getWaitingTime();
				}
				temp.pop();
			}
			minibuses.pop();
		}
	}
	int getPassengerCount() const {
		return passengers.size();
	}
	double getAverageWaitingTime() const {
		return totalPassengers > 0 ? static_cast<double>(totalWaitingTime) / totalPassengers : 0;
	}
	bool isTerminalStop() const {
		return isTerminal;
	}
private:
	queue<Passenger> passengers;
	queue<Minibus> minibuses;
	bool isTerminal;
	int totalPassengers;
	int totalWaitingTime;
};
template<typename T>
T input(const string& prompt, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) {
	T value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value < min || value > max) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка ввода. Пожалуйста, введите корректное значение." << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

//Задание 3-2.
//Разработать приложение, имитирующее очередь печати
//принтера.Должны быть клиенты, посылающие запросы
//на принтер, у каждого из которых есть свой приоритет.
//Каждый новый клиент попадает в очередь в зависимости
//от своего приоритета.Необходимо сохранять статистику печати(пользователь, время) в отдельной очереди.
//Предусмотреть вывод статистики на экран.

// Структура для задания печати
struct PrintJob {
	string user;
	int priority;
	int pages;
	time_t time;
};
// Структура для статистики
struct PrintStat {
	string user;
	time_t start;
	time_t end;
	int pages;
};
// Компаратор для очереди с приоритетом
struct ComparePriority {
	bool operator()(PrintJob a, PrintJob b) {
		return a.priority > b.priority;
	}
};

int main()
{
	system("chcp 1251");
	srand(time(0));
	//int size = 5;
	//int* arr = new int[size] {1,12,7,-5,4};

	//Matrix<int> mat1(5);
	//Matrix<int> mat2(5);
	//Matrix<int> mat3(5);
	//mat1.Random_Filling();
	//mat2.Random_Filling();
	//mat1.Show_Matrix();
	//cout << endl;
	//mat2.Show_Matrix();
	//mat3=mat1/ mat2;
	//cout << endl;
	//mat3.Show_Matrix();

	//std::cout << Min_Val(arr, size);
	//std::cout <<"\n" << Max_Val(arr, size);

	//Print_Arr(arr, size);
	//Sort(arr, size);
	//std::cout << std::endl;
	//Print_Arr(arr, size);
	
	//string str{ "([x - y - z}*[x + 2y) - {z + 4x)]" };//({ x - y - z }*[x + 2y] - (z + 4x)) || ([x - y - z}*[x + 2y) - {z + 4x)]
	//checkBrackets(str);

	//Random random;

	//// Ввод параметров моделирования
	//cout << "=== Параметры моделирования ===" << endl;
	//int simulationTime = input<int>("Время моделирования (мин): ", 1);
	//int dayPeriods = input<int>("Количество периодов суток: ", 1);

	//vector<double> passengerRates(dayPeriods);
	//vector<double> minibusRates(dayPeriods);
	//vector<int> periodDurations(dayPeriods);

	//for (int i = 0; i < dayPeriods; ++i) {
	//	cout << "\nПериод " << i + 1 << ":" << endl;
	//	passengerRates[i] = input<double>("Среднее время между появлением пассажиров (мин): ", 0.1);
	//	minibusRates[i] = input<double>("Среднее время между появлением маршруток (мин): ", 0.1);
	//	periodDurations[i] = input<int>("Продолжительность периода (мин): ", 1);
	//}

	//bool isTerminal = input<int>("Тип остановки (0 - промежуточная, 1 - конечная): ", 0, 1);
	//int maxPassengers = input<int>("Максимальное допустимое количество пассажиров (N): ", 1);
	//int minCapacity = input<int>("Минимальная вместимость маршрутки: ", 1);
	//int maxCapacity = input<int>("Максимальная вместимость маршрутки: ", minCapacity);

	//BusStop stop(isTerminal);

	//// Моделирование
	//cout << "\n=== Начало моделирования ===" << endl;

	//int nextPassengerTime = 0;
	//int nextMinibusTime = 0;
	//int currentPeriod = 0;
	//int periodEndTime = periodDurations[0];
	//bool optimalIntervalFound = false;
	//double optimalInterval = 0;

	//for (int time = 0; time < simulationTime; ++time) {
	//	// Проверка смены периода суток
	//	if (time >= periodEndTime && currentPeriod < dayPeriods - 1) {
	//		currentPeriod++;
	//		periodEndTime += periodDurations[currentPeriod];
	//		cout << "Переход к периоду " << currentPeriod + 1 << " в минуту " << time << endl;
	//	}

	//	// Появление пассажиров
	//	if (time >= nextPassengerTime) {
	//		stop.addPassenger(time);
	//		double interval = random.nextExponentыial(passengerRates[currentPeriod]);
	//		nextPassengerTime = time + static_cast<int>(ceil(interval));
	//		cout << "Пассажир прибыл в минуту " << time << ". Следующий через "
	//			<< fixed << setprecision(1) << interval << " мин" << endl;
	//	}

	//	// Прибытие маршрутного такси
	//	if (time >= nextMinibusTime) {
	//		int capacity = random.nextInt(minCapacity, maxCapacity);
	//		stop.addMinibus(capacity, time);
	//		double interval = random.nextExponential(minibusRates[currentPeriod]);
	//		nextMinibusTime = time + static_cast<int>(ceil(interval));
	//		cout << "Маршрутка прибыла в минуту " << time << ". Вместимость: " << capacity
	//			<< ". Следующая через " << fixed << setprecision(1) << interval << " мин" << endl;

	//		// Обработка прибытия маршрутки
	//		stop.processMinibusArrival(time);
	//	}

	//	// Проверка условия оптимального интервала
	//	if (!optimalIntervalFound && stop.getPassengerCount() > maxPassengers) {
	//		optimalInterval = minibusRates[currentPeriod] * 0.8; // Уменьшаем интервал на 20%
	//		cout << "\n!!! ВНИМАНИЕ !!! Превышено максимальное количество пассажиров ("
	//			<< stop.getPassengerCount() << ")" << endl;
	//		cout << "Рекомендуемый интервал между маршрутками: "
	//			<< fixed << setprecision(1) << optimalInterval << " мин" << endl;
	//		optimalIntervalFound = true;
	//	}
	//}

	//// Вывод результатов
	//cout << "\n=== Результаты моделирования ===" << endl;
	//cout << "Общее время моделирования: " << simulationTime << " мин" << endl;
	//cout << "Количество периодов: " << dayPeriods << endl;
	//cout << "Тип остановки: " << (isTerminal ? "конечная" : "промежуточная") << endl;
	//cout << "Среднее время ожидания пассажиров: " << fixed << setprecision(2)
	//	<< stop.getAverageWaitingTime() << " мин" << endl;
	//cout << "Количество пассажиров на остановке в конце: " << stop.getPassengerCount() << endl;

	//if (optimalIntervalFound) {
	//	cout << "Рекомендуемый интервал между маршрутками: " << fixed << setprecision(1)
	//		<< optimalInterval << " мин" << endl;
	//}
	//else {
	//	cout << "Текущий интервал между маршрутками достаточен" << endl;
	//}

// Очередь печати с приоритетом
priority_queue<PrintJob, vector<PrintJob>, ComparePriority> printQueue;
// Вектор для статистики
vector<PrintStat> stats;
// Добавляем несколько заданий в очередь
printQueue.push({ "User1", 1, 5, time(nullptr) });
printQueue.push({ "User2", 3, 2, time(nullptr) });
printQueue.push({ "User3", 2, 3, time(nullptr) });
// Обрабатываем очередь
while (!printQueue.empty()) {
	PrintJob job = printQueue.top();
	printQueue.pop();
	// Запоминаем время начала
	time_t start = time(nullptr);
	// Имитируем печать (1 сек на страницу)
	cout << "Печатаем: " << job.user
		<< " (" << job.pages << " стр.)" << endl;
	for (int i = 0; i < job.pages; i++) {
		cout << "." << flush;
		_sleep(1000); // Задержка 1 сек
	}
	// Запоминаем статистику
	time_t end = time(nullptr);
	stats.push_back({ job.user, start, end, job.pages });
	cout << "\nГотово!\n";
}
// Выводим статистику
cout << "\nСтатистика печати:\n";
for (PrintStat s : stats) {
	cout << s.user << ": " << s.pages << " стр., "
		<< (s.end - s.start) << " сек\n";
}

}
