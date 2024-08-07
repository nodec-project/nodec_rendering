#ifndef NODEC_RENDERING__SERIALIZATION__COMPONENTS__IMAGE_RENDERER_HPP_
#define NODEC_RENDERING__SERIALIZATION__COMPONENTS__IMAGE_RENDERER_HPP_

#include <nodec/serialization/vector4.hpp>
#include <nodec_rendering/components/image_renderer.hpp>
#include <nodec_rendering/resources/material.hpp>
#include <nodec_rendering/resources/texture.hpp>
#include <nodec_scene_serialization/archive_context.hpp>
#include <nodec_scene_serialization/serializable_component.hpp>

namespace nodec_rendering {
namespace components {

class SerializableImageRenderer : public nodec_scene_serialization::BaseSerializableComponent {
public:
    SerializableImageRenderer()
        : BaseSerializableComponent(this) {}

    SerializableImageRenderer(const ImageRenderer &other)
        : BaseSerializableComponent(this),
          image(other.image),
          material(other.material),
          pixels_per_unit(other.pixels_per_unit),
          color(other.color) {}

    operator ImageRenderer() const noexcept {
        ImageRenderer value;
        value.image = image;
        value.material = material;
        value.pixels_per_unit = pixels_per_unit;
        value.color = color;
        return value;
    }

    std::shared_ptr<resources::Texture> image;
    std::shared_ptr<resources::Material> material;

    int pixels_per_unit{100};

    nodec::Vector4f color{1.0f, 1.0f, 1.0f, 1.0f};

    template<class Archive>
    void save(Archive &archive) const {
        using namespace nodec_scene_serialization;
        ArchiveContext &context = cereal::get_user_data<ArchiveContext>(archive);

        archive(cereal::make_nvp("image", context.resource_registry().lookup_name<resources::Texture>(image).first));
        archive(cereal::make_nvp("material", context.resource_registry().lookup_name<resources::Material>(material).first));
        archive(cereal::make_nvp("pixels_per_unit", pixels_per_unit));
        archive(cereal::make_nvp("color", color));
    }

    template<class Archive>
    void load(Archive &archive) {
        using namespace nodec_scene_serialization;
        using namespace nodec::resource_management;

        auto &context = cereal::get_user_data<ArchiveContext>(archive);

        {
            std::string name;
            archive(cereal::make_nvp("image", name));
            image = context.resource_registry().get_resource_direct<resources::Texture>(name);
        }
        {
            std::string name;
            archive(cereal::make_nvp("material", name));
            material = context.resource_registry().get_resource_direct<resources::Material>(name);
        }
        archive(cereal::make_nvp("pixels_per_unit", pixels_per_unit));
        archive(cereal::make_nvp("color", color));
    }
};

template<class Archive>
void serialize(Archive &archive, ImageRenderer &image_renderer) {
    archive(cereal::make_nvp("pixels_per_unit", image_renderer.pixels_per_unit));
    archive(cereal::make_nvp("color", image_renderer.color));
}

} // namespace components
} // namespace nodec_rendering

NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableImageRenderer)

#endif