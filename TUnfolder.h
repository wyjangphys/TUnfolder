#ifndef _TUNFOLDER_H_
#define _TUNFOLDER_H_

#define UNFOUT std::cout << "[TUnfolder::STDOUT] "
#define UNFERR std::cerr << "[TUnfolder::STDERR] "

class TUnfolder
{
  public:
    TUnfolder();
    ~TUnfolder();
    void ShowInfo();
};
#endif
