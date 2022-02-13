#pragma once

const int x=5;
const int y=5;
const int z=5;
int PrintNameAndValueL (const char *pname, const bool bi);
int PrintTBL (const char *cmessage[], int n, const char *ptitle);
int Run_BoolTestFN (int argc,char * argv[]);
int InitalArrayL(int array[x][y][z], int i);
int RunTestArraySizeofFN(int argc1);
int ToGotoL(int argc1);
int RunArrAddFN(int argc1);
int RunMyTestFN(int argc, char *argv[]);


const int h = 9;
const int v = 9;
int RunPrint_MonthFN (int argc1);
int Print_CharL (char c, int inum);
int Init_MartixL (int i[h][v], int argc1);
int RunMartxL (int argc1);

int RunPickInitalFN (int icp, int ic, int il);

bool PickUpBigL (int i[h][v], int ipicknum);
