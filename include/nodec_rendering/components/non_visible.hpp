#ifndef NODEC_RENDERING__COMPONENTS__NON_VISIBLE_HPP_
#define NODEC_RENDERING__COMPONENTS__NON_VISIBLE_HPP_

namespace nodec_rendering {
namespace components {

struct NonVisible {
    bool self{false};
};


struct RenderDistance {
    float min_distance{0.0f}; // これより近いと描画しない
    float max_distance{1000.0f}; // これより遠いと描画しない
};

} // namespace components
} // namespace nodec_rendering

#endif