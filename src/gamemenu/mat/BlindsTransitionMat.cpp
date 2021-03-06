#include <gamemenu/mat/BlindsTransitionMat.hpp>

#include <shader/ShaderProgramBuilder.hpp>

namespace gamemenu {
namespace mat {
using ::monkeysworld::file::CachedFileLoader;
using ::monkeysworld::shader::ShaderProgramBuilder;
BlindsTransitionMat::BlindsTransitionMat(::monkeysworld::engine::Context* ctx) {
  auto exec_prog = [&] {
    prog_ = ShaderProgramBuilder()
              .WithVertexShader("resources/mat/BlindsTransition.vert")
              .WithFragmentShader("resources/mat/BlindsTransition.frag")
              .Build();
  };

  auto f = ctx->GetExecutor()->ScheduleOnMainThread(exec_prog);
  f.wait();

  segment_count = 5;
  segment_offset = 0.1f;
  time = 0.0f;
  texture = 0;
}

void BlindsTransitionMat::UseMaterial() {
  glUseProgram(prog_.GetProgramDescriptor());
  glUniform1i(0, segment_count);
  glUniform1f(1, segment_offset);
  glUniform1f(2, time);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);
  glUniform1i(3, 0);
}

}
}