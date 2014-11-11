//*******************************************
//           math function
//res::http://docs.mql4.com/maths
//*******************************************
#ifndef MATHTRIG_H__
#define MATHTRIG_H__

double MathAbs(double value);
double MathArccos(double x);
double MathArcsin(double x);
double MathArctan(double x);
double MathCeil(double x);
double MathCos(double value);
double MathExp(double d);
double MathFloor(double x);
double MathLog(double x);
double MathLog10(double x);
double MathMax(double value1, double value2);
double MathMin(double value1, double value2);
double MathMod(double value, double value2);
double MathPow(double base, double exponent);
int MathRand();
double MathRound(double value);
double MathSin(double value);
double MathSqrt(double x);
void MathSrand(int seed);
double MathTan(double x);
bool MathIsValidNumber(double number);
#endif
