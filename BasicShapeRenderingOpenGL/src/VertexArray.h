#pragma once

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind();
	void Unbind();
	void DeleteVertexArray();

	unsigned int GetVertexArray() const { return mVertexArray; }
private:
	unsigned int mVertexArray;
};