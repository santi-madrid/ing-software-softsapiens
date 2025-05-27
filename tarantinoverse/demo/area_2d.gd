extends Area2D

@export var speed: float = 400.0

func _physics_process(delta):
	position.x += speed * delta
	if position.x > 700: # Limite fuera de pantalla
		queue_free()
