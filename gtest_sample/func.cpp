/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-18 22:27
 * Filename :        func.c
 * Description :     
 * *********************************************************************/

#include "func.h"

int fac(int nInput) {
  if (nInput < 0) {
    return -1;
  }

  int nRev = 1;
  for (int i = 1; i <= nInput; ++i) {
    nRev *= i;
  }

  return nRev;
}
