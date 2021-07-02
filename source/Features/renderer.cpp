// #include"renderer.hpp"

// void Renderer::Clear() const
// {
//     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// }

// void Renderer::Draw(const VertexArray& VAO, const IndexBuffer& EBO, const Shader& shader) const
// {
//         shader.Bind();
//         VAO.Bind();
//         EBO.Bind();
//         glDrawElements(GL_TRIANGLES, EBO.getCount(), GL_UNSIGNED_INT, nullptr);
// }