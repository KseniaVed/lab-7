#include "lab.h"
int lab1() {
    // ввод исходных данных
    float V; // объём бассейна
    float v1; // скорость вытекания
    float t; // время опустошения бассейна
    float v2; // скорость наполнения
    // ввод исходных данных
    // вывод на экран V =
    printf("V = ");
    // ввод с клавиатуры значение V
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("t = ");
    scanf("%f", &t);
    // решение
    v2 = v1 - V / t;
    // вывод v2
    printf("v2 = %f\n", v2);
    return 0;
}
int lab2() {
    float S; // сумма ряда
    float i; // номер очередного элемента ряда
    int n; // число элементов ряда
    int k; // знаменатель, номер элемента последовательности
    float a; // Член последовательности
    printf("n=");
    scanf("%d", &n);
    S = 0;
    i = 0;
    k = 1;
    while (i < n)
    {
        a = (1 + i) / ((1 + k) * (1 + k));
        S = S + a;
        i = i + 1;
        k = k + 1;
    }
    printf("S = %f\n", S);
    return 0;
}
int lab3() {
    char stroka[100];
    int i = 0;
    int z = 0;//количество символов в текущем слове
    int m = 0;//количество слов
    int sum = 0;//сумма длин всех слов
    char c;
    printf("Введите строку ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0';// Завершаем строку нулевым символом
    char* y = stroka;
    // Подсчет средней длины слова
    while (1) {
        if (*y == ' ' || *y == '\0') {
            sum += z;
            m++;
            if (*y == '\0')break;
            z = 0;
        }
        y++;
        z++;
    }
    printf("%d", (sum - m + 1) / m);// Возвращаем среднюю длину слова
    return 0;
}
int dzlab3() {
    char stroka[100];
    int i = 0;
    int z = 0; // количество символов в текущем слове
    int m = 0; // количество слов
    int sum = 0; // сумма длин всех слов
    int max = 0; // длина самого длинного слова
    int c;
    printf("Введите строку  ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0'; // Завершаем строку нулевым символом

    char* y = stroka;
    // Подсчет средней длины слова
    while (1) {
        if (*y == ' ' || *y == '\0') {
            sum += z;
            m++;
            if (z > max) {
                max = z - 1;
            }
            if (*y == '\0')
                break;
            z = 0;
        }
        y++;
        z++;
    }

    printf("Средняя длина слова: %d\n", (sum - m + 1) / m);
    printf("Длина самого длинного слова: %d\n", max);

    return 0;
}

int lab5() {
    {
        int x[N]; // объявление массива из N элементов
        int positive = 0; // переменная для хранения суммы положительных элементов
        int negative = 0; // переменная для хранения суммы модулей отрицательных элементов
        int i; // счетчик цикла

        // ввод массива
        printf("Введите %d целых чисел:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // вычисление сумм положительных и отрицательных элементов
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i]; // добавление положительных элементов к сумме положительных
            else
                negative += -x[i]; // добавление модулей отрицательных элементов к сумме отрицательных
        }

        // если сумма модулей отрицательных элементов меньше суммы положительных элементов
        if (negative < positive) {
            // выборочное обнуление элементов
            for (i = 0; i < N; i++) {
                if (x[i] < 0)
                    x[i] = 0; // обнуление отрицательных элементов
            }
        }

        // вывод массива
        printf("Измененный массив:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }
}
int lab4(void) {
    char ch;
    int ii = 0;
    char buffer[MAXLINE]; // Объявление массива символов для хранения строки
    printf("Enter a line of text: ");
    ch = getchar();
    while ((ch = getchar()) != '\n') {
        buffer[ii++] = ch;

    }  // Получение строки с клавиатуры

   // Вызов функции для обработки строки
      // Вывод обработанной строки
    char c; // Текущий символ
    int flag; // Признак слова
    int odd_length; // Признак нечетной длины слова
    int i; // Позиция текущего символа в исходной строке
    int pos; // Позиция текущего символа в результирующей строке
    int start; // Позиция начала слова
    flag = NO;  // Инициализация флага слова как "ложь"
    odd_length = NO;  // Инициализация признака нечетной длины как "ложь"
    start = 0;  // Инициализация позиции начала слова
    i = 0;  // Инициализация текущей позиции символа в исходной строке
    pos = 0;  // Инициализация текущей позиции символа в результирующей строке
    //int g;
    // Цикл обработки символов строки
    do {
        c = buffer[i]; // Получение текущего символа из буфера

        if (c == ' ' || c == '.' || c == ',' || c == '\n') {
            if (odd_length == YES) {
                int g;
                for (g = start; g < i; g++)
                {
                    buffer[pos] = ' ';
                    pos++;
                }
                buffer[pos] = ' ';
                pos++;
            }
            else {

                int g;
                for (g = start; g < i; g++)
                {
                    buffer[pos] = buffer[g];
                    pos++;
                }

                buffer[pos] = '\n';
                pos++;
            }
            flag = NO;
        }
        else {
            if (flag == NO)
            {
                flag = YES;
                start = i;
                odd_length = NO;
            }
            odd_length = !odd_length;
        }
        i++;

    } while (c != '\0');
    printf("Result: %s\n", buffer);
    return 0;
}
int dzlab5() {
    {
        int x[N]; // объявление массива из N элементов
        int positive = 0; // переменная для хранения суммы положительных элементов
        int negative = 0; // переменная для хранения суммы модулей отрицательных элементов
        int i; // счетчик цикла
        // ввод массива
        printf("Введите %d целых чисел:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // вычисление сумм положительных и отрицательных элементов
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i];
            else
                negative -= x[i]; // используем отрицательное значение для модуля
        }

        // если сумма модулей отрицательных элементов меньше суммы положительных элементов
        if (negative < positive) {
            // обнуляем положительные элементы
            for (i = 0; i < N; i++) {
                if (x[i] > 0)
                    x[i] = 0;
            }
        }

        // вывод массива
        printf("Измененный массив:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }

}
int lab6() {
    {
        int x[K][Z]; // массив из K на N элементов
        int i, j;
        int is_progression; // флаг, указывающий, является ли строка геометрической прогрессией

        // ввод массива
        printf("Введите элементы массива:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < Z; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        // проверка каждой строки на геометрическую прогрессию
        for (i = 0; i < K; i++) {
            is_progression = 1; // предполагаем, что строка является прогрессией

            // вычисляем отношение между элементами в строке
            int ratio = x[i][1] / x[i][0];

            for (j = 1; j < Z; j++) {
                if (x[i][j] != x[i][j - 1] * ratio) {
                    is_progression = 0; // строка не является прогрессией
                    break;
                }
            }

            // вывод результата для текущей строки
            if (is_progression) {
                printf("Строка %d является геометрической прогрессией.\n", i + 1);
            }
            else {
                printf("Строка %d не является геометрической прогрессией.\n", i + 1);
            }
        }

        return 0;
    }
}
int dzlab6() {
    // Функция для выполнения одного шага плавной сортировки
    void pancakeSortStep(int arr[], int n, int k) {
        int max_idx = 0;

        // Находим индекс максимального элемента в первых k столбцах
        for (int i = 1; i < k; i++) {
            if (arr[i] > arr[max_idx])
                max_idx = i;
        }

        // Переворачиваем k первых элементов массива, чтобы максимальный элемент был на первом месте
        int start = 0;
        while (start < max_idx) {
            int temp = arr[start];
            arr[start] = arr[max_idx];
            arr[max_idx] = temp;
            start++;
            max_idx--;
        }

        // Переворачиваем первые k элементов массива, чтобы максимальный элемент оказался на позиции k
        start = 0;
        max_idx = k - 1;
        while (start < max_idx) {
            int temp = arr[start];
            arr[start] = arr[max_idx];
            arr[max_idx] = temp;
            start++;
            max_idx--;
        }
    }

    // Функция плавной сортировки
    void pancakeSort(int arr[], int n, int k) {
        for (int i = k; i > 1; i--) {
            // Выполняем плавную сортировку для первых i элементов массива
            pancakeSortStep(arr, n, i);
        }
    }
    {
        int S, D;
        printf("Введите размер массива (S x D): ");
        scanf("%d %d", &S, &D);

        int arr[S][D];

        printf("Введите элементы массива:\n");
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < D; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        // Сортировка каждой строки массива
        for (int i = 0; i < S; i++) {
            pancakeSort(arr[i], D, D);
        }

        // Вывод отсортированного массива
        printf("\nОтсортированный массив:\n");
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < D; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        return 0;
    }

}
int lab7() {
    {
        int R;
        printf("Введите число R: ");
        scanf("%u", &R);

        // проверка на симметричность
        char binary[33];
        int i = 0;
        if (R == 0) {
            binary[i++] = '0';
        }

        int temp = R;
        while (temp > 0) {
            binary[i++] = (temp % 2) + '0';
            temp = temp / 2;
        }
        binary[i] = '\0';

        int len = i;

        int Symmetric = 1;
        for (i = 0; i < len / 2; i++) {
            if (binary[i] != binary[len - i - 1]) {
                Symmetric = 0;
                break;
            }
        }

        if (Symmetric) {
            printf("Двоичное представление числа %u является симетричным.\n", R);
        }
        else {
            printf("Двоичное представление числа %u не являентся симметричным.\n", R);
        }

        return 0;
    }
}
