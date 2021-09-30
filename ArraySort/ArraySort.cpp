#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//Вариант 1: Удалить из массива все четные числа и отсортировать по возрастанию оставшиеся элементы
//Вариант 2: Удалить из массива все нечетные числа и развернуть оставшиеся элементы в обратном порядке
//Вариант 3: Отсортировать массив таким образом, чтобы сначала по возрастанию шли все четные элементы массива, а затем по убыванию нечетные элементы.
void Print(vector<int>& array);
void RandomFilling(vector<int>& array);

void SortOptionOne(vector<int>& array);
bool IncreasingComparator(int a, int b);

void SortOptionTwo(vector<int>& array);

void SortOptionThree(vector<int>& array);
bool DecreasingComparator(int a, int b);

int main()
{
    srand(time(NULL));
    setlocale(0, "ru");

    vector<int> array;
    RandomFilling(array);
    vector<int> arrayCopy = array;
    cout << "Исходный массив:\n";
    Print(array);
    cout << endl;
    cout << "Выберите вариант сортировки.\n"
        << "Вариант 1: Удалить из массива все четные числа и отсортировать по возрастанию оставшиеся элементы\n"
        << "Вариант 2: Удалить из массива все нечетные числа и развернуть оставшиеся элементы в обратном порядке\n"
        << "Вариант 3: Отсортировать массив таким образом, чтобы сначала по возрастанию шли все четные элементы массива, а затем по убыванию нечетные элементы.\n"
        << "0 - выход\n";
    while (1) {
        int x;
        cin >> x;
        switch (x) {
        case 1:
            SortOptionOne(array);
            break;
        case 2:
            SortOptionTwo(array);
            break;
        case 3:
            SortOptionThree(array);
            break;
        case 0:
            return 0;
        }
        Print(array);
        array = arrayCopy;
    }
    return 0;
}

void Print(vector<int>& array) {
    for (auto i : array) {
        cout << i << " ";
    }
    cout << endl;
}

void RandomFilling(vector<int>& array) {
    array.resize(5 + rand() % 6);
    for (auto& i : array) {
        i = 5 + rand() % 10;
    }
}

void SortOptionOne(vector<int>& array) {
    //Удаляем все четные числа
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % 2 == 0) {
            array.erase(array.begin() + i);
            i--;
        }
    }
    //и сортируем по возрастанию оставшиеся элементы
    sort(array.begin(), array.end(), IncreasingComparator);
}

void SortOptionTwo(vector<int>& array)
{
    //Удаляем все нечетные числа
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % 2 != 0) {
            array.erase(array.begin() + i);
            i--;
        }
    }
    //и переворачиваем массив
    reverse(array.begin(), array.end());
}

void SortOptionThree(vector<int>& array)
{
    vector<int> evenArray;
    vector<int> unevenArray;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % 2 == 0) {
            evenArray.push_back(array[i]);
        }
        else {
            unevenArray.push_back(array[i]);
        }
    }
    sort(evenArray.begin(), evenArray.end(), IncreasingComparator);
    sort(unevenArray.begin(), unevenArray.end(), DecreasingComparator);
    array = evenArray;
    array.insert(array.end(), unevenArray.begin(), unevenArray.end());
}

bool DecreasingComparator(int a, int b)
{
    return a > b;
}

bool IncreasingComparator(int a, int b) {
    return a < b;
}
