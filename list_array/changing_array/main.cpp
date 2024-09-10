#include <iostream>
#include <windows.h>
using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size){
    std::cout<< "Динамический массив: ";
    for( int i{0}; i< actual_size; ++i){
        if( i< logical_size) std::cout<< arr[i]<< ' ';
        else std::cout<< '_'<< ' ';
    }
    std::cout<<std::endl;
}

int main(){
//    cout << "Hello World!" << endl;
    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int num{0};
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
    print_dynamic_array( arr, logical_size, actual_size);

    delete[] arr;
    arr= nullptr;
    return 0;
}
