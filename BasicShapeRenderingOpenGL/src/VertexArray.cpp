#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &mVertexArray);
}

VertexArray::~VertexArray()
{
	DeleteVertexArray();
}

void VertexArray::Bind()
{
	glBindVertexArray(mVertexArray);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::DeleteVertexArray()
{
	glDeleteVertexArrays(1, &mVertexArray);
}
