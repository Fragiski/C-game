#pragma once
#include "level.h"


class Level1 : public Level {
protected:

	void loadLevelSpecificBlocks() override;   // Load Level 1 blocks
	std::string getBlockTexture(int i) const override; // Provide Level 1-specific textures
	std::string getBkgndTexture() const override;

	void loadPlayerCoords();

public:

	void checkEndLevel();
	void checkOutOfBounds();
	void checkCollisions();
	void loadLevelSpecificCherries();
	explicit Level1(const std::string& name); // Constructor
	~Level1();
};