#pragma once

#include "raylib.h"

#include <deque>

/**
 * @brief Double pendulum runtime state.
 */
struct Pendulum {
    float gravity;              ///< Gravity.
    Vector2 origin;             ///< Pivot point in screen coordinates.
    float l1, l2;               ///< Length of each string.
    float m1, m2;               ///< Mass of each bob.

    float theta1, theta2;       ///< Angle of each bob relative to the vertical axis (deg).
    float omega1, omega2;       ///< Angular velocity of each bob.

    std::deque<Vector2> trace;  ///< Past positions trace.
};

namespace pendulum {
    /**
     * @brief Update pendulum state.
     * @param pendulum Pendulum to update.
     */
    void update(Pendulum& pendulum);

    /**
     * @brief Draw pendulum components.
     * @param pendulum Pendulum to draw.
     * @param show_trace Whether to show the trace.
     */
    void draw(Pendulum& pendulum, bool show_trace);

    /**
     * @brief Reset pendulum to its default configuration.
     * @param pendulum Pendulum to reset.
     */
    void reset(Pendulum& pendulum);
}
