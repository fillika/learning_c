#include <stdio.h>

#define DIGITAL_ENCODING_TYPE 0b001
#define DIG_LIT_ENCODING_TYPE 0b010
#define BYTE_ENCODING_TYPE 0b100

enum QR_VERSIONS {
    FIRST = 21,
    SECOND = 25,
    THIRD = 29,
    FOURTH = 33,
    FIFTH = 37,
    SIXTH = 41,
    SEVENTH = 45,
    EIGHTH = 49,
    NINTH = 53,
    TENTH = 57,
    ELEVENTH = 61,
    TWELFTH = 65,
    THIRTEENTH = 69,
    FOURTEENTH = 73,
    FIFTEENTH = 77,
    SIXTEENTH = 81,
    SEVENTEENTH = 85,
    EIGHTEENTH = 89,
    NINETEENTH = 93,
    TWENTIETH = 97,
    TWENTY_FIRST = 101,
    TWENTY_SECOND = 105,
    TWENTY_THIRD = 109,
    TWENTY_FOURTH = 113,
    TWENTY_FIFTH = 117,
    TWENTY_SIXTH = 121,
    TWENTY_SEVENTH = 125,
    TWENTY_EIGHTH = 129,
    TWENTY_NINTH = 133,
    THIRTIETH = 137,
    THIRTY_FIRST = 141,
    THIRTY_SECOND = 145,
    THIRTY_THIRD = 149,
    THIRTY_FOURTH = 153,
    THIRTY_FIFTH = 157,
    THIRTY_SIXTH = 161,
    THIRTY_SEVENTH = 165,
    THIRTY_EIGHTH = 169,
    THIRTY_NINTH = 173,
    FORTIETH = 177
};

enum CorrectionLevel {
    LOW, // 7%
    MEDIUM, // 15%
    HIGH, // 25%
    VERY_HIGH // 30%
};

char test_data[] = "ALEK OS";

/*
#1 Перевести данные в двоичный вид
#2 Указать тип кодирования, с помощью которого Я переводил эти данные.
#3 В зависимости от версии указать длину данных между типом и данными

DIGITAL_ENCODING_TYPE

0010 - 000000111 - 10010...10

*/

int main()
{

    

    printf("QR_CODE_GENERATOR %d\n", DIG_LIT_ENCODING_TYPE);
    printf("LOW %d\n", LOW);
    printf("MEDIUM %d\n", MEDIUM);
    printf("HIGH %d\n", HIGH);
    printf("VERY_HIGHT %d\n", VERY_HIGH);
    return 0;
}