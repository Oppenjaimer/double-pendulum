#include "config.hpp"
#include "pendulum.hpp"
#include "theme.hpp"

#include <cmath>

/**
 * @brief Convert polar into Cartesian coordinates relative to some origin.
 * @param origin Cartesian plane origin in screen coordinates.
 * @param r Polar radius.
 * @param theta Polar angle (deg).
 * @returns Relative position in Cartesian coordinates.
 */
static Vector2 cartesian(Vector2 origin, float r, float theta) {
    float r_scaled = r * config::scale;
    float theta_rad = theta * PI / 180.0f;

    return {
        origin.x + r_scaled * sinf(theta_rad),
        origin.y + r_scaled * cosf(theta_rad),
    };
}

void pendulum::update(Pendulum& pendulum) {
    (void)pendulum;
}

void pendulum::draw(Pendulum& pendulum) {
    DrawCircleV(pendulum.origin, config::pivot_radius, theme::fg0);

    Vector2 pos1 = cartesian(pendulum.origin, pendulum.l1, pendulum.theta1);
    Vector2 pos2 = cartesian(pos1, pendulum.l2, pendulum.theta2);

    DrawLineV(pendulum.origin, pos1, theme::fg0);
    DrawLineV(pos1, pos2, theme::fg0);
    DrawCircleV(pos1, config::bob_radius, theme::red);
    DrawCircleV(pos2, config::bob_radius, theme::red);
}

void pendulum::reset(Pendulum& pendulum) {
    pendulum.origin = {config::screen_width / 2.0f, config::screen_height / 2.0f};
    pendulum.l1 = pendulum.l2 = config::length;
    pendulum.m1 = pendulum.m2 = config::mass;
    pendulum.theta1 = pendulum.theta2 = config::angle;
}
