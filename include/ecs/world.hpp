// Copyright 2025 Jakub Kijek
// Licensed under the MIT License.
// See LICENSE.md file in the project root for full license information.

#include "container/dynamic_array.hpp"
#include "entity.hpp"

namespace frank {
class World {
private:
    DynamicArray<Entity> entities;
};
}
