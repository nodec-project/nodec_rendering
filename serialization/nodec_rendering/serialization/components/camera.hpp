#ifndef NODEC_RENDERING__SERIALIZATION__COMPONENTS__CAMERA_HPP_
#define NODEC_RENDERING__SERIALIZATION__COMPONENTS__CAMERA_HPP_

#include <nodec_rendering/components/camera.hpp>
#include <nodec_scene_serialization/serializable_component.hpp>

namespace nodec_rendering {
namespace components {

class SerializableCamera : public nodec_scene_serialization::BaseSerializableComponent {
public:
    SerializableCamera()
        : BaseSerializableComponent(this) {
    }

    SerializableCamera(const Camera &other)
        : BaseSerializableComponent(this),
          far_clip_plane(other.far_clip_plane),
          near_clip_plane(other.near_clip_plane),
          projection(other.projection),
          fov_angle(other.fov_angle),
          ortho_width(other.ortho_width),
          render_type(other.render_type),
          priority(other.priority),
          culling_mask(other.culling_mask),
          clear_depth(other.clear_depth),
          camera_group(other.camera_group) {}

    operator Camera() const noexcept {
        Camera value;
        value.far_clip_plane = far_clip_plane;
        value.near_clip_plane = near_clip_plane;
        value.projection = projection;
        value.fov_angle = fov_angle;
        value.ortho_width = ortho_width;
        value.render_type = render_type;
        value.priority = priority;
        value.culling_mask = culling_mask;
        value.clear_depth = clear_depth;
        value.camera_group = camera_group;
        return value;
    }

    float far_clip_plane{100.0f};
    float near_clip_plane{0.01f};

    float fov_angle{45.0f};
    float ortho_width{10.0f};

    Camera::Projection projection{Camera::Projection::Perspective};

    // Camera Stack fields
    Camera::RenderType render_type{Camera::RenderType::Base};
    std::int32_t priority{0};
    std::uint32_t culling_mask{0xFFFFFFFF};
    bool clear_depth{true};
    std::string camera_group{"default"};

    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::make_nvp("far_clip_plane", far_clip_plane));
        archive(cereal::make_nvp("near_clip_plane", near_clip_plane));
        archive(cereal::make_nvp("projection", projection));
        archive(cereal::make_nvp("fov_angle", fov_angle));
        archive(cereal::make_nvp("ortho_width", ortho_width));
        archive(cereal::make_nvp("render_type", render_type));
        archive(cereal::make_nvp("priority", priority));
        archive(cereal::make_nvp("culling_mask", culling_mask));
        archive(cereal::make_nvp("clear_depth", clear_depth));
        archive(cereal::make_nvp("camera_group", camera_group));
    }
};

template<class Archive>
void serialize(Archive &archive, Camera &camera) {
    archive(cereal::make_nvp("far_clip_plane", camera.far_clip_plane));
    archive(cereal::make_nvp("near_clip_plane", camera.near_clip_plane));
    archive(cereal::make_nvp("projection", camera.projection));
    archive(cereal::make_nvp("fov_angle", camera.fov_angle));
    archive(cereal::make_nvp("ortho_width", camera.ortho_width));
    archive(cereal::make_nvp("render_type", camera.render_type));
    archive(cereal::make_nvp("priority", camera.priority));
    archive(cereal::make_nvp("culling_mask", camera.culling_mask));
    archive(cereal::make_nvp("clear_depth", camera.clear_depth));
    archive(cereal::make_nvp("camera_group", camera.camera_group));
}

} // namespace components
} // namespace nodec_rendering

NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableCamera)

#endif