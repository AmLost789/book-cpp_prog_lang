/*
 * trim.h
 *
 *  Created on: Oct 19, 2019
 *      Author: jonrw
 */

#ifndef TRIM_H_
#define TRIM_H_

#include <algorithm>
#include <cctype>
#include <locale>
#include <string>

void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);


#endif /* TRIM_H_ */
