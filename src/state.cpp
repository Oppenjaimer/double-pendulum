#include "state.hpp"

void state::reset(State& state) {
    state.time_scale = config::time_scale;
    state.time_acc = 0.0f;
    pendulum::reset(state.pendulum);
}
