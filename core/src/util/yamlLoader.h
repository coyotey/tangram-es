#pragma once

#include "yaml-cpp/node/node.h"

namespace Tangram {

struct YamlLoader {
    YAML::Node load(const char* bytes, size_t length);
};

}
