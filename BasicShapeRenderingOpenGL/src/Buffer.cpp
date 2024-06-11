#include "Buffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(std::vector<float> vertices)
{
    glGenBuffers(1, &mVertexBufferObject);

    Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    DeleteVertexBuffer();
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::DeleteVertexBuffer()
{
    glDeleteBuffers(1, &mVertexBufferObject);
}

IndexBuffer::IndexBuffer(std::vector<unsigned int> indices)
{
    glGenBuffers(1, &mIndexBuffer);

    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    DeleteIndexBuffer();
}

void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
}

void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::DeleteIndexBuffer()
{
    glDeleteBuffers(1, &mIndexBuffer);
}
