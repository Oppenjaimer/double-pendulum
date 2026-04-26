#include "simulation.hpp"
#include "state.hpp"
#include "theme.hpp"

void simulation::update(State& state) {
    if (state.is_paused) return;
}

void simulation::draw(State& state) {
    (void)state;

    // Placeholder circle
    DrawCircle(config::screen_width / 2.0f, config::screen_height / 2.0f, 10, theme::orange);
}
