// Copyright 2022 Labinskaya Marina

#ifndef MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_APP_H_
#define MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_APP_H_

#include <string>

class polygonAreaApp {
 public:
    polygonAreaApp();
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const std::string& appname);
    std::string argument_error();
};

#endif  // MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_APP_H_
