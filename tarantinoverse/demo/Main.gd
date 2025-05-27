extends Node

func _on_Sprite2D_position_changed(node, new_pos):
	print("The position of " + node.get_class() + " is now " + str(new_pos))
