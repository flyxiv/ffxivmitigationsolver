/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef UTIL_STRING_H
#define UTIL_STRING_H

/*
 * Parses str based on delimiter and return a list of strings.
 * ex) split_string("Hello,World,!", ",") -> ["Hello", "World", "!"]
 */
int split_string(char *str, const char delimeters[static 1], int max_token_cnt, int token_length, char token[][token_length]);

#endif