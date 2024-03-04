/**
 *  @example serial_port_read.cpp
 */

#include <libserial/SerialPort.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>

constexpr const char* const SERIAL_PORT_1 = "/dev/ttyACM0" ;

/**
 * @brief This example demonstrates configuring a serial port and 
 *        reading serial data.
 */
int main()
{
    using namespace LibSerial ;

    // Instantiate a SerialPort object.
    SerialPort serial_port ;

    try
    {
        // Open the Serial Port at the desired hardware port.
        serial_port.Open(SERIAL_PORT_1) ;
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }

    // Set the baud rate of the serial port.
    serial_port.SetBaudRate(BaudRate::BAUD_115200) ;
    // Set the number of data bits.
    serial_port.SetCharacterSize(CharacterSize::CHAR_SIZE_8) ;
    // Turn off hardware flow control.
    serial_port.SetFlowControl(FlowControl::FLOW_CONTROL_NONE) ;
    // Disable parity.
    serial_port.SetParity(Parity::PARITY_NONE) ;
    // Set the number of stop bits.
    serial_port.SetStopBits(StopBits::STOP_BITS_1) ;
    // Wait for data to be available at the serial port.
    while(!serial_port.IsDataAvailable()) 
    {
        usleep(1000) ;
    }

    // Specify a timeout value (in milliseconds).
    size_t ms_timeout = 250 ;
    usleep(1000) ;

    DataBuffer read_buffer ;

    try
    {
        // Read as many bytes as are available during the timeout period.
        serial_port.Read(read_buffer, 0, ms_timeout) ;
    }
    catch (const ReadTimeout&)
    {
        int buf = 0;
        for (size_t i = 0 ; ((i < read_buffer.size()) && (i < out.size())) ; i++)
        {
            buf += (int)(read_buffer.at(i));
            if(i % 2) {
                out[i] = buf;
        //        std::cout << (buf) << std::endl ;
                buf = 0;
            }
        }

        std::cerr << "The Read() call timed out waiting for additional data." << std::endl ;
    }

    // Successful program completion.
    std::cout << "The example program successfully completed!" << std::endl ;
    return EXIT_SUCCESS ;
}