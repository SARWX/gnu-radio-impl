/*
#include <iostream>
#include <fstream>

// #include <conio.h>      // getch()

class cdc {
private:
    int baudrate;       // baudrate of the COM device
    char *path;         // path to the COM device

public:
// constructor:
    cdc(int b, char *p) {
        baudrate = b;
        path = p;         // NOOOO, strcopy
    }
    
    int convert_to_num() {

    }
};

int main() {
   // // Create CDC connection
    // char *cdc_path = "/dev/ttyACM0";
    // int cdc_baudrate = 2000000;
    // cdc milandr(cdc_path, cdc_baudrate);

    // while(1) {
    //     int val = milandr.convert_to_num();
    //     std::cout << val;
    // }


    std::ifstream in("/dev/ttyACM0"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (1)
        {
            int a;
            in >> a;
            std::cout << a << std::endl;
        }
    }
    else {
        std::cout << "NOT WORKING" << std::endl;
    }
    in.close();     // закрываем файл
*/

// #include <SerialPort.h>
// #include <SerialStream.h>
#include "/usr/include/libserial/SerialStream.h"
#include <iostream>

using namespace LibSerial;

int main()
{
    SerialStream serialPort("/dev/ttyACM0", std::ios_base::in | std::ios_base::out);
    
    if (serialPort.IsOpen())
    {
        std::cout << "Порт успешно открыт." << std::endl;
        
        // Установка параметров порта (например, скорость передачи данных)
        serialPort.SetBaudRate(SerialStreamBuf::BAUD_115200);

        // Чтение/запись данных с/на порт
        char data;
        while (serialPort.get(data))
        {
            std::cout << data; // Обработка прочитанных данных
        }

        std::cout << "Чтение завершено." << std::endl;

        // Закрытие порта
        serialPort.Close();
    }
    else
    {
        std::cerr << "Ошибка при открытии порта." << std::endl;
    }

    return 0;
}