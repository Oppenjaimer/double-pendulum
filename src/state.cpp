#include "state.hpp"

void state::reset(State& state) {
    state.gravity = config::gravity;
    pendulum::reset(state.pendulum);
}
