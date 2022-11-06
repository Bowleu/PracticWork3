#include <iostream>
#include <windows.h>
using namespace std;

void setTextColor(int textColorIndex) { // Смена цвета текста
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (0 << 4) + textColorIndex);
}

void printArray(int **arr, int length, int isClsNeeded) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << arr[i][j] << ' ';
            if (arr[i][j] < 10) {
                cout << ' ';
            }
            if (length == 10) {
                cout << ' ';
            }
            cout << "| ";
        }
        cout << '\n';
    }
    cout << '\n';
    if (isClsNeeded)
        system("cls");
}

bool isRestartNeeded() { // Функция перезапуска программы
    cin.clear(); // Очистка ввода от ошибок
    cin.sync();
    cout << "Перезагрузить программу? [";
    setTextColor(2);
    cout << "Y";
    setTextColor(15);
    cout << "/";
    setTextColor(4);
    cout << "любой другой символ";
    setTextColor(15);
    cout << "] ";
    string answer;
    cin >> answer;
    if (answer == "y" || answer == "Y")
        return true;
    else
        return false;
}

int main()
{
    srand(0);
    setlocale(0, "");
    setTextColor(15);
    int size;
    cout << "Введите размер матрицы (6, 8, 10): ";
    cin >> size;
    if (size != 6 and size != 8 and size != 10 and size != 4) {
        setTextColor(4);
        cout << "Неверное значение! Программа будет остановлена." << '\n';
        setTextColor(15);
        return 0;
    }
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    cout << "\t|Заполнение матрицы|" << '\n';
    setTextColor(6);
    cout << "[1] ";
    setTextColor(15);
    cout << "Спиралью" << '\n';
    setTextColor(6);
    cout << "[2] ";
    setTextColor(15);
    cout << "Змейкой" << '\n';
    cout << "Как заполнить матрицу: ";
    short int fillingType;
    cin >> fillingType;
    int counter = 1;
    int i = 0, j = 0;
    system("cls");
    switch (fillingType) {
    case 1:
        while (counter <= size * size) {
            if (counter == size * size) {
                *(*(matrix + i) + j) = rand() % (size * size) + 1;
                printArray(matrix, size, 0);
                counter++;
            }
            else {
                while (j < size - 1 and *(*(matrix + i) + j + 1) == 0) {
                    *(*(matrix + i) + j) = rand() % (size * size) + 1;
                    j++;
                    counter++;
                    printArray(matrix, size, 1);
                    Sleep(0);

                }
                while (i < size - 1 and *(*(matrix + i + 1) + j) == 0) {
                    *(*(matrix + i) + j) = rand() % (size * size) + 1;
                    i++;
                    counter++;
                    printArray(matrix, size, 1);
                    Sleep(0);
                }
                while (j > 0 and *(*(matrix + i) + j - 1) == 0) {
                    *(*(matrix + i) + j) = rand() % (size * size) + 1;
                    j--;
                    counter++;
                    printArray(matrix, size, 1);
                    Sleep(0);
                }
                while (i > 0 and *(*(matrix + i - 1) + j) == 0) {
                    *(*(matrix + i) + j) = rand() % (size * size) + 1;
                    i--;
                    counter++;
                    printArray(matrix, size, 1);
                    Sleep(0);
                }
            }
        }
        break;
    case 2:
        while (counter <= size * size) {
            while (i + 1 <= size) {
                *(*(matrix + i) + j) = rand() % (size * size) + 1;
                printArray(matrix, size, 1);
                Sleep(0);
                i++;
                counter++;
            }
            i--;
            j++;
            while (i - 1 >= -1) {
                *(*(matrix + i) + j) = rand() % (size * size) + 1;
                if (counter == size * size)
                    printArray(matrix, size, 0);
                else
                    printArray(matrix, size, 1);
                Sleep(0);
                i--;
                counter++;
            }
            i++;
            j++;
        }
        break;
    default:
        setTextColor(4);
        cout << "Неверное значение! Программа будет остановлена." << '\n';
        setTextColor(15);
        return 0;
    }
    cout << "\t|Изменение матрицы|" << '\n';
    setTextColor(6);
    cout << "[1] ";
    setTextColor(15);
    cout << "По часовой стрелке" << '\n';
    setTextColor(6);
    cout << "[2] ";
    setTextColor(15);
    cout << "Крест-накрест" << '\n';
    setTextColor(6);
    cout << "[3] ";
    setTextColor(15);
    cout << "По-вертикали" << '\n';
    setTextColor(6);
    cout << "[4] ";
    setTextColor(15);
    cout << "По-горизонтали" << '\n';
    setTextColor(6);
    cout << "[5] ";
    setTextColor(15);
    cout << "Не менять" << '\n';
    cout << "Как изменить матрицу: ";
    short int changeType;
    cin >> changeType;
    switch (changeType) {
    case 1:
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                int temp = *(*(matrix + i) + j);
                *(*(matrix + i) + j) = *(*(matrix + i + size / 2) + j);
                *(*(matrix + i + size / 2) + j) = *(*(matrix + i + size / 2) + j + size / 2);
                *(*(matrix + i + size / 2) + j + size / 2) = *(*(matrix + i) + j + size / 2);
                *(*(matrix + i) + j + size / 2) = temp;
            }
        }
        break;
    case 2:
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                int firstTemp = *(*(matrix + i) + j);
                int secondTemp = *(*(matrix + i) + j + size / 2);
                *(*(matrix + i) + j) = *(*(matrix + i + size / 2) + j + size / 2);
                *(*(matrix + i + size / 2) + j + size / 2) = firstTemp;
                *(*(matrix + i) + j + size / 2) = *(*(matrix + i + size / 2) + j);
                *(*(matrix + i + size / 2) + j) = secondTemp;
            }
        }
        break;
    case 3:
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                int firstTemp = *(*(matrix + i) + j);
                int secondTemp = *(*(matrix + i) + j + size / 2);
                *(*(matrix + i) + j) = *(*(matrix + i + size / 2) + j);
                *(*(matrix + i + size / 2) + j) = firstTemp;
                *(*(matrix + i) + j + size / 2) = *(*(matrix + i + size / 2) + j + size / 2);
                *(*(matrix + i + size / 2) + j + size / 2) = secondTemp;
            }
        }
        break;
    case 4:
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                int firstTemp = *(*(matrix + i) + j);
                int secondTemp = *(*(matrix + i + size / 2) + j);
                *(*(matrix + i) + j) = *(*(matrix + i) + j + size / 2);
                *(*(matrix + i) + j + size / 2) = firstTemp;
                *(*(matrix + i + size / 2) + j) = *(*(matrix + i + size / 2) + j + size / 2);
                *(*(matrix + i + size / 2) + j + size / 2) = secondTemp;
            }
        }
        break;
    case 5:
        break;
    default:
        setTextColor(4);
        cout << "Неверное значение! Программа будет остановлена." << '\n';
        setTextColor(15);
        return 0;
    }
    printArray(matrix, size, 0);

    bool swapped;
    int lastUnsortedIndex[2] = {size - 1, size - 1};
    int tempUnsortedIndex[2];
    do {
        swapped = false;
        for (int i = 0; i < lastUnsortedIndex[0]; i++) {
            for (int j = 0; j < size; j++) {
                if (*(*(matrix + i) + j) > *(*(matrix + i + (j + 1) / size) + (j + 1) % size)) {
                    swap(*(*(matrix + i) + j), *(*(matrix + i + (j + 1) / size) + (j + 1) % size));
                    swapped = true;
                    tempUnsortedIndex[0] = i;
                    tempUnsortedIndex[1] = j;
                }
            }
        }
        for (int j = 0; j < lastUnsortedIndex[1]; j++) {
            if (*(*(matrix + lastUnsortedIndex[0]) + j) > *(*(matrix + lastUnsortedIndex[0]) + j + 1)) {
                swap(*(*(matrix + lastUnsortedIndex[0]) + j), *(*(matrix + lastUnsortedIndex[0]) + j + 1));
                swapped = true;
                tempUnsortedIndex[0] = lastUnsortedIndex[0];
                tempUnsortedIndex[1] = j;
            }
        }
        lastUnsortedIndex[0] = tempUnsortedIndex[0];
        lastUnsortedIndex[1] = tempUnsortedIndex[1];
    } while (swapped);
    printArray(matrix, size, 0);

    char operation;
    int number;
    cout << "Введите операцию и число, например: / 6" << '\n';
    cout << "Ввод данных: ";
    cin >> operation >> number;
    if (operation != '+' and operation != '-' and operation != '/' and operation != '*' and operation != 'x') {
        setTextColor(4);
        cout << "Неверное значение! Программа будет остановлена." << '\n';
        setTextColor(15);
        return 0;
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (operation == '/')
                    *(*(matrix + i) + j) /= number;
                else if (operation == '+')
                    *(*(matrix + i) + j) += number;
                else if (operation == '-')
                    *(*(matrix + i) + j) -= number;
                else
                    *(*(matrix + i) + j) *= number;
            }
        }
    }
    printArray(matrix, size, 0);
    if (isRestartNeeded()) {
        cout << '\n' << "Перезапуск программы..." << '\n' << '\n';
        Sleep(2000); // Остановка времени на 2c 
        main(); // Перезапуск программы
    }
    else { // Выход  из программы
        return 0;
    }
}