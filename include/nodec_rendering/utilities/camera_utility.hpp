#ifndef NODEC_RENDERING__UTILITIES__CAMERA_UTILITY_HPP_
#define NODEC_RENDERING__UTILITIES__CAMERA_UTILITY_HPP_

#include <utility>

#include <nodec/math/math.hpp>
#include <nodec/matrix4x4.hpp>
#include <nodec/vector2.hpp>
#include <nodec/vector3.hpp>

#include "../components/camera.hpp"

namespace nodec_rendering {
namespace utilities {

class CameraUtility {
public:
    /**
     * @brief Generates a ray from screen coordinates to world space.
     *
     * @param screen_pos Screen coordinates in pixels (top-left origin).
     * @param screen_size Screen size in pixels.
     * @param camera Camera component with projection_matrix and world2camera_matrix.
     * @param camera_world_position World position of the camera.
     * @return std::pair<nodec::Vector3f, nodec::Vector3f> {ray_origin, ray_direction}
     */
    static std::pair<nodec::Vector3f, nodec::Vector3f> screen_to_world_ray(
        const nodec::Vector2f &screen_pos,
        const nodec::Vector2f &screen_size,
        const components::Camera &camera,
        const nodec::Vector3f &camera_world_position) {
        // Convert screen coordinates to NDC (-1 to 1)
        float ndc_x = (2.0f * screen_pos.x / screen_size.x) - 1.0f;
        float ndc_y = 1.0f - (2.0f * screen_pos.y / screen_size.y); // Flip Y

        // Ray direction in NDC space (pointing into the screen)
        nodec::Vector3f ray_ndc_near(ndc_x, ndc_y, -1.0f);
        nodec::Vector3f ray_ndc_far(ndc_x, ndc_y, 1.0f);

        // Inverse projection matrix
        auto inv_proj = nodec::math::inv(camera.projection_matrix);

        // Inverse view matrix (world2camera -> camera2world)
        auto inv_view = nodec::math::inv(camera.world2camera_matrix);

        // Transform from NDC to view space
        auto ray_view_near = transform_point(inv_proj, ray_ndc_near);
        auto ray_view_far = transform_point(inv_proj, ray_ndc_far);

        // Transform from view space to world space
        auto ray_world_near = transform_point(inv_view, ray_view_near);
        auto ray_world_far = transform_point(inv_view, ray_view_far);

        // Calculate ray direction
        nodec::Vector3f direction = ray_world_far - ray_world_near;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        if (length > 0.0f) {
            direction = direction / length;
        }

        return {camera_world_position, direction};
    }

private:
    /**
     * @brief Transform a 3D point by a 4x4 matrix with perspective division.
     *
     * Treats the input as a homogeneous point (x, y, z, 1) and performs
     * perspective division by the resulting w component.
     */
    static nodec::Vector3f transform_point(const nodec::Matrix4x4f &m, const nodec::Vector3f &v) {
        float w = m.m41 * v.x + m.m42 * v.y + m.m43 * v.z + m.m44;
        if (w == 0.0f) w = 1.0f;
        return {
            (m.m11 * v.x + m.m12 * v.y + m.m13 * v.z + m.m14) / w,
            (m.m21 * v.x + m.m22 * v.y + m.m23 * v.z + m.m24) / w,
            (m.m31 * v.x + m.m32 * v.y + m.m33 * v.z + m.m34) / w};
    }
};

} // namespace utilities
} // namespace nodec_rendering

#endif
