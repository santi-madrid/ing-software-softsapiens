#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

class AudioManager : public Node {
    GDCLASS(AudioManager, Node);

private:
    bool muted = false;

protected:
    static void _bind_methods();

public:
    void _ready();

    void toggle_mute();
    bool is_muted() const;
};

}

#endif
