#include <iostream>
/*
Задание 19

1. Дан целочисленный массив размера N. Удалить из массива все соседние одинаковые элементы, оставив их первые вхождения.
2. Дан целочисленный массив размера N. Удалить из массива все элементы, встречающиеся ровно два раза, и вывести размер полученного массива и его содержимое.
3. Дан массив размера N. Вставить элемент с нулевым значением перед минимальным и после максимального элемента массива.
4. Дан массив размера N. После каждого отрицательного элемента массива вставить элемент с нулевым значением.
5. Дан массив размера N. Перед каждым положительным элементом массива вставить элемент с нулевым значением.

Каждая задача решена в отдельном классе
*/

class z1
{
private:
    int n;
    int* a;
    int* end;

public:

    z1(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        end = a + n - 1;
        a[3] = 3;
        a[4] = 3;
    }

    z1(int size, int* m) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
        end = a + n - 1;
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = i + 1; j < n; j++) {
                if (s == 0) {
                    if (a[i] == a[j]) {
                        s = 1;
                        for (int h = j + 1; h < n; h++) {
                            if (a[i] == a[h]) {
                                s++;
                            }
                            else {
                                j = j + s - 1;
                                break;
                            }
                        }
                    }
                }
                else {
                    a[j - s] = a[j];
                }
            }
            n = n - s;
        }

        /* for (int* i = end; i > a + n - 1; i--) {
             delete i;
         }
         */
    }
};


class z2
{
private:
    int n;
    int* a;
    int* end;

public:

    z2(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        end = a + n - 1;
    }

    z2(int size, int* m) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
        end = a + n - 1;
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) {
                    int s = 1;
                    for (int h = j + 1; h < n; h++) {
                        if (a[i] == a[h]) {
                            s++;
                        }
                        else {
                            a[h - s] = a[h];
                        }
                    }
                    n = n - s;
                    break;
                }
            }
       }


        /* for (int* i = end; i > a + n - 1; i--) {
             delete i;
         }
         */
    }
};


class z3
{
private:
    int n;
    int* a;

public:

    z3(int size = 10) {
        n = size;
        a = new int[n + 2];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }

    z3(int size, int* m) {
        n = size;
        a = new int[n + 2];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {

        int* max = NULL;
        int* min = NULL;
        for (int i = 0; i < n; i++) {
            if (max == NULL) {
                max = a + i;
            }
            if (min == NULL) {
                min = a + i;
            }
            if (*max < a[i]) {
                max = a + i;
            }
            if (*min > a[i]) {
                min = a + i;
            }
        }
        

        int k = 2;
        n = n + k;
        for (int i = n - k - 1; i > -1; i--) {
            if (k == 0) {
                break;
            }

            if (a + i == min || a + i == max) {
                k--;
                if (a + i == min) {
                    a[i + k + 1] = *min;
                    a[i + k] = 0;
                }
                else {
                    a[i + k] = *max;
                    a[i + k + 1] = 0;
                }
            }
            else {
                a[i + k] = a[i];
            }
        }
    }
};


class z4
{
private:
    int n;
    int* a;
    int* end;

public:

    z4(int size = 10) {
        n = size;
        a = new int[2 * n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        end = a + 2 * n - 1;
    }

    z4(int size, int* m) {
        n = size;
        a = new int[2 * n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
        end = a + 2 * n - 1;
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                k++;
            }
        }

        n = n + k;

        for (int i = n - k - 1; i > -1; i--) {
            if (k == 0) {
                break;
            }
            
            if (a[i] < 0) {
                a[i + k] = 0;
                k--;
            }
            a[i + k] = a[i];
        }


        /* for (int* i = end; i > a + n - 1; i--) {
             delete i;
         }
         */
    }
};


class z5
{
private:
    int n;
    int* a;
    int* end;

public:

    z5(int size = 10) {
        n = size;
        a = new int[2 * n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        end = a + 2 * n - 1;
    }

    z5(int size, int* m) {
        n = size;
        a = new int[2 * n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
        end = a + 2 * n - 1;
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                k++;
            }
        }

        n = n + k;

        for (int i = n - k - 1; i > -1; i--) {
            if (k == 0) {
                break;
            }
            a[i + k] = a[i];
            if (a[i] > 0) {
                a[i + k - 1] = 0;
                k--;
            }
        }
        

       /* for (int* i = end; i > a + n - 1; i--) {
            delete i;
        }
        */
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    z1 first;
    first.print_arr();
    first.foo();
    first.print_arr();


    std::cout << "Hello World!\n";
}