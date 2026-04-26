#include "pendulum.hpp"
#include "simulation.hpp"

void simulation::update(State& state) {
    if (state.is_paused) return;

    float scaled_time = GetFrameTime() * state.time_scale;
    if (scaled_time > config::scaled_time_threshold) scaled_time = config::scaled_time_threshold;

    state.time_acc += scaled_time;
    while (state.time_acc >= config::dt) {
        pendulum::update(state.pendulum);
        state.time_acc -= config::dt;
    }
}

void simulation::draw(State& state) {
    pendulum::draw(state.pendulum);
}
