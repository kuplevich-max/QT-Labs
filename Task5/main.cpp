#include <QCoreApplication>
class Expression
{
public:
    virtual double evaluate() const = 0;
};

class Number: public Expression{
public:
    double val;
    Number(double value):val(value)
    {

    }
    double evaluate() const override
    {
        return val;
    }
};

class BinaryOperation: public Expression
{
public:
    BinaryOperation(Expression *l, char op, Expression *r)
        :left(l), right(r), operation(op)
    {

    }
    double evaluate() const override
    {
        switch(operation)
        {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        }
        return 0;
    }
private:
    Expression const *left;
    Expression const *right;
    char operation;
};

bool check_equals(Expression const *left, Expression const *right)
{
    return (*((size_t*)left) == *((size_t*)right));
}
