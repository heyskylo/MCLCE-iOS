#include "stdafx.h"
#include "net.minecraft.world.level.h"

#include "SpringTile.h"


SpringTile::SpringTile(int id, int liquidTileId) : Tile(id, Material::water)
{
	this->liquidTileId = liquidTileId;
	this->setTicking(true);
}

void SpringTile::onPlace(Level *level, int x, int y, int z)
{
	Tile::onPlace(level, x, y, z);
	if (level->isEmptyTile(x-1, y, z)) level->setTileAndData(x-1, y, z, liquidTileId, 0, 3);
	if (level->isEmptyTile(x+1, y, z)) level->setTileAndData(x+1, y, z, liquidTileId, 0, 3);
	if (level->isEmptyTile(x, y, z-1)) level->setTileAndData(x, y, z-1, liquidTileId, 0, 3);
	if (level->isEmptyTile(x, y, z+1)) level->setTileAndData(x, y, z+1, liquidTileId, 0, 3);
}

void SpringTile::tick(Level *level, int x, int y, int z, Random *random)
{
	Tile::tick(level, x, y, z, random);
	if (level->isEmptyTile(x-1, y, z)) level->setTileAndData(x-1, y, z, liquidTileId, 0, 3);
	if (level->isEmptyTile(x+1, y, z)) level->setTileAndData(x+1, y, z, liquidTileId, 0, 3);
	if (level->isEmptyTile(x, y, z-1)) level->setTileAndData(x, y, z-1, liquidTileId, 0, 3);
	if (level->isEmptyTile(x, y, z+1)) level->setTileAndData(x, y, z+1, liquidTileId, 0, 3);
}