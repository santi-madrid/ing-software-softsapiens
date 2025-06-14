#include "register_types.h"
#include "View/CharacterView.h"
#include "View/BulletView.h"
#include "View/EnemyView.h"
<<<<<<< HEAD
#include "View/MainMenuView.h"
#include "View/BaseMenuView.h"
#include "View/PauseMenuView.h"
#include "View/OptionsMenuView.h"
#include "View/CreditsMenuView.h"
=======
#include "View/ObjectView.h"
>>>>>>> feature/recollection
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_RUNTIME_CLASS(CharacterView);
	GDREGISTER_RUNTIME_CLASS(BulletView);
	GDREGISTER_RUNTIME_CLASS(EnemyView);
<<<<<<< HEAD
	GDREGISTER_RUNTIME_CLASS(BaseMenuView);
	GDREGISTER_RUNTIME_CLASS(MainMenuView);
	GDREGISTER_RUNTIME_CLASS(PauseMenuView);
	GDREGISTER_RUNTIME_CLASS(OptionsMenuView);
	GDREGISTER_RUNTIME_CLASS(CreditsMenuView);
=======
	GDREGISTER_CLASS(ObjectView);
>>>>>>> feature/recollection
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
