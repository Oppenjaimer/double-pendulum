#include "config.hpp"
#include "pendulum.hpp"
#include "theme.hpp"

#include <cmath>

/**
 * @brief Helper struct to hold pendulum derivatives.
 */
struct Derivatives {
    float dt1, dt2; ///< Derivative of each angle (rad).
    float dw1, dw2; ///< Derivative of each angular velocity (rad/s).
};

/**
 * @brief Get derivatives from system of 1st order ODEs.
 * @param p Pendulum to work with.
 * @param t1 Angle 1 (rad).
 * @param t2 Angle 2 (rad).
 * @param w1 Angular velocity 1 (rad/s).
 * @param w2 Angular velocity 2 (rad/s).
 * @returns Pendulum derivatives.
 */
static Derivatives get_derivatives(Pendulum& p, float t1, float t2, float w1, float w2) {
    float g = p.gravity;
    float delta = t1 - t2;
    float denom = 2.0f * p.m1 + p.m2 - p.m2 * cosf(2.0f * delta);

    float n1 = -g * (2.0f * p.m1 + p.m2) * sinf(t1);
    float n2 = -p.m2 * g * sinf(t1 - 2.0f * t2);
    float n3 = -2.0f * sinf(delta) * p.m2 * (w2 * w2 * p.l2 + w1 * w1 * p.l1 * cosf(delta));
    float dw1 = (n1 + n2 + n3) / (p.l1 * denom);

    float n4 = 2.0f * sinf(delta) * (w1 * w1 * p.l1 * (p.m1 + p.m2) + g * (p.m1 + p.m2) * cosf(t1) + w2 * w2 * p.l2 * p.m2 * cosf(delta));
    float dw2 = n4 / (p.l2 * denom);

    return {w1, w2, dw1, dw2};
}

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
    float t1 = pendulum.theta1 * PI / 180.0f;
    float t2 = pendulum.theta2 * PI / 180.0f;
    float w1 = pendulum.omega1 * PI / 180.0f;
    float w2 = pendulum.omega2 * PI / 180.0f;

    // Get RK4 stages
    Derivatives k1 = get_derivatives(
        pendulum,
        t1,
        t2,
        w1,
        w2
    );
    Derivatives k2 = get_derivatives(
        pendulum,
        t1 + 0.5f * config::dt * k1.dt1,
        t2 + 0.5f * config::dt * k1.dt2,
        w1 + 0.5f * config::dt * k1.dw1,
        w2 + 0.5f * config::dt * k1.dw2
    );
    Derivatives k3 = get_derivatives(
        pendulum,
        t1 + 0.5f * config::dt * k2.dt1,
        t2 + 0.5f * config::dt * k2.dt2,
        w1 + 0.5f * config::dt * k2.dw1,
        w2 + 0.5f * config::dt * k2.dw2
    );
    Derivatives k4 = get_derivatives(
        pendulum,
        t1 + config::dt * k3.dt1,
        t2 + config::dt * k3.dt2,
        w1 + config::dt * k3.dw1,
        w2 + config::dt * k3.dw2
    );

    // Apply RK4 stages
    t1 += (config::dt / 6.0f) * (k1.dt1 + 2.0f * k2.dt1 + 2.0f * k3.dt1 + k4.dt1);
    t2 += (config::dt / 6.0f) * (k1.dt2 + 2.0f * k2.dt2 + 2.0f * k3.dt2 + k4.dt2);
    w1 += (config::dt / 6.0f) * (k1.dw1 + 2.0f * k2.dw1 + 2.0f * k3.dw1 + k4.dw1);
    w2 += (config::dt / 6.0f) * (k1.dw2 + 2.0f * k2.dw2 + 2.0f * k3.dw2 + k4.dw2);

    pendulum.theta1 = t1 * 180.0f / PI;
    pendulum.theta2 = t2 * 180.0f / PI;
    pendulum.omega1 = w1 * 180.0f / PI;
    pendulum.omega2 = w2 * 180.0f / PI;
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
    pendulum.gravity = config::gravity;
    pendulum.origin = {config::screen_width / 2.0f, config::screen_height / 2.0f};
    pendulum.l1 = pendulum.l2 = config::length;
    pendulum.m1 = pendulum.m2 = config::mass;
    pendulum.theta1 = pendulum.theta2 = config::angle;
    pendulum.omega1 = pendulum.omega2 = 0.0f;
}
