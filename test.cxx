#include <iostream>

#include "TUnfolder.h"

int main()
{
  TUnfolder unfolder;
  unfolder.ShowInfo();
  unfolder.GenerateTestTree("defaultOutput.root");
  return 0;
}
