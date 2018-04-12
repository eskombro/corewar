#version 410

#define ANTI_ALIASING 1

#define SQUARE_FILLING 0.9
#define SQUARE_MARGIN 0.1

uniform	int			mode;

uniform ivec4		bounds;
uniform vec4		ocolor;
uniform vec4		grid_color;
uniform vec4		p1;
uniform vec4		p2;
uniform vec4		p3;
uniform vec4		p4;
uniform int			edge;

uniform sampler2D	hextex;
uniform usampler2D	map;
uniform usampler2D	writerMap;
uniform	int			mapDataSize;
uniform ivec2		mapSize;

out vec4 			frag_color;

int			getSquareSize()
{
	int		size;

	size = int(floor(float(bounds.z - (edge + 2) * 2) / float(mapSize.x)));
	size = min(int(floor(float((bounds.w - (edge + 2) * 2)) / float(mapSize.y))), size);
	return (size);
}

void		clip(ivec4 bounds)
{
	if (int(gl_FragCoord.x) <= bounds.x || int(gl_FragCoord.x) >= bounds.x + bounds.z)
		discard;
	if (int(gl_FragCoord.y) <= bounds.y || int(gl_FragCoord.y) >= bounds.y + bounds.w)
		discard;
}

ivec4		getNewBounds(ivec4 bounds)
{
	ivec4	newBounds;
	int		size;

	size = getSquareSize();
	newBounds.z = mapSize.x * size;
	newBounds.w = mapSize.y * size;
	newBounds.x = bounds.x + (bounds.z - newBounds.z) / 2;
	newBounds.y = bounds.y + (bounds.w - newBounds.w) / 2;
	return (newBounds);
}

ivec2		getMapCoord(vec2 pos, vec4 newBounds)
{
	ivec2	mapCoord;

	mapCoord.x = int(floor(((pos.x - newBounds.x) / newBounds.z) * float(mapSize.x)));
	mapCoord.y = mapSize.y - 1 - int(floor(((pos.y - newBounds.y) / newBounds.w) * float(mapSize.y)));
	return (mapCoord);
}

vec2		getHextexCoord(ivec2 mapCoord, ivec2 absMapCoord, int size)
{
	vec2	coord;
	uint	letter;
	uint	mapContent;

	mapContent = texelFetch(map, mapCoord, 0).r;
	letter = mapContent / 16;
	if (gl_FragCoord.x - absMapCoord.x > size / 2)
	{
		letter = mapContent % 16;
		absMapCoord.x += size / 2;
	}
	coord = vec2(float(int(gl_FragCoord.x) - absMapCoord.x) / float(size) * (1.0 / 8.0) + float(letter) * (1.0 / 16.0),
		1.0 - float(int(gl_FragCoord.y) - absMapCoord.y) / float(size));
	return (coord);
}

vec4		colorFromUint(uint player)
{
	switch (player)
	{
		case 1:
			return (p1);
			break;
		case 2:
			return (p2);
			break;
		case 3:
			return (p3);
			break;
		case 4:
			return (p4);
			break;
		default:
			return (grid_color);
	}
}

vec4		getColorBack(ivec4 newBounds)
{
	vec4	color;
	vec4	result;
	ivec2	mapCoord;
	ivec2	absMapCoord;
	int		size;

	result = vec4(0.0, 0.0, 0.0, 0.0);
	color = vec4(1.0, 1.0, 1.0, 1.0);
	size = getSquareSize();
	mapCoord = getMapCoord(gl_FragCoord.xy, vec4(newBounds));
	if (mapCoord.y * mapSize.x + mapCoord.x > mapDataSize)
		return (result);
	color = colorFromUint(texelFetch(writerMap, mapCoord, 0).r);
	color = color / 2.0;
	/* return (color); */
	return (vec4(0.0, 0.0, 0.0, 0.0));
}

vec4		getColor(ivec4 newBounds)
{
	vec4	color;
	vec4	result;
	ivec2	mapCoord;
	ivec2	absMapCoord;
	int		size;

	result = vec4(0.0, 0.0, 0.0, 0.0);
	color = vec4(1.0, 1.0, 1.0, 1.0);
	size = getSquareSize();
	mapCoord = getMapCoord(gl_FragCoord.xy, vec4(newBounds));
	if (mapCoord.y * mapSize.x + mapCoord.x > mapDataSize)
		return (result);
	color = colorFromUint(texelFetch(writerMap, mapCoord, 0).r);
	absMapCoord.x = newBounds.x + mapCoord.x * size + int(SQUARE_MARGIN * float(size));
	absMapCoord.y = newBounds.y + (mapSize.y - 1 - mapCoord.y) * size + int(SQUARE_MARGIN * float(size));
	if (gl_FragCoord.x > absMapCoord.x && gl_FragCoord.x < absMapCoord.x + int(float(size) * SQUARE_FILLING) &&
		gl_FragCoord.y > absMapCoord.y && gl_FragCoord.y < absMapCoord.y + int(float(size) * SQUARE_FILLING))
		result = texture(hextex, getHextexCoord(mapCoord, absMapCoord, int(float(size) * SQUARE_FILLING))) * color;
	return (result);
}

void		main()
{
	ivec4	newBounds;

	newBounds = getNewBounds(bounds);
	clip(newBounds + ivec4(-edge - 2, -edge - 2, (edge + 2) * 2, (edge + 2) * 2));
	if (edge != 0 && (
			(int(gl_FragCoord.x) < newBounds.x && int(gl_FragCoord.x) > newBounds.x - edge - 2) ||
			(int(gl_FragCoord.y) < newBounds.y && int(gl_FragCoord.y) > newBounds.y - edge - 2) ||
			(int(gl_FragCoord.x) > newBounds.x + newBounds.z && int(gl_FragCoord.x) < newBounds.x + newBounds.z + edge + 2) ||
			(int(gl_FragCoord.y) > newBounds.y + newBounds.w && int(gl_FragCoord.y) < newBounds.y + newBounds.w + edge + 2)))
		frag_color = ocolor;
	else
		frag_color = mode == 0 ? getColorBack(newBounds) : getColor(newBounds);
	/* frag_color = vec4(1.0, 0.0, 0.0, 1.0); */
}
