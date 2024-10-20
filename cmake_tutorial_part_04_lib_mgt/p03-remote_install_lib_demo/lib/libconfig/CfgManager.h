#ifndef CfgManager_HPP
#define CfgManager_HPP

#include <string>
#include "confuse.h"

class CfgManager {
private:
    cfg_t *cfg;
    const char* config_file;

public:
    CfgManager(const char* file);
    ~CfgManager();
    std::string getTarget();
    int getConfigNum();
};

#endif // CfgManager_HPP