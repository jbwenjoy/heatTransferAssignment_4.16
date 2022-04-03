// heatTransfer_4.16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    double d_tou = 1e-3;
    double t1 = 93.5;
    double t2, t3, t4, t5;
    t2 = t3 = t4 = t5 = 650;
    double a = 1.16e-5;

    double A = 1.1507e-3;
    double B = 0.9977;
    double C = 1.1507e-3;
    double D = 2 * A;

    double t15_a[7] = { 0, 93.5, 650, 650, 650, 650 };
    double t15_b[7] = { 0, 93.5, 650, 650, 650, 650 };

    while(t15_a[5] - 450 > 0)
    {
        t15_b[2] = A * t15_a[1] + B * t15_a[2] + C * t15_a[3];
        t15_b[3] = A * t15_a[2] + B * t15_a[3] + C * t15_a[4];
        t15_b[4] = A * t15_a[3] + B * t15_a[4] + C * t15_a[5];
        t15_b[5] = D * t15_a[4] + B * t15_a[5];

        t15_b[0] += 1;

        t15_a[0] = t15_b[0];
        t15_a[1] = t15_b[1];
        t15_a[2] = t15_b[2];
        t15_a[3] = t15_b[3];
        t15_a[4] = t15_b[4];
        t15_a[5] = t15_b[5];

        std::cout << "Step.";
        for (int i = 0; i < 6; i++) {
            std::cout << t15_a[i] << '\t';
        }
        std::cout << '\n';
    }

    double time = d_tou * t15_a[0];
    std::cout << "\ntime: " << time << "s\n";
    std::cout << "step: " << t15_a[0] << '\n';
    return 0;
}
