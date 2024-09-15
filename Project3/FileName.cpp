#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// 1つ目のアルゴリズム: std::rand() を使用
int randomAlgorithm1() {
    return std::rand() % 6 + 1;  // 1から6のランダムな値を生成
}

// 2つ目のアルゴリズム: std::mt19937 を使用
int randomAlgorithm2() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

int main() {
    // 乱数のシード設定
    std::srand(static_cast<unsigned>(std::time(0)));

    int commonCount = 0;        // 共通した回数のカウンタ
    int totalIterations = 0;    // 総試行回数
    const int targetCommonCount = 19200000;  // 目標の共通回数

    // 1から6の各値の共通回数を保存する配列（インデックス0は未使用）
    int commonValuesCount[7] = { 0 };

    // 共通した回数が1万回になるまでループ
    while (commonCount < targetCommonCount) {
        int value1 = randomAlgorithm1();
        int value2 = randomAlgorithm2();

        if (value1 == value2) {
            ++commonCount;  // 共通した値をカウント
            ++commonValuesCount[value1];  // 各値の共通回数をカウント
        }

        ++totalIterations;  // 試行回数をカウント
    }

    // 結果の出力
    cout << "1万回共通するまでにかかった試行回数: " << totalIterations << endl;
    for (int i = 1; i <= 6; ++i) {
        cout << "値 " << i << " が共通した回数: " << commonValuesCount[i] << endl;
    }

    return 0;
}
