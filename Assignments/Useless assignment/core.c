#include <stdio.h>

// -----------------------------------------
// Tester Function Prototypes
// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// -----------------------------------------
// Tester Function Definitions
int inputInt() {
    int number;
    char newline;
    scanf("%d%c", &number, &newline);
    if(newline != '\n') {
        clearInputBuffer();
        printf("Error! Input a whoe number: ");
        number = inputInt();
    }
    else 
        return number;
}

void test01_inputInt(void)
{
    int intValue = 0;

    printf("TEST #1 - Instructions:\n"
           "1) Enter the word 'error'  [ENTER]\n"
           "2) Enter the number '-100' [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputInt function:
    intValue = inputInt();

    printf("////////////////////////////////////////\n");
    printf("TEST #1 RESULT: ");
    if (intValue == -100)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

int inputIntPositive() {
    int number;
    scanf("%d", &number);
    if(number < 0) {
        clearInputBuffer();
        printf("ERROR! Value must be > 0: ");
        number = inputIntPositive();
    }
    else 
        return number;
}
void test02_inputIntPositive(void)
{
    int intValue = -1;

    printf("TEST #2 - Instructions:\n"
           "1) Enter the number '-100' [ENTER]\n"
           "2) Enter the number '200'  [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputIntPositive function:
    intValue = inputIntPositive();

    printf("////////////////////////////////////////\n");
    printf("TEST #2 RESULT: ");
    if (intValue == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

int inputIntRange(int lower_bound, int upper_bound) {
    int number;
    int newline;
    scanf("%d%c", &number, &newline);
    if(newline != '\n') {
        clearInputBuffer();
        printf("Error! Input a whole number: ");
        number = inputIntRange(lower_bound, upper_bound);
    }  else {
        if(number < lower_bound || number > upper_bound) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
            number = inputIntRange(lower_bound, upper_bound);
        } else
            return number;
    }
}

void test03_inputIntRange(void)
{
    int intValue = 999;

    printf("TEST #3 - Instructions:\n"
           "1) Enter the word 'error' [ENTER]\n"
           "2) Enter the number '-4'  [ENTER]\n"
           "3) Enter the number '12'  [ENTER]\n"
           "4) Enter the number '-3'  [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputIntRange function:
    intValue = inputIntRange(-3, 11);

    printf("////////////////////////////////////////\n");
    printf("TEST #3 RESULT: ");
    if (intValue == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test04_inputIntRange(void)
{
    int intValue = 999;

    printf("TEST #4 - Instructions:\n"
           "1) Enter the number '14' [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputIntRange function:
    intValue = inputIntRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (intValue == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

int validateChar(const char *temp, const char input) {
    for(int i = 0; temp[i] != '\0'; i++) 
        if(input == temp[i]) return 1;
    return 0;
}

char inputCharOption(const char *temp) {
    char input = 'x';
    scanf("%c", &input);
    if (!validateChar(temp, input)) { 
        printf("ERROR: Character must be one of [qwErty]: ");
        clearInputBuffer();
        input = inputCharOption(temp);
    } else {
        clearInputBuffer();
        return input;
    }  
}

void test05_inputCharOption(void)
{
    char charValue = 'x';

    printf("TEST #5 - Instructions:\n"
           "1) Enter the character 'R' [ENTER]\n"
           "2) Enter the character 'e' [ENTER]\n"
           "3) Enter the character 'p' [ENTER]\n"
           "4) Enter the character 'r' [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputCharOption function:
    charValue = inputCharOption("qwErty");
    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void get_name(char *name) {
    scanf("%[^\n]%*c", name);
}

int countCString(const char *temp) {
    int count = 0;
    while(temp[count] != '\0')
        count++;
    return count;
}

void inputCString (char *temp, int minimum, int maximum) {
    get_name(temp);
    if(countCString(temp) < minimum || countCString(temp) > maximum) {
        printf("ERROR: String length must be exactly 6 chars: ");
        inputCString(temp, minimum, maximum);
    } 
}

void test06_inputCString(void)
{
    char cstringValue[7] = {'\0'};

    // Test explicit string length
    printf("TEST #6: - Instructions:\n"
           "1) Enter the word 'horse'   [ENTER]\n" // too short
           "2) Enter the word 'chicken' [ENTER]\n" // too long
           "3) Enter the word 'SENECA'  [ENTER]\n" // just right
           ":>");

    // You may want to comment the next line if you have not yet created the inputCString function:
    inputCString(cstringValue, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    printf("%s (expected result: SENECA)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test07_inputCString(void)
{
    char cstringValue[7] = {'\0'};

    // Test range of string length (shortest allowed)
    printf("TEST #7: - Instructions:\n"
           "1) Enter the words 'Seneca College' [ENTER]\n"
           "2) Enter the word 'CATS'            [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputCString function:
    inputCString(cstringValue, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    printf("%s (expected result: CATS)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test08_inputCString(void)
{
    char cstringValue[7] = {'\0'};

    // Test range of string length (longest allowed)
    printf("TEST #8: - Instructions:\n"
           "1) Enter the word 'dogs'  [ENTER]\n"
           "2) Enter the word 'HORSES' [ENTER]\n"
           ":>");

    // You may want to comment the next line if you have not yet created the inputCString function:
    inputCString(cstringValue, 5, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (expected result: HORSES)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

int validatePhone(const char *phone) {
    for(int i = 0; phone[i] != '\0'; i++) {
        int j = 0; 
        while (j < 10) 
            if(phone[i] != j) return 0;
    }
    return 1;
}


void displayFormattedPhone(const char *phone) {
    if(phone == NULL || countCString(phone) != 10 || !validatePhone(phone)) {
        printf("(___)___-____");
    }
}

void test09_displayPhone(void)
{
    char *phone1 = NULL;
    char phone2[10 + 1] = "";
    char phone3[10 + 1] = "1";
    char phone4[10 * 2] = "111333444499999999";
    char phone5[10 + 1] = "111222444z";
    char phone6[10 + 1] = "z112224444";
    char phone7[10 + 1] = "4161114444";

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT:\n");
    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone1);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone2);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone3);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone4);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone5);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone6);
    putchar('\n');

    printf("Expecting (416)111-4444 => Your result: ");
    // You may want to comment the next line if you have not yet created the displayFormattedPhone function:
    displayFormattedPhone(phone7);
    printf("\n"
           "////////////////////////////////////////\n\n");
}

// -----------------------------------------
// Main: Entry-point to the application
int main(void)
{
    printf("Assignment 1 Milestone 1: Tester\n");
    printf("================================\n\n");

    // -----------------------------------------
    // Unit Tests:

    // Integer testers
    test01_inputInt();
    test02_inputIntPositive();
    test03_inputIntRange();
    test04_inputIntRange();

    // Char tester
    test05_inputCharOption();

    // C string testers
    test06_inputCString();
    test07_inputCString();
    test08_inputCString();

    // phone
    test09_displayPhone();

    printf("Assignment #1 Milestone #1 testing completed!\n");

    return 0;
}
