#include "gtest/gtest.h"
#include "header.h"

// Тестирование функции total()
TEST(TotalFunctionTest, SingleNumberTest) {
    // Тестирование отдельных чисел
    EXPECT_EQ(total(0, 0), 0);    // 0 в двоичной: 0 → 0 единиц
    EXPECT_EQ(total(1, 1), 1);    // 1 в двоичной: 1 → 1 единица
    EXPECT_EQ(total(2, 2), 1);    // 2 в двоичной: 10 → 1 единица
    EXPECT_EQ(total(3, 3), 2);    // 3 в двоичной: 11 → 2 единицы
    EXPECT_EQ(total(4, 4), 1);    // 4 в двоичной: 100 → 1 единица
    EXPECT_EQ(total(5, 5), 2);    // 5 в двоичной: 101 → 2 единицы
    EXPECT_EQ(total(6, 6), 2);    // 6 в двоичной: 110 → 2 единицы
    EXPECT_EQ(total(7, 7), 3);    // 7 в двоичной: 111 → 3 единицы
}

TEST(TotalFunctionTest, RangeTest) {
    // Тестирование диапазонов чисел
    EXPECT_EQ(total(0, 1), 1);    // 0(0) + 1(1) = 0 + 1 = 1
    EXPECT_EQ(total(1, 2), 2);    // 1(1) + 2(10) = 1 + 1 = 2
    EXPECT_EQ(total(1, 3), 4);    // 1(1) + 2(10) + 3(11) = 1 + 1 + 2 = 4
    EXPECT_EQ(total(1, 4), 5);    // 1+2+3+4 = 1+1+2+1 = 5
    EXPECT_EQ(total(1, 5), 7);    // 1+1+2+1+2 = 7
}

TEST(TotalFunctionTest, SameStartEndTest) {
    // Граничные случаи - одинаковые начало и конец
    EXPECT_EQ(total(10, 10), 2);  // 10 в двоичной: 1010 → 2 единицы
    EXPECT_EQ(total(15, 15), 4);  // 15 в двоичной: 1111 → 4 единицы
    EXPECT_EQ(total(16, 16), 1);  // 16 в двоичной: 10000 → 1 единица
}

TEST(TotalFunctionTest, PowerOfTwoTest) {
    // Тестирование степеней двойки (всегда 1 единица)
    EXPECT_EQ(total(1, 1), 1);    // 2^0
    EXPECT_EQ(total(2, 2), 1);    // 2^1
    EXPECT_EQ(total(4, 4), 1);    // 2^2
    EXPECT_EQ(total(8, 8), 1);    // 2^3
    EXPECT_EQ(total(16, 16), 1);  // 2^4
    EXPECT_EQ(total(32, 32), 1);  // 2^5
    EXPECT_EQ(total(64, 64), 1);  // 2^6
}

TEST(TotalFunctionTest, LargeRangeTest) {
    // Тестирование большего диапазона
    EXPECT_EQ(total(0, 7), 12);   // 0-7: 0+1+1+2+1+2+2+3 = 12
    EXPECT_EQ(total(8, 15), 20);  // 8-15: 1+2+2+3+2+3+3+4 = 20
    EXPECT_EQ(total(0, 15), 32);  // 0-15: 12 + 20 = 32
}

TEST(TotalFunctionTest, ReverseRangeTest) {
    // Тестирование, что функция работает корректно при a > b
    // (если ваша функция должна обрабатывать такой случай)
    EXPECT_EQ(total(3, 1), 0);    // Пустой диапазон
}

TEST(TotalFunctionTest, NegativeNumbersTest) {
    // Тестирование отрицательных чисел (если поддерживается)
    // Если не поддерживается - тест может упасть, что ожидаемо
    // EXPECT_EQ(total(-1, -1), 1); // -1 в доп. коде: все единицы
}

TEST(TotalFunctionTest, EdgeCasesTest) {
    // Особые граничные случаи
    EXPECT_EQ(total(0, 0), 0);    // Ноль
    EXPECT_EQ(total(255, 255), 8); // 255: 11111111 → 8 единиц
}

// Дополнительные тесты для проверки конкретных паттернов
TEST(TotalFunctionTest, PatternTest) {
    // Проверка известных паттернов
    EXPECT_EQ(total(1, 8), 13);   // 1+1+2+1+2+2+3+1 = 13
    EXPECT_EQ(total(9, 16), 20);  // 2+2+3+2+3+3+4+1 = 20
}