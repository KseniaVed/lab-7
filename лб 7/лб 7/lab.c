#include "lab.h"
int lab1() {
    // ���� �������� ������
    float V; // ����� ��������
    float v1; // �������� ���������
    float t; // ����� ����������� ��������
    float v2; // �������� ����������
    // ���� �������� ������
    // ����� �� ����� V =
    printf("V = ");
    // ���� � ���������� �������� V
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("t = ");
    scanf("%f", &t);
    // �������
    v2 = v1 - V / t;
    // ����� v2
    printf("v2 = %f\n", v2);
    return 0;
}
int lab2() {
    float S; // ����� ����
    float i; // ����� ���������� �������� ����
    int n; // ����� ��������� ����
    int k; // �����������, ����� �������� ������������������
    float a; // ���� ������������������
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
    int z = 0;//���������� �������� � ������� �����
    int m = 0;//���������� ����
    int sum = 0;//����� ���� ���� ����
    char c;
    printf("������� ������ ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0';// ��������� ������ ������� ��������
    char* y = stroka;
    // ������� ������� ����� �����
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
    printf("%d", (sum - m + 1) / m);// ���������� ������� ����� �����
    return 0;
}
int dzlab3() {
    char stroka[100];
    int i = 0;
    int z = 0; // ���������� �������� � ������� �����
    int m = 0; // ���������� ����
    int sum = 0; // ����� ���� ���� ����
    int max = 0; // ����� ������ �������� �����
    int c;
    printf("������� ������  ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0'; // ��������� ������ ������� ��������

    char* y = stroka;
    // ������� ������� ����� �����
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

    printf("������� ����� �����: %d\n", (sum - m + 1) / m);
    printf("����� ������ �������� �����: %d\n", max);

    return 0;
}

int lab5() {
    {
        int x[N]; // ���������� ������� �� N ���������
        int positive = 0; // ���������� ��� �������� ����� ������������� ���������
        int negative = 0; // ���������� ��� �������� ����� ������� ������������� ���������
        int i; // ������� �����

        // ���� �������
        printf("������� %d ����� �����:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // ���������� ���� ������������� � ������������� ���������
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i]; // ���������� ������������� ��������� � ����� �������������
            else
                negative += -x[i]; // ���������� ������� ������������� ��������� � ����� �������������
        }

        // ���� ����� ������� ������������� ��������� ������ ����� ������������� ���������
        if (negative < positive) {
            // ���������� ��������� ���������
            for (i = 0; i < N; i++) {
                if (x[i] < 0)
                    x[i] = 0; // ��������� ������������� ���������
            }
        }

        // ����� �������
        printf("���������� ������:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }
}
int lab4(void) {
    char ch;
    int ii = 0;
    char buffer[MAXLINE]; // ���������� ������� �������� ��� �������� ������
    printf("Enter a line of text: ");
    ch = getchar();
    while ((ch = getchar()) != '\n') {
        buffer[ii++] = ch;

    }  // ��������� ������ � ����������

   // ����� ������� ��� ��������� ������
      // ����� ������������ ������
    char c; // ������� ������
    int flag; // ������� �����
    int odd_length; // ������� �������� ����� �����
    int i; // ������� �������� ������� � �������� ������
    int pos; // ������� �������� ������� � �������������� ������
    int start; // ������� ������ �����
    flag = NO;  // ������������� ����� ����� ��� "����"
    odd_length = NO;  // ������������� �������� �������� ����� ��� "����"
    start = 0;  // ������������� ������� ������ �����
    i = 0;  // ������������� ������� ������� ������� � �������� ������
    pos = 0;  // ������������� ������� ������� ������� � �������������� ������
    //int g;
    // ���� ��������� �������� ������
    do {
        c = buffer[i]; // ��������� �������� ������� �� ������

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
        int x[N]; // ���������� ������� �� N ���������
        int positive = 0; // ���������� ��� �������� ����� ������������� ���������
        int negative = 0; // ���������� ��� �������� ����� ������� ������������� ���������
        int i; // ������� �����
        // ���� �������
        printf("������� %d ����� �����:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // ���������� ���� ������������� � ������������� ���������
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i];
            else
                negative -= x[i]; // ���������� ������������� �������� ��� ������
        }

        // ���� ����� ������� ������������� ��������� ������ ����� ������������� ���������
        if (negative < positive) {
            // �������� ������������� ��������
            for (i = 0; i < N; i++) {
                if (x[i] > 0)
                    x[i] = 0;
            }
        }

        // ����� �������
        printf("���������� ������:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }

}
int lab6() {
    {
        int x[K][Z]; // ������ �� K �� N ���������
        int i, j;
        int is_progression; // ����, �����������, �������� �� ������ �������������� �����������

        // ���� �������
        printf("������� �������� �������:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < Z; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        // �������� ������ ������ �� �������������� ����������
        for (i = 0; i < K; i++) {
            is_progression = 1; // ������������, ��� ������ �������� �����������

            // ��������� ��������� ����� ���������� � ������
            int ratio = x[i][1] / x[i][0];

            for (j = 1; j < Z; j++) {
                if (x[i][j] != x[i][j - 1] * ratio) {
                    is_progression = 0; // ������ �� �������� �����������
                    break;
                }
            }

            // ����� ���������� ��� ������� ������
            if (is_progression) {
                printf("������ %d �������� �������������� �����������.\n", i + 1);
            }
            else {
                printf("������ %d �� �������� �������������� �����������.\n", i + 1);
            }
        }

        return 0;
    }
}
int dzlab6() {
    // ������� ��� ���������� ������ ���� ������� ����������
    void pancakeSortStep(int arr[], int n, int k) {
        int max_idx = 0;

        // ������� ������ ������������� �������� � ������ k ��������
        for (int i = 1; i < k; i++) {
            if (arr[i] > arr[max_idx])
                max_idx = i;
        }

        // �������������� k ������ ��������� �������, ����� ������������ ������� ��� �� ������ �����
        int start = 0;
        while (start < max_idx) {
            int temp = arr[start];
            arr[start] = arr[max_idx];
            arr[max_idx] = temp;
            start++;
            max_idx--;
        }

        // �������������� ������ k ��������� �������, ����� ������������ ������� �������� �� ������� k
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

    // ������� ������� ����������
    void pancakeSort(int arr[], int n, int k) {
        for (int i = k; i > 1; i--) {
            // ��������� ������� ���������� ��� ������ i ��������� �������
            pancakeSortStep(arr, n, i);
        }
    }
    {
        int S, D;
        printf("������� ������ ������� (S x D): ");
        scanf("%d %d", &S, &D);

        int arr[S][D];

        printf("������� �������� �������:\n");
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < D; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        // ���������� ������ ������ �������
        for (int i = 0; i < S; i++) {
            pancakeSort(arr[i], D, D);
        }

        // ����� ���������������� �������
        printf("\n��������������� ������:\n");
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
        printf("������� ����� R: ");
        scanf("%u", &R);

        // �������� �� ��������������
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
            printf("�������� ������������� ����� %u �������� �����������.\n", R);
        }
        else {
            printf("�������� ������������� ����� %u �� ��������� ������������.\n", R);
        }

        return 0;
    }
}
