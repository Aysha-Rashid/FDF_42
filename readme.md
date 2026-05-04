# FDF

Hello! 👋

## About The Project

**FDF** (Fil De Fer — French for *"wireframe"*) is a 3D wireframe renderer built in **C** as part of the 42 Abu Dhabi curriculum.
It reads a map file containing a grid of height values and renders it as a 3D mesh in a window using the **MiniLibX** graphics library.

## How It Works

### Map Parsing
The program reads a `.fdf` file where each number represents the **altitude (Z value)** of a point on a grid.
These values are stored as a matrix of 3D coordinates `(x, y, z)`.

### Isometric Projection
To display the 3D grid on a 2D screen, an **isometric projection** is applied to each point,
transforming the `(x, y, z)` coordinates using these formulas:

```c
  iso_x = (x - y) * cos(0.523599);  // cos(30°)
  iso_y = (x + y) * sin(0.523599) - z;  // sin(30°)

  implemented in code like this:

  angle = 0.523599;
  dots->matrix.x = (dots->matrix.x - dots->matrix.y) * cos(angle);
  dots->matrix.y = (dots->matrix.x + dots->matrix.y)
  * sin(angle) - dots->matrix.z;
```

This gives the classic "tilted cube" look without perspective distortion.

### Bresenham's Line Algorithm
Once the projected points are calculated, **Bresenham's Line Algorithm** is used to draw
straight lines between adjacent coordinates — both horizontally and vertically across the grid.

It works entirely with **integer arithmetic**, making it fast and efficient:

```c
  Check out draw.c file:

  delta.matrix.x = next.matrix.x - current.matrix.x;
	delta.matrix.y = next.matrix.y - current.matrix.y;
	max = ft_max(ft_abs(delta.matrix.x), ft_abs(delta.matrix.y));
	delta.matrix.y /= max;
	delta.matrix.x /= max;
	while ((int)(current.matrix.x - next.matrix.x)
		|| (int)(current.matrix.y - next.matrix.y))
	{
		put_pixel(current.matrix.x, current.matrix.y, color, data);
		current.matrix.x += delta.matrix.x;
		current.matrix.y += delta.matrix.y;
		if (current.matrix.x > W_WIDTH || current.matrix.y > W_LENGTH
			|| current.matrix.y < 0 || current.matrix.x < 0)
			break ;
	}
```

### Rotation
The map can be rotated along the **X, Y, and Z axes** using standard rotation matrices applied to each coordinate before projection:

```c
// Rotate around X axis
new_y = y * cos(angle) - z * sin(angle);
new_z = y * sin(angle) + z * cos(angle);

// Rotate around Z axis
new_x = x * cos(angle) - y * sin(angle);
new_y = x * sin(angle) + y * cos(angle);
```


### Prerequisites
Make sure you have the MiniLibX folder and you are using MAC OS.
In case you don't have MAC OS then you should using Minilibx that is compatible with linux.

### Steps

In your terminal, run the following commands:

```bash
git clone https://github.com/Aysha-Rashid/FDF_42/
make
./fdf test_map/42.fdf
```

![FDF Preview](/FDF.gif)
