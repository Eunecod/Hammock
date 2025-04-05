#pragma once

#include <base/Entity.h>


struct Component { 
    Entity entity;
    ~Component() = default;
};
