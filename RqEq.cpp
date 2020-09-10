#include <stdio.h>
#include <locale.h>
#include <math.h>
//================================================================
/*!
	\brief Coefficients availability function a, b, c
	\author Kolyadich Mark
	\version 1.0
	\date 06 September 2020
	\param a, b, c  - coefficients for a quadratic equation of the form: a*x^2 + b*x + c = 0
*/
void Enter (double a, double b, double c);
/*!
	\brief The function solves a quadratic equation
	\author Kolyadich Mark
	\version 1.0
	\date 06 September 2020
	\param a, b, c - parameters that are defined in the Enter function
	\param a, b, c - coefficients for a quadratic equation of the form: a*x^2 + b*x + c = 0
*/

void Sol_Quad_Equat (double a, double b, double c);

/*!
	\brief The function solves the linear equation
	\author Kolyadich Mark
	\version 1.0
	\date 06 September 2020
	\param k, b - parameters that are defined in the Enter function
	\param k, b - coefficients for a linear equation of the form: k*x + b = 0
*/
void Sol_Line_Equat (double k, double b);
//================================================================
int main ()
    {
    setlocale (LC_ALL, "Russian");
    double a = 0, b = 0, c = 0;
    Enter (a, b, c);
    Sol_Quad_Equat (a, b, c);
    return 0;
    }
//================================================================
void Enter (double a, double b, double c)
    {
    printf ("���������, ������� ������ ���������� ��������� ���� "
            "a*x^2 + b*x + c = 0.\n"
            "�����: ������� �. �. ���� �1\n"
            "������� �������� ��� a, b � c:");
    while (scanf ("%lg %lg %lg", &a, &b, &c) !=3)
        {
        printf ("\n"
                "������!!! �� ����� �� ���������� ��������. "
                "����������� ������� ����� ��� ���.\n"
                "������� �������� ��� a, b � c:");
        fflush (stdin);
        }
    printf ("��������� �� ����. ������������ ������� ���������:\n"
            "%lg*x^2 + %lg*x + %lg = 0\n"
            "�������� ������� ��������� ��������.\n", a, b, c);
    }
//================================================================
void Sol_Quad_Equat (double a, double b, double c)
    {
    if (fabs (a) < 1e-7)
        {
        Sol_Line_Equat (b, c);
        }
    else if (fabs (a) > 1e-7)
            {
            if (fabs (b) < 1e-7)
                {
                if (fabs (c) < 1e-7)
                    {
                    printf ("��� ��������� ����� ������������ ������ x = 0");
                    }
                else if (fabs (c) > 1e-7)
                        {
                        double d = 4*a*c;
                            if (d > 0)
                            {
                            printf ("��� ��������� �� ����� �������������� ������.\n"
                                    "��������� ���������� 0.");
                            }
                            else if (d < 0)
                                 {
                                 double x1 = (sqrt(-d))/(2*a);
                                 double x2 = -(sqrt(-d))/(2*a);
                                 printf ("��� ��������� ����� ��� ����� x1 = %lg, x2 = %lg", x1, x2);
                                 }
                        }
                }
            else if (fabs (b) > 1e-7)
                {
                 double d = b*b - 4*a*c;
                 if (d < 0)
                    {
                    printf ("��� ��������� �� ����� �������������� ������.");
                    }
                 else if (fabs (d) < 1e-7)
                        {
                        double x1 = -b/(2*a);
                        printf ("��� ��������� ����� ������������ ������ x = %lg", x1);
                        }
                      else if (d > 0)
                            {
                            double x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
                            double x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
                            printf ("��� ��������� ����� ��� ����� x1 = %lg, x2 = %lg", x1, x2);
                            }
                }
            }
    printf ("\n"
            "�������� ������� ��������� �����������.");
    }
//================================================================
void Sol_Line_Equat (double k, double b)
    {
    if (fabs (b) < 1e-7)
        {
        if (fabs (k) < 1e-7)
            {
            printf ("��� ��������� ����� ����������� ��������� ������.\n"
                    "��������� ���������� 0");
            }
        else if (fabs (k) > 1e-7)
                {
                printf ("��� ��������� ����� ������������ ������ x = 0");
                }
        }
    else if (fabs (b) > 1e-7)
            {
            if (fabs (k) < 1e-7)
                {
                printf ("��� ��������� �� ����� ������.\n"
                        "��������� ���������� 0.");
                }
            else if (fabs (k) > 1e-7)
                    {
                    double x2 = -(b/k);
                    printf ("��� ��������� ����� ������������ ������ x = %lg", x2);
                    }
            }
    printf ("\n"
            "�������� ������� ��������� ��������� ���� ������.");
    }
