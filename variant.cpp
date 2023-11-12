namespace bad {
    
struct Message {
    struct Throttle {
        Percent percent;
    } throttle;
    struct Position {
        Meters position;
    } position;
    struct Config {
        Percent min_throttle;
        Percent max_throttle;
        ...
    } config;
    ...
};

union Message {
    struct Throttle {
        Percent percent;
    } throttle;
    struct Position {
        Meters position;
    } position;
    struct Config {
        Percent min_throttle;
        Percent max_throttle;
        ...
    } config;
};

struct Message {
    // 0 - throttle
    // 1 - position
    // 2 - config
    std::uint8_t messageId;
    union {
        struct Throttle {
            double percent;
        } throttle;
        struct Position {
            double position;
        } position;
        struct Config {
            double min_throttle;
            double max_throttle;
        } config;
    } data;
};

}

namespace good {

struct Throttle {
    Percent percent;
};
struct Position {
    Meters position;
};
struct Config {
    Percent min_throttle;
    Percent max_throttle;
    ...
};
using Message =
    std::variant<Throttle, Position, Config>;


void process(Throttle const& throttle) {
    // process percent output (open loop)
}

void process(Position const& position) {
    // run PID loop (closed loop control)
}

void process(Config const& config) {
    // process config
}

void process(Message const& message) {
    std::visit([](auto const& m) { process(m); }, message);
}

}