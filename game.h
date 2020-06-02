#pragma once

class Block {
public:
	Block(int block_x, int block_y, int block_type) {
		x = block_x;
		y = block_y;
		type = block_type;
	}
private:
	int x;
	int  y;
	int type;
};