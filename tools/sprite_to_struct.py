"""
This program takes in an image file and converts it to a preloaded struct to be used in XGA.

The goal is to take the pixel data and convert it into an importable header like so:

```c
// Sprite is named after file with no extension, same as header
#define PLUMBER_WIDTH 2
#define PLUMBER_HEIGHT 3

static XGA_color plumber_row0[PLUMBER_WIDTH] = {
    {255, 0, 0},
    {0, 255, 0}
};
static XGA_color plumber_row1[PLUMBER_WIDTH] = {
    {0, 0, 255},
    {255, 255, 0}
};
static XGA_color plumber_row2[PLUMBER_WIDTH] = {
    {255, 255, 255},
    {0, 0, 0}
};

static XGA_color *plumber_sprite_rows[PLUMBER_HEIGHT] = { row0, row1, row2 };

static XGA_sprite plumber = {
    .data = plumber_sprite_rows,
    .width = PLUMBER_WIDTH,
    .height = PLUMBER_HEIGHT
};
```
"""

from PIL import Image
import numpy as np
import sys
from pathlib import Path

if len(sys.argv) < 2:
    print("usage: sprite_to_struct.py <path to image>", file=sys.stderr)
    
sprite_name = Path(sys.argv[1]).stem
    
image = Image.open(sys.argv[1]).convert("RGB")
img_array = np.array(image, dtype=np.uint8)
img_array = np.transpose(img_array, (1, 0, 2)) # By default numpy does (height, width, channels) we want (width, height, channels)

# Produce macro definitions
print("#pragma once")
print(f"#define {sprite_name.upper()}_WIDTH {image.width}")
print(f"#define {sprite_name.upper()}_HEIGHT {image.height}\n")

# Produce row structs
row_names = []
for cnt, row in enumerate(img_array):
    row_name = f"{sprite_name}_row{cnt}"
    row_names.append(row_name)
    print(f"static XGA_color {row_name}[{sprite_name.upper()}_WIDTH] = {{")
    for pixel in row:
        print(f"\t{{{pixel[0]},{pixel[1]},{pixel[2]}}},")
    print("};\n")
    
# Produce main player sprite data
print(f"static XGA_color *{sprite_name}_sprite_rows[{sprite_name.upper()}_HEIGHT] = {{{",".join(row_names)}}};\n")

# Produce final sprite definition
print(f"static XGA_sprite {sprite_name} = {{")
print(f"\t.data = {sprite_name}_sprite_rows,")
print(f"\t.width = {sprite_name.upper()}_WIDTH,")
print(f"\t.height = {sprite_name.upper()}_HEIGHT")
print("};")