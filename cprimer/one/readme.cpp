#include <iostream>
#include <string>
using namespace std;

int RunReadmeRE (int argc, char *argv[])
{
    string strStarStartLine="************************************"
                            "**************************\n";
    string strStarNEnd=string(60,'*');
    strStarNEnd+='\n';
    string strReadme="Compare random number's arrary 0.10\n"
                     "Copyleft (C) 2022 Free Software gitglassshark@Nothing, INC:bbc@sina.com.\n"
                     "This is free software;see the source for copying conditions.\nThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
     Usage:\n\t cparray   [row]  [colmun]  [compare number]\n\
         \n\t [row]\t\t\t The arrary row.\n\t [colmun]\t\t The arrary line.\n\t [compare number]\t The compare number.\n"
                     ;
    /*    cout << "Compare random number's arrary 0.10\n"
             "Copyleft (C) 2022 Free Software gitglassshark@Nothing, INC:bbc@sina.com.\n"
             "This is free software;see the source for copying conditions.\nThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
         Usage:\n\t cparray  [colmun]  [cow]  [compare number]\n\
             \n\t -[colmun]\t\t The arrary line.\n\t -[cow]\t\t\t The arrary cow.\n\t -[compare number]\t The compare number.\n";*/
    cout<<strStarStartLine;
    cout<<strReadme;
    cout<<strStarNEnd;
    cout<<"\t[row]\n""\t\t if set 0 entry test module.\n";
    return 0;
}
