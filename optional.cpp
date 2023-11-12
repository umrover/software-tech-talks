#include <optional>

namespace bad {

int read_delta_encoder_ticks() {
  if ( hardware checks pass ) {
    // read from actual hardware
    int delta_ticks = ...;
    return delta_ticks;
  } else {
    return -1;
  }
}

int running_total = 0;

int main() {
  while (1) {
    int delta_ticks = read_delta_encoder_ticks();
    if (delta_ticks != -1) {
        running_total += delta_ticks;
    }

    // do something with running_total
  }
}

}

namespace good {

std::optional<int> read_delta_encoder_ticks() {
  if ( hardware checks pass ) {
    // read from actual hardware
    int delta_ticks = ...;
    return delta_ticks;
  } else {
    return std::nullopt;
  }
}

int running_total = 0;

int main() {
  while (1) {
    std::optional<int> delta_ticks = read_delta_encoder_ticks();
    if (delta_ticks) {
        running_total += delta_ticks.value();
    }

    // do something with running_total
  }
}

}
