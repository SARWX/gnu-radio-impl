/* -*- c++ -*- */
/*
 * Copyright 2024 gnuradio.org.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TUTORIAL_MY_QPSK_DEMOD_CB_H
#define INCLUDED_TUTORIAL_MY_QPSK_DEMOD_CB_H

#include <gnuradio/block.h>
#include <gnuradio/tutorial/api.h>

namespace gr {
namespace tutorial {

/*!
 * \brief <+description of block+>
 * \ingroup tutorial
 *
 */
class TUTORIAL_API my_qpsk_demod_cb : virtual public gr::block
{
public:
    typedef std::shared_ptr<my_qpsk_demod_cb> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of tutorial::my_qpsk_demod_cb.
     *
     * To avoid accidental use of raw pointers, tutorial::my_qpsk_demod_cb's
     * constructor is in a private implementation
     * class. tutorial::my_qpsk_demod_cb::make is the public interface for
     * creating new instances.
     */
    static sptr make(bool gray_code);
};

} // namespace tutorial
} // namespace gr

#endif /* INCLUDED_TUTORIAL_MY_QPSK_DEMOD_CB_H */
