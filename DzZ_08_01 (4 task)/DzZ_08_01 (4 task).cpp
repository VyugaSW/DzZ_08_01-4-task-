
#include <iostream>
#include <Windows.h>

using namespace std;

int live;
int PCnum;
int score_user = 0, score_PC = 0;
void rand_num_level1() {
    srand(time(NULL));
    PCnum = rand() % 10 + 1;
    cout << PCnum << endl;
}
void rand_num_level2() {
    srand(time(NULL));
    PCnum = rand() % 100 + 10;
    cout << PCnum << endl;
}
void HELP(int a) {
    if (a > PCnum) cout << "\t===Ваше число больше загаданного===\n";
    else cout << "\t===Ваше число меньше загаданного===\n";
}
void level(int a) {
    int user;
    char hel;

    if (a == 1) {
        live = 5;
        rand_num_level1();
    }
    else if (a == 2) {
        live = 22;
        rand_num_level2();
    }

    while (live >= 0) {
        cout << "\t|ВАШИ ЖИЗНИ - " << live << "|" << endl;
        if (live > 0) {
            cout << "---------------\n";
            cout << "ПК загадал число\n" << "Предположите его - "; cin >> user;        //Ох, чаю, что вы разберётесь в этом вареве :))
            if (user == ::PCnum) {
                cout << "ОХ, ВЫ УГАДАЛИ!\n";
                (a == 1) ? score_user += live * 5: score_PC += live * 10;
                break;
            }
            else {
                cout << "Нет :)\n";
                live -= 1;
            }
            cout << endl << "Подсказочку?(Y or N) - "; cin >> hel;
            if (hel == 'Y') {
                HELP(user);
                live -= 1;
            }
        }
        else if (live == 0) {
            cout << "Ох, вы проиграли (:\n";
            (a == 2) ? score_PC += 5 * 5 : score_user += 22 * 10;
            cout << "Число ПК было - " << PCnum << endl;
            live -= 1;
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Модифицировать игру «GUESS MY NUMBER» следующим
    //образом:
    //■■ пользователь не выбирает уровень, т.к.переход ко второму
    //    уровню возможен только после завершения первого без
    //    проигрыша(если игрок желает продолжать);
    //■■ первый уровень длится три раунда(на каждом раунде
    //    загадывается новое число), а второй — два раунда.Новые
    //    жизни начисляются игроку перед новым раундом.
    //■■ если пользователь проиграл раунд, то компьютеру на -
    //    числяются очки за раунд в размере начальные жизни
    //    пользователя, умноженные на 5 для первого уровня и на
    //    10 для второго;
    //■■ количество очков сохраняется и накапливается в раундах
    //    и уровнях;
    //■■ промежуточные итоги выводятся после каждого раунда
    //    и уровня.


    cout << "\t\"GUESS MY NUMBER 2.0 \"\n";
    cout << "Пора начинать!\n";
    cout << "\t|Уровень 1|\n";
    for (int i = 0; i < 3; i++) {
        cout << "-----------\n";
        cout << "\t||РАУНД " << i+1 << "||" << endl;
        level(1);
        cout << "-----------\n";
        cout << "Ваши очки - " << score_user << endl;
        cout << "очки ПК - " << score_PC << endl;
    }
    cout << "Желаете продолжить задорную игру? (Y or N) - "; char g; cin >> g;
    if (g == 'Y') {
        cout << "\t|Уровень 2|\n";
        for (int i = 0; i < 2; i++) {
            cout << "-----------\n";
            cout << "\t||РАУНД " << i + 1 << "||" << endl;
            level(2);
            cout << "-----------\n";
            cout << "Ваши очки - " << score_user << endl;
            cout << "очки ПК - " << score_PC << endl;
        }
    }
    else
        cout << "Пускай вас обласкают гурии, удачи!";


}
