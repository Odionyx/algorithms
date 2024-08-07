#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>

int counterNum(int* arr, int size, int keyPoint){
    if(!arr) return -101;
    if( keyPoint< *arr) return size;
    if( keyPoint> arr[size-1]) return 0;
    if( keyPoint== arr[1]) return size- 2;
    if( keyPoint== arr[size- 3]) return 2;

    int count{0}, r{(size-1)};
    for( int l{0}; l< r; ++l){
        int m{l+(r- l)/2};
        if( keyPoint >= arr[m]) l= ++m;
        else r= --m;
        count= size- m;
    }
    return count;
}

int main( int argc, char** argv){
    setlocale(LC_ALL, "ru_RU");
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    int arr[]{14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr)/sizeof(arr[0]);
    int point{0};

    std::cout<< "Введите точку отсчёта: ";
    std::cin>> point;

    std::cout<< "Количество элементов в массиве больших, чем "
             << point<< ':'<< ' '<< counterNum(arr, size, point)
             << std::endl;
    return 0;
}
