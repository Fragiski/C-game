#pragma once
#include "level.h"


class Level2 : public Level {
protected:

	int previousRandomNumber = 5;

	void loadLevelSpecificBlocks() override;   // Load Level 1 blocks
	std::string getBlockTexture(int i) const override; // Provide Level 1-specific textures
	std::string getBkgndTexture() const override;

	void loadPlayerCoords();

public:

	void FallingBombs() override;
	void checkEndLevel();
	void checkOutOfBounds();
	void checkCollisions();
	void loadLevelSpecificCherries();
	explicit Level2(const std::string& name); // Constructor
	~Level2();
};