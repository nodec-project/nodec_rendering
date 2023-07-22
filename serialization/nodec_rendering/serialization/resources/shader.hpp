#ifndef NODEC_RENDERING__SERIALIZATION__RESOURCES__SHADER_HPP_
#define NODEC_RENDERING__SERIALIZATION__RESOURCES__SHADER_HPP_

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>

#include <nodec/serialization/vector4.hpp>
#include <nodec/vector4.hpp>

#include <string>
#include <vector>

namespace nodec_rendering {
namespace resources {

template<class Archive>
void serialize(Archive &archive, ShaderMetaInfo::FloatProperty &property) {
    archive(
        cereal::make_nvp("name", property.name),
        cereal::make_nvp("default_value", property.default_value));
}

template<class Archive>
void serialize(Archive &archive, ShaderMetaInfo::Vector4Property &property) {
    archive(
        cereal::make_nvp("name", property.name),
        cereal::make_nvp("default_value", property.default_value));
}

template<class Archive>
void serialize(Archive &archive, ShaderMetaInfo::TextureEntry &entry) {
    archive(
        cereal::make_nvp("name", entry.name));
}

template<class Archive>
void serialize(Archive &archive, ShaderMetaInfo &info) {
    archive(
        cereal::make_nvp("float_properties", info.float_properties),
        cereal::make_nvp("vector4_properties", info.vector4_properties),
        cereal::make_nvp("texture_entries", info.texture_entries),
        cereal::make_nvp("pass", info.pass),
        cereal::make_nvp("rendering_priority", info.rendering_priority));
}

template<class Archive>
void serialize(Archive &archive, SubShaderMetaInfo &info) {
    archive(
        cereal::make_nvp("render_targets", info.render_targets),
        cereal::make_nvp("texture_resources", info.texture_resources));
};

} // namespace resources
} // namespace nodec_rendering

#endif
