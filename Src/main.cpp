#define CATCH_CONFIG_RUNNER

#include "Tools/GLogInit.h"

#include <catch2/catch_all.hpp>

int main(int argc, char* argv[])
{
    GLogInit log(argv[0]);
    int result = Catch::Session().run(argc, argv);
    return result;
}
