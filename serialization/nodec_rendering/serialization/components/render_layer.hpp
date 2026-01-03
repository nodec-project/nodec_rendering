#ifndef NODEC_RENDERING__SERIALIZATION__COMPONENTS__RENDER_LAYER_HPP_
#define NODEC_RENDERING__SERIALIZATION__COMPONENTS__RENDER_LAYER_HPP_

#include <nodec_rendering/components/render_layer.hpp>
#include <nodec_scene_serialization/serializable_component.hpp>

namespace nodec_rendering {
namespace components {

/**
 * @brief Serializable version of RenderLayer<N>.
 *
 * Since RenderLayer is a tag component with no data, serialization
 * is trivial. The type information itself carries the layer index.
 */
template<std::uint32_t N>
struct SerializableRenderLayer : public nodec_scene_serialization::BaseSerializableComponent {
    static_assert(N < 32, "Layer index must be 0-31");

    SerializableRenderLayer()
        : BaseSerializableComponent(this) {}

    SerializableRenderLayer(const RenderLayer<N> &)
        : BaseSerializableComponent(this) {}

    operator RenderLayer<N>() const noexcept {
        return {};
    }

    template<class Archive>
    void serialize(Archive &) {
        // No data to serialize - type itself carries the layer index
    }
};

} // namespace components
} // namespace nodec_rendering

// Register all 32 layers with cereal polymorphic serialization
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<0>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<1>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<2>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<3>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<4>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<5>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<6>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<7>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<8>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<9>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<10>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<11>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<12>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<13>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<14>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<15>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<16>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<17>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<18>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<19>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<20>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<21>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<22>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<23>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<24>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<25>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<26>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<27>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<28>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<29>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<30>)
NODEC_SCENE_REGISTER_SERIALIZABLE_COMPONENT(nodec_rendering::components::SerializableRenderLayer<31>)

#endif
