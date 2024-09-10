#include <iostream>
#include <windows.h>
using namespace std;

void print_dynamic_array( int* &arr, int logical_size, int actual_size){
    std::cout<< "Динамический массив: ";
    for( int i{0}; i< actual_size; ++i){
        if( i< logical_size) std::cout<< arr[i]<< ' ';
        else std::cout<< '_'<< ' ';
    }
    std::cout<<std::endl;
}

int*& append_to_dynamic_array( int* &arr, int& logical_size,
                              int& actual_size, int num){
    if( num == 0) return arr;

    arr[logical_size]= num;
    ++logical_size;

    if( logical_size== actual_size){
        actual_size= (logical_size* 2);

        int* arr_temp= new int[actual_size];
        for( int i{0}; i< logical_size; ++i){
            arr_temp[i]= arr[i];
        }
        delete[] arr;
        arr= new int[actual_size];
        arr= arr_temp;

        delete[] arr_temp;
        arr_temp= nullptr;
    }
    return arr;
}

int main(){
//    cout << "Hello World!" << endl;
    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int num{-1};
    int actual_size{0};
    int logical_size{0};

    std::cout<< "Введите фактичеcкий размер массива: ";
    std::cin>> actual_size;
    std::cout<< "Введите логический размер массива: ";
    std::cin>> logical_size;
    if( logical_size> actual_size){
        std::cout<< "Ошибка! Логический размер массива не "
                    "может превышать фактический!" << std::endl;
        return 0;
    }

    int* arr= new int[actual_size];
    for( int i{0}; i< logical_size; ++i){
        std::cout<< "Введите arr["<< i<< ']'<< ':'<< ' ';
        std::cin>> num;
        arr[i]= num;
    }
    while (num!= 0) {
        print_dynamic_array( arr, logical_size, actual_size);
        std::cout<< "Введите элемент для добавления: ";
        std::cin>> num;
        arr= append_to_dynamic_array( arr, logical_size, actual_size, num);
    }
    std::cout<< "Спасибо! Ваш массив: ";
    print_dynamic_array( arr, logical_size, actual_size);

    delete[] arr;
    arr= nullptr;
    return 0;
}
