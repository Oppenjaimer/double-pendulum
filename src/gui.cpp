#include "imgui.h"
#include "raylib.h"

#include "gui.hpp"

void gui::render(State& state) {
    // Settings panel collapse
    if (state.settings_trigger) {
        ImGui::SetNextWindowCollapsed(state.settings_collapse);
        state.settings_trigger = false;
    }

    // Settings panel initialization
    ImGui::Begin("Simulation Settings [S]", NULL, ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::SetWindowPos(ImVec2(config::settings_pos_x, config::settings_pos_y), ImGuiCond_FirstUseEver);
    ImGui::SetWindowCollapsed(state.settings_collapse, ImGuiCond_FirstUseEver);
    state.settings_collapse = ImGui::IsWindowCollapsed();

    // FPS counter
    ImGui::Text("FPS: %d", GetFPS());

    // Control buttons
    ImGui::SeparatorText("Controls");

    // Quit button
    if (ImGui::Button("Quit [Q]"))
        state.is_running = false;

    // Reset button
    ImGui::SameLine();
    if (ImGui::Button("Reset [R]"))
        state::reset(state);

    // Play/Pause button
    ImGui::SameLine();
    if (ImGui::Button(state.is_paused ? "Play [SPACE]" : "Pause [SPACE]"))
        state.is_paused = !state.is_paused;

    // Simulation parameters
    ImGui::SeparatorText("Simulation");

    ImGui::SliderFloat("Time scale", &state.time_scale, config::time_scale_min, config::time_scale_max);
    ImGui::SliderFloat("Gravity", &state.pendulum.gravity, config::gravity_min, config::gravity_max);
    ImGui::SliderFloat("Length 1", &state.pendulum.l1, config::length_min, config::length_max);
    ImGui::SliderFloat("Length 2", &state.pendulum.l2, config::length_min, config::length_max);
    ImGui::SliderFloat("Mass 1", &state.pendulum.m1, config::mass_min, config::mass_max);
    ImGui::SliderFloat("Mass 2", &state.pendulum.m2, config::mass_min, config::mass_max);
    ImGui::SliderFloat("Angle 1", &state.pendulum.theta1, config::angle_min, config::angle_max);
    ImGui::SliderFloat("Angle 2", &state.pendulum.theta2, config::angle_min, config::angle_max);

    ImGui::Checkbox("Show trace", &state.show_trace);

    ImGui::End();
}
