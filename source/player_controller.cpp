#include "player_controller.h"
#include "Input.hpp"
#include <ResourceLoader.hpp>
#include <Input.hpp>
#include <Viewport.hpp>
#include <Area2D.hpp>
#include <SceneTree.hpp>
#include "block_parent.h"

namespace godot
{
	void PlayerController::_register_methods()
	{
		godot::register_method("_ready", &PlayerController::_ready);
		godot::register_method("_process", &PlayerController::_process);

		godot::register_property<PlayerController, int>("Nails", &PlayerController::remainingNails, 10);
	}

	PlayerController::PlayerController()
	{
	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::_init()
	{
		Ref<Resource> resource = ResourceLoader::get_singleton()->load("res://scenes/actors/nail.tscn");
		nail = resource;
	}

	void PlayerController::_ready()
	{
		Node* playButton = get_node("PlayButton");
		BlockParent* blockParent = static_cast<BlockParent*>(get_node("BlockParent"));
		playButton->connect("play_physics", blockParent, "EnableGravity");
	}

	void PlayerController::_process(float delta)
	{
		Vector2 mousePosition = this->get_local_mouse_position();

		const auto& input = Input::get_singleton();

		if(!this->placingStarted && input->is_action_just_released("start_level"))
		{
			this->placingStarted = true;
			this->Explode();
		}

		if(this->placingStarted && input->is_action_just_released("place_nail") && this->remainingNails > 0)
		{
			this->remainingNails -= 1;
			godot::Godot::print("Nails reminding: {0}", this->remainingNails);
			Node* instance = nail->instance();
			Node2D* node = static_cast<Node2D*>(instance);
			node->set_z_index(++PlayerController::zOrder);
			node->set_position(mousePosition);
			add_child(node);
		}
	}

	void PlayerController::Explode()
	{
		godot::Godot::print("Explosion!");
		auto children = this->get_children();

//		for (auto x : children)
//		{
//			godot::Godot::print("child: {0}", 10);

//		}

		for (int i =0 ; i < children.size(); i++)
		{

		}
	}
}
