#pragma once
#include <vector>

class VertexBuffer
{
public:
	VertexBuffer(std::vector<float> vertices);
	~VertexBuffer();
	void Bind();
	void Unbind();
	unsigned int GetVertexBuffer() const { return mVertexBufferObject; }
	void DeleteVertexBuffer();
private:
	unsigned int mVertexBufferObject;
};

class IndexBuffer
{
public:
	IndexBuffer(std::vector<unsigned int> indices);
	~IndexBuffer();
	void Bind();
	void Unbind();
	unsigned int GetIndexBuffer() const { return mIndexBuffer; }
	void DeleteIndexBuffer();
private:
	unsigned int mIndexBuffer;
};