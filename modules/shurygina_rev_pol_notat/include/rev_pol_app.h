// Copyright 2022 Kozel Svetlana

#ifndef  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_REV_POL_APP_H_
#define  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_REV_POL_APP_H_

#include <string>

class Application {
 public:
     std::string operator()(int argc, const char* argv[]);
 private:
     static inline std::string help(const char* appname);
};

#endif  //  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_REV_POL_APP_H_
