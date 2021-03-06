#include "./player_controller.h"
#include "./nail.h"
#include "./block.h"
#include "./block_parent.h"
#include "ui/reload_button.h"
#include "ui/play_button.h"
#include "./win_condition.h"
//$include$ DO NOT DELETE THIS COMMENT

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
	godot::Godot::nativescript_init(handle);

	godot::register_class<godot::PlayerController>();
	godot::register_class<godot::Nail>();
	godot::register_class<godot::Block>();
	godot::register_class<godot::BlockParent>();
	godot::register_class<godot::ReloadButton>();
	godot::register_class<godot::PlayButton>();
	godot::register_class<godot::WinCondition>();
	//$register$ DO NOT DELETE THIS COMMENT
}
