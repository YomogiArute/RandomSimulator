#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// 1�ڂ̃A���S���Y��: std::rand() ���g�p
int randomAlgorithm1() {
    return std::rand() % 6 + 1;  // 1����6�̃����_���Ȓl�𐶐�
}

// 2�ڂ̃A���S���Y��: std::mt19937 ���g�p
int randomAlgorithm2() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

int main() {
    // �����̃V�[�h�ݒ�
    std::srand(static_cast<unsigned>(std::time(0)));

    int commonCount = 0;        // ���ʂ����񐔂̃J�E���^
    int totalIterations = 0;    // �����s��
    const int targetCommonCount = 19200000;  // �ڕW�̋��ʉ�

    // 1����6�̊e�l�̋��ʉ񐔂�ۑ�����z��i�C���f�b�N�X0�͖��g�p�j
    int commonValuesCount[7] = { 0 };

    // ���ʂ����񐔂�1����ɂȂ�܂Ń��[�v
    while (commonCount < targetCommonCount) {
        int value1 = randomAlgorithm1();
        int value2 = randomAlgorithm2();

        if (value1 == value2) {
            ++commonCount;  // ���ʂ����l���J�E���g
            ++commonValuesCount[value1];  // �e�l�̋��ʉ񐔂��J�E���g
        }

        ++totalIterations;  // ���s�񐔂��J�E���g
    }

    // ���ʂ̏o��
    cout << "1���񋤒ʂ���܂łɂ����������s��: " << totalIterations << endl;
    for (int i = 1; i <= 6; ++i) {
        cout << "�l " << i << " �����ʂ�����: " << commonValuesCount[i] << endl;
    }

    return 0;
}
