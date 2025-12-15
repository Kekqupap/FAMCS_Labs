#include "Par.h"
#include "Stack.h"
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cmath>

// Конструкторы Expression
Expression::Expression() : token(""), args(nullptr) {}

Expression::Expression(std::string token) : token(token), args(nullptr) {}

Expression::Expression(std::string token, const Expression& a) : token(token) {
    args = new Stack<Expression>();
    *args << a;
}

Expression::Expression(std::string token, const Expression& a, const Expression& b) : token(token) {
    args = new Stack<Expression>();
    *args << a;
    *args << b;
}

// Деструктор
Expression::~Expression() {
    delete args;
}

// Конструктор копирования
Expression::Expression(const Expression& other) : token(other.token) {
    if (other.args != nullptr) {
        args = new Stack<Expression>();
        *args = *(other.args);
    } else {
        args = nullptr;
    }
}

// Оператор присваивания
Expression& Expression::operator=(const Expression& other) {
    if (this != &other) {
        token = other.token;
        delete args;
        if (other.args != nullptr) {
            args = new Stack<Expression>();
            *args = *(other.args);
        } else {
            args = nullptr;
        }
    }
    return *this;
}

// Оператор сравнения
bool Expression::operator==(const Expression& other) const {
    if (token != other.token) return false;
    
    if (args == nullptr && other.args == nullptr) return true;
    if (args == nullptr || other.args == nullptr) return false;
    
    if (args->size() != other.args->size()) return false;
    
    for (size_t i = 0; i < args->size(); i++) {
        if (!((*args)[i] == (*other.args)[i])) return false;
    }
    
    return true;
}

// Реализация методов парсера
std::string Parser::parse_token() {
    while (std::isspace(*input)) ++input;

    if (std::isdigit(*input)) {
        std::string number;
        while (std::isdigit(*input) || *input == '.') number.push_back(*input++);
        return number;
    }

    static const std::string tokens[] = {
        "+", "-", "**", "^", "*", "/", "mod", "abs", "log", "lg", "ln",
        "sin", "cos", "(", ")", "G", "tan", "tg", "cot", "exp", "%",
        "sh", "ch", "th", "cth", "asin", "acos", "atan", "acot", "atg",
        "arsh", "arch", "arth", "arcth", "@", "sqrt", "cbrt", "deg"
    };
    
    for (auto& t : tokens) {
        if (std::strncmp(input, t.c_str(), t.size()) == 0) {
            input += t.size();
            return t;
        }
    }

    return "";
}

Expression Parser::parse_simple_expression() {
    auto token = parse_token();
    if (token.empty()) throw std::runtime_error("Empty token");

    if (token == "(") {
        auto result = parse();
        if (parse_token() != ")") throw std::runtime_error("Cannot find necessary ')'");
        return result;
    }

    if (std::isdigit(token[0]))
        return Expression(token);

    return Expression(token, parse_simple_expression());
}

int get_priority(const std::string& binary_op) {
    if (binary_op == "+") return 1;
    if (binary_op == "-") return 1;
    if (binary_op == "*") return 2;
    if (binary_op == "/") return 2;
    if (binary_op == "mod" || binary_op == "%") return 2;
    if (binary_op == "**" || binary_op == "^") return 3;
    return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {
    auto left_expr = parse_simple_expression();

    for (;;) {
        auto op = parse_token();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return parse_binary_expression(0);
}

double eval(const Expression& e) {
    if (e.args == nullptr) {
        return strtod(e.token.c_str(), nullptr);
    }

    switch (e.args->size()) {
    case 2: {
        auto a = eval((*e.args)[1]);
        auto b = eval((*e.args)[0]);
        if (e.token == "+") return a + b;
        if (e.token == "-") return a - b;
        if (e.token == "*") return a * b;
        if (e.token == "/") return a / b;
        if (e.token == "**" || e.token == "^") return pow(a, b);
        if (e.token == "mod" || e.token == "%") {
            int int_a = static_cast<int>(a);
            int int_b = static_cast<int>(b);
            return static_cast<double>((int_a % int_b + int_b) % int_b);
        }
        throw std::runtime_error("Unknown binary expression");
    }

    case 1: {
        auto a = eval((*e.args)[0]);
        if (e.token == "-") return -a;
        if (e.token == "@" || e.token == "deg") return a * acos(-1.0) / 180.0;
        if (e.token == "abs") return fabs(a);
        if (e.token == "exp") return exp(a);
        if (e.token == "cbrt") return cbrt(a);
        if (e.token == "sqrt") return sqrt(a);
        if (e.token == "sin") return sin(a);
        if (e.token == "cos") return cos(a);
        if (e.token == "tan" || e.token == "tg") return tan(a);
        if (e.token == "cot") return 1.0 / tan(a);
        if (e.token == "sh") return sinh(a);
        if (e.token == "ch") return cosh(a);
        if (e.token == "th") return tanh(a);
        if (e.token == "cth") return 1.0 / tanh(a);
        if (e.token == "asin") return asin(a);
        if (e.token == "acos") return acos(a);
        if (e.token == "atan" || e.token == "atg") return atan(a);
        if (e.token == "acot") return acos(-1.0) / 2.0 - atan(a);
        if (e.token == "arsh") return asinh(a);
        if (e.token == "arch") return acosh(a);
        if (e.token == "arth") return atanh(a);
        if (e.token == "arcth") return 0.5 * log((a + 1.0) / (a - 1.0));
        if (e.token == "log" || e.token == "ln") return log(a);
        if (e.token == "lg") return log10(a);
        if (e.token == "G") return tgamma(a);
        throw std::runtime_error("Unknown unary expression");
    }

    default:
        throw std::runtime_error("Invalid number of arguments");
    }
}