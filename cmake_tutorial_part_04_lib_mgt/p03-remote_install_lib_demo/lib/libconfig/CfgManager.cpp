#include <iostream>
#include <cstdio>
#include "CfgManager.h"

CfgManager::CfgManager(const char* file) : config_file(file) {
    cfg_opt_t opts[] = {
        CFG_STR("target", "World", CFGF_NONE), // 设置默认值
        CFG_INT("cfg_num", -1, CFGF_NONE),
        CFG_END()
    };
    cfg = cfg_init(opts, CFGF_NONE);
    if (cfg_parse(cfg, config_file) == CFG_PARSE_ERROR) {
        std::cerr << "parse file failed!" << std::endl;
        exit(1); // 使用exit来确保程序终止
    }
}

CfgManager::~CfgManager() {
    cfg_free(cfg);
}

std::string CfgManager::getTarget() {
    return cfg_getstr(cfg, "target");
}

int CfgManager::getConfigNum() {
    return cfg_getint(cfg, "cfg_num");
}
