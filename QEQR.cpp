#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#define TEST(a, b, c, X1, X2) \
square_eq(a, b, c, x1, x2); \
if (*x1 == X1 && *x2 == X2) \
printf("���� ������� ��������\n"); \
else printf("���� ��������\n");

//---------------------------------------------------------------------------�
//  Solution to a square eqution a*x^2 + b*x + c = 0
//  version 2.0
//  authors Kolyadich Mark
//  param x1 - the first answer = 0
//  param x2 - the second answer = 0
//  param roots - nubmer of unique answers
//---------------------------------------------------------------------------

int Enter (double *x1, double *x2);

//---------------------------------------------------------------------------
//  iszero
//  version 2.0
//  authors Kolyadich Mark
//  param value
//---------------------------------------------------------------------------

int iszero (double value);

//---------------------------------------------------------------------------
//  Solution to a square eqution a*x^2 + b*x + c = 0
//  version 2.0
//  authors Kolyadich Mark
//  param a, b, c - coffecients
//  param x1 - the first answer = 0
//  param x2 - the second answer = 0
//---------------------------------------------------------------------------�

int square_eq (double a, double b, double c, double *x1, double *x2);

//---------------------------------------------------------------------------
//  Solution to a linear eqution a*x + b = 0
//  version 2.0
//  authors Kolyadich Mark
//  param a, b - coffecients
//  param x1 - the first answer = 0
//  param x2 - the second answer = 0
//---------------------------------------------------------------------------

int line_eq (double a, double b, double *x1, double *x2);

//---------------------------------------------------------------------------
//  Test to the function square_eq
//  version 2.0
//  authors Kolyadich Mark
//  param x1 - the first answer = 0
//  param x2 - the second answer = 0
//---------------------------------------------------------------------------

void Test(double *x1, double *x2);

//---------------------------------------------------------------------------
//  Results of function square_eq
//  version 2.0
//  authors Kolyadich Mark
//  param x1 - the first answer = 0
//  param x2 - the second answer = 0
//---------------------------------------------------------------------------

void res_sq(int ss, double *x1, double *x2);

int main()
    {
    setlocale (LC_ALL, "Russian");

    double x1 = 0, x2 = 0;

    int ss = Enter (&x1, &x2);
    assert (ss >= -1 && ss <= 2);

    res_sq (ss, &x1, &x2);

    Test (&x1, &x2);

    return 0;
    }

int Enter (double *x1, double *x2)
    {
    assert (x1 != NULL);

    assert (x2 != NULL);
    assert (isfinite(*x2));
    assert (isfinite(*x1));
    assert (isfinite(*x2));

    printf ("��������� ��� ������� ���������� ���������.\n"
            "������� ������������ ����������� ��������� (a*x^2 + b*x + c = 0) a, b � c:\n");

    double a = 0, b = 0, c = 0;

    while (scanf ("%lf %lf %lf", &a, &b, &c) != 3)
        {
        printf ("������� ������ �����, � ������ ��� �����\n");
        fflush (stdin);
        }

    int ss = square_eq (a, b, c, x1, x2);

    return ss;
    }

int square_eq (double a, double b, double c, double *x1, double *x2)
    {
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (iszero (a))
    return line_eq (b, c, x1, x2);
    else
        {
        int d = b*b - 4*a*c;
        assert (isfinite (d));

        if ((iszero(d) == 0) && (d < 0))
            {
            *x1 = *x2 = 0;
            return 0;
            }
        else if (iszero (d))
        {
        if (iszero (-b/2/a))
        *x1 = *x2 = fabs (-b/2/a);
        else *x1 = *x2 = -b/2/a;
        return 1;
        }
        else if ((iszero(d) == 0) && (d > 0))
        {
        *x1 = (-b - sqrt(d))/2/a;
        *x2 = (-b + sqrt(d))/2/a;
        return 2;
        }
        }

    }

int line_eq (double a, double b, double *x1, double *x2)
    {
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite(a));
    assert (isfinite(b));

    if (iszero(a))
        {
        if (iszero(b))
            {
            *x1 = *x2 = 0;
            return -1;
            }
        else
            {
            *x1 = *x2 = 0;
            return 0;
            }
        }
    else
        {
        assert (isfinite(-b/a));

        if (iszero(-b/a))
        *x1 = *x2 = fabs(-b/a);
        else *x1 = *x2 = -b/a;

        return 1;
        }
        }

void res_sq (int ss, double *x1, double *x2)
    {
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite(*x1));
    assert (isfinite(*x2));
    assert (ss >= -1 && ss <= 2);
    if (ss == 0)
    printf ("������ � ����� ��������� ���\n"
            "� ���������� x1 � x2 �������� ����\n");
        else if (ss == 1)
        printf ("��� ����� ��������� � ����� %.8lf\n", *x1);
            else if (ss == 2)
            printf ("����� ��������� ����� %.8lf � %.8lf\n", *x1, *x2);
                else if (ss == -1)
                printf ("������ ��������� ���������� �����\n"
                        "� ���������� x1 � x2 �������� ����\n");
        }

    int iszero (double value)
    {
    assert (isfinite (value));

    if (fabs (value) < 1e-7)
    return 1;
    else
    return 0;
    }

void Test(double *x1, double *x2)
    {
    assert (x1 != NULL);
    assert (x2 != NULL);

    TEST (3, 3, 4, 0, 0);
    TEST (0, 10, 0, 0, 0);
    TEST (3, 3, 3, 0, 0);
    TEST (2, 10, 0, -5, 0);
    TEST (4, 100, 35, (-100-sqrt(10000-16*35))/8, (-100+sqrt(10000-16*35))/8);
    TEST (0, 0, 0.5, 0, 0);
    TEST (4, 14, 3, (-14-sqrt(148))/8, (-14+sqrt(148))/8);
    TEST (1, 2, 1, -1, -1);
    TEST (2, 11, 0, -5.5, 0);
    TEST (6, 6, 1.5, -0.5, -0.5);
    }
