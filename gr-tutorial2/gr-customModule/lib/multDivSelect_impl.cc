/* -*- C++ -*- */
/*
 * Copyright 2022 YourName.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "multDivSelect_impl.h"
#include <gnuradio/io_signature.h>
#include "/usr/include/libserial/SerialStream.h"

#include <libserial/SerialPort.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>

namespace gr {
namespace customModule {

using input_type = gr_complex;
using output_type = gr_complex;
multDivSelect::sptr multDivSelect::make(bool selector)
{
    return gnuradio::make_block_sptr<multDivSelect_impl>(selector);
}


/*
 * The private constructor
 */
multDivSelect_impl::multDivSelect_impl(bool selector)
    : gr::sync_block("multDivSelect",
                     gr::io_signature::make(
                         2 /* min inputs */, 2 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
    _selector = selector;
    // Часть конструктора, ответсвенная за создание объекта serial_port
    constexpr const char* const SERIAL_PORT_1 = "/dev/ttyACM0";
    try
    {
        // Open the Serial Port at the desired hardware port.
        serial_port.Open(SERIAL_PORT_1) ;
    }
    catch (const LibSerial::OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return;              // Тут был return, но конструктор не может возвращать ничего
    }

    // Set the baud rate of the serial port.
    serial_port.SetBaudRate(LibSerial::BaudRate::BAUD_2000000) ;
    // Set the number of data bits.
    serial_port.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8) ;
    // Turn off hardware flow control.
    serial_port.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE) ;
    // Disable parity.
    serial_port.SetParity(LibSerial::Parity::PARITY_NONE) ;
    // Set the number of stop bits.
    serial_port.SetStopBits(LibSerial::StopBits::STOP_BITS_1) ;
    // Wait for data to be available at the serial port.
    while(!serial_port.IsDataAvailable()) 
    {
        usleep(1000) ;
    }
}

/*
 * Our virtual destructor.
 */
multDivSelect_impl::~multDivSelect_impl() 
{
    // Закрытие порта
    this->serial_port.Close();
}

int multDivSelect_impl::work(int noutput_items,
                               gr_vector_const_void_star& input_items,
                               gr_vector_void_star& output_items)
{
    auto in0 = static_cast<const input_type*>(input_items[0]);
    auto in1 = static_cast<const input_type*>(input_items[1]);
    auto out1 = static_cast<output_type*>(output_items[0]);
    auto out2 = static_cast<output_type*>(output_items[1]);
    // auto out2 = static_cast<output_type*>(output_items[1]);

    // for (int index = 0; index < noutput_items; index++) {
    //     if (_selector) { out[index] = in0[index] * in1[index]; }
    //     else{ out[index] = in0[index] / in1[index]; }
    // }
    /////////////////////////////////////////////////////////////////////////////////////////
    // Пробуем сделать включение libserial:
    // Instantiate a SerialPort object.
    
    


    // Specify a timeout value (in milliseconds).
    size_t ms_timeout = 10000;
    // usleep(1000);

    LibSerial::DataBuffer read_buffer ;
    // Read noutput_items * 2 bytes 
    serial_port.Read(read_buffer, (noutput_items * 2), ms_timeout);
    int buf = 0;
    for(int i = 0; i < (noutput_items) ; i++)
    {
        buf = read_buffer.at(i * 2) + (read_buffer.at(i * 2 + 1) << 8);
        out1[i] = buf;
        // if ((i % 2) == 0)
        // {
        //     out1[i/2] = buf;
        // }
        // else
        // {
        //     out2[i/2] = buf;
        // }
    }





    // int i = 0;
    // while (i < noutput_items)
    // {
    //     serial_port.Read(read_buffer, (2), ms_timeout);
    //     int buf = read_buffer.at(1);
    //     buf = buf << 8;
    //     buf += read_buffer.at(0);
    //     out1[i++] = buf;

        // serial_port.Read(read_buffer, (2), ms_timeout);
        // buf = read_buffer.at(0);
        // buf = buf << 8;
        // buf += read_buffer.at(1);
        // out1[i++] = buf;
    // }
    

    

    // int buf = 0;
    // for (size_t i = 0; i < 128; i++)
    // {
    //     buf = buf << 8;
    //     buf += (int)(read_buffer.at(i));
    //     if(i % 2) 
    //     {
    //         out[i] = buf;
    // //        std::cout << (buf) << std::endl ;
    //         buf = 0;
    //     }
    // }

    // std::cerr << "Ok" << std::endl ;
    /////////////////////////////////////////////////////////////////////////////////////////
    // Tell runtime system how many output items we produced.
    return (noutput_items);
}

} /* namespace customModule */
} /* namespace gr */