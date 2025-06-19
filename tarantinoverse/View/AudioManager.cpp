#include "AudioManager.h"
#include <godot_cpp/classes/audio_server.hpp>
#include <godot_cpp/classes/engine.hpp>


using namespace godot;

void AudioManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("toggle_mute"), &AudioManager::toggle_mute);
    ClassDB::bind_method(D_METHOD("is_muted"), &AudioManager::is_muted);
}

void AudioManager::_ready() {
    UtilityFunctions::print("AudioManager está listo.");

    // Opcional: aplicar estado inicial de mute
    int master_index = AudioServer::get_singleton()->get_bus_index("Master");
    AudioServer::get_singleton()->set_bus_mute(master_index, muted);
}

void AudioManager::toggle_mute() {
    muted = !muted;
    int master_index = AudioServer::get_singleton()->get_bus_index("Master");
    AudioServer::get_singleton()->set_bus_mute(master_index, muted);
    UtilityFunctions::print("Mute toggled: ", muted);
}

bool AudioManager::is_muted() const {
    return muted;
}
