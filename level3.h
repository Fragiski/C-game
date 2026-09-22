#pragma once
#include "level.h"


class Level3 : public Level {
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
	explicit Level3(const std::string& name); // Constructor
	~Level3();
};