#pragma once

/**
 * @brief Global configuration constants.
 */
namespace config {
    // Application
    constexpr int fps = 60;                             ///< Target frames per second.
    constexpr const char* title = "Double Pendulum";    ///< Application window title.

    // Screen
    constexpr int screen_width = 1280;                  ///< Initial screen width (px).
    constexpr int screen_height = 720;                  ///< Initial screen height (px).
    constexpr float scale = 100.0f;                     ///< Scaling factor for drawing.

    // Settings panel
    constexpr int settings_collapse = false;            ///< Default state of the settings panel.
    constexpr int settings_pos_x = 10;                  ///< Default X position of the settings panel.
    constexpr int settings_pos_y = 10;                  ///< Default Y position of the settings panel.
    constexpr float gravity_min = 0.0f;                 ///< Minimum gravity.
    constexpr float gravity_max = 20.0f;                ///< Maximum gravity.
    constexpr float length_min = 1.0f;                  ///< Minimum string length.
    constexpr float length_max = 10.0f;                 ///< Maximum string length.
    constexpr float mass_min = 0.1f;                    ///< Minimum bob mass.
    constexpr float mass_max = 20.0f;                   ///< Maximum bob mass.
    constexpr float angle_min = 0.0f;                   ///< Minimum bob angle (deg).
    constexpr float angle_max = 360.0f;                 ///< Maximum bob angle (deg).
    constexpr float time_scale_min = 0.1f;              ///< Minimum time scale.
    constexpr float time_scale_max = 5.0f;              ///< Maximum time scale.

    // Camera
    constexpr float pan_sensitivity_mouse = 1.0f;       ///< Drag sensitivity for mouse panning.
    constexpr float pan_sensitivity_keyboard = 10.0f;   ///< Key press sensitivity for keyboard panning.
    constexpr float zoom_sensitivity_mouse = 0.15f;     ///< Wheel sensitivity for mouse zooming.
    constexpr float zoom_sensitivity_keyboard = 0.08f;  ///< Key press sensitivity for keyboard zooming.
    constexpr float zoom_min = 0.1f;                    ///< Minimum camera zoom level.
    constexpr float zoom_max = 10.0f;                   ///< Maximum camera zoom level.

    // Simulation
    constexpr float pivot_radius = 2.0f;                ///< Pivot point radius.
    constexpr float bob_radius = 12.0f;                 ///< Bob radius.
    constexpr float gravity = 9.8f;                     ///< Initial gravity.
    constexpr float length = 1.0f;                      ///< Initial string length.
    constexpr float mass = 1.0f;                        ///< Initial bob mass.
    constexpr float angle = 0.0f;                       ///< Initial bob angle (deg).
    constexpr float time_scale = 1.0f;                  ///< Initial time scale.
    constexpr float dt = 0.005f;                        ///< Time step.
    constexpr float scaled_time_threshold = 0.1f;       ///< Scaled time cap.
}
