#pragma once

#include "raylib.h"

/**
 * @brief Double pendulum runtime state.
 */
struct Pendulum {
    Vector2 origin;         ///< Pivot point in screen coordinates.
    float l1, l2;           ///< Length of each string.
    float m1, m2;           ///< Mass of each bob.
    float theta1, theta2;   ///< Angle of each bob relative to the vertical axis (deg).
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
     */
    void draw(Pendulum& pendulum);

    /**
     * @brief Reset pendulum to its default configuration.
     * @param pendulum Pendulum to reset.
     */
    void reset(Pendulum& pendulum);
}
