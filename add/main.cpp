
//==================================================

//运算符重载的实现，本例子是进行有理数的加减乘除的设计

//使用的编译器：CodeBlocks

//编程语言：C/C++

//涉及知识：类、对象、运算符重载等

//==================================================

#include <iostream>

#include <stdlib.h>



//==================================================

//定义一个Rational类，类中定义了六个公有函数，两个私有变量，一个私有函数

//==================================================

class Rational

{

public:

    Rational(int num,int denom);                   //实现有理数的形式"num/denom"



    Rational operator+(Rational rhs);              //加法重载

    Rational operator-(Rational rhs);              //减法重载

    Rational operator*(Rational rhs);              //乘法重载

    Rational operator/(Rational rhs);              //除法重载



    void print();                                  //打印结果输出



private:

    void normalize();      //对分数的简化处理



    int numerator;         //分子

    int denominator;       //分母

};



Rational::Rational(int num,int denom)

{

    numerator = num;

    denominator = denom;



    normalize();

}



//==================================================

//做化简处理，如出现2/16这样的情况，就需要化简为1/8

//==================================================

void Rational::normalize()

{

    //确保分母为正

    if(denominator < 0)

    {

        numerator = -numerator;

        denominator = -denominator;

    }



    //欧几里得算法

    int a = abs(numerator);

    int b = abs(denominator);



    while(b>0)

    {

        int t = a%b;

        a = b;

        b = t;

    }



    numerator/=a;

    denominator/=a;

}





Rational Rational::operator+(Rational rhs)

{

    int a = numerator;

    int b = denominator;

    int c = rhs.numerator;

    int d = rhs.denominator;



    int e = a*b +c*d;

    int f = b*d;



    return Rational(e,f);

}



Rational Rational::operator-(Rational rhs)

{

    rhs.numerator = -rhs.numerator;



    return operator+(rhs);

}



Rational Rational::operator*(Rational rhs)

{

    int a = numerator;

    int b = denominator;

    int c = rhs.numerator;

    int d = rhs.denominator;



    int e = a*c;

    int f = b*d;



    return Rational(e,f);

}



Rational Rational::operator/(Rational rhs)

{

    int t = rhs.numerator;

    rhs.numerator = rhs.denominator;

    rhs.denominator = t;



    return operator*(rhs);

}



void Rational::print()

{

    if(numerator%denominator == 0)

       std::cout<<numerator / denominator;

    else

       std::cout<<numerator <<"/"<<denominator;

}



int main()

{

    Rational f1(2,16);

    Rational f2(7,8);



    Rational res = f1+f2;

    f1.print();

    std::cout<<" + ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";





    res = f1 - f2;

    f1.print();

    std::cout<<" - ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    res = f1 * f2;

    f1.print();

    std::cout<<" * ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    res = f1 / f2;

    f1.print();

    std::cout<<" / ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    return 0;

}
