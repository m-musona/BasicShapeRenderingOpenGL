#pragma once
#include <string>

class Texture
{
public:
	Texture(const std::string& texturePath);
	~Texture();

	void Bind(unsigned int slot);

	unsigned int GetTextureID() const { return mTextureID; }

private:
	unsigned int mTextureID;
};