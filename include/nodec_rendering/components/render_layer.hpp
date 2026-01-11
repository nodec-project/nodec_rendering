#ifndef NODEC_RENDERING__COMPONENTS__RENDER_LAYER_HPP_
#define NODEC_RENDERING__COMPONENTS__RENDER_LAYER_HPP_

#include <cstdint>

namespace nodec_rendering {
namespace components {

/**
 * @brief Tag component for layer-based rendering.
 *
 * Entities with RenderLayer<N> are only rendered by cameras whose
 * culling_mask includes bit N. This enables separation of UI from
 * scene objects, multiple render passes, etc.
 *
 * @tparam N Layer index (0-31).
 *
 * Usage:
 *   - Entities without any RenderLayer are treated as Layer 0.
 *   - Camera with culling_mask=0xFFFFFFFF renders all layers (default).
 *   - Camera with culling_mask=0x00000001 renders only Layer 0.
 *   - Camera with culling_mask=0x00000002 renders only Layer 1.
 */
template<std::uint32_t N>
struct RenderLayer {
    static_assert(N < 32, "Layer index must be 0-31");

    static constexpr std::uint32_t index = N;
    static constexpr std::uint32_t mask = 1u << N;
};

} // namespace components
} // namespace nodec_rendering

#endif
