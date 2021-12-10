#include <string>
#include <sstream>
#include "Stack.h"

inline int priority(char op)
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

