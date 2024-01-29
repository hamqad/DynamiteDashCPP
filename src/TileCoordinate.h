#pragma once
class TileCoordinate
{
	protected:
		int x, y;
		const int TILE_SIZE = 16;
	public:	
		TileCoordinate(int xx, int yy) {
			x = xx * TILE_SIZE;
			y = yy * TILE_SIZE;
		};

		int getX();
		int getY();
};

