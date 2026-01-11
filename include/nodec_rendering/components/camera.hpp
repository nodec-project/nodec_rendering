#ifndef NODEC_RENDERING__COMPONENTS__CAMERA_HPP_
#define NODEC_RENDERING__COMPONENTS__CAMERA_HPP_

#include <nodec/flags.hpp>
#include <nodec/matrix4x4.hpp>

#include <cstdint>
#include <string>

namespace nodec_rendering {
namespace components {

struct Camera {
    enum class Projection {
        //! Camera will render objects with perspective intact.
        Perspective,

        //! Camera will render objects uniformly, with no sense of perspective.
        Orthographic
    };

    //! Render type for camera stacking (Unity URP style).
    enum class RenderType : std::uint8_t {
        //! Base camera clears color buffer and renders first.
        Base,

        //! Overlay camera renders on top without clearing color buffer.
        Overlay
    };

    float far_clip_plane{100.0f};
    float near_clip_plane{0.01f};

    Projection projection{Projection::Perspective};

    float fov_angle{45.0f};
    float ortho_width{10.0f};

    nodec::Matrix4x4f world2camera_matrix;
    nodec::Matrix4x4f projection_matrix;

    // --- Camera Stack fields ---

    //! Determines if this camera is a base or overlay camera.
    RenderType render_type{RenderType::Base};

    //! Rendering priority within the camera group. Lower values render first.
    std::int32_t priority{0};

    //! Bitmask for layer-based culling. Entities with matching RenderLayer are rendered.
    std::uint32_t culling_mask{0xFFFFFFFF};

    //! Whether to clear depth buffer before rendering (useful for overlay cameras).
    bool clear_depth{true};

    //! Camera group name. Cameras in the same group are stacked together.
    std::string camera_group{"default"};
};

enum class CameraDirtyFlag {
    None = 0x00,
    Projection = 0x01,
    _nodec_flags_enable
};

struct CameraDirty {
    nodec::Flags<CameraDirtyFlag> flags;
};

} // namespace components
} // namespace nodec_rendering

#endif