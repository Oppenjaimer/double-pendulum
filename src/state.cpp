#include "state.hpp"

void state::reset(State& state) {
    state.is_paused = true;
    state.time_scale = config::time_scale;
    state.time_acc = 0.0f;
    pendulum::reset(state.pendulum);
}
