#include <iostream>
#include <vector>
#include "mylib.hpp"
using namespace std;



vector < pPF > vectCommand2;
vector < PF * >vectCommand3;
vector < fPF > vectCommand4;
vector < ffP * >vectCommand5;
int RunMenuMU (int argc, char *argv[], vector < string > &vectMenu,
               vector < PFp > &vectCommand)
{
    int iChoiceMenu = 'r';
    const int ciMaxChoiceMenu = vectMenu.size () - 1;

    while (iChoiceMenu) {
        int iNumberMenu = 0;

        if (iChoiceMenu == 'r')
            for (const auto i:vectMenu) {
                star ();
                if (iNumberMenu == 0) {
                    cout << "***";
                } else {
                    cout << "No." << iNumberMenu << ' ';
                }
                cout << i << endl;
                ++iNumberMenu;
            }
        cin.clear ();
        cout << "Please input a number (99==renew menu)--->:";
        cin >> iChoiceMenu;
        if (iChoiceMenu == 99) {
            iChoiceMenu = 'r';
            continue;
        }
        if ((iChoiceMenu <= ciMaxChoiceMenu) && (iChoiceMenu > 0))
            (*vectCommand[iChoiceMenu]) (argc, argv);
    }
    return 0;
};

int RunListMenu (const int nMenuItemsT, const char *pCMenuListT[])
{
    int iMenuCountS = 0;

    while (nMenuItemsT >= 0) {
        cout << ++iMenuCountS << ".\t";
        cout << pCMenuListT[iMenuCountS] << endl;
    }
    return 0;
}

int MenuCM (int argc, char *argv[])
{
    cout << __func__ << endl;
    return 0;
};
