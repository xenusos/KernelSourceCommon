/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends: xenus.h
*/
#pragma once


// buffer         in                length of buffer (may optionally include the NULL byte)
// offset         in/out            state
// string_out     out     optional  output destination of the next value to consume
// str_buf_length in                equals the length of string_out with the additional overhead of a NULL byte. an arbitrary value can be passed if string_out is null
// str_length     out     optional  callee returns the length of the value without str_buf_length clipping
// returns:
//     XENUS_ERROR_CSV_EOS        the offset variable is equal to buf_length or at an index whereby no more values could be read 
//     XENUS_STATUS_CSV_READ_ALL  consumed a value and no more value can be read past this offset
//     XENUS_STATUS_OKAY          consumed a value and more keys exist past this offset

XENUS_SYM error_t csv_process_buffer(const char * buffer, uint_t buf_length, uint_t * offset, char * string_out, uint_t str_buf_length, uint_t * str_length);