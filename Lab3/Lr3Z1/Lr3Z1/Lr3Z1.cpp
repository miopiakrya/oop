/*
* ������� ���������, ����������� �������� � ��������������� �����������, �� ��������� :
* (3 �������)
* CustomExpression = (x1 + x2) * x3 * x4 ... .
* Substractor: 2 ��������, ��������� ����������� 23.65, -12.15.
* CustomExpressionEvaluator: 5 ���������, ��������� ������� 2.5, -5, -3, 2, 10.
* Multiplier: 4 ��������, ��������� ����������� 2.5, -3, 4, -1.
* shuffle() - �������� ������� ������ � ��������� ��������, ������� ������� �����.
* shuffle(size_t i, size_t j) - ���� ���� �� 2 �������� �� i-�� �� j-� �������� ����� ������� ����� - �������� �� �������.
* ������ ������: 
* Total : 4
* ( 2.5 + (-5) ) * (-3) * 2 * 10
* Equals to 150
*/ 

#include <iostream> 
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Substractor.h"
#include "Multiplier.h"
#include "ILoggable.h"

int main()
{
    ExpressionEvaluator* evaluators[3];
    
    evaluators[0] = new CustomExpressionEvaluator(5);
    double custom_operands[] = { 2.5, -5, -3, 2, 10 };
    evaluators[0]->setOperands(custom_operands, 5);
    std::cout << "Custom Expression Evaluator: " << std::endl;
    evaluators[0]->logToScreen();

    evaluators[1] = new Substractor(2);
    evaluators[1]->setOperand(0, 23.65);
    evaluators[1]->setOperand(1, -12.15);
    std::cout << std::endl << "Substractor Evaluator: " << std::endl;
    evaluators[1]->logToScreen();

    evaluators[2] = new Multiplier(4);
    evaluators[2]->setOperand(0, 2.5);
    evaluators[2]->setOperand(1, -3);
    evaluators[2]->setOperand(2, 4);
    evaluators[2]->setOperand(3, -1);
    std::cout << std::endl << "Multiplier Evaluator: " << std::endl;
    evaluators[2]->logToScreen();

    std::cout << std::endl << "Log To File: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        evaluators[i]->logToFile("Lab3.log");
    }
 
    std::cout << std::endl << "Shuffle Evaluators: " << std::endl << std::endl;
    for (int i = 0; i < 3; i++)
    {
        evaluators[i]->shuffle();
        evaluators[i]->logToScreen();
        std::cout << std::endl;
        evaluators[i]->~ExpressionEvaluator();
    }
}
