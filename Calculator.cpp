#include "Calculator.h"

Calculator::Calculator(/* args */)
    : Root(nullptr)
{
}

Calculator::Calculator(std::string expression2)
    : Root(nullptr)
{
    this->expression = expression2;
}

bool Calculator::insert(std::string insertExpression)
{
    expression = insertExpression;
    return true;
}

int priority(char op)
{
    switch (op)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '%':
        return 1;
        break;
    case '^':
        return 2;
        break;
    default:
        return -1;
        break;
    }
}

std::string infixToPostFix(std::string ifExpression)
{
    std::string pfExpression;
    std::istringstream input(ifExpression);
    std::string s;
    Stack<std::string> st;
    while (!input.eof())
    {
        input >> s;

        if (s == "(")
        {
            st.push("(");
        }
        else if (s == ")")
        {
            while (st.top() != "(")
            {
                pfExpression = pfExpression + st.top() + " ";
                st.pop();
            }
            st.pop();
        }
        else if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "^")
        {
            while (st.is_empty() == false && priority(s[0]) <= priority(st.top()[0]))
            {
                pfExpression = pfExpression + st.top() + " ";
                st.pop();
            }
            st.push(s);
        }
        else
        {
            pfExpression = pfExpression + s + " ";
        }
    }
    while (!st.is_empty())
    {
        pfExpression = pfExpression + st.top() + " ";
        st.pop();
    }

    pfExpression.pop_back();
    return pfExpression;
}

bool Calculator::parse_expr()
{
    if (expression == "")
        return false;
    expression = infixToPostFix(expression);
    std::istringstream input(expression);
    std::string token;
    int number;

    //builder.start_expression();

    while (!input.eof())
    {
        input >> token;
        if (token == "+")
            this->builder.add_operator();
        else if (token == "-")
            this->builder.subtract_operator();
        else if (token == "*")
            this->builder.multiplication_operator();
        else if (token == "/")
            this->builder.division_operator();
        else
        {
            this->builder.build_number(std::stoi(token));
        }
    }
    Root = this->builder.getRoot();
    return true;
}

int Calculator::evaluate()
{
    parse_expr();
    return Root->eval();
}

Calculator::~Calculator()
{
}