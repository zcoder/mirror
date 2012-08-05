/* 
 * File:   answer.cpp
 * Author: zhenka
 * 
 * Created on 5 Август 2012 г., 23:46
 */

#include "answer.h"

const answer::val_t& answer::get_items()
{
    return answer_value;
}

answer::answer( json_t* in_json )
{
    
}

answer::~answer( )
{
}

