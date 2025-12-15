#ifndef PAR_H
#define PAR_H
#pragma once

#include <string>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>

// Предварительное объявление Stack
template<typename T> class Stack;

struct Expression;

class Parser
{
public:
    explicit Parser(const char* input) : input(input) {}
    Expression parse();
private:
    std::string parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);

    const char* input;
};

struct Expression
{
    Expression();
    explicit Expression(std::string token);
    Expression(std::string token, const Expression& a);
    Expression(std::string token, const Expression& a, const Expression& b);
    ~Expression();
    Expression(const Expression& other);
    Expression& operator=(const Expression& other);
    bool operator==(const Expression& other) const;
    
    std::string token;
    Stack<Expression>* args;  // Указатель на Stack
};

double eval(const Expression& e);

#endif