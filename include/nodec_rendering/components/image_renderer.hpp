#ifndef NODEC_RENDERING__COMPONENTS__IMAGE_RENDERER_HPP_
#define NODEC_RENDERING__COMPONENTS__IMAGE_RENDERER_HPP_

#include <memory>

#include <nodec/vector4.hpp>

#include "../resources/material.hpp"

namespace nodec_rendering {
namespace components {

struct ImageRenderer {
    std::shared_ptr<resources::Texture> image;
    std::shared_ptr<resources::Material> material;

    int pixels_per_unit{100};

    nodec::Vector4f color{1.0f, 1.0f, 1.0f, 1.0f};
};

} // namespace components
} // namespace nodec_rendering
#endif