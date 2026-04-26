#include "state.hpp"

void state::reset(State& state) {
    pendulum::reset(state.pendulum);
}
