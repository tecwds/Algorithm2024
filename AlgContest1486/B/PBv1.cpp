#include <iostream>
using namespace std;

// A 4
// B 3
// C 2
// D 1
// F 0

char input;

int num;
double sum;

int main()
{

    while (scanf("%c", &input) != EOF)
    {
        switch (input)
        {
        case 'A':
            sum += 4.0;
            break;
        case 'B':
            sum += 3.0;
            break;
        case 'C':
            sum += 2.0;
            break;
        case 'D':
            sum += 1.0;
            break;
        case 'F':
            sum += 0.0;
            break;
        case '\n':
            // printf("%1.2d", sum / num);
            cout << sum / (double)num << endl;
            sum = 0.0;
            num = 0;
            continue;
        case ' ':
            continue;
        default:
            cout << "Unknown" << endl;
            // cout << flush;
            sum = 0.0;
            num = 0;
            continue;
        }

        num++;
    }
}