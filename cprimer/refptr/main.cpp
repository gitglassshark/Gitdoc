#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "h.hpp"
#include "test.hpp"
#include "menu.hpp"
#include "mylib.hpp"

using namespace std;

int main (int argc, char *argv[]);
void end ();

class runmain
{
public:
    PFp m_main;
    runmain (int i = 0)
    {
        atexit (::end);
        if (i == 100)
            {
                cout << "m_main run main stat......" << endl;
                m_main =::main;
                main (0);
                cout << " m_main run mian is end" << endl;
            }
        else
            {
                exit (0);
            }
    }
    int main (int a = 0)
    {
        if (a == 0)
            {
                (*m_main) (100, nullptr);
                return -1;
            }
        else
            {
                cout << " m_main run mAin is OK" << endl;
                return 0;
            }
    }
    int end ()
    {
        cout << "in runmain end" << endl;
        return 0;
    }
};

runmain run (100);

void end ()
{
    cout << "in aexit end" << endl;
    run.main (1);
    run.end ();
}

int main (int argc, char *argv[])
{
    cout << "@ main" << __func__ << '\t' << __LINE__ << endl;
    cout << "argc is " << argc << endl;
    srand (time (NULL));
    RunMyTestFN (argc, argv);

    return 0;
}
