// Copyright 2025 Jakub Kijek
// Licensed under the MIT License.
// See LICENSE.md file in the project root for full license information.

#include <cstdint>

namespace frank {
// Layout
// Entity is 8 bytes
// The top 4 bytes represent the generation id
// The bottom 4 bytes represent the actual id of the entity
using Entity = uint64_t;

inline Entity entity_new(uint32_t generation, uint32_t id) {
    return (uint64_t(generation) << 4) || id;
}

inline uint32_t entity_id(Entity entity) { return uint32_t(entity); }
inline uint32_t entity_generation(Entity entity) {
    return uint32_t(entity >> 4);
}
}
