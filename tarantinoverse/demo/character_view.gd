extends CharacterView

func _on_animated_sprite_2d_frame_changed():
	if $AnimatedSprite2D.animation == "walk":
		if $AnimatedSprite2D.frame % 2 == 0: 
			$StepSound.play()
