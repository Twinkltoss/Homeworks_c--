#include <iostream>
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



//Задание 3-1.
//Создать имитационную модель "остановка маршрутных
//такси". Необходимо вводить следующую информацию:
//среднее время между появлениями пассажиров на остановке в разное время суток, среднее время между появлениями маршруток на остановке в разное время суток,
//тип остановки(конечная или нет).Необходимо определить : среднее время пребывание человека на остановке,
//достаточный интервал времени между приходами маршруток, чтобы на остановке находилось не более N людей
//одновременно.Количество свободных мест в маршрутке является случайной величиной.
//Задание 3-2.
//Разработать приложение, имитирующее очередь печати
//принтера.Должны быть клиенты, посылающие запросы
//на принтер, у каждого из которых есть свой приоритет.
//Каждый новый клиент попадает в очередь в зависимости
//от своего приоритета.Необходимо сохранять статистику печати(пользователь, время) в отдельной очереди.
//Предусмотреть вывод статистики на экран.


int main()
{
	srand(time(0));
	//int size = 5;
	//int* arr = new int[size] {1,12,7,-5,4};

	Matrix<int> mat1(5);
	Matrix<int> mat2(5);
	Matrix<int> mat3(5);
	mat1.Random_Filling();
	mat2.Random_Filling();
	mat1.Show_Matrix();
	cout << endl;
	mat2.Show_Matrix();
	mat3=mat1/ mat2;
	cout << endl;
	mat3.Show_Matrix();



	//std::cout << Min_Val(arr, size);
	//std::cout <<"\n" << Max_Val(arr, size);

	//Print_Arr(arr, size);
	//Sort(arr, size);
	//std::cout << std::endl;
	//Print_Arr(arr, size);


}
