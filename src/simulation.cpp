#include "pendulum.hpp"
#include "simulation.hpp"

void simulation::update(State& state) {
    if (state.is_paused) return;
}

void simulation::draw(State& state) {
    pendulum::draw(state.pendulum);
}
