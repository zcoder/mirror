/* 
 * File:   answer.h
 * Author: zhenka
 *
 * Created on 5 Август 2012 г., 23:46
 */

#include "../deps/jansson/src/jansson.h"

#ifndef ANSWER_H
#define	ANSWER_H

class answer
{
public:
    typedef std::multimap<std::string, std::string> val_t;
    const val_t& get_items();
    answer( json_t* in_json );
    ~answer( );
private:
    val_t answer_value;
} ;

#endif	/* ANSWER_H */

